#include "Python.h"

unsigned int fibonacci_c(unsigned int n) {
	if (n <= 1) 
		return n;
	return fibonacci_c(n - 1) + fibonacci_c(n - 2);
}	

static PyObject* fibonacci(PyObject* self, PyObject* args) {
	int n;
	if (!PyArg_ParseTuple(args, "i", &n))
		return NULL;
	int num = fibonacci_c(n);
	return Py_BuildValue("i", num);
}

static PyMethodDef methods[] = {
	{"fibonacci", fibonacci, METH_VARARGS, "Get Fibonacci number"},
	{NULL, NULL, 0, NULL}
};

static PyModuleDef fibo = {
	PyModuleDef_HEAD_INIT,
	"fibo_test", "Calculate Fibonacci number via c/c++",
	-1,
	methods
};

PyMODINIT_FUNC PyInit_fibo_test(void){
	return PyModule_Create(&fibo);
}
