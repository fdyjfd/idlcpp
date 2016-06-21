#pragma once
#include "ScopeNode.h"

struct TokenNode;
struct EnumeratorListNode;
struct EnumTypeNode;

struct EnumNode : ScopeNode
{
	TokenNode* m_keyword;
	TokenNode* m_leftBrace;
	EnumeratorListNode* m_enumeratorList;
	TokenNode* m_rightBrace;
	TokenNode* m_semicolon;
	EnumTypeNode* m_typeNode;
public:
	EnumNode(TokenNode* keyword, IdentifyNode* name, TokenNode* leftBrace, EnumeratorListNode* enumeratorList, TokenNode* rightBrace, TokenNode* semicolon);
	virtual TypeNode* getTypeNode();
	virtual void collectTypes(TypeNode* enclosingTypeNode, TemplateArguments* templateArguments);
	virtual void checkSemantic(TemplateArguments* templateArguments);
};