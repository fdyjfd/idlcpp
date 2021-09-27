#include "ErrorList.h"
#include "Compiler.h"
#include "SourceFile.h"
#include "IdentifyNode.h"
#include "TemplateClassInstanceNode.h"
#include "TypeTree.h"

const char* g_errorStrings[] =
{
	"",
	"file not existing",
	"open file failed",

	"internal error",
	"invalid string",
	"unterminated code",
	"unterminated comment",

	"namespace redefined",
	"type redefined",
	"template redefined",
	"enumerator redefined",
	"nested template class",

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
	"invalid_ arameter",
	"invalid result",
	"invalid field",
	"invalid property",
	"invalid class template name",

	"missing template argument list",
	"too few template arguments",
	"too many template arguments",
	"invalid template argument",
	"ambiguous type name",
	"ambiguous template name",
	"template parameter redefinition",
	"template class not instantiton",
	"template interface not supported",
	"missing reference base type",
	"error in template class instance",
	"too few formal parameters",
	"too many formal parameters",
	"semantic error operator can not be static",
	"semantic error override method must be virtual or abstract",
	"semantic error attribute redefined",
};

ErrorList::ErrorList()
{
	m_templateClassInstanceNode = 0;
}

void ErrorList::addItem_(const char* fileName, int lineNo, int columnNo, ErrorCode errorCode, const char* errorText)
{
	ErrorInfo errorInfo;
	errorInfo.fileName = m_fileNames.insert(fileName).first->c_str();
	errorInfo.lineNo = lineNo;
	errorInfo.columnNo = columnNo;
	errorInfo.errorCode = errorCode;
	errorInfo.errorText = errorText;
	m_errorInfos.push_back(errorInfo);
}

void ErrorList::addItem(const char* fileName, int lineNo, int columnNo, ErrorCode errorCode, const char* errorText)
{
	addItem_(fileName, lineNo, columnNo, errorCode, errorText);
	if (m_templateClassInstanceNode)
	{
		std::string error = ": " + m_templateClassInstanceNode->getTypeNode()->m_name;
		SourceFile* sourceFile = m_templateClassInstanceNode->getSourceFile();
		addItem_(sourceFile->m_fileName.c_str(),
			m_templateClassInstanceNode->m_name->m_lineNo,
			m_templateClassInstanceNode->m_name->m_columnNo,
			semantic_error_template_class_instance_internal,
			error.c_str());
	}
}

void ErrorList::setTemplateClassInstance(TemplateClassInstanceNode* templateClassInstanceNode)
{
	m_templateClassInstanceNode = templateClassInstanceNode;
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

size_t ErrorList_ErrorCount()
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
