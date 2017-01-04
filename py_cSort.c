//Python.h has all the required function definitions to manipulate the Python objects
#include <Python.h>

#include "sort.c"


typedef void (*sort_cb) (int*, int, int);

static PyObject*
runSort(PyObject* args, sort_cb sort_func) {
  PyObject * listObj;
  if (! PyArg_ParseTuple( args, "O", &listObj))
    return NULL;

  Py_INCREF(listObj);
  long length = PyList_Size(listObj);
  int lst[length];
  for(int i=0; i < length; i++){
    PyObject* temp = PyList_GetItem(listObj, i);
    long elem = PyInt_AsLong(temp);
    lst[i] = elem;
  }

  sort_func(lst, 0, length-1);

  for (int i=0;i<length;i++) {
	  PyObject * temp = Py_BuildValue("i", lst[i]);
	  Py_INCREF(temp);
	  PyList_SetItem(listObj, i, temp);
  }
  return listObj;
}


/*
 * Python bindings
 */

static PyObject* 
cSort_bubble(PyObject* self, PyObject* args){
  return (PyObject*) runSort(args, (sort_cb)bubbleSort);
}


static PyObject* 
cSort_merge(PyObject* self, PyObject* args){
  return (PyObject*) runSort(args, (sort_cb)mergeSort);
}


static PyObject* 
cSort_heap(PyObject* self, PyObject* args){
  return (PyObject*) runSort(args, (sort_cb)heapSort);
}


static PyObject*
cSort_quick(PyObject* self, PyObject* args, PyObject* kwds){
  return (PyObject*) runSort(args, (sort_cb)quickSort);
}


static char cSort_docs[] =
    "quick( list, low, high ): sort <list> elements from position <low> to <high>\n";


static PyMethodDef cSort_funcs[] = {
    {"quick", (PyCFunction)cSort_quick, METH_VARARGS|METH_KEYWORDS, cSort_docs},
    {"merge", (PyCFunction)cSort_merge, METH_VARARGS, cSort_docs},
    {"heap",  (PyCFunction)cSort_heap, 	METH_VARARGS, cSort_docs},
    {"bubble",(PyCFunction)cSort_bubble,METH_VARARGS, cSort_docs},
    {NULL, NULL, 0, NULL}
};


PyMODINIT_FUNC initcSort(void){
    Py_InitModule3("cSort", cSort_funcs,
                   "Sort the numbers");
}