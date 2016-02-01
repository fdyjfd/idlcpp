#include "MetaHeaderFileGenerator.h"
#include "HeaderFileGenerator.h"
#include "SourceFile.h"
#include "ProgramNode.h"
#include "NamespaceNode.h"
#include "TokenNode.h"
#include "IdentifyNode.h"
#include "EnumeratorListNode.h"
#include "MemberListNode.h"
#include "EnumNode.h"
#include "ClassNode.h"
#include "TemplateClassInstanceNode.h"
#include "TemplateParametersNode.h"
#include "TypeAliasNode.h"
#include "TypeNameListNode.h"
#include "TypeNameNode.h"
#include "FilterNode.h"
#include "FieldNode.h"
#include "PropertyNode.h"
#include "MethodNode.h"
#include "ParameterNode.h"
#include "ParameterNode.h"
#include "Platform.h"
#include "Options.h"
#include "CommonFuncs.h"
#include <assert.h>
#include <algorithm>


const char g_metaMethodPrefix[] = "static ::pafcore::ErrorCode ";
const char g_metaMethodPostfix[] = "(::pafcore::Variant* result, ::pafcore::Variant** args, int numArgs);\n";

void writeMetaMethodDecl(const char* funcName, FILE* file, int indentation)
{
	writeStringToFile(g_metaMethodPrefix, sizeof(g_metaMethodPrefix) - 1, file, indentation);
	writeStringToFile(funcName, file);
	writeStringToFile(g_metaMethodPostfix, sizeof(g_metaMethodPostfix) - 1, file);
}

void writeMetaMethodDecls(ClassNode* classNode, std::vector<MethodNode*> methodNodes, FILE* file, int indentation)
{
	size_t methodCount = methodNodes.size();
	if(0 < methodCount)
	{
		writeStringToFile("public:\n", file, indentation);
		for(size_t i = 0 ; i < methodCount; ++i)
		{
			char funcName[256];
			if(i > 0 && methodNodes[i]->m_name->m_str == methodNodes[i-1]->m_name->m_str)
			{
				continue;
			}
			sprintf_s(funcName, "%s_%s", classNode->m_name->m_str.c_str(), methodNodes[i]->m_name->m_str.c_str());
			writeMetaMethodDecl(funcName, file, indentation + 1);
		}
	}
}

const char g_metaPropertyDeclPrefix[] = "static ::pafcore::ErrorCode ";
const char g_metaPropertyDeclPostfix[] = "(::pafcore::Variant* that, ::pafcore::Variant* value);\n";
const char g_metaStaticPropertyDeclPostfix[] = "(::pafcore::Variant* value);\n";

void writeMetaPropertyDecl(const char* funcName, bool isStatic, FILE* file, int indentation)
{
	writeStringToFile(g_metaPropertyDeclPrefix, sizeof(g_metaPropertyDeclPrefix) - 1, file, indentation);
	writeStringToFile(funcName, file);
	if(isStatic)
	{
		writeStringToFile(g_metaStaticPropertyDeclPostfix, sizeof(g_metaStaticPropertyDeclPostfix) - 1, file);
	}
	else
	{
		writeStringToFile(g_metaPropertyDeclPostfix, sizeof(g_metaPropertyDeclPostfix) - 1, file);
	}
}

void writeMetaPropertyDecl(ClassNode* classNode, PropertyNode* propertyNode, FILE* file, int indentation)
{
	char funcName[256];
	if(0 != propertyNode->m_get)
	{
		sprintf_s(funcName, "%s_get_%s", classNode->m_name->m_str.c_str(), propertyNode->m_name->m_str.c_str());
		writeMetaPropertyDecl(funcName, propertyNode->isStatic(), file, indentation + 1);
	}		
	if(0 != propertyNode->m_set)
	{
		sprintf_s(funcName, "%s_set_%s", classNode->m_name->m_str.c_str(), propertyNode->m_name->m_str.c_str());
		writeMetaPropertyDecl(funcName, propertyNode->isStatic(), file, indentation + 1);
	}
}

void writeMetaPropertyDecls(ClassNode* classNode, std::vector<PropertyNode*> propertyNodes, FILE* file, int indentation)
{
	size_t propertyCount = propertyNodes.size();
	if(0 < propertyCount)
	{
		writeStringToFile("public:\n", file, indentation);
		for(size_t i = 0 ; i < propertyCount; ++i)
		{
			writeMetaPropertyDecl(classNode, propertyNodes[i], file, indentation);
		}
	}
}

void MetaHeaderFileGenerator::generateCode(FILE* dstFile, SourceFile* sourceFile, const char* fullPathName, const char* baseName)
{
	generateCode_Program(dstFile, sourceFile->m_syntaxTree, fullPathName, baseName);
}

void MetaHeaderFileGenerator::generateCode_Program(FILE* file, ProgramNode* programNode, const char* fileName, const char* cppName)
{
	std::string pafcorePath;
	GetRelativePath(pafcorePath, fileName, g_options.m_pafcorePath.c_str());
	FormatPathForInclude(pafcorePath);

	writeStringToFile("#pragma once\n\n", file);

	if(0 == programNode->m_memberList)
	{
		return;
	}

	char buf[512];
	sprintf_s(buf, "#include \"%s.h\"\n", cppName);
	writeStringToFile(buf, file);
	sprintf_s(buf, "#include \"%sClassType.h\"\n", pafcorePath.c_str());
	writeStringToFile(buf, file);
	sprintf_s(buf, "#include \"%sEnumType.h\"\n", pafcorePath.c_str());
	writeStringToFile(buf, file);
	sprintf_s(buf, "#include \"%sTypeAlias.h\"\n", pafcorePath.c_str());
	writeStringToFile(buf, file);
	sprintf_s(buf, "#include \"%sVariant.h\"\n", pafcorePath.c_str());
	writeStringToFile(buf, file);
	sprintf_s(buf, "#include \"%sSubclassInvoker.h\"\n", pafcorePath.c_str());
	writeStringToFile(buf, file);

	writeStringToFile("\nnamespace idlcpp\n{\n\n", file);
	generateCode_Namespace(file, programNode, 1);
	writeStringToFile("}\n\n", file);

	std::vector<ExportedTypeInfo> typeInfos;
	CollectExportedTypeInfos(typeInfos, programNode);
	std::reverse(typeInfos.begin(), typeInfos.end());
	size_t typeCount = typeInfos.size();

	for(size_t i = 0; i < typeCount; ++i)
	{
		if(snt_type_alias != typeInfos[i].m_typeNode->m_nodeType)
		{
			TypeCategory typeCategory = typeInfos[i].m_typeNode->getTypeCategory();
			const char* typeCategoryName = "";
			switch(typeCategory)
			{
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

			std::string metaTypeName = typeInfos[i].m_typeName;
			std::replace_if(metaTypeName.begin(), metaTypeName.end(), isNotIdentifyChar, '_');
			metaTypeName += g_options.m_metaTypePostfix;
			sprintf_s(buf, "template<>\n"
				"struct RuntimeTypeOf<%s>\n"
				"{\n"
				"\ttypedef ::idlcpp::%s RuntimeType;\n"
				"\tenum {type_category = ::pafcore::%s};\n"
				"};\n\n",
				typeInfos[i].m_typeName.c_str(), metaTypeName.c_str(), typeCategoryName);
			writeStringToFile(buf, file);
		}
	}
}

void MetaHeaderFileGenerator::generateCode_Namespace(FILE* file, NamespaceNode* namespaceNode, int indentation)
{
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
			generateCode_Class(file, static_cast<ClassNode*>(memberNode), indentation);
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

void MetaHeaderFileGenerator::generateCode_Enum(FILE* file, EnumNode* enumNode, int indentation)
{
	char buf[512];
	std::string metaTypeName;
	GetMetaTypeFullName(metaTypeName, enumNode);

	sprintf_s(buf, "class %s : public ::pafcore::EnumType\n",
		metaTypeName.c_str());
	writeStringToFile(buf, file, indentation);
	writeStringToFile("{\n", file, indentation);

	writeStringToFile("public:\n", file, indentation);

	writeStringToFile(metaTypeName.c_str(), metaTypeName.length(), file, indentation + 1);
	writeStringToFile("();\n", file);

	writeStringToFile("public:\n", file, indentation);
	sprintf_s(buf, "%s static %s* GetSingleton();\n", 
		g_options.m_exportMacro.c_str(), metaTypeName.c_str());
	writeStringToFile(buf, file, indentation + 1);
	writeStringToFile("};\n\n", file, indentation);
}

void MetaHeaderFileGenerator::generateCode_Class(FILE* file, ClassNode* classNode, int indentation)
{
	if(0 != classNode->m_templateParameters && 0 == classNode->m_templateArgumentList)
	{
		return;
	}
	char buf[512];
	std::string metaClassName;
	GetMetaTypeFullName(metaClassName, classNode);

	sprintf_s(buf, "class %s : public ::pafcore::ClassType\n",
		metaClassName.c_str());
	writeStringToFile(buf, file, indentation);
	writeStringToFile("{\n", file, indentation);

	bool generateCode = true;
	std::vector<MemberNode*> memberNodes;
	std::vector<MethodNode*> methodNodes;
	std::vector<MethodNode*> staticMethodNodes;
	std::vector<PropertyNode*> propertyNodes;
	std::vector<PropertyNode*> staticPropertyNodes;
	std::vector<MemberNode*> subTypeNodes;

	classNode->m_memberList->collectMemberNodes(memberNodes);
	size_t memberCount = memberNodes.size();
	for(size_t i = 0; i < memberCount; ++i)
	{
		MemberNode* memberNode = memberNodes[i];
		if(snt_filter == memberNode->m_nodeType)
		{
			generateCode = static_cast<FilterNode*>(memberNode)->m_meta;
			continue;
		}
		if(generateCode)
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
			else if(snt_enum == memberNode->m_nodeType ||
				snt_class == memberNode->m_nodeType)
			{
				subTypeNodes.push_back(memberNode);
			}
		}
	}
	
	if(!classNode->isAbstractClass())
	{
		staticMethodNodes.insert(staticMethodNodes.end(), classNode->m_additionalMethods.begin(), classNode->m_additionalMethods.end());
	}

	std::sort(propertyNodes.begin(), propertyNodes.end(), CompareMemberNodeByName());
	std::sort(methodNodes.begin(), methodNodes.end(), CompareMemberNodeByName());
	std::sort(staticPropertyNodes.begin(), staticPropertyNodes.end(), CompareMemberNodeByName());
	std::sort(staticMethodNodes.begin(), staticMethodNodes.end(), CompareMemberNodeByName());


	writeStringToFile("public:\n", file, indentation);
	writeStringToFile(metaClassName.c_str(), metaClassName.length(), file, indentation + 1);
	writeStringToFile("();\n", file);

	writeStringToFile("public:\n", file, indentation);
	writeStringToFile("virtual void destroyInstance(void* address);\n", file, indentation + 1);
	writeStringToFile("virtual void destroyArray(void* address);\n", file, indentation + 1);
	writeStringToFile("virtual void assign(void* dst, const void* src);\n", file, indentation + 1);
	
	if(classNode->needExport())
	{
		writeStringToFile("public:\n", file, indentation);
		writeStringToFile("virtual void* createSubclassProxy(::pafcore::SubclassInvoker* subclassInvoker);\n", file, indentation + 1);
		writeStringToFile("virtual void destroySubclassProxy(void* subclassProxy);\n", file, indentation + 1);
	}
	writeMetaPropertyDecls(classNode, propertyNodes, file, indentation);
	writeMetaMethodDecls(classNode, methodNodes, file, indentation);
	writeMetaPropertyDecls(classNode, staticPropertyNodes, file, indentation);
	writeMetaMethodDecls(classNode, staticMethodNodes, file, indentation);


	writeStringToFile("public:\n", file, indentation);
	sprintf_s(buf, "%s static %s* GetSingleton();\n", 
		g_options.m_exportMacro.c_str(), metaClassName.c_str());
	writeStringToFile(buf, file, indentation + 1);
	writeStringToFile("};\n\n", file, indentation);

	if(classNode->needExport())
	{
		generateCode_Interface(file, classNode, indentation);
	}

	size_t subTypeCount = subTypeNodes.size();
	for(size_t i = 0; i < subTypeCount; ++i)
	{
		MemberNode* typeNode = subTypeNodes[i];
		switch (typeNode->m_nodeType)
		{
		case snt_enum:
			generateCode_Enum(file, static_cast<EnumNode*>(typeNode), indentation);
			break;
		case snt_class:
			generateCode_Class(file, static_cast<ClassNode*>(typeNode), indentation);
			break;
		default:
			assert(false);
		}
	}
}

void writeMethodParameter(MethodNode* methodNode, ParameterNode* parameterNode, FILE* file)
{
	std::string typeName;
	ClassNode* classNode = static_cast<ClassNode*>(methodNode->m_enclosing);
	if(parameterNode->m_constant)
	{
		writeStringToFile("const ", file);
	}
	parameterNode->m_type->getRelativeName(typeName, methodNode->m_enclosing, 0);
	writeStringToFile(typeName.c_str(), file);
	if(0 != parameterNode->m_out)
	{
		writeStringToFile(g_keywordTokens[parameterNode->m_out->m_nodeType - snt_keyword_begin_output - 1], file);
	}
	if(0 != parameterNode->m_passing)
	{
		writeStringToFile(g_keywordTokens[parameterNode->m_passing->m_nodeType - snt_keyword_begin_output - 1], file);
	}
	writeStringToFile(g_strSpaces, 1, file);
	writeStringToFile(parameterNode->m_name->m_str.c_str(), file);
};

void writeInterfaceMethodDecl(MethodNode* methodNode, FILE* file, int indentation)
{
	char buf[512];
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
	sprintf_s(buf, "%s %s( ", resultName.c_str(), methodNode->m_name->m_str.c_str());
	writeStringToFile(buf, file, indentation);

	std::vector<ParameterNode*> parameterNodes;
	methodNode->collectParameterNodes(parameterNodes);
	size_t parameterCount = parameterNodes.size();
	for(size_t i = 0; i < parameterCount; ++i)
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
	writeStringToFile(";\n", file);
}


void writeInterfaceMethodsDecl(ClassNode* classNode, FILE* file, int indentation)
{
	std::vector<MethodNode*> methodNodes;
	classNode->collectExportMethods(methodNodes);
	size_t count = methodNodes.size();
	for(size_t i = 0; i < count; ++i)
	{
		MethodNode* methodNode = methodNodes[i];
		assert(snt_method == methodNode->m_nodeType && methodNode->m_export && methodNode->isVirtual());
		writeInterfaceMethodDecl(methodNode, file, indentation);
	}
}

void MetaHeaderFileGenerator::generateCode_Interface(FILE* file, ClassNode* classNode, int indentation)
{
	char buf[512];
	std::string className;
	classNode->getFullName(className, 0);
	std::string subclassProxyName;
	GetSubclassProxyFullName(subclassProxyName, classNode);
	
	sprintf_s(buf, "class %s : public %s\n", subclassProxyName.c_str(), className.c_str());
	writeStringToFile(buf, file, indentation);
	writeStringToFile("{\n", file, indentation);
	writeStringToFile("::pafcore::SubclassInvoker* m_subclassInvoker;\n", file, indentation + 1);
	writeStringToFile("public:\n", file, indentation);
	sprintf_s(buf, "%s(::pafcore::SubclassInvoker* subclassInvoker);\n", subclassProxyName.c_str());
	writeStringToFile(buf, file, indentation + 1);
	sprintf_s(buf, "~%s();\n", subclassProxyName.c_str());
	writeStringToFile(buf, file, indentation + 1);
	writeInterfaceMethodsDecl(classNode, file, indentation + 1);
	writeStringToFile("};\n\n", file, indentation);

}

void MetaHeaderFileGenerator::generateCode_TemplateClassInstance(FILE* file, TemplateClassInstanceNode* templateClassInstance, int indentation)
{
	assert(0 != templateClassInstance->m_templateTypeNameNode->m_typeInfo
			&& snt_class == templateClassInstance->m_templateTypeNameNode->m_typeInfo->m_typeNode->m_nodeType);
	ClassNode* classNode = static_cast<ClassNode*>(templateClassInstance->m_templateTypeNameNode->m_typeInfo->m_typeNode);
	assert(0 != classNode->m_templateParameters);
	assert(classNode->m_templateParameters->getParameterCount() == templateClassInstance->getParameterCount());

	TypeNameListNode* oldTemplateArgumentList = classNode->setTemplateArgumentList(templateClassInstance->m_parameterList);
	generateCode_Class(file, classNode, indentation);
	classNode->setTemplateArgumentList(oldTemplateArgumentList);
}

void MetaHeaderFileGenerator::generateCode_TypeAlias(FILE* file, TypeAliasNode* typeAliasNode, int indentation)
{
	char buf[512];
	std::string metaTypeName;
	GetMetaTypeFullName(metaTypeName, typeAliasNode);

	sprintf_s(buf, "class %s : public ::pafcore::TypeAlias\n",
		metaTypeName.c_str());
	writeStringToFile(buf, file, indentation);
	writeStringToFile("{\n", file, indentation);

	writeStringToFile("public:\n", file, indentation);

	writeStringToFile(metaTypeName.c_str(), metaTypeName.length(), file, indentation + 1);
	writeStringToFile("();\n", file);

	writeStringToFile("public:\n", file, indentation);
	sprintf_s(buf, "%s static %s* GetSingleton();\n", 
		g_options.m_exportMacro.c_str(), metaTypeName.c_str());
	writeStringToFile(buf, file, indentation + 1);
	writeStringToFile("};\n\n", file, indentation);
}

