#pragma once

#include "Utility.h"

BEGIN_PAFSTD

template<typename T, size_t local_size>
class PAFSTD_TEMPLATE TempBuffer
{
private:
	TempBuffer(const TempBuffer&);
public:
	TempBuffer()
	{
		m_pointer = m_localBuffer;
	}
	explicit TempBuffer(size_t size)
	{
		if (local_size < size)
		{
			m_pointer = paf_new T[size];
		}
		else
		{
			m_pointer = m_localBuffer;
		}
	}
	~TempBuffer()
	{
		if(m_localBuffer != m_pointer)
		{
			delete[] m_pointer;
		}
	}
	void initialize(size_t size)
	{
		PAF_ASSERT(m_localBuffer == m_pointer);
		if(local_size < size)
		{
			m_pointer = paf_new T[size];
		}
	}
	T* getBuffer()
	{
		return m_pointer;
	}
private:
	T m_localBuffer[local_size];
	T* m_pointer;
};

END_PAFSTD


