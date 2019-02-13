#include "DelegateNode.h"
#include "ParameterListNode.h"
#include "ParameterNode.h"
#include "TypeNameNode.h"
#include "IdentifyNode.h"
#include "ClassNode.h"
#include "ErrorList.h"
#include "RaiseError.h"
#include "TypeTree.h"
#include "Compiler.h"
#include "ScopeNameListNode.h"
#include "TypeNameListNode.h"
#include "ScopeNameNode.h"
#include "MethodNode.h"


#include <set>
#include <assert.h>

const char g_strPure[] = {" = 0 "};

DelegateNode::DelegateNode(IdentifyNode* name, TokenNode* leftParenthesis, 
	ParameterListNode* parameterList, TokenNode* rightParenthesis, TokenNode* semicolon)
{
	m_nodeType = snt_delegate;
	m_keyword = 0;
	m_resultConst = 0;
	m_resultTypeName = 0;
	m_passing = 0;
	m_name = name;
	m_leftParenthesis = leftParenthesis;
	m_parameterList = parameterList;
	m_rightParenthesis = rightParenthesis;
	m_semicolon = semicolon;
	m_resultArray = false;
	m_parameterCount = size_t(-1);
	m_classNode = 0;
}

bool DelegateNode::byValue()
{
	return 0 == m_passing;
}

bool DelegateNode::byRef()
{
	return (0 != m_passing && '&' == m_passing->m_nodeType);
}

bool DelegateNode::byPtr()
{
	return (0 != m_passing && '*' == m_passing->m_nodeType);
}

bool DelegateNode::byNew()
{
	return (0 != m_passing && '+' == m_passing->m_nodeType);
}

size_t DelegateNode::getParameterCount() const
{
	if (size_t(-1) == m_parameterCount)
	{
		size_t res = 0;
		ParameterListNode* list = m_parameterList;
		while(0 != list)
		{
			++res;
			list = list->m_parameterList;
		}
		m_parameterCount = res;
	}
	return m_parameterCount;
}

void DelegateNode::collectTypes(TypeNode* enclosingTypeNode, TemplateArguments* templateArguments)
{
	m_classNode->collectTypes(enclosingTypeNode, templateArguments);
}

void DelegateNode::checkTypeNames(TypeNode* enclosingTypeNode, TemplateArguments* templateArguments)
{
	//if (0 != m_resultTypeName)
	//{
	//	m_resultTypeName->calcTypeNodes(enclosingTypeNode, templateArguments);
	//}

	//std::vector<ParameterNode*> parameterNodes;
	//m_parameterList->collectParameterNodes(parameterNodes);
	//auto it = parameterNodes.begin();
	//auto end = parameterNodes.end();
	//for (; it != end; ++it)
	//{
	//	ParameterNode* parameterNode = *it;
	//	parameterNode->m_typeName->calcTypeNodes(enclosingTypeNode, templateArguments);
	//}

	m_classNode->checkTypeNames(enclosingTypeNode, templateArguments);
}

void DelegateNode::checkSemantic(TemplateArguments* templateArguments)
{
	MemberNode::checkSemantic(templateArguments);

	if(0 != m_resultTypeName)
	{
		TypeNode* typeNode = m_resultTypeName->getTypeNode(templateArguments);
		if (0 == typeNode)
		{
			return;
		}
		if (void_type == typeNode->getTypeCategory(templateArguments))
		{
			if (0 != m_passing && ('+' == m_passing->m_nodeType || '&' == m_passing->m_nodeType))
			{
				RaiseError_InvalidResultType(this);
			}
		}
		g_compiler.useType(typeNode, templateArguments, byValue() ? tu_use_definition : tu_use_declaration, m_resultTypeName);
	}

	std::vector<ParameterNode*> parameterNodes;
	m_parameterList->collectParameterNodes(parameterNodes);
	checkParameterNames(parameterNodes);

	size_t parameterCount = parameterNodes.size();
	for(size_t i = 0; i < parameterCount; ++i)
	{
		parameterNodes[i]->checkSemantic(templateArguments);
	}

	m_classNode->checkSemantic(templateArguments);
}

void DelegateNode::extendInternalCode(TypeNode* enclosingTypeNode, TemplateArguments* templateArguments)
{
	ClassNode* classNode = (ClassNode*)newClass(m_keyword, 0, m_name);

	IdentifyNode* nsIdentifyNode = (IdentifyNode*)newIdentify("pafcore");
	ScopeNameNode* nsScopeNameNode = (ScopeNameNode*)newScopeName(nsIdentifyNode, 0, 0, 0);

	IdentifyNode* baseIdentifyNode = (IdentifyNode*)newIdentify("Delegate");
	ScopeNameNode* baseScopeNameNode = (ScopeNameNode*)newScopeName(baseIdentifyNode, 0, 0, 0);

	ScopeNameListNode* baseScopeNameListNode = (ScopeNameListNode*)newScopeNameList(newScopeNameList(0, nsScopeNameNode), baseScopeNameNode);

	TypeNameNode* baseTypeNameNode = (TypeNameNode*)newTypeName(baseScopeNameListNode);
	TypeNameListNode* baseTypeNameListNode = (TypeNameListNode*)newTypeNameList(0, 0, baseTypeNameNode);
	setClassBaseList(classNode, 0, baseTypeNameListNode);

	IdentifyNode* invokeIdentifyNode = (IdentifyNode*)newIdentify("invoke");
	MethodNode* invokeMethodNode = (MethodNode*)newMethod(invokeIdentifyNode, m_leftParenthesis, m_parameterList, m_rightParenthesis, NULL);
	setMethodResult(invokeMethodNode, m_resultTypeName, m_passing);
	if (m_resultConst)
	{
		setMethodResultConst(invokeMethodNode, m_resultConst);
	}
	MemberListNode* classMemberListNode  = (MemberListNode*)newClassMemberList(0, invokeMethodNode);
	classNode->setMemberList(0, classMemberListNode, 0);

	invokeMethodNode->m_enclosing = classNode;
	classNode->m_enclosing = m_enclosing;
	m_classNode = classNode;
}
