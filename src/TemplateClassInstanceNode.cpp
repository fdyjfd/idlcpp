#include "TemplateClassInstanceNode.h"
#include "ScopeNameListNode.h"
#include "TypeNameNode.h"
#include "TypeNameListNode.h"
#include "IdentifyNode.h"
#include "TokenListNode.h"
#include "ClassNode.h"
#include "RaiseError.h"
#include "TemplateParametersNode.h"
#include "Compiler.h"
#include "TypeTree.h"
#include "ErrorList.h"
#include <assert.h>
#include <algorithm>

TemplateClassInstanceNode::TemplateClassInstanceNode(IdentifyNode* name, TypeNameListNode* parameterList)
{
	m_nodeType = snt_template_class_instance;
	m_name = name;
	m_parameterList = parameterList;
	m_tokenList = 0;
	m_typeNode = 0;
	m_classTypeNode = 0;
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

TypeNode* TemplateClassInstanceNode::getTypeNode()
{
	return m_typeNode;
}

void TemplateClassInstanceNode::getLocalName(std::string& name, TemplateArguments* templateArguments)
{
	assert(m_typeNode);
	m_typeNode->getLocalName(name);
}

void TemplateClassInstanceNode::collectTypes(TypeNode* enclosingTypeNode, TemplateArguments* templateArguments)
{
	assert(enclosingTypeNode->isNamespace() && 0 == templateArguments);
	assert(0 == m_typeNode && 0 == m_classTypeNode);
	TypeNode* childTypeNode = enclosingTypeNode->getChildNode(m_name->m_str);
	if (0 == childTypeNode || !childTypeNode->isTemplateClass())
	{
		RaiseError_InvalidClassTemplateName(m_name);
		return;
	}
	m_classTypeNode = static_cast<ClassTypeNode*>(childTypeNode);

	ClassNode* classNode = static_cast<ClassNode*>(m_classTypeNode->m_classNode);
	std::vector<IdentifyNode*> parameterNodes;
	classNode->m_templateParametersNode->collectParameterNodes(parameterNodes);
	size_t paramCount = parameterNodes.size();
	std::vector<TypeNameNode*> argumentNodes;
	m_parameterList->collectTypeNameNodes(argumentNodes);
	size_t argCount = argumentNodes.size();
	if (paramCount != argCount)
	{
		if (paramCount < argCount)
		{
			RaiseError_TooManyTemplateArguments(m_name);
		}
		else
		{
			RaiseError_TooFewTemplateArguments(m_name);
		}
		return;
	}
	bool argError = false;
	for (size_t i = 0; i < argCount; ++i)
	{
		if (argumentNodes[i]->calcTypeNodes(enclosingTypeNode, 0))
		{
			TemplateArgument arg;
			arg.m_name = parameterNodes[i]->m_str;
			arg.m_typeNode = argumentNodes[i]->m_typeNode;
			m_templateArguments.m_arguments.push_back(arg);
		}
		else
		{
			argError = true;
			RaiseError_InvalidTemplateArgument(argumentNodes[i]);
		}
	}
	if (!argError)
	{
		assert(enclosingTypeNode->isNamespace());
		m_typeNode = static_cast<NamespaceTypeNode*>(enclosingTypeNode)->addTemplateClassInstance(this);
		if (m_typeNode)
		{
			m_templateArguments.m_className = m_name->m_str;
			m_templateArguments.m_classTypeNode = m_typeNode;
		}
	}
}

void TemplateClassInstanceNode::checkSemantic(TemplateArguments* templateArguments)
{
	MemberNode::checkSemantic(templateArguments);

	assert(0 == templateArguments);
	assert(m_typeNode && m_classTypeNode);
	ClassNode* classNode = static_cast<ClassNode*>(m_classTypeNode->m_classNode);

	g_errorList.setTemplateClassInstance(this);
	classNode->checkSemantic(&m_templateArguments);
	g_errorList.setTemplateClassInstance(0);
}

void TemplateClassInstanceNode::getReservedMembers(std::vector<IdentifyNode*>& reservedNames, std::vector<TokenNode*>& reservedOperators)
{
	reservedNames.clear();
	reservedOperators.clear();
	std::vector<TokenNode*> reservedMembers;
	m_tokenList->collectTokenNodes(reservedMembers);
	auto it = reservedMembers.begin();
	auto end = reservedMembers.end();
	for (; it != end; ++it)
	{
		TokenNode* token = *it;
		if (snt_identify == token->m_nodeType)
		{
			reservedNames.push_back(static_cast<IdentifyNode*>(token));
		}
		else
		{
			reservedOperators.push_back(token);
		}
	}
	std::sort(reservedNames.begin(), reservedNames.end(), CompareIdentifyPtr());
	std::sort(reservedOperators.begin(), reservedOperators.end(), CompareTokenPtr());

}
