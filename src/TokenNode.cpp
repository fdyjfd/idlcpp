#include "TokenNode.h"

#include "Utility.h"
#include "Compiler.h"
#include <assert.h>

const char* g_keywordTokens[] = 
{
	"::",
	"+=",
	"-=",
	"*=",
	"/=",
	"%=",
	"^=",
	"&=",
	"|=",
	"<<",
	">>",
	"<<=",
	">>=",
	"==",
	"!=",
	"<=",
	">=",
	"&&",
	"||",
	"++",
	"--",
	"++",
	"--",

	"namespace ",
	"enum ",
	"class ",
	"struct ",
	"template ",
	"virtual ",
	"virtual ",
	"static ",
	"const ",
	"operator ",
	"get_",
	"void set_",
	"typedef ",
	"struct ",
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
	g_compiler.outputEmbededCodes(file, this);
	if(isNumAlpha_(GetLastWrittenChar()) && addSpace)
	{
		writeSpaceToFile(file);
	}
}

