#pragma once

#include <memory.h>

template<size_t local_size>
class TempBuffer
{
public:
	TempBuffer(size_t size)
	{
		if(local_size < size)
		{
			m_pointer = malloc(size);
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
			free(m_pointer);
		}
	}
	void* GetBuffer()
	{
		return m_pointer;
	}
private:
	char m_localBuffer[local_size];
	void* m_pointer;
};
