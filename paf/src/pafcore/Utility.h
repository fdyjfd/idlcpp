#pragma once

#pragma warning(disable:4251)
#pragma warning(error:4150)

#include "Typedef.h"

#if defined PAFCORE_EXPORTS
	#define PAFCORE_EXPORT __declspec(dllexport)
	#define PAFCORE_TEMPLATE __declspec(dllexport)
#else
	#define PAFCORE_EXPORT __declspec(dllimport)
	#define PAFCORE_TEMPLATE
#endif

#define BEGIN_PAFCORE namespace pafcore {
#define END_PAFCORE }

PAFCORE_EXPORT void* __cdecl operator new(size_t size, const char* fileName, int line, int);
PAFCORE_EXPORT void* __cdecl operator new[](size_t size, const char* fileName, int line, int);
PAFCORE_EXPORT void __cdecl operator delete(void* block, const char* fileName, int line, int);
PAFCORE_EXPORT void __cdecl operator delete[](void* block, const char* fileName, int line, int);

#define PAF_WIDE_(s) L ## s
#define PAF_WIDE(s) PAF_WIDE_(s)

#ifdef _DEBUG
#define paf_new new(__FILE__, __LINE__, 0)


PAFCORE_EXPORT void PafAsset(wchar_t const* _Message, wchar_t const* _File, unsigned _Line);

#define PAF_ASSERT(expression) (void)(			\
		(!!(expression)) ||							\
		(PafAsset(PAF_WIDE(#expression), PAF_WIDE(__FILE__), (unsigned)(__LINE__)), 0) \
	)

#else

#define paf_new new
#define PAF_ASSERT(expression) ((void)0)

#endif

#define paf_array_size_of(a)	(sizeof(a)/sizeof(a[0]))
#define paf_field_size_of(s, m)	sizeof(((s*)0)->m)
#define paf_field_array_size_of(s, m)	(sizeof(((s*)0)->m)/sizeof(((s*)0)->m[0]))
#define paf_base_offset_of(d, b) (reinterpret_cast<ptrdiff_t>(static_cast<b*>(reinterpret_cast<d*>(1))) - 1)
#define paf_verify
#define AUTO_NEW_ARRAY_SIZE


#ifdef AUTO_NEW_ARRAY_SIZE

inline size_t paf_new_array_size_of(void* p)
{
	if (0 != p)
	{
		return *((size_t*)p - 1);
	}
	return 0;
}

template<typename T>
inline T* paf_new_array(size_t count)
{
	size_t* p = (size_t*) paf_new char[sizeof(T)*count + sizeof(size_t)];
	if(0 != p)
	{
		*p = count;
		++p;
		new(p)T[count];
	}
	return (T*)p;
}

template<typename T>
inline void paf_delete_array(T* p)
{
	if(0 != p)
	{
		size_t* addr = (size_t*)p - 1;
		size_t count = *addr;
		for(size_t i = 0; i < count; ++i)
		{
			p->~T();
			++p;
		}
		delete[] (char*)(addr);
	}
}
#else

inline size_t paf_new_array_size_of(void* p)
{
	return 0 != p ? 1 : 0;
}

template<typename T>
inline T* paf_new_array(size_t count)
{
	return paf_new T[count];
}

template<typename T>
inline void paf_delete_array(T* p)
{
	delete[] p;
}

#endif

BEGIN_PAFCORE


PAFCORE_EXPORT void DummyDestroyInstance(void* address);
PAFCORE_EXPORT void DummyDestroyArray(void* address);
PAFCORE_EXPORT void DummyAssign(void* dst, const void* src);

class PAFCORE_EXPORT VirtualDestructor
{
public:
	virtual ~VirtualDestructor()
	{}
};

END_PAFCORE

template<typename T>
inline void DeleteSetNull(T*& p)
{
	delete p;
	p = 0;
}

template<typename T>
inline void DeleteArraySetNull(T*& p)
{
	delete[] p;
	p = 0;
}

template<typename T>
inline void SafeAddRef(T* p)
{
	if (0 != p)
	{
		p->addRef();
	}
}

template<typename T>
inline void SafeAddRefArray(T* const * p, size_t count)
{
	for (size_t i = 0; i < count; ++i)
	{
		if (0 != p[i])
		{
			p[i]->addRef();
		}
	}
}

template<typename T>
inline void SafeRelease(T* p)
{
	if (0 != p)
	{
		p->release();
	}
}

template<typename T>
inline void SafeReleaseSetNull(T*& p)
{
	if (0 != p)
	{
		p->release();
		p = 0;
	}
}

template<typename T>
inline void SafeReleaseArray(T* const* p, size_t count)
{
	for (size_t i = 0; i < count; ++i)
	{
		if (0 != p[i])
		{
			p[i]->release();
		}
	}
}

template<typename T>
inline void SafeReleaseArraySetNull(T** p, size_t count)
{
	for (size_t i = 0; i < count; ++i)
	{
		if (0 != p[i])
		{
			p[i]->release();
			p[i] = 0;
		}
	}
}

template<typename T>
inline void CoSafeAddRef(T* p)
{
	if (0 != p)
	{
		p->AddRef();
	}
}

template<typename T>
inline void CoSafeRelease(T* p)
{
	if (0 != p)
	{
		p->Release();
	}
}

template<typename T>
inline void CoSafeReleaseSetNull(T*& p)
{
	if (0 != p)
	{
		p->Release();
		p = 0;
	}
}

template<typename T>
class AutoDeleteArray
{
public:
	AutoDeleteArray(T* p) : m_p(p)
	{}
	~AutoDeleteArray()
	{
		delete[]m_p;
	}
public:
	T* m_p;
};
