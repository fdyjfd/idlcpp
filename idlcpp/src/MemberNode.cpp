#include "MemberNode.h"
#include "IdentifyNode.h"
#include "ScopeNode.h"
#include "ClassNode.h"
#include "NamespaceNode.h"
#include "ProgramNode.h"
#include "TypedefNode.h"
#include "TypeTree.h"
#include "Options.h"
#include <assert.h>

MemberNode::MemberNode()
{
	m_name = 0;
	m_enclosing = 0;
	m_filter = mf_default;
}

bool MemberNode::isMetaOnly()
{
	return mf_meta_only == m_filter;
}

bool MemberNode::isNativeOnly()
{
	return mf_native_only == m_filter;
}

bool MemberNode::canGenerateMetaCode()
{
	if (mf_native_only == m_filter)
	{
		return false;
	}
	if (0 == m_enclosing)
	{
		return true;
	}
	return m_enclosing->canGenerateMetaCode();
}

bool MemberNode::canGenerateNativeCode()
{
	if (mf_meta_only == m_filter)
	{
		return false;
	}
	if (0 == m_enclosing)
	{
		return true;
	}
	return m_enclosing->canGenerateNativeCode();
}

void MemberNode::getFullName(std::string& fullName, TemplateArguments* templateArguments)
{
	std::string localName;
	fullName.clear();
	std::vector<ScopeNode*> enclosings;
	getEnclosings(enclosings);
	auto it = enclosings.begin();
	auto end = enclosings.end();
	for (; it != end; ++it)
	{
		ScopeNode* enclosing = *it;
		enclosing->getLocalName(localName, templateArguments);
		fullName += localName + "::";
	}
	getLocalName(localName, templateArguments);
	fullName += localName;
}

void MemberNode::getEnclosings(std::vector<ScopeNode*>& enclosings)
{
	ScopeNode* enclosing = m_enclosing;
	while (enclosing)
	{
		enclosings.push_back(enclosing);
		enclosing = enclosing->m_enclosing;
	}
	std::reverse(enclosings.begin(), enclosings.end());
}


bool MemberNode::isNamespace()
{
	return (snt_namespace == m_nodeType);
}

bool MemberNode::isTemplateClass()
{
	if (snt_class == m_nodeType)
	{
		return (0 != static_cast<ClassNode*>(this)->m_templateParametersNode);
	}
	return false;
}

bool MemberNode::isTypedef()
{
	if (snt_typedef == m_nodeType)
	{
		return 0 != static_cast<TypedefNode*>(this)->m_keyword;
	}
	return false;
}


void MemberNode::getLocalName(std::string& name, TemplateArguments* templateArguments)
{
	name = m_name->m_str;
}

TypeNode* MemberNode::getTypeNode()
{
	assert(false);
	return 0;
}

SourceFile* MemberNode::getSourceFile()
{
	MemberNode* memberNode = this;
	ScopeNode* enclosing = m_enclosing;
	while (enclosing)
	{
		memberNode = enclosing;
		enclosing = enclosing->m_enclosing;
	}
	assert(snt_namespace == memberNode->m_nodeType);
	return static_cast<ProgramNode*>(memberNode)->m_sourceFile;
}

void MemberNode::collectTypes(TypeNode* enclosingTypeNode)
{
}

void MemberNode::checkTypeNames(TypeNode* enclosingTypeNode, TemplateArguments* templateArguments)
{
}

void MemberNode::checkSemantic(TemplateArguments* templateArguments)
{
}


bool CompareMemberNodeByName::operator()(const MemberNode* m1, const MemberNode* m2) const
{
	return m1->m_name->m_str < m2->m_name->m_str;
}