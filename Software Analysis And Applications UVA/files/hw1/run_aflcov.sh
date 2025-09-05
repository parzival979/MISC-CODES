#!/bin/bash
#Import our 'run string' and convert the path to use the version of tcc compiled with coverage support (`/root/tcc-cov/bin` instead of `/root/tcc/bin`) and replace the file placeholder.
tcc_run=$(<tcc_run_string.txt)
echo $tcc_run
tcc_run=${tcc_run//\@\@/AFL_FILE}
tcc_run=${tcc_run//root\/tcc/root\/tcc\-cov}
echo $tcc_run

afl-cov -d /root/files/hw1/afl_output/ --coverage-cmd "$tcc_run" --code-dir /root/tinycc/ --lcov-path /usr/bin/lcov --genhtml-path /usr/bin/genhtml 
