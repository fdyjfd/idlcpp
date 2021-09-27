#include "TypeNameListNode.h"
#include "TypeNameNode.h"


TypeNameListNode::TypeNameListNode(TypeNameListNode* typeNameList, TokenNode* delimiter, TypeNameNode* typeName)
{
	m_nodeType = snt_type_name_list;
	m_typeNameList = typeNameList;
	m_delimiter = delimiter;
	m_typeName = typeName;
}

void TypeNameListNode::collectTypeNameNodes(std::vector<TypeNameNode*>& typeNameNodes)
{
	TypeNameListNode* list = this;
	while(0 != list)
	{
		typeNameNodes.push_back(list->m_typeName);
		list = list->m_typeNameList;
	}
	std::reverse(typeNameNodes.begin(), typeNameNodes.end());
}

void TypeNameListNode::collectTypeNameNodes(std::vector<std::pair<TokenNode*, TypeNameNode*>>& typeNameNodes)
{
	TypeNameListNode* list = this;
	while(0 != list)
	{
		typeNameNodes.push_back(std::make_pair(list->m_delimiter, list->m_typeName));
		list = list->m_typeNameList;
	}
	std::reverse(typeNameNodes.begin(), typeNameNodes.end());
}

void TypeNameListNode::collectTypeNameNodesNotNoCode(std::vector<std::pair<TokenNode*, TypeNameNode*>>& typeNameNodes)
{
	TypeNameListNode* list = this;
	while (0 != list)
	{
		if (!list->m_typeName->isNoCode())
		{
			typeNameNodes.push_back(std::make_pair(list->m_delimiter, list->m_typeName));
		}
		list = list->m_typeNameList;
	}
	std::reverse(typeNameNodes.begin(), typeNameNodes.end());
}

void TypeNameListNode::collectTypeNameNodesNotNoMeta(std::vector<std::pair<TokenNode*, TypeNameNode*>>& typeNameNodes)
{
	TypeNameListNode* list = this;
	while (0 != list)
	{
		if (!list->m_typeName->isNoMeta())
		{
			typeNameNodes.push_back(std::make_pair(list->m_delimiter, list->m_typeName));
		}
		list = list->m_typeNameList;
	}
	std::reverse(typeNameNodes.begin(), typeNameNodes.end());
}
