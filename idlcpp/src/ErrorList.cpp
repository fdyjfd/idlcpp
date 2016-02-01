#include "ErrorList.h"
#include "SourceFile.h"

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
		fprintf(stderr, "%s(%d,%d):error:%.4d,%s\n", err.fileName, err.lineNo, err.columnNo, err.errorCode, err.errorText.c_str());
	}
}
