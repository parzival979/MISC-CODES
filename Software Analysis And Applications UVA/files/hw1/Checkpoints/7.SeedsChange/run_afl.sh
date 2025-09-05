#!/bin/bash
tcc_run=$(<tcc_run_string.txt)
afl-fuzz -m 500 -i afl_input/ -o afl_output/ $tcc_run
