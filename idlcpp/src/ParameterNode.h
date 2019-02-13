#pragma once

#include "SyntaxNodeImpl.h"

struct TokenNode;
struct TypeNameNode;
struct IdentifyNode;
struct MethodNode;
struct TemplateArguments;

struct ParameterNode : SyntaxNodeImpl
{
	TokenNode* m_constant;
	TypeNameNode* m_typeName;
	TokenNode* m_out;
	TokenNode* m_passing;
	IdentifyNode* m_name;
	bool m_array;
	bool m_allowNull;
public:
	ParameterNode(TypeNameNode* typeName, TokenNode* out, TokenNode* passing, IdentifyNode* name);
	bool isConstant();
	bool isByValue();
	bool isByRef();
	bool isByPtr();
	bool isByNonRefPtr();
	bool isByDecRefPtr();
	bool isByIncRefPtr();
	bool isInput();
	bool isOutput();
	bool isOutputPtr();
	bool isOutputRef();
	bool isArray();
	bool isAllowNull();
	void checkSemantic(TemplateArguments* templateArguments);
};
