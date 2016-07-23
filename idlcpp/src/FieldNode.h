#pragma once

#include "MemberNode.h"

struct TokenNode;
struct TypeNameNode;

struct FieldNode : MemberNode
{
	TokenNode* m_static;
	TokenNode* m_constant;
	TypeNameNode* m_typeName;
	TokenNode* m_pointer;
	TokenNode* m_leftBracket;
	TokenNode* m_rightBracket;
	TokenNode* m_semicolon;
public:
	FieldNode(TypeNameNode* typeName, TokenNode* pointer, IdentifyNode* name, TokenNode* leftBracket, TokenNode* rightBracket);
	bool isStatic();
	bool isConstant();
	bool isPointer();
	bool isArray();
	virtual void checkTypeNames(TypeNode* enclosingTypeNode, TemplateArguments* templateArguments);
	virtual void checkSemantic(TemplateArguments* templateArguments);
};
