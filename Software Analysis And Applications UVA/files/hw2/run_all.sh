#!/bin/bash
set -xe


# make cleanup.sh executable
chmod +x cleanup.sh

./cleanup.sh

#1
clang -emit-llvm -c -g -O0 -Xclang -disable-O0-optnone program_suite/1-divisibility-check-sym.c -o program_suite/1-1.bc
klee program_suite/1-1.bc
klee-stats program_suite/klee-last/

#2
clang -emit-llvm -c -g -O0 -Xclang -disable-O0-optnone program_suite/1-max-check-sym.c -o program_suite/1-2.bc
klee program_suite/1-2.bc
klee-stats program_suite/klee-last/

#3
clang -emit-llvm -c -g -O0 -Xclang -disable-O0-optnone program_suite/1-loop-iteration-sym.c -o program_suite/1-3.bc
klee program_suite/1-3.bc
klee-stats program_suite/klee-last/

#4
clang -emit-llvm -c -g -O0 -Xclang -disable-O0-optnone program_suite/1-struct-check-sym.c -o program_suite/1-4.bc
klee program_suite/1-4.bc
klee-stats program_suite/klee-last/

#5
clang -emit-llvm -c -g -O0 -Xclang -disable-O0-optnone program_suite/1-sorted-check-sym.c -o program_suite/1-5.bc
klee program_suite/1-5.bc
klee-stats program_suite/klee-last/

# #6
# clang -emit-llvm -c -g -O0 -Xclang -disable-O0-optnone program_suite/2-huge-braching-sym.c -o program_suite/2-1.bc
# timeout 30m klee program_suite/2-1.bc
# klee-stats program_suite/klee-last/

# #7
# clang -emit-llvm -c -g -O0 -Xclang -disable-O0-optnone program_suite/2-recursion-explosion-sym.c -o program_suite/2-2.bc
# timeout 30m klee program_suite/2-2.bc
# klee-stats program_suite/klee-last/

#8
clang -emit-llvm -c -g -O0 -Xclang -disable-O0-optnone program_suite/2-out-of-bounds-sym.c -o program_suite/2-3.bc
klee program_suite/2-3.bc
klee-stats program_suite/klee-last/
ktest-tool program_suite/klee-last/test000001.ktest

# #9
# clang -emit-llvm -c -g -O0 -Xclang -disable-O0-optnone program_suite/2-mulit-pointer-arithmetic-sym.c -o program_suite/2-4.bc
# timeout 30m klee program_suite/2-4.bc
# klee-stats program_suite/klee-last/

# #10
# clang -emit-llvm -c -g -O0 -Xclang -disable-O0-optnone program_suite/2-multi-var-sym.c -o program_suite/2-5.bc
# timeout 30m  klee program_suite/2-5.bc
# klee-stats program_suite/klee-last/