#include "ErrorList.h"
#include "SourceFile.h"

const char* g_errorStrings[] =
{
	"file not existing",
	"open file failed",

	"internal error",
	"invalid string",
	"unterminated code",
	"unterminated comment",

	"native type as namespace name",
	"native type as type name",
	"type name as namespace name",
	"type redefined",
	"enumerator redefined",
	"missing type specifier",
	"constructor with return type",
	"constructor with modifier",
	"member name equal to class name",
	"member redefined",
	"primitive type as base",
	"base type",
	"base redeclared",
	"invalid package name",
	"invalid type name",
	"invalid class template name",
	"missing template argument list",
	"too few template arguments",
	"too many template arguments",
	"invalid template argument",
	"ambiguous type name",
	"template parameter redefinition",
	"template class not instantiton",
	"template interface not supported",
	"missing reference base type",
};

void ErrorList::addItem(const char* fileName, int lineNo, int columnNo, ErrorCode errorCode, const char* errorText)
{
	ErrorInfo errorInfo;
	errorInfo.fileName = m_fileNames.insert(fileName).first->c_str();
	errorInfo.lineNo = lineNo;
	errorInfo.columnNo = columnNo;
	errorInfo.errorCode = errorCode;
	errorInfo.errorText = errorText;
	m_errorInfos.push_back(errorInfo);
}

ErrorList g_errorList;

extern "C"
{
extern int yylineno;
extern int yycolumnno;
}

void ErrorList_AddItem(const char* fileName, int lineNo, int columnNo, ErrorCode errorCode, const char* errorText)
{
	g_errorList.addItem(fileName, lineNo, columnNo, errorCode, errorText);
}

void ErrorList_AddItem_CurrentFile(ErrorCode errorCode, const char* errorText)
{
	g_errorList.addItem(getCurrentSourceFileName(), yylineno, yycolumnno, errorCode, errorText);
}

void ErrorList_AddItem_CurrentFile(int lineNo, int columnNo, ErrorCode errorCode, const char* errorText)
{
	g_errorList.addItem(getCurrentSourceFileName(), lineNo, columnNo, errorCode, errorText);
}

//void ErrorList_AddItem_MainFile(int lineNo, int columnNo, ErrorCode errorCode, const char* errorText)
//{
//	g_errorList.addItem(getMainSourceFileName(), lineNo, columnNo, errorCode, errorText);
//}


int ErrorList_ErrorCount()
{
	return g_errorList.m_errorInfos.size();
}

void ErrorList_Output()
{
	size_t count = g_errorList.m_errorInfos.size();
	for(size_t i = 0; i < count; ++i)
	{
		ErrorList::ErrorInfo& err = g_errorList.m_errorInfos[i];
		fprintf(stderr, "%s(%d,%d): error %.4d : %s, %s\n", err.fileName, err.lineNo, err.columnNo, err.errorCode, 
			g_errorStrings[err.errorCode], err.errorText.c_str());
	}
}
