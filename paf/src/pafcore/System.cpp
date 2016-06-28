#include "System.h"
#include "System.ic"
#include "System.mh"
#include "System.mc"

#ifdef WIN32

#include <windows.h>

namespace pafcore
{
	inline void System::LoadDLL(const char* fileName)
	{
		LoadLibraryA(fileName);
	}
}

#endif
