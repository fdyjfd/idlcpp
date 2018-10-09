#include "FixedString.h"
#include "FixedString.mh"
#include "FixedString.ic"
#include "FixedString.mc"
#include <string.h>

BEGIN_PAFSTD

static char* s_emptyString = "";

FixedString::FixedString(const char* str)
{
	if (str && str[0])
	{
		m_length = strlen(str);
		size_t len = m_length + 1;
		m_str = paf_new char[len];
		memcpy(m_str, str, len * sizeof(char));
	}
	else
	{
		m_str = s_emptyString;
		m_length = 0;
	}
}

FixedString::~FixedString()
{
	if (s_emptyString != m_str)
	{
		delete[]m_str;
	}
}

END_PAFSTD

