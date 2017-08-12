#include "Utility.h"
#include <string.h>
#include <malloc.h>
#include <assert.h>
#include <crtdbg.h>

BEGIN_PAFCORE

size_t stringBinarySearch(const char** strs, size_t stride, size_t count, const char* value)
{
	size_t left = 0;
	size_t right = count;
	while (left < right)
	{
		size_t mid = (left + right) / 2;
		int_t cmp = strcmp(value, *reinterpret_cast<const char**>(reinterpret_cast<size_t>(strs)+stride*mid));
		if (0 == cmp)
		{
			return mid;
		}
		if (cmp < 0)
		{
			right = mid;
		}
		else
		{
			left = mid + 1;
		}
	}
	return count;
}

void* allocateMemory(size_t n)
{
	return malloc(n);
}

void freeMemory(void* p)
{
	free(p);
}

void DummyDestroyInstance(void* address)
{}

void DummyDestroyArray(void* address)
{}

void DummyAssign(void* dst, const void* src)
{}


END_PAFCORE


void PafAsset(wchar_t const* _Message, wchar_t const* _File, unsigned _Line)
{
#ifdef _DEBUG
	_wassert(_Message, _File, _Line);
#endif
}

void* __cdecl operator new(size_t size, const char* fileName, int line, int)
{
	return operator new(size, 1, fileName, line);
}

void* __cdecl operator new[](size_t size, const char* fileName, int line, int)
{
	return operator new[](size, 1, fileName, line);
}

void __cdecl operator delete(void* block, const char* fileName, int line, int)
{
	operator delete(block, 1, fileName, line);
}

void __cdecl operator delete[](void* block, const char* fileName, int line, int)
{
	operator delete[](block, 1, fileName, line);
}
