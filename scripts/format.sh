#! /bin/bash

for run in {1..2}
do
    git clang-format-14 HEAD^ -- src/*.cpp -f
done
