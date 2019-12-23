#include "System.h"
#include "System.ic"
#include "System.mh"
#include "System.mc"

#ifdef _WINDOWS

#include <windows.h>

namespace pafcore
{
	string_t System::GetProgramPath()
	{
		static char* s_buffer = 0;
		if (0 == s_buffer)
		{
			DWORD size = GetModuleFileNameA(0, 0, 0);
			s_buffer = new char[size + 1];
			s_buffer[0] = 0;
			GetModuleFileNameA(0, s_buffer, size + 1);
		}
		return s_buffer;
	}

	void System::LoadDLL(string_t fileName)
	{
		LoadLibraryA(fileName);
	}

	void System::OutputDebug(string_t str)
	{
		::OutputDebugStringA(str);
	}
	
	void System::DebugBreak()
	{
		::DebugBreak();
	}

}

#endif
