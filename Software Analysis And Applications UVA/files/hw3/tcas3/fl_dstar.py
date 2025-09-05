#!/usr/bin/env python3
import sys
import os
import glob

def parse_gcov_file(gcov_filename):
    lines_data = []
    with open(gcov_filename, 'r') as f:
        for line in f:
            parts = line.split(":", 2)
            if len(parts) < 3:
                continue
            exec_count = parts[0].strip()
            line_number = parts[1].strip()
            statement = parts[2].rstrip()
            if line_number == "0":
                continue
            try:
                count = int(exec_count)
            except ValueError:
                count = 0
            executed = (count > 0)
            lines_data.append({
                "line": int(line_number),
                "statement": statement,
                "executed": executed
            })
    return lines_data

def aggregate_coverage(pass_dir, fail_dir):
    coverage = {}
    passing_files = glob.glob(os.path.join(pass_dir, "*.gcov"))
    for gcov_file in passing_files:
        parsed = parse_gcov_file(gcov_file)
        for entry in parsed:
            if not entry["executed"]:
                continue
            key = (entry["line"], entry["statement"])
            if key not in coverage:
                coverage[key] = {"passed": 0, "failed": 0}
            coverage[key]["passed"] += 1
    failing_files = glob.glob(os.path.join(fail_dir, "*.gcov"))
    total_failed = len(failing_files)
    for gcov_file in failing_files:
        parsed = parse_gcov_file(gcov_file)
        for entry in parsed:
            if not entry["executed"]:
                continue
            key = (entry["line"], entry["statement"])
            if key not in coverage:
                coverage[key] = {"passed": 0, "failed": 0}
            coverage[key]["failed"] += 1
    return coverage, total_failed

def compute_suspiciousness(coverage, total_failed):
    results = []
    for (line, stmt), counts in coverage.items():
        passed = counts["passed"]
        failed = counts["failed"]
        denominator = passed + total_failed - failed + 1e-6
        if denominator > 0:
            s_val = round((failed ** 2) / denominator, 2)
        else:
            s_val = 0.0
        results.append({
            "line": line,
            "statement": stmt,
            "passed": passed,
            "failed": failed,
            "total_failed": total_failed,
            "suspiciousness": s_val
        })
    return results

def main():
    if len(sys.argv) != 3:
        print("Usage: python3 fl_dstar.py <passing_dir> <failing_dir>")
        sys.exit(1)
    passing_dir = sys.argv[1]
    failing_dir = sys.argv[2]
    coverage, total_failed = aggregate_coverage(passing_dir, failing_dir)
    results = compute_suspiciousness(coverage, total_failed)
    sorted_results = sorted(results, key=lambda x: (-x["suspiciousness"], x["line"]))
    header = f"{'Line #':<8} | {'Statement':<50} | {'#failedTests(s)':<15} | {'#passedTests(s)':<15} | {'total_failed':<12} | {'Suspiciousness':<15}"
    print(header)
    print("-" * len(header))
    for r in sorted_results:
        print(f"{r['line']:<8} | {r['statement'][:50]:<50} | {r['failed']:<15} | {r['passed']:<15} | {r['total_failed']:<12} | {r['suspiciousness']:<15}")

if __name__ == "__main__":
    main()