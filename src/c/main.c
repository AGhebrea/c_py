#include <stdio.h>
#include <ctype.h>

// boilerplate
#include "/usr/include/python3.10/Python.h"
//

#define ENDLINE printf("\n")

/*
	This is branch 2
*/

void printSubclasses(PyObject* data);
void printDoc(PyObject* data);
void printType(PyObject* data);

PyObject* function(PyObject* argdata)
{
	PyObject* retdata;
	int i;
	i = 888;

	// this is still unresolved
	// retdata = Py_BuildValue("i", argdata->ob_refcnt);
	// retdata = Py_BuildValue("O", argdata);

	printDoc(argdata);
	printSubclasses(argdata);
	printType(argdata);

	ENDLINE;

	return argdata;
}

void printType(PyObject* data)
{
	printf(
		"\n\nprintDoc:\n%s",
		data->ob_type->tp_doc
	);
}

void printDoc(PyObject* data)
{
	if(data->ob_type->tp_doc == NULL){
		return;
	}
	printf(
		"\n\nprintDoc:\n%s",
		data->ob_type->tp_doc
	);

	return;
}

void printSubclasses(PyObject* data)
{
	PyObject *tmp;
	tmp = data->ob_type->tp_subclasses;
	if(tmp == NULL){
		printf("\nObject has no subclasses!!!");
		return;
	}
	printf(
		"\nprintSubclassesDoc:\n%s",
		tmp->ob_type->tp_doc
	);

	return;
}

// PyObject_GetAttr(data, Py_BuildValue("s", "whatever"));
// return Py_BuildValue("i", i);	

// typedef struct _object {
//     _PyObject_HEAD_EXTRA 	// idk
//     Py_ssize_t ob_refcnt;	// references of the objects held
//     PyTypeObject *ob_type;	// idk
// } PyObject;

// struct _typeobject {
//     PyObject_VAR_HEAD
//     const char *tp_name; /* For printing, in format "<module>.<name>" */
//     Py_ssize_t tp_basicsize, tp_itemsize; /* For allocation */

//     /* Methods to implement standard operations */

//     destructor tp_dealloc;
//     Py_ssize_t tp_vectorcall_offset;
//     getattrfunc tp_getattr;
//     setattrfunc tp_setattr;
//     PyAsyncMethods *tp_as_async; /* formerly known as tp_compare (Python 2)
//                                     or tp_reserved (Python 3) */
//     reprfunc tp_repr;

//     /* Method suites for standard classes */

//     PyNumberMethods *tp_as_number;
//     PySequenceMethods *tp_as_sequence;
//     PyMappingMethods *tp_as_mapping;

//     /* More standard operations (here for binary compatibility) */

//     hashfunc tp_hash;
//     ternaryfunc tp_call;
//     reprfunc tp_str;
//     getattrofunc tp_getattro;
//     setattrofunc tp_setattro;

//     /* Functions to access object as input/output buffer */
//     PyBufferProcs *tp_as_buffer;

//     /* Flags to define presence of optional/expanded features */
//     unsigned long tp_flags;

//     const char *tp_doc; /* Documentation string */

//     /* Assigned meaning in release 2.0 */
//     /* call function for all accessible objects */
//     traverseproc tp_traverse;

//     /* delete references to contained objects */
//     inquiry tp_clear;

//     /* Assigned meaning in release 2.1 */
//     /* rich comparisons */
//     richcmpfunc tp_richcompare;

//     /* weak reference enabler */
//     Py_ssize_t tp_weaklistoffset;

//     /* Iterators */
//     getiterfunc tp_iter;
//     iternextfunc tp_iternext;

//     /* Attribute descriptor and subclassing stuff */
//     struct PyMethodDef *tp_methods;
//     struct PyMemberDef *tp_members;
//     struct PyGetSetDef *tp_getset;
//     // Strong reference on a heap type, borrowed reference on a static type
//     struct _typeobject *tp_base;
//     PyObject *tp_dict;
//     descrgetfunc tp_descr_get;
//     descrsetfunc tp_descr_set;
//     Py_ssize_t tp_dictoffset;
//     initproc tp_init;
//     allocfunc tp_alloc;
//     newfunc tp_new;
//     freefunc tp_free; /* Low-level free-memory routine */
//     inquiry tp_is_gc; /* For PyObject_IS_GC */
//     PyObject *tp_bases;
//     PyObject *tp_mro; /* method resolution order */
//     PyObject *tp_cache;
//     PyObject *tp_subclasses;
//     PyObject *tp_weaklist;
//     destructor tp_del;

//     /* Type attribute cache version tag. Added in version 2.6 */
//     unsigned int tp_version_tag;

//     destructor tp_finalize;
//     vectorcallfunc tp_vectorcall;
// };