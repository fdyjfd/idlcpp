#pragma once
#include "CommonFuncs.h"
#include "IdentifyNode.h"
#include "MemberNode.h"
#include "EnumNode.h"
#include "ClassNode.h"
#include "TypedefNode.h"
#include "TypeDeclarationNode.h"
#include "MemberListNode.h"
#include "TypeNameNode.h"
#include "ClassNode.h"
#include "DelegateNode.h"
#include "TemplateParametersNode.h"
#include "TemplateClassInstanceNode.h"
#include "NamespaceNode.h"

#include "Compiler.h"
#include "Options.h"
#include "TypeTree.h"
#include <algorithm>
#include <assert.h>

void GetMetaTypeFullName(std::string& metaTypeName, MemberNode* memberNode, TemplateArguments* templateArguments)
{
	std::string typeName;
	memberNode->getFullName(typeName, templateArguments);
	std::replace_if(typeName.begin(), typeName.end(), isNotIdentifyChar, '_');
	metaTypeName = typeName + g_options.m_metaTypePostfix;
}

void GetMetaTypeFullName(std::string& metaTypeName, TypeNode* typeNode)
{
	std::string typeName;
	typeNode->getFullName(typeName);
	std::replace_if(typeName.begin(), typeName.end(), isNotIdentifyChar, '_');
	metaTypeName = typeName + g_options.m_metaTypePostfix;
}

void GetSubclassProxyFullName(std::string& subclassProxyName, ClassNode* classNode, TemplateArguments* templateArguments)
{
	std::string typeName;
	classNode->getFullName(typeName, templateArguments);
	std::replace_if(typeName.begin(), typeName.end(), isNotIdentifyChar, '_');
	subclassProxyName = typeName + g_options.m_subclassProxyPostfix;
}

TypeCategory CalcTypeNativeName(std::string& typeName, TypeNameNode* typeNameNode, TemplateArguments* templateArguments)
{
	TypeNode* typeNode = typeNameNode->getTypeNode(templateArguments);
	assert(typeNode);
	typeNode->getNativeName(typeName);
	return typeNode->getTypeCategory(templateArguments);
}

void CollectTypeNodes(std::vector<TypeNode*>& typeNodes, ClassTypeNode* classTypeNode)
{
	typeNodes.push_back(classTypeNode);
	auto it = classTypeNode->m_children.begin();
	auto end = classTypeNode->m_children.end();
	for (; it != end; ++it)
	{
		TypeNode* srcChild = *it;
		switch (srcChild->m_category)
		{
		case tc_enum_type:
			typeNodes.push_back(srcChild);
			break;
		case tc_class_type:
			CollectTypeNodes(typeNodes, static_cast<ClassTypeNode*>(srcChild));
			break;
		case tc_typedef:
			typeNodes.push_back(srcChild);
			break;
		case tc_type_declaration:
			typeNodes.push_back(srcChild);
			break;
		default:
			assert(false);
		}
	}
}

void CollectTypeNodes(std::vector<TypeNode*>& typeNodes, MemberNode* memberNode)
{
	std::string typeName;
	switch (memberNode->m_nodeType)
	{
	case snt_enum:
		typeNodes.push_back(static_cast<EnumNode*>(memberNode)->m_typeNode);
		break;
	case snt_class:
		if (!memberNode->isTemplateClass())
		{
			CollectTypeNodes(typeNodes, static_cast<ClassNode*>(memberNode)->m_typeNode);
		}
		break;
	case snt_delegate:
		typeNodes.push_back(static_cast<DelegateNode*>(memberNode)->m_classNode->m_typeNode);
		break;
	case snt_template_class_instance:
		CollectTypeNodes(typeNodes, static_cast<TemplateClassInstanceNode*>(memberNode)->m_typeNode);
		break;
	case snt_typedef:
		typeNodes.push_back(static_cast<TypedefNode*>(memberNode)->m_typeNode);
		break;
	case snt_type_declaration:
		typeNodes.push_back(static_cast<TypeDeclarationNode*>(memberNode)->m_typeNode);
		break;
	}
	if (memberNode->isNamespace())
	{
		MemberListNode* list = static_cast<NamespaceNode*>(memberNode)->m_memberList;
		while (0 != list)
		{
			CollectTypeNodes(typeNodes, list->m_member);
			list = list->m_memberList;
		}
	}
}
