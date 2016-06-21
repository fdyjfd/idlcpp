#pragma once
#include "MemberNode.h"

struct TokenNode;
struct ScopeNameListNode;
struct TypeNameNode;
struct TypeDeclarationTypeNode;

struct TypeDeclarationNode : MemberNode
{
	TypeCategory m_typeCategory;
	TypeDeclarationTypeNode* m_typeNode;
public:
	TypeDeclarationNode(IdentifyNode* name, TypeCategory typeCategory);
	virtual TypeNode* getTypeNode();
	virtual void collectTypes(TypeNode* enclosingTypeNode, TemplateArguments* templateArguments);
};

