# Q1
```
$ gcc test.c -shared -o test.so  
/usr/bin/ld: /tmp/ccDuw5ie.o: relocation R_X86_64_32 against `.rodata' can not be used when making a shared object; recompile with -fPIC 
```
why does the .rodata section have a R_X86_64_32 relocation type?   
	From a statically linked lib?   
	default linker script?

# Q2
https://github.com/python/cpython/blob/main/Lib/ctypes/__init__.py#L139C42-L139C42
```
    from _ctypes import dlopen as _dlopen
```
What _ctypes module, how does that import work?

# Q3
```
main.c:
PyObject* function(PyObject* data)
{
	printf(
		"\n[%d]",
		data->ob_refcnt
	);
	data->ob_refcnt = data->ob_refcnt + 1024;
	return data;
}

main.py
arbdata2 = own_libc.function(ctypes.py_object(arbdata));
print(type(arbdata2));
print(arbdata2["whatever"]);

<class 'int'>
[2]Traceback (most recent call last):
  File "/home/sirius/etc/sw_projects/c_py/./src/py/main.py", line 17, in <module>
    print(arbdata2["whatever"]);
TypeError: 'int' object is not subscriptable
```

# Q4
```
PyObject* function(PyObject* argdata)
{
	retdata = Py_BuildValue("i", argdata->ob_refcnt);

```

in C this segfaults, why ?

btrace:
```
#0  __PyLong_GetSmallInt_internal (value=2) at /usr/src/debug/python3.10-3.10.11-1.fc36.x86_64/Include/internal/pycore_long.h:55
#1  get_small_int (ival=2) at /usr/src/debug/python3.10-3.10.11-1.fc36.x86_64/Objects/longobject.c:46
#2  PyLong_FromLong (ival=2) at /usr/src/debug/python3.10-3.10.11-1.fc36.x86_64/Objects/longobject.c:186
#3  0x00007ffff7d091af in va_build_value (format=<optimized out>, va=0x7fffffffd3f0, flags=0)
    at /usr/src/debug/python3.10-3.10.11-1.fc36.x86_64/Python/modsupport.c:565
#4  0x00007ffff7d0912f in Py_BuildValue (format=<optimized out>)
    at /usr/src/debug/python3.10-3.10.11-1.fc36.x86_64/Python/modsupport.c:522
#5  0x00007ffff7a1e15a in function () from /home/sirius/etc/sw_projects/c_py/bin/libown.so

```

same but with
```
retdata = Py_BuildValue("o", argdata);
```

btrace:
```
#0  _PyErr_SetObject (tstate=0x0, exception=0x7ffff7f31960 <_PyExc_SystemError>, value=0x7fffea002550)
    at /usr/src/debug/python3.10-3.10.11-1.fc36.x86_64/Python/errors.c:130
#1  0x00007ffff7d46257 in _PyErr_SetString (string=<optimized out>, exception=0x7ffff7f31960 <_PyExc_SystemError>, tstate=0x0)
    at /usr/src/debug/python3.10-3.10.11-1.fc36.x86_64/Python/errors.c:235
#2  PyErr_SetString (exception=0x7ffff7f31960 <_PyExc_SystemError>, string=<optimized out>)
    at /usr/src/debug/python3.10-3.10.11-1.fc36.x86_64/Python/errors.c:243
#3  0x00007ffff7c648bc in do_mkvalue (p_format=0x7fffffffd3a8, p_va=0x7fffffffd3b0, flags=0)
    at /usr/src/debug/python3.10-3.10.11-1.fc36.x86_64/Python/modsupport.c:505
#4  0x00007ffff7d091af in va_build_value (format=<optimized out>, va=0x7fffffffd3f0, flags=0)
    at /usr/src/debug/python3.10-3.10.11-1.fc36.x86_64/Python/modsupport.c:565
#5  0x00007ffff7d0912f in Py_BuildValue (format=<optimized out>)
    at /usr/src/debug/python3.10-3.10.11-1.fc36.x86_64/Python/modsupport.c:522
#6  0x00007ffff7a1e157 in function () from /home/sirius/etc/sw_projects/c_py/bin/libown.so

```

# Q5:
```
own_libc.function.restype = ctypes.py_object;
```

what is that needed

# Q6:
```
static int
dict_traverse(PyObject *op, visitproc visit, void *arg)
{
    PyDictObject *mp = (PyDictObject *)op;
    ...
}
```

I read somewhere in the docs that these type of casts (any object to PyObject) always
work. If that is the case then how do they work to ensure that?