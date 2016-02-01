#include "MemberNode.h"
#include "IdentifyNode.h"
#include "ScopeNode.h"
#include "ClassNode.h"
#include "NamespaceNode.h"
#include "Options.h"
#include <assert.h>

MemberNode::MemberNode()
{
	m_name = 0;
	m_enclosing = 0;
}

void MemberNode::getFullName(std::string& fullName, TemplateArgumentMap* templateArguments)
{
	getRelativeName(fullName, 0, templateArguments);
}

void MemberNode::getRelativeName(std::string& relativeName, ScopeNode* scope, TemplateArgumentMap* templateArguments)
{
	assert((0 == m_enclosing && 0 == m_name) || (0 != m_enclosing && 0 != m_name));
	relativeName.clear();
	if(0 == m_enclosing)
	{
		//global scope, name is ""
		return;
	}
	std::vector<ScopeNode*> enclosings;
	getEnclosings(enclosings);
	if(enclosings.empty())
	{
		//under global scope, name is ::m_name 
		relativeName = "::" + m_name->m_str;
		return;
	}

	std::vector<ScopeNode*> scopeEnclosings;
	if(0 != scope)
	{
		scope->getEnclosings(scopeEnclosings);
		if(scope->m_name)
		{
			scopeEnclosings.push_back(scope);
		}
	}

	bool visible = false;
	size_t count1 = enclosings.size();
	size_t count2 = scopeEnclosings.size();

	if(count1 <= count2)
	{
		size_t index = 0;
		for(; index < count1; ++index)
		{
			if(enclosings[index]->m_name->m_str != scopeEnclosings[index]->m_name->m_str)
			{
				break;
			}
		}
		if(index == count1)
		{
			visible = true;
		}
	}
	if(visible)
	{
		relativeName = m_name->m_str;
	}
	else
	{
		std::string enclosingName;
		m_enclosing->getRelativeName(enclosingName, scope, templateArguments);
		assert(!enclosingName.empty());
		relativeName = enclosingName + "::" + m_name->m_str;
	}

	//std::string enclosingName;
	//if(!visible)
	//{
	//	m_enclosing->getRelativeName(enclosingName, scope, templateArguments);
	//	assert(!enclosingName.empty());
	//}

	//relativeName = enclosingName;

	//if(!enclosingName.empty())
	//{
	//	relativeName += "::";
	//}
	//relativeName += m_name->m_str;
}

/*
void MemberNode::getRelativeName(std::string& relativeName, ScopeNode* scope, TemplateArgumentMap* templateArguments)
{
	relativeName.clear();
	std::vector<std::string> names;
	bool isGlobal = getRelativeName(names, scope);
	if(!names.empty())
	{
		if(isGlobal)
		{
			relativeName = "::";
		}
		relativeName.append(names[0]);
		size_t count = names.size();
		for (size_t i = 1; i < count; ++i)
		{
			relativeName.append("::");
			relativeName.append(names[i]);
		}
	}
}

bool MemberNode::getRelativeName(std::vector<std::string>& names, ScopeNode* scope)
{
	names.clear();
	std::vector<ScopeNode*> enclosings;
	getEnclosings(enclosings);
	std::vector<ScopeNode*> scopeEnclosings;
	if(0 != scope)
	{
		scope->getEnclosings(scopeEnclosings);
		if(scope->m_name)
		{
			scopeEnclosings.push_back(scope);
		}
	}
	size_t count1 = enclosings.size();
	size_t count2 = scopeEnclosings.size();
	size_t count = count1 < count2 ? count1 : count2;
	size_t index = 0;
	for(; index < count; ++index)
	{
		if(enclosings[index]->m_name->m_str != scopeEnclosings[index]->m_name->m_str)
		{
			break;
		}
	}
	bool isGlobal = (0 == index);
	for(; index < enclosings.size(); ++index)
	{
		names.push_back(enclosings[index]->m_name->m_str);
	}
	if(m_name)
	{
		names.push_back(m_name->m_str);
	}
	return isGlobal;
}
*/

void MemberNode::getEnclosings(std::vector<ScopeNode*>& enclosings)
{
	ScopeNode* enclosing = m_enclosing;
	while (enclosing && enclosing->m_name)
	{
		enclosings.push_back(enclosing);
		enclosing = enclosing->m_enclosing;
	}
	std::reverse(enclosings.begin(), enclosings.end());
}

TypeCategory MemberNode::getTypeCategory()
{
	return unknown_type;
}

void MemberNode::collectTypeInfo()
{}

bool MemberNode::isTemplateClass()
{
	if (snt_class == m_nodeType)
	{
		return (0 != static_cast<ClassNode*>(this)->m_templateParameters);
	}
	return false;
}

NamespaceNode* MemberNode::getNamespace()
{
	ScopeNode* enclosing = m_enclosing;
	while(snt_namespace != enclosing->m_nodeType)
	{
		enclosing = enclosing->m_enclosing;
	}
	return static_cast<NamespaceNode*>(enclosing);
}

bool MemberNode::isAbstractClass()
{
	assert(false);
	return false;
}


bool CompareMemberNodeByName::operator()(const MemberNode* m1, const MemberNode* m2) const
{
	return m1->m_name->m_str < m2->m_name->m_str;
}