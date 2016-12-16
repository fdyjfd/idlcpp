#include "System.h"
#include "System.ic"
#include "System.mh"
#include "System.mc"

#include <windows.h>

namespace pafcore
{
	inline void System::LoadDLL(const char* fileName)
	{
		LoadLibraryA(fileName);
	}
}

