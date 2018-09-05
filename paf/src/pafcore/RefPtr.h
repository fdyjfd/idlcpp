#pragma once
#include "Utility.h"

BEGIN_PAFCORE

template<typename T>
class RefPtr
{
public:
	RefPtr() : m_ptr(0)
	{
	}

	RefPtr(const RefPtr<T>& arg)
		: m_ptr(arg.m_ptr)
	{
		if(0 != m_ptr)
		{
			m_ptr->addRef();
		}
	}
	RefPtr(RefPtr&& arg)
		: m_ptr(arg.m_ptr)
	{
		arg.m_ptr = 0;
	}

	~RefPtr()
	{
		if(0 != m_ptr)
		{
			m_ptr->release();
		}
	}
public:

	void assign(T* p)
	{
		if(m_ptr != p)
		{
			if(0 != p)
			{
				p->addRef();
			}
			if(0 != m_ptr)
			{
				m_ptr->release();
			}
			m_ptr = p;
		}
	}

	T* getPointer()
	{
		return m_ptr;
	}

	const T* getPointer() const
	{
		return m_ptr;
	}

	bool isNull() const
	{
		return (0 == m_ptr);
	}

	RefPtr<T>& operator = (const RefPtr<T>& arg)
	{
		assign(arg.m_ptr);
		return *this;
	}

	RefPtr<T>& operator = (T* p)
	{
		assign(p);
		return *this;
	}

	operator T*() 
	{
		return m_ptr;
	}
	
	operator const T*() const
	{
		return m_ptr;
	}

	T& operator*() throw()
	{
		return *m_ptr;
	}

	const T& operator*() const throw()
	{
		return *m_ptr;
	}

	T* operator->() throw()
	{
		return m_ptr;
	}

	const T* operator->() const throw()
	{
		return m_ptr;
	}

	bool operator == (const RefPtr& arg) const
	{
		return m_ptr == arg.m_ptr;
	}

	bool operator == (RefPtr& arg) const
	{
		return m_ptr == arg.m_ptr;
	}

	bool operator != (const RefPtr& arg) const
	{
		return m_ptr != arg.m_ptr;
	}

	bool operator != (RefPtr& arg) const
	{
		return m_ptr != arg.m_ptr;
	}

	bool operator == (const T* p) const
	{
		return (m_ptr == p);
	}

	bool operator == (T* p) const
	{
		return (m_ptr == p);
	}

	bool operator != (const T* p) const
	{
		return (m_ptr != p);
	}

	bool operator != (T* p) const
	{
		return (m_ptr != p);
	}

	operator bool () const
	{
		return 0 != m_ptr;
	}

	bool operator !() const
	{
		return 0 == m_ptr;
	}

protected:
	T* m_ptr;
};


END_PAFCORE
