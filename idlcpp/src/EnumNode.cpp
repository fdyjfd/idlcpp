#include "EnumNode.h"
#include "IdentifyNode.h"
#include "EnumeratorListNode.h"
#include "ErrorList.h"
#include "SourceFile.h"
#include <vector>

EnumNode::EnumNode(TokenNode* keyword, IdentifyNode* name, TokenNode* leftBrace, EnumeratorListNode* enumeratorList, TokenNode* rightBrace, TokenNode* semicolon)
{
	m_nodeType = snt_enum;
	m_keyword = keyword;
	m_name = name;
	m_leftBrace = leftBrace;
	m_enumeratorList = enumeratorList;
	m_rightBrace = rightBrace;
	m_semicolon = semicolon;
}

TypeCategory EnumNode::getTypeCategory()
{
	return enum_type;
}

void EnumNode::collectTypeInfo()
{
	g_sourceFileManager.registerType(this);
}

void EnumNode::checkSemantic()
{
	std::vector<std::pair<TokenNode*, IdentifyNode*>> identifyNodes;
	m_enumeratorList->collectIdentifyNodes(identifyNodes);
	size_t count = identifyNodes.size();
	std::set<IdentifyNode*, CompareIdentifyPtr> items;
	for(size_t i = 0; i < count; ++i)
	{
		IdentifyNode* identify = identifyNodes[i].second;
		auto res = items.insert(identify);
		if(!res.second)
		{
			char buf[512];
			sprintf_s(buf, "\'%s\' : enumerator already defined at line %d, column %d", identify->m_str.c_str(), 
				(*res.first)->m_lineNo, (*res.first)->m_columnNo);
			ErrorList_AddItem_CurrentFile(identify->m_lineNo,
				identify->m_columnNo, semantic_error_enumerator_redefined, buf);
		}
	}
}
