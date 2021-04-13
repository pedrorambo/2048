#!/usr/bin/env bash

# Prepare destination folder
rm -rf build
mkdir build

# Compile
gcc -o ./build/main main.c lib/prints.c lib/utils.c lib/tableLogic.c

# Run
./build/main