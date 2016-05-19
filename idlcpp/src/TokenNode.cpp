#include "TokenNode.h"
#include "SourceFile.h"
#include <assert.h>

const char* g_keywordTokens[] = 
{
	"namespace ",
	"enum ",
	"class ",
	"struct ",
	"void",
	"virtual ",
	"virtual ",
	"static ",
	"const ",
	"get_",
	"void set_",
	"*",
	"*",
	"&",
	"typedef ",
};

TokenNode::TokenNode(int nodeType, int tokenNo, int lineNo, int columnNo)
{
	m_nodeType = nodeType;
	m_tokenNo = tokenNo;
	m_lineNo = lineNo;
	m_columnNo = columnNo;
}

void TokenNode::outputEmbededCodes(FILE* file, bool addSpace)
{
	char lastChar = g_sourceFileManager.outputEmbededCodes(file, this);
	if(isNumAlpha_(lastChar) && addSpace)
	{
		writeStringToFile(g_strSpaces, 1, file);
	}
}

