#pragma once
#include "CommonFuncs.h"
#include "IdentifyNode.h"
#include "MemberNode.h"
#include "MemberListNode.h"
#include "TypeNameNode.h"
#include "ClassNode.h"
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

void GetSubclassProxyFullName(std::string& subclassProxyName, MemberNode* typeNode)
{
	std::string typeName;
	typeNode->getFullName(typeName, 0);
	std::replace_if(typeName.begin(), typeName.end(), isNotIdentifyChar, '_');
	subclassProxyName = typeName + g_options.m_subclassProxyPostfix;
}

TypeCategory CalcTypeFullName(std::string& typeName, TypeNameNode* typeNameNode, TemplateArgumentMap* templateArguments)
{
	TypeCategory typeCategory = typeNameNode->getFullName(typeName, templateArguments);
	if(class_template == typeCategory)
	{
		assert(0 != templateArguments);
		assert(typeNameNode->m_typeInfo->m_typeNode->isTemplateClass());
		ClassNode* classNode = static_cast<ClassNode*>(typeNameNode->m_typeInfo->m_typeNode);
		
		std::vector<IdentifyNode*> templateParameters;
		classNode->m_templateParameters->collectParameterNodes(templateParameters);
		size_t count = templateParameters.size();
		typeName += '<';
		for(size_t i = 0; i < count; ++i)
		{
			if(0 != i)
			{
				typeName += ',';
			}
			IdentifyNode* parameter = templateParameters[i];
			auto it = templateArguments->find(parameter->m_str);
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
