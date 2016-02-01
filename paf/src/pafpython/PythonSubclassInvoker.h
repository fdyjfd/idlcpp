#pragma once

#include "Utility.h"
#include "../pafcore/SubclassInvoker.h"
#include "Python.h"

BEGIN_PAFPYTHON

struct PythonSubclassInvoker : public pafcore::SubclassInvoker
{
public:
	PythonSubclassInvoker(PyObject* pyObject);
	~PythonSubclassInvoker();
public:
	virtual pafcore::ErrorCode invoke(const char* name, pafcore::Variant* result, pafcore::Variant* self, pafcore::Variant* args, size_t numArgs);
public:
	PyObject* m_pyObject;
};

END_PAFPYTHON
