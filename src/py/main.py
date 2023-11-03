import ctypes

class custom:
	def __init__(self):
		pass;

argdata = {
	"whatever": "unga bunga"
};

own_libc = ctypes.cdll.LoadLibrary("/home/sirius/etc/sw_projects/c_py/bin/libown.so");
retdata = own_libc.function(ctypes.py_object(argdata));

print("\n")
print(type(retdata));
print(retdata);
retdata = ctypes.py_object(retdata);
print(type(retdata));
print(retdata);