#pragma once
#include "MemberNode.h"

struct TokenNode;
struct EnumeratorListNode;
struct EnumTypeNode;

struct EnumNode : MemberNode
{
	TokenNode* m_keyword;
	TokenNode* m_keyword2;
	TokenNode* m_leftBrace;
	EnumeratorListNode* m_enumeratorList;
	TokenNode* m_rightBrace;
	TokenNode* m_semicolon;
	EnumTypeNode* m_typeNode;
public:
	EnumNode(TokenNode* keyword, TokenNode* keyword2, IdentifyNode* name, TokenNode* leftBrace, EnumeratorListNode* enumeratorList, TokenNode* rightBrace);
	virtual TypeNode* getTypeNode();
	virtual void collectTypes(TypeNode* enclosingTypeNode, TemplateArguments* templateArguments);
	virtual void checkSemantic(TemplateArguments* templateArguments);
	bool isStronglyTypedEnum();
};

