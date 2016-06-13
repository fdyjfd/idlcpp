#pragma once

#include "MemberNode.h"

struct TokenNode;
struct TypeNameNode;

struct FieldNode : MemberNode
{
	TokenNode* m_static;
	TokenNode* m_constant;
	TypeNameNode* m_typeName;
	TokenNode* m_leftBracket;
	TokenNode* m_rightBracket;
	TokenNode* m_semicolon;
public:
	FieldNode(TypeNameNode* typeName, IdentifyNode* name, TokenNode* leftBracket, TokenNode* rightBracket, TokenNode* semicolon);
	bool isStatic();
	bool isConstant();
	bool isArray();
	virtual void checkTypeNames(TypeNode* enclosingTypeNode, TemplateArguments* templateArguments);
	virtual void checkSemantic(TemplateArguments* templateArguments);
};
