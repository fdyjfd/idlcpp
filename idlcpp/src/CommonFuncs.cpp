#pragma once
#include "CommonFuncs.h"
#include "IdentifyNode.h"
#include "MemberNode.h"
#include "MemberListNode.h"
#include "TypeNameNode.h"
#include "ClassNode.h"
#include "TemplateParameterNode.h"
#include "TemplateParametersNode.h"
#include "TemplateClassInstanceNode.h"

#include "SourceFile.h"
#include "Options.h"
#include <algorithm>
#include <assert.h>

void GetMetaTypeFullName(std::string& metaTypeName, MemberNode* typeNode)
{
	std::string typeName;
	typeNode->getFullName(typeName, 0);
	std::replace_if(typeName.begin(), typeName.end(), isNotIdentifyChar, '_');
	metaTypeName = typeName + g_options.m_metaTypePostfix;
}

void GetSubclassProxyFullName(std::string& interfaceImplementorName, MemberNode* typeNode)
{
	std::string typeName;
	typeNode->getFullName(typeName, 0);
	std::replace_if(typeName.begin(), typeName.end(), isNotIdentifyChar, '_');
	interfaceImplementorName = typeName + g_options.m_interfaceImplementorPostfix;
}

TypeCategory CalcTypeFullName(std::string& typeName, TypeNameNode* typeNameNode, TemplateArgumentMap* templateArguments)
{
	TypeCategory typeCategory = typeNameNode->getFullName(typeName, templateArguments);
	if(class_template == typeCategory)
	{
		assert(0 != templateArguments);
		assert(typeNameNode->m_typeInfo->m_typeNode->isTemplateClass());
		ClassNode* classNode = static_cast<ClassNode*>(typeNameNode->m_typeInfo->m_typeNode);
		
		std::vector<TemplateParameterNode*> templateParameters;
		classNode->m_templateParameters->collectParameterNodes(templateParameters);
		size_t count = templateParameters.size();
		typeName += '<';
		for(size_t i = 0; i < count; ++i)
		{
			if(0 != i)
			{
				typeName += ',';
			}
			TemplateParameterNode* parameter = templateParameters[i];
			auto it = templateArguments->find(parameter->m_name->m_str);
			assert(it != templateArguments->end());
			TypeNameNode* argument = it->second;
			std::string argumentName;
			CalcTypeFullName(argumentName, argument, templateArguments);
			typeName += argumentName;
		}
		typeName += '>';
		typeCategory = classNode->isValueType() ? value_type : reference_type;
	}
	return typeCategory;
}

void CollectExportedTypeInfos(std::vector<ExportedTypeInfo>& typeInfos, MemberNode* memberNode)
{
	std::string typeName;
	switch(memberNode->m_nodeType)
	{
	case snt_enum:
		memberNode->getFullName(typeName, 0);
		typeInfos.push_back(ExportedTypeInfo(memberNode,typeName));
		break;
	case snt_type_alias:
		memberNode->getFullName(typeName, 0);
		typeInfos.push_back(ExportedTypeInfo(memberNode,typeName));
		break;
	case snt_class:
		if(!memberNode->isTemplateClass() || 0 != static_cast<ClassNode*>(memberNode)->m_templateArgumentList)
		{
			memberNode->getFullName(typeName, 0);
			typeInfos.push_back(ExportedTypeInfo(memberNode,typeName));
		}
		break;
	case snt_template_class_instance:
		{
			TemplateClassInstanceNode* templateClassInstance = static_cast<TemplateClassInstanceNode*>(memberNode);
			ClassNode* classNode = static_cast<ClassNode*>(templateClassInstance->m_templateTypeNameNode->m_typeInfo->m_typeNode);
			assert(0 != classNode->m_templateParameters);
			assert(classNode->m_templateParameters->getParameterCount() == templateClassInstance->getParameterCount());
			TypeNameListNode* oldTemplateArgumentList = classNode->setTemplateArgumentList(templateClassInstance->m_parameterList);
			CollectExportedTypeInfos(typeInfos, classNode);
			classNode->setTemplateArgumentList(oldTemplateArgumentList);
		}
		break;
	}
	MemberListNode* list = 0;
	switch(memberNode->m_nodeType)
	{
		case snt_namespace:
			list = static_cast<ScopeNode*>(memberNode)->m_memberList;
			break;
		case snt_class:
			if(!memberNode->isTemplateClass() || 0 != static_cast<ClassNode*>(memberNode)->m_templateArgumentList)
			{
				list = static_cast<ScopeNode*>(memberNode)->m_memberList;
			}
			break;
	}
	while(0 != list)
	{
		CollectExportedTypeInfos(typeInfos, list->m_member);
		list = list->m_memberList;
	}
}


//
//void CollectExportTypeNames(std::vector<std::string>& typeNames, MemberListNode* list)
//{
//	while(0 != list)
//	{
//		std::string typeName;
//		MemberNode* memberNode = list->m_member;
//		switch(memberNode->m_nodeType)
//		{
//		case snt_namespace:
//		case snt_class:
//			CollectExportTypeNames(typeNames, static_cast<ScopeNode*>(memberNode)->m_memberList);
//			break;
//		}
//		switch(memberNode->m_nodeType)
//		{
//		case snt_enum:
//		case snt_type_alias:
//			memberNode->getFullName(typeName, 0);
//			typeNames.push_back(typeName);
//			break;
//		case snt_template_class_instance:
//			{
//				TemplateClassInstanceNode* templateClassInstance = static_cast<TemplateClassInstanceNode*>(memberNode);
//				ClassNode* classNode = static_cast<ClassNode*>(templateClassInstance->m_templateTypeNameNode->m_typeInfo->m_typeNode);
//				assert(0 != classNode->m_templateParameters);
//				assert(classNode->m_templateParameters->getParameterCount() == templateClassInstance->getParameterCount());
//				TypeNameListNode* oldTemplateArgumentList = classNode->setTemplateArgumentList(templateClassInstance->m_parameterList);
//				classNode->getFullName(typeName, 0);
//				typeNames.push_back(typeName);
//				CollectExportTypeNames(typeNames, classNode->m_memberList);
//				classNode->setTemplateArgumentList(oldTemplateArgumentList);
//			}
//			break;
//		case snt_class:
//			if(!memberNode->isTemplateClass())
//			{
//				memberNode->getFullName(typeName, 0);
//				typeNames.push_back(typeName);
//			}
//			break;
//		}
//		list = list->m_memberList;
//	}
//}
