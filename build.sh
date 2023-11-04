#!/usr/bin/env bash

# compile .c as .so
# run python script

SRCDIR='./src'
# /home/sirius/etc/sw_projects/c_py/bin/libown.so

if [ ! -d ./bin ]; then
	mkdir bin
fi

gcc $SRCDIR/c/main.c -shared -fPIC -o ./bin/libown.so
python $SRCDIR/py/main.py