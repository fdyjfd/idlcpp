#pragma once

#include "SyntaxNodeImpl.h"

struct TokenNode : SyntaxNodeImpl
{
	int m_tokenNo;
	int m_lineNo;
	int m_columnNo;
public:
	TokenNode(int nodeType, int tokenNo, int lineNo, int columnNo);
	void outputEmbededCodes(FILE* file, bool addSpace);
};

extern const char* g_keywordTokens[];
