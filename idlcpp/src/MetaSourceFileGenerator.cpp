#include "MetaSourceFileGenerator.h"
#include "SourceFile.h"
#include "ProgramNode.h"
#include "NamespaceNode.h"
#include "TokenNode.h"
#include "IdentifyNode.h"
#include "EnumeratorListNode.h"
#include "EnumNode.h"
#include "ClassNode.h"
#include "TemplateParametersNode.h"
#include "TemplateClassInstanceNode.h"
#include "TypeAliasNode.h"
#include "TypeNameListNode.h"
#include "TypeNameNode.h"
#include "MemberListNode.h"
#include "FieldNode.h"
#include "GetterSetterNode.h"
#include "PropertyNode.h"
#include "MethodNode.h"
#include "ParameterNode.h"
#include "ParameterNode.h"
#include "Platform.h"
#include "CommonFuncs.h"
#include "Options.h"
#include <assert.h>
#include <algorithm>
#include <vector>
#include <string>

const char* s_variantSemantic_ByValue = "::pafcore::Variant::by_value";
const char* s_variantSemantic_ByRef = "::pafcore::Variant::by_ref";
const char* s_variantSemantic_ByPtr = "::pafcore::Variant::by_ptr";
const char* s_variantSemantic_ByArray = "::pafcore::Variant::by_array";
const char* s_variantSemantic_ByNewPtr = "::pafcore::Variant::by_new_ptr";
const char* s_variantSemantic_ByNewArray = "::pafcore::Variant::by_new_array";

void writeMetaConstructor(ClassNode* classNode, 
	TemplateArgumentMap* templateArguments,
	std::vector<MemberNode*>& nestedTypeNodes,
	std::vector<TypeAliasNode*>& nestedTypeAliasNodes,
	std::vector<FieldNode*>& staticFieldNodes,
	std::vector<PropertyNode*>& staticPropertyNodes,
	std::vector<MethodNode*>& staticMethodNodes,
	std::vector<FieldNode*>& fieldNodes,
	std::vector<PropertyNode*>& propertyNodes,
	std::vector<MethodNode*>& methodNodes,
	FILE* file, int indentation);

void writeMetaPropertyImpls(ClassNode* classNode, TemplateArgumentMap* templateArguments, std::vector<PropertyNode*>& propertyNodes, FILE* file, int indentation);
void writeMetaMethodImpls(ClassNode* classNode, TemplateArgumentMap* templateArguments, std::vector<MethodNode*>& methodNodes, FILE* file, int indentation);
void writeMetaGetSingletonImpls(MemberNode* typeNode, FILE* file, int indentation);
void writeEnumMetaConstructor(EnumNode* enumNode, std::vector<IdentifyNode*>& enumerators, FILE* file, int indentation);
void writeInterfaceImplementedByScript(FILE* file, ClassNode* classNode, int indentation);


void MetaSourceFileGenerator::generateCode(FILE* dstFile, SourceFile* sourceFile, const char* fullPathName, const char* baseName)
{
	generateCode_Program(dstFile, sourceFile, fullPathName, baseName);
}

void MetaSourceFileGenerator::generateCode_Program(FILE* file, SourceFile* sourceFile, const char* fileName, const char* cppName)
{
	ProgramNode* programNode = sourceFile->m_syntaxTree;
	char buf[512];
	std::string pafcorePath;
	GetRelativePath(pafcorePath, fileName, g_options.m_pafcorePath.c_str());
	FormatPathForInclude(pafcorePath);

	writeStringToFile("#pragma once\n\n", file);
	g_sourceFileManager.outputUsedTypesForMetaSource(file, sourceFile);
	sprintf_s(buf, "#include \"%s%s\"\n", cppName, g_options.m_metaHeaderFilePostfix.c_str());
	writeStringToFile(buf, file);
	sprintf_s(buf, "#include \"%sAutoRun.h\"\n", pafcorePath.c_str());
	writeStringToFile(buf, file);
	sprintf_s(buf, "#include \"%sNameSpace.h\"\n", pafcorePath.c_str());
	writeStringToFile(buf, file);
	sprintf_s(buf, "#include \"%sResult.h\"\n", pafcorePath.c_str());
	writeStringToFile(buf, file);
	sprintf_s(buf, "#include \"%sArgument.h\"\n", pafcorePath.c_str());
	writeStringToFile(buf, file);
	sprintf_s(buf, "#include \"%sInstanceField.h\"\n", pafcorePath.c_str());
	writeStringToFile(buf, file);
	sprintf_s(buf, "#include \"%sStaticField.h\"\n", pafcorePath.c_str());
	writeStringToFile(buf, file);
	sprintf_s(buf, "#include \"%sInstanceProperty.h\"\n", pafcorePath.c_str());
	writeStringToFile(buf, file);
	sprintf_s(buf, "#include \"%sStaticProperty.h\"\n", pafcorePath.c_str());
	writeStringToFile(buf, file);
	sprintf_s(buf, "#include \"%sInstanceMethod.h\"\n", pafcorePath.c_str());
	writeStringToFile(buf, file);
	sprintf_s(buf, "#include \"%sStaticMethod.h\"\n", pafcorePath.c_str());
	writeStringToFile(buf, file);
	sprintf_s(buf, "#include \"%sEnumerator.h\"\n", pafcorePath.c_str());
	writeStringToFile(buf, file);
	sprintf_s(buf, "#include \"%sPrimitiveType.h\"\n", pafcorePath.c_str());
	writeStringToFile(buf, file);
	sprintf_s(buf, "#include \"%sVoidType.h\"\n", pafcorePath.c_str());
	writeStringToFile(buf, file);
	writeStringToFile("\n", file);

	writeStringToFile("\nnamespace idlcpp\n{\n\n", file);
	generateCode_Namespace(file, programNode, 1);
	writeStringToFile("}\n\n", file);

	std::vector<ExportedTypeInfo> typeInfos;
	CollectExportedTypeInfos(typeInfos, programNode);
	std::reverse(typeInfos.begin(), typeInfos.end());
	size_t typeCount = typeInfos.size();
	for (size_t i = 0; i < typeCount; ++i)
	{
		if (typeInfos[i].m_typeNode->canGenerateMetaCode())
		{
			std::string metaTypeName = typeInfos[i].m_typeName;
			std::replace_if(metaTypeName.begin(), metaTypeName.end(), isNotIdentifyChar, '_');
			metaTypeName += g_options.m_metaTypePostfix;
			sprintf_s(buf, "AUTO_REGISTER_TYPE(::idlcpp::%s)\n", metaTypeName.c_str());
			writeStringToFile(buf, file);
			if (snt_type_alias == typeInfos[i].m_typeNode->m_nodeType)
			{
				TypeAliasNode* typeAliasNode = static_cast<TypeAliasNode*>(typeInfos[i].m_typeNode);
				if (0 == typeAliasNode->m_typeName)
				{
					TypeCategory typeCategory = typeInfos[i].m_typeNode->getTypeCategory();
					const char* typeCategoryName = "";
					switch (typeCategory)
					{
					case void_type:
						typeCategoryName = "void_object";
						break;
					case primitive_type:
						typeCategoryName = "primitive_object";
						break;
					case enum_type:
						typeCategoryName = "enum_object";
						break;
					case value_type:
						typeCategoryName = "value_object";
						break;
					case reference_type:
						typeCategoryName = "reference_object";
						break;
					default:
						assert(false);
					}
					sprintf_s(buf, "static_assert(RuntimeTypeOf<%s>::type_category == ::pafcore::%s, \"type category error\");\n",
						typeInfos[i].m_typeName.c_str(), typeCategoryName);
					writeStringToFile(buf, file);
				}
			}
		}
	}
}

void MetaSourceFileGenerator::generateCode_Namespace(FILE* file, NamespaceNode* namespaceNode, int indentation)
{
	if (namespaceNode->isNativeOnly())
	{
		return;
	}

	std::vector<MemberNode*> memberNodes;
	namespaceNode->m_memberList->collectMemberNodes(memberNodes);
	size_t count = memberNodes.size();
	for(size_t i = 0; i < count; ++i)
	{
		MemberNode* memberNode = memberNodes[i];
		switch (memberNode->m_nodeType)
		{
		case snt_enum:
			generateCode_Enum(file, static_cast<EnumNode*>(memberNode), indentation);
			break;
		case snt_class:
			generateCode_Class(file, static_cast<ClassNode*>(memberNode), 0, indentation);
			break;
		case snt_namespace:
			generateCode_Namespace(file, static_cast<NamespaceNode*>(memberNode), indentation);
			break;
		case snt_type_alias:
			generateCode_TypeAlias(file, static_cast<TypeAliasNode*>(memberNode), indentation);
			break;
		case snt_template_class_instance:
			generateCode_TemplateClassInstance(file, static_cast<TemplateClassInstanceNode*>(memberNode), indentation);
			break;
		default:
			assert(false);
		}
	}
}

void MetaSourceFileGenerator::generateCode_Enum(FILE* file, EnumNode* enumNode, int indentation)
{
	if (enumNode->isNativeOnly())
	{
		return;
	}
	std::vector<IdentifyNode*> identifyNodes;
	enumNode->m_enumeratorList->collectIdentifyNodes(identifyNodes);
	std::sort(identifyNodes.begin(), identifyNodes.end(), CompareIdentifyPtr());
	writeEnumMetaConstructor(enumNode, identifyNodes, file, indentation);
	writeMetaGetSingletonImpls(enumNode, file, indentation);
}

void MetaSourceFileGenerator::generateCode_TemplateClassInstance(FILE* file, TemplateClassInstanceNode* templateClassInstance, int indentation)
{
	if (templateClassInstance->isNativeOnly())
	{
		return;
	}

	assert(0 != templateClassInstance->m_templateTypeNameNode->m_typeInfo
			&& snt_class == templateClassInstance->m_templateTypeNameNode->m_typeInfo->m_typeNode->m_nodeType);
	ClassNode* classNode = static_cast<ClassNode*>(templateClassInstance->m_templateTypeNameNode->m_typeInfo->m_typeNode);
	assert(0 != classNode->m_templateParameters);
	assert(classNode->m_templateParameters->getParameterCount() == templateClassInstance->getParameterCount());

	std::vector<IdentifyNode*> templateParameters;
	classNode->m_templateParameters->collectParameterNodes(templateParameters);

	std::vector<TypeNameNode*> templateArguments;
	templateClassInstance->m_parameterList->collectTypeNameNodes(templateArguments);
	assert(templateParameters.size() == templateArguments.size());
	size_t count = templateParameters.size();

	TemplateArgumentMap templateArgumentMap;

	for(size_t i = 0; i < count; ++i)
	{
		IdentifyNode* parameter = templateParameters[i];
		TypeNameNode* argument = templateArguments[i];
		templateArgumentMap.insert(make_pair(parameter->m_str, argument));
	}

	TypeNameListNode* oldTemplateArgumentList = classNode->setTemplateArgumentList(templateClassInstance->m_parameterList);
	generateCode_Class(file, classNode, &templateArgumentMap, indentation);
	classNode->setTemplateArgumentList(oldTemplateArgumentList);
}

void writeOverrideFunction(ClassNode* classNode, TemplateArgumentMap* templateArguments, bool hasDelete, bool hasDeleteArray, FILE* file, int indentation)
{
	char buf[512];
	std::string metaClassName;
	GetMetaTypeFullName(metaClassName, classNode);
	//if(!classNode->isAbstractClass())
	{
		std::string className;
		classNode->getFullName(className, templateArguments);

		sprintf_s(buf, "void %s::destroyInstance(void* address)\n", metaClassName.c_str());
		writeStringToFile(buf, file, indentation);
		writeStringToFile("{\n", file, indentation);
		if (hasDelete)
		{
			sprintf_s(buf, "%s::Delete(reinterpret_cast<%s*>(address));\n", className.c_str(), className.c_str());
		}
		else
		{
			if (classNode->isValueType())
			{
				sprintf_s(buf, "delete reinterpret_cast<%s*>(address);\n", className.c_str());
			}
			else
			{
				sprintf_s(buf, "reinterpret_cast<::pafcore::Reference*>(address)->release();\n");
			}
		}
		writeStringToFile(buf, file, indentation + 1);
		writeStringToFile("}\n\n", file, indentation);

		sprintf_s(buf, "void %s::destroyArray(void* address)\n", metaClassName.c_str());
		writeStringToFile(buf, file, indentation);
		writeStringToFile("{\n", file, indentation);
		if (hasDeleteArray)
		{
			sprintf_s(buf, "%s::DeleteArray(reinterpret_cast<%s*>(address));\n", className.c_str(), className.c_str());
		}
		else
		{
			if (classNode->isValueType())
			{
				sprintf_s(buf, "delete_array(reinterpret_cast<%s*>(address));\n", className.c_str());
			}
			else
			{
				sprintf_s(buf, "delete_array(reinterpret_cast<::pafcore::RefCountObject<%s>*>(address));\n", className.c_str());
			}
		}
		writeStringToFile(buf, file, indentation + 1);
		writeStringToFile("}\n\n", file, indentation);

		sprintf_s(buf, "void %s::assign(void* dst, const void* src)\n", metaClassName.c_str());
		writeStringToFile(buf, file, indentation);
		writeStringToFile("{\n", file, indentation);
		sprintf_s(buf, "*(%s*)dst = *(const %s*)src;\n", className.c_str(), className.c_str());
		writeStringToFile(buf, file, indentation + 1);
		writeStringToFile("}\n\n", file, indentation);

	}
	if(classNode->needExport())
	{
		std::string subclassProxyName;
		GetSubclassProxyFullName(subclassProxyName, classNode);
		sprintf_s(buf, "void* %s::createSubclassProxy(::pafcore::SubclassInvoker* subclassInvoker)\n", metaClassName.c_str());
		writeStringToFile(buf, file, indentation);
		writeStringToFile("{\n", file, indentation);
		if(classNode->isValueType())
		{
			sprintf_s(buf, "return new %s(subclassInvoker);\n", subclassProxyName.c_str());
		}
		else
		{
			sprintf_s(buf, "return new ::pafcore::RefCountObject<%s>(subclassInvoker);\n", subclassProxyName.c_str());
		}
		writeStringToFile(buf, file, indentation + 1);
		writeStringToFile("}\n\n", file, indentation);
	
		sprintf_s(buf, "void %s::destroySubclassProxy(void* subclassProxy)\n", metaClassName.c_str());
		writeStringToFile(buf, file, indentation);
		writeStringToFile("{\n", file, indentation);
		if(classNode->isValueType())
		{
			sprintf_s(buf, "delete reinterpret_cast<%s*>(subclassProxy);\n", subclassProxyName.c_str());
		}
		else
		{
			sprintf_s(buf, "delete reinterpret_cast<::pafcore::RefCountObject<%s>*>(subclassProxy);\n", subclassProxyName.c_str());
		}
		writeStringToFile(buf, file, indentation + 1);
		writeStringToFile("}\n\n", file, indentation);
	}
}

void MetaSourceFileGenerator::generateCode_Class(FILE* file, ClassNode* classNode, TemplateArgumentMap* templateArguments, int indentation)
{
	if (classNode->isNativeOnly())
	{
		return;
	}
	if(0 != classNode->m_templateParameters && 0 == classNode->m_templateArgumentList)
	{
		return;
	}
	std::vector<MemberNode*> memberNodes;
	std::vector<MethodNode*> methodNodes;
	std::vector<MethodNode*> staticMethodNodes;
	std::vector<PropertyNode*> propertyNodes;
	std::vector<PropertyNode*> staticPropertyNodes;
	std::vector<FieldNode*> fieldNodes;
	std::vector<FieldNode*> staticFieldNodes;
	std::vector<MemberNode*> nestedTypeNodes;
	std::vector<TypeAliasNode*> nestedTypeAliasNodes;

	classNode->m_memberList->collectMemberNodes(memberNodes);
	size_t memberCount = memberNodes.size();
	for(size_t i = 0; i < memberCount; ++i)
	{
		MemberNode* memberNode = memberNodes[i];
		if(!memberNode->isNativeOnly())
		{
			if(snt_method == memberNode->m_nodeType)
			{
				MethodNode* methodNode = static_cast<MethodNode*>(memberNode);
				if(memberNode->m_name->m_str != classNode->m_name->m_str)
				{
					if(methodNode->isStatic())
					{
						staticMethodNodes.push_back(methodNode);
					}
					else
					{
						methodNodes.push_back(methodNode);
					}
				}
			}
			else if(snt_property == memberNode->m_nodeType)
			{
				PropertyNode* propertyNode = static_cast<PropertyNode*>(memberNode);
				if(propertyNode->isStatic())
				{
					staticPropertyNodes.push_back(propertyNode);
				}
				else
				{
					propertyNodes.push_back(propertyNode);
				}
			}
			else if(snt_field == memberNode->m_nodeType)
			{
				FieldNode* fieldNode = static_cast<FieldNode*>(memberNode);
				if(fieldNode->isStatic())
				{
					staticFieldNodes.push_back(fieldNode);
				}
				else
				{
					fieldNodes.push_back(fieldNode);
				}
			}
			else if(snt_enum == memberNode->m_nodeType ||
				snt_class == memberNode->m_nodeType)
			{
				nestedTypeNodes.push_back(memberNode);
			}
			else if (snt_type_alias == memberNode->m_nodeType)
			{
				TypeAliasNode* typeAliasNode = static_cast<TypeAliasNode*>(memberNode);
				nestedTypeAliasNodes.push_back(typeAliasNode);
			}
		}
	}

	if(!classNode->isAbstractClass())
	{
		auto it = classNode->m_additionalMethods.begin();
		auto end = classNode->m_additionalMethods.end();
		for (; it != end; ++it)
		{
			MethodNode* methodNode = *it;
			if (!methodNode->isNativeOnly())
			{
				staticMethodNodes.push_back(methodNode);
			}
		}
	}

	std::sort(nestedTypeNodes.begin(), nestedTypeNodes.end(), CompareMemberNodeByName());
	std::sort(nestedTypeAliasNodes.begin(), nestedTypeAliasNodes.end(), CompareMemberNodeByName());
	std::sort(fieldNodes.begin(), fieldNodes.end(), CompareMemberNodeByName());
	std::sort(propertyNodes.begin(), propertyNodes.end(), CompareMemberNodeByName());
	std::sort(methodNodes.begin(), methodNodes.end(), CompareMemberNodeByName());
	std::sort(staticFieldNodes.begin(), staticFieldNodes.end(), CompareMemberNodeByName());
	std::sort(staticPropertyNodes.begin(), staticPropertyNodes.end(), CompareMemberNodeByName());
	std::sort(staticMethodNodes.begin(), staticMethodNodes.end(), CompareMemberNodeByName());

	bool hasDelete, hasDeleteArray;
	{
		IdentifyNode tmpIdentifyNode("Delete", 0, 0, 0);
		MethodNode tmpMethodNode(&tmpIdentifyNode, 0,0,0,0,0);
		hasDelete = std::binary_search(staticMethodNodes.begin(), staticMethodNodes.end(), &tmpMethodNode, CompareMemberNodeByName());
		tmpIdentifyNode.m_str = "DeleteArray";
		hasDeleteArray = std::binary_search(staticMethodNodes.begin(), staticMethodNodes.end(), &tmpMethodNode, CompareMemberNodeByName());
	}

	writeMetaConstructor(classNode, templateArguments, nestedTypeNodes, nestedTypeAliasNodes,
		staticFieldNodes, staticPropertyNodes, staticMethodNodes, 
		fieldNodes, propertyNodes, methodNodes, file, indentation);

	writeOverrideFunction(classNode, templateArguments, hasDelete, hasDeleteArray, file, indentation);
	writeMetaPropertyImpls(classNode, templateArguments, propertyNodes, file, indentation);
	writeMetaPropertyImpls(classNode, templateArguments, staticPropertyNodes, file, indentation);
	writeMetaMethodImpls(classNode, templateArguments, methodNodes, file, indentation);
	writeMetaMethodImpls(classNode, templateArguments, staticMethodNodes, file, indentation);
	writeMetaGetSingletonImpls(classNode, file, indentation);

	if(classNode->needExport())
	{
		generateCode_Interface(file, classNode, templateArguments, indentation);
	}

	size_t subTypeCount = nestedTypeNodes.size();
	for(size_t i = 0; i < subTypeCount; ++i)
	{
		MemberNode* typeNode = nestedTypeNodes[i];
		switch (typeNode->m_nodeType)
		{
		case snt_enum:
			generateCode_Enum(file, static_cast<EnumNode*>(typeNode), indentation);
			break;
		case snt_class:
			generateCode_Class(file, static_cast<ClassNode*>(typeNode), templateArguments, indentation);
			break;
		default:
			assert(false);
		}
	}

	size_t typeAliasCount = nestedTypeAliasNodes.size();
	for (size_t i = 0; i < typeAliasCount; ++i)
	{
		TypeAliasNode* typeAliasNode = nestedTypeAliasNodes[i];
		generateCode_TypeAlias(file, typeAliasNode, indentation);
	}

}

const char g_metaPropertyImplPrefix[] = "::pafcore::ErrorCode ";
const char g_metaPropertyImplPostfix[] = "(::pafcore::Variant* that, ::pafcore::Variant* value)\n";
const char g_metaStaticPropertyImplPostfix[] = "(::pafcore::Variant* value)\n";

void writeMetaGetPropertyImpl(ClassNode* classNode, TemplateArgumentMap* templateArguments, PropertyNode* propertyNode, FILE* file, int indentation)
{
	char buf[512];
	std::string typeName;
	std::string className;
	std::string metaClassName;

	classNode->getFullName(className, templateArguments);
	GetMetaTypeFullName(metaClassName, classNode);

	writeStringToFile(g_metaPropertyImplPrefix, sizeof(g_metaPropertyImplPrefix) - 1, file, indentation);
	sprintf_s(buf, "%s::%s_get_%s", metaClassName.c_str(),
		classNode->m_name->m_str.c_str(), propertyNode->m_name->m_str.c_str());
	writeStringToFile(buf, file);
	if(propertyNode->isStatic())
	{
		writeStringToFile(g_metaStaticPropertyImplPostfix, sizeof(g_metaStaticPropertyImplPostfix) - 1, file);		
	}
	else
	{
		writeStringToFile(g_metaPropertyImplPostfix, sizeof(g_metaPropertyImplPostfix) - 1, file);	
	}
	writeStringToFile("{\n", file, indentation);
	TypeCategory typeCategory = CalcTypeFullName(typeName, propertyNode->m_type, templateArguments);

	if(propertyNode->isStatic())
	{
		if(0 == propertyNode->m_get->m_passing)
		{
			if(primitive_type == typeCategory || enum_type == typeCategory)
			{
				sprintf_s(buf, "%s res = %s::get_%s();\n", typeName.c_str(), className.c_str(), propertyNode->m_name->m_str.c_str());
			}
			else
			{
				sprintf_s(buf, "%s* res = new %s(%s::get_%s());\n", typeName.c_str(), typeName.c_str(), className.c_str(), propertyNode->m_name->m_str.c_str());
			}
		}
		else if(snt_keyword_ptr == propertyNode->m_get->m_passing->m_nodeType)
		{
			sprintf_s(buf, "%s%s* res = %s::get_%s();\n", propertyNode->m_get->isConstant() ? "const " : "",
				typeName.c_str(), className.c_str(), propertyNode->m_name->m_str.c_str());
		}
		else
		{
			assert(snt_keyword_ref == propertyNode->m_get->m_passing->m_nodeType);
			sprintf_s(buf, "%s%s* res = &%s::get_%s();\n",  propertyNode->m_get->isConstant() ? "const " : "",
				typeName.c_str(), className.c_str(), propertyNode->m_name->m_str.c_str());
		}
		writeStringToFile(buf, file, indentation + 1);
	}
	else
	{
		sprintf_s(buf, "%s* self;\n", className.c_str());
		writeStringToFile(buf, file, indentation + 1);
		if(classNode->isValueType())
		{
			writeStringToFile("if(!that->castToValuePtr(GetSingleton(), (void**)&self))\n", file, indentation + 1);
		}
		else 
		{
			writeStringToFile("if(!that->castToReferencePtr(GetSingleton(), (void**)&self))\n", file, indentation + 1);
		}
		writeStringToFile("{\n", file, indentation + 1);
		writeStringToFile("return ::pafcore::e_invalid_this_type;\n", file, indentation + 2);
		writeStringToFile("}\n", file, indentation + 1);
		if(0 == propertyNode->m_get->m_passing)
		{
			if(primitive_type == typeCategory || enum_type == typeCategory)
			{
				sprintf_s(buf, "%s res = self->get_%s();\n", typeName.c_str(), propertyNode->m_name->m_str.c_str());
			}
			else
			{
				sprintf_s(buf, "%s* res = new %s(self->get_%s());\n", typeName.c_str(), typeName.c_str(), propertyNode->m_name->m_str.c_str());
			}
		}
		else if(snt_keyword_ptr == propertyNode->m_get->m_passing->m_nodeType)
		{
			sprintf_s(buf, "%s%s* res = self->get_%s();\n", propertyNode->m_get->isConstant() ? "const " : "",
				typeName.c_str(), propertyNode->m_name->m_str.c_str());
		}
		else
		{
			assert(snt_keyword_ref == propertyNode->m_get->m_passing->m_nodeType);
			sprintf_s(buf, "%s%s* res = &self->get_%s();\n",  propertyNode->m_get->isConstant() ? "const " : "",
				typeName.c_str(), propertyNode->m_name->m_str.c_str());
		}
		writeStringToFile(buf, file, indentation + 1);
	}

	const char* varSemantic;
	if(propertyNode->m_get->byPtr())
	{
		varSemantic = s_variantSemantic_ByPtr;
	}
	else if(propertyNode->m_get->byRef())
	{
		varSemantic = s_variantSemantic_ByRef;
	}
	else
	{
		assert(propertyNode->m_get->byValue());
		varSemantic = s_variantSemantic_ByValue;
	}

	if(0 == propertyNode->m_get->m_passing)
	{
		switch(typeCategory)
		{
		//case void_type: impossible
		case primitive_type:
			sprintf_s(buf, "value->assignPrimitive(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), &res);\n", typeName.c_str());
			break;
		case enum_type:
			sprintf_s(buf, "value->assignEnum(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), &res);\n", typeName.c_str());
			break;
		case value_type:
			sprintf_s(buf, "value->assignValuePtr(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), res, false, %s);\n", typeName.c_str(), varSemantic);
			break;
		case reference_type:
			sprintf_s(buf, "value->assignReferencePtr(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), res, false, %s);\n", typeName.c_str(), varSemantic);
			break;
		default:
			assert(false);
		}
	}
	else
	{
		switch(typeCategory)
		{
		case void_type:
			sprintf_s(buf, "value->assignVoidPtr(res, %s);\n", propertyNode->m_get->isConstant() ? "true" : "false");
			break;
		case primitive_type:
			sprintf_s(buf, "value->assignPrimitivePtr(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), res, %s, %s);\n",
				typeName.c_str(), propertyNode->m_get->isConstant() ? "true" : "false", varSemantic);
			break;
		case enum_type:
			sprintf_s(buf, "value->assignEnumPtr(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), res, %s, %s);\n", 
				typeName.c_str(), propertyNode->m_get->isConstant() ? "true" : "false", varSemantic);
			break;
		case value_type:
			sprintf_s(buf, "value->assignValuePtr(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), res, %s, %s);\n",
				typeName.c_str(), propertyNode->m_get->isConstant() ? "true" : "false", varSemantic);
			break;
		case reference_type:
			sprintf_s(buf, "value->assignReferencePtr(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), res, %s, %s);\n",
				typeName.c_str(), propertyNode->m_get->isConstant() ? "true" : "false", varSemantic);
			break;
		default:
			assert(false);
		}
	}
	writeStringToFile(buf, file, indentation + 1);
	writeStringToFile("return ::pafcore::s_ok;\n", file, indentation + 1);	
	writeStringToFile("}\n\n", file, indentation);
}

void writeMetaSetPropertyImpl(ClassNode* classNode, TemplateArgumentMap* templateArguments, PropertyNode* propertyNode, FILE* file, int indentation)
{
	char buf[512];
	std::string typeName;
	std::string className;
	std::string metaClassName;
	
	classNode->getFullName(className, templateArguments);
	GetMetaTypeFullName(metaClassName, classNode);

	writeStringToFile(g_metaPropertyImplPrefix, sizeof(g_metaPropertyImplPrefix) - 1, file, indentation);
	sprintf_s(buf, "%s::%s_set_%s", metaClassName.c_str(),
		classNode->m_name->m_str.c_str(), propertyNode->m_name->m_str.c_str());
	writeStringToFile(buf, file);
	if(propertyNode->isStatic())
	{
		writeStringToFile(g_metaStaticPropertyImplPostfix, sizeof(g_metaStaticPropertyImplPostfix) - 1, file);		
	}
	else
	{
		writeStringToFile(g_metaPropertyImplPostfix, sizeof(g_metaPropertyImplPostfix) - 1, file);	
	}
	writeStringToFile("{\n", file, indentation);

	TypeCategory typeCategory = CalcTypeFullName(typeName, propertyNode->m_type, templateArguments);

	if(!propertyNode->isStatic())
	{
		writeStringToFile("if(that->isConstant())\n", file, indentation + 1);
		writeStringToFile("{\n", file, indentation + 1);
		writeStringToFile("return ::pafcore::e_this_is_constant;\n", file, indentation + 2);
		writeStringToFile("}\n", file, indentation + 1);

		sprintf_s(buf, "%s* self;\n", className.c_str());
		writeStringToFile(buf, file, indentation + 1);
		if(classNode->isValueType())
		{
			writeStringToFile("if(!that->castToValuePtr(GetSingleton(), (void**)&self))\n", file, indentation + 1);
		}
		else 
		{
			writeStringToFile("if(!that->castToReferencePtr(GetSingleton(), (void**)&self))\n", file, indentation + 1);
		}
		writeStringToFile("{\n", file, indentation + 1);
		writeStringToFile("return ::pafcore::e_invalid_this_type;\n", file, indentation + 2);
		writeStringToFile("}\n", file, indentation + 1);
	}
	switch(typeCategory)
	{
	case void_type:
		sprintf_s(buf, "%s* arg;\n", typeName.c_str());
		writeStringToFile(buf, file, indentation + 1);
		sprintf_s(buf, "if(!value->castToVoidPtr((void**)&arg))\n");
		writeStringToFile(buf, file, indentation + 1);
		break;
	case primitive_type:
		if(propertyNode->m_set->byValue() || (propertyNode->m_set->isConstant() && propertyNode->m_set->byRef()))
		{
			sprintf_s(buf, "%s arg;\n", typeName.c_str());
			writeStringToFile(buf, file, indentation + 1);
			sprintf_s(buf, "if(!value->castToPrimitive(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), &arg))\n", typeName.c_str());
			writeStringToFile(buf, file, indentation + 1);
		}
		else
		{
			sprintf_s(buf, "%s* arg;\n", typeName.c_str());
			writeStringToFile(buf, file, indentation + 1);
			sprintf_s(buf, "if(!value->castToPrimitivePtr(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), (void**)&arg))\n", typeName.c_str());
			writeStringToFile(buf, file, indentation + 1);
		}
		break;
	case enum_type:
		sprintf_s(buf, "%s* arg;\n", typeName.c_str());
		writeStringToFile(buf, file, indentation + 1);
		sprintf_s(buf, "if(!value->castToEnumPtr(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), (void**)&arg))\n", typeName.c_str());
		writeStringToFile(buf, file, indentation + 1);
		break;
	case value_type:
		sprintf_s(buf, "%s* arg;\n", typeName.c_str());
		writeStringToFile(buf, file, indentation + 1);
		sprintf_s(buf, "if(!value->castToValuePtr(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), (void**)&arg))\n", typeName.c_str());
		writeStringToFile(buf, file, indentation + 1);
		break;
	case reference_type:
		sprintf_s(buf, "%s* arg;\n", typeName.c_str());
		writeStringToFile(buf, file, indentation + 1);
		sprintf_s(buf, "if(!value->castToReferencePtr(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), (void**)&arg))\n", typeName.c_str());
		writeStringToFile(buf, file, indentation + 1);
		break;
	default:
		assert(false);
	}

	writeStringToFile("{\n", file, indentation + 1);
	writeStringToFile("return ::pafcore::e_invalid_property_type;\n", file, indentation + 2);
	writeStringToFile("}\n", file, indentation + 1);
	if(propertyNode->isStatic())
	{
		sprintf_s(buf, "%s::set_%s", className.c_str(), propertyNode->m_name->m_str.c_str());
	}
	else
	{
		sprintf_s(buf, "self->set_%s", propertyNode->m_name->m_str.c_str());
	}
	writeStringToFile(buf, file, indentation + 1);

	if(primitive_type == typeCategory)
	{
		if(propertyNode->m_set->byRef() && !propertyNode->m_set->isConstant())
		{
			strcpy_s(buf, "(*arg);\n");
		}
		else
		{
			strcpy_s(buf, "(arg);\n");
		}
	}
	else
	{
		if(propertyNode->m_set->byPtr())
		{
			strcpy_s(buf, "(arg);\n");
		}
		else
		{
			strcpy_s(buf, "(*arg);\n");
		}
	}
	writeStringToFile(buf, file, 0);
	writeStringToFile("return ::pafcore::s_ok;\n", file, indentation + 1);	
	writeStringToFile("}\n\n", file, indentation);
}

void writeMetaPropertyImpls(ClassNode* classNode, TemplateArgumentMap* templateArguments, std::vector<PropertyNode*>& propertyNodes, FILE* file, int indentation)
{
	size_t propertyCount = propertyNodes.size();
	if(0 < propertyCount)
	{
		for(size_t i = 0 ; i < propertyCount; ++i)
		{
			PropertyNode* propertyNode = propertyNodes[i];
			if(0 != propertyNode->m_get)
			{
				writeMetaGetPropertyImpl(classNode, templateArguments, propertyNodes[i], file, indentation);
			}
			if(0 != propertyNode->m_set)
			{
				writeMetaSetPropertyImpl(classNode, templateArguments, propertyNodes[i], file, indentation);
			}
		}
	}
}

const char g_metaMethodImplPrefix[] = "::pafcore::ErrorCode ";
const char g_metaMethodImplPostfix[] = "(::pafcore::Variant* result, ::pafcore::Variant** args, int_t numArgs)\n";
	
void writeMetaMethodImpl_CastSelf(ClassNode* classNode, TemplateArgumentMap* templateArguments, MethodNode* methodNode, FILE* file, int indentation)
{
	std::string className;
	classNode->getFullName(className, templateArguments);

	if(!methodNode->isConstant())
	{
		writeStringToFile("if(args[0]->isConstant())\n", file, indentation);
		writeStringToFile("{\n", file, indentation);
		writeStringToFile("return ::pafcore::e_this_is_constant;\n", file, indentation + 1);
		writeStringToFile("}\n", file, indentation);
	}
	char buf[512];
	sprintf_s(buf, "%s* self;\n", className.c_str());
	writeStringToFile(buf, file, indentation);
	if(classNode->isValueType())
	{
		writeStringToFile("if(!args[0]->castToValuePtr(GetSingleton(), (void**)&self))\n", file, indentation);
	}
	else
	{
		writeStringToFile("if(!args[0]->castToReferencePtr(GetSingleton(), (void**)&self))\n", file, indentation);
	}
	writeStringToFile("{\n", file, indentation);
	writeStringToFile("return ::pafcore::e_invalid_this_type;\n", file, indentation + 1);
	writeStringToFile("}\n", file, indentation);
}

void writeMetaMethodImpl_CastParam(ClassNode* classNode, TemplateArgumentMap* templateArguments, ParameterNode* parameterNode, size_t argIndex, size_t paramIndex, FILE* file, int indentation)
{
	char buf[512];
	std::string typeName;
	TypeCategory typeCategory = CalcTypeFullName(typeName, parameterNode->m_type, templateArguments);

	if(0 == parameterNode->m_out)
	{
		switch(typeCategory)
		{
		case void_type:
			sprintf_s(buf, "%s* a%d;\n", typeName.c_str(), paramIndex);
			writeStringToFile(buf, file, indentation);
			sprintf_s(buf, "if(!args[%d]->castToVoidPtr((void**)&a%d))\n", argIndex, paramIndex);
			writeStringToFile(buf, file, indentation);
			break;
		case primitive_type:
			if(parameterNode->byValue() || (parameterNode->isConstant() && parameterNode->byRef()))
			{
				sprintf_s(buf, "%s a%d;\n", typeName.c_str(), paramIndex);
				writeStringToFile(buf, file, indentation);
				sprintf_s(buf, "if(!args[%d]->castToPrimitive(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), &a%d))\n", argIndex, typeName.c_str(), paramIndex);
				writeStringToFile(buf, file, indentation);
			}
			else 
			{
				assert(snt_keyword_ptr == parameterNode->m_passing->m_nodeType || snt_keyword_ref == parameterNode->m_passing->m_nodeType);
				sprintf_s(buf, "%s* a%d;\n", typeName.c_str(), paramIndex);
				writeStringToFile(buf, file, indentation);
				sprintf_s(buf, "if(!args[%d]->castToPrimitivePtr(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), (void**)&a%d))\n", argIndex, typeName.c_str(), paramIndex);
				writeStringToFile(buf, file, indentation);
			}
			break;
		case enum_type:
			if (parameterNode->byValue() || (parameterNode->isConstant() && parameterNode->byRef()))
			{
				sprintf_s(buf, "%s a%d;\n", typeName.c_str(), paramIndex);
				writeStringToFile(buf, file, indentation);
				sprintf_s(buf, "if(!args[%d]->castToEnum(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), &a%d))\n", argIndex, typeName.c_str(), paramIndex);
				writeStringToFile(buf, file, indentation);
			}
			else
			{
				sprintf_s(buf, "%s* a%d;\n", typeName.c_str(), paramIndex);
				writeStringToFile(buf, file, indentation);
				sprintf_s(buf, "if(!args[%d]->castToEnumPtr(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), (void**)&a%d))\n", argIndex, typeName.c_str(), paramIndex);
				writeStringToFile(buf, file, indentation);
			}
			break;
		case value_type:
			sprintf_s(buf, "%s* a%d;\n", typeName.c_str(), paramIndex);
			writeStringToFile(buf, file, indentation);
			sprintf_s(buf, "if(!args[%d]->castToValuePtr(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), (void**)&a%d))\n", argIndex, typeName.c_str(), paramIndex);
			writeStringToFile(buf, file, indentation);
			break;
		case reference_type:
			sprintf_s(buf, "%s* a%d;\n", typeName.c_str(), paramIndex);
			writeStringToFile(buf, file, indentation);
			sprintf_s(buf, "if(!args[%d]->castToReferencePtr(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), (void**)&a%d))\n", argIndex, typeName.c_str(), paramIndex);
			writeStringToFile(buf, file, indentation);
			break;
		default:
			assert(false);
		}
		writeStringToFile("{\n", file, indentation);
		sprintf_s(buf, "return ::pafcore::e_invalid_arg_type_%d;\n", paramIndex + 1);
		writeStringToFile(buf, file, indentation + 1);
		writeStringToFile("}\n", file, indentation);
	}
	else
	{
		sprintf_s(buf, "%s* a%d = 0;\n", typeName.c_str(), paramIndex);
		writeStringToFile(buf, file, indentation);
	}
}

void writeMetaMethodImpl_UseParam(ClassNode* classNode, TemplateArgumentMap* templateArguments, ParameterNode* parameterNode, size_t paramIndex, FILE* file)
{
	char buf[512];
	std::string typeName;
	TypeCategory typeCategory = CalcTypeFullName(typeName, parameterNode->m_type, templateArguments);
	if(0 == parameterNode->m_out)
	{
		if(primitive_type == typeCategory || enum_type == typeCategory)
		{
			if(parameterNode->byRef() && !parameterNode->isConstant())
			{
				sprintf_s(buf, "*a%d", paramIndex);
			}
			else 
			{
				sprintf_s(buf, "a%d", paramIndex);
			}
		}
		else
		{
			if(parameterNode->byPtr())
			{
				sprintf_s(buf, "a%d", paramIndex);
			}
			else 
			{
				sprintf_s(buf, "*a%d", paramIndex);
			}
		}
	}
	else
	{
		if(parameterNode->byPtr())
		{
			sprintf_s(buf, "&a%d", paramIndex);
		}
		else
		{
			assert(parameterNode->byRef());
			sprintf_s(buf, "a%d", paramIndex);
		}
	}
	if(0 != paramIndex)
	{
		writeStringToFile(", ", 2, file, 0);
	}
	writeStringToFile(buf, file, 0);
}

void writeMetaMethodImpl_AssignOutputParam(ClassNode* classNode, TemplateArgumentMap* templateArguments, ParameterNode* parameterNode, size_t argIndex, size_t paramIndex, FILE* file, int indentation)
{
	char buf[512];
	std::string typeName;
	TypeCategory typeCategory = CalcTypeFullName(typeName, parameterNode->m_type, templateArguments);

	if(parameterNode->isArray())
	{
		assert(parameterNode->outNew());
		sprintf_s(buf, "args[%d]->assignArray(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), a%d, new_array_size_of(a%d), %s, %s);\n",
				argIndex, typeName.c_str(), paramIndex, paramIndex, parameterNode->isConstant() ? "true" : "false", s_variantSemantic_ByNewArray);
	}
	else
	{
		const char* varSemantic;
		if(parameterNode->outNew())
		{
			varSemantic = s_variantSemantic_ByNewPtr;
		}
		else
		{
			varSemantic = s_variantSemantic_ByPtr;
		}

		switch(typeCategory)
		{
		case void_type:
			sprintf_s(buf, "args[%d]->assignVoidPtr(a%d, %s);\n",
				argIndex, paramIndex, parameterNode->isConstant() ? "true" : "false");
			break;
		case primitive_type:
			sprintf_s(buf, "args[%d]->assignPrimitivePtr(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), a%d, %s, %s);\n",
				argIndex, typeName.c_str(), paramIndex, parameterNode->isConstant() ? "true" : "false", varSemantic);
			break;
		case enum_type:
			sprintf_s(buf, "args[%d]->assignEnumPtr(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), a%d, %s, %s);\n",
				argIndex, typeName.c_str(), paramIndex, parameterNode->isConstant() ? "true" : "false", varSemantic);
			break;
		case value_type:
			sprintf_s(buf, "args[%d]->assignValuePtr(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), a%d, %s, %s);\n",
				argIndex, typeName.c_str(), paramIndex, parameterNode->isConstant() ? "true" : "false", varSemantic);
			break;
		case reference_type:
			sprintf_s(buf, "args[%d]->assignReferencePtr(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), a%d, %s, %s);\n",
				argIndex, typeName.c_str(), paramIndex, parameterNode->isConstant() ? "true" : "false", varSemantic);
			break;
		default:
			assert(false);
		}
	}
	writeStringToFile(buf, file, indentation);
}

void writeMetaMethodImpl_AssignResult(const std::string& typeName, TypeCategory typeCategory, MethodNode* methodNode, FILE* file, int indentation)
{
	char buf[512];
	if(methodNode->m_resultArray)
	{
		assert(methodNode->byNew());
		sprintf_s(buf, "result->assignArray(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), res, new_array_size_of(res), %s, %s);\n", 
			typeName.c_str(), methodNode->m_resultConst ? "true" : "false", s_variantSemantic_ByNewArray);
		writeStringToFile(buf, file, indentation);
		return;
	}


	const char* varSemantic;
	if(methodNode->byRef())
	{
		varSemantic = s_variantSemantic_ByRef;
	}
	else if(methodNode->byPtr())
	{
		varSemantic = s_variantSemantic_ByPtr;
	}
	else if(methodNode->byNew())
	{
		varSemantic = s_variantSemantic_ByNewPtr;
	}
	else 
	{
		assert(methodNode->byValue());
		varSemantic = s_variantSemantic_ByValue;
	}

	if(methodNode->byValue())
	{
		switch(typeCategory)
		{
		//case void_type: impossible
		case primitive_type:
			sprintf_s(buf, "result->assignPrimitive(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), &res);\n", typeName.c_str());
			break;
		case enum_type:
			sprintf_s(buf, "result->assignEnum(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), &res);\n", typeName.c_str());
			break;
		case value_type:
			sprintf_s(buf, "result->assignValuePtr(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), res, %s, %s);\n", 
				typeName.c_str(), methodNode->m_resultConst ? "true" : "false", s_variantSemantic_ByValue);
			break;
		case reference_type:
			sprintf_s(buf, "result->assignReferencePtr(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), res, %s, %s);\n", 
				typeName.c_str(), methodNode->m_resultConst ? "true" : "false", s_variantSemantic_ByValue);
			break;
		default:
			assert(false);
		}
	}
	else
	{
		switch(typeCategory)
		{
		case void_type:
			sprintf_s(buf, "result->assignVoidPtr(res, %s);\n", methodNode->m_resultConst ? "true" : "false");
			break;
		case primitive_type:
			sprintf_s(buf, "result->assignPrimitivePtr(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), res, %s, %s);\n", 
				typeName.c_str(), methodNode->m_resultConst ? "true" : "false", varSemantic);
			break;
		case enum_type:
			sprintf_s(buf, "result->assignEnumPtr(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), res, %s, %s);\n", 
				typeName.c_str(), methodNode->m_resultConst ? "true" : "false", varSemantic);
			break;
		case value_type:
			sprintf_s(buf, "result->assignValuePtr(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), res, %s, %s);\n", 
				typeName.c_str(), methodNode->m_resultConst ? "true" : "false", varSemantic);
			break;
		case reference_type:
			sprintf_s(buf, "result->assignReferencePtr(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), res, %s, %s);\n", 
				typeName.c_str(), methodNode->m_resultConst ? "true" : "false", varSemantic);
			break;
		default:
			assert(false);
		}
	}
	writeStringToFile(buf, file, indentation);
}

void writeMetaMethodImpl_Call(ClassNode* classNode, TemplateArgumentMap* templateArguments, MethodNode* methodNode, std::vector<ParameterNode*>& parameterNodes, FILE* file, int indentation)
{
	char buf[512];
	std::string typeName;
	std::string className;
	classNode->getFullName(className, templateArguments);

	TypeCategory typeCategory;
	if(methodNode->m_result->isVoid() && 0 == methodNode->m_passing)
	{
		typeCategory = void_type;
		writeStringToFile("", 0, file, indentation);
	}
	else
	{
		typeCategory = CalcTypeFullName(typeName, methodNode->m_result, templateArguments);
		if(methodNode->byValue())
		{
			if(primitive_type == typeCategory || enum_type == typeCategory)
			{
				sprintf_s(buf, "%s res = ", typeName.c_str());
			}
			else
			{
				sprintf_s(buf, "%s* res = new %s(", typeName.c_str(), typeName.c_str());
			}
		}
		else
		{
			sprintf_s(buf, "%s%s* res = %s", methodNode->m_constant ? "const " : "", typeName.c_str(), methodNode->byRef() ? "&" : "");
		}
		writeStringToFile(buf, file, indentation);
	}
	if(methodNode->isStatic())
	{
		sprintf_s(buf, "%s::%s(", className.c_str(), methodNode->m_name->m_str.c_str());
	}
	else
	{
		sprintf_s(buf, "self->%s(", methodNode->m_name->m_str.c_str());
	}
	writeStringToFile(buf, file, 0);
	size_t paramCount = parameterNodes.size();
	for(size_t i = 0 ; i < paramCount; ++i)
	{
		ParameterNode* parameterNode = parameterNodes[i];
		writeMetaMethodImpl_UseParam(classNode, templateArguments, parameterNode, i, file);
	}
	if(methodNode->byValue() && (value_type == typeCategory || reference_type == typeCategory))
	{
		writeStringToFile("));\n", file, 0);
	}
	else
	{
		writeStringToFile(");\n", file, 0);
	}
	if(!(methodNode->m_result->isVoid() && 0 == methodNode->m_passing))
	{
		writeMetaMethodImpl_AssignResult(typeName, typeCategory, methodNode, file, indentation);
	}	
}

void writeMetaMethodImpl(ClassNode* classNode, TemplateArgumentMap* templateArguments, const char* funcName, std::vector<MethodNode*>::iterator first, std::vector<MethodNode*>::iterator last, FILE* file, int indentation)
{
	char buf[512];
	std::string typeName;
	std::string metaClassName;
	GetMetaTypeFullName(metaClassName, classNode);

	writeStringToFile(g_metaMethodImplPrefix, sizeof(g_metaMethodImplPrefix) - 1, file, indentation);
	sprintf_s(buf, "%s::%s_%s", metaClassName.c_str(),
		classNode->m_name->m_str.c_str(), funcName);
	writeStringToFile(buf, file);
	writeStringToFile(g_metaMethodImplPostfix, sizeof(g_metaMethodImplPostfix) - 1, file);
	writeStringToFile("{\n", file, indentation);

	std::vector<MethodNode*>::iterator it = first;
	for(; it != last; ++it)
	{
		MethodNode* methodNode = *it;
		bool isStaticMethod = methodNode->isStatic() /*|| isSpecailMethod(funcName)*/;

		std::vector<ParameterNode*> parameterNodes;
		methodNode->collectParameterNodes(parameterNodes);
		size_t paramCount = parameterNodes.size();
		size_t argCount = isStaticMethod ? paramCount : paramCount + 1;

		sprintf_s(buf, "if(%d == numArgs)\n", argCount);
		writeStringToFile(buf, file, indentation + 1);
		writeStringToFile("{\n", file, indentation + 1);
		if(!isStaticMethod)
		{
			writeMetaMethodImpl_CastSelf(classNode, templateArguments, methodNode, file, indentation + 2);
		}
		for(size_t i = 0 ; i < paramCount; ++i)
		{
			ParameterNode* parameterNode = parameterNodes[i];
			size_t argIndex = isStaticMethod ? i : i + 1;
			writeMetaMethodImpl_CastParam(classNode, templateArguments, parameterNode, argIndex, i, file, indentation + 2);
		}
		writeMetaMethodImpl_Call(classNode, templateArguments, methodNode, parameterNodes, file, indentation + 2);
		for(size_t i = 0 ; i < paramCount; ++i)
		{
			ParameterNode* parameterNode = parameterNodes[i];
			if(parameterNode->m_out)
			{
				size_t argIndex = isStaticMethod ? i : i + 1;
				writeMetaMethodImpl_AssignOutputParam(classNode, templateArguments, parameterNode, argIndex, i, file, indentation + 2);
			}
		}
		writeStringToFile("return ::pafcore::s_ok;\n", file, indentation + 2);
		writeStringToFile("}\n", file, indentation + 1);
	}
	writeStringToFile("return ::pafcore::e_invalid_arg_num;\n", file, indentation + 1);
	writeStringToFile("}\n\n", file, indentation);	
}

void writeMetaMethodImpls(ClassNode* classNode, TemplateArgumentMap* templateArguments, std::vector<MethodNode*>& methodNodes, FILE* file, int indentation)
{
	std::vector<MethodNode*>::iterator first = methodNodes.begin();
	std::vector<MethodNode*>::iterator last = first;
	std::vector<MethodNode*>::iterator end = methodNodes.end();
	for(; first != end;)
	{
		++last;
		if(last == end || (*last)->m_name->m_str != (*first)->m_name->m_str)
		{
			writeMetaMethodImpl(classNode, templateArguments, (*first)->m_name->m_str.c_str(), first, last, file, indentation);
			first = last;
		}
	}
}

void writeMetaConstructor_Fields(ClassNode* classNode, TemplateArgumentMap* templateArguments, std::vector<FieldNode*>& fieldNodes, bool isStatic, FILE* file, int indentation)
{
	char buf[512];
	if(fieldNodes.empty())
	{
		return;
	}
	std::string className;
	classNode->getFullName(className, templateArguments);
	size_t count = fieldNodes.size();
	if(isStatic)
	{
		writeStringToFile("static ::pafcore::StaticField s_staticFields[] = \n", file, indentation);
	}
	else
	{
		writeStringToFile("static ::pafcore::InstanceField s_fields[] = \n", file, indentation);
	}
	writeStringToFile("{\n", file, indentation);

	for(size_t i = 0; i < count; ++i)
	{
		FieldNode* fieldNode = fieldNodes[i];
		char arraySize[512];
		if(fieldNode->isArray())
		{
			sprintf_s(arraySize, "field_array_size_of(%s, %s)", className.c_str(), fieldNode->m_name->m_str.c_str());
		}
		else
		{
			strcpy_s(arraySize, "0");
		}
		std::string typeName;
		TypeCategory typeCategory = CalcTypeFullName(typeName, fieldNode->m_type, templateArguments);
		if(isStatic)
		{
			sprintf_s(buf, "::pafcore::StaticField(\"%s\", RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), (size_t)&%s::%s, %s, %s, %s),\n",
				fieldNode->m_name->m_str.c_str(), typeName.c_str(), className.c_str(), fieldNode->m_name->m_str.c_str(),
				arraySize, fieldNode->isConstant() ? "true" : "false", fieldNode->isArray() ? "true" : "false");
		}
		else
		{
			sprintf_s(buf, "::pafcore::InstanceField(\"%s\", GetSingleton(), RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), offsetof(%s, %s), %s, %s, %s),\n",
				fieldNode->m_name->m_str.c_str(), typeName.c_str(), className.c_str(), fieldNode->m_name->m_str.c_str(),
				arraySize, fieldNode->isConstant() ? "true" : "false", fieldNode->isArray() ? "true" : "false");
		}

		writeStringToFile(buf, file, indentation + 1);
	}
	writeStringToFile("};\n", file, indentation);

	if(isStatic)
	{
		writeStringToFile("m_staticFields = s_staticFields;\n", file, indentation);
		writeStringToFile("m_staticFieldCount = array_size_of(s_staticFields);\n", file, indentation);
	}
	else
	{
		writeStringToFile("m_fields = s_fields;\n", file, indentation);
		writeStringToFile("m_fieldCount = array_size_of(s_fields);\n", file, indentation);
	}
}

void writeMetaConstructor_Properties(ClassNode* classNode, TemplateArgumentMap* templateArguments, std::vector<PropertyNode*>& propertyNodes, bool isStatic, FILE* file, int indentation)
{
	char buf[512];
	char getterFunc[256];
	char setterFunc[256];
	char getterType[256];
	char setterType[256];
	char getterPassing[64];
	char setterPassing[64];
	bool getterConstant;
	bool setterConstant;
	if(propertyNodes.empty())
	{
		return;
	}
	size_t count = propertyNodes.size();
	if(isStatic)
	{
		writeStringToFile("static ::pafcore::StaticProperty s_staticProperties[] = \n", file, indentation);
	}
	else
	{
		writeStringToFile("static ::pafcore::InstanceProperty s_properties[] = \n", file, indentation);
	}
	writeStringToFile("{\n", file, indentation);

	for(size_t i = 0; i < count; ++i)
	{
		sprintf_s(getterPassing, "::pafcore::Metadata::by_value");
		sprintf_s(setterPassing, "::pafcore::Metadata::by_value");
		getterConstant = false;
		setterConstant = false;

		PropertyNode* propertyNode = propertyNodes[i];
		if(propertyNode->m_get)
		{
			std::string typeName;
			TypeCategory typeCategory = CalcTypeFullName(typeName, propertyNode->m_get->m_type, templateArguments);
			sprintf_s(getterType, "RuntimeTypeOf<%s>::RuntimeType::GetSingleton()", typeName.c_str());
			sprintf_s(getterFunc, "%s_get_%s", classNode->m_name->m_str.c_str(), propertyNode->m_name->m_str.c_str());
			if(propertyNode->m_get->byPtr())
			{
				sprintf_s(getterPassing, "::pafcore::Metadata::by_ptr");
			}
			else if(propertyNode->m_get->byRef())
			{
				sprintf_s(getterPassing, "::pafcore::Metadata::by_ref");
			}
			getterConstant = propertyNode->m_get->isConstant();
		}
		else
		{
			strcpy_s(getterType, "0");
			strcpy_s(getterFunc, "0");
		}
		if(propertyNode->m_set)
		{
			std::string typeName;
			TypeCategory typeCategory = CalcTypeFullName(typeName, propertyNode->m_set->m_type, templateArguments);
			sprintf_s(setterType, "RuntimeTypeOf<%s>::RuntimeType::GetSingleton()", typeName.c_str());
			sprintf_s(setterFunc, "%s_set_%s", classNode->m_name->m_str.c_str(), propertyNode->m_name->m_str.c_str());
			if(propertyNode->m_set->byPtr())
			{
				sprintf_s(setterPassing, "::pafcore::Metadata::by_ptr");
			}
			else if(propertyNode->m_set->byRef())
			{
				sprintf_s(setterPassing, "::pafcore::Metadata::by_ref");
			}
			setterConstant = propertyNode->m_set->isConstant();
		}
		else
		{
			strcpy_s(setterType, "0");
			strcpy_s(setterFunc, "0");
		}
		if(isStatic)
		{
			sprintf_s(buf, "::pafcore::StaticProperty(\"%s\", %s, %s, %s, %s, %s, %s, %s, %s),\n",
				propertyNode->m_name->m_str.c_str(), 
				getterFunc, getterType, getterPassing, getterConstant ? "true" : "false",
				setterFunc, setterType, setterPassing, setterConstant ? "true" : "false");
		}
		else
		{
			sprintf_s(buf, "::pafcore::InstanceProperty(\"%s\", GetSingleton(), %s, %s, %s, %s, %s, %s, %s, %s),\n",
				propertyNode->m_name->m_str.c_str(), 
				getterFunc, getterType, getterPassing, getterConstant ? "true" : "false",
				setterFunc, setterType, setterPassing, setterConstant ? "true" : "false");
		}
		writeStringToFile(buf, file, indentation + 1);
	}
	writeStringToFile("};\n", file, indentation);

	if(isStatic)
	{
		writeStringToFile("m_staticProperties = s_staticProperties;\n", file, indentation);
		writeStringToFile("m_staticPropertyCount = array_size_of(s_staticProperties);\n", file, indentation);
	}
	else
	{
		writeStringToFile("m_properties = s_properties;\n", file, indentation);
		writeStringToFile("m_propertyCount = array_size_of(s_properties);\n", file, indentation);
	}
}

void writeMetaConstructor_Method_Result(ClassNode* classNode, TemplateArgumentMap* templateArguments, MethodNode* methodNode, FILE* file, int indentation)
{
	char buf[512];
	std::string typeName;
	char passing[32];
	strcpy_s(passing, "::pafcore::Result::by_value");
	if(0 != methodNode->m_passing)
	{
		switch(methodNode->m_passing->m_nodeType)
		{
		case snt_keyword_ref:
			strcpy_s(passing, "::pafcore::Result::by_ref");
			break;
		case snt_keyword_ptr:
			strcpy_s(passing, "::pafcore::Result::by_ptr");
			break;
		case snt_keyword_new:
			if(methodNode->m_resultArray)
			{
				strcpy_s(passing, "::pafcore::Result::by_new_array");
			}
			else
			{
				strcpy_s(passing, "::pafcore::Result::by_new");
			}
			break;
		}
	}
	if(snt_type_name == methodNode->m_result->m_nodeType)
	{
		TypeCategory typeCategory = CalcTypeFullName(typeName, (TypeNameNode*)methodNode->m_result, templateArguments);
	}
	else
	{
		typeName = "void";
	}
	size_t parameterCount = methodNode->getParameterCount();
	sprintf_s(buf, "static ::pafcore::Result s_%s_%d_Result(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), %s, %s);\n",
		methodNode->m_name->m_str.c_str(), parameterCount, typeName.c_str(), methodNode->m_resultConst ? "true" : "false", passing);
	writeStringToFile(buf, file, indentation);
}

void writeMetaConstructor_Method_Arguments(ClassNode* classNode, TemplateArgumentMap* templateArguments, MethodNode* methodNode, FILE* file, int indentation)
{
	char buf[512];
	std::string typeName;
	char passing[32];
	size_t parameterCount = methodNode->getParameterCount();
	if(0 < parameterCount)
	{
		sprintf_s(buf, "static ::pafcore::Argument s_%s_%d_Arguments[] = \n", 
			methodNode->m_name->m_str.c_str(), parameterCount);
		writeStringToFile(buf, file, indentation);
		writeStringToFile("{\n", file, indentation);

		std::vector<ParameterNode*> parameterNodes;
		methodNode->collectParameterNodes(parameterNodes);
		assert(parameterNodes.size() == parameterCount);

		for(size_t i = 0; i < parameterCount; ++i)
		{
			ParameterNode* parameterNode = parameterNodes[i];

			strcpy_s(passing, "::pafcore::Argument::by_value");
			if(0 != parameterNode->m_passing)
			{
				switch(parameterNode->m_passing->m_nodeType)
				{
				case snt_keyword_ref:
					strcpy_s(passing, "::pafcore::Argument::by_ref");
					break;
				case snt_keyword_ptr:
					strcpy_s(passing, "::pafcore::Argument::by_ptr");
					break;
				}
			}
			TypeCategory typeCategory = CalcTypeFullName(typeName, parameterNode->m_type, templateArguments);
			sprintf_s(buf, "::pafcore::Argument(\"%s\", RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), %s),\n",
				parameterNode->m_name->m_str.c_str(), typeName.c_str(), passing);
			writeStringToFile(buf, file, indentation + 1);
		}
		writeStringToFile("};\n", file, indentation);
	}
}

void writeMetaConstructor_Method_Overloads(std::vector<MethodNode*>::iterator first, std::vector<MethodNode*>::iterator last, FILE* file, int indentation)
{
	char buf[512];
	char arguments[256];
	sprintf_s(buf, "static ::pafcore::Overload s_%s_Overloads[] = \n",
		(*first)->m_name->m_str.c_str());
	writeStringToFile(buf, file, indentation);
	writeStringToFile("{\n", file, indentation);
	for(auto it = first; it != last; ++it)
	{
		MethodNode* methodNode = *it;
		size_t parameterCount = methodNode->getParameterCount();
		if(0 == parameterCount)
		{
			strcpy_s(arguments, "0");
		}
		else
		{
			sprintf_s(arguments, "s_%s_%d_Arguments", methodNode->m_name->m_str.c_str(), parameterCount);
		}
		sprintf_s(buf, "::pafcore::Overload(&s_%s_%d_Result, %s, %d),\n",
			methodNode->m_name->m_str.c_str(), parameterCount, arguments, parameterCount);
		writeStringToFile(buf, file, indentation + 1);
	}
	writeStringToFile("};\n", file, indentation);
}


void writeMetaConstructor_Methods(ClassNode* classNode, TemplateArgumentMap* templateArguments, std::vector<MethodNode*>& methodNodes, bool isStatic, FILE* file, int indentation)
{
	if(methodNodes.empty())
	{
		return;
	}
	std::string className;
	classNode->getFullName(className, templateArguments);

	//Result & Arguments
	size_t count = methodNodes.size();
	for(size_t i = 0; i < count; ++i)
	{
		MethodNode* methodNode = methodNodes[i];
		writeMetaConstructor_Method_Result(classNode, templateArguments, methodNode, file, indentation);
		writeMetaConstructor_Method_Arguments(classNode, templateArguments, methodNode, file, indentation);
	}

	//Overloads
	std::vector<MethodNode*>::iterator first = methodNodes.begin();
	std::vector<MethodNode*>::iterator last = first;
	std::vector<MethodNode*>::iterator end = methodNodes.end();

	for(; first != end;)
	{
		++last;
		if(last == end || (*last)->m_name->m_str != (*first)->m_name->m_str)
		{
			writeMetaConstructor_Method_Overloads(first, last, file, indentation);
			first = last;
		}
	}

	//Method
	if(isStatic)
	{
		writeStringToFile("static ::pafcore::StaticMethod s_staticMethods[] = \n", file, indentation);
	}
	else
	{
		writeStringToFile("static ::pafcore::InstanceMethod s_methods[] = \n", file, indentation);
	}
	writeStringToFile("{\n", file, indentation);

	first = methodNodes.begin();
	last = first;
	for(; first != end;)
	{
		++last;
		if(last == end || (*last)->m_name->m_str != (*first)->m_name->m_str)
		{
			char buf[512];
			const char* methodName = (*first)->m_name->m_str.c_str();
			int overloadCount = last - first;
			sprintf_s(buf, "::pafcore::%s(\"%s\", %s_%s, s_%s_Overloads, %d),\n",
				isStatic ? "StaticMethod" : "InstanceMethod",
				methodName, classNode->m_name->m_str.c_str(), methodName, methodName, overloadCount);
			writeStringToFile(buf, file, indentation + 1);
			first = last;
		}
	}
	writeStringToFile("};\n", file, indentation);

	if(isStatic)
	{
		writeStringToFile("m_staticMethods = s_staticMethods;\n", file, indentation);
		writeStringToFile("m_staticMethodCount = array_size_of(s_staticMethods);\n", file, indentation);
	}
	else
	{
		writeStringToFile("m_methods = s_methods;\n", file, indentation);
		writeStringToFile("m_methodCount = array_size_of(s_methods);\n", file, indentation);
	}
}

bool MethodNodeNameEqual(MethodNode* arg1, MethodNode* arg2)
{
	return arg1->m_name->m_str == arg2->m_name->m_str;
}

void writeMetaConstructor_Member(
	std::vector<MemberNode*>& nestedTypeNodes, 
	std::vector<TypeAliasNode*>& nestedTypeAliasNodes,
	std::vector<FieldNode*>& staticFieldNodes,
	std::vector<PropertyNode*>& staticPropertyNodes,
	const std::vector<MethodNode*>& staticMethodNodes_,
	std::vector<FieldNode*>& fieldNodes,
	std::vector<PropertyNode*>& propertyNodes,
	const std::vector<MethodNode*>& methodNodes_,
	FILE* file, int indentation)
{
	char buf[512];

	std::vector<MethodNode*> staticMethodNodes = staticMethodNodes_;
	std::vector<MethodNode*> methodNodes = methodNodes_;
	
	auto it = std::unique(staticMethodNodes.begin(), staticMethodNodes.end(), MethodNodeNameEqual);
	staticMethodNodes.erase(it, staticMethodNodes.end());

	it = std::unique(methodNodes.begin(), methodNodes.end(), MethodNodeNameEqual);
	methodNodes.erase(it, methodNodes.end());

	if(nestedTypeNodes.empty() && nestedTypeAliasNodes.empty() 
		&& staticFieldNodes.empty() && staticPropertyNodes.empty() && staticMethodNodes.empty()
		&& fieldNodes.empty() && propertyNodes.empty() && methodNodes.empty())
	{
		return;
	}


	writeStringToFile("static Metadata* s_members[] = \n", file, indentation);
	writeStringToFile("{\n", file, indentation);

	size_t nestedTypeCount = nestedTypeNodes.size();
	size_t nestedTypeAliasCount = nestedTypeAliasNodes.size();
	size_t staticFieldCount = staticFieldNodes.size();
	size_t staticPropertyCount = staticPropertyNodes.size();
	size_t staticMethodCount = staticMethodNodes.size();
	size_t fieldCount = fieldNodes.size();
	size_t propertyCount = propertyNodes.size();
	size_t methodCount = methodNodes.size();

	size_t currentNestedType = 0;
	size_t currentNestedTypeAlias = 0;
	size_t currentStaticField = 0;
	size_t currentStaticProperty = 0;
	size_t currentStaticMethod = 0;
	size_t currentField = 0;
	size_t currentProperty = 0;
	size_t currentMethod = 0;

	enum MemberCategory
	{
		unknown_member,
		nested_type,
		nested_type_alias,
		static_field,
		static_property,
		static_method,
		instance_field,
		instance_property,
		instance_method,
	};
	while(true)
	{
		MemberNode* current = 0;
		MemberCategory category = unknown_member;
		if(currentNestedType < nestedTypeCount)
		{
			current = nestedTypeNodes[currentNestedType];
			category = nested_type;
		}
		if (currentNestedTypeAlias < nestedTypeAliasCount)
		{
			MemberNode* memberNode = nestedTypeAliasNodes[currentNestedTypeAlias];
			if (0 == current || memberNode->m_name->m_str < current->m_name->m_str)
			{
				current = memberNode;
				category = nested_type_alias;
			}
		}
		if (currentStaticField < staticFieldCount)
		{
			MemberNode* memberNode = staticFieldNodes[currentStaticField];
			if (0 == current || memberNode->m_name->m_str < current->m_name->m_str)
			{
				current = memberNode;
				category = static_field;
			}
		}
		if(currentStaticProperty < staticPropertyCount)
		{
			MemberNode* memberNode = staticPropertyNodes[currentStaticProperty];
			if(0 == current || memberNode->m_name->m_str < current->m_name->m_str)
			{
				current = memberNode;
				category = static_property;
			}
		}
		if(currentStaticMethod < staticMethodCount)
		{
			MemberNode* memberNode = staticMethodNodes[currentStaticMethod];
			if(0 == current || memberNode->m_name->m_str < current->m_name->m_str)
			{
				current = memberNode;
				category = static_method;
			}
		}
		if(currentField < fieldCount)
		{
			MemberNode* memberNode = fieldNodes[currentField];
			if(0 == current || memberNode->m_name->m_str < current->m_name->m_str)
			{
				current = memberNode;
				category = instance_field;
			}
		}
		if(currentProperty < propertyCount)
		{
			MemberNode* memberNode = propertyNodes[currentProperty];
			if(0 == current || memberNode->m_name->m_str < current->m_name->m_str)
			{
				current = memberNode;
				category = instance_property;
			}
		}
		if(currentMethod < methodCount)
		{
			MemberNode* memberNode = methodNodes[currentMethod];
			if(0 == current || memberNode->m_name->m_str < current->m_name->m_str)
			{
				current = memberNode;
				category = instance_method;
			}
		}
		if(unknown_member == category)
		{
			break;
		}
		switch(category)
		{
		case nested_type:
			sprintf_s(buf, "s_nestedTypes[%d],\n", currentNestedType);
			++currentNestedType;
			break;
		case nested_type_alias:
			sprintf_s(buf, "s_nestedTypeAliases[%d],\n", currentNestedTypeAlias);
			++currentNestedTypeAlias;
			break;
		case static_field:
			sprintf_s(buf, "&s_staticFields[%d],\n", currentStaticField);
			++currentStaticField;
			break;
		case static_property:
			sprintf_s(buf, "&s_staticProperties[%d],\n", currentStaticProperty);
			++currentStaticProperty;
			break;
		case static_method:
			sprintf_s(buf, "&s_staticMethods[%d],\n", currentStaticMethod);
			++currentStaticMethod;
			break;
		case instance_field:
			sprintf_s(buf, "&s_fields[%d],\n", currentField);
			++currentField;
			break;
		case instance_property:
			sprintf_s(buf, "&s_properties[%d],\n", currentProperty);
			++currentProperty;
			break;
		case instance_method:
			sprintf_s(buf, "&s_methods[%d],\n", currentMethod);
			++currentMethod;
			break;
		default:
			assert(false);
		}
		writeStringToFile(buf, file, indentation + 1);
	}

	writeStringToFile("};\n", file, indentation);
	writeStringToFile("m_members = s_members;\n", file, indentation);
	writeStringToFile("m_memberCount = array_size_of(s_members);\n", file, indentation);	
}

void writeMetaConstructor_BaseClasses(ClassNode* classNode, TemplateArgumentMap* templateArguments, FILE* file, int indentation)
{
	char buf[512];
	std::string typeName;
	std::vector<std::pair<TokenNode*, TypeNameNode*>> typeNameNodes;
	classNode->m_baseList->collectTypeNameNodes(typeNameNodes);
	if(typeNameNodes.empty())
	{
		return;
	}
	std::string className;
	classNode->getFullName(className, templateArguments);

	writeStringToFile("static BaseClass s_baseClasses[] =\n", file, indentation);
	writeStringToFile("{\n", file, indentation);
	size_t count = typeNameNodes.size();
	for(size_t i = 0; i < count; ++i)
	{
		TypeNameNode* typeNameNode = typeNameNodes[i].second;
		TypeCategory typeCategory = CalcTypeFullName(typeName, typeNameNode, templateArguments);
		sprintf_s(buf, "{RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), base_offset_of(%s, %s)},\n",
			typeName.c_str(), className.c_str(), typeName.c_str());
		writeStringToFile(buf, file, indentation + 1);
	}
	writeStringToFile("};\n", file, indentation);
	writeStringToFile("m_baseClasses = s_baseClasses;\n", file, indentation);
	writeStringToFile("m_baseClassCount = array_size_of(s_baseClasses);\n", file, indentation);
}

void writeMetaConstructor_NestedTypes(ClassNode* classNode, TemplateArgumentMap* templateArguments, std::vector<MemberNode*>& nestedTypeNodes, FILE* file, int indentation)
{
	char buf[512];
	if(nestedTypeNodes.empty())
	{
		return;
	}
	size_t count = nestedTypeNodes.size();
	writeStringToFile("static ::pafcore::Type* s_nestedTypes[] = \n", file, indentation);
	writeStringToFile("{\n", file, indentation);

	for(size_t i = 0; i < count; ++i)
	{
		MemberNode* typeNode = nestedTypeNodes[i];
		std::string metaTypeName;
		GetMetaTypeFullName(metaTypeName, typeNode);

		sprintf_s(buf, "%s::GetSingleton(),\n",metaTypeName.c_str());
		writeStringToFile(buf, file, indentation + 1);
	}
	writeStringToFile("};\n", file, indentation);

	writeStringToFile("m_nestedTypes = s_nestedTypes;\n", file, indentation);
	writeStringToFile("m_nestedTypeCount = array_size_of(s_nestedTypes);\n", file, indentation);
}

void writeMetaConstructor_NestedTypeAliases(ClassNode* classNode, TemplateArgumentMap* templateArguments, std::vector<TypeAliasNode*>& nestedTypeAliasNodes, FILE* file, int indentation)
{
	char buf[512];
	if (nestedTypeAliasNodes.empty())
	{
		return;
	}
	size_t count = nestedTypeAliasNodes.size();
	writeStringToFile("static ::pafcore::TypeAlias* s_nestedTypeAliases[] = \n", file, indentation);
	writeStringToFile("{\n", file, indentation);

	for (size_t i = 0; i < count; ++i)
	{
		TypeAliasNode* typeAliasNode = nestedTypeAliasNodes[i];
		std::string metaTypeName;
		GetMetaTypeFullName(metaTypeName, typeAliasNode);

		sprintf_s(buf, "%s::GetSingleton(),\n", metaTypeName.c_str());
		writeStringToFile(buf, file, indentation + 1);
	}
	writeStringToFile("};\n", file, indentation);

	writeStringToFile("m_nestedTypeAliases = s_nestedTypeAliases;\n", file, indentation);
	writeStringToFile("m_nestedTypeAliasCount = array_size_of(s_nestedTypeAliases);\n", file, indentation);
}

void writeMetaRegisterToNamespace(MemberNode* memberNode, FILE* file, int indentation)
{
	char buf[512];
	assert(0 != memberNode->m_enclosing);
	if (snt_namespace == memberNode->m_enclosing->m_nodeType)
	{
		writeStringToFile("::pafcore::NameSpace::GetGlobalNameSpace()", file, indentation);

		std::vector<ScopeNode*> enclosings;
		memberNode->getEnclosings(enclosings);
		size_t count = enclosings.size();
		for(size_t i = 0; i < count; ++i)
		{
			ScopeNode* enclosing = enclosings[i];
			if(snt_namespace == enclosing->m_nodeType)
			{
				sprintf_s(buf, "->getNameSpace(\"%s\")", enclosing->m_name->m_str.c_str());
				writeStringToFile(buf, file);
			}
			else
			{
				break;
			}
		}
		writeStringToFile("->registerMember(this);\n", file);
	}
}

void writeMetaConstructor(ClassNode* classNode, 
	TemplateArgumentMap* templateArguments,
	std::vector<MemberNode*>& nestedTypeNodes,
	std::vector<TypeAliasNode*>& nestedTypeAliasNodes,
	std::vector<FieldNode*>& staticFieldNodes,
	std::vector<PropertyNode*>& staticPropertyNodes,
	std::vector<MethodNode*>& staticMethodNodes,
	std::vector<FieldNode*>& fieldNodes,
	std::vector<PropertyNode*>& propertyNodes,
	std::vector<MethodNode*>& methodNodes,
	FILE* file, int indentation)
{
	char buf[512];

	std::string classTemplateArgumentsName;
	std::string className;
	std::string metaClassName;

	classNode->getTemplateArgumentsName(classTemplateArgumentsName, 0, templateArguments);
	classNode->getFullName(className, templateArguments);
	GetMetaTypeFullName(metaClassName, classNode);

	sprintf_s(buf, "%s::%s() : ::pafcore::ClassType(\"%s%s\", ::pafcore::%s)\n", 
		metaClassName.c_str(), metaClassName.c_str(),
		classNode->m_name->m_str.c_str(), classTemplateArgumentsName.c_str(),
		classNode->m_category ? classNode->m_category->m_str.c_str() : 
		classNode->isValueType() ? "value_object" : "reference_object" );

	writeStringToFile(buf, file, indentation);
	writeStringToFile("{\n", file, indentation);

	sprintf_s(buf, "m_size = sizeof(%s);\n", className.c_str());
	writeStringToFile(buf, file, indentation + 1);
	
	writeMetaConstructor_BaseClasses(classNode, templateArguments, file, indentation + 1);
	writeMetaConstructor_NestedTypes(classNode, templateArguments, nestedTypeNodes, file, indentation + 1);
	writeMetaConstructor_NestedTypeAliases(classNode, templateArguments, nestedTypeAliasNodes, file, indentation + 1);
	writeMetaConstructor_Fields(classNode, templateArguments, staticFieldNodes, true, file, indentation + 1);
	writeMetaConstructor_Properties(classNode, templateArguments, staticPropertyNodes, true, file, indentation + 1);
	writeMetaConstructor_Methods(classNode, templateArguments, staticMethodNodes, true, file, indentation + 1);

	writeMetaConstructor_Fields(classNode, templateArguments, fieldNodes, false, file, indentation + 1);
	writeMetaConstructor_Properties(classNode, templateArguments, propertyNodes, false, file, indentation + 1);
	writeMetaConstructor_Methods(classNode, templateArguments, methodNodes, false, file, indentation + 1);

	writeMetaConstructor_Member(nestedTypeNodes, nestedTypeAliasNodes, 
		staticFieldNodes, staticPropertyNodes, staticMethodNodes,
		fieldNodes, propertyNodes, methodNodes, file, indentation + 1);

	writeMetaRegisterToNamespace(classNode, file, indentation + 1);

	writeStringToFile("}\n\n", file, indentation);	
}


void writeEnumMetaConstructor_Enumerators(EnumNode* enumNode, std::vector<IdentifyNode*>& enumerators, FILE* file, int indentation)
{
	char buf[512];
	if (enumerators.empty())
	{
		return;
	}
	std::string metaClassName;
	GetMetaTypeFullName(metaClassName, enumNode);

	writeStringToFile("static ::pafcore::Enumerator s_enumerators[] = \n", file, indentation);
	writeStringToFile("{\n", file, indentation);
	size_t count = enumerators.size();
	for (size_t i = 0; i < count; ++i)
	{
		IdentifyNode* enumerator = enumerators[i];
		std::string enumScopeName;
		enumNode->m_enclosing->getFullName(enumScopeName, 0);
		sprintf_s(buf, "::pafcore::Enumerator(\"%s\", %s::GetSingleton(), %s::%s),\n",
			enumerator->m_str.c_str(), metaClassName.c_str(), enumScopeName.c_str(), enumerator->m_str.c_str());
		writeStringToFile(buf, file, indentation + 1);
	}
	writeStringToFile("};\n", file, indentation);
	
	writeStringToFile("m_enumerators = s_enumerators;\n", file, indentation);
	writeStringToFile("m_enumeratorCount = array_size_of(s_enumerators);\n", file, indentation);
}

void writeEnumMetaConstructor(EnumNode* enumNode, std::vector<IdentifyNode*>& enumerators, FILE* file, int indentation)
{
	char buf[512];
	std::string typeName;
	std::string metaTypeName;
	enumNode->getFullName(typeName, 0);
	GetMetaTypeFullName(metaTypeName, enumNode);

	sprintf_s(buf, "%s::%s() : ::pafcore::EnumType(\"%s\")\n",
		metaTypeName.c_str(),
		metaTypeName.c_str(),
		enumNode->m_name->m_str.c_str());

	writeStringToFile(buf, file, indentation);
	writeStringToFile("{\n", file, indentation);

	sprintf_s(buf, "m_size = sizeof(%s);\n", typeName.c_str());
	writeStringToFile(buf, file, indentation + 1);
	
	writeEnumMetaConstructor_Enumerators(enumNode, enumerators, file, indentation + 1);
	writeMetaRegisterToNamespace(enumNode, file, indentation + 1);
	writeStringToFile("}\n\n", file, indentation);
}

void writeMetaGetSingletonImpls(MemberNode* memberNode, FILE* file, int indentation)
{
	char buf[512];
	std::string metaClassName;
	GetMetaTypeFullName(metaClassName, memberNode);

	sprintf_s(buf, "%s* %s::GetSingleton()\n", metaClassName.c_str(), metaClassName.c_str());
	writeStringToFile(buf, file, indentation);
	writeStringToFile("{\n", file, indentation);
	sprintf_s(buf, "static %s* s_instance = 0;\n", metaClassName.c_str());
	writeStringToFile(buf, file, indentation + 1);
	sprintf_s(buf, "static char s_buffer[sizeof(%s)];\n", metaClassName.c_str());
	writeStringToFile(buf, file, indentation + 1);
	writeStringToFile("if(0 == s_instance)\n", file, indentation + 1);
	writeStringToFile("{\n", file, indentation + 1);
	sprintf_s(buf, "s_instance = (%s*)s_buffer;\n", metaClassName.c_str());
	writeStringToFile(buf, file, indentation + 2);
	sprintf_s(buf, "new (s_buffer)%s;\n", metaClassName.c_str());
	writeStringToFile(buf, file, indentation + 2);
	writeStringToFile("}\n", file, indentation + 1);
	writeStringToFile("return s_instance;\n", file, indentation + 1);
	writeStringToFile("}\n\n", file, indentation);
}

void MetaSourceFileGenerator::generateCode_TypeAlias(FILE* file, TypeAliasNode* typeAliasNode, int indentation)
{
	if (typeAliasNode->isNativeOnly())
	{
		return;
	}

	char buf[512];
	std::string typeName;
	std::string metaTypeName;
	typeAliasNode->getFullName(typeName, 0);
	GetMetaTypeFullName(metaTypeName, typeAliasNode);

	sprintf_s(buf, "%s::%s() : TypeAlias(\"%s\", RuntimeTypeOf<%s>::RuntimeType::GetSingleton())\n",
		metaTypeName.c_str(), metaTypeName.c_str(), typeAliasNode->m_name->m_str.c_str(), typeName.c_str());
	writeStringToFile(buf, file, indentation);
	writeStringToFile("{\n", file, indentation);
	writeMetaRegisterToNamespace(typeAliasNode, file, indentation + 1);
	writeStringToFile("}\n\n", file, indentation);
	writeMetaGetSingletonImpls(typeAliasNode, file, indentation);
}

void writeMethodParameter(MethodNode* methodNode, ParameterNode* parameterNode, FILE* file);

void writeInterfaceMethodImpl_AssignThis(ClassNode* classNode, MethodNode* methodNode, FILE* file, int indentation)
{
	std::string className;
	classNode->getFullName(className, 0);
	char buf[512];
	if(classNode->isValueType())
	{
		sprintf_s(buf, "__self__.assignValuePtr(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), this, %s, %s);\n", 
			className.c_str(), methodNode->isConstant() ? "true" : "false", s_variantSemantic_ByPtr);
	}
	else
	{
		sprintf_s(buf, "__self__.assignReferencePtr(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), this, %s, %s);\n", 
			className.c_str(), methodNode->isConstant() ? "true" : "false", s_variantSemantic_ByPtr);
	}
	writeStringToFile(buf, file, indentation);
}


void writeInterfaceMethodImpl_SetOutputParamType(ClassNode* classNode, MethodNode* methodNode, ParameterNode* parameterNode, size_t argIndex, FILE* file, int indentation)
{
	char buf[512];
	std::string typeName;
	TypeCategory typeCategory = CalcTypeFullName(typeName, parameterNode->m_type, 0);
	sprintf_s(buf, "__args__[%d].assignNullPtr(RuntimeTypeOf<%s>::RuntimeType::GetSingleton());\n", 
		argIndex, typeName.c_str());
	writeStringToFile(buf, file, indentation);
}

void writeInterfaceMethodImpl_AssignInputParam(ClassNode* classNode, MethodNode* methodNode, ParameterNode* parameterNode, size_t argIndex, FILE* file, int indentation)
{
	char buf[512];
	std::string typeName;
	TypeCategory typeCategory = CalcTypeFullName(typeName, parameterNode->m_type, 0);
	//if(parameterNode->isArray())
	//{
	//	sprintf_s(buf, "__args__[%d].assignArray(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), %s, new_array_size_of(%s), %s, %s);\n", 
	//		argIndex, typeName.c_str(), parameterNode->m_name->m_str.c_str(), 
	//		parameterNode->m_name->m_str.c_str(), methodNode->isConstant() ? "true" : "false", s_variantSemantic_ByArray);
	//	writeStringToFile(buf, file, indentation);
	//	return;
	//}

	const char* varSemantic;
	if(parameterNode->byRef())
	{
		varSemantic = s_variantSemantic_ByRef;
	}
	else if(parameterNode->byPtr())
	{
		varSemantic = s_variantSemantic_ByPtr;
	}
	else 
	{
		assert(parameterNode->byValue());
		varSemantic = s_variantSemantic_ByValue;
	}

	const char* sign = parameterNode->byPtr() ? "" : "&";
	if(parameterNode->byValue())
	{
		switch(typeCategory)
		{
		//case void_type: impossible
		case primitive_type:
			sprintf_s(buf, "__args__[%d].assignPrimitive(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), &%s);\n", 
				argIndex, typeName.c_str(), parameterNode->m_name->m_str.c_str());
			break;
		case enum_type:
			sprintf_s(buf, "__args__[%d].assignEnum(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), &%s);\n", 
				argIndex, typeName.c_str(), parameterNode->m_name->m_str.c_str());
			break;
		case value_type:
			sprintf_s(buf, "__args__[%d].assignValuePtr(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), %s%s, %s, %s);\n", 
				argIndex, typeName.c_str(), sign, parameterNode->m_name->m_str.c_str(), 
				methodNode->isConstant() ? "true" : "false", s_variantSemantic_ByValue);
			break;
		case reference_type:
			sprintf_s(buf, "__args__[%d].assignReferencePtr(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), %s%s, %s, %s);\n", 
				argIndex, typeName.c_str(), sign, parameterNode->m_name->m_str.c_str(), 
				methodNode->isConstant() ? "true" : "false", s_variantSemantic_ByValue);
			break;
		default:
			assert(false);	
		}
	}
	else
	{
		switch(typeCategory)
		{
		case void_type:
			sprintf_s(buf, "__args__[%d].assignVoidPtr(%s%s, %s);\n",
				argIndex, sign, parameterNode->m_name->m_str.c_str(),
				methodNode->isConstant() ? "true" : "false");
			break;
		case primitive_type:
			sprintf_s(buf, "__args__[%d].assignPrimitivePtr(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), %s%s, %s, %s);\n", 
				argIndex, typeName.c_str(), sign, parameterNode->m_name->m_str.c_str(), 
				methodNode->isConstant() ? "true" : "false", varSemantic);
			break;
		case enum_type:
			sprintf_s(buf, "__args__[%d].assignEnumPtr(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), %s%s, %s, %s);\n", 
				argIndex, typeName.c_str(), sign, parameterNode->m_name->m_str.c_str(), 
				methodNode->isConstant() ? "true" : "false", varSemantic);
			break;
		case value_type:
			sprintf_s(buf, "__args__[%d].assignValuePtr(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), %s%s, %s, %s);\n", 
				argIndex, typeName.c_str(), sign, parameterNode->m_name->m_str.c_str(), 
				methodNode->isConstant() ? "true" : "false", varSemantic);
			break;
		case reference_type:
			sprintf_s(buf, "__args__[%d].assignReferencePtr(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), %s%s, %s, %s);\n", 
				argIndex, typeName.c_str(), sign, parameterNode->m_name->m_str.c_str(), 
				methodNode->isConstant() ? "true" : "false", varSemantic);
			break;
		default:
			assert(false);	
		}
	}
	writeStringToFile(buf, file, indentation);
}

void writeInterfaceMethodImpl_CastOutputParam(ClassNode* classNode, MethodNode* methodNode, ParameterNode* parameterNode, size_t argIndex, FILE* file, int indentation)
{
	char buf[512];
	std::string typeName;
	TypeCategory typeCategory = CalcTypeFullName(typeName, parameterNode->m_type, 0);
	assert(parameterNode->isOutput() && (parameterNode->byRef() || parameterNode->byPtr()));
	
	const char* sign = parameterNode->byPtr() ? "" : "&";
	switch(typeCategory)
	{
	case void_type:
		sprintf_s(buf, "__args__[%d].castToVoidPtr((void**)%s%s);\n",
			argIndex, sign, parameterNode->m_name->m_str.c_str());
		break;
	case primitive_type:
		sprintf_s(buf, "__args__[%d].castToPrimitivePtr(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), (void**)%s%s);\n",
			argIndex, typeName.c_str(), sign, parameterNode->m_name->m_str.c_str());
		break;
	case enum_type:
		sprintf_s(buf, "__args__[%d].castToEnumPtr(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), (void**)%s%s);\n",
			argIndex, typeName.c_str(), sign, parameterNode->m_name->m_str.c_str());
		break;
	case value_type:
		sprintf_s(buf, "__args__[%d].castToValuePtr(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), (void**)%s%s);\n",
			argIndex, typeName.c_str(), sign, parameterNode->m_name->m_str.c_str());
		break;
	case reference_type:
		sprintf_s(buf, "__args__[%d].castToReferencePtr(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), (void**)%s%s);\n",
			argIndex, typeName.c_str(), sign, parameterNode->m_name->m_str.c_str());
		break;
	default:
		assert(false);
	}
	writeStringToFile(buf, file, indentation);
	if(parameterNode->outNew())
	{
		sprintf_s(buf, "__args__[%d].unhold();\n", argIndex);
		writeStringToFile(buf, file, indentation);
	}
}

void writeInterfaceMethodImpl_SetResultType(ClassNode* classNode, MethodNode* methodNode, FILE* file, int indentation)
{
	char buf[512];
	std::string typeName;
	TypeCategory typeCategory = CalcTypeFullName(typeName, methodNode->m_result, 0);

	if(methodNode->byValue() && (primitive_type == typeCategory || enum_type == typeCategory))
	{
		if(primitive_type == typeCategory)
		{
			sprintf_s(buf, "__result__.assignNullPrimitive(RuntimeTypeOf<%s>::RuntimeType::GetSingleton());\n", typeName.c_str());
		}
		else
		{
			sprintf_s(buf, "__result__.assignNullEnum(RuntimeTypeOf<%s>::RuntimeType::GetSingleton());\n", typeName.c_str());
		}
	}
	else
	{
		sprintf_s(buf, "__result__.assignNullPtr(RuntimeTypeOf<%s>::RuntimeType::GetSingleton());\n", typeName.c_str());
	}
	writeStringToFile(buf, file, indentation);
}

void writeInterfaceMethodImpl_CastResult(ClassNode* classNode, MethodNode* methodNode, FILE* file, int indentation)
{
	char buf[512];
	std::string typeName;
	TypeCategory typeCategory = CalcTypeFullName(typeName, methodNode->m_result, 0);

	const char* sign;
	if(methodNode->byValue() && (primitive_type == typeCategory || enum_type == typeCategory))
	{
		sign = "";
	}
	else
	{
		sign = "*";
	}
	sprintf_s(buf, "%s%s __res__;\n", typeName.c_str(), sign);
	writeStringToFile(buf, file, indentation);

	TypeNameNode* resultNode = static_cast<TypeNameNode*>(methodNode->m_result);
	if(methodNode->byValue())
	{
		switch(typeCategory)
		{
		//case void_type: impossible
		case primitive_type:
			sprintf_s(buf, "__result__.castToPrimitive(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), &__res__);\n", typeName.c_str());
			break;
		case enum_type:
			sprintf_s(buf, "__result__.castToEnum(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), &__res__);\n", typeName.c_str());
			break;
		case value_type:
			sprintf_s(buf, "__result__.castToValuePtr(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), (void**)&__res__);\n", typeName.c_str());
			break;
		case reference_type:
			sprintf_s(buf, "__result__.castToReferencePtr(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), (void**)&__res__);\n", typeName.c_str());
			break;
		default:
			assert(false);
		}
		writeStringToFile(buf, file, indentation);
		if(primitive_type == typeCategory || enum_type == typeCategory)
		{
			writeStringToFile("return __res__;\n", file, indentation);
		}
		else
		{
			writeStringToFile("return *__res__;\n", file, indentation);
		}
	}
	else
	{
		switch(typeCategory)
		{
		case void_type:
			sprintf_s(buf, "__result__.castToVoidPtr(&__res__);\n");	
			break;
		case primitive_type:
			sprintf_s(buf, "__result__.castToPrimitivePtr(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), (void**)&__res__);\n", typeName.c_str());
			break;
		case enum_type:
			sprintf_s(buf, "__result__.castToEnumPtr(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), (void**)&__res__);\n", typeName.c_str());
			break;
		case value_type:
			sprintf_s(buf, "__result__.castToValuePtr(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), (void**)&__res__);\n", typeName.c_str());
			break;
		case reference_type:
			sprintf_s(buf, "__result__.castToReferencePtr(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), (void**)&__res__);\n", typeName.c_str());
			break;
		default:
			assert(false);
		}
		writeStringToFile(buf, file, indentation);
		if(methodNode->byNew())
		{
			writeStringToFile("__result__.unhold();\n", file, indentation);		
		}
		if(methodNode->byRef())
		{
			writeStringToFile("return *__res__;\n", file, indentation);
		}
		else
		{
			writeStringToFile("return __res__;\n", file, indentation);
		}
	}
}

void writeInterfaceMethodImpl_CallBaseClass(ClassNode* classNode, MethodNode* methodNode, std::vector<ParameterNode*>& parameterNodes, FILE* file, int indentation)
{
	char buf[512];
	std::string className;
	classNode->getFullName(className, 0);

	writeStringToFile("if(::pafcore::e_not_implemented == __error__)\n", file, indentation);
	writeStringToFile("{\n", file, indentation);

	bool isVoid = (methodNode->m_result->isVoid() && 0 == methodNode->m_passing);
	sprintf_s(buf, "%s%s::%s(", isVoid ? "" : "return ", className.c_str(), methodNode->m_name->m_str.c_str());
	writeStringToFile(buf, file, indentation + 1);
	size_t paramCount = parameterNodes.size();
	for(size_t i = 0; i < paramCount; ++i)
	{
		if(0 != i)
		{
			writeStringToFile(", ", file);
		}
		ParameterNode* parameterNode = parameterNodes[i];
		writeStringToFile(parameterNode->m_name->m_str.c_str(), parameterNode->m_name->m_str.length(), file);
	}
	writeStringToFile(");\n", file);
	if(isVoid)
	{
		writeStringToFile("return;\n", file, indentation + 1);
	}
	writeStringToFile("}\n", file, indentation);
}

void writeInterfaceMethodImpl(ClassNode* classNode, MethodNode* methodNode, FILE* file, int indentation)
{
	char buf[512];
	std::string subclassProxyName;
	GetSubclassProxyFullName(subclassProxyName, classNode);

	std::string resultName;
	if(0 != methodNode->m_resultConst)
	{
		resultName = "const ";
	}
	assert(0 != methodNode->m_result);
	std::string typeName;
	methodNode->m_result->getRelativeName(typeName, methodNode->m_enclosing, 0);
	resultName += typeName;
	if(0 != methodNode->m_passing)
	{
		resultName += g_keywordTokens[methodNode->m_passing->m_nodeType - snt_keyword_begin_output - 1];
	}
	sprintf_s(buf, "%s %s::%s( ", resultName.c_str(), subclassProxyName.c_str(), methodNode->m_name->m_str.c_str());
	writeStringToFile(buf, file, indentation);

	std::vector<ParameterNode*> parameterNodes;
	methodNode->collectParameterNodes(parameterNodes);
	size_t paramCount = parameterNodes.size();
	for(size_t i = 0; i < paramCount; ++i)
	{
		if(0 != i)
		{
			writeStringToFile(", ", file);
		}
		writeMethodParameter(methodNode, parameterNodes[i], file);
	}
	writeStringToFile(")", file);
	if(methodNode->m_constant)
	{
		writeStringToFile(" const", file, indentation);
	}
	writeStringToFile("\n", file);
	writeStringToFile("{\n", file, indentation);

	writeStringToFile("pafcore::Variant __result__, __self__;\n", file, indentation + 1);
	if(0 < paramCount)
	{
		sprintf_s(buf, "pafcore::Variant __args__[%d];\n", paramCount);
		writeStringToFile(buf, file, indentation + 1);
	}

	bool isVoid = (methodNode->m_result->isVoid() && 0 == methodNode->m_passing);
	if(!isVoid)
	{
		writeInterfaceMethodImpl_SetResultType(classNode, methodNode, file, indentation + 1);
	}
	writeInterfaceMethodImpl_AssignThis(classNode, methodNode, file, indentation + 1);
	for(size_t i = 0 ; i < paramCount; ++i)
	{
		ParameterNode* parameterNode = parameterNodes[i];
		if(parameterNode->isInput())
		{
			writeInterfaceMethodImpl_AssignInputParam(classNode, methodNode, parameterNode, i, file, indentation + 1);
		}
		else
		{
			writeInterfaceMethodImpl_SetOutputParamType(classNode, methodNode, parameterNode, i, file, indentation + 1);
		}
	}
	sprintf_s(buf, "::pafcore::ErrorCode __error__ = m_subclassInvoker->invoke(\"%s\", &__result__, &__self__, %s, %d);\n", 
		methodNode->m_name->m_str.c_str(), paramCount > 0 ? "__args__" : "0", paramCount);
	writeStringToFile(buf, file, indentation + 1);

	if(!methodNode->isAbstract() || methodNode->m_enclosing != classNode)
	{
		writeInterfaceMethodImpl_CallBaseClass(classNode, methodNode, parameterNodes, file, indentation + 1);
	}
	for(size_t i = 0 ; i < paramCount; ++i)
	{
		ParameterNode* parameterNode = parameterNodes[i];
		if(parameterNode->isOutput())
		{
			writeInterfaceMethodImpl_CastOutputParam(classNode, methodNode, parameterNode, i, file, indentation + 1);
		}
	}
	if(!isVoid)
	{
		writeInterfaceMethodImpl_CastResult(classNode, methodNode, file, indentation + 1);
	}
	writeStringToFile("}\n\n", file, indentation);
}

void writeInterfaceMethodsImpl(ClassNode* classNode, FILE* file, int indentation)
{
	std::vector<MethodNode*> methodNodes;
	classNode->collectOverrideMethods(methodNodes);
	size_t count = methodNodes.size();
	for(size_t i = 0; i < count; ++i)
	{
		MethodNode* methodNode = methodNodes[i];
		assert(snt_method == methodNode->m_nodeType && methodNode->m_override && methodNode->isVirtual());
		writeInterfaceMethodImpl(classNode, methodNode, file, indentation);
	}
}

void MetaSourceFileGenerator::generateCode_Interface(FILE* file, ClassNode* classNode, TemplateArgumentMap* templateArguments, int indentation)
{
	char buf[512];
	std::string subclassProxyName;
	GetSubclassProxyFullName(subclassProxyName, classNode);

	sprintf_s(buf, "%s::%s(::pafcore::SubclassInvoker* subclassInvoker)\n", subclassProxyName.c_str(), subclassProxyName.c_str());
	writeStringToFile(buf, file, indentation);
	writeStringToFile("{\n", file, indentation);
	writeStringToFile("m_subclassInvoker = subclassInvoker;\n", file, indentation + 1);
	writeStringToFile("}\n\n", file, indentation);

	sprintf_s(buf, "%s::~%s()\n", subclassProxyName.c_str(), subclassProxyName.c_str());
	writeStringToFile(buf, file, indentation);
	writeStringToFile("{\n", file, indentation);
	writeStringToFile("delete m_subclassInvoker;\n", file, indentation + 1);
	writeStringToFile("}\n\n", file, indentation);

	writeInterfaceMethodsImpl(classNode, file, indentation);
}

