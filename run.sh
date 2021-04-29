#!/usr/bin/env bash

# Prepare destination folder
rm -rf build
mkdir build

# Compile
gcc -Wall -Wextra -Wpedantic \
    -o build/main \
    src/main.c src/prints.c src/utils.c src/tableLogic.c src/tablePlays.c src/view.c \
    -lncurses \
    -I src/include

# Run
./build/main