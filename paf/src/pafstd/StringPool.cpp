#include "StringPool.h"
#include <algorithm>

BEGIN_PAFSTD

StringPool::StringPool()
{
}

StringPool::~StringPool()
{
	auto it = m_strings.begin();
	auto end = m_strings.end();
	while (it != end)
	{
		const char* str = *it;
		it = m_strings.erase(it);
		delete[]str;
	}
}

const char* StringPool::getString(const char* str)
{
	if (0 == str)
	{
		str = "";
	}
	auto it = m_strings.find(str);
	if (it != m_strings.end())
	{
		return *it;
	}
	else
	{
		size_t len = strlen(str) + 1;
		char* p = paf_new char[len];
		memcpy(p, str, len);
		m_strings.insert(p);
		return p;
	}
}

const char* StringPool::findString(const char* str)
{
	if (0 == str)
	{
		str = "";
	}
	auto it = m_strings.find(str);
	if (it != m_strings.end())
	{
		return *it;
	}
	else
	{
		return 0;
	}
}

END_PAFSTD
