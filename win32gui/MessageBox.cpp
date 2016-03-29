#include <Windows.h>
#include "MessageBox.h"
#include "MessageBox.ic"
#include "MessageBox.mh"
#include "MessageBox.mc"


namespace win32gui
{
	void MessageBox::Show(::size_t hwnd, const char* text, const char* caption, ::uint_t flag)
	{
		::MessageBox(HWND(hwnd), text, caption, flag);
	}
}

