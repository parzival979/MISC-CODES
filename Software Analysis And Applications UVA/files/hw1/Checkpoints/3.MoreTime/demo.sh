#!/bin/sh

# If afl_output isn't empty, empty it.
[ "$(ls -A "afl_output")" ] && rm -rf "afl_output"/*

# `timeout` is a function built into the shell that terminates a program after acertain amount of time.
timeout 15s ./run_afl.sh
./run_aflcov.sh
