#pragma once
#include "Utility.h"
#include <intrin.h>

BEGIN_PAFCORE

inline long_t Atomic_Increment(volatile long_t * lpAddend)
{
	return _InterlockedIncrement(lpAddend);
}

inline long_t Atomic_Decrement(volatile long_t * lpAddend)
{
	return _InterlockedDecrement(lpAddend);
}

class RefCountObject : public VirtualDestructor
{
public:
	RefCountObject() : m_refCount(1)
	{}
	long_t addRef()
	{
		return ++m_refCount;
	}
	long_t release()
	{
		long_t res = --m_refCount;
		if (0 == res)
		{
			delete this;
		}
		return res;
	}
private:
	long_t m_refCount;
};

class AtomicRefCountObject : public VirtualDestructor
{
public:
	AtomicRefCountObject() : m_refCount(1)
	{}
	long_t addRef()
	{
		return Atomic_Increment(&m_refCount);
	}
	long_t release()
	{
		long_t res = Atomic_Decrement(&m_refCount);
		if (0 == res)
		{
			delete this;
		}
		return res;
	}
private:
	volatile long_t m_refCount;
};

class DebugRefCountObject : public VirtualDestructor
{
public:
	DebugRefCountObject() : m_refCount(1)
	{}
	long_t addRef()
	{
		return Atomic_Increment(&m_refCount);
	}
	long_t release()
	{
		long_t res = Atomic_Decrement(&m_refCount);
		if (0 == res)
		{
			delete this;
		}
		return res;
	}
private:
	volatile long_t m_refCount;
};

template<typename T>
class RefCountImpl : public T
{
public:
	RefCountImpl()
	{
		m_refCount = 1;
	}
	template<typename A1>
	RefCountImpl(A1 a1) : T(a1)
	{
		m_refCount = 1;
	}
	template<typename A1, typename A2>
	RefCountImpl(A1 a1, A2 a2) : T(a1, a2)
	{
		m_refCount = 1;
	}
	template<typename A1, typename A2, typename A3>
	RefCountImpl(A1 a1, A2 a2, A3 a3) : T(a1, a2, a3)
	{
		m_refCount = 1;
	}
	template<typename A1, typename A2, typename A3, typename A4>
	RefCountImpl(A1 a1, A2 a2, A3 a3, A4 a4) : T(a1, a2, a3, a4)
	{
		m_refCount = 1;
	}
	template<typename A1, typename A2, typename A3, typename A4, typename A5>
	RefCountImpl(A1 a1, A2 a2, A3 a3, A4 a4, A5 a5) : T(a1, a2, a3, a4, a5)
	{
		m_refCount = 1;
	}
	template<typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
	RefCountImpl(A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6) : T(a1, a2, a3, a4, a5, a6)
	{
		m_refCount = 1;
	}
	template<typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
	RefCountImpl(A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7) : T(a1, a2, a3, a4, a5, a6, a7)
	{
		m_refCount = 1;
	}
	template<typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
	RefCountImpl(A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8) : T(a1, a2, a3, a4, a5, a6, a7, a8)
	{
		m_refCount = 1;
	}
	template<typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9>
	RefCountImpl(A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9) : T(a1, a2, a3, a4, a5, a6, a7, a8, a9)
	{
		m_refCount = 1;
	}
	template<typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10>
	RefCountImpl(A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9, A10 a10) : T(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10)
	{
		m_refCount = 1;
	}
	template<typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11>
	RefCountImpl(A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9, A10 a10, A11 a11) : T(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11)
	{
		m_refCount = 1;
	}
	template<typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12>
	RefCountImpl(A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9, A10 a10, A11 a11, A12 a12) : T(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12)
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
		if (0 == res)
		{
			delete this;
		}
		return res;
	}
private:
	long_t m_refCount;
};


template<typename T>
class AtomicRefCountImpl : public T
{
public:
	AtomicRefCountImpl()
	{
		m_refCount = 1;
	}
	template<typename A1>
	AtomicRefCountImpl(A1 a1) : T(a1)
	{
		m_refCount = 1;
	}
	template<typename A1, typename A2>
	AtomicRefCountImpl(A1 a1, A2 a2) : T(a1, a2)
	{
		m_refCount = 1;
	}
	template<typename A1, typename A2, typename A3>
	AtomicRefCountImpl(A1 a1, A2 a2, A3 a3) : T(a1, a2, a3)
	{
		m_refCount = 1;
	}
	template<typename A1, typename A2, typename A3, typename A4>
	AtomicRefCountImpl(A1 a1, A2 a2, A3 a3, A4 a4) : T(a1, a2, a3, a4)
	{
		m_refCount = 1;
	}
	template<typename A1, typename A2, typename A3, typename A4, typename A5>
	AtomicRefCountImpl(A1 a1, A2 a2, A3 a3, A4 a4, A5 a5) : T(a1, a2, a3, a4, a5)
	{
		m_refCount = 1;
	}
	template<typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
	AtomicRefCountImpl(A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6) : T(a1, a2, a3, a4, a5, a6)
	{
		m_refCount = 1;
	}
	template<typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
	AtomicRefCountImpl(A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7) : T(a1, a2, a3, a4, a5, a6, a7)
	{
		m_refCount = 1;
	}
	template<typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
	AtomicRefCountImpl(A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8) : T(a1, a2, a3, a4, a5, a6, a7, a8)
	{
		m_refCount = 1;
	}
	template<typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9>
	AtomicRefCountImpl(A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9) : T(a1, a2, a3, a4, a5, a6, a7, a8, a9)
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
		if (0 == res)
		{
			delete this;
		}
		return res;
	}
private:
	volatile long_t m_refCount;
};


template<typename T>
class DummyRefCountImpl : public T
{
public:
	DummyRefCountImpl()
	{
	}
	template<typename A1>
	DummyRefCountImpl(A1 a1) : T(a1)
	{
	}
	template<typename A1, typename A2>
	DummyRefCountImpl(A1 a1, A2 a2) : T(a1, a2)
	{
	}
	template<typename A1, typename A2, typename A3>
	DummyRefCountImpl(A1 a1, A2 a2, A3 a3) : T(a1, a2, a3)
	{
	}
	template<typename A1, typename A2, typename A3, typename A4>
	DummyRefCountImpl(A1 a1, A2 a2, A3 a3, A4 a4) : T(a1, a2, a3, a4)
	{
	}
	template<typename A1, typename A2, typename A3, typename A4, typename A5>
	DummyRefCountImpl(A1 a1, A2 a2, A3 a3, A4 a4, A5 a5) : T(a1, a2, a3, a4, a5)
	{
	}
	template<typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
	DummyRefCountImpl(A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6) : T(a1, a2, a3, a4, a5, a6)
	{
	}
	template<typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
	DummyRefCountImpl(A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7) : T(a1, a2, a3, a4, a5, a6, a7)
	{
	}
	template<typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
	DummyRefCountImpl(A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8) : T(a1, a2, a3, a4, a5, a6, a7, a8)
	{
	}
	template<typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9>
	DummyRefCountImpl(A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9) : T(a1, a2, a3, a4, a5, a6, a7, a8, a9)
	{
	}
public:
	virtual long_t addRef()
	{
		return 0;
	}
	virtual long_t release()
	{
		delete this;
		return 0;
	}
};

template<typename T>
class DebugRefCountImpl : public T
{
public:
	DebugRefCountImpl()
	{
		m_refCount = 1;
	}
	template<typename A1>
	DebugRefCountImpl(A1 a1) : T(a1)
	{
		m_refCount = 1;
	}
	template<typename A1, typename A2>
	DebugRefCountImpl(A1 a1, A2 a2) : T(a1, a2)
	{
		m_refCount = 1;
	}
	template<typename A1, typename A2, typename A3>
	DebugRefCountImpl(A1 a1, A2 a2, A3 a3) : T(a1, a2, a3)
	{
		m_refCount = 1;
	}
	template<typename A1, typename A2, typename A3, typename A4>
	DebugRefCountImpl(A1 a1, A2 a2, A3 a3, A4 a4) : T(a1, a2, a3, a4)
	{
		m_refCount = 1;
	}
	template<typename A1, typename A2, typename A3, typename A4, typename A5>
	DebugRefCountImpl(A1 a1, A2 a2, A3 a3, A4 a4, A5 a5) : T(a1, a2, a3, a4, a5)
	{
		m_refCount = 1;
	}
	template<typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
	DebugRefCountImpl(A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6) : T(a1, a2, a3, a4, a5, a6)
	{
		m_refCount = 1;
	}
	template<typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
	DebugRefCountImpl(A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7) : T(a1, a2, a3, a4, a5, a6, a7)
	{
		m_refCount = 1;
	}
	template<typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
	DebugRefCountImpl(A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8) : T(a1, a2, a3, a4, a5, a6, a7, a8)
	{
		m_refCount = 1;
	}
	template<typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9>
	DebugRefCountImpl(A1 a1, A2 a2, A3 a3, A4 a4, A5 a5, A6 a6, A7 a7, A8 a8, A9 a9) : T(a1, a2, a3, a4, a5, a6, a7, a8, a9)
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
		if (0 == res)
		{
			delete this;
		}
		return res;
	}
private:
	volatile long_t m_refCount;
};

END_PAFCORE
