#!/bin/bash
tcc_run=$(<$HOME/files/hw1/tcc_run_string.txt)
afl-fuzz -x c_asm.dict -m 300 -i $HOME/files/hw1/afl_input/ -o $HOME/files/hw1/afl_output/ $tcc_run
