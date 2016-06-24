#pragma once

#include "SyntaxNodeImpl.h"
#include <stdio.h>

struct TokenNode : SyntaxNodeImpl
{
	int m_tokenNo;
	int m_lineNo;
	int m_columnNo;
public:
	TokenNode(int nodeType, int tokenNo, int lineNo, int columnNo);
	void outputEmbededCodes(FILE* file, bool addSpace);
};

struct CompareTokenPtr
{
	bool operator()(const TokenNode* arg1, const TokenNode* arg2) const
	{
		return arg1->m_nodeType < arg2->m_nodeType;
	}
};

extern const char* g_keywordTokens[];
