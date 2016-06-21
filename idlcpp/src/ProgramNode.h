#pragma once
#include "NamespaceNode.h"

struct MemberListNode;
class SourceFile;
struct ProgramNode : NamespaceNode
{
public:
	ProgramNode(MemberListNode* memberList);
	virtual void getLocalName(std::string& name, TemplateArguments* templateArguments);
	virtual void collectTypes(TypeNode* enclosingTypeNode, TemplateArguments* templateArguments);
public:
	SourceFile* m_sourceFile;
};
