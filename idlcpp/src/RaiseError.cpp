#include "RaiseError.h"
#include "ErrorList.h"
#include "IdentifyNode.h"
#include "TypeNameNode.h"
#include "ParameterNode.h"
#include "MethodNode.h"
#include "ScopeNameListNode.h"
#include "ScopeNameNode.h"
#include <assert.h>

const size_t error_info_buffer_size = 512;

void RaiseError_InvalidTypeName(IdentifyNode* node)
{
	char buf[error_info_buffer_size];
	sprintf_s(buf, "\'%s\' : is not a type name", node->m_str.c_str());
	ErrorList_AddItem_CurrentFile(node->m_lineNo,
		node->m_columnNo, semantic_error_invalid_type_name, buf);
}

void RaiseError_InvalidTypeName(ScopeNameListNode* node)
{
	char buf[error_info_buffer_size];
	std::string str;
	node->getString(str);
	IdentifyNode* identifyNode = node->m_scopeName->m_name;
	sprintf_s(buf, "\'%s\' : is not a type name", str.c_str());
	ErrorList_AddItem_CurrentFile(identifyNode->m_lineNo,
		identifyNode->m_columnNo, semantic_error_invalid_type_name, buf);
}

void RaiseError_InvalidTypeName(TypeNameNode* node)
{
	char buf[error_info_buffer_size];
	std::string str;
	node->getString(str);
	IdentifyNode* identifyNode = node->m_scopeNameList->m_scopeName->m_name;
	sprintf_s(buf, "\'%s\' : is not a type name", str.c_str());
	ErrorList_AddItem_CurrentFile(identifyNode->m_lineNo,
		identifyNode->m_columnNo, semantic_error_invalid_type_name, buf);
}

void RaiseError_InvalidParameterType(ParameterNode* node)
{
	TypeNameNode* typeName = node->m_typeName;
	TokenNode* out = node->m_out;
	TokenNode* passing = node->m_passing;

	char buf[error_info_buffer_size];
	std::string str;
	typeName->getString(str);

	const char* strOut = "";
	if (out)
	{
		switch (out->m_nodeType)
		{
		case snt_keyword_new:
			strOut = node->m_array ? "new []" : "new";
			break;
		case snt_keyword_ptr:
			strOut = "ptr";
			break;
		}
	}
	const char* strPassing = "";
	if (passing)
	{
		switch (passing->m_nodeType)
		{
		case snt_keyword_new:
			strPassing = "new";
			break;
		case snt_keyword_ptr:
			strPassing = "ptr";
			break;
		case snt_keyword_ref:
			strPassing = "ref";
			break;
		}
	}
	TokenNode* tokenNode = typeName->m_scopeNameList ? typeName->m_scopeNameList->m_scopeName->m_name : typeName->m_keyword;
	sprintf_s(buf, "\'%s %s %s\' : is an invalid type", str.c_str(), strOut, strPassing);
	ErrorList_AddItem_CurrentFile(tokenNode->m_lineNo,
		tokenNode->m_columnNo, semantic_error_invalid_type_name, buf);
}

void RaiseError_InvalidResultType(MethodNode* node)
{
	TypeNameNode* result = node->m_resultTypeName;
	TokenNode* passing = node->m_passing;
	char buf[error_info_buffer_size];
	std::string str;
	result->getString(str);

	const char* strPassing = "";
	if(passing)
	{ 
		switch (passing->m_nodeType)
		{
		case snt_keyword_new:
			strPassing = "new";
			break;
		case snt_keyword_ptr:
			strPassing = "ptr";
			break;
		case snt_keyword_ref:
			strPassing = "ref";
			break;
		}
	}
	TokenNode* tokenNode = result->m_scopeNameList ? result->m_scopeNameList->m_scopeName->m_name : result->m_keyword;
	sprintf_s(buf, "\'%s %s\' : can not be a result type", str.c_str(), strPassing);
	ErrorList_AddItem_CurrentFile(tokenNode->m_lineNo,
		tokenNode->m_columnNo, semantic_error_invalid_type_name, buf);
}

void RaiseError_InvalidClassTemplateName(IdentifyNode* node)
{
	char buf[error_info_buffer_size];
	sprintf_s(buf, "\'%s\' : is not a class template name", node->m_str.c_str());
	ErrorList_AddItem_CurrentFile(node->m_lineNo,
		node->m_columnNo, semantic_error_invalid_class_template_name, buf);
}

void RaiseError_InvalidClassTemplateName(TypeNameNode* node)
{
	char buf[error_info_buffer_size];
	std::string name;
	node->getString(name);
	IdentifyNode* identifyNode = node->m_scopeNameList->m_scopeName->m_name;
	sprintf_s(buf, "\'%s\' : is not a class template name", name.c_str());
	ErrorList_AddItem_CurrentFile(identifyNode->m_lineNo,
		identifyNode->m_columnNo, semantic_error_invalid_class_template_name, buf);
}

void RaiseError_TooManyTemplateArguments(IdentifyNode* node)
{
	char buf[error_info_buffer_size];
	sprintf_s(buf, "\'%s\' : too many template arguments", node->m_str.c_str());
	ErrorList_AddItem_CurrentFile(node->m_lineNo,
		node->m_columnNo, semantic_error_too_many_template_arguments, buf);
}

void RaiseError_TooFewTemplateArguments(IdentifyNode* node)
{
	char buf[error_info_buffer_size];
	sprintf_s(buf, "\'%s\' : too few template arguments", node->m_str.c_str());
	ErrorList_AddItem_CurrentFile(node->m_lineNo,
		node->m_columnNo, semantic_error_too_few_template_arguments, buf);
}

void RaiseError_InvalidTemplateArgument(TypeNameNode* node)
{
	char buf[error_info_buffer_size];
	std::string name;
	node->getString(name);
	sprintf_s(buf, "\'%s\' : is not a valid template argument", name.c_str());
	ErrorList_AddItem_CurrentFile(node->m_scopeNameList->m_scopeName->m_name->m_lineNo,
		node->m_scopeNameList->m_scopeName->m_name->m_columnNo, semantic_error_invalid_template_argument, buf);
}

void RaiseError_TemplateParameterRedefinition(IdentifyNode* node)
{
	char buf[error_info_buffer_size];
	sprintf_s(buf, "redefinition of template parameter \'%s\'", node->m_str.c_str());
	ErrorList_AddItem_CurrentFile(node->m_lineNo,
		node->m_columnNo, semantic_error_template_parameter_redefinition, buf);
}

void RaiseError_TemplateClassInstanceInvalidTypeName(const char* typeName, IdentifyNode* node)
{
	char buf[error_info_buffer_size];
	sprintf_s(buf, "\'%s\' : template class is not explicit instantition", typeName);
	ErrorList_AddItem_CurrentFile(node->m_lineNo,
		node->m_columnNo, semantic_error_template_class_not_instantiton, buf);
}

void RaiseError_TemplateInterfaceNotSupported(IdentifyNode* node)
{
	char buf[error_info_buffer_size];
	sprintf_s(buf, "\'%s\' : template interface is not supported", node->m_str.c_str());
	ErrorList_AddItem_CurrentFile(node->m_lineNo,
		node->m_columnNo, semantic_error_template_interface_not_supported, buf);
}

void RaiseError_MissingReferenceBaseType(IdentifyNode* node)
{
	char buf[error_info_buffer_size];
	sprintf_s(buf, "\'%s\' : reference type must inherited from ::pafcore::Reference", node->m_str.c_str());
	ErrorList_AddItem_CurrentFile(node->m_lineNo,
		node->m_columnNo, semantic_error_missing_reference_base_type, buf);
}

void RaiseError_InterfaceMethodIsNotVirtual(IdentifyNode* node)
{
	char buf[error_info_buffer_size];
	sprintf_s(buf, "\'%s\' : interface method must be virtual or abstract", node->m_str.c_str());
	ErrorList_AddItem_CurrentFile(node->m_lineNo,
		node->m_columnNo, semantic_error_missing_reference_base_type, buf);
}
