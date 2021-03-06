// Autogenerated file for halcon type HImageArray

#include "pyhirsch.h"

static void
PyHirschImageArray_dealloc(PyHirschImageArray* self)
{
    if(self->ImageArray)
        delete self->ImageArray;
    PyObject_Del(self);
}

#if PY_MAJOR_VERSION >= 3
#define PyString_FromFormat PyUnicode_FromFormat
#define PyString_AsString PyUnicode_AsUTF8
#endif

static int
PyHirschImageArray_init(PyHirschImageArray *self, PyObject *args, PyObject */*kwds*/)
{
    PyObject *v;

    self->ImageArray=new Halcon::HImageArray;

    if (PyArg_ParseTuple(args,"O",&v) && PySequence_Check(v)) {
        bool error = false;
        for (int i=0; i<PySequence_Length(v); i++) {
            PyObject *el = PySequence_GetItem(v, i);

            if (PyHirschImage_Check(el)) 
                self->ImageArray->Append(*(((PyHirschImage*)el)->Image));
            else
                error = true;
  
            Py_DECREF(el);
            if (error) {
                PyObject *ErrorMessage = PyString_FromFormat("Unsupported type of element %d in sequence when initializing PyHTuple!", i+1);
                PyErr_SetString(PyExc_RuntimeError, PyString_AsString(ErrorMessage));
                Py_DECREF(ErrorMessage);
                break;
            }
        }
    }

    return 0;
}

#include "himagearray_autogen_methods_declarations.i"

static PyMethodDef PyHirschImageArray_methods[] = {
#include "himagearray_autogen_methods_list.i"
    {NULL}  /* Sentinel */
};

static Py_ssize_t PyHirschImageArray_Length(PyObject *o)
{
    Halcon::HImageArray *ImageArray = (((PyHirschImageArray*)o)->ImageArray);
    return ImageArray->Num(); // Return the length of the sequence
}

static PyObject *
PyHirschImageArray_GetItem(PyObject *o, Py_ssize_t i)
{
    Halcon::HImageArray *ImageArray = (((PyHirschImageArray*)o)->ImageArray);
    Halcon::HImage& Image((*ImageArray)[i]);
    return PyHirschImage_FromHImage(Image);
}

static PySequenceMethods PyHirschImageArray_sequence_methods = {
    PyHirschImageArray_Length,                /* sq_length */
    0,                                   /* sq_concat */
    0,                                   /* sq_repeat */
    PyHirschImageArray_GetItem,               /* sq_item */
    0
};

static PyObject* PyHirschImageArray_iter(PyObject *self)
{
  Py_INCREF(self);
  ((PyHirschImageArray*)self)->iter_pos = 0;
  return self;
}

static PyObject* PyHirschImageArray_iternext(PyObject *self)
{
    PyHirschImageArray *p = (PyHirschImageArray *)self;
    Halcon::HImageArray *ImageArray = p->ImageArray;

    if (p->iter_pos < ImageArray->Num()) {
        PyObject *ret = PyHirschImageArray_GetItem(self,p->iter_pos);
        p->iter_pos+=1;
        return ret;
    }
    else {
        /* Raising of standard StopIteration exception with empty value. */
        PyErr_SetNone(PyExc_StopIteration);
        return NULL;
    }
}

PyObject *PyHirschImageArray_FromHImageArray(Halcon::HImageArray ImageArray)
{
    PyHirschImageArray *v = (PyHirschImageArray*)PyObject_New(PyHirschImageArray, &PyHirschImageArrayType);
    v->ImageArray = new Halcon::HImageArray(ImageArray);
    return (PyObject*)v;
}

PyTypeObject PyHirschImageArrayType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "Hirsch.HImageArray",      /*tp_name*/
    sizeof(PyHirschImageArray), /*tp_basicsize*/
    0,                         /*tp_itemsize*/
    (destructor)PyHirschImageArray_dealloc,       /*tp_dealloc*/
    0,                         /*tp_print*/
    0,                         /*tp_getattr*/
    0,                         /*tp_setattr*/
    0,                         /*tp_compare*/
    0,                         /*tp_repr*/
    0,                         /*tp_as_number*/
    &PyHirschImageArray_sequence_methods,        /*tp_as_sequence*/
    0,                         /*tp_as_mapping*/
    0,                         /*tp_hash */
    0,                         /*tp_call*/
    0,                         /*tp_str*/
    0,                         /*tp_getattro*/
    0,                         /*tp_setattro*/
    0,                         /*tp_as_buffer*/
    Py_TPFLAGS_DEFAULT,        /*tp_flags*/
    "PyHirschImageArray",        /* tp_doc */
    0,		               /* tp_traverse */
    0,		               /* tp_clear */
    0,		               /* tp_richcompare */
    0,		               /* tp_weaklistoffset */
    PyHirschImageArray_iter,		 /* tp_iter */
    PyHirschImageArray_iternext,         /* tp_iternext */
    PyHirschImageArray_methods,  /* tp_methods */
    0,                         /* tp_members */
    0,                         /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc)PyHirschImageArray_init,          /* tp_init */
    0,                         /* tp_alloc */
    PyType_GenericNew,         /* tp_new */
};


void PyHirschImageArrayAddToModule(PyObject *m)
{
    Py_INCREF(&PyHirschImageArrayType);
    if (PyType_Ready(&PyHirschImageArrayType) < 0)
        return;
    PyModule_AddObject(m, "HImageArray", (PyObject *)&PyHirschImageArrayType);
}

