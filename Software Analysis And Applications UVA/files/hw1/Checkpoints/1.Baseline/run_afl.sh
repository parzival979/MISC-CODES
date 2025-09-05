#!/bin/bash
tcc_run=$(<tcc_run_string.txt)
afl-fuzz -i afl_input/ -o afl_output/ $tcc_run
