#!/bin/bash
set -xe
[ ! "$(ls -A "afl_output")" ] 

### Explanation of above ###
# A `#!` in the first line of a file is called a shebang - it tells the system what interpreter to use when you call the file directly (e.g. `./run_all.sh`). We tell it here that it should use the bash shell executable.

# Line 2 sets 2 flags for the shell: 
# `-x` will cause the shell to repeat each line to the terminal with its output as it's executed so that you can see what's happening.
# `-e` will cause the script to stop immediately if a line returns an error. 

# Line 3 ensures that the afl_output directory is empty (that you don't have leftover files from a previous run). (It returns a non-zero exit code if there are files, and so, because of the `set -e` above, the script will stop.)

# Please note that, for grading, this script be run as `timeout 30m ./run_all.sh`. You should ensure that the script finishes before that.

# Delete the above comments and put your code here. (For HW1, since you only need to turn in your final settings, you can either put the commands directly in here or you can modify the given example files and call them here.)
