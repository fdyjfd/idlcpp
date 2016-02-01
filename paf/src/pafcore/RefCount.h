#pragma once
#include "Utility.h"
#ifdef WIN32
#include <intrin.h>
#endif

BEGIN_PAFCORE

#ifdef WIN32
inline long_t Atomic_Increment(long_t * lpAddend)
{
	return _InterlockedIncrement(lpAddend);
}

inline long_t Atomic_Decrement(long_t * lpAddend)
{
	return _InterlockedDecrement(lpAddend);
}
#endif

template<typename T>
class RefCountObject : public T
{
public:
	RefCountObject()
	{
		m_refCount = 1;
	}
	template<typename A1>
	RefCountObject(A1 a1) : T(a1)
	{
		m_refCount = 1;
	}
	template<typename A1, typename A2>
	RefCountObject(A1 a1, A2 a2) : T(a1, a2)
	{
		m_refCount = 1;
	}
	template<typename A1, typename A2, typename A3>
	RefCountObject(A1 a1, A2 a2, A3 a3) : T(a1, a2, a3)
	{
		m_refCount = 1;
	}
	template<typename A1, typename A2, typename A3, typename A4>
	RefCountObject(A1 a1, A2 a2, A3 a3, A4 a4) : T(a1, a2, a3, a4)
	{
		m_refCount = 1;
	}
	template<typename A1, typename A2, typename A3, typename A4, typename A5>
	RefCountObject(A1 a1, A2 a2, A3 a3, A4 a4, A5 a5) : T(a1, a2, a3, a4, a5)
	{
		m_refCount = 1;
	}
	template<typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
	RefCountObject(A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6) : T(a1, a2, a3, a4, a5, a6)
	{
		m_refCount = 1;
	}
	template<typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
	RefCountObject(A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7) : T(a1, a2, a3, a4, a5, a6, a7)
	{
		m_refCount = 1;
	}
	template<typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
	RefCountObject(A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8) : T(a1, a2, a3, a4, a5, a6, a7, a8)
	{
		m_refCount = 1;
	}
	template<typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9>
	RefCountObject(A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9) : T(a1, a2, a3, a4, a5, a6, a7, a8, a9)
	{
		m_refCount = 1;
	}
public:	
	virtual long_t addRef()
	{
		return ++m_refCount;
	}
	virtual long_t release()
	{
		long_t res = --m_refCount;
		if(0 == res)
		{
			delete this;
		}
		return res;
	}
private:
	long_t m_refCount;
};


template<typename T>
class AtomicRefCountObject : public T
{
public:
	AtomicRefCountObject()
	{
		m_refCount = 1;
	}
	template<typename A1>
	AtomicRefCountObject(A1 a1) : T(a1)
	{
		m_refCount = 1;
	}
	template<typename A1, typename A2>
	AtomicRefCountObject(A1 a1, A2 a2) : T(a1, a2)
	{
		m_refCount = 1;
	}
	template<typename A1, typename A2, typename A3>
	AtomicRefCountObject(A1 a1, A2 a2, A3 a3) : T(a1, a2, a3)
	{
		m_refCount = 1;
	}
	template<typename A1, typename A2, typename A3, typename A4>
	AtomicRefCountObject(A1 a1, A2 a2, A3 a3, A4 a4) : T(a1, a2, a3, a4)
	{
		m_refCount = 1;
	}
	template<typename A1, typename A2, typename A3, typename A4, typename A5>
	AtomicRefCountObject(A1 a1, A2 a2, A3 a3, A4 a4, A5 a5) : T(a1, a2, a3, a4, a5)
	{
		m_refCount = 1;
	}
	template<typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
	AtomicRefCountObject(A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6) : T(a1, a2, a3, a4, a5, a6)
	{
		m_refCount = 1;
	}
	template<typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
	AtomicRefCountObject(A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7) : T(a1, a2, a3, a4, a5, a6, a7)
	{
		m_refCount = 1;
	}
	template<typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
	AtomicRefCountObject(A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8) : T(a1, a2, a3, a4, a5, a6, a7, a8)
	{
		m_refCount = 1;
	}
	template<typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9>
	AtomicRefCountObject(A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9) : T(a1, a2, a3, a4, a5, a6, a7, a8, a9)
	{
		m_refCount = 1;
	}
public:	
	virtual long_t addRef()
	{
		return Atomic_Increment(&m_refCount);
	}
	virtual long_t release()
	{
		long_t res = Atomic_Decrement(&m_refCount);
		if(0 == res)
		{
			delete this;
		}
		return res;
	}
private:
	long_t m_refCount;
};
	
END_PAFCORE
