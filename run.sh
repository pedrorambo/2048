#!/usr/bin/env bash

# Prepare destination folder
rm -rf build
mkdir build

# Compile
gcc -o ./build/main main.c

# Run
./build/main