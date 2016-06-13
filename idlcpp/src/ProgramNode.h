#pragma once
#include "NamespaceNode.h"

struct MemberListNode;

struct ProgramNode : NamespaceNode
{
public:
	ProgramNode(MemberListNode* memberList);
	virtual void getLocalName(std::string& name, TemplateArguments* templateArguments);
	virtual void collectTypes(TypeNode* enclosingTypeNode);
};
