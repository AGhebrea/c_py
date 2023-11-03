# create a py program that will call C code
## reqs
[X] Boilerplate
[X] Pass object py -> c
[ ] c modifies object
[X] recv object py <- c

## special req
[ ] throw errors from c/c++ (c is cooler), catch them in python

## refs

https://docs.python.org/3/library/ctypes.html
https://github.com/python/cpython/tree/main/Lib/ctypes
https://github.com/python/cpython/blob/main/Include/object.h#L207
https://github.com/python/cpython/blob/main/Include/cpython/object.h#L104

https://github.com/numpy/numpy/blob/main/numpy/_core/src/common/array_assign.c