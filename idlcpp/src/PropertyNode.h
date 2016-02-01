#pragma once

#include "MemberNode.h"

struct GetterSetterNode;
struct TypeNameNode;

struct PropertyNode : MemberNode
{
	TokenNode* m_modifier;
	TokenNode* m_constant;
	TypeNameNode* m_type;
	TokenNode* m_passing;//PTR or REF
	GetterSetterNode* m_get;
	GetterSetterNode* m_set;
public:
	PropertyNode(TokenNode* constant, TypeNameNode* type, TokenNode* passing, IdentifyNode* name);
	bool isStatic();
	bool isVirtual();
	bool isAbstract();
	void setGetter(GetterSetterNode* getter);
	void setSetter(GetterSetterNode* setter);
	virtual void checkSemantic();
	virtual void checkSemanticForTemplateInstance(TemplateClassInstanceNode* templateClassInstanceNode, TemplateArgumentMap* templateArguments);
};