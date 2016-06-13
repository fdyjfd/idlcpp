#include "TypeNameNode.h"
#include "IdentifyNode.h"
#include "TypedefNode.h"
#include "ErrorList.h"
#include "RaiseError.h"
#include "ScopeNameListNode.h"
#include "ScopeNameNode.h"
#include "Options.h"
#include "ClassNode.h"
#include "TemplateParametersNode.h"
#include "TypeNameListNode.h"
#include "TemplateClassInstanceNode.h"
#include "ProgramNode.h"
#include "Compiler.h"
#include "TypeTree.h"
#include "TemplateArguments.h"
#include "yyfuncs.h"
#include <assert.h>


TypeNameNode::TypeNameNode(TokenNode* keyword, PredefinedType primitiveType)
{
	assert(primitiveType < pt_end);
	m_nodeType = snt_type_name;
	m_keyword = keyword;
	m_scopeNameList = 0;
	m_startTypeNode = g_typeTree.getPredefinedTypeNode(primitiveType);
	m_typeNode = m_startTypeNode;
}

TypeNameNode::TypeNameNode(ScopeNameListNode* scopeNameList)
{
	m_nodeType = snt_type_name;
	m_keyword = 0;
	m_scopeNameList = scopeNameList;
	m_startTypeNode = 0;
	m_typeNode = 0;
}

bool TypeNameNode::calcTypeNodes(TypeNode* enclosingTypeTreeNode, TemplateArguments* templateArguments)
{
	if (m_keyword)
	{
		return true;
	}
	assert(0 == m_startTypeNode && 0 == m_typeNode);
	if (!m_scopeNameList->calcTemplateParametersTypeNodes(enclosingTypeTreeNode, templateArguments))
	{
		return false;
	}
	TypeNode* initialTypeTreeNode = 0;
	TypeNode* finalTypeTreeNode = 0;
	if (g_typeTree.checkTypeNameNode(initialTypeTreeNode, finalTypeTreeNode, m_scopeNameList, enclosingTypeTreeNode, templateArguments))
	{
		m_startTypeNode = initialTypeTreeNode;
		m_typeNode = finalTypeTreeNode;
		return true;
	}
	else
	{
		return false;
	}
}

TypeNode* TypeNameNode::getTypeNode(TemplateArguments* templateArguments)
{
	assert(0 == templateArguments || templateArguments->m_classTypeNode->isTemplateClassInstance());
	assert(0 != m_startTypeNode);
	TypeNode* result = 0;
	if (0 == m_typeNode)// under template parameter
	{
		assert(templateArguments && templateArguments->m_classTypeNode->isTemplateClassInstance() 
			&& m_startTypeNode && m_startTypeNode->isTemplateParameter());
		TypeNode* actualStartTypeNode = templateArguments->findTypeNode(m_startTypeNode->m_name);
		assert(actualStartTypeNode);
		actualStartTypeNode = actualStartTypeNode->getActualTypeNode();
		std::vector<ScopeNameNode*> scopeNameNodes;
		m_scopeNameList->collectIdentifyNodes(scopeNameNodes);
		assert(scopeNameNodes.size() > 1);
		scopeNameNodes.erase(scopeNameNodes.begin());
		TypeNode* initialTypeTreeNode = 0;
		TypeNode* finalTypeTreeNode = 0;
		if (g_typeTree.findNodeByScopeNames(initialTypeTreeNode, finalTypeTreeNode,
			scopeNameNodes, actualStartTypeNode, templateArguments))
		{
			assert(finalTypeTreeNode);
			result = finalTypeTreeNode;
		}
	}
	else if (m_typeNode->isTemplateParameter())
	{
		assert(templateArguments);
		result = templateArguments->findTypeNode(m_scopeNameList->m_scopeName->m_name->m_str);
	}
	else if (m_typeNode->isTemplateClass())
	{
		assert(templateArguments);
		if (m_scopeNameList->m_scopeName->isTemplateForm())
		{
			result = g_typeTree.findNodeByScopeName(m_scopeNameList->m_scopeName, m_typeNode->m_enclosing, templateArguments);
		}
		else
		{
			assert(m_scopeNameList->m_scopeName->m_name->m_str == templateArguments->m_className);
			result = templateArguments->m_classTypeNode;
		}
	}
	else if (m_typeNode->isUnderTemplateClass())
	{
		assert(templateArguments);
		if (m_startTypeNode->isUnderTemplateClass())
		{
			std::vector<TypeNode*> typeNodes;
			TypeNode* typeNode = m_typeNode;
			while (typeNode)
			{
				if (typeNode->isTemplateClass())
				{
					break;
				}
				typeNodes.push_back(typeNode);
				typeNode = typeNode->m_enclosing;
			}
			assert(typeNode->isTemplateClass() && typeNode->m_name == templateArguments->m_className);
			typeNode = templateArguments->m_classTypeNode;
			auto it = typeNodes.rbegin();
			auto end = typeNodes.rend();
			for (; it != end; ++it)
			{
				TypeNode* tempTypeNode = *it;
				typeNode = typeNode->getChildNode(tempTypeNode->m_name);
				assert(typeNode);
			}
			result = typeNode;
		}
		else
		{
			std::vector<ScopeNameNode*> scopeNameNodes;
			m_scopeNameList->collectIdentifyNodes(scopeNameNodes);
			TypeNode* initialTypeTreeNode = 0;
			TypeNode* finalTypeTreeNode = 0;
			if (m_startTypeNode->isTemplateClass() && !scopeNameNodes[0]->isTemplateForm())
			{
				assert(m_startTypeNode->m_name == templateArguments->m_className);
				scopeNameNodes.erase(scopeNameNodes.begin());
				if (g_typeTree.findNodeByScopeNames(initialTypeTreeNode, finalTypeTreeNode,
					scopeNameNodes, templateArguments->m_classTypeNode, templateArguments))
				{
					result = finalTypeTreeNode;
				}
			}
			else
			{
				if (g_typeTree.findNodeByScopeNames(initialTypeTreeNode, finalTypeTreeNode,
					scopeNameNodes, m_startTypeNode->m_enclosing, templateArguments))
				{
					result = finalTypeTreeNode;
				}
			}
		}
	}
	else
	{
		assert(m_typeNode->isPredefinedType() ||
			m_typeNode->isEnum() ||
			m_typeNode->isClass() ||
			m_typeNode->isTemplateClassInstance() ||
			m_typeNode->isTypedef() ||
			m_typeNode->isTypeDeclaration());
		result = m_typeNode;
	}

	if(0 == result)
	{
		RaiseError_InvalidTypeName(m_scopeNameList);
	}
	return result;
}

TypeNode* TypeNameNode::getActualTypeNode(TemplateArguments* templateArguments)
{
	TypeNode* typeNode = getTypeNode(templateArguments);
	if (typeNode)
	{
		typeNode = typeNode->getActualTypeNode();
	}
	return typeNode;
}


void TypeNameNode::getString(std::string& str)
{
	if (m_keyword)
	{
		str = m_startTypeNode->m_name;
	}
	else
	{
		assert(m_scopeNameList);
		m_scopeNameList->getString(str);
	}
}

void TypeNameNode::getRelativeName(std::string& typeName, ScopeNode* scopeNode)
{
	assert(m_startTypeNode && scopeNode);
	if (0 == m_scopeNameList)// predefined type
	{
		m_typeNode->getFullName(typeName);
	}
	else if (m_scopeNameList->isGlobal())
	{
		m_scopeNameList->getString(typeName);
	}
	else
	{
		TypeNode* scopeTypeNode = scopeNode->getTypeNode();

		std::vector<TypeNode*> enclosings;
		m_startTypeNode->getEnclosings(enclosings);
		std::vector<TypeNode*> scopeEnclosings;
		scopeTypeNode->getEnclosings(scopeEnclosings);
		scopeEnclosings.push_back(scopeTypeNode);

		auto it = enclosings.begin();
		auto end = enclosings.end();
		auto it2 = scopeEnclosings.begin();
		auto end2 = scopeEnclosings.end();
		for (; it2 != end2; ++it2)
		{
			if (it == end)
			{
				break;
			}
			if (*it != *it2)
			{
				break;
			}
			++it;
		}
		typeName.clear();
		for (; it != end; ++it)
		{
			TypeNode* typeNode = *it;
			std::string localName;
			typeNode->getLocalName(localName);
			typeName += localName + "::";
		}
		std::string str;
		m_scopeNameList->getString(str);
		typeName += str;
	}
}

