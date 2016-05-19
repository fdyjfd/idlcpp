#include "ClassNode.h"
#include "TypeNameNode.h"
#include "ScopeListNode.h"
#include "IdentifyNode.h"
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
#include "SourceFile.h"
#include "ErrorList.h"
#include "RaiseError.h"
#include "Options.h"

#include <assert.h>
#include <vector>
#include <set>
#include <algorithm>

const char g_strPublic[] = {"public "};

void checkBaseNames(ClassNode* classNode, std::vector<std::pair<TokenNode*, TypeNameNode*>>& typeNameNodes)
{
	std::set<TypeNameNode*, CompareTypeNamePtr> items;
	size_t count = typeNameNodes.size();
	for(size_t i = 0; i < count; ++i)
	{
		TypeNameNode* typeName = typeNameNodes[i].second;
		if(0 == typeName->m_typeInfo)
		{
			continue;
		}
		TypeCategory baseTypeCategory = typeName->m_typeInfo->m_typeNode->getTypeCategory();
		if(!((classNode->isValueType() && value_type == baseTypeCategory) 
			|| (!classNode->isValueType() && reference_type == baseTypeCategory)))	
		{
			char buf[512];
			sprintf_s(buf, "\'%s\' : base type must be %s type", typeName->m_scopeList->m_name->m_str.c_str(),
				snt_keyword_struct == classNode->m_keyword->m_nodeType ? "struct" : "class");
			ErrorList_AddItem_CurrentFile(typeName->m_scopeList->m_name->m_lineNo,
				typeName->m_scopeList->m_name->m_columnNo, semantic_error_base_type, buf);
		}
		auto res = items.insert(typeName);
		if(!res.second)
		{
			char buf[512];
			sprintf_s(buf, "\'%s\' : is already a direct base class, the previous declaration is at line %d, column %d", typeName->m_scopeList->m_name->m_str.c_str(),
				(*res.first)->m_scopeList->m_name->m_lineNo, (*res.first)->m_scopeList->m_name->m_columnNo);
			ErrorList_AddItem_CurrentFile(typeName->m_scopeList->m_name->m_lineNo,
				typeName->m_scopeList->m_name->m_columnNo, semantic_error_base_redeclared, buf);
		}
	}
}

struct Overload
{
	IdentifyNode* methodName;
	size_t parameterCount;
	bool operator < (const Overload& arg) const
	{
		int cmp = methodName->m_str.compare(arg.methodName->m_str);
		if(cmp < 0)
		{
			return true;
		}
		else if(cmp > 0)
		{
			return false;
		}
		return parameterCount < arg.parameterCount;
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

bool isCopyConstructor(ClassNode* classNode, MethodNode* methodNode)
{
	if(classNode->m_name->m_str == methodNode->m_name->m_str)
	{
		std::vector<ParameterNode*> parameterNodes;
		methodNode->collectParameterNodes(parameterNodes);
		if(1 == parameterNodes.size())
		{
			ParameterNode* parameterNode = parameterNodes.front();
			if(0 != parameterNode->m_type->m_typeInfo)
			{
				if(classNode == parameterNode->m_type->m_typeInfo->m_typeNode)
				{
					if(0 == parameterNode->m_passing || snt_keyword_ref == parameterNode->m_passing->m_nodeType)
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}

void checkMemberNames(ClassNode* classNode, std::vector<MemberNode*>& memberNodes)
{
	std::set<IdentifyNode*, CompareIdentifyPtr> methodNames;
	std::set<IdentifyNode*, CompareIdentifyPtr> staticMethodNames;
	std::set<IdentifyNode*, CompareIdentifyPtr> otherNames;
	IdentifyNode* copyConstructor = 0;
	std::set<Overload> methods;
	std::set<Overload> staticMethods;

	size_t count = memberNodes.size();
	IdentifyNode* collisionNode = 0;
	for(size_t i = 0; i < count; ++i)
	{
		MemberNode* memberNode = memberNodes[i];
		bool nameCollision = false;
		IdentifyNode* identify = memberNode->m_name;
		if(snt_method == memberNode->m_nodeType)
		{
			MethodNode* methodNode = static_cast<MethodNode*>(memberNode);
			if(methodNode->m_name->m_str == classNode->m_name->m_str)
			{
				if(0 != methodNode->m_result)
				{
					char buf[512];
					sprintf_s(buf, "\'%s\' : constructor with return type", identify->m_str.c_str());
					ErrorList_AddItem_CurrentFile(identify->m_lineNo,
						identify->m_columnNo, semantic_error_constructor_with_return_type, buf);
					continue;
				}
				if(0 != methodNode->m_modifier)
				{
					char buf[512];
					sprintf_s(buf, "\'%s\' : constructor cannot be declared %s", identify->m_str.c_str(), 
						g_keywordTokens[methodNode->m_modifier->m_nodeType - snt_keyword_begin_output - 1]);
					ErrorList_AddItem_CurrentFile(identify->m_lineNo,
						identify->m_columnNo, semantic_error_constructor_with_modifier, buf);
					continue;
				}
			}
			else
			{
				if(0 == methodNode->m_result)
				{
					char buf[512];
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
				if(isCopyConstructor(classNode, methodNode))
				{
					if(0 == copyConstructor)
					{
						copyConstructor = methodNode->m_name;
					}
					else
					{
						collisionNode = copyConstructor;
						nameCollision = true;
					}
				}
				else
				{
					if(methodNode->isStatic())
					{
						it = methodNames.find(identify);
						if(methodNames.end() != it)
						{
							collisionNode = *it;
							nameCollision = true;
						}
					}
					else
					{
						it = staticMethodNames.find(identify);
						if(staticMethodNames.end() != it)
						{
							collisionNode = *it;
							nameCollision = true;
						}
					}
					if(!nameCollision)
					{
						Overload overload;
						overload.methodName = identify;
						overload.parameterCount = methodNode->getParameterCount();
						if(methodNode->isStatic())
						{
							auto res = staticMethods.insert(overload);
							if(!res.second)
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
							if(!res.second)
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
		}
		else
		{
			if(identify->m_str == classNode->m_name->m_str)
			{
				char buf[512];
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
			else if((it = methodNames.find(identify)) != methodNames.end())
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
			char buf[512];
			sprintf_s(buf, "\'%s\' : member already defined at line %d, column %d", identify->m_str.c_str(), 
				collisionNode->m_lineNo, collisionNode->m_columnNo);
			ErrorList_AddItem_CurrentFile(identify->m_lineNo,
				identify->m_columnNo, semantic_error_member_redefined, buf);
		}
	}
}

ClassNode::ClassNode(TokenNode* keyword, IdentifyNode* name, IdentifyNode* category)
{
	assert(snt_keyword_struct == keyword->m_nodeType || snt_keyword_class == keyword->m_nodeType);

	m_nodeType = snt_class;
	m_keyword = keyword;
	m_name = name;
	m_category = category;
	m_modifier = 0;
	m_colon = 0;
	m_baseList = 0;
	m_leftBrace = 0;
	m_memberList = 0;
	m_rightBrace = 0;
	m_semicolon = 0;
	m_templateParameters = 0;
	m_templateArgumentList = 0;
	if(0 == category)
	{
		m_isValueType = (snt_keyword_struct == keyword->m_nodeType);
	}
	else
	{
		m_isValueType = (category->m_str == "value_object");
	}
	m_override = false;
	m_abstractFlag = lb_unknown;
	m_exportFlag = lb_unknown;
}


void ClassNode::setMemberList(TokenNode* leftBrace, MemberListNode* memberList, TokenNode* rightBrace, TokenNode* semicolon)
{
	m_leftBrace = leftBrace;
	m_memberList = memberList;
	m_rightBrace = rightBrace;
	m_semicolon = semicolon;
	m_memberList->initializeMembersEnclosing(this);
}

void ClassNode::checkSemantic()
{
	//if(isInterface() && isTemplateClass())
	//{
	//	RaiseError_TemplateInterfaceNotSupported(m_name);
	//	return;
	//}

	std::vector<std::pair<TokenNode*, TypeNameNode*>> typeNameNodes;
	m_baseList->collectTypeNameNodes(typeNameNodes);

	size_t baseCount = typeNameNodes.size();
	for(size_t i = 0; i < baseCount; ++i)
	{
		typeNameNodes[i].second->checkTypeName(m_enclosing);
		g_sourceFileManager.useType(typeNameNodes[i].second->m_typeInfo, tu_as_base);
	}

	checkBaseNames(this, typeNameNodes);
	if(0 == baseCount)
	{
		if(!isValueType())
		{
			std::string fullName;
			getFullName(fullName, 0);
			if(fullName != "::pafcore::Reference")
			{
				RaiseError_MissingReferenceBaseType(m_name);
			}
		}
	}

	std::vector<MemberNode*> memberNodes;
	m_memberList->collectMemberNodes(memberNodes);

	size_t memberCount = memberNodes.size();
	for(size_t i = 0; i < memberCount; ++i)
	{
		MemberNode* memberNode = memberNodes[i];
		//if(memberNode->m_name)
		//{
		//	if("New" == memberNode->m_name->m_str || "NewArray" == memberNode->m_name->m_str
		//		|| "Clone" == memberNode->m_name->m_str )
		//	{
		//		char buf[512];
		//		sprintf_s(buf, "\'%s\' : member name reserved for create object(s)", memberNode->m_name->m_str.c_str());
		//		ErrorList_AddItem_CurrentFile(memberNode->m_name->m_lineNo,
		//			memberNode->m_name->m_columnNo, semantic_error_member_redefined, buf);
		//	}
		//}
		memberNodes[i]->checkSemantic();
	}
	//内部用到TypeInfo， 需要memberNodes::checkSemantic()才可以
	checkMemberNames(this, memberNodes);
}

void ClassNode::checkSemanticForTemplateInstance(TemplateClassInstanceNode* templateClassInstanceNode, TemplateArgumentMap* templateArguments)
{
	std::vector<TypeNameNode*> typeNameNodes;
	m_baseList->collectTypeNameNodes(typeNameNodes);
	size_t baseCount = typeNameNodes.size();
	for(size_t i = 0; i < baseCount; ++i)
	{
		typeNameNodes[i]->checkTypeNameForTemplateClassInstance(templateClassInstanceNode, templateArguments);
	}

	std::vector<MemberNode*> memberNodes;
	m_memberList->collectMemberNodes(memberNodes);

	size_t memberCount = memberNodes.size();
	for(size_t i = 0; i < memberCount; ++i)
	{
		MemberNode* memberNode = memberNodes[i];
		memberNodes[i]->checkSemanticForTemplateInstance(templateClassInstanceNode, templateArguments);
	}
}

void ClassNode::extendInternalCode()
{
	if(!isAbstractClass())
	{
		//New NewArray Clone
		buildAdditionalMethods();
	}
	std::vector<MemberNode*> memberNodes;
	m_memberList->collectMemberNodes(memberNodes);
	size_t count = memberNodes.size();
	for (size_t i = 0; i < count; ++i)
	{
		MemberNode* memberNode = memberNodes[i];
		switch (memberNode->m_nodeType)
		{
		case snt_class:
			static_cast<ClassNode*>(memberNode)->extendInternalCode();
			break;
		}
	}
}

extern "C" extern int yytokenno;

void ClassNode::GenerateCreateInstanceMethod(const char* methodName, MethodNode* constructor)
{
	IdentifyNode* name = (IdentifyNode*)newIdentify(methodName);
	MethodNode* method = (MethodNode*)newMethod(name, 
		constructor->m_leftParenthesis, constructor->m_parameterList, 
		constructor->m_rightParenthesis, constructor->m_constant, constructor->m_semicolon);
	ScopeListNode* scopeList = (ScopeListNode*)newScopeList(0, m_name);
	TypeNameNode* typeName = (TypeNameNode*)newTypeName(scopeList);
	TokenNode* passing = (TokenNode*)newToken(snt_keyword_new);
	setMethodResult(method, typeName, passing);
	TokenNode* modifier = (TokenNode*)newToken(snt_keyword_static);
	setMethodModifier(method, modifier);
	//method->m_filter = constructor->m_filter;
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
		constructor->m_rightParenthesis, constructor->m_constant, constructor->m_semicolon);
	ScopeListNode* scopeList = (ScopeListNode*)newScopeList(0, m_name);
	TypeNameNode* typeName = (TypeNameNode*)newTypeName(scopeList);
	TokenNode* passing = (TokenNode*)newToken(snt_keyword_new);
	setMethodResult(method, typeName, passing);
	setMethodResultArray(method);
	TokenNode* modifier = (TokenNode*)newToken(snt_keyword_static);
	setMethodModifier(method, modifier);
	//method->m_filter = constructor->m_filter;
	method->m_enclosing = this;
	m_additionalMethods.push_back(method);
}

void ClassNode::buildAdditionalMethods()
{
	int backup = yytokenno;
	yytokenno = 0;
	MethodNode* defaultConstructor = 0;
	MethodNode* copyConstructor = 0;
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
				if(isCopyConstructor(this, methodNode))
				{
					assert(0 == copyConstructor);
					copyConstructor = methodNode;
				}
				else
				{
					constructors.push_back(methodNode);
				}
			}
		}
	}

	size_t count = constructors.size();
	for(size_t i = 0; i < count; ++i)
	{
		MethodNode* constructor = constructors[i];
		GenerateCreateInstanceMethod("New", constructor);
		if(!isValueType())
		{
			GenerateCreateInstanceMethod("NewARC", constructor);
		}
	}
	if(0 != defaultConstructor)
	{
		MethodNode* constructor = defaultConstructor;
		GenerateCreateArrayMethod("NewArray", constructor);
		if(!isValueType())
		{
			GenerateCreateArrayMethod("NewArrayARC", constructor);
		}
	}
	if(0 != copyConstructor)
	{
		MethodNode* constructor = copyConstructor;
		GenerateCreateInstanceMethod("Clone", constructor);
		if(!isValueType())
		{
			GenerateCreateInstanceMethod("CloneARC", constructor);
		}
	}
	yytokenno = backup;

	count = m_additionalMethods.size();
	for(size_t i = 0; i < count; ++i)
	{
		m_additionalMethods[i]->checkSemantic();
	}
}

TypeCategory ClassNode::getTypeCategory()
{
	return m_isValueType ? value_type : reference_type;
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
			else if(snt_property == memberNode->m_nodeType)
			{
				PropertyNode* propertyNode = static_cast<PropertyNode*>(memberNode);
				if(propertyNode->isAbstract())
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

void ClassNode::collectOverrideMethods(std::vector<MethodNode*>& methodNodes)
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
		assert(snt_class == typeNameNode->m_typeInfo->m_typeNode->m_nodeType);
		ClassNode* baseClass = static_cast<ClassNode*>(typeNameNode->m_typeInfo->m_typeNode);
		baseClass->collectOverrideMethods(methodNodes);
	}
}

bool ClassNode::hasExportMethod()
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
		assert(snt_class == typeNameNode->m_typeInfo->m_typeNode->m_nodeType);
		ClassNode* baseClass = static_cast<ClassNode*>(typeNameNode->m_typeInfo->m_typeNode);
		if(baseClass->hasExportMethod())
		{
			return true;
		}
	}
	return false;
}

bool ClassNode::needExport()
{
	if(lb_unknown == m_exportFlag)
	{
		m_exportFlag = lb_false;
		if(m_override)
		{
			if(hasExportMethod())
			{
				m_exportFlag = lb_true;
			}
		}
	}
	return (lb_true == m_exportFlag);
}

void ClassNode::collectTypeInfo()
{
	if(0 != m_templateParameters)
	{
		m_templateParameters->checkSemantic();
	}
	g_sourceFileManager.registerType(this);
	m_memberList->collectTypeInfo();
}

TypeNameListNode* ClassNode::setTemplateArgumentList(TypeNameListNode* templateArgumentList)
{
	TypeNameListNode* old = m_templateArgumentList;
	m_templateArgumentList = templateArgumentList;
	return old;
}


void ClassNode::getTemplateArgumentsName(std::string& relativeName, ScopeNode* scopeNode, TemplateArgumentMap* templateArguments)
{
	relativeName.clear();
	if(0 != m_templateArgumentList)
	{
		assert(0 != m_templateParameters);
		std::vector<TypeNameNode*> parameterNodes;
		m_templateArgumentList->collectTypeNameNodes(parameterNodes);
		relativeName += '<';
		for(size_t i = 0; i < parameterNodes.size(); ++i)
		{
			if(0 != i)
			{
				relativeName += ',';
			}
			std::string paramTypeName;
			TypeNameNode* paramNode = parameterNodes[i];
			paramNode->getRelativeName(paramTypeName, scopeNode, templateArguments);
			relativeName += paramTypeName;
		}
		relativeName += '>';
	}
}

void ClassNode::getRelativeName(std::string& relativeName, ScopeNode* scopeNode, TemplateArgumentMap* templateArguments)
{
	ScopeNode::getRelativeName(relativeName, scopeNode, templateArguments);
	std::string templateParametersName;
	getTemplateArgumentsName(templateParametersName, scopeNode, templateArguments);
	relativeName += templateParametersName;
}

