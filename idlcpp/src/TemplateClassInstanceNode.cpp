#include "TemplateClassInstanceNode.h"
#include "SourceFile.h"
#include "ScopeListNode.h"
#include "TypeNameNode.h"
#include "TypeNameListNode.h"
#include "IdentifyNode.h"
#include "ClassNode.h"
#include "RaiseError.h"
#include "TemplateParametersNode.h"
#include "TemplateParameterNode.h"
#include <assert.h>

TemplateClassInstanceNode::TemplateClassInstanceNode(TokenNode* keyword, TokenNode* keyword2, IdentifyNode* name, 
	TokenNode* leftBracket, TypeNameListNode* parameterList, TokenNode* rightBracket, TokenNode* semicolon)
{
	m_nodeType = snt_template_class_instance;
	m_keyword = keyword;
	m_keyword2 = keyword2;
	m_name = name;
	m_leftBracket = leftBracket;
	m_parameterList = parameterList;
	m_rightBracket = rightBracket;
	m_semicolon = semicolon;
	m_typeCategory = unknown_type;
	ScopeListNode* scopeList = static_cast<ScopeListNode*>(newScopeList(0, name));
	m_templateTypeNameNode = static_cast<TypeNameNode*>(newTypeName(scopeList));
}

void TemplateClassInstanceNode::getRelativeName(std::string& relativeName, ScopeNode* scope, TemplateArgumentMap* templateArguments)
{
	MemberNode::getRelativeName(relativeName, scope, templateArguments);
	std::vector<TypeNameNode*> paramTypeNameNodes;
	m_parameterList->collectTypeNameNodes(paramTypeNameNodes);
	relativeName += '<';
	for(size_t i = 0; i < paramTypeNameNodes.size(); ++i)
	{
		if(0 != i)
		{
			relativeName += ',';
		}
		TypeNameNode* paramTypeNameNode = paramTypeNameNodes[i];
		std::string paramName;
		paramTypeNameNode->getRelativeName(paramName, scope, 0);
		relativeName += paramName;
	}
	relativeName += '>';
}


TypeCategory TemplateClassInstanceNode::getTypeCategory()
{
	return m_typeCategory;
}

size_t TemplateClassInstanceNode::getParameterCount()
{
	size_t count = 0;
	TypeNameListNode* list = m_parameterList;
	while (0 != list)
	{
		++count;
		list = list->m_typeNameList;
	}
	return count;
}

void TemplateClassInstanceNode::collectTypeInfo()
{
	m_typeCategory = type_not_found;

	m_templateTypeNameNode->checkTypeName(m_enclosing);
	if(class_template != m_templateTypeNameNode->m_typeCategory)
	{
		RaiseError_InvalidClassTemplateName(m_name);
		return;
	}

	assert(0 != m_templateTypeNameNode->m_typeInfo && snt_class == m_templateTypeNameNode->m_typeInfo->m_typeNode->m_nodeType);
	ClassNode* classNode = static_cast<ClassNode*>(m_templateTypeNameNode->m_typeInfo->m_typeNode);
	assert(0 != classNode->m_templateParameters);

	size_t paramCount = classNode->m_templateParameters->getParameterCount();

	std::vector<TypeNameNode*> argumentNodes;
	m_parameterList->collectTypeNameNodes(argumentNodes);
	size_t argCount = argumentNodes.size();
	if(paramCount != argCount)
	{
		if(paramCount < argCount)
		{
			RaiseError_TooManyTemplateArguments(m_name);
		}
		else
		{
			RaiseError_TooFewTemplateArguments(m_name);
		}
		return;
	}

	size_t argIndex = 0;
	for(; argIndex < argCount; ++argIndex)
	{
		TypeNameNode* typeNameNode = argumentNodes[argIndex];
		typeNameNode->checkTypeName(m_enclosing);
		if(!(primitive_type == typeNameNode->m_typeCategory
			|| value_type == typeNameNode->m_typeCategory
			|| reference_type == typeNameNode->m_typeCategory))
		{
			break;
		}
	}
	if(argIndex < argCount)
	{
		TypeNameNode* typeNameNode = argumentNodes[argIndex];
		RaiseError_InvalidTemplateArgument(typeNameNode);
	}
	else
	{
		m_typeCategory = classNode->isValueType() ? value_type : reference_type;
		g_sourceFileManager.registerType(this);
	}	
}

void TemplateClassInstanceNode::checkSemantic()
{
	ClassNode* classNode = static_cast<ClassNode*>(m_templateTypeNameNode->m_typeInfo->m_typeNode);
	std::vector<TemplateParameterNode*> templateParameters;
	classNode->m_templateParameters->collectParameterNodes(templateParameters);

	std::vector<TypeNameNode*> templateArguments;
	m_parameterList->collectTypeNameNodes(templateArguments);

	size_t count = templateParameters.size();

	TemplateArgumentMap templateArgumentMap;
	for(size_t i = 0; i < count; ++i)
	{
		TemplateParameterNode* parameter = templateParameters[i];
		TypeNameNode* argument = templateArguments[i];
		templateArgumentMap.insert(make_pair(parameter->m_name->m_str, argument));
	}

	TypeNameListNode* oldTemplateArgumentList = classNode->setTemplateArgumentList(m_parameterList);
	classNode->checkSemanticForTemplateInstance(this, &templateArgumentMap);
	classNode->setTemplateArgumentList(oldTemplateArgumentList);

}

bool TemplateClassInstanceNode::isAbstractClass()
{
	return m_templateTypeNameNode->m_typeInfo->m_typeNode->isAbstractClass();
}
