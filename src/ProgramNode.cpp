#include "ProgramNode.h"
#include "MemberListNode.h"
#include "NamespaceNode.h"
#include "IdentifyNode.h"
#include "ClassNode.h"
#include "TypeTree.h"

#include "Options.h"
#include "Platform.h"
#include <assert.h>
#include <vector>

const char g_pragmaOnce[] = {"#pragma once\n\n"};

ProgramNode::ProgramNode(MemberListNode* memberList)
: NamespaceNode(0, 0, 0, memberList, 0)
{
	m_sourceFile = 0;
}

void ProgramNode::getLocalName(std::string& name, TemplateArguments* templateArguments)
{
	name = "";
}

void ProgramNode::collectTypes(TypeNode* enclosingTypeNode, TemplateArguments* templateArguments)
{
	assert(0 == enclosingTypeNode && 0 == m_typeNode && 0 == templateArguments);
	m_typeNode = g_typeTree.getRootNamespaceTypeNode();
	m_memberList->collectTypes(m_typeNode, templateArguments);
}

