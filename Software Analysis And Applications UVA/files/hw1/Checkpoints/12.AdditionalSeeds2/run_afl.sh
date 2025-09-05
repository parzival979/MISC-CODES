#!/bin/bash
tcc_run=$(<tcc_run_string.txt)
afl-fuzz -x c_asm.dict -m 300 -i afl_input/ -o afl_output/ $tcc_run
