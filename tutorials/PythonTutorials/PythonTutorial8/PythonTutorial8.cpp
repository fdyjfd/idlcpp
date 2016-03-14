#include <tchar.h>
#include <windows.h>
#include "Python.h"
#include "../../../paf/src/pafpython/PythonWrapper.h"


#if defined(_DEBUG)
#pragma comment(lib,"pafcore_d.lib")
#pragma comment(lib,"pafpython_d.lib")
#else
#pragma comment(lib,"pafcore.lib")
#pragma comment(lib,"pafpython.lib")
#endif

int _tmain(int argc, _TCHAR* argv[])
{
	const char* path = "tutorial8";

	PyImport_AppendInittab("pafpython", &PyInit_PafPython);

	Py_Initialize();
	PyObject* pName = PyUnicode_FromString(path);
	PyObject* pModule = PyImport_Import(pName);
	Py_DECREF(pName);
	if(pModule != NULL)
	{
		Py_DECREF(pModule);
	}
	else
	{
		PyErr_Print();
		fprintf(stderr, "Failed to load \"%s\"\n", path);
	}
	Py_Finalize();
 	return 0;
}


