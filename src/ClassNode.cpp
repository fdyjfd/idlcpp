#include "ClassNode.h"
#include "TypeNameNode.h"
#include "ScopeNameNode.h"
#include "ScopeNameListNode.h"
#include "IdentifyNode.h"
#include "IdentifyListNode.h"
#include "TypeNameListNode.h"

#include "TemplateParametersNode.h"
#include "TemplateClassInstanceNode.h"
#include "MemberNode.h"
#include "MemberListNode.h"
#include "MethodNode.h"
#include "ParameterListNode.h"
#include "ParameterNode.h"
#include "PropertyNode.h"
#include "FieldNode.h"
#include "NamespaceNode.h"
#include "ProgramNode.h"
#include "ErrorList.h"
#include "RaiseError.h"
#include "Options.h"
#include "Compiler.h"
#include "TypeTree.h"
#include "DelegateNode.h"

#include <assert.h>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

const char g_strPublic[] = {"public "};

void checkBaseTypes(ClassNode* classNode, std::vector<TypeNameNode*>& baseTypeNameNodes, std::vector<TypeNode*>& baseTypeNodes, TemplateArguments* templateArguments)
{
	assert(baseTypeNameNodes.size() == baseTypeNodes.size());
	size_t count = baseTypeNameNodes.size();
	for(size_t i = 0; i < count; ++i)
	{
		TypeNameNode* typeNameNode = baseTypeNameNodes[i];
		TypeNode* typeNode = baseTypeNodes[i];
		if (0 == typeNode)
		{
			continue;
		}
		TypeCategory baseTypeCategory = typeNode->getTypeCategory(templateArguments);
		if(classNode->isValueType())
		{
			if (value_type != baseTypeCategory)
			{
				char buf[4096];
				sprintf_s(buf, "\'%s\' : base type must be value type", typeNameNode->m_scopeNameList->m_scopeName->m_name->m_str.c_str());
				ErrorList_AddItem_CurrentFile(typeNameNode->m_scopeNameList->m_scopeName->m_name->m_lineNo,
					typeNameNode->m_scopeNameList->m_scopeName->m_name->m_columnNo, semantic_error_base_type, buf);
			}
		}
		else
		{
			if (0 == i)
			{
				if (reference_type != baseTypeCategory)
				{
					char buf[4096];
					sprintf_s(buf, "\'%s\' : first base type must be reference type", typeNameNode->m_scopeNameList->m_scopeName->m_name->m_str.c_str());
					ErrorList_AddItem_CurrentFile(typeNameNode->m_scopeNameList->m_scopeName->m_name->m_lineNo,
						typeNameNode->m_scopeNameList->m_scopeName->m_name->m_columnNo, semantic_error_base_type, buf);
				}
			}
			else
			{
				if (reference_type != baseTypeCategory && value_type != baseTypeCategory)
				{
					char buf[4096];
					sprintf_s(buf, "\'%s\' : base type must be reference type or value type", typeNameNode->m_scopeNameList->m_scopeName->m_name->m_str.c_str());
					ErrorList_AddItem_CurrentFile(typeNameNode->m_scopeNameList->m_scopeName->m_name->m_lineNo,
						typeNameNode->m_scopeNameList->m_scopeName->m_name->m_columnNo, semantic_error_base_type, buf);
				}
			}
		}
		auto it = std::find(baseTypeNodes.begin(), baseTypeNodes.begin() + i, typeNode);
		if(it != baseTypeNodes.begin() + i)
		{
			size_t index = it - baseTypeNodes.begin();
			char buf[4096];
			sprintf_s(buf, "\'%s\' : is already a direct base class, the previous declaration is at line %d, column %d", 
				typeNameNode->m_scopeNameList->m_scopeName->m_name->m_str.c_str(),
				baseTypeNameNodes[index]->m_scopeNameList->m_scopeName->m_name->m_lineNo,
				baseTypeNameNodes[index]->m_scopeNameList->m_scopeName->m_name->m_columnNo);
			ErrorList_AddItem_CurrentFile(typeNameNode->m_scopeNameList->m_scopeName->m_name->m_lineNo,
				typeNameNode->m_scopeNameList->m_scopeName->m_name->m_columnNo, semantic_error_base_redeclared, buf);
		}
	}
}

struct Overload
{
	IdentifyNode* methodName;
	size_t parameterCount;
	std::string manglingName;
	bool operator < (const Overload& arg) const
	{
		int cmp = methodName->m_str.compare(arg.methodName->m_str);
		if (cmp != 0)
		{
			return cmp < 0;
		}
		if (parameterCount != arg.parameterCount)
		{
			return parameterCount < arg.parameterCount;
		}
		return manglingName < arg.manglingName;
	}
};

bool isDefaultConstructor(ClassNode* classNode, MethodNode* methodNode)
{
	if(classNode->m_name->m_str == methodNode->m_name->m_str)
	{
		if(0 == methodNode->getParameterCount())
		{
			return true;
		}
	}
	return false;
}

void checkMemberNames(ClassNode* classNode, std::vector<MemberNode*>& memberNodes, TemplateArguments* templateArguments)
{
	std::set<IdentifyNode*, CompareIdentifyPtr> methodNames;
	std::set<IdentifyNode*, CompareIdentifyPtr> staticMethodNames;
	std::set<IdentifyNode*, CompareIdentifyPtr> otherNames;
	std::set<Overload> methods;
	std::set<Overload> staticMethods;

	size_t count = memberNodes.size();
	IdentifyNode* collisionNode = 0;
	for(size_t i = 0; i < count; ++i)
	{
		MemberNode* memberNode = memberNodes[i];
		bool nameCollision = false;
		IdentifyNode* identify = memberNode->m_name;
		if (0 == identify)
		{
			//invalid operator has no name
			continue;
		}
		if(snt_method == memberNode->m_nodeType || snt_operator == memberNode->m_nodeType)
		{
			MethodNode* methodNode = static_cast<MethodNode*>(memberNode);
			if(methodNode->m_name->m_str == classNode->m_name->m_str && !methodNode->isStatic())
			{
				if(0 != methodNode->m_resultTypeName)
				{
					char buf[4096];
					sprintf_s(buf, "\'%s\' : constructor with return type", identify->m_str.c_str());
					ErrorList_AddItem_CurrentFile(identify->m_lineNo,
						identify->m_columnNo, semantic_error_constructor_with_return_type, buf);
					continue;
				}
				if(0 != methodNode->m_modifier)
				{
					char buf[4096];
					sprintf_s(buf, "\'%s\' : constructor cannot be declared %s", identify->m_str.c_str(), 
						g_keywordTokens[methodNode->m_modifier->m_nodeType - snt_begin_output - 1]);
					ErrorList_AddItem_CurrentFile(identify->m_lineNo,
						identify->m_columnNo, semantic_error_constructor_with_modifier, buf);
					continue;
				}
			}
			else
			{
				if(0 == methodNode->m_resultTypeName)
				{
					char buf[4096];
					sprintf_s(buf, "\'%s\' : missing type specifier", identify->m_str.c_str());
					ErrorList_AddItem_CurrentFile(identify->m_lineNo,
						identify->m_columnNo, semantic_error_missing_type_specifier, buf);
					continue;
				}
			}
			auto it = otherNames.find(identify);
			if(otherNames.end() != it)
			{
				collisionNode = *it;
				nameCollision = true;
			}
			else
			{
				if (methodNode->isStatic())
				{
					it = methodNames.find(identify);
					if (methodNames.end() != it)
					{
						collisionNode = *it;
						nameCollision = true;
					}
				}
				else
				{
					it = staticMethodNames.find(identify);
					if (staticMethodNames.end() != it)
					{
						collisionNode = *it;
						nameCollision = true;
					}
				}
				if (!nameCollision)
				{
					Overload overload;
					overload.methodName = identify;
					overload.parameterCount = methodNode->getParameterCount();
					methodNode->calcManglingName(overload.manglingName, templateArguments);
					if (methodNode->isStatic())
					{
						auto res = staticMethods.insert(overload);
						if (!res.second)
						{
							collisionNode = res.first->methodName;
							nameCollision = true;
						}
						else
						{
							staticMethodNames.insert(identify);
						}
					}
					else
					{
						++overload.parameterCount;
						auto res = methods.insert(overload);
						if (!res.second)
						{
							collisionNode = res.first->methodName;
							nameCollision = true;
						}
						else
						{
							methodNames.insert(identify);
						}
					}
				}
			}
		}
		else
		{
			if(identify->m_str == classNode->m_name->m_str)
			{
				char buf[4096];
				sprintf_s(buf, "\'%s\' : class member name cannot equal to class name", identify->m_str.c_str());
				ErrorList_AddItem_CurrentFile(identify->m_lineNo,
					identify->m_columnNo, semantic_error_member_name_equal_to_class_name, buf);
			}
			auto it = otherNames.find(identify);
			if(otherNames.end() !=  it)
			{
				collisionNode = *it;
				nameCollision = true;
			}
			else
			{
				otherNames.insert(identify);
			}	
			if((it = methodNames.find(identify)) != methodNames.end())
			{
				collisionNode = *it;
				nameCollision = true;
			}
			else if((it = staticMethodNames.find(identify)) != staticMethodNames.end())
			{
				collisionNode = *it;
				nameCollision = true;
			}
		}
		if(nameCollision)
		{
			char buf[4096];
			sprintf_s(buf, "\'%s\' : member already defined at line %d, column %d", identify->m_str.c_str(), 
				collisionNode->m_lineNo, collisionNode->m_columnNo);
			ErrorList_AddItem_CurrentFile(identify->m_lineNo,
				identify->m_columnNo, semantic_error_member_redefined, buf);
		}
	}
}

static void ParseConceptList(
	IdentifyNode*& categoryNode,
	ClassNode::LazyBool& copyableFlag,
	IdentifyListNode* conceptList)
{
	const char* s_categorys[] =
	{
		"void_object",
		"primitive_object",
		"enum_object",
		"value_object",
		"reference_object",
		"atomic_reference_object",
		"enumerator",
		"instance_field",
		"static_field",
		"instance_property",
		"static_property",
		"instance_method",
		"static_method",
		"function_argument",
		"function_result",
		"void_type",
		"primitive_type",
		"enum_type",
		"class_type",
		"type_alias",
		"name_space",
	};

	std::vector<IdentifyNode*> identifyNodes;
	conceptList->collectIdentifyNodes(identifyNodes);
	for (IdentifyNode* identifyNode : identifyNodes)
	{
		if (identifyNode->m_str == "copyable")
		{
			copyableFlag = ClassNode::lb_true;
		}
		else if (identifyNode->m_str == "noncopyable")
		{
			copyableFlag = ClassNode::lb_false;
		}
		else if (0 == categoryNode)
		{
			for (int i = 0; i < sizeof(s_categorys) / sizeof(s_categorys[0]); ++i)
			{
				if (identifyNode->m_str == s_categorys[i])
				{
					categoryNode = identifyNode;
					break;
				}
			}
		}
	}
}


ClassNode::ClassNode(TokenNode* keyword, IdentifyListNode* conceptList, IdentifyNode* name)
{
	assert(snt_keyword_struct == keyword->m_nodeType 
		|| snt_keyword_class == keyword->m_nodeType 
		|| snt_keyword_delegate == keyword->m_nodeType);

	m_nodeType = snt_class;
	m_keyword = keyword;
	//m_conceptList = conceptList;
	m_name = name;
	m_modifier = 0;
	m_colon = 0;
	m_baseList = 0;
	m_leftBrace = 0;
	m_memberList = 0;
	m_rightBrace = 0;
	m_semicolon = 0;
	m_templateParametersNode = 0;
	m_typeNode = 0;
	m_category = 0;
	m_copyableFlag = lb_unknown;

	ParseConceptList(m_category, m_copyableFlag, conceptList);
	if(0 == m_category)
	{
		m_isValueType = (snt_keyword_struct == keyword->m_nodeType || snt_keyword_delegate == keyword->m_nodeType);
	}
	else
	{
		m_isValueType = (m_category->m_str == "value_object");
	}
	m_override = false;
	m_abstractFlag = lb_unknown;
}

void ClassNode::setTemplateParameters(TemplateParametersNode* templateParametersNode)
{
	assert(templateParametersNode);
	m_templateParametersNode = templateParametersNode;
}

void ClassNode::setMemberList(TokenNode* leftBrace, MemberListNode* memberList, TokenNode* rightBrace)
{
	m_leftBrace = leftBrace;
	m_memberList = memberList;
	m_rightBrace = rightBrace;
	m_memberList->initializeMembersEnclosing(this);
}


void ClassNode::extendInternalCode(TypeNode* enclosingTypeNode, TemplateArguments* templateArguments)
{
	if (m_templateParametersNode)
	{
		assert(0 == templateArguments);
		templateArguments = &m_templateArguments;
	}

	if(!isAbstractClass())
	{
		//New NewArray
		buildAdditionalMethods();
	}

	//size_t count = m_additionalMethods.size();
	//for (size_t i = 0; i < count; ++i)
	//{
	//	MethodNode* methodNode = m_additionalMethods[i];
	//	assert(methodNode->m_resultTypeName);
	//	methodNode->m_resultTypeName->calcTypeNodes(m_typeNode, templateArguments);
	//}

	std::vector<MemberNode*> memberNodes;
	m_memberList->collectMemberNodes(memberNodes);
	size_t count = memberNodes.size();
	for (size_t i = 0; i < count; ++i)
	{
		MemberNode* memberNode = memberNodes[i];
		switch (memberNode->m_nodeType)
		{
		case snt_class:
			static_cast<ClassNode*>(memberNode)->extendInternalCode(m_typeNode, templateArguments);
			break;
		case snt_delegate:
			static_cast<DelegateNode*>(memberNode)->extendInternalCode(m_typeNode, templateArguments);
			break;
		}
	}

}

extern "C" extern int yytokenno;
extern "C" extern int yylineno;
extern "C" extern int yycolumnno;

void ClassNode::GenerateCreateInstanceMethod(const char* methodName, MethodNode* constructor)
{
	IdentifyNode* name = (IdentifyNode*)newIdentify(methodName);
	MethodNode* method = (MethodNode*)newMethod(name, 
		constructor->m_leftParenthesis, constructor->m_parameterList, 
		constructor->m_rightParenthesis, constructor->m_constant);
	method->m_semicolon = constructor->m_semicolon;
	ScopeNameNode* scopeName = (ScopeNameNode*)newScopeName(m_name, 0, 0, 0);
	ScopeNameListNode* scopeNameList = (ScopeNameListNode*)newScopeNameList(0, scopeName);
	TypeNameNode* typeName = (TypeNameNode*)newTypeName(scopeNameList);
	TokenNode* passing = (TokenNode*)newToken('+');
	setMethodResult(method, typeName, passing);
	TokenNode* modifier = (TokenNode*)newToken(snt_keyword_static);
	setMethodModifier(method, modifier);
	//if (constructor->m_filterNode)
	//{
	//	method->m_filterNode = (TokenNode*)newToken(constructor->m_filterNode->m_nodeType);
	//}
	method->m_enclosing = this;
	m_additionalMethods.push_back(method);
}

void ClassNode::GenerateCreateArrayMethod(const char* methodName, MethodNode* constructor)
{
	IdentifyNode* name = (IdentifyNode*)newIdentify(methodName);
	ParameterNode* parameter = (ParameterNode*)newParameter(newPrimitiveType(newToken(snt_keyword_unsigned), pt_uint), 0, 0, newIdentify("count"));
	ParameterListNode* parameterList = (ParameterListNode*)newParameterList(0,0,parameter);
	MethodNode* method = (MethodNode*)newMethod(name, 
		constructor->m_leftParenthesis, parameterList, 
		constructor->m_rightParenthesis, constructor->m_constant);
	method->m_semicolon = constructor->m_semicolon;

	ScopeNameNode* scopeName = (ScopeNameNode*)newScopeName(m_name, 0, 0, 0);
	ScopeNameListNode* scopeNameList = (ScopeNameListNode*)newScopeNameList(0, scopeName);
	TypeNameNode* typeName = (TypeNameNode*)newTypeName(scopeNameList);
	TokenNode* passing = (TokenNode*)newToken('+');
	setMethodResult(method, typeName, passing);
	setMethodResultArray(method);
	TokenNode* modifier = (TokenNode*)newToken(snt_keyword_static);
	setMethodModifier(method, modifier);
	//if (constructor->m_filterNode)
	//{
	//	method->m_filterNode = (TokenNode*)newToken(constructor->m_filterNode->m_nodeType);
	//}
	method->m_enclosing = this;
	m_additionalMethods.push_back(method);
}

void ClassNode::buildAdditionalMethods()
{
	int backupToken = yytokenno;
	int backupLine = yylineno;
	int backupColumn = yycolumnno;
	yytokenno = 0;
	yylineno = 0;
	yycolumnno = 0;

	MethodNode* defaultConstructor = 0;
	std::vector<MethodNode*> constructors;	
	std::vector<MemberNode*> memberNodes;
	m_memberList->collectMemberNodes(memberNodes);
	size_t memberCount = memberNodes.size();
	for(size_t i = 0; i < memberCount; ++i)
	{
		MemberNode* memberNode = memberNodes[i];
		if(snt_method == memberNode->m_nodeType)
		{
			MethodNode* methodNode = static_cast<MethodNode*>(memberNode);
			if(memberNode->m_name->m_str == m_name->m_str)
			{
				if(isDefaultConstructor(this, methodNode))
				{
					assert(0 == defaultConstructor);
					defaultConstructor = methodNode;
				}
				constructors.push_back(methodNode);
			}
		}
	}

	size_t count = constructors.size();
	for(size_t i = 0; i < count; ++i)
	{
		MethodNode* constructor = constructors[i];
		GenerateCreateInstanceMethod("New", constructor);
		//if(!isValueType())
		//{
		//	GenerateCreateInstanceMethod("NewARC", constructor);
		//}
	}
	if(0 != defaultConstructor && isValueType())
	{
		GenerateCreateArrayMethod("NewArray", defaultConstructor);
	}
	yytokenno = backupToken;
	yylineno = backupLine;
	yycolumnno = backupColumn;
}

bool ClassNode::isValueType()
{
	return m_isValueType;
}

bool ClassNode::isAbstractClass()
{
	if(lb_unknown == m_abstractFlag)
	{
		if(m_modifier)
		{
			m_abstractFlag = lb_true;
			return true;
		}
		std::vector<MemberNode*> memberNodes;
		m_memberList->collectMemberNodes(memberNodes);
		size_t count = memberNodes.size();
		for(size_t i = 0; i < count; ++i)
		{
			MemberNode* memberNode = memberNodes[i];
			if(snt_method == memberNode->m_nodeType)
			{
				MethodNode* methodNode = static_cast<MethodNode*>(memberNode);
				if(methodNode->isAbstract())
				{
					m_abstractFlag = lb_true;
					return true;
				}
			}
		}
		m_abstractFlag = lb_false;
	}
	return (lb_true == m_abstractFlag);
}

bool ClassNode::isCopyableClass(TemplateArguments* templateArguments)
{
	if (lb_unknown == m_copyableFlag)
	{
		bool baseClassCopyable = true;
		std::vector<TypeNameNode*> baseTypeNameNodes;
		m_baseList->collectTypeNameNodes(baseTypeNameNodes);
		size_t count = baseTypeNameNodes.size();
		for (size_t i = 0; i < count; ++i)
		{
			TypeNameNode* typeNameNode = baseTypeNameNodes[i];
			TypeNode* typeNode = typeNameNode->getActualTypeNode(templateArguments);
			if (typeNode->isTemplateClassInstance())
			{
				TemplateClassInstanceTypeNode* templateClassInstanceTypeNode = static_cast<TemplateClassInstanceTypeNode*>(typeNode);
				if (!templateClassInstanceTypeNode->m_classNode->isCopyableClass(&templateClassInstanceTypeNode->m_templateClassInstanceNode->m_templateArguments))
				{
					baseClassCopyable = false;
					break;
				}
			}
			else
			{
				assert(typeNode->isClass() && !typeNode->isTemplateClass());
				ClassTypeNode* classTypeNode = static_cast<ClassTypeNode*>(typeNode);
				if (!classTypeNode->m_classNode->isCopyableClass(0))
				{
					baseClassCopyable = false;
					break;
				}
			}
		}
		m_copyableFlag = baseClassCopyable ? lb_true : lb_false;
	}
	return (lb_true == m_copyableFlag);
}

void ClassNode::collectOverrideMethods(std::vector<MethodNode*>& methodNodes, TemplateArguments* templateArguments)
{
	std::vector<MemberNode*> memberNodes;
	m_memberList->collectMemberNodes(memberNodes);
	size_t count = memberNodes.size();
	for(size_t i = 0; i < count; ++i)
	{
		MemberNode* memberNode = memberNodes[i];
		if(snt_method == memberNode->m_nodeType)
		{
			MethodNode* methodNode = static_cast<MethodNode*>(memberNode);
			if(methodNode->m_override)
			{
				methodNodes.push_back(methodNode);
			}
		}
	}
	std::vector<TypeNameNode*> baseTypeNameNodes;
	m_baseList->collectTypeNameNodes(baseTypeNameNodes);
	count = baseTypeNameNodes.size();
	for(size_t i = 0; i < count; ++i)
	{
		TypeNameNode* typeNameNode = baseTypeNameNodes[i];
		TypeNode* typeNode = typeNameNode->getActualTypeNode(templateArguments);
		if (typeNode->isTemplateClassInstance())
		{
			TemplateClassInstanceTypeNode* templateClassInstanceTypeNode = static_cast<TemplateClassInstanceTypeNode*>(typeNode);
			templateClassInstanceTypeNode->m_classNode->collectOverrideMethods(methodNodes,
				&templateClassInstanceTypeNode->m_templateClassInstanceNode->m_templateArguments);
		}
		else
		{
			assert(typeNode->isClass() && !typeNode->isTemplateClass());
			ClassTypeNode* classTypeNode = static_cast<ClassTypeNode*>(typeNode);
			classTypeNode->m_classNode->collectOverrideMethods(methodNodes, 0);
		}
	}
}

bool ClassNode::hasOverrideMethod(TemplateArguments* templateArguments)
{
	std::vector<MemberNode*> memberNodes;
	m_memberList->collectMemberNodes(memberNodes);
	size_t count = memberNodes.size();
	for(size_t i = 0; i < count; ++i)
	{
		MemberNode* memberNode = memberNodes[i];
		if(snt_method == memberNode->m_nodeType)
		{
			MethodNode* methodNode = static_cast<MethodNode*>(memberNode);
			if(methodNode->m_override)
			{
				return true;
			}
		}
	}
	std::vector<TypeNameNode*> baseTypeNameNodes;
	m_baseList->collectTypeNameNodes(baseTypeNameNodes);
	count = baseTypeNameNodes.size();
	for(size_t i = 0; i < count; ++i)
	{
		TypeNameNode* typeNameNode = baseTypeNameNodes[i];
		TypeNode* typeNode = typeNameNode->getActualTypeNode(templateArguments);
		if (typeNode->isTemplateClassInstance())
		{
			TemplateClassInstanceTypeNode* templateClassInstanceTypeNode = static_cast<TemplateClassInstanceTypeNode*>(typeNode);
			if (templateClassInstanceTypeNode->m_classNode->hasOverrideMethod(&templateClassInstanceTypeNode->m_templateClassInstanceNode->m_templateArguments))
			{
				return true;
			}
		}
		else
		{
			assert(typeNode->isClass() && !typeNode->isTemplateClass());
			ClassTypeNode* classTypeNode = static_cast<ClassTypeNode*>(typeNode);
			if (classTypeNode->m_classNode->hasOverrideMethod(0))
			{
				return true;
			}
		}
	}
	return false;
}

bool ClassNode::isAdditionalMethod(MethodNode* methodNode)
{
	auto it = m_additionalMethods.begin();
	auto end = m_additionalMethods.end();
	for(; it != end; ++it)
	{
		if (methodNode == *it)
		{
			return true;
		}
	}
	return false;
}

bool ClassNode::needSubclassProxy(TemplateArguments* templateArguments)
{
	if (m_override)
	{
		if (hasOverrideMethod(templateArguments))
		{
			return true;
		}
	}
	return false;
}

TypeNode* ClassNode::getTypeNode()
{
	return m_typeNode;
}

void ClassNode::getLocalName(std::string& name, TemplateArguments* templateArguments)
{
	if (m_templateParametersNode)
	{
		assert(templateArguments 
			&& templateArguments->m_classTypeNode->isTemplateClassInstance()
			&& templateArguments->m_className == m_name->m_str
			&& templateArguments->m_arguments.size() == m_templateArguments.m_arguments.size());
		name = static_cast<TemplateClassInstanceTypeNode*>(templateArguments->m_classTypeNode)->m_localName;
	}
	else
	{
		name = m_name->m_str;
	}
}

void ClassNode::collectTypes(TypeNode* enclosingTypeNode, TemplateArguments* templateArguments)
{
	assert(enclosingTypeNode);
	assert(0 == m_typeNode);
	if (0 != m_templateParametersNode)
	{		
		if (!m_templateParametersNode->checkSemantic())
		{
			return;
		}
	}
	switch (enclosingTypeNode->m_category)
	{
	case tc_namespace:
		m_typeNode = static_cast<NamespaceTypeNode*>(enclosingTypeNode)->addClass(this);
		break;
	case tc_class_type:
		if (0 == m_templateParametersNode)
		{
			m_typeNode = static_cast<ClassTypeNode*>(enclosingTypeNode)->addClass(this);
		}
		else
		{
			RaiseError_NestedTemplateClass(m_name);
		}
		break;
	default:
		assert(false);
	}
	if(m_typeNode)
	{
		if (m_templateParametersNode)
		{
			m_templateArguments.m_className = m_name->m_str;
			m_templateArguments.m_classTypeNode = m_typeNode;
			auto it = m_typeNode->m_parameterNodes.begin();
			auto end = m_typeNode->m_parameterNodes.end();
			for (; it != end; ++it)
			{
				TemplateParameterTypeNode* typeNode = *it;
				TemplateArgument arg;
				arg.m_name = typeNode->m_name;
				arg.m_typeNode = typeNode;
				m_templateArguments.m_arguments.push_back(arg);
			}
			assert(0 == templateArguments);
			templateArguments = &m_templateArguments;
		}
		if (m_memberList)
		{
			m_memberList->collectTypes(m_typeNode, templateArguments);
		}
	}
}

void ClassNode::checkTypeNames(TypeNode* enclosingTypeNode, TemplateArguments* templateArguments)
{
	if (m_templateParametersNode)
	{
		assert(0 == templateArguments);
		templateArguments = &m_templateArguments;
	}
	std::vector<TypeNameNode*> baseTypeNameNodes;
	m_baseList->collectTypeNameNodes(baseTypeNameNodes);
	std::vector<TypeNode*> baseTypeNodes;
	size_t baseCount = baseTypeNameNodes.size();
	for (size_t i = 0; i < baseCount; ++i)
	{
		TypeNameNode* typeNameNode = baseTypeNameNodes[i];
		typeNameNode->calcTypeNodes(enclosingTypeNode, templateArguments);
	}
	m_memberList->checkTypeNames(m_typeNode, templateArguments);


	size_t count = m_additionalMethods.size();
	for (size_t i = 0; i < count; ++i)
	{
		MethodNode* methodNode = m_additionalMethods[i];
		//methodNode->checkTypeNames(m_typeNode, templateArguments);
		assert(methodNode->m_resultTypeName);
		methodNode->m_resultTypeName->calcTypeNodes(m_typeNode, templateArguments);
	}
}

void ClassNode::checkSemantic(TemplateArguments* templateArguments)
{
	MemberNode::checkSemantic(templateArguments);

	if (m_templateParametersNode)
	{
		if (0 == templateArguments)
		{
			return;
		}
	}
	assert(m_typeNode && m_typeNode->m_enclosing);
	std::vector<TypeNameNode*> baseTypeNameNodes;
	m_baseList->collectTypeNameNodes(baseTypeNameNodes);
	std::vector<TypeNode*> baseTypeNodes;
	size_t baseCount = baseTypeNameNodes.size();
	for (size_t i = 0; i < baseCount; ++i)
	{
		TypeNameNode* typeNameNode = baseTypeNameNodes[i];
		TypeNode* typeNode = typeNameNode->getTypeNode(templateArguments);
		if (0 != typeNode)
		{
			baseTypeNodes.push_back(typeNode);
			g_compiler.useType(typeNode, templateArguments, tu_use_definition, typeNameNode);
		}
	}

	checkBaseTypes(this, baseTypeNameNodes, baseTypeNodes, templateArguments);
	if (0 == baseCount)
	{
		if (!isValueType())
		{
			std::string typeName;
			m_typeNode->getFullName(typeName);
			if (typeName != "::pafcore::Reference")
			{
				RaiseError_MissingReferenceBaseType(m_name);
			}
		}
	}

	std::vector<MemberNode*> memberNodes;
	m_memberList->collectMemberNodes(memberNodes);

	size_t memberCount = memberNodes.size();
	for (size_t i = 0; i < memberCount; ++i)
	{
		MemberNode* memberNode = memberNodes[i];
		memberNodes[i]->checkSemantic(templateArguments);
	}
	checkMemberNames(this, memberNodes, templateArguments);
}
