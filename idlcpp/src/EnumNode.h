#pragma once
#include "ScopeNode.h"

struct TokenNode;
struct IdentityListNode;
struct EnumTypeNode;

struct EnumNode : ScopeNode
{
	TokenNode* m_keyword;
	TokenNode* m_leftBrace;
	IdentityListNode* m_identityList;
	TokenNode* m_rightBrace;
	TokenNode* m_semicolon;
	EnumTypeNode* m_typeNode;
public:
	EnumNode(TokenNode* keyword, IdentifyNode* name, TokenNode* leftBrace, IdentityListNode* identityList, TokenNode* rightBrace);
	virtual TypeNode* getTypeNode();
	virtual void collectTypes(TypeNode* enclosingTypeNode, TemplateArguments* templateArguments);
	virtual void checkSemantic(TemplateArguments* templateArguments);
};