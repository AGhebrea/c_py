#!/usr/bin/env bash

# compile .c as .so
# run python script

SRCDIR='./src'

gcc $SRCDIR/c/main.c -shared -fPIC -o ./bin/libown.so
python $SRCDIR/py/main.py