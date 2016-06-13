#pragma once

#include <vector>
#include <string>

struct TypeNode;
struct ClassTypeNode;

struct TemplateArgument
{
	std::string m_name;
	TypeNode* m_typeNode;
};

struct TemplateArguments
{
	std::string m_className;
	TypeNode* m_classTypeNode;
	std::vector<TemplateArgument> m_arguments;
public:
	TypeNode* findTypeNode(const std::string& name);
};
