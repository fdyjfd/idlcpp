#include "PythonSubclassInvoker.h"
#include "Python.h"

BEGIN_PAFPYTHON

const size_t max_param_count = 20;

PyObject* VariantToPython(pafcore::Variant* variant);
pafcore::Variant* PythonToVariant(pafcore::Variant* value, PyObject* pyObject);

struct VariantWrapper
{
    PyObject_HEAD
	char m_var[sizeof(pafcore::Variant)];
};

PythonSubclassInvoker::PythonSubclassInvoker(PyObject* pyObject)
{
	m_pyObject = pyObject;
	Py_INCREF(pyObject);
}

PythonSubclassInvoker::~PythonSubclassInvoker()
{
	Py_DECREF(m_pyObject);
}

pafcore::ErrorCode PythonSubclassInvoker::invoke(const char* name, pafcore::Variant* result, pafcore::Variant* self, pafcore::Variant* args, size_t numArgs)
{
	PyObject* pyFunc = PyObject_GetAttrString(m_pyObject, name);
	if(pyFunc)
	{
		if(PyCallable_Check(pyFunc))
		{
			PyObject* pyArgs[max_param_count];
			PyObject* pyTuple = 0;
			if(numArgs)
			{
				pyTuple = PyTuple_New(numArgs);
				for(size_t i = 0; i < numArgs; ++i)
				{
					pyArgs[i] = VariantToPython(&args[i]);
					PyTuple_SetItem(pyTuple, i, pyArgs[i]);
				}
			}
			PyObject* pyResult = PyObject_CallObject(pyFunc, pyTuple);
			if(pyResult)
			{
				pafcore::Variant* value = PythonToVariant(result, pyResult);
				if(value != result)
				{
					result->move(*value);
				}
			}
			for(size_t i = 0; i < numArgs; ++i)
			{
				args[i].move(*(pafcore::Variant*)((VariantWrapper*)pyArgs[i])->m_var);
			}
			Py_XDECREF(pyTuple);
			Py_XDECREF(pyResult);
		}
		Py_DECREF(pyFunc);
		return pafcore::s_ok;
	}
	return pafcore::e_script_error;
}

END_PAFPYTHON
