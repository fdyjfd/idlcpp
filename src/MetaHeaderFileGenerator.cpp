#include "MetaHeaderFileGenerator.h"
#include "Utility.h"
#include "SourceFile.h"
#include "HeaderFileGenerator.h"
#include "ProgramNode.h"
#include "NamespaceNode.h"
#include "TokenNode.h"
#include "IdentifyNode.h"
#include "EnumeratorListNode.h"
#include "MemberListNode.h"
#include "EnumNode.h"
#include "DelegateNode.h"
#include "ClassNode.h"
#include "TemplateClassInstanceNode.h"
#include "TemplateParametersNode.h"
#include "TypedefNode.h"
#include "typeDeclarationNode.h"
#include "TypeNameListNode.h"
#include "TypeNameNode.h"
#include "FieldNode.h"
#include "PropertyNode.h"
#include "MethodNode.h"
#include "OperatorNode.h"
#include "ParameterNode.h"
#include "ParameterListNode.h"
#include "TypeTree.h"
#include "Platform.h"
#include "Options.h"
#include "CommonFuncs.h"
#include "Compiler.h"
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

const char g_metaPropertyDeclPostfix[] = "(::pafcore::InstanceProperty* instanceProperty, ::pafcore::Variant* that, ::pafcore::Variant* value);\n";
const char g_metaArrayPropertyDeclPostfix[] = "(::pafcore::InstanceProperty* instanceProperty, ::pafcore::Variant* that, size_t index, ::pafcore::Variant* value);\n";
const char g_metaMapPropertyDeclPostfix[] = "(::pafcore::InstanceProperty* instanceProperty, ::pafcore::Variant* that, ::pafcore::Variant* key, ::pafcore::Variant* value);\n";

const char g_metaPropertyDeclCandidateCountPostfix[] = "(::pafcore::InstanceProperty* instanceProperty, ::pafcore::Variant* that, ::pafcore::Variant* value);\n";
const char g_metaPropertyDeclGetCandidatePostfix[] = "(::pafcore::InstanceProperty* instanceProperty, ::pafcore::Variant* that, size_t index, ::pafcore::Variant* value);\n";

const char g_metaArrayPropertyDeclSizePostfix[] = "(::pafcore::InstanceProperty* instanceProperty, ::pafcore::Variant* that, ::pafcore::Variant* value);\n";
const char g_metaArrayPropertyDeclResizePostfix[] = "(::pafcore::InstanceProperty* instanceProperty, ::pafcore::Variant* that, ::pafcore::Variant* value);\n";

const char g_metaPropertyDeclPushBackPostfix[] = "(::pafcore::InstanceProperty* instanceProperty, ::pafcore::Variant* that, ::pafcore::Variant* value);\n";
const char g_metaPropertyDeclGetIteratorPostfix[] = "(::pafcore::InstanceProperty* instanceProperty, ::pafcore::Variant* that, ::pafcore::Variant* iterator);\n";
const char g_metaPropertyDeclGetKeyPostfix[] = "(::pafcore::InstanceProperty* instanceProperty, ::pafcore::Variant* that, ::pafcore::Iterator* iterator, ::pafcore::Variant* key);\n";
const char g_metaPropertyDeclGetValuePostfix[] = "(::pafcore::InstanceProperty* instanceProperty, ::pafcore::Variant* that, ::pafcore::Iterator* iterator, ::pafcore::Variant* value);\n";
const char g_metaPropertyDeclInsertPostfix[] = "(::pafcore::InstanceProperty* instanceProperty, ::pafcore::Variant* that, ::pafcore::Iterator* iterator, ::pafcore::Variant* value);\n";
const char g_metaPropertyDeclErasePostfix[] = "(::pafcore::InstanceProperty* instanceProperty, ::pafcore::Variant* that, ::pafcore::Iterator* iterator);\n";

const char g_metaStaticPropertyDeclPostfix[] = "(::pafcore::Variant* value);\n";
const char g_metaStaticArrayPropertyDeclPostfix[] = "(size_t index, ::pafcore::Variant* value);\n";
const char g_metaStaticMapPropertyDeclPostfix[] = "(::pafcore::Variant* key, ::pafcore::Variant* value);\n";

const char g_metaStaticPropertyDeclCandidateCountPostfix[] = "(::pafcore::Variant* value);\n";
const char g_metaStaticPropertyDeclGetCandidatePostfix[] = "(size_t index, ::pafcore::Variant* value);\n";

const char g_metaStaticArrayPropertyDeclSizePostfix[] = "(::pafcore::Variant* value);\n";
const char g_metaStaticArrayPropertyDeclResizePostfix[] = "(::pafcore::Variant* value);\n";

const char g_metaStaticPropertyDeclPushBackPostfix[] = "(::pafcore::Variant* value);\n";
const char g_metaStaticPropertyDeclGetIteratorPostfix[] = "(::pafcore::Variant* iterator);\n";
const char g_metaStaticPropertyDeclGetKeyPostfix[] = "(::pafcore::Iterator* iterator, ::pafcore::Variant* key);\n";
const char g_metaStaticPropertyDeclGetValuePostfix[] = "(::pafcore::Iterator* iterator, ::pafcore::Variant* value);\n";
const char g_metaStaticPropertyDeclInsertPostfix[] = "(::pafcore::Iterator* iterator, ::pafcore::Variant* value);\n";
const char g_metaStaticPropertyDeclErasePostfix[] = "(::pafcore::Iterator* iterator);\n";



void writeMetaPropertyDeclGetSet(const char* funcName, bool isStatic, PropertyCategory category, FILE* file, int indentation)
{
	writeStringToFile(g_metaPropertyDeclPrefix, sizeof(g_metaPropertyDeclPrefix) - 1, file, indentation);
	writeStringToFile(funcName, file);
	if(isStatic)
	{
		switch (category)
		{
		case simple_property:
			writeStringToFile(g_metaStaticPropertyDeclPostfix, sizeof(g_metaStaticPropertyDeclPostfix) - 1, file);
			break;
		case fixed_array_property:
		case dynamic_array_property:
		case list_property:
			writeStringToFile(g_metaStaticArrayPropertyDeclPostfix, sizeof(g_metaStaticArrayPropertyDeclPostfix) - 1, file);
			break;
		case map_property:
			writeStringToFile(g_metaStaticMapPropertyDeclPostfix, sizeof(g_metaStaticMapPropertyDeclPostfix) - 1, file);
			break;
		}
	}
	else
	{
		switch (category)
		{
		case simple_property:
			writeStringToFile(g_metaPropertyDeclPostfix, sizeof(g_metaPropertyDeclPostfix) - 1, file);
			break;
		case fixed_array_property:
		case dynamic_array_property:
		case list_property:
			writeStringToFile(g_metaArrayPropertyDeclPostfix, sizeof(g_metaArrayPropertyDeclPostfix) - 1, file);
			break;
		case map_property:
			writeStringToFile(g_metaMapPropertyDeclPostfix, sizeof(g_metaMapPropertyDeclPostfix) - 1, file);
			break;
		}
	}
}

void writeMetaPropertyDecl(ClassNode* classNode, PropertyNode* propertyNode, FILE* file, int indentation)
{
	char funcName[256];
	if(0 != propertyNode->m_get)
	{
		sprintf_s(funcName, "%s_get_%s", classNode->m_name->m_str.c_str(), propertyNode->m_name->m_str.c_str());
		writeMetaPropertyDeclGetSet(funcName, propertyNode->isStatic(), propertyNode->getCategory(), file, indentation + 1);
	}		
	if(0 != propertyNode->m_set)
	{
		sprintf_s(funcName, "%s_set_%s", classNode->m_name->m_str.c_str(), propertyNode->m_name->m_str.c_str());
		writeMetaPropertyDeclGetSet(funcName, propertyNode->isStatic(), propertyNode->getCategory(), file, indentation + 1);
	}
	if (propertyNode->isSimple())
	{
		if (propertyNode->hasCandidate())
		{
			if (propertyNode->isStatic())
			{
				sprintf_s(funcName, "%s_candidateCount_%s", classNode->m_name->m_str.c_str(), propertyNode->m_name->m_str.c_str());
				writeStringToFile(g_metaPropertyDeclPrefix, sizeof(g_metaPropertyDeclPrefix) - 1, file, indentation + 1);
				writeStringToFile(funcName, file);
				writeStringToFile(g_metaStaticPropertyDeclCandidateCountPostfix, sizeof(g_metaStaticPropertyDeclCandidateCountPostfix) - 1, file);

				sprintf_s(funcName, "%s_getCandidate_%s", classNode->m_name->m_str.c_str(), propertyNode->m_name->m_str.c_str());
				writeStringToFile(g_metaPropertyDeclPrefix, sizeof(g_metaPropertyDeclPrefix) - 1, file, indentation + 1);
				writeStringToFile(funcName, file);
				writeStringToFile(g_metaStaticPropertyDeclGetCandidatePostfix, sizeof(g_metaStaticPropertyDeclGetCandidatePostfix) - 1, file);
			}
			else
			{
				sprintf_s(funcName, "%s_candidateCount_%s", classNode->m_name->m_str.c_str(), propertyNode->m_name->m_str.c_str());
				writeStringToFile(g_metaPropertyDeclPrefix, sizeof(g_metaPropertyDeclPrefix) - 1, file, indentation + 1);
				writeStringToFile(funcName, file);
				writeStringToFile(g_metaPropertyDeclCandidateCountPostfix, sizeof(g_metaPropertyDeclCandidateCountPostfix) - 1, file);

				sprintf_s(funcName, "%s_getCandidate_%s", classNode->m_name->m_str.c_str(), propertyNode->m_name->m_str.c_str());
				writeStringToFile(g_metaPropertyDeclPrefix, sizeof(g_metaPropertyDeclPrefix) - 1, file, indentation + 1);
				writeStringToFile(funcName, file);
				writeStringToFile(g_metaPropertyDeclGetCandidatePostfix, sizeof(g_metaPropertyDeclGetCandidatePostfix) - 1, file);
			}
		}
	}
	else if(propertyNode->isFixedArray() || propertyNode->isDynamicArray())
	{
		sprintf_s(funcName, "%s_size_%s", classNode->m_name->m_str.c_str(), propertyNode->m_name->m_str.c_str());
		writeStringToFile(g_metaPropertyDeclPrefix, sizeof(g_metaPropertyDeclPrefix) - 1, file, indentation + 1);
		writeStringToFile(funcName, file);
		if (propertyNode->isStatic())
		{
			writeStringToFile(g_metaStaticArrayPropertyDeclSizePostfix, sizeof(g_metaStaticArrayPropertyDeclSizePostfix) - 1, file);
		}
		else
		{
			writeStringToFile(g_metaArrayPropertyDeclSizePostfix, sizeof(g_metaArrayPropertyDeclSizePostfix) - 1, file);
		}
		if (propertyNode->isDynamicArray())
		{
			sprintf_s(funcName, "%s_resize_%s", classNode->m_name->m_str.c_str(), propertyNode->m_name->m_str.c_str());
			writeStringToFile(g_metaPropertyDeclPrefix, sizeof(g_metaPropertyDeclPrefix) - 1, file, indentation + 1);
			writeStringToFile(funcName, file);
			if (propertyNode->isStatic())
			{
				writeStringToFile(g_metaStaticArrayPropertyDeclResizePostfix, sizeof(g_metaStaticArrayPropertyDeclResizePostfix) - 1, file);
			}
			else
			{
				writeStringToFile(g_metaArrayPropertyDeclResizePostfix, sizeof(g_metaArrayPropertyDeclResizePostfix) - 1, file);
			}
		}
		if (propertyNode->isStatic())
		{
			sprintf_s(funcName, "%s_getIterator_%s", classNode->m_name->m_str.c_str(), propertyNode->m_name->m_str.c_str());
			writeStringToFile(g_metaPropertyDeclPrefix, sizeof(g_metaPropertyDeclPrefix) - 1, file, indentation + 1);
			writeStringToFile(funcName, file);
			writeStringToFile(g_metaStaticPropertyDeclGetIteratorPostfix, sizeof(g_metaStaticPropertyDeclGetIteratorPostfix) - 1, file);

			sprintf_s(funcName, "%s_getValue_%s", classNode->m_name->m_str.c_str(), propertyNode->m_name->m_str.c_str());
			writeStringToFile(g_metaPropertyDeclPrefix, sizeof(g_metaPropertyDeclPrefix) - 1, file, indentation + 1);
			writeStringToFile(funcName, file);
			writeStringToFile(g_metaStaticPropertyDeclGetValuePostfix, sizeof(g_metaStaticPropertyDeclGetValuePostfix) - 1, file);
		}
		else
		{
			sprintf_s(funcName, "%s_getIterator_%s", classNode->m_name->m_str.c_str(), propertyNode->m_name->m_str.c_str());
			writeStringToFile(g_metaPropertyDeclPrefix, sizeof(g_metaPropertyDeclPrefix) - 1, file, indentation + 1);
			writeStringToFile(funcName, file);
			writeStringToFile(g_metaPropertyDeclGetIteratorPostfix, sizeof(g_metaPropertyDeclGetIteratorPostfix) - 1, file);

			sprintf_s(funcName, "%s_getValue_%s", classNode->m_name->m_str.c_str(), propertyNode->m_name->m_str.c_str());
			writeStringToFile(g_metaPropertyDeclPrefix, sizeof(g_metaPropertyDeclPrefix) - 1, file, indentation + 1);
			writeStringToFile(funcName, file);
			writeStringToFile(g_metaPropertyDeclGetValuePostfix, sizeof(g_metaPropertyDeclGetValuePostfix) - 1, file);
		}
	}
	else if (propertyNode->isList())
	{
		if (propertyNode->isStatic())
		{
			sprintf_s(funcName, "%s_pushBack_%s", classNode->m_name->m_str.c_str(), propertyNode->m_name->m_str.c_str());
			writeStringToFile(g_metaPropertyDeclPrefix, sizeof(g_metaPropertyDeclPrefix) - 1, file, indentation + 1);
			writeStringToFile(funcName, file);
			writeStringToFile(g_metaStaticPropertyDeclPushBackPostfix, sizeof(g_metaStaticPropertyDeclPushBackPostfix) - 1, file);

			sprintf_s(funcName, "%s_getIterator_%s", classNode->m_name->m_str.c_str(), propertyNode->m_name->m_str.c_str());
			writeStringToFile(g_metaPropertyDeclPrefix, sizeof(g_metaPropertyDeclPrefix) - 1, file, indentation + 1);
			writeStringToFile(funcName, file);
			writeStringToFile(g_metaStaticPropertyDeclGetIteratorPostfix, sizeof(g_metaStaticPropertyDeclGetIteratorPostfix) - 1, file);

			sprintf_s(funcName, "%s_getValue_%s", classNode->m_name->m_str.c_str(), propertyNode->m_name->m_str.c_str());
			writeStringToFile(g_metaPropertyDeclPrefix, sizeof(g_metaPropertyDeclPrefix) - 1, file, indentation + 1);
			writeStringToFile(funcName, file);
			writeStringToFile(g_metaStaticPropertyDeclGetValuePostfix, sizeof(g_metaStaticPropertyDeclGetValuePostfix) - 1, file);

			sprintf_s(funcName, "%s_insert_%s", classNode->m_name->m_str.c_str(), propertyNode->m_name->m_str.c_str());
			writeStringToFile(g_metaPropertyDeclPrefix, sizeof(g_metaPropertyDeclPrefix) - 1, file, indentation + 1);
			writeStringToFile(funcName, file);
			writeStringToFile(g_metaStaticPropertyDeclInsertPostfix, sizeof(g_metaStaticPropertyDeclInsertPostfix) - 1, file);

			sprintf_s(funcName, "%s_erase_%s", classNode->m_name->m_str.c_str(), propertyNode->m_name->m_str.c_str());
			writeStringToFile(g_metaPropertyDeclPrefix, sizeof(g_metaPropertyDeclPrefix) - 1, file, indentation + 1);
			writeStringToFile(funcName, file);
			writeStringToFile(g_metaStaticPropertyDeclErasePostfix, sizeof(g_metaStaticPropertyDeclErasePostfix) - 1, file);
		}
		else
		{
			sprintf_s(funcName, "%s_pushBack_%s", classNode->m_name->m_str.c_str(), propertyNode->m_name->m_str.c_str());
			writeStringToFile(g_metaPropertyDeclPrefix, sizeof(g_metaPropertyDeclPrefix) - 1, file, indentation + 1);
			writeStringToFile(funcName, file);
			writeStringToFile(g_metaPropertyDeclPushBackPostfix, sizeof(g_metaPropertyDeclPushBackPostfix) - 1, file);

			sprintf_s(funcName, "%s_getIterator_%s", classNode->m_name->m_str.c_str(), propertyNode->m_name->m_str.c_str());
			writeStringToFile(g_metaPropertyDeclPrefix, sizeof(g_metaPropertyDeclPrefix) - 1, file, indentation + 1);
			writeStringToFile(funcName, file);
			writeStringToFile(g_metaPropertyDeclGetIteratorPostfix, sizeof(g_metaPropertyDeclGetIteratorPostfix) - 1, file);

			sprintf_s(funcName, "%s_getValue_%s", classNode->m_name->m_str.c_str(), propertyNode->m_name->m_str.c_str());
			writeStringToFile(g_metaPropertyDeclPrefix, sizeof(g_metaPropertyDeclPrefix) - 1, file, indentation + 1);
			writeStringToFile(funcName, file);
			writeStringToFile(g_metaPropertyDeclGetValuePostfix, sizeof(g_metaPropertyDeclGetValuePostfix) - 1, file);

			sprintf_s(funcName, "%s_insert_%s", classNode->m_name->m_str.c_str(), propertyNode->m_name->m_str.c_str());
			writeStringToFile(g_metaPropertyDeclPrefix, sizeof(g_metaPropertyDeclPrefix) - 1, file, indentation + 1);
			writeStringToFile(funcName, file);
			writeStringToFile(g_metaPropertyDeclInsertPostfix, sizeof(g_metaPropertyDeclInsertPostfix) - 1, file);

			sprintf_s(funcName, "%s_erase_%s", classNode->m_name->m_str.c_str(), propertyNode->m_name->m_str.c_str());
			writeStringToFile(g_metaPropertyDeclPrefix, sizeof(g_metaPropertyDeclPrefix) - 1, file, indentation + 1);
			writeStringToFile(funcName, file);
			writeStringToFile(g_metaPropertyDeclErasePostfix, sizeof(g_metaPropertyDeclErasePostfix) - 1, file);
		}
	}
	else if (propertyNode->isMap())
	{
		if (propertyNode->isStatic())
		{
			sprintf_s(funcName, "%s_getIterator_%s", classNode->m_name->m_str.c_str(), propertyNode->m_name->m_str.c_str());
			writeStringToFile(g_metaPropertyDeclPrefix, sizeof(g_metaPropertyDeclPrefix) - 1, file, indentation + 1);
			writeStringToFile(funcName, file);
			writeStringToFile(g_metaStaticPropertyDeclGetIteratorPostfix, sizeof(g_metaStaticPropertyDeclGetIteratorPostfix) - 1, file);

			sprintf_s(funcName, "%s_getKey_%s", classNode->m_name->m_str.c_str(), propertyNode->m_name->m_str.c_str());
			writeStringToFile(g_metaPropertyDeclPrefix, sizeof(g_metaPropertyDeclPrefix) - 1, file, indentation + 1);
			writeStringToFile(funcName, file);
			writeStringToFile(g_metaStaticPropertyDeclGetKeyPostfix, sizeof(g_metaStaticPropertyDeclGetKeyPostfix) - 1, file);

			sprintf_s(funcName, "%s_getValue_%s", classNode->m_name->m_str.c_str(), propertyNode->m_name->m_str.c_str());
			writeStringToFile(g_metaPropertyDeclPrefix, sizeof(g_metaPropertyDeclPrefix) - 1, file, indentation + 1);
			writeStringToFile(funcName, file);
			writeStringToFile(g_metaStaticPropertyDeclGetValuePostfix, sizeof(g_metaStaticPropertyDeclGetValuePostfix) - 1, file);
		}
		else
		{
			sprintf_s(funcName, "%s_getIterator_%s", classNode->m_name->m_str.c_str(), propertyNode->m_name->m_str.c_str());
			writeStringToFile(g_metaPropertyDeclPrefix, sizeof(g_metaPropertyDeclPrefix) - 1, file, indentation + 1);
			writeStringToFile(funcName, file);
			writeStringToFile(g_metaPropertyDeclGetIteratorPostfix, sizeof(g_metaPropertyDeclGetIteratorPostfix) - 1, file);

			sprintf_s(funcName, "%s_getKey_%s", classNode->m_name->m_str.c_str(), propertyNode->m_name->m_str.c_str());
			writeStringToFile(g_metaPropertyDeclPrefix, sizeof(g_metaPropertyDeclPrefix) - 1, file, indentation + 1);
			writeStringToFile(funcName, file);
			writeStringToFile(g_metaPropertyDeclGetKeyPostfix, sizeof(g_metaPropertyDeclGetKeyPostfix) - 1, file);

			sprintf_s(funcName, "%s_getValue_%s", classNode->m_name->m_str.c_str(), propertyNode->m_name->m_str.c_str());
			writeStringToFile(g_metaPropertyDeclPrefix, sizeof(g_metaPropertyDeclPrefix) - 1, file, indentation + 1);
			writeStringToFile(funcName, file);
			writeStringToFile(g_metaPropertyDeclGetValuePostfix, sizeof(g_metaPropertyDeclGetValuePostfix) - 1, file);
		}
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
	generateCode_Program(dstFile, sourceFile, sourceFile->m_syntaxTree, fullPathName, baseName);
}

void MetaHeaderFileGenerator::generateCode_Program(FILE* file, SourceFile* sourceFile, ProgramNode* programNode, const char* fileName, const char* cppName)
{
	char buf[4096];
	std::string pafcorePath;
	GetRelativePath(pafcorePath, fileName, g_options.m_pafcorePath.c_str());
	FormatPathForInclude(pafcorePath);

	writeStringToFile("#pragma once\n\n", file);

	if(0 == programNode->m_memberList)
	{
		return;
	}

	g_compiler.outputUsedTypesForMetaHeader(file, sourceFile);
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


	std::vector<TypeNode*> typeNodes;
	CollectTypeNodes(typeNodes, programNode);
	std::reverse(typeNodes.begin(), typeNodes.end());
	size_t typeCount = typeNodes.size();

	for(size_t i = 0; i < typeCount; ++i)
	{
		TypeNode* typeNode = typeNodes[i];
		if(!typeNode->isTypedef() 
			&& !typeNode->isTypeDeclaration()
			&& typeNode->getSyntaxNode()->canGenerateMetaCode())
		{
			TypeCategory typeCategory = typeNode->getTypeCategory(0);
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

			std::string typeName;
			typeNode->getNativeName(typeName);
			std::string metaTypeName;
			GetMetaTypeFullName(metaTypeName, typeNode);
			sprintf_s(buf, "template<>\n"
				"struct RuntimeTypeOf<%s>\n"
				"{\n"
				"\ttypedef ::idlcpp::%s RuntimeType;\n"
				"\tenum {type_category = ::pafcore::%s};\n"
				"};\n\n",
				typeName.c_str(), metaTypeName.c_str(), typeCategoryName);
			writeStringToFile(buf, file);
		}
	}
}

void MetaHeaderFileGenerator::generateCode_Namespace(FILE* file, NamespaceNode* namespaceNode, int indentation)
{
	if (namespaceNode->isNoMeta())
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
			generateCode_Enum(file, static_cast<EnumNode*>(memberNode), 0, indentation);
			break;
		case snt_class:
			if (!memberNode->isTemplateClass())
			{
				generateCode_Class(file, static_cast<ClassNode*>(memberNode), 0, indentation);
			}
			break;
		case snt_delegate:
			generateCode_Delegate(file, static_cast<DelegateNode*>(memberNode), 0, indentation);
			break;
		case snt_namespace:
			generateCode_Namespace(file, static_cast<NamespaceNode*>(memberNode), indentation);
			break;
		case snt_template_class_instance:
			generateCode_TemplateClassInstance(file, static_cast<TemplateClassInstanceNode*>(memberNode), indentation);
			break;
		case snt_typedef:
			generateCode_Typedef(file, static_cast<TypedefNode*>(memberNode), 0, indentation);
			break;
		case snt_type_declaration:
			generateCode_TypeDeclaration(file, static_cast<TypeDeclarationNode*>(memberNode), 0, indentation);
			break;
		default:
			assert(false);
		}
	}
}


void MetaHeaderFileGenerator::generateCode_Enum(FILE* file, EnumNode* enumNode, TemplateArguments* templateArguments, int indentation)
{
	if (enumNode->isNoMeta())
	{
		return;
	}

	char buf[4096];
	std::string metaTypeName;
	GetMetaTypeFullName(metaTypeName, enumNode, templateArguments);

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

void MetaHeaderFileGenerator::generateCode_Delegate(FILE* file, DelegateNode* delegateNode, TemplateArguments* templateArguments, int indentation)
{
	if (delegateNode->isNoMeta())
	{
		return;
	}
	generateCode_Class(file, delegateNode->m_classNode, 0, indentation);
}

void MetaHeaderFileGenerator::generateCode_Class(FILE* file, ClassNode* classNode, TemplateClassInstanceNode* templateClassInstance, int indentation)
{
	if (classNode->isNoMeta())
	{
		return;
	}
	TemplateArguments* templateArguments = templateClassInstance ? &templateClassInstance->m_templateArguments : 0;

	std::vector<IdentifyNode*> reservedNames;
	std::vector<TokenNode*> reservedOperators;
	if (templateClassInstance && templateClassInstance->m_tokenList
		&& templateClassInstance->m_classTypeNode->m_classNode == classNode)
	{
		assert(classNode->m_typeNode == templateClassInstance->m_classTypeNode);
		templateClassInstance->getReservedMembers(reservedNames, reservedOperators);
	}
	bool hasReservedMember = (!reservedNames.empty() || !reservedOperators.empty());

	char buf[4096];
	std::string metaClassName;
	GetMetaTypeFullName(metaClassName, classNode, templateArguments);

	sprintf_s(buf, "class %s : public ::pafcore::ClassType\n",
		metaClassName.c_str());
	writeStringToFile(buf, file, indentation);
	writeStringToFile("{\n", file, indentation);

	std::vector<MemberNode*> memberNodes;
	std::vector<MethodNode*> methodNodes;
	std::vector<MethodNode*> staticMethodNodes;
	std::vector<MethodNode*> typeMethodNodes;
	std::vector<PropertyNode*> propertyNodes;
	std::vector<PropertyNode*> staticPropertyNodes;
	std::vector<MemberNode*> subTypeNodes;

	classNode->m_memberList->collectMemberNodes(memberNodes);
	size_t memberCount = memberNodes.size();
	for(size_t i = 0; i < memberCount; ++i)
	{
		MemberNode* memberNode = memberNodes[i];
		if (hasReservedMember)
		{
			if (snt_method == memberNode->m_nodeType || snt_property == memberNode->m_nodeType)
			{
				if (!std::binary_search(reservedNames.begin(), reservedNames.end(), memberNode->m_name, CompareIdentifyPtr()))
				{
					continue;
				}
			}	
			if (snt_operator == memberNode->m_nodeType)
			{
				OperatorNode* operatorNode = static_cast<OperatorNode*>(memberNode);
				if (!std::binary_search(reservedOperators.begin(), reservedOperators.end(), operatorNode->m_sign, CompareTokenPtr()))
				{
					continue;
				}
			}
		}

		if(!memberNode->isNoMeta())
		{
			if(snt_method == memberNode->m_nodeType || snt_operator == memberNode->m_nodeType)
			{
				MethodNode* methodNode = static_cast<MethodNode*>(memberNode);
				if(memberNode->m_name->m_str != classNode->m_name->m_str)
				{
					if(methodNode->isStatic())
					{
						if (methodNode->m_name->m_str == "__destroyInstance__"
							|| methodNode->m_name->m_str == "__destroyArray__"
							|| methodNode->m_name->m_str == "__assign__")
						{
							typeMethodNodes.push_back(methodNode);
							//if (0 == methodNode->m_nativeName)
							//{
							//	staticMethodNodes.push_back(methodNode);
							//}
						}
						else
						{
							staticMethodNodes.push_back(methodNode);
						}
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
			else if(snt_enum == memberNode->m_nodeType
				|| snt_class == memberNode->m_nodeType
				|| snt_delegate == memberNode->m_nodeType
				|| snt_typedef == memberNode->m_nodeType
				|| snt_type_declaration == memberNode->m_nodeType)
			{
				subTypeNodes.push_back(memberNode);
			}
			else
			{
				assert(snt_field == memberNode->m_nodeType);
			}
		}
	}
	
	//if(!classNode->isAbstractClass())
	{
		auto it = classNode->m_additionalMethods.begin();
		auto end = classNode->m_additionalMethods.end();
		for (; it != end; ++it)
		{
			MethodNode* methodNode = *it;
			if (!reservedNames.empty())
			{
				if (!std::binary_search(reservedNames.begin(), reservedNames.end(), methodNode->m_name, CompareIdentifyPtr()))
				{
					continue;
				}
			}
			if (!methodNode->isNoMeta())
			{
				staticMethodNodes.push_back(methodNode);
			}
		}
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
	writeStringToFile("virtual bool assign(void* dst, const void* src);\n", file, indentation + 1);
	
	if(classNode->needSubclassProxy(templateArguments))
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

	if(classNode->needSubclassProxy(templateArguments))
	{
		generateCode_SubclassProxy(file, classNode, templateArguments, indentation);
	}

	size_t subTypeCount = subTypeNodes.size();
	for(size_t i = 0; i < subTypeCount; ++i)
	{
		MemberNode* typeNode = subTypeNodes[i];
		switch (typeNode->m_nodeType)
		{
		case snt_enum:
			generateCode_Enum(file, static_cast<EnumNode*>(typeNode), templateArguments, indentation);
			break;
		case snt_class:
			generateCode_Class(file, static_cast<ClassNode*>(typeNode), templateClassInstance, indentation);
			break;
		case snt_delegate:
			generateCode_Delegate(file, static_cast<DelegateNode*>(typeNode), templateArguments, indentation);
			break;
		case snt_typedef:
			generateCode_Typedef(file, static_cast<TypedefNode*>(typeNode), templateArguments, indentation);
			break;
		case snt_type_declaration:
			generateCode_TypeDeclaration(file, static_cast<TypeDeclarationNode*>(typeNode), templateArguments, indentation);
			break;
		default:
			assert(false);
		}
	}
}

void writeOverrideMethodParameter(MethodNode* methodNode, ParameterNode* parameterNode, FILE* file)
{
	std::string typeName;
	ClassNode* classNode = static_cast<ClassNode*>(methodNode->m_enclosing);
	if(parameterNode->m_constant)
	{
		writeStringToFile("const ", file);
	}
	parameterNode->m_typeName->getRelativeName(typeName, methodNode->getProgramNode());
	writeStringToFile(typeName.c_str(), file);

	if (parameterNode->isByPtr())
	{
		writeStringToFile("*", file);
	}
	else if(parameterNode->isByRef())
	{
		writeStringToFile("&", file);
	}

	if (parameterNode->isOutputPtr())
	{
		writeStringToFile("*", file);
	}
	else if (parameterNode->isOutputRef())
	{
		writeStringToFile("&", file);
	}

	writeSpaceToFile(file);
	writeStringToFile(parameterNode->m_name->m_str.c_str(), file);
};

void writeInterfaceMethodDecl(MethodNode* methodNode, FILE* file, int indentation)
{
	char buf[4096];
	std::string resultName;
	if(0 != methodNode->m_resultConst)
	{
		resultName = "const ";
	}
	assert(0 != methodNode->m_resultTypeName);
	std::string typeName;
	methodNode->m_resultTypeName->getRelativeName(typeName, methodNode->getProgramNode());
	resultName += typeName;

	if (methodNode->byRef())
	{
		resultName += "&";
	}
	else if (methodNode->byPtr() || methodNode->byNew())
	{
		resultName += "*";
	}

	sprintf_s(buf, "%s %s( ", resultName.c_str(), methodNode->m_name->m_str.c_str());
	writeStringToFile(buf, file, indentation);

	std::vector<ParameterNode*> parameterNodes;
	methodNode->m_parameterList->collectParameterNodes(parameterNodes);
	size_t parameterCount = parameterNodes.size();
	for(size_t i = 0; i < parameterCount; ++i)
	{
		if(0 != i)
		{
			writeStringToFile(", ", file);
		}
		writeOverrideMethodParameter(methodNode, parameterNodes[i], file);
	}
	writeStringToFile(")", file);
	if(methodNode->m_constant)
	{
		writeStringToFile(" const", file, indentation);
	}
	writeStringToFile(";\n", file);
}


void writeInterfaceMethodsDecl(FILE* file, ClassNode* classNode, TemplateArguments* templateArguments, int indentation)
{
	std::vector<MethodNode*> methodNodes;
	classNode->collectOverrideMethods(methodNodes, templateArguments);
	size_t count = methodNodes.size();
	for(size_t i = 0; i < count; ++i)
	{
		MethodNode* methodNode = methodNodes[i];
		assert(snt_method == methodNode->m_nodeType && methodNode->m_override && methodNode->isVirtual());
		writeInterfaceMethodDecl(methodNode, file, indentation);
	}
}

void MetaHeaderFileGenerator::generateCode_SubclassProxy(FILE* file, ClassNode* classNode, TemplateArguments* templateArguments, int indentation)
{
	char buf[4096];
	std::string className;
	classNode->getFullName(className, templateArguments);
	std::string subclassProxyName;
	GetSubclassProxyFullName(subclassProxyName, classNode, templateArguments);
	
	sprintf_s(buf, "class %s : public %s\n", subclassProxyName.c_str(), className.c_str());
	writeStringToFile(buf, file, indentation);
	writeStringToFile("{\n", file, indentation);
	writeStringToFile("public:\n", file, indentation);
	writeStringToFile("::pafcore::SubclassInvoker* m_subclassInvoker;\n", file, indentation + 1);
	writeStringToFile("public:\n", file, indentation);
	sprintf_s(buf, "%s(::pafcore::SubclassInvoker* subclassInvoker);\n", subclassProxyName.c_str());
	writeStringToFile(buf, file, indentation + 1);
	sprintf_s(buf, "~%s();\n", subclassProxyName.c_str());
	writeStringToFile(buf, file, indentation + 1);
	writeInterfaceMethodsDecl(file, classNode, templateArguments, indentation + 1);
	writeStringToFile("};\n\n", file, indentation);

}

void MetaHeaderFileGenerator::generateCode_TemplateClassInstance(FILE* file, TemplateClassInstanceNode* templateClassInstance, int indentation)
{
	if (templateClassInstance->isNoMeta())
	{
		return;
	}

	ClassNode* classNode = static_cast<ClassNode*>(templateClassInstance->m_classTypeNode->m_classNode);
	generateCode_Class(file, classNode, templateClassInstance, indentation);

}

void MetaHeaderFileGenerator::generateCode_Typedef(FILE* file, TypedefNode* typedefNode, TemplateArguments* templateArguments, int indentation)
{
	if (typedefNode->isNoMeta())
	{
		return;
	}

	char buf[4096];
	std::string metaTypeName;
	GetMetaTypeFullName(metaTypeName, typedefNode, templateArguments);

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

void MetaHeaderFileGenerator::generateCode_TypeDeclaration(FILE* file, TypeDeclarationNode* typeDeclarationNode, TemplateArguments* templateArguments, int indentation)
{
	if (typeDeclarationNode->isNoMeta())
	{
		return;
	}

	char buf[4096];
	std::string metaTypeName;
	GetMetaTypeFullName(metaTypeName, typeDeclarationNode, templateArguments);

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

