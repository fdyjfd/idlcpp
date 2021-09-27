#include "MemberNode.h"
#include "IdentifyNode.h"
#include "AttributeListNode.h"
#include "ScopeNode.h"
#include "ClassNode.h"
#include "NamespaceNode.h"
#include "ProgramNode.h"
#include "TypedefNode.h"
#include "TypeTree.h"
#include "Options.h"
#include "SourceFile.h"
#include <assert.h>
#include <algorithm>

MemberNode::MemberNode()
{
	m_attributeList = 0;
	m_name = 0;
	m_enclosing = 0;
	m_filterNode = 0;
	m_nativeName = 0;
}

bool MemberNode::isNoCode()
{
	return (m_filterNode && snt_keyword_nocode == m_filterNode->m_nodeType);
}

bool MemberNode::isNoMeta()
{
	return (m_filterNode && snt_keyword_nometa == m_filterNode->m_nodeType);
}

bool MemberNode::canGenerateMetaCode()
{
	if (isNoMeta())
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
	if (isNoCode())
	{
		return false;
	}
	if (0 == m_enclosing)
	{
		return true;
	}
	return m_enclosing->canGenerateNativeCode();
}

void MemberNode::getNativeName(std::string& nativeName, TemplateArguments* templateArguments)
{
	if (m_nativeName)
	{
		nativeName = m_nativeName->m_str;
	}
	else
	{
		getFullName(nativeName, templateArguments);
	}
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

ProgramNode* MemberNode::getProgramNode()
{
	MemberNode* memberNode = this;
	ScopeNode* enclosing = m_enclosing;
	while (enclosing)
	{
		memberNode = enclosing;
		enclosing = enclosing->m_enclosing;
	}
	assert(snt_namespace == memberNode->m_nodeType);
	return static_cast<ProgramNode*>(memberNode);
}

SourceFile* MemberNode::getSourceFile()
{
	//MemberNode* memberNode = this;
	//ScopeNode* enclosing = m_enclosing;
	//while (enclosing)
	//{
	//	memberNode = enclosing;
	//	enclosing = enclosing->m_enclosing;
	//}
	//assert(snt_namespace == memberNode->m_nodeType);
	//return static_cast<ProgramNode*>(memberNode)->m_sourceFile;
	return getProgramNode()->m_sourceFile;
}

std::string MemberNode::getSourceFilePath()
{
	std::string str;
	str = getSourceFile()->m_fileName;
	std::replace(str.begin(), str.end(), '\\', '/');
	return str;
}

void MemberNode::collectTypes(TypeNode* enclosingTypeNode, TemplateArguments* templateArguments)
{
}

void MemberNode::checkTypeNames(TypeNode* enclosingTypeNode, TemplateArguments* templateArguments)
{
}

void MemberNode::checkSemantic(TemplateArguments* templateArguments)
{
	if (m_attributeList)
	{
		m_attributeList->checkSemantic();
	}
}


bool CompareMemberNodeByName::operator()(const MemberNode* m1, const MemberNode* m2) const
{
	return m1->m_name->m_str < m2->m_name->m_str;
}