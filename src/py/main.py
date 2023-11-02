import ctypes

class custom:
	def __init__(self):
		pass;

arbdata = {
	"whatever": "unga bunga"
};

own_libc = ctypes.cdll.LoadLibrary("/home/sirius/etc/sw_projects/c_py/bin/libown.so");
# arbdata2 = ctypes.py_object(own_libc.function(ctypes.py_object(arbdata)));
arbdata2 = own_libc.function(ctypes.py_object(arbdata))
print(type(arbdata2));
print(arbdata2);