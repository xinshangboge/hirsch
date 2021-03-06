// Autogenerated file for halcon type HXLD

#include "pyhirsch.h"

static void
PyHirschXLD_dealloc(PyHirschXLD* self)
{
    if(self->XLD)
        delete self->XLD;
    PyObject_Del(self);
}

static int
PyHirschXLD_init(PyHirschXLD *self, PyObject */*args*/, PyObject */*kwds*/)
{
    // TBD - Use PyArg_ParseTupleAndKeywords() to do special initilaziation
    self->XLD=new Halcon::HXLD;
    return 0;
}

#include "hxld_autogen_methods_declarations.i"

static PyMethodDef PyHirschXLD_methods[] = {
#include "hxld_autogen_methods_list.i"
    {NULL}  /* Sentinel */
};

PyObject *PyHirschXLD_FromHXLD(Halcon::HXLD XLD)
{
    PyHirschXLD *v = (PyHirschXLD*)PyObject_New(PyHirschXLD, &PyHirschXLDType);
    v->XLD = new Halcon::HXLD(XLD);
    return (PyObject*)v;
}

PyTypeObject PyHirschXLDType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "Hirsch.HXLD",      /*tp_name*/
    sizeof(PyHirschXLD), /*tp_basicsize*/
    0,                         /*tp_itemsize*/
    (destructor)PyHirschXLD_dealloc,       /*tp_dealloc*/
    0,                         /*tp_print*/
    0,                         /*tp_getattr*/
    0,                         /*tp_setattr*/
    0,                         /*tp_compare*/
    0,                         /*tp_repr*/
    0,                         /*tp_as_number*/
    0,        /*tp_as_sequence*/
    0,                         /*tp_as_mapping*/
    0,                         /*tp_hash */
    0,                         /*tp_call*/
    0,                         /*tp_str*/
    0,                         /*tp_getattro*/
    0,                         /*tp_setattro*/
    0,                         /*tp_as_buffer*/
    Py_TPFLAGS_DEFAULT,        /*tp_flags*/
    "PyHirschXLD",        /* tp_doc */
    0,		               /* tp_traverse */
    0,		               /* tp_clear */
    0,		               /* tp_richcompare */
    0,		               /* tp_weaklistoffset */
    0,		 /* tp_iter */
    0,         /* tp_iternext */
    PyHirschXLD_methods,  /* tp_methods */
    0,                         /* tp_members */
    0,                         /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc)PyHirschXLD_init,          /* tp_init */
    0,                         /* tp_alloc */
    PyType_GenericNew,         /* tp_new */
};


void PyHirschXLDAddToModule(PyObject *m)
{
    Py_INCREF(&PyHirschXLDType);
    if (PyType_Ready(&PyHirschXLDType) < 0)
        return;
    PyModule_AddObject(m, "HXLD", (PyObject *)&PyHirschXLDType);
}

