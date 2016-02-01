#include "TypeAliasNode.h"
#include "TypeNameNode.h"
#include "SourceFile.h"
#include "RaiseError.h"
#include <assert.h>


TypeAliasNode::TypeAliasNode(IdentifyNode* name, TypeCategory typeCategory)
{
	m_nodeType = snt_type_alias;
	m_keyword = 0;
	m_name = name;
	m_typeName = 0;
	m_typeCategory = typeCategory;
}

TypeAliasNode::TypeAliasNode(TokenNode* keyword, IdentifyNode* name, TypeNameNode* typeName)
{
	m_nodeType = snt_type_alias;
	m_keyword = keyword;
	m_name = name;
	m_typeName = typeName;
	m_typeCategory = unknown_type;
}

void TypeAliasNode::collectTypeInfo()
{
	if(unknown_type == m_typeCategory)
	{
		assert(0 != m_typeName && 0 != m_keyword);
		m_typeName->checkTypeName(m_enclosing);
		switch(m_typeName->m_typeCategory)
		{
		case void_type:
		case primitive_type:
		case enum_type:
		case value_type:
		case reference_type:
			m_typeCategory = m_typeName->m_typeCategory;
			break;
		default:
			m_typeCategory = type_not_found;
		}
	}
	if(type_not_found != m_typeCategory)
	{
		g_sourceFileManager.registerType(this);
	}
	else
	{
		assert(0 != m_typeName);
		RaiseError_InvalidTypeName(m_typeName);
	}
}

void TypeAliasNode::checkSemantic()
{
}

TypeCategory TypeAliasNode::getTypeCategory()
{
	return m_typeCategory;
}

bool TypeAliasNode::isAbstractClass()
{
	if(m_typeName)
	{
		return m_typeName->m_typeInfo->m_typeNode->isAbstractClass();
	}
	else
	{
		return false;
	}
}

//
//bool TypeAliasNode::isPrimitive()
//{
//	return true;
//}
//
//bool TypeAliasNode::isEnum()
//{
//	return false;
//}
//
//bool TypeAliasNode::isValue()
//{
//	return false;
//}
//
//bool TypeAliasNode::isReference()
//{
//	return false;
//}
