#include "System.h"
#include "System.ic"
#include "System.mh"
#include "System.mc"

#ifdef _WINDOWS

#include <windows.h>

namespace pafcore
{
	inline void System::LoadDLL(string_t fileName)
	{
		LoadLibraryA(fileName);
	}
}

#endif
