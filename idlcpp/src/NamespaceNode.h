#pragma once
#include "ScopeNode.h"

struct TokenNode;
struct IdentifyNode;
struct MemberListNode;
struct NamespaceTypeNode;

struct NamespaceNode : ScopeNode
{
	TokenNode* m_keyword;
	TokenNode* m_leftBrace;
	TokenNode* m_rightBrace;
	NamespaceTypeNode* m_typeNode;
public:
	NamespaceNode(TokenNode* keyword, IdentifyNode* name, TokenNode* leftBrace, MemberListNode* memberList, TokenNode* rightBrace);
	virtual TypeNode* getTypeNode();
	virtual void collectTypes(TypeNode* enclosingTypeNode, TemplateArguments* templateArguments);
	virtual void checkTypeNames(TypeNode* enclosingTypeNode, TemplateArguments* templateArguments);
	virtual void checkSemantic(TemplateArguments* templateArguments);
	bool isGlobalNamespace();
	void extendInternalCode(TypeNode* enclosingTypeNode, TemplateArguments* templateArguments);
};