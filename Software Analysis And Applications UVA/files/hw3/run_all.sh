#!/bin/bash
set -xe

# Go to each tcas0, tcas1,.. tcas4 directory and run sh run.sh
for i in {0..4}
do
    cd tcas$i
    sh run.sh
    cd ..
done