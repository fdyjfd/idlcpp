#pragma once

#include "Utility.h"
#include <unordered_set>

BEGIN_PAFSTD

class PAFSTD_EXPORT StringPool
{
private:
	struct Hash_String
	{
		size_t operator ()(const char* str) const
		{
			size_t seed = 0;
			for (const char* p = str; 0 != *p; ++p)
			{
				seed ^= size_t(*p) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
			}
			return seed;
		}
	};
	struct Equal_String
	{
		bool operator() (const char* lhs, const char* rhs) const
		{
			return (0 == strcmp(lhs, rhs));
		}
	};
public:
	StringPool();
	~StringPool();
private:
	StringPool(const StringPool&);
	StringPool& operator = (const StringPool&);
public:
	typedef std::unordered_set<const char*, Hash_String, Equal_String> StringContainer;
	typedef StringContainer::iterator iterator;
public:
	iterator begin()
	{
		return m_strings.begin();
	}
	iterator end()
	{
		return m_strings.end();
	}
	size_t size()
	{
		return m_strings.size();
	}
	iterator find(const char* str)
	{
		return m_strings.find(str);
	}
	const char* getString(const char* str);
	const char* findString(const char* str);
private:
	StringContainer m_strings;
};

END_PAFSTD
