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