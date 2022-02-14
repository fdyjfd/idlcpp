#pragma once
#include "SyntaxNodeImpl.h"
#include <vector>
#include <string>

struct ScopeNameNode;
struct TypeNode;
struct TemplateArguments;

struct ScopeNameListNode : SyntaxNodeImpl
{
	ScopeNameListNode* m_scopeNameList;
	ScopeNameNode* m_scopeName;
	bool m_global;
public:
	ScopeNameListNode(ScopeNameListNode* scopeNameList, ScopeNameNode* scopeName);
	void collectIdentifyNodes(std::vector<ScopeNameNode*>& scopeNameNodes);
	bool calcTemplateParametersTypeNodes(TypeNode* enclosingTypeTreeNode, TemplateArguments* templateArguments);
	void getString(std::string& str);

	bool isGlobal()
	{
		return m_global;
	}
};

