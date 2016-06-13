#include "MethodNode.h"
#include "ParameterListNode.h"
#include "ParameterNode.h"
#include "TypeNameNode.h"
#include "IdentifyNode.h"
#include "ClassNode.h"
#include "ErrorList.h"
#include "RaiseError.h"
#include "TypeTree.h"
#include "Compiler.h"

#include <set>
#include <assert.h>

const char g_strPure[] = {" = 0 "};

MethodNode::MethodNode(IdentifyNode* name, TokenNode* leftParenthesis, ParameterListNode* parameterList, TokenNode* rightParenthesis, TokenNode* constant, TokenNode* semicolon)
{
	m_nodeType = snt_method;
	m_modifier = 0;
	m_resultConst = 0;
	m_resultTypeName = 0;
	m_passing = 0;
	m_name = name;
	m_leftParenthesis = leftParenthesis;
	m_parameterList = parameterList;
	m_rightParenthesis = rightParenthesis;
	m_constant = constant;
	m_semicolon = semicolon;
	m_resultArray = false;
	m_override = false;
}

bool MethodNode::isStatic()
{
	return (0 != m_modifier && snt_keyword_static == m_modifier->m_nodeType);
}

bool MethodNode::isConstant()
{
	return (0 != m_constant && snt_keyword_const == m_constant->m_nodeType);
}

bool MethodNode::isVirtual()
{
	return (0 != m_modifier && 
		(snt_keyword_virtual == m_modifier->m_nodeType || 
		snt_keyword_abstract == m_modifier->m_nodeType));
}

bool MethodNode::isAbstract()
{
	return (0 != m_modifier && snt_keyword_abstract == m_modifier->m_nodeType);
}

bool MethodNode::byValue()
{
	return 0 == m_passing;
}

bool MethodNode::byRef()
{
	return (0 != m_passing && snt_keyword_ref == m_passing->m_nodeType);
}

bool MethodNode::byPtr()
{
	return (0 != m_passing && snt_keyword_ptr == m_passing->m_nodeType);
}

bool MethodNode::byNew()
{
	return (0 != m_passing && snt_keyword_new == m_passing->m_nodeType);
}

size_t MethodNode::getParameterCount()
{
	size_t res = 0;
	ParameterListNode* list = m_parameterList;
	while(0 != list)
	{
		++res;
		list = list->m_parameterList;
	}
	return res;
}

void MethodNode::collectParameterNodes(std::vector<std::pair<TokenNode*, ParameterNode*>>& parameterNodes)
{
	ParameterListNode* list = m_parameterList;
	while(0 != list)
	{
		parameterNodes.push_back(std::make_pair(list->m_delimiter, list->m_parameter));
		list = list->m_parameterList;
	}
	std::reverse(parameterNodes.begin(), parameterNodes.end());
}

void MethodNode::collectParameterNodes(std::vector<ParameterNode*>& parameterNodes)
{
	ParameterListNode* list = m_parameterList;
	while(0 != list)
	{
		parameterNodes.push_back(list->m_parameter);
		list = list->m_parameterList;
	}
	std::reverse(parameterNodes.begin(), parameterNodes.end());
}

void checkParameterNames(std::vector<ParameterNode*>& parameterNodes)
{
	std::set<IdentifyNode*, CompareIdentifyPtr> items;
	size_t count = parameterNodes.size();
	for(size_t i = 0; i < count; ++i)
	{
		IdentifyNode* identify = parameterNodes[i]->m_name;
		auto res = items.insert(identify);
		if(!res.second)
		{
			char buf[512];
			sprintf_s(buf, "\'%s\' : parameter already defined at line %d, column %d", identify->m_str.c_str(), 
				(*res.first)->m_lineNo, (*res.first)->m_columnNo);
			ErrorList_AddItem_CurrentFile(identify->m_lineNo,
				identify->m_columnNo, semantic_error_member_redefined, buf);
		}
	}
}

void MethodNode::checkTypeNames(TypeNode* enclosingTypeNode, TemplateArguments* templateArguments)
{
	if (0 != m_resultTypeName)
	{
		m_resultTypeName->calcTypeNodes(enclosingTypeNode, templateArguments);
	}

	std::vector<ParameterNode*> parameterNodes;
	collectParameterNodes(parameterNodes);
	auto it = parameterNodes.begin();
	auto end = parameterNodes.end();
	for (; it != end; ++it)
	{
		ParameterNode* parameterNode = *it;
		parameterNode->m_typeName->calcTypeNodes(enclosingTypeNode, templateArguments);
	}
}

void MethodNode::checkSemantic(TemplateArguments* templateArguments)
{
	assert(snt_class == m_enclosing->m_nodeType);
	ClassNode* classNode = static_cast<ClassNode*>(m_enclosing);
	if(0 != m_resultTypeName)
	{
		TypeNode* typeNode = m_resultTypeName->getTypeNode(templateArguments);
		if (void_type == typeNode->getTypeCategory())
		{
			if (0 != m_passing && (snt_keyword_new == m_passing->m_nodeType || snt_keyword_ref == m_passing->m_nodeType))
			{
				RaiseError_InvalidResultType(this);
			}
		}
		g_compiler.useType(typeNode, byValue() ? tu_definition : tu_declaration, m_resultTypeName);
	}
	if(m_override)
	{
		if(!isVirtual())
		{
			RaiseError_InterfaceMethodIsNotVirtual(m_name);
		}
	}

	std::vector<ParameterNode*> parameterNodes;
	collectParameterNodes(parameterNodes);
	checkParameterNames(parameterNodes);

	size_t parameterCount = parameterNodes.size();
	for(size_t i = 0; i < parameterCount; ++i)
	{
		parameterNodes[i]->checkSemantic(this, templateArguments);
	}
}
