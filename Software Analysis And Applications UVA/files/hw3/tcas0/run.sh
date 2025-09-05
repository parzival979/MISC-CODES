#!/bin/bash
TCAS_FILE="tcas0.c"
BINARY="${TCAS_FILE%.c}"
PASS_DIR="$(pwd)/passing_gcov"
FAIL_DIR="$(pwd)/failing_gcov"
rm -rf "$PASS_DIR" "$FAIL_DIR"
mkdir -p "$PASS_DIR" "$FAIL_DIR"
TEST_COUNTER=0
while IFS=',' read -r test_input expected; do
    echo "========================================"
    echo "Running test $((TEST_COUNTER+1)) with input: $test_input"
    gcc -Wno-implicit-function-declaration -std=gnu89 -Wall -fprofile-arcs -ftest-coverage "$TCAS_FILE" -o "$BINARY"
    output=$(./"$BINARY" $test_input)
    echo "Output: $output"
    if echo "$output" | grep -q "${expected// /}"; then
         result="P"
         echo "Test Result: PASS"
    else
         result="F"
         echo "Test Result: FAIL"
    fi
    gcov "${BINARY}-${TCAS_FILE}"
    GCOV_FILE="${TCAS_FILE}.gcov"
    NEW_GCOV_FILE="test${TEST_COUNTER}_${GCOV_FILE}"
    if [ "$result" == "P" ]; then
        mv "$GCOV_FILE" "$PASS_DIR/$NEW_GCOV_FILE"
    else
        mv "$GCOV_FILE" "$FAIL_DIR/$NEW_GCOV_FILE"
    fi
    rm -f *.gcda *.gcno "$BINARY"
    TEST_COUNTER=$((TEST_COUNTER+1))
done < tests.csv
echo "All tests processed. Total tests: $TEST_COUNTER"
echo "Passing gcov files are in: $PASS_DIR"
echo "Failing gcov files are in: $FAIL_DIR"
rm -f fl_dstar_output.txt
python3 fl_dstar.py "$PASS_DIR" "$FAIL_DIR" >> fl_dstar_output.txt