#pragma once

#include "TokenNode.h"
#include <string>

struct IdentifyNode : TokenNode
{
	std::string m_str;
public:
	IdentifyNode(const char* str, int tokenNo, int lineNo, int columnNo);
	IdentifyNode(const char* str, size_t len, int tokenNo, int lineNo, int columnNo);
};

struct CompareIdentifyPtr
{
	bool operator()(const IdentifyNode* arg1, const IdentifyNode* arg2) const
	{
		return arg1->m_str < arg2->m_str;
	}
};

