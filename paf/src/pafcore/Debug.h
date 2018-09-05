#pragma once
#include "Utility.h"
#include <unordered_map>
#include <Windows.h>

BEGIN_PAFCORE

template<typename T>
class LiveObjects
{
public:
	LiveObjects() : m_serialNumber(0)
	{
		InitializeCriticalSection(&m_mutex);
	}
	~LiveObjects()
	{
		DeleteCriticalSection(&m_mutex);
	}
public:
	void addPtr(T* p)
	{
		EnterCriticalSection(&m_mutex);
		m_objects.insert(std::make_pair(p, m_serialNumber++));
		LeaveCriticalSection(&m_mutex);
	}
	void removePtr(T* p)
	{
		EnterCriticalSection(&m_mutex);
		m_objects.erase(p);
		LeaveCriticalSection(&m_mutex);
	}
	void lock()
	{
		EnterCriticalSection(&m_mutex);
	}
	void unlock()
	{
		LeaveCriticalSection(&m_mutex);
	}
public:
	std::unordered_map<T*, size_t> m_objects;
	CRITICAL_SECTION m_mutex;
	size_t m_serialNumber;
};


END_PAFCORE
