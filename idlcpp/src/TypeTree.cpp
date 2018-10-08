#include "TypeTree.h"
#include "NamespaceNode.h"
#include "EnumNode.h"
#include "ClassNode.h"
#include "TypedefNode.h"
#include "TypeDeclarationNode.h"
#include "TemplateClassInstanceNode.h"
#include "IdentifyNode.h"
#include "TemplateParametersNode.h"
#include "ScopeNameNode.h"
#include "ScopeNameListNode.h"
#include "TypeNameNode.h"
#include "TypeNameListNode.h"
#include "SourceFile.h"
#include "Compiler.h"
#include "ErrorList.h"
#include "RaiseError.h"

#include <assert.h>

const size_t type_template_paramter_0 = pt_end + 4;//
const size_t type_template_paramter_max = type_template_paramter_0 + 256;
const size_t type_special_end = type_template_paramter_max + 1;

void GetPrimitiveTypeName(std::string& typeName, PredefinedType type)
{
	switch (type)
	{
	case pt_void:
		typeName = "void";
		break;
	case pt_bool:
		typeName = "bool";
		break;
	case pt_char:
		typeName = "char";
		break;
	case pt_schar:
		typeName = "signed char";
		break;
	case pt_uchar:
		typeName = "unsigned char";
		break;
	case pt_wchar_t:
		typeName = "wchar_t";
		break;
	case pt_short:
		typeName = "short";
		break;
	case pt_ushort:
		typeName = "unsigned short";
		break;
	case pt_long:
		typeName = "long";
		break;
	case pt_ulong:
		typeName = "unsigned long";
		break;
	case pt_longlong:
		typeName = "long long";
		break;
	case pt_ulonglong:
		typeName = "unsigned long long";
		break;
	case pt_int:
		typeName = "int";
		break;
	case pt_uint:
		typeName = "unsigned int";
		break;
	case pt_float:
		typeName = "float";
		break;
	case pt_double:
		typeName = "double";
		break;
	case pt_long_double:
		typeName = "long double";
		break;
	case pt_string_t:
		typeName = "string_t";
		break;
	default:
		assert(false);
	}
}


bool TypeNode::CompareTypeNodePtrByName::operator()(const TypeNode* lhs, const TypeNode* rhs) const
{
	return lhs->m_name < rhs->m_name;
}

TypeNode* TypeNode::TypeNodeContainer::getTypeNodeByName(const std::string& name)
{
	TypeNode dummy;
	dummy.m_name = name;
	iterator it = find(&dummy);
	if (end() == it)
	{
		return 0;
	}
	else
	{
		return (*it);
	}
}

template<typename T>
T* TypeNode::TypeNodeContainer::addTypeNode(TypeNode* enclosing, const std::string& name, IdentifyNode* identifyNode)
{
	TypeNode* child = getTypeNodeByName(name);
	if (0 == child)
	{
		T* result = new T;
		result->m_name = name;
		result->m_enclosing = enclosing;
		result->m_identifyNode = identifyNode;
		result->m_sourceFile = g_compiler.m_currentSourceFile;
		this->insert(result);
		return result;
	}
	else
	{
		char buf[4096];
		sprintf_s(buf, "\'%s\' : already defined in %s(%d,%d)",
			name.c_str(), child->m_sourceFile->m_fileName.c_str(),
			child->m_identifyNode->m_lineNo, child->m_identifyNode->m_columnNo);
		ErrorList_AddItem(getCurrentSourceFileName(), identifyNode->m_lineNo,
			identifyNode->m_columnNo, semantic_error_type_redefined, buf);
		return 0;
	}
}

TypeNode::TypeNode()
{
	m_enclosing = 0;
	m_identifyNode = 0;
	m_sourceFile = 0;
}


TypeNode::~TypeNode()
{}

TypeNode* TypeNode::getChildNode(const std::string& name)
{
	return 0;
}

void TypeNode::getActualTypeFullName(std::string& name)
{
	name.clear();
	std::vector<TypeNode*> enclosings;
	getEnclosings(enclosings);
	auto it = enclosings.begin();
	auto end = enclosings.end();
	for (; it != end; ++it)
	{
		TypeNode* enclosing = *it;
		name += enclosing->m_name + "::";
	}
	name += m_name;
}

void TypeNode::getLocalName(std::string& name)
{
	name = m_name;
}

void TypeNode::getFullName(std::string& name)
{
	std::string localName;
	name.clear();
	std::vector<TypeNode*> enclosings;
	getEnclosings(enclosings);
	auto it = enclosings.begin();
	auto end = enclosings.end();
	for (; it != end; ++it)
	{
		TypeNode* enclosing = *it;
		enclosing->getLocalName(localName);
		name += localName + "::";
	}
	getLocalName(localName);
	name += localName;
}

void TypeNode::getNativeName(std::string& name)
{
	MemberNode* memberNode = getSyntaxNode();
	if (memberNode && memberNode->m_nativeName)
	{
		memberNode->getNativeName(name, 0);
	}
	else
	{
		getFullName(name);
	}
}

MemberNode* TypeNode::getSyntaxNode()
{
	return 0;
}

TypeCategory TypeNode::getTypeCategory(TemplateArguments* templateArguments)
{
	assert(false);
	return unknown_type;
}

TypeNode* TypeNode::getActualTypeNode(TemplateArguments* templateArguments)
{
	return this;
}

TypeNode* TypeNode::getEnclosing()
{
	return m_enclosing;
}

void TypeNode::getEnclosings(std::vector<TypeNode*>& enclosings)
{
	TypeNode* enclosing = m_enclosing;
	while (enclosing)
	{
		enclosings.push_back(enclosing);
		enclosing = enclosing->m_enclosing;
	}
	std::reverse(enclosings.begin(), enclosings.end());
}

bool TypeNode::isNamespace()
{
	return tc_namespace == m_category;
}

bool TypeNode::isPredefinedType()
{
	return tc_predefined_type == m_category;
}

bool TypeNode::isEnum()
{
	return tc_enum_type == m_category;
}

bool TypeNode::isClass()
{
	return tc_class_type == m_category;
}

bool TypeNode::isTemplateClass()
{
	if (tc_class_type == m_category)
	{
		return static_cast<ClassTypeNode*>(this)->m_classNode->isTemplateClass();
	}
	return false;
}

bool TypeNode::isUnderTemplateClass()
{
	TypeNode* enclosing = m_enclosing;
	while (enclosing && !enclosing->isNamespace())
	{
		if (enclosing->isTemplateClass())
		{
			return true;
		}
		enclosing = enclosing->m_enclosing;
	}
	return false;
}

bool TypeNode::isTemplateParameter()
{
	return tc_template_paramter == m_category;
}

bool TypeNode::isTemplateClassInstance()
{
	return tc_template_class_instance == m_category;
}

bool TypeNode::isTypedef()
{
	return tc_typedef == m_category;
}

bool TypeNode::isTypeDeclaration()
{
	return tc_type_declaration == m_category;
}

PredefinedTypeNode::PredefinedTypeNode()
{
	m_category = tc_predefined_type;
}

TypeCategory PredefinedTypeNode::getTypeCategory(TemplateArguments* templateArguments)
{
	return pt_void == m_type ? void_type : primitive_type;
}

EnumTypeNode::EnumTypeNode()
{
	m_category = tc_enum_type;
}

MemberNode* EnumTypeNode::getSyntaxNode()
{
	return m_enumNode;
}

TypeCategory EnumTypeNode::getTypeCategory(TemplateArguments* templateArguments)
{
	return enum_type;
}

TypedefTypeNode::TypedefTypeNode()
{
	m_category = tc_typedef;
}

void TypedefTypeNode::getActualTypeFullName(std::string& name)
{
	m_typedefNode->m_srcTypeNode->getActualTypeFullName(name);
}

TypeNode* TypedefTypeNode::getActualTypeNode(TemplateArguments* templateArguments)
{
	TypeNode* actualTypeNode = m_typedefNode->getActualTypeNode(templateArguments);
	return actualTypeNode;
}

MemberNode* TypedefTypeNode::getSyntaxNode()
{
	return m_typedefNode;
}

TypeCategory TypedefTypeNode::getTypeCategory(TemplateArguments* templateArguments)
{
	return m_typedefNode->m_srcTypeNode->getTypeCategory(templateArguments);
}

TypeDeclarationTypeNode::TypeDeclarationTypeNode()
{
	m_category = tc_type_declaration;
}

MemberNode* TypeDeclarationTypeNode::getSyntaxNode()
{
	return m_typeDeclarationNode;
}

TypeCategory TypeDeclarationTypeNode::getTypeCategory(TemplateArguments* templateArguments)
{
	return m_typeDeclarationNode->m_typeCategory;
}

TemplateParameterTypeNode::TemplateParameterTypeNode()
{
	m_category = tc_template_paramter;
}

TypeCategory TemplateParameterTypeNode::getTypeCategory(TemplateArguments* templateArguments)
{
	TypeNode* actualTypeNode = templateArguments->findTypeNode(m_name);
	return actualTypeNode->getTypeCategory(templateArguments);

}

TypeNode* TemplateParameterTypeNode::getActualTypeNode(TemplateArguments* templateArguments)
{
	TypeNode* actualTypeNode = templateArguments->findTypeNode(m_name);
	return actualTypeNode;
}

ClassTypeNode::ClassTypeNode()
{
	m_category = tc_class_type;
}

EnumTypeNode* ClassTypeNode::addEnum(EnumNode* node)
{
	EnumTypeNode* res = m_children.addTypeNode<EnumTypeNode>(this, node->m_name->m_str, node->m_name);
	if (res)
	{
		res->m_enumNode = node;
	}
	return res;
}

ClassTypeNode* ClassTypeNode::addClass(ClassNode* node)
{
	ClassTypeNode* res = m_children.addTypeNode<ClassTypeNode>(this, node->m_name->m_str, node->m_name);
	if (res)
	{
		res->m_classNode = node;
	}
	return res;
}

TypedefTypeNode* ClassTypeNode::addTypedef(TypedefNode* node)
{
	TypedefTypeNode* res = m_children.addTypeNode<TypedefTypeNode>(this, node->m_name->m_str, node->m_name);
	if (res)
	{
		res->m_typedefNode = node;
	}
	return res;
}

TypeDeclarationTypeNode* ClassTypeNode::addTypeDeclaration(TypeDeclarationNode* node)
{
	TypeDeclarationTypeNode* res = m_children.addTypeNode<TypeDeclarationTypeNode>(this, node->m_name->m_str, node->m_name);
	if (res)
	{
		res->m_typeDeclarationNode = node;
	}
	return res;
}

TypeNode* ClassTypeNode::getChildNode(const std::string& name)
{
	return m_children.getTypeNodeByName(name);
}

MemberNode* ClassTypeNode::getSyntaxNode()
{
	return m_classNode;
}

TypeCategory ClassTypeNode::getTypeCategory(TemplateArguments* templateArguments)
{
	return m_classNode->isValueType() ? value_type : reference_type;
}

TemplateClassInstanceTypeNode::TemplateClassInstanceTypeNode()
{
	m_category = tc_template_class_instance;
}

MemberNode* TemplateClassInstanceTypeNode::getSyntaxNode()
{
	return m_templateClassInstanceNode;
}

TypeCategory TemplateClassInstanceTypeNode::getTypeCategory(TemplateArguments* templateArguments)
{
	return m_templateClassInstanceNode->m_classTypeNode->getTypeCategory(templateArguments);
}

void TemplateClassInstanceTypeNode::getLocalName(std::string& name)
{
	name = m_localName;
}

NamespaceTypeNode::NamespaceTypeNode()
{
	m_category = tc_namespace;
}

NamespaceTypeNode* NamespaceTypeNode::addNamespace(NamespaceNode* node)
{
	TypeNode* child = getChildNode(node->m_name->m_str);
	if (0 == child)
	{
		NamespaceTypeNode* result = new NamespaceTypeNode;
		result->m_name = node->m_name->m_str;
		result->m_enclosing = this;
		result->m_identifyNode = node->m_name;
		result->m_sourceFile = g_compiler.m_currentSourceFile;
		m_children.insert(result);
		g_typeTree.m_allNamespaces.push_back(result);
		return result;
	}
	else if (child->isNamespace())
	{
		NamespaceTypeNode* result = static_cast<NamespaceTypeNode*>(child);
		assert(result->m_name == node->m_name->m_str);
		//result->m_syntaxInfos.push_back(std::make_pair(node, g_compiler.m_currentSourceFile));
		return result;
	}
	else
	{
		char buf[4096];
		sprintf_s(buf, "\'%s\' : already defined in %s(%d,%d)",
			node->m_name->m_str.c_str(), child->m_sourceFile->m_fileName.c_str(),
			child->m_identifyNode->m_lineNo, child->m_identifyNode->m_columnNo);
		ErrorList_AddItem(getCurrentSourceFileName(), node->m_name->m_lineNo,
			node->m_name->m_columnNo, semantic_error_namespace_redefined, buf);
		return 0;
	}
}

EnumTypeNode* NamespaceTypeNode::addEnum(EnumNode* node)
{
	EnumTypeNode* res = m_children.addTypeNode<EnumTypeNode>(this, node->m_name->m_str, node->m_name);
	if (res)
	{
		res->m_enumNode = node;
	}
	return res;
}

ClassTypeNode* NamespaceTypeNode::addClass(ClassNode* node)
{
	ClassTypeNode* res = m_children.addTypeNode<ClassTypeNode>(this, node->m_name->m_str, node->m_name);
	if (res)
	{
		res->m_classNode = node;
		if (node->m_templateParametersNode)
		{
			std::vector<IdentifyNode*> templateParameterNodes;
			node->m_templateParametersNode->collectParameterNodes(templateParameterNodes);
			auto it = templateParameterNodes.begin();
			auto end = templateParameterNodes.end();
			for (; it != end; ++it)
			{
				IdentifyNode* identifyNode = *it;
				TemplateParameterTypeNode* typeNode = new TemplateParameterTypeNode();
				typeNode->m_name = identifyNode->m_str;
				typeNode->m_identifyNode = identifyNode;
				typeNode->m_sourceFile = g_compiler.m_currentSourceFile;
				res->m_parameterNodes.push_back(typeNode);
			}
		}
	}
	return res;
}

TypedefTypeNode* NamespaceTypeNode::addTypedef(TypedefNode* node)
{
	TypedefTypeNode* res = m_children.addTypeNode<TypedefTypeNode>(this, node->m_name->m_str, node->m_name);
	if (res)
	{
		res->m_typedefNode = node;
	}
	return res;
}

TypeDeclarationTypeNode* NamespaceTypeNode::addTypeDeclaration(TypeDeclarationNode* node)
{
	TypeDeclarationTypeNode* res = m_children.addTypeNode<TypeDeclarationTypeNode>(this, node->m_name->m_str, node->m_name);
	if (res)
	{
		res->m_typeDeclarationNode = node;
	}
	return res;
}


void CopyChildren(ClassTypeNode* dst, ClassTypeNode* src)
{
	auto it = src->m_children.begin();
	auto end = src->m_children.end();
	for (; it != end; ++it)
	{
		TypeNode* srcChild = *it;
		switch (srcChild->m_category)
		{
		case tc_enum_type:
			dst->addEnum(static_cast<EnumTypeNode*>(srcChild)->m_enumNode);
			break;
		case tc_class_type:
			{
				ClassTypeNode* dstChild = dst->addClass(static_cast<ClassTypeNode*>(srcChild)->m_classNode);
				CopyChildren(dstChild, static_cast<ClassTypeNode*>(srcChild));
			}
			break;
		case tc_typedef:
			dst->addTypedef(static_cast<TypedefTypeNode*>(srcChild)->m_typedefNode);
			break;
		case tc_type_declaration:
			dst->addTypeDeclaration(static_cast<TypeDeclarationTypeNode*>(srcChild)->m_typeDeclarationNode);
			break;
		default:
			assert(false);
		}
	}
}

TemplateClassInstanceTypeNode* NamespaceTypeNode::addTemplateClassInstance(TemplateClassInstanceNode* node)
{
	std::string name = node->m_name->m_str;
	std::string localName = node->m_name->m_str;
	name += "<";
	localName += "<";
	auto begin = node->m_templateArguments.m_arguments.begin();
	auto end = node->m_templateArguments.m_arguments.end();
	for (auto it = begin; it != end; ++it)
	{
		if (it != begin)
		{
			name += ", ";
			localName += ", ";
		}
		TypeNode* paramTypeNode = it->m_typeNode;
		std::string paramName;
		paramTypeNode->getActualTypeFullName(paramName);
		name += paramName;
		paramTypeNode->getFullName(paramName);
		localName += paramName;
	}
	name += ">";
	localName += ">";
	TemplateClassInstanceTypeNode* result = m_children.addTypeNode<TemplateClassInstanceTypeNode>(this, name, node->m_name);
	if (result)
	{
		result->m_localName = localName;
		result->m_templateClassInstanceNode = node;
		CopyChildren(result, node->m_classTypeNode);
	}
	return result;
}


TypeNode* NamespaceTypeNode::getChildNode(const std::string& name)
{
	return m_children.getTypeNodeByName(name);
}

TypeTree::TypeTree()
{
	m_predefinedTypeNodes.resize(pt_end);
	for (size_t i = 0; i < pt_end; ++i)
	{
		m_predefinedTypeNodes[i].m_type = (PredefinedType)i;
		GetPrimitiveTypeName(m_predefinedTypeNodes[i].m_name, (PredefinedType)i);
	}
}

TypeTree::~TypeTree()
{

}

NamespaceTypeNode* TypeTree::getRootNamespaceTypeNode()
{
	return &m_root;
}

PredefinedTypeNode* TypeTree::getPredefinedTypeNode(PredefinedType type)
{
	assert(0 <= type && type < pt_end);
	return &m_predefinedTypeNodes[type];
}


bool TypeTree::checkTypeNameNode(TypeNode*& initialTypeTreeNode, TypeNode*& finalTypeTreeNode,
	ScopeNameListNode* scopeNameListNode, TypeNode* enclosingTypeTreeNode, TemplateArguments* templateArguments)
{
	assert(0 == templateArguments || templateArguments->m_classTypeNode->isTemplateClass());
	initialTypeTreeNode = 0;
	finalTypeTreeNode = 0;
	std::vector<ScopeNameNode*> scopeNameNodes;
	scopeNameListNode->collectIdentifyNodes(scopeNameNodes);
	assert(!scopeNameNodes.empty());

	if (0 != templateArguments && !scopeNameListNode->isGlobal())
	{
		ScopeNameNode* scopeNameNode = scopeNameNodes.front();
		if (!scopeNameNode->isTemplateForm())
		{
			if (scopeNameNode->m_name->m_str == templateArguments->m_className)
			{
				initialTypeTreeNode = templateArguments->m_classTypeNode;
				if (1 == scopeNameNodes.size())
				{
					//finalTypeTreeNode->isTemplateClass()
					finalTypeTreeNode = initialTypeTreeNode; 
					return true;
				}
				else
				{
					//0 == finalTypeTreeNode || finalTypeTreeNode->isUnderTemplateClass()
					scopeNameNodes.erase(scopeNameNodes.begin());
					TypeNode* tmpTypeNode = 0;
					return findNodeByScopeNames(tmpTypeNode, finalTypeTreeNode, scopeNameNodes, initialTypeTreeNode, 0);
				}
			}
			initialTypeTreeNode = templateArguments->findTypeNode(scopeNameNode->m_name->m_str);
			if(initialTypeTreeNode)
			{
				if (1 == scopeNameNodes.size())
				{
					//finalTypeTreeNode->isTemplateParameter()
					finalTypeTreeNode = initialTypeTreeNode;
				}
				else
				{
					finalTypeTreeNode = 0;
				}
				return true;
			}
		}
	}
	if (scopeNameListNode->isGlobal())
	{
		return findNodeByScopeNames(initialTypeTreeNode, finalTypeTreeNode, scopeNameNodes, getRootNamespaceTypeNode(), templateArguments);
	}

	TypeNode* enclosing = enclosingTypeTreeNode;
	while (enclosing)
	{
		if(findNodeByScopeNames(initialTypeTreeNode, finalTypeTreeNode, scopeNameNodes, enclosing, templateArguments))
		{
			return true;
		}		
		enclosing = enclosing->getEnclosing();
	}

	initialTypeTreeNode = 0;
	finalTypeTreeNode = 0;
	bool result = false;
	auto it = m_allNamespaces.begin();
	auto end = m_allNamespaces.end();
	for (; it != end; ++it)
	{
		TypeNode* tempInitialTypeTreeNode = 0;
		TypeNode* tempFinalTypeTreeNode = 0;
		if(findNodeByScopeNames(tempInitialTypeTreeNode, tempFinalTypeTreeNode, scopeNameNodes, *it, templateArguments))
		{
			if (result)
			{
				char buf[4096];
				std::string str;
				scopeNameListNode->getString(str);
				sprintf_s(buf, "\'%s\' : ambiguous type name could be %s(%d, %d) or %s(%d, %d)",
					str.c_str(),
					finalTypeTreeNode->m_sourceFile->m_fileName.c_str(), 
					finalTypeTreeNode->m_identifyNode->m_lineNo, 
					finalTypeTreeNode->m_identifyNode->m_columnNo,
					tempFinalTypeTreeNode->m_sourceFile->m_fileName.c_str(), 
					tempFinalTypeTreeNode->m_identifyNode->m_lineNo,
					tempFinalTypeTreeNode->m_identifyNode->m_columnNo);
				ErrorList_AddItem_CurrentFile(scopeNameNodes.back()->m_name->m_lineNo,
					scopeNameNodes.back()->m_name->m_columnNo, semantic_error_ambiguous_type_name, buf);
				return false;
			}
			else
			{
				initialTypeTreeNode = tempInitialTypeTreeNode;
				finalTypeTreeNode = tempFinalTypeTreeNode;
				result = true;
			}
		}
	}
	if (!result)
	{
		RaiseError_InvalidTypeName(scopeNameListNode);
	}
	return result;
}


bool TypeTree::findNodeByScopeNames(TypeNode*& initialTypeTreeNode, TypeNode*& finalTypeTreeNode,
	const std::vector<ScopeNameNode*>& scopeNameNodes, TypeNode* enclosingTypeTreeNode, TemplateArguments* templateArguments)
{
	assert(!enclosingTypeTreeNode->isTypedef());
	initialTypeTreeNode = 0;
	finalTypeTreeNode = 0;

	auto it = scopeNameNodes.begin();
	auto end = scopeNameNodes.end();
	initialTypeTreeNode = findNodeByScopeName(*it, enclosingTypeTreeNode, templateArguments);
	TypeNode* currentTypeTreeNode = initialTypeTreeNode;
	while (true)
	{
		if (0 == currentTypeTreeNode)
		{
			return false;
		}
		finalTypeTreeNode = currentTypeTreeNode;
		//currentTypeTreeNode = currentTypeTreeNode->getActualTypeNode(templateArguments);
		//assert(0 != currentTypeTreeNode);
		if (currentTypeTreeNode->isTypedef())
		{
			currentTypeTreeNode = static_cast<TypedefTypeNode*>(currentTypeTreeNode)->m_typedefNode->m_srcTypeNode;
			if (0 == currentTypeTreeNode)
			{
				//under template parameter
				finalTypeTreeNode = 0;
				return true;
			}
			assert(currentTypeTreeNode && !currentTypeTreeNode->isTypedef());
		}
		//if (currentTypeTreeNode->isTemplateParameter())
		//{
		//	currentTypeTreeNode = templateArguments->findTypeNode(currentTypeTreeNode->m_name);
		//	assert(0 != currentTypeTreeNode);
		//}
		++it;
		if (end == it)
		{
			return !(currentTypeTreeNode->isNamespace());
		}
		currentTypeTreeNode = findNodeByScopeName(*it, currentTypeTreeNode, templateArguments);
	}
}

TypeNode* TypeTree::findNodeByScopeName(ScopeNameNode* scopeNameNode, TypeNode* enclosingTypeTreeNode, TemplateArguments* templateArguments)
{
	if (templateArguments && templateArguments->m_classTypeNode->isTemplateClass())//must be TypeNameNode::calcTypeNodes
	{
		if (scopeNameNode->isTemplateForm())
		{
			TypeNode* result = enclosingTypeTreeNode->getChildNode(scopeNameNode->m_name->m_str);
			if (0 == result || !result->isTemplateClass())
			{
				return 0;
			}
			std::vector<TypeNameNode*> paramTypeNameNodes;
			scopeNameNode->m_parameterList->collectTypeNameNodes(paramTypeNameNodes);
			assert(!paramTypeNameNodes.empty());
			if (paramTypeNameNodes.size() != static_cast<ClassTypeNode*>(result)->m_parameterNodes.size())
			{
				return 0;
			}
			bool hasUndeteminedType = false;
			std::string name = scopeNameNode->m_name->m_str;
			name += "<";
			auto begin = paramTypeNameNodes.begin();
			auto end = paramTypeNameNodes.end();
			for (auto it = begin; it != end; ++it)
			{
				if (it != begin)
				{
					name += ", ";
				}
				TypeNameNode* paramTypeNameNode = *it;
				assert(paramTypeNameNode->m_startTypeNode);
				if (0 == paramTypeNameNode->m_typeNode ||
					paramTypeNameNode->m_typeNode->isTemplateParameter() ||
					paramTypeNameNode->m_typeNode->isTemplateClass() ||
					paramTypeNameNode->m_typeNode->isUnderTemplateClass())
				{
					hasUndeteminedType = true;
					break;
				}
				else
				{
					assert(paramTypeNameNode->m_typeNode->isPredefinedType() ||
						paramTypeNameNode->m_typeNode->isEnum() ||
						paramTypeNameNode->m_typeNode->isClass() ||
						paramTypeNameNode->m_typeNode->isTemplateClassInstance() ||
						paramTypeNameNode->m_typeNode->isTypedef() ||
						paramTypeNameNode->m_typeNode->isTypeDeclaration());
					std::string paramName;
					paramTypeNameNode->m_typeNode->getActualTypeFullName(paramName);
					name += paramName;
				}
			}
			name += ">";
			if (!hasUndeteminedType)
			{
				result = enclosingTypeTreeNode->getChildNode(name);
			}
			return result;
		}
		else
		{
			TypeNode* result = enclosingTypeTreeNode->getChildNode(scopeNameNode->m_name->m_str);
			if (0 == result || result->isTemplateClass())
			{
				return 0;
			}
			return result;
		}
	}
	else
	{
		if (scopeNameNode->isTemplateForm())
		{
			TypeNode* result = enclosingTypeTreeNode->getChildNode(scopeNameNode->m_name->m_str);
			if (0 == result || !result->isTemplateClass())
			{
				return 0;
			}
			std::vector<TypeNameNode*> paramTypeNameNodes;
			scopeNameNode->m_parameterList->collectTypeNameNodes(paramTypeNameNodes);
			assert(!paramTypeNameNodes.empty());
			if (paramTypeNameNodes.size() != static_cast<ClassTypeNode*>(result)->m_parameterNodes.size())
			{
				return 0;
			}
			bool hasUndeteminedType = false;
			std::string name = scopeNameNode->m_name->m_str;
			name += "<";
			auto begin = paramTypeNameNodes.begin();
			auto end = paramTypeNameNodes.end();
			for (auto it = begin; it != end; ++it)
			{
				if (it != begin)
				{
					name += ", ";
				}
				TypeNameNode* paramTypeNameNode = *it;
				TypeNode* paramTypeNode = paramTypeNameNode->getTypeNode(templateArguments);
				if(0 == paramTypeNode)
				{
					return 0;
				}
				else
				{
					std::string paramName;
					paramTypeNode->getActualTypeFullName(paramName);
					name += paramName;
				}
			}
			name += ">";
			if (!hasUndeteminedType)
			{
				result = enclosingTypeTreeNode->getChildNode(name);
			}
			return result;
		}
		else
		{
			TypeNode* result = enclosingTypeTreeNode->getChildNode(scopeNameNode->m_name->m_str);
			if (0 == result || result->isTemplateClass())
			{
				return 0;
			}
			return result;
		}
	}
}


TypeTree g_typeTree;
