#include "System.h"
#include "System.ic"
#include "System.mh"
#include "System.mc"

#ifdef _WINDOWS

#include <windows.h>

namespace pafcore
{
	void System::LoadDLL(string_t fileName)
	{
		LoadLibraryA(fileName);
	}

	void System::OutputDebug(string_t str)
	{
		::OutputDebugStringA(str);
	}
}

#endif
