#pragma once

#include "MemberNode.h"

struct TokenNode;
struct TypeNameNode;

struct FieldNode : MemberNode
{
	TokenNode* m_static;
	TokenNode* m_constant;
	TypeNameNode* m_type;
	TokenNode* m_leftBracket;
	TokenNode* m_rightBracket;
	TokenNode* m_semicolon;
public:
	FieldNode(TypeNameNode* type, IdentifyNode* name, TokenNode* leftBracket, TokenNode* rightBracket, TokenNode* semicolon);
	bool isStatic();
	bool isConstant();
	bool isArray();
	virtual void checkSemantic();
	virtual void checkSemanticForTemplateInstance(TemplateClassInstanceNode* templateClassInstanceNode, TemplateArgumentMap* templateArguments);
};
