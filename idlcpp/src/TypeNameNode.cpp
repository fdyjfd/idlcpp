#include "TypeNameNode.h"
#include "IdentifyNode.h"
#include "TypeAliasNode.h"
#include "ErrorList.h"
#include "RaiseError.h"
#include "ScopeListNode.h"
#include "SourceFile.h"
#include "Options.h"
#include "ClassNode.h"
#include "TemplateParameterNode.h"
#include "TemplateParametersNode.h"
#include "TypeNameListNode.h"
#include "TemplateClassInstanceNode.h"
#include "ProgramNode.h"
#include <assert.h>

void GetPrimitiveTypeName(std::string& typeName, PrimitiveType type)
{
	switch (type)
	{
	case pt_void:
		typeName = "void";
		break;
	case pt_bool:
		typeName = "bool";
		break;
	case pt_char:
		typeName = "char";
		break;
	case pt_schar:
		typeName = "signed char";
		break;
	case pt_uchar:
		typeName = "unsigned char";
		break;
	case pt_wchar_t:
		typeName = "wchar_t";
		break;
	case pt_short:
		typeName = "short";
		break;
	case pt_ushort:
		typeName = "unsigned short";
		break;
	case pt_long:
		typeName = "long";
		break;
	case pt_ulong:
		typeName = "unsigned long";
		break;
	case pt_longlong:
		typeName = "long long";
		break;
	case pt_ulonglong:
		typeName = "unsigned long long";
		break;
	case pt_int:
		typeName = "int";
		break;
	case pt_uint:
		typeName = "unsigned int";
		break;
	case pt_float:
		typeName = "float";
		break;
	case pt_double:
		typeName = "double";
		break;
	case pt_long_double:
		typeName = "long double";
		break;
	default:
		assert(false);
	}
}

TypeNameNode::TypeNameNode(TokenNode* keyword, PrimitiveType primitiveType)
{
	m_nodeType = snt_type_name;
	m_keyword = keyword;
	m_primitiveType = primitiveType;
	m_scopeList = 0;
	m_leftBracket = 0;
	m_parameterList = 0;
	m_rightBracket = 0;
	m_typeCategory = primitive_type;
	if(pt_void == primitiveType)
	{
		m_typeCategory = void_type;
	}
	m_typeInfo = 0;
}

TypeNameNode::TypeNameNode(ScopeListNode* scopeList)
{
	m_nodeType = snt_type_name;
	m_keyword = 0;
	m_primitiveType = pt_unknown;
	m_scopeList = scopeList;
	m_leftBracket = 0;
	m_parameterList = 0;
	m_rightBracket = 0;
	m_typeCategory = unknown_type;
	m_typeInfo = 0;
}

TypeNameNode::TypeNameNode(ScopeListNode* scopeList, TokenNode* leftBracket, TypeNameListNode* parameterList, TokenNode* rightBracket)
{
	m_nodeType = snt_type_name;
	m_keyword = 0;
	m_primitiveType = pt_unknown;
	m_scopeList = scopeList;
	m_leftBracket = leftBracket;
	m_parameterList = parameterList;
	m_rightBracket = rightBracket;
	m_typeCategory = unknown_type;
	m_typeInfo = 0;
}

size_t TypeNameNode::getParameterCount()
{
	size_t count = 0;
	TypeNameListNode* list = m_parameterList;
	while(0 != list)
	{
		++count;
		list = list->m_typeNameList;
	}
	return count;
}

bool TypeNameNode::isGlobal()
{
	return m_scopeList->m_global;
}

void TypeNameNode::getName(std::vector<std::string>& names)
{
	assert(names.empty());
	assert(0 != m_scopeList);
	ScopeListNode* list = m_scopeList;
	while (list)
	{
		names.push_back(list->m_name->m_str);
		list = list->m_scopeList;
	}
	std::reverse(names.begin(), names.end());
}

void TypeNameNode::getNameExceptTemplateParameters(std::string& name)
{
	assert(0 != m_scopeList);
	name.clear();
	std::vector<std::string> names;
	getName(names);
	if(isGlobal())
	{
		name.assign("::");
	}
	name.append(names.front());
	size_t count = names.size();
	for (size_t i = 1; i < count; ++i)
	{
		name.append("::");
		name.append(names[i]);
	}
}

void TypeNameNode::getTemplateParametersName(std::string& name)
{
	name.clear();
	if(m_parameterList)
	{
		name += '<';
		std::vector<TypeNameNode*> paramNodes;
		m_parameterList->collectTypeNameNodes(paramNodes);
		size_t count = paramNodes.size();
		for(size_t i = 0; i < count; ++i)
		{
			if(0 != i)
			{
				name += ',';
			}
			TypeNameNode* paramNode = paramNodes[i];
			std::string paramName;
			paramNode->getName(paramName);
			name.append(paramName);
		}
		name += '>';
	}
}

void TypeNameNode::getName(std::string& name)
{
	if(0 != m_keyword)
	{
		assert(0 == m_scopeList);
		GetPrimitiveTypeName(name, m_primitiveType);
		return;
	}
	getNameExceptTemplateParameters(name);
	if(m_parameterList)
	{
		std::string paramsName;
		getTemplateParametersName(paramsName);
		name += paramsName;
	}
}

TypeCategory TypeNameNode::getRelativeName(std::string& typeName, ScopeNode* scopeNode, TemplateArgumentMap* templateArguments)
{
	typeName.clear();
	if (0 != m_keyword)
	{
		GetPrimitiveTypeName(typeName, m_primitiveType);
	}
	else if(isTemplateParameter())
	{
		getName(typeName);
		if(templateArguments)
		{
			auto it = templateArguments->find(typeName);
			if(it != templateArguments->end())
			{
				TypeNameNode* typeNameNode = it->second;
				return typeNameNode->getRelativeName(typeName, scopeNode, templateArguments);				
			}
		}
	}
	else
	{
		assert(0 != m_typeInfo);
		MemberNode* typeNode = m_typeInfo->m_typeNode;
		ClassNode* classNode = 0;
		TypeNameListNode* oldTemplateArgumentList = 0;
		if(typeNode->isTemplateClass())
		{
			classNode = static_cast<ClassNode*>(typeNode);
			oldTemplateArgumentList = classNode->setTemplateArgumentList(m_parameterList);
		}
		typeNode->getRelativeName(typeName, scopeNode, templateArguments);
		if(classNode)
		{
			classNode->setTemplateArgumentList(oldTemplateArgumentList);
		}
	}
	return m_typeCategory;
}

TypeCategory TypeNameNode::getFullName(std::string& typeName, TemplateArgumentMap* templateArguments)
{
	return getRelativeName(typeName, 0, templateArguments);
}

TypeInfo* TypeNameNode::checkTemplateTypeName_(ScopeNode* scopeNode, std::vector<TemplateParameterNode*>& templateParameters)
{
	assert(isTemplateForm());
	std::string partTypeName;
	getNameExceptTemplateParameters(partTypeName);

	TypeInfo* typeInfo = g_sourceFileManager.findTypeInfo(m_scopeList->m_name, partTypeName, isGlobal(), scopeNode);
	if(0 == typeInfo || !typeInfo->m_typeNode->isTemplateClass())
	{
		RaiseError_InvalidClassTemplateName(m_scopeList->m_name);
		return 0;
	}
	ClassNode* classNode = static_cast<ClassNode*>(typeInfo->m_typeNode);
	size_t paramCount = classNode->m_templateParameters->getParameterCount();
	std::vector<TypeNameNode*> argumentNodes;
	m_parameterList->collectTypeNameNodes(argumentNodes);
	size_t argCount = argumentNodes.size();
	if(paramCount != argCount)
	{
		if(paramCount < argCount)
		{
			RaiseError_TooManyTemplateArguments(m_scopeList->m_name);
		}
		else
		{
			RaiseError_TooFewTemplateArguments(m_scopeList->m_name);
		}
		return 0;
	}

	size_t argIndex = 0;
	for(; argIndex < argCount; ++argIndex)
	{
		TypeNameNode* typeNameNode = argumentNodes[argIndex];
		typeNameNode->checkTypeName(scopeNode);
		if(!(primitive_type == typeNameNode->m_typeCategory
			|| value_type == typeNameNode->m_typeCategory
			|| reference_type == typeNameNode->m_typeCategory
			|| template_parameter == typeNameNode->m_typeCategory))
		{
			break;
		}
	}
	if(argIndex < argCount)
	{
		TypeNameNode* typeNameNode = argumentNodes[argIndex];
		RaiseError_InvalidTemplateArgument(typeNameNode);
		return 0;
	}
	else
	{
		return typeInfo;
	}	

}

void TypeNameNode::checkTypeName_(ScopeNode* scopeNode, std::vector<TemplateParameterNode*>& templateParameters)
{
	assert(unknown_type == m_typeCategory);
	assert(0 == m_typeInfo);
	assert(0 != m_scopeList);

	m_typeCategory = type_not_found;

	std::string typeName;
	getName(typeName);

	size_t templateParamCount = templateParameters.size();
	for(size_t i = 0; i < templateParamCount; ++i)
	{
		TemplateParameterNode* param = templateParameters[i];
		if(param->m_name->m_str == typeName)
		{
			m_typeCategory = template_parameter;
			return;
		}
	}
	if(isTemplateForm())
	{
		m_typeInfo = checkTemplateTypeName_(scopeNode, templateParameters);
		if(m_typeInfo)
		{
			assert(m_typeInfo->m_typeNode->isTemplateClass());
			m_typeCategory = m_typeInfo->m_typeNode->getTypeCategory();
		}
	}
	else
	{
		m_typeInfo = g_sourceFileManager.findTypeInfo(m_scopeList->m_name, typeName, isGlobal(), scopeNode);
		if(m_typeInfo)
		{
			if(m_typeInfo->m_typeNode->isTemplateClass())
			{
				m_typeCategory = class_template;
			}
			else
			{
				m_typeCategory = m_typeInfo->m_typeNode->getTypeCategory();
			}
		}
	}
}

void TypeNameNode::checkTypeName(ScopeNode* scopeNode)
{
	if (unknown_type == m_typeCategory)
	{
		if (0 != m_keyword)
		{
			assert(pt_unknown != m_primitiveType);
			if (pt_void == m_primitiveType)
			{
				m_typeCategory = void_type;
			}
			else
			{
				m_typeCategory = primitive_type;
			}
		}
		else
		{
			std::vector<TemplateParameterNode*> templateParameters;
			if(scopeNode->isTemplateClass())
			{
				static_cast<ClassNode*>(scopeNode)->m_templateParameters->collectParameterNodes(templateParameters);
			}
			checkTypeName_(scopeNode, templateParameters);
			assert(unknown_type != m_typeCategory);
		}
	}
}

void TypeNameNode::checkTypeNameForTemplateClassInstance(TemplateClassInstanceNode* templateClassInstanceNode, TemplateArgumentMap* templateArguments)
{
	if(m_scopeList && template_parameter != m_typeCategory)
	{
		std::string fullName;
		getFullName(fullName, templateArguments);
		TypeInfo* typeInfo = g_sourceFileManager.findTypeInfo(m_scopeList->m_name, fullName, true, 0);
		if(0 == typeInfo)
		{
			RaiseError_TemplateClassInstanceInvalidTypeName(fullName.c_str(), templateClassInstanceNode->m_name);
		}
	}
}

bool CompareTypeNamePtr::operator()(const TypeNameNode* arg1, const TypeNameNode* arg2) const
{
	return arg1->m_typeInfo < arg2->m_typeInfo;
}

