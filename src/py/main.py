import ctypes
import sys
import os

class custom:
	def __init__(self):
		pass;

argdata = {
	"whatever": "unga bunga"
};

argdata = "abc"

# boilerplate
own_libc = ctypes.cdll.LoadLibrary(f"{os.getcwd()}/bin/libown.so"); # hack, fix paths
own_libc.function.restype = ctypes.py_object;
#

retdata = own_libc.function(ctypes.py_object(argdata));

print("\n")
print(type(retdata));
print(retdata);
if id(retdata) != id(argdata):
	print("Objects are different")
else:
	print("Objects are the same")