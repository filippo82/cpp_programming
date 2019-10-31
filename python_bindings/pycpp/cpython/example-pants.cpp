#include <Python.h>

static PyObject *pants(PyObject *self, PyObject *args) {
  int input0;
  int input1;
  if (!PyArg_ParseTuple(args, "ii", &input0, &input1)) {
    return NULL;
  }

  return PyLong_FromLong((long)input0 * (long)input1);
}

static PyMethodDef example_methods[] = {
    {"pants", pants, METH_VARARGS, "Returns a square of an integer"},
    {NULL, NULL, 0, NULL},
};

static struct PyModuleDef example_definition = {
    PyModuleDef_HEAD_INIT,
    "example",
    "example module containing pants() function",
    -1,
    example_methods,
};

PyMODINIT_FUNC PyInit_example(void) {
  Py_Initialize();
  PyObject *m = PyModule_Create(&example_definition);

  return m;
}
