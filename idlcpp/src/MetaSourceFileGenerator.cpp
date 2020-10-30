#include "MetaSourceFileGenerator.h"
#include "Utility.h"
#include "SourceFile.h"
#include "ProgramNode.h"
#include "NamespaceNode.h"
#include "TokenNode.h"
#include "TokenListNode.h"
#include "IdentifyNode.h"
#include "EnumeratorListNode.h"
#include "EnumeratorNode.h"
#include "EnumNode.h"
#include "ClassNode.h"
#include "DelegateNode.h"
#include "TemplateParametersNode.h"
#include "TemplateClassInstanceNode.h"
#include "TypedefNode.h"
#include "typeDeclarationNode.h"
#include "TypeNameListNode.h"
#include "TypeNameNode.h"
#include "MemberListNode.h"
#include "FieldNode.h"
#include "GetterSetterNode.h"
#include "PropertyNode.h"
#include "MethodNode.h"
#include "OperatorNode.h"
#include "ParameterNode.h"
#include "ParameterListNode.h"
#include "AttributeNode.h"
#include "AttributeListNode.h"
#include "TypeTree.h"
#include "Platform.h"
#include "CommonFuncs.h"
#include "Options.h"
#include "Compiler.h"

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
	TemplateArguments* templateArguments,
	std::vector<MemberNode*>& nestedTypeNodes,
	std::vector<MemberNode*>& nestedTypeAliasNodes,
	std::vector<FieldNode*>& staticFieldNodes,
	std::vector<PropertyNode*>& staticPropertyNodes,
	std::vector<MethodNode*>& staticMethodNodes,
	std::vector<FieldNode*>& fieldNodes,
	std::vector<PropertyNode*>& propertyNodes,
	std::vector<MethodNode*>& methodNodes,
	FILE* file, int indentation);

void writeMetaPropertyImpls(ClassNode* classNode, TemplateArguments* templateArguments, std::vector<PropertyNode*>& propertyNodes, FILE* file, int indentation);
void writeMetaMethodImpls(ClassNode* classNode, TemplateArguments* templateArguments, std::vector<MethodNode*>& methodNodes, bool isStatic, FILE* file, int indentation);
void writeMetaGetSingletonImpls(MemberNode* typeNode, TemplateArguments* templateArguments, FILE* file, int indentation);
void writeEnumMetaConstructor(EnumNode* enumNode, TemplateArguments* templateArguments, std::vector<EnumeratorNode*>& enumerators, FILE* file, int indentation);


void MetaSourceFileGenerator::generateCode(FILE* dstFile, SourceFile* sourceFile, const char* fullPathName, const char* baseName)
{
	generateCode_Program(dstFile, sourceFile, fullPathName, baseName);
}

void MetaSourceFileGenerator::generateCode_Program(FILE* file, SourceFile* sourceFile, const char* fileName, const char* cppName)
{
	ProgramNode* programNode = sourceFile->m_syntaxTree;
	char buf[4096];
	std::string pafcorePath;
	GetRelativePath(pafcorePath, fileName, g_options.m_pafcorePath.c_str());
	FormatPathForInclude(pafcorePath);

	writeStringToFile("#pragma once\n\n", file);
	g_compiler.outputUsedTypesForMetaSource(file, sourceFile);
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
	sprintf_s(buf, "#include \"%sRefCountImpl.h\"\n", pafcorePath.c_str());
	writeStringToFile(buf, file);
	sprintf_s(buf, "#include \"%sIterator.h\"\n", pafcorePath.c_str());
	writeStringToFile(buf, file);
	writeStringToFile("#include <new>\n\n", file);

	writeStringToFile("\nnamespace idlcpp\n{\n\n", file);
	generateCode_Namespace(file, programNode, 1);
	writeStringToFile("}\n\n", file);

	std::vector<TypeNode*> typeNodes;
	CollectTypeNodes(typeNodes, programNode);
	std::reverse(typeNodes.begin(), typeNodes.end());
	size_t typeCount = typeNodes.size();
	for (size_t i = 0; i < typeCount; ++i)
	{
		TypeNode* typeNode = typeNodes[i];
		if (typeNode->getSyntaxNode()->canGenerateMetaCode())
		{
			std::string metaTypeName;
			GetMetaTypeFullName(metaTypeName, typeNode);
			sprintf_s(buf, "AUTO_REGISTER_TYPE(::idlcpp::%s)\n", metaTypeName.c_str());
			writeStringToFile(buf, file);
			if (typeNode->isTypeDeclaration())
			{
				TypeCategory typeCategory = typeNode->getTypeCategory(0);
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
				std::string typeName;
				typeNode->getNativeName(typeName);
				sprintf_s(buf, "static_assert(RuntimeTypeOf<%s>::type_category == ::pafcore::%s, \"type category error\");\n",
					typeName.c_str(), typeCategoryName);
				writeStringToFile(buf, file);
			}
		}
	}
}

void MetaSourceFileGenerator::generateCode_Namespace(FILE* file, NamespaceNode* namespaceNode, int indentation)
{
	if (namespaceNode->isNoMeta())
	{
		return;
	}

	std::vector<MemberNode*> memberNodes;
	namespaceNode->m_memberList->collectMemberNodes(memberNodes);
	size_t count = memberNodes.size();
	for (size_t i = 0; i < count; ++i)
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

void MetaSourceFileGenerator::generateCode_Enum(FILE* file, EnumNode* enumNode, TemplateArguments* templateArguments, int indentation)
{
	if (enumNode->isNoMeta())
	{
		return;
	}
	std::vector<EnumeratorNode*> enumeratorNodes;
	enumNode->m_enumeratorList->collectEnumeratorNodes(enumeratorNodes);
	std::sort(enumeratorNodes.begin(), enumeratorNodes.end(), CompareEnumeratorPtr());
	writeEnumMetaConstructor(enumNode, templateArguments, enumeratorNodes, file, indentation);
	writeMetaGetSingletonImpls(enumNode, templateArguments, file, indentation);
}

void MetaSourceFileGenerator::generateCode_TemplateClassInstance(FILE* file, TemplateClassInstanceNode* templateClassInstance, int indentation)
{
	if (templateClassInstance->isNoMeta())
	{
		return;
	}
	ClassNode* classNode = static_cast<ClassNode*>(templateClassInstance->m_classTypeNode->m_classNode);
	generateCode_Class(file, classNode, templateClassInstance, indentation);
}

void calcOverrideFunctionName(std::string& res, const char* funcName, const std::vector<MethodNode*>& typeMethodNodes, const std::string& className)
{
	assert(res.empty());
	IdentifyNode tmpIdentifyNode(funcName, 0, 0, 0);
	MethodNode tmpMethodNode(&tmpIdentifyNode, 0, 0, 0, 0);
	auto it = std::lower_bound(typeMethodNodes.begin(), typeMethodNodes.end(), &tmpMethodNode, CompareMemberNodeByName());
	if (typeMethodNodes.end() != it && (*it)->m_name->m_str == tmpIdentifyNode.m_str)
	{
		MethodNode* methodNode = *it;
		if (methodNode->m_nativeName)
		{
			if (methodNode->m_nativeName->m_str.find(':') != std::string::npos)
			{
				res = methodNode->m_nativeName->m_str;
			}
			else
			{
				res = className + "::" + methodNode->m_nativeName->m_str;
			}
		}
		else
		{
			res = className + "::" + methodNode->m_name->m_str;
		}
	}
}

void writeOverrideFunction(ClassNode* classNode, TemplateArguments* templateArguments, const std::vector<MethodNode*>& typeMethodNodes, FILE* file, int indentation)
{
	char buf[4096];
	std::string metaClassName;
	GetMetaTypeFullName(metaClassName, classNode, templateArguments);
	std::string className;
	classNode->getNativeName(className, templateArguments);

	std::string destroyInstanceName, destroyArrayName, assignName;
	calcOverrideFunctionName(destroyInstanceName, "__destroyInstance__", typeMethodNodes, className);
	calcOverrideFunctionName(destroyArrayName, "__destroyArray__", typeMethodNodes, className);
	calcOverrideFunctionName(assignName, "__assign__", typeMethodNodes, className);

	//if(!classNode->isAbstractClass())
	{

		sprintf_s(buf, "void %s::destroyInstance(void* address)\n", metaClassName.c_str());
		writeStringToFile(buf, file, indentation);
		writeStringToFile("{\n", file, indentation);
		if (destroyInstanceName.empty())
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
		else
		{
			sprintf_s(buf, "%s(reinterpret_cast<%s*>(address));\n", destroyInstanceName.c_str(), className.c_str());
		}
		writeStringToFile(buf, file, indentation + 1);
		writeStringToFile("}\n\n", file, indentation);

		sprintf_s(buf, "void %s::destroyArray(void* address)\n", metaClassName.c_str());
		writeStringToFile(buf, file, indentation);
		writeStringToFile("{\n", file, indentation);
		if (destroyArrayName.empty())
		{
			if (classNode->isValueType())
			{
				sprintf_s(buf, "paf_delete_array(reinterpret_cast<%s*>(address));\n", className.c_str());
			}
			else
			{
				sprintf_s(buf, "paf_delete_array(reinterpret_cast<::pafcore::RefCountImpl<%s>*>(address));\n", className.c_str());
			}
		}
		else
		{
			sprintf_s(buf, "%s(reinterpret_cast<%s*>(address));\n", destroyArrayName.c_str(), className.c_str());
		}
		writeStringToFile(buf, file, indentation + 1);
		writeStringToFile("}\n\n", file, indentation);

		sprintf_s(buf, "bool %s::assign(void* dst, const void* src)\n", metaClassName.c_str());
		writeStringToFile(buf, file, indentation);
		writeStringToFile("{\n", file, indentation);
		if (classNode->isCopyableClass(templateArguments))
		{
			if (assignName.empty())
			{
				sprintf_s(buf, "*(%s*)dst = *(const %s*)src;\n", className.c_str(), className.c_str());
			}
			else
			{
				sprintf_s(buf, "%s((%s*)dst, (const %s*)(src));\n",
					assignName.c_str(), className.c_str(), className.c_str());
			}
			writeStringToFile(buf, file, indentation + 1);
			writeStringToFile("return true;\n", file, indentation + 1);
		}
		else
		{
			writeStringToFile("return false;\n", file, indentation + 1);
		}
		writeStringToFile("}\n\n", file, indentation);

	}
	if (classNode->needSubclassProxy(templateArguments))
	{
		std::string subclassProxyName;
		GetSubclassProxyFullName(subclassProxyName, classNode, templateArguments);
		sprintf_s(buf, "void* %s::createSubclassProxy(::pafcore::SubclassInvoker* subclassInvoker)\n", metaClassName.c_str());
		writeStringToFile(buf, file, indentation);
		writeStringToFile("{\n", file, indentation);
		if (classNode->isValueType())
		{
			sprintf_s(buf, "return paf_new %s(subclassInvoker);\n", subclassProxyName.c_str());
		}
		else
		{
			sprintf_s(buf, "return paf_new ::pafcore::RefCountImpl<%s>(subclassInvoker);\n", subclassProxyName.c_str());
		}
		writeStringToFile(buf, file, indentation + 1);
		writeStringToFile("}\n\n", file, indentation);

		sprintf_s(buf, "void %s::destroySubclassProxy(void* subclassProxy)\n", metaClassName.c_str());
		writeStringToFile(buf, file, indentation);
		writeStringToFile("{\n", file, indentation);

		if (classNode->isValueType())
		{
			sprintf_s(buf, "delete reinterpret_cast<%s*>(subclassProxy)->m_subclassInvoker;\n", subclassProxyName.c_str());
		}
		else
		{
			sprintf_s(buf, "delete reinterpret_cast<::pafcore::RefCountImpl<%s>*>(subclassProxy)->m_subclassInvoker;\n", subclassProxyName.c_str());
		}
		writeStringToFile(buf, file, indentation + 1);
		if (classNode->isValueType())
		{
			sprintf_s(buf, "reinterpret_cast<%s*>(subclassProxy)->m_subclassInvoker = 0;\n", subclassProxyName.c_str());
		}
		else
		{
			sprintf_s(buf, "reinterpret_cast<::pafcore::RefCountImpl<%s>*>(subclassProxy)->m_subclassInvoker = 0;\n", subclassProxyName.c_str());
		}
		writeStringToFile(buf, file, indentation + 1);
		writeStringToFile("destroyInstance(subclassProxy);\n", file, indentation + 1);
		writeStringToFile("}\n\n", file, indentation);
	}
}

struct CompareMethodNode
{
	bool operator()(const MethodNode* m1, const MethodNode* m2) const
	{
		int cmp = m1->m_name->m_str.compare(m2->m_name->m_str);
		if (0 != cmp)
		{
			return cmp < 0;
		}
		return m1->getParameterCount() < m2->getParameterCount();
	}
};

void MetaSourceFileGenerator::generateCode_Delegate(FILE* file, DelegateNode* delegateNode, TemplateArguments* templateArguments, int indentation)
{
	if (delegateNode->isNoMeta())
	{
		return;
	}
	generateCode_Class(file, delegateNode->m_classNode, 0, indentation);
}

void MetaSourceFileGenerator::generateCode_Class(FILE* file, ClassNode* classNode, TemplateClassInstanceNode* templateClassInstance, int indentation)
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

	std::vector<MemberNode*> memberNodes;
	std::vector<MethodNode*> methodNodes;
	std::vector<MethodNode*> staticMethodNodes;
	std::vector<MethodNode*> typeMethodNodes;
	std::vector<PropertyNode*> propertyNodes;
	std::vector<PropertyNode*> staticPropertyNodes;
	std::vector<FieldNode*> fieldNodes;
	std::vector<FieldNode*> staticFieldNodes;
	std::vector<MemberNode*> nestedTypeNodes;
	std::vector<MemberNode*> nestedTypeAliasNodes;

	classNode->m_memberList->collectMemberNodes(memberNodes);
	size_t memberCount = memberNodes.size();
	for (size_t i = 0; i < memberCount; ++i)
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
		if (!memberNode->isNoMeta())
		{
			if (snt_method == memberNode->m_nodeType || snt_operator == memberNode->m_nodeType)
			{
				MethodNode* methodNode = static_cast<MethodNode*>(memberNode);
				if (memberNode->m_name->m_str != classNode->m_name->m_str)
				{
					if (methodNode->isStatic())
					{
						if (methodNode->m_name->m_str == "__destroyInstance__"
							|| methodNode->m_name->m_str == "__destroyArray__"
							|| methodNode->m_name->m_str == "__assign__")
						{
							typeMethodNodes.push_back(methodNode);
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
			else if (snt_property == memberNode->m_nodeType)
			{
				PropertyNode* propertyNode = static_cast<PropertyNode*>(memberNode);
				if (propertyNode->isStatic())
				{
					propertyNode->m_orderIndex = staticPropertyNodes.size();
					staticPropertyNodes.push_back(propertyNode);
				}
				else
				{
					propertyNode->m_orderIndex = propertyNodes.size();
					propertyNodes.push_back(propertyNode);
				}
			}
			else if (snt_field == memberNode->m_nodeType)
			{
				FieldNode* fieldNode = static_cast<FieldNode*>(memberNode);
				if (fieldNode->isStatic())
				{
					fieldNode->m_orderIndex = staticFieldNodes.size();
					staticFieldNodes.push_back(fieldNode);
				}
				else
				{
					fieldNode->m_orderIndex = fieldNodes.size();
					fieldNodes.push_back(fieldNode);
				}
			}
			else if (snt_enum == memberNode->m_nodeType ||
				snt_delegate == memberNode->m_nodeType ||
				snt_class == memberNode->m_nodeType)
			{
				nestedTypeNodes.push_back(memberNode);
			}
			else if (snt_typedef == memberNode->m_nodeType ||
				snt_type_declaration == memberNode->m_nodeType)
			{
				nestedTypeAliasNodes.push_back(memberNode);
			}
			else
			{
				assert(false);
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


	writeMetaConstructor(classNode, templateArguments, nestedTypeNodes, nestedTypeAliasNodes,
		staticFieldNodes, staticPropertyNodes, staticMethodNodes,
		fieldNodes, propertyNodes, methodNodes, file, indentation);

	writeOverrideFunction(classNode, templateArguments, typeMethodNodes, file, indentation);
	writeMetaPropertyImpls(classNode, templateArguments, propertyNodes, file, indentation);
	writeMetaPropertyImpls(classNode, templateArguments, staticPropertyNodes, file, indentation);
	writeMetaMethodImpls(classNode, templateArguments, methodNodes, false, file, indentation);
	writeMetaMethodImpls(classNode, templateArguments, staticMethodNodes, true, file, indentation);
	writeMetaGetSingletonImpls(classNode, templateArguments, file, indentation);

	if (classNode->needSubclassProxy(templateArguments))
	{
		generateCode_SubclassProxy(file, classNode, templateArguments, indentation);
	}

	size_t subTypeCount = nestedTypeNodes.size();
	for (size_t i = 0; i < subTypeCount; ++i)
	{
		MemberNode* typeNode = nestedTypeNodes[i];
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
		default:
			assert(false);
		}
	}

	size_t typeAliasCount = nestedTypeAliasNodes.size();
	for (size_t i = 0; i < typeAliasCount; ++i)
	{
		MemberNode* typeAliasNode = nestedTypeAliasNodes[i];
		switch (typeAliasNode->m_nodeType)
		{
		case snt_typedef:
			generateCode_Typedef(file, static_cast<TypedefNode*>(typeAliasNode), templateArguments, indentation);
			break;
		case snt_type_declaration:
			generateCode_TypeDeclaration(file, static_cast<TypeDeclarationNode*>(typeAliasNode), templateArguments, indentation);
			break;
		default:
			assert(false);
		}
	}
}

const char g_metaPropertyImplPrefix[] = "::pafcore::ErrorCode ";

const char g_metaPropertyImplPostfix[] = "(::pafcore::InstanceProperty* instanceProperty, ::pafcore::Variant* that, ::pafcore::Variant* value)\n";
const char g_metaArrayPropertyImplPostfix[] = "(::pafcore::InstanceProperty* instanceProperty, ::pafcore::Variant* that, size_t index, ::pafcore::Variant* value)\n";
const char g_metaMapPropertyImplPostfix[] = "(::pafcore::InstanceProperty* instanceProperty, ::pafcore::Variant* that, ::pafcore::Variant* key, ::pafcore::Variant* value)\n";

const char g_metaPropertyImplGetCandidatePostfix[] = "(::pafcore::InstanceProperty* instanceProperty, ::pafcore::Variant* that, size_t index, ::pafcore::Variant* value)\n";

const char g_metaArrayPropertyImplSizePostfix[] = "(::pafcore::InstanceProperty* instanceProperty, ::pafcore::Variant* that, ::pafcore::Variant* value)\n";
const char g_metaArrayPropertyImplResizePostfix[] = "(::pafcore::InstanceProperty* instanceProperty, ::pafcore::Variant* that, ::pafcore::Variant* value)\n";

const char g_metaPropertyImplPushBackPostfix[] = "(::pafcore::InstanceProperty* instanceProperty, ::pafcore::Variant* that, ::pafcore::Variant* value)\n";
const char g_metaPropertyImplGetIteratorPostfix[] = "(::pafcore::InstanceProperty* instanceProperty, ::pafcore::Variant* that, ::pafcore::Variant* iterator)\n";
const char g_metaPropertyImplGetKeyPostfix[] = "(::pafcore::InstanceProperty* instanceProperty, ::pafcore::Variant* that, ::pafcore::Iterator* iterator, ::pafcore::Variant* key)\n";
const char g_metaPropertyImplGetValuePostfix[] = "(::pafcore::InstanceProperty* instanceProperty, ::pafcore::Variant* that, ::pafcore::Iterator* iterator, ::pafcore::Variant* value)\n";
const char g_metaPropertyImplInsertPostfix[] = "(::pafcore::InstanceProperty* instanceProperty, ::pafcore::Variant* that, ::pafcore::Iterator* iterator, ::pafcore::Variant* value)\n";
const char g_metaPropertyImplErasePostfix[] = "(::pafcore::InstanceProperty* instanceProperty, ::pafcore::Variant* that, ::pafcore::Iterator* iterator)\n";

const char g_metaStaticPropertyImplPostfix[] = "(::pafcore::Variant* value)\n";
const char g_metaStaticArrayPropertyImplPostfix[] = "(size_t index, ::pafcore::Variant* value)\n";
const char g_metaStaticMapPropertyImplPostfix[] = "(::pafcore::Variant* key, ::pafcore::Variant* value)\n";

const char g_metaStaticPropertyImplGetCandidatePostfix[] = "(size_t index, ::pafcore::Variant* value)\n";

const char g_metaStaticArrayPropertyImplSizePostfix[] = "(::pafcore::Variant* value)\n";
const char g_metaStaticArrayPropertyImplResizePostfix[] = "(::pafcore::Variant* value)\n";

const char g_metaStaticPropertyImplPushBackPostfix[] = "(::pafcore::Variant* value)\n";
const char g_metaStaticPropertyImplGetIteratorPostfix[] = "(::pafcore::Variant* iterator)\n";
const char g_metaStaticPropertyImplGetKeyPostfix[] = "(::pafcore::Iterator* iterator, ::pafcore::Variant* key)\n";
const char g_metaStaticPropertyImplGetValuePostfix[] = "(::pafcore::Iterator* iterator, ::pafcore::Variant* value)\n";
const char g_metaStaticPropertyImplInsertPostfix[] = "(::pafcore::Iterator* iterator, ::pafcore::Variant* value)\n";
const char g_metaStaticPropertyImplErasePostfix[] = "(::pafcore::Iterator* iterator)\n";

void writeMetaGetPropertyImpl_Key(ClassNode* classNode, TemplateArguments* templateArguments, PropertyNode* propertyNode, FILE* file, int indentation)
{
	char buf[4096];
	std::string typeName;
	TypeCategory typeCategory = CalcTypeNativeName(typeName, propertyNode->m_keyTypeName, templateArguments);
	switch (typeCategory)
	{
	case void_type:
		sprintf_s(buf, "%s* index;\n", typeName.c_str());
		writeStringToFile(buf, file, indentation);
		sprintf_s(buf, "if(!key->%s((void**)&index))\n", /*propertyNode->isKeyAllowNull() ? "castToVoidPtrAllowNull" : */"castToVoidPtr");
		writeStringToFile(buf, file, indentation);
		break;
	case primitive_type:
		if (propertyNode->isKeyByValue()/* || (propertyNode->isKeyConstant() && propertyNode->isKeyByRef())*/)
		{
			sprintf_s(buf, "%s index;\n", typeName.c_str());
			writeStringToFile(buf, file, indentation);
			sprintf_s(buf, "if(!key->castToPrimitive(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), &index))\n", typeName.c_str());
			writeStringToFile(buf, file, indentation);
		}
		else
		{
			sprintf_s(buf, "%s* index;\n", typeName.c_str());
			writeStringToFile(buf, file, indentation);
			sprintf_s(buf, "if(!key->%s(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), (void**)&index))\n",
				/*propertyNode->isKeyAllowNull() ? "castToPrimitivePtrAllowNull" : */"castToPrimitivePtr", typeName.c_str());
			writeStringToFile(buf, file, indentation);
		}
		break;
	case enum_type:
		if (propertyNode->isKeyByValue()/* || (propertyNode->isKeyConstant() && propertyNode->isKeyByRef())*/)
		{
			sprintf_s(buf, "%s index;\n", typeName.c_str());
			writeStringToFile(buf, file, indentation);
			sprintf_s(buf, "if(!key->castToEnum(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), &index))\n", typeName.c_str());
			writeStringToFile(buf, file, indentation);
		}
		else
		{
			sprintf_s(buf, "%s* index;\n", typeName.c_str());
			writeStringToFile(buf, file, indentation);
			sprintf_s(buf, "if(!key->%s(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), (void**)&index))\n",
				/*propertyNode->isKeyAllowNull() ? "castToEnumPtrAllowNull" :*/ "castToEnumPtr", typeName.c_str());
			writeStringToFile(buf, file, indentation);
		}
		break;
	case value_type:
		sprintf_s(buf, "%s* index;\n", typeName.c_str());
		writeStringToFile(buf, file, indentation);
		sprintf_s(buf, "if(!key->%s(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), (void**)&index))\n",
			/*propertyNode->isKeyAllowNull() ? "castToValuePtrAllowNull" : */"castToValuePtr", typeName.c_str());
		writeStringToFile(buf, file, indentation);
		break;
	case reference_type:
		sprintf_s(buf, "%s* index;\n", typeName.c_str());
		writeStringToFile(buf, file, indentation);
		sprintf_s(buf, "if(!key->%s(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), (void**)&index))\n",
			/*propertyNode->isKeyAllowNull() ? "castToReferencePtrAllowNull" :*/ "castToReferencePtr", typeName.c_str());
		writeStringToFile(buf, file, indentation);
		break;
	default:
		assert(false);
	}
	writeStringToFile("{\n", file, indentation);
	writeStringToFile("return ::pafcore::e_invalid_subscript_type;\n", file, indentation + 1);
	writeStringToFile("}\n", file, indentation);
}

void writeMetaGetPropertyImpl(ClassNode* classNode, TemplateArguments* templateArguments, PropertyNode* propertyNode, FILE* file, int indentation)
{
	char buf[4096];
	char strCall[1024];
	std::string typeName;
	std::string className;
	std::string metaClassName;

	classNode->getNativeName(className, templateArguments);
	GetMetaTypeFullName(metaClassName, classNode, templateArguments);

	writeStringToFile(g_metaPropertyImplPrefix, sizeof(g_metaPropertyImplPrefix) - 1, file, indentation);
	sprintf_s(buf, "%s::%s_get_%s", metaClassName.c_str(),
		classNode->m_name->m_str.c_str(), propertyNode->m_name->m_str.c_str());
	writeStringToFile(buf, file);
	if (propertyNode->isStatic())
	{
		switch (propertyNode->getCategory())
		{
		case simple_property:
			writeStringToFile(g_metaStaticPropertyImplPostfix, sizeof(g_metaStaticPropertyImplPostfix) - 1, file);
			break;
		case fixed_array_property:
		case dynamic_array_property:
		case list_property:
			writeStringToFile(g_metaStaticArrayPropertyImplPostfix, sizeof(g_metaStaticArrayPropertyImplPostfix) - 1, file);
			break;
		case map_property:
			writeStringToFile(g_metaStaticMapPropertyImplPostfix, sizeof(g_metaStaticMapPropertyImplPostfix) - 1, file);
			break;
		}
	}
	else
	{
		switch (propertyNode->getCategory())
		{
		case simple_property:
			writeStringToFile(g_metaPropertyImplPostfix, sizeof(g_metaPropertyImplPostfix) - 1, file);
			break;
		case fixed_array_property:
		case dynamic_array_property:
		case list_property:
			writeStringToFile(g_metaArrayPropertyImplPostfix, sizeof(g_metaArrayPropertyImplPostfix) - 1, file);
			break;
		case map_property:
			writeStringToFile(g_metaMapPropertyImplPostfix, sizeof(g_metaMapPropertyImplPostfix) - 1, file);
			break;
		}
	}
	writeStringToFile("{\n", file, indentation);
	TypeCategory typeCategory = CalcTypeNativeName(typeName, propertyNode->m_typeName, templateArguments);

	if (propertyNode->isMap())
	{
		writeMetaGetPropertyImpl_Key(classNode, templateArguments, propertyNode, file, indentation + 1);
	}

	const char* strIndex = propertyNode->isSimple() ? "" : "index";

	if (propertyNode->isStatic())
	{
		if (propertyNode->m_get->m_nativeName)
		{
			sprintf_s(strCall, "%s(", propertyNode->m_get->m_nativeName->m_str.c_str());
		}
		else
		{
			sprintf_s(strCall, "%s::get_%s(", className.c_str(), propertyNode->m_name->m_str.c_str());
		}

		if (0 == propertyNode->m_passing)
		{
			if (primitive_type == typeCategory || enum_type == typeCategory)
			{
				sprintf_s(buf, "%s res = %s%s);\n", typeName.c_str(), strCall, strIndex);
			}
			else
			{
				sprintf_s(buf, "%s* res = paf_new %s(%s%s));\n", typeName.c_str(), typeName.c_str(), strCall, strIndex);
			}
		}
		else if ('*' == propertyNode->m_passing->m_nodeType)
		{
			sprintf_s(buf, "%s* res = %s%s);\n", typeName.c_str(), strCall, strIndex);
		}
		else
		{
			assert('&' == propertyNode->m_passing->m_nodeType);
			sprintf_s(buf, "%s* res = &%s%s);\n",  typeName.c_str(), strCall, strIndex);
		}
		writeStringToFile(buf, file, indentation + 1);
	}
	else
	{
		if (propertyNode->m_get->m_nativeName)
		{
			if (propertyNode->m_get->m_nativeName->m_str.find(':') != std::string::npos)
			{
				sprintf_s(strCall, "%s(self%s", propertyNode->m_get->m_nativeName->m_str.c_str(),
					propertyNode->isSimple() ? "" : ", ");
			}
			else
			{
				sprintf_s(strCall, "self->%s(", propertyNode->m_get->m_nativeName->m_str.c_str());
			}
		}
		else
		{
			sprintf_s(strCall, "self->get_%s(", propertyNode->m_name->m_str.c_str());
		}

		sprintf_s(buf, "%s* self;\n", className.c_str());
		writeStringToFile(buf, file, indentation + 1);
		if (classNode->isValueType())
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
		if (0 == propertyNode->m_passing)
		{
			if (primitive_type == typeCategory || enum_type == typeCategory)
			{
				sprintf_s(buf, "%s res = %s%s);\n", typeName.c_str(), strCall, strIndex);
			}
			else
			{
				sprintf_s(buf, "%s* res = paf_new %s(%s%s));\n", typeName.c_str(), typeName.c_str(), strCall, strIndex);
			}
		}
		else if ('*' == propertyNode->m_passing->m_nodeType)
		{
			sprintf_s(buf, "%s* res = %s%s);\n", typeName.c_str(), strCall, strIndex);
		}
		else
		{
			assert('&' == propertyNode->m_passing->m_nodeType);
			sprintf_s(buf, "%s* res = &%s%s);\n",  typeName.c_str(), strCall, strIndex);
		}
		writeStringToFile(buf, file, indentation + 1);
	}

	const char* varSemantic;
	if (propertyNode->isByPtr())
	{
		if (propertyNode->m_get->isGetterIncRef())
		{
			varSemantic = s_variantSemantic_ByNewPtr;
		}
		else
		{
			varSemantic = s_variantSemantic_ByPtr;
		}
	}
	else if(propertyNode->isByRef())
	{
		varSemantic = s_variantSemantic_ByRef;
	}
	else
	{
		assert(propertyNode->isByValue());
		varSemantic = s_variantSemantic_ByValue;
	}

	if (0 == propertyNode->m_passing)
	{
		switch (typeCategory)
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
		switch (typeCategory)
		{
		case void_type:
			sprintf_s(buf, "value->assignVoidPtr(res, %s);\n", false ? "true" : "false");
			break;
		case primitive_type:
			sprintf_s(buf, "value->assignPrimitivePtr(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), res, %s, %s);\n",
				typeName.c_str(), false ? "true" : "false", varSemantic);
			break;
		case enum_type:
			sprintf_s(buf, "value->assignEnumPtr(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), res, %s, %s);\n",
				typeName.c_str(), false ? "true" : "false", varSemantic);
			break;
		case value_type:
			sprintf_s(buf, "value->assignValuePtr(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), res, %s, %s);\n",
				typeName.c_str(), false ? "true" : "false", varSemantic);
			break;
		case reference_type:
			sprintf_s(buf, "value->assignReferencePtr(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), res, %s, %s);\n",
				typeName.c_str(), false ? "true" : "false", varSemantic);
			break;
		default:
			assert(false);
		}
	}
	writeStringToFile(buf, file, indentation + 1);
	writeStringToFile("return ::pafcore::s_ok;\n", file, indentation + 1);
	writeStringToFile("}\n\n", file, indentation);
}

void writeMetaSetPropertyImpl(ClassNode* classNode, TemplateArguments* templateArguments, PropertyNode* propertyNode, FILE* file, int indentation)
{
	char buf[4096];
	std::string typeName;
	std::string className;
	std::string metaClassName;

	classNode->getNativeName(className, templateArguments);
	GetMetaTypeFullName(metaClassName, classNode, templateArguments);

	writeStringToFile(g_metaPropertyImplPrefix, sizeof(g_metaPropertyImplPrefix) - 1, file, indentation);
	sprintf_s(buf, "%s::%s_set_%s", metaClassName.c_str(),
		classNode->m_name->m_str.c_str(), propertyNode->m_name->m_str.c_str());
	writeStringToFile(buf, file);
	if (propertyNode->isStatic())
	{
		switch (propertyNode->getCategory())
		{
		case simple_property:
			writeStringToFile(g_metaStaticPropertyImplPostfix, sizeof(g_metaStaticPropertyImplPostfix) - 1, file);
			break;
		case fixed_array_property:
		case dynamic_array_property:
		case list_property:
			writeStringToFile(g_metaStaticArrayPropertyImplPostfix, sizeof(g_metaStaticArrayPropertyImplPostfix) - 1, file);
			break;
		case map_property:
			writeStringToFile(g_metaStaticMapPropertyImplPostfix, sizeof(g_metaStaticMapPropertyImplPostfix) - 1, file);
			break;
		}
	}
	else
	{
		switch (propertyNode->getCategory())
		{
		case simple_property:
			writeStringToFile(g_metaPropertyImplPostfix, sizeof(g_metaPropertyImplPostfix) - 1, file);
			break;
		case fixed_array_property:
		case dynamic_array_property:
		case list_property:
			writeStringToFile(g_metaArrayPropertyImplPostfix, sizeof(g_metaArrayPropertyImplPostfix) - 1, file);
			break;
		case map_property:
			writeStringToFile(g_metaMapPropertyImplPostfix, sizeof(g_metaMapPropertyImplPostfix) - 1, file);
			break;
		}

	}
	writeStringToFile("{\n", file, indentation);

	TypeCategory typeCategory = CalcTypeNativeName(typeName, propertyNode->m_typeName, templateArguments);

	if (!propertyNode->isStatic())
	{
		if (g_options.m_checkConstant)
		{
			writeStringToFile("if(that->isConstant())\n", file, indentation + 1);
			writeStringToFile("{\n", file, indentation + 1);
			writeStringToFile("return ::pafcore::e_this_is_constant;\n", file, indentation + 2);
			writeStringToFile("}\n", file, indentation + 1);
		}

		sprintf_s(buf, "%s* self;\n", className.c_str());
		writeStringToFile(buf, file, indentation + 1);
		if (classNode->isValueType())
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

	if (propertyNode->isMap())
	{
		writeMetaGetPropertyImpl_Key(classNode, templateArguments, propertyNode, file, indentation + 1);
	}

	switch (typeCategory)
	{
	case void_type:
		sprintf_s(buf, "%s* arg;\n", typeName.c_str());
		writeStringToFile(buf, file, indentation + 1);
		sprintf_s(buf, "if(!value->%s((void**)&arg))\n", propertyNode->m_set->isSetterAllowNull() ? "castToVoidPtrAllowNull" : "castToVoidPtr");
		writeStringToFile(buf, file, indentation + 1);
		break;
	case primitive_type:
		if (propertyNode->isByValue())
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
			sprintf_s(buf, "if(!value->%s(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), (void**)&arg))\n",
				propertyNode->m_set->isSetterAllowNull() ? "castToPrimitivePtrAllowNull" : "castToPrimitivePtr", typeName.c_str());
			writeStringToFile(buf, file, indentation + 1);
		}
		break;
	case enum_type:
		if (propertyNode->isByValue())
		{
			sprintf_s(buf, "%s arg;\n", typeName.c_str());
			writeStringToFile(buf, file, indentation + 1);
			sprintf_s(buf, "if(!value->castToEnum(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), &arg))\n", typeName.c_str());
			writeStringToFile(buf, file, indentation + 1);
		}
		else
		{
			sprintf_s(buf, "%s* arg;\n", typeName.c_str());
			writeStringToFile(buf, file, indentation + 1);
			sprintf_s(buf, "if(!value->%s(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), (void**)&arg))\n",
				propertyNode->m_set->isSetterAllowNull() ? "castToEnumPtrAllowNull" : "castToEnumPtr", typeName.c_str());
			writeStringToFile(buf, file, indentation + 1);
		}
		break;
	case value_type:
		sprintf_s(buf, "%s* arg;\n", typeName.c_str());
		writeStringToFile(buf, file, indentation + 1);
		sprintf_s(buf, "if(!value->%s(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), (void**)&arg))\n",
			propertyNode->m_set->isSetterAllowNull() ? "castToValuePtrAllowNull" : "castToValuePtr", typeName.c_str());
		writeStringToFile(buf, file, indentation + 1);
		break;
	case reference_type:
		sprintf_s(buf, "%s* arg;\n", typeName.c_str());
		writeStringToFile(buf, file, indentation + 1);
		sprintf_s(buf, "if(!value->%s(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), (void**)&arg))\n",
			propertyNode->m_set->isSetterAllowNull() ? "castToReferencePtrAllowNull" : "castToReferencePtr", typeName.c_str());
		writeStringToFile(buf, file, indentation + 1);
		break;
	default:
		assert(false);
	}
	writeStringToFile("{\n", file, indentation + 1);
	writeStringToFile("return ::pafcore::e_invalid_property_type;\n", file, indentation + 2);
	writeStringToFile("}\n", file, indentation + 1);

	if (propertyNode->m_set->isSetterDecRef() && propertyNode->isByPtr())
	{
		if (reference_type == typeCategory)
		{
			writeStringToFile("if(arg)\n", file, indentation + 1);
			writeStringToFile("{\n", file, indentation + 1);
			writeStringToFile("arg->addRef();\n", file, indentation + 2);
			writeStringToFile("}\n", file, indentation + 1);
		}
		else
		{
			writeStringToFile("value->unhold();\n", file, indentation + 1);
		}
	}

	if (propertyNode->isStatic())
	{
		if (propertyNode->m_set->m_nativeName)
		{
			sprintf_s(buf, "%s(", propertyNode->m_set->m_nativeName->m_str.c_str());
		}
		else
		{
			sprintf_s(buf, "%s::set_%s(", className.c_str(), propertyNode->m_name->m_str.c_str());
		}
	}
	else
	{
		if (propertyNode->m_set->m_nativeName)
		{
			if (propertyNode->m_set->m_nativeName->m_str.find(':') != std::string::npos)
			{
				sprintf_s(buf, "%s(self, ", propertyNode->m_set->m_nativeName->m_str.c_str());
			}
			else
			{
				sprintf_s(buf, "self->%s(", propertyNode->m_set->m_nativeName->m_str.c_str());
			}
		}
		else
		{
			sprintf_s(buf, "self->set_%s(", propertyNode->m_name->m_str.c_str());
		}
	}
	writeStringToFile(buf, file, indentation + 1);

	if (!propertyNode->isSimple())
	{
		writeStringToFile("index, ", file);
	}

	if (primitive_type == typeCategory || enum_type == typeCategory)
	{
		//if(propertyNode->m_set->byRef() && !propertyNode->m_set->isConstant())
		//{
		//	strcpy_s(buf, "*arg);\n");
		//}
		//else
		{
			strcpy_s(buf, "arg);\n");
		}
	}
	else
	{
		if (propertyNode->isByPtr())
		{
			strcpy_s(buf, "arg);\n");
		}
		else
		{
			strcpy_s(buf, "*arg);\n");
		}
	}
	writeStringToFile(buf, file, 0);


	writeStringToFile("return ::pafcore::s_ok;\n", file, indentation + 1);
	writeStringToFile("}\n\n", file, indentation);
}


void writeMetaProperty_GetCandidate_Impl(ClassNode* classNode, TemplateArguments* templateArguments, PropertyNode* propertyNode, const char* funcPrefix, FILE* file, int indentation)
{
	char buf[4096];
	std::string typeName;
	std::string className;
	std::string metaClassName;

	bool isByValue, isByPtr, isByRef;
	isByValue = propertyNode->isByValue();
	isByPtr = propertyNode->isByPtr();
	isByRef = propertyNode->isByRef();

	classNode->getNativeName(className, templateArguments);
	GetMetaTypeFullName(metaClassName, classNode, templateArguments);

	writeStringToFile(g_metaPropertyImplPrefix, sizeof(g_metaPropertyImplPrefix) - 1, file, indentation);
	sprintf_s(buf, "%s::%s_%s_%s", metaClassName.c_str(),
		classNode->m_name->m_str.c_str(), funcPrefix, propertyNode->m_name->m_str.c_str());
	writeStringToFile(buf, file);
	if (propertyNode->isStatic())
	{
		writeStringToFile(g_metaStaticPropertyImplGetCandidatePostfix, sizeof(g_metaStaticPropertyImplGetCandidatePostfix) - 1, file);
	}
	else
	{
		writeStringToFile(g_metaPropertyImplGetCandidatePostfix, sizeof(g_metaPropertyImplGetCandidatePostfix) - 1, file);
	}
	writeStringToFile("{\n", file, indentation);

	TypeCategory typeCategory = CalcTypeNativeName(typeName, propertyNode->m_typeName, templateArguments);

	TokenNode* passing = propertyNode->m_passing;

	if (propertyNode->isStatic())
	{
		if (0 == passing)
		{
			if (primitive_type == typeCategory || enum_type == typeCategory)
			{
				sprintf_s(buf, "%s res = %s::%s_%s(index);\n", typeName.c_str(), className.c_str(), funcPrefix, propertyNode->m_name->m_str.c_str());
			}
			else
			{
				sprintf_s(buf, "%s* res = paf_new %s(%s::%s_%s(index));\n", typeName.c_str(), typeName.c_str(), className.c_str(), funcPrefix, propertyNode->m_name->m_str.c_str());
			}
		}
		else if ('*' == passing->m_nodeType)
		{
			sprintf_s(buf, "%s* res = %s::%s_%s(index);\n", typeName.c_str(), className.c_str(), funcPrefix, propertyNode->m_name->m_str.c_str());
		}
		else
		{
			assert('&' == passing->m_nodeType);
			sprintf_s(buf, "%s* res = &%s::%s_%s(index);\n", typeName.c_str(), className.c_str(), funcPrefix, propertyNode->m_name->m_str.c_str());
		}
		writeStringToFile(buf, file, indentation + 1);
	}
	else
	{
		sprintf_s(buf, "%s* self;\n", className.c_str());
		writeStringToFile(buf, file, indentation + 1);
		if (classNode->isValueType())
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
		if (0 == passing)
		{
			if (primitive_type == typeCategory || enum_type == typeCategory)
			{
				sprintf_s(buf, "%s res = self->%s_%s(index);\n", typeName.c_str(), funcPrefix, propertyNode->m_name->m_str.c_str());
			}
			else
			{
				sprintf_s(buf, "%s* res = paf_new %s(self->%s_%s(index));\n", typeName.c_str(), typeName.c_str(), funcPrefix, propertyNode->m_name->m_str.c_str());
			}
		}
		else if ('*' == passing->m_nodeType)
		{
			sprintf_s(buf, "%s* res = self->%s_%s(index);\n", typeName.c_str(), funcPrefix, propertyNode->m_name->m_str.c_str());
		}
		else
		{
			assert('&' == passing->m_nodeType);
			sprintf_s(buf, "%s* res = &self->%s_%s(index);\n", typeName.c_str(), funcPrefix, propertyNode->m_name->m_str.c_str());
		}
		writeStringToFile(buf, file, indentation + 1);
	}

	const char* varSemantic;
	if (isByPtr)
	{
		varSemantic = s_variantSemantic_ByPtr;
	}
	else if (isByRef)
	{
		varSemantic = s_variantSemantic_ByRef;
	}
	else
	{
		assert(isByValue);
		varSemantic = s_variantSemantic_ByValue;
	}

	if (0 == passing)
	{
		switch (typeCategory)
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
		switch (typeCategory)
		{
		case void_type:
			sprintf_s(buf, "value->assignVoidPtr(res, %s);\n", false ? "true" : "false");
			break;
		case primitive_type:
			sprintf_s(buf, "value->assignPrimitivePtr(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), res, %s, %s);\n",
				typeName.c_str(), false ? "true" : "false", varSemantic);
			break;
		case enum_type:
			sprintf_s(buf, "value->assignEnumPtr(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), res, %s, %s);\n",
				typeName.c_str(), false ? "true" : "false", varSemantic);
			break;
		case value_type:
			sprintf_s(buf, "value->assignValuePtr(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), res, %s, %s);\n",
				typeName.c_str(), false ? "true" : "false", varSemantic);
			break;
		case reference_type:
			sprintf_s(buf, "value->assignReferencePtr(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), res, %s, %s);\n",
				typeName.c_str(), false ? "true" : "false", varSemantic);
			break;
		default:
			assert(false);
		}
	}
	writeStringToFile(buf, file, indentation + 1);
	writeStringToFile("return ::pafcore::s_ok;\n", file, indentation + 1);
	writeStringToFile("}\n\n", file, indentation);
}


void writeMetaProperty_Size_CandidateCount_Impl(ClassNode* classNode, TemplateArguments* templateArguments, PropertyNode* propertyNode, const char* funcPrefix, FILE* file, int indentation)
{
	char buf[4096];
	std::string typeName;
	std::string className;
	std::string metaClassName;

	classNode->getNativeName(className, templateArguments);
	GetMetaTypeFullName(metaClassName, classNode, templateArguments);

	writeStringToFile(g_metaPropertyImplPrefix, sizeof(g_metaPropertyImplPrefix) - 1, file, indentation);
	sprintf_s(buf, "%s::%s_%s_%s", metaClassName.c_str(),
		classNode->m_name->m_str.c_str(), funcPrefix, propertyNode->m_name->m_str.c_str());
	writeStringToFile(buf, file);
	if (propertyNode->isStatic())
	{
		writeStringToFile(g_metaStaticArrayPropertyImplSizePostfix, sizeof(g_metaStaticArrayPropertyImplSizePostfix) - 1, file);
	}
	else
	{
		writeStringToFile(g_metaArrayPropertyImplSizePostfix, sizeof(g_metaArrayPropertyImplSizePostfix) - 1, file);
	}
	writeStringToFile("{\n", file, indentation);

	if (propertyNode->isStatic())
	{
		sprintf_s(buf, "size_t res = %s::%s_%s();\n", className.c_str(), funcPrefix, propertyNode->m_name->m_str.c_str());
		writeStringToFile(buf, file, indentation + 1);
	}
	else
	{
		sprintf_s(buf, "%s* self;\n", className.c_str());
		writeStringToFile(buf, file, indentation + 1);
		if (classNode->isValueType())
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
		sprintf_s(buf, "size_t res = self->%s_%s();\n", funcPrefix, propertyNode->m_name->m_str.c_str());
		writeStringToFile(buf, file, indentation + 1);
	}
	writeStringToFile("value->assignPrimitive(RuntimeTypeOf<size_t>::RuntimeType::GetSingleton(), &res);\n", file, indentation + 1);
	writeStringToFile("return ::pafcore::s_ok;\n", file, indentation + 1);
	writeStringToFile("}\n\n", file, indentation);
}


void writeMetaPropertyResizeImpl(ClassNode* classNode, TemplateArguments* templateArguments, PropertyNode* propertyNode, FILE* file, int indentation)
{
	char buf[4096];
	std::string typeName;
	std::string className;
	std::string metaClassName;

	classNode->getNativeName(className, templateArguments);
	GetMetaTypeFullName(metaClassName, classNode, templateArguments);

	writeStringToFile(g_metaPropertyImplPrefix, sizeof(g_metaPropertyImplPrefix) - 1, file, indentation);
	sprintf_s(buf, "%s::%s_resize_%s", metaClassName.c_str(),
		classNode->m_name->m_str.c_str(), propertyNode->m_name->m_str.c_str());
	writeStringToFile(buf, file);
	if (propertyNode->isStatic())
	{
		writeStringToFile(g_metaStaticArrayPropertyImplResizePostfix, sizeof(g_metaStaticArrayPropertyImplResizePostfix) - 1, file);
	}
	else
	{
		writeStringToFile(g_metaArrayPropertyImplResizePostfix, sizeof(g_metaArrayPropertyImplResizePostfix) - 1, file);
	}
	writeStringToFile("{\n", file, indentation);

	writeStringToFile("size_t arg;\n", file, indentation + 1);
	writeStringToFile("if(!value->castToPrimitive(RuntimeTypeOf<size_t>::RuntimeType::GetSingleton(), &arg))\n", file, indentation + 1);
	writeStringToFile("{\n", file, indentation + 1);
	writeStringToFile("return ::pafcore::e_invalid_property_type;\n", file, indentation + 2);
	writeStringToFile("}\n", file, indentation + 1);

	if (propertyNode->isStatic())
	{
		sprintf_s(buf, "%s::resize_%s(arg);\n", className.c_str(), propertyNode->m_name->m_str.c_str());
		writeStringToFile(buf, file, indentation + 1);
	}
	else
	{
		if (g_options.m_checkConstant)
		{
			writeStringToFile("if(that->isConstant())\n", file, indentation + 1);
			writeStringToFile("{\n", file, indentation + 1);
			writeStringToFile("return ::pafcore::e_this_is_constant;\n", file, indentation + 2);
			writeStringToFile("}\n", file, indentation + 1);
		}
		sprintf_s(buf, "%s* self;\n", className.c_str());
		writeStringToFile(buf, file, indentation + 1);
		if (classNode->isValueType())
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
		sprintf_s(buf, "self->resize_%s(arg);\n", propertyNode->m_name->m_str.c_str());
		writeStringToFile(buf, file, indentation + 1);
	}
	writeStringToFile("return ::pafcore::s_ok;\n", file, indentation + 1);
	writeStringToFile("}\n\n", file, indentation);
}

void writeMetaProperty_PushBack_Impl(ClassNode* classNode, TemplateArguments* templateArguments, PropertyNode* propertyNode, const char* funcPrefix, FILE* file, int indentation)
{
	char buf[4096];
	std::string typeName;
	std::string className;
	std::string metaClassName;

	bool isAllowNull, isByValue, isByPtr;
	if (propertyNode->m_set)
	{
		isAllowNull = propertyNode->m_set->isSetterAllowNull();
	}
	else
	{
		isAllowNull = false;
	}
	isByValue = propertyNode->isByValue();
	isByPtr = propertyNode->isByPtr();

	classNode->getNativeName(className, templateArguments);
	GetMetaTypeFullName(metaClassName, classNode, templateArguments);

	writeStringToFile(g_metaPropertyImplPrefix, sizeof(g_metaPropertyImplPrefix) - 1, file, indentation);
	sprintf_s(buf, "%s::%s_%s_%s", metaClassName.c_str(),
		classNode->m_name->m_str.c_str(), funcPrefix, propertyNode->m_name->m_str.c_str());
	writeStringToFile(buf, file);
	if (propertyNode->isStatic())
	{
		writeStringToFile(g_metaStaticPropertyImplPushBackPostfix, sizeof(g_metaStaticPropertyImplPushBackPostfix) - 1, file);
	}
	else
	{
		writeStringToFile(g_metaPropertyImplPushBackPostfix, sizeof(g_metaPropertyImplPushBackPostfix) - 1, file);
	}
	writeStringToFile("{\n", file, indentation);

	TypeCategory typeCategory = CalcTypeNativeName(typeName, propertyNode->m_typeName, templateArguments);

	if (!propertyNode->isStatic())
	{
		if (g_options.m_checkConstant)
		{
			writeStringToFile("if(that->isConstant())\n", file, indentation + 1);
			writeStringToFile("{\n", file, indentation + 1);
			writeStringToFile("return ::pafcore::e_this_is_constant;\n", file, indentation + 2);
			writeStringToFile("}\n", file, indentation + 1);
		}
		sprintf_s(buf, "%s* self;\n", className.c_str());
		writeStringToFile(buf, file, indentation + 1);
		if (classNode->isValueType())
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

	switch (typeCategory)
	{
	case void_type:
		sprintf_s(buf, "%s* arg;\n", typeName.c_str());
		writeStringToFile(buf, file, indentation + 1);
		sprintf_s(buf, "if(!value->%s((void**)&arg))\n", isAllowNull ? "castToVoidPtrAllowNull" : "castToVoidPtr");
		writeStringToFile(buf, file, indentation + 1);
		break;
	case primitive_type:
		if (isByValue)
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
			sprintf_s(buf, "if(!value->%s(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), (void**)&arg))\n",
				isAllowNull ? "castToPrimitivePtrAllowNull" : "castToPrimitivePtr", typeName.c_str());
			writeStringToFile(buf, file, indentation + 1);
		}
		break;
	case enum_type:
		if (isByValue)
		{
			sprintf_s(buf, "%s arg;\n", typeName.c_str());
			writeStringToFile(buf, file, indentation + 1);
			sprintf_s(buf, "if(!value->castToEnum(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), &arg))\n", typeName.c_str());
			writeStringToFile(buf, file, indentation + 1);
		}
		else
		{
			sprintf_s(buf, "%s* arg;\n", typeName.c_str());
			writeStringToFile(buf, file, indentation + 1);
			sprintf_s(buf, "if(!value->%s(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), (void**)&arg))\n",
				isAllowNull ? "castToEnumPtrAllowNull" : "castToEnumPtr", typeName.c_str());
			writeStringToFile(buf, file, indentation + 1);
		}
		break;
	case value_type:
		sprintf_s(buf, "%s* arg;\n", typeName.c_str());
		writeStringToFile(buf, file, indentation + 1);
		sprintf_s(buf, "if(!value->%s(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), (void**)&arg))\n",
			isAllowNull ? "castToValuePtrAllowNull" : "castToValuePtr", typeName.c_str());
		writeStringToFile(buf, file, indentation + 1);
		break;
	case reference_type:
		sprintf_s(buf, "%s* arg;\n", typeName.c_str());
		writeStringToFile(buf, file, indentation + 1);
		sprintf_s(buf, "if(!value->%s(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), (void**)&arg))\n",
			isAllowNull ? "castToReferencePtrAllowNull" : "castToReferencePtr", typeName.c_str());
		writeStringToFile(buf, file, indentation + 1);
		break;
	default:
		assert(false);
	}

	writeStringToFile("{\n", file, indentation + 1);
	writeStringToFile("return ::pafcore::e_invalid_property_type;\n", file, indentation + 2);
	writeStringToFile("}\n", file, indentation + 1);
	if (propertyNode->isStatic())
	{
		sprintf_s(buf, "%s::%s_%s(", className.c_str(), funcPrefix, propertyNode->m_name->m_str.c_str());
	}
	else
	{
		sprintf_s(buf, "self->%s_%s(", funcPrefix, propertyNode->m_name->m_str.c_str());
	}
	writeStringToFile(buf, file, indentation + 1);

	if (primitive_type == typeCategory || enum_type == typeCategory)
	{
		//if (isByRef && !isConstant)
		//{
		//	strcpy_s(buf, "*arg);\n");
		//}
		//else
		{
			strcpy_s(buf, "arg);\n");
		}
	}
	else
	{
		if (isByPtr)
		{
			strcpy_s(buf, "arg);\n");
		}
		else
		{
			strcpy_s(buf, "*arg);\n");
		}
	}
	writeStringToFile(buf, file, 0);
	writeStringToFile("return ::pafcore::s_ok;\n", file, indentation + 1);
	writeStringToFile("}\n\n", file, indentation);
}


void writeMetaPropertyGetIteratorImpl(ClassNode* classNode, TemplateArguments* templateArguments, PropertyNode* propertyNode, FILE* file, int indentation)
{
	char buf[4096];
	std::string typeName;
	std::string className;
	std::string metaClassName;

	classNode->getNativeName(className, templateArguments);
	GetMetaTypeFullName(metaClassName, classNode, templateArguments);

	writeStringToFile(g_metaPropertyImplPrefix, sizeof(g_metaPropertyImplPrefix) - 1, file, indentation);
	sprintf_s(buf, "%s::%s_getIterator_%s", metaClassName.c_str(),
		classNode->m_name->m_str.c_str(), propertyNode->m_name->m_str.c_str());
	writeStringToFile(buf, file);
	if (propertyNode->isStatic())
	{
		writeStringToFile(g_metaStaticPropertyImplGetIteratorPostfix, sizeof(g_metaStaticPropertyImplGetIteratorPostfix) - 1, file);
	}
	else
	{
		writeStringToFile(g_metaPropertyImplGetIteratorPostfix, sizeof(g_metaPropertyImplGetIteratorPostfix) - 1, file);
	}
	writeStringToFile("{\n", file, indentation);

	if (propertyNode->isStatic())
	{
		sprintf_s(buf, "::pafcore::Iterator* res = %s::getIterator_%s();\n", className.c_str(), propertyNode->m_name->m_str.c_str());
		writeStringToFile(buf, file, indentation + 1);
	}
	else
	{
		sprintf_s(buf, "%s* self;\n", className.c_str());
		writeStringToFile(buf, file, indentation + 1);
		if (classNode->isValueType())
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
		sprintf_s(buf, "::pafcore::Iterator* res = self->getIterator_%s();\n", propertyNode->m_name->m_str.c_str());
		writeStringToFile(buf, file, indentation + 1);
	}
	writeStringToFile("iterator->assignReferencePtr(res, false, ::pafcore::Variant::by_new_ptr);\n", file, indentation + 1);
	writeStringToFile("return ::pafcore::s_ok;\n", file, indentation + 1);
	writeStringToFile("}\n\n", file, indentation);
}


void writeMetaPropertyGetKeyImpl(ClassNode* classNode, TemplateArguments* templateArguments, PropertyNode* propertyNode, FILE* file, int indentation)
{
	char buf[4096];
	std::string typeName;
	std::string className;
	std::string metaClassName;

	classNode->getNativeName(className, templateArguments);
	GetMetaTypeFullName(metaClassName, classNode, templateArguments);

	writeStringToFile(g_metaPropertyImplPrefix, sizeof(g_metaPropertyImplPrefix) - 1, file, indentation);
	sprintf_s(buf, "%s::%s_getKey_%s", metaClassName.c_str(),
		classNode->m_name->m_str.c_str(), propertyNode->m_name->m_str.c_str());
	writeStringToFile(buf, file);
	if (propertyNode->isStatic())
	{
		writeStringToFile(g_metaStaticPropertyImplGetValuePostfix, sizeof(g_metaStaticPropertyImplGetValuePostfix) - 1, file);
	}
	else
	{
		writeStringToFile(g_metaPropertyImplGetValuePostfix, sizeof(g_metaPropertyImplGetValuePostfix) - 1, file);
	}
	writeStringToFile("{\n", file, indentation);

	TypeCategory typeCategory = CalcTypeNativeName(typeName, propertyNode->m_keyTypeName, templateArguments);

	if (propertyNode->isStatic())
	{
		if (0 == propertyNode->m_keyPassing)
		{
			if (primitive_type == typeCategory || enum_type == typeCategory)
			{
				sprintf_s(buf, "%s res = %s::getKey_%s(iterator);\n", typeName.c_str(), className.c_str(), propertyNode->m_name->m_str.c_str());
			}
			else
			{
				sprintf_s(buf, "%s* res = paf_new %s(%s::getKey_%s(iterator));\n", typeName.c_str(), typeName.c_str(), className.c_str(), propertyNode->m_name->m_str.c_str());
			}
		}
		else if ('*' == propertyNode->m_keyPassing->m_nodeType)
		{
			sprintf_s(buf, "%s%s* res = %s::getKey_%s(iterator);\n",/* propertyNode->isKeyConstant() ? "const " : */"",
				typeName.c_str(), className.c_str(), propertyNode->m_name->m_str.c_str());
		}
		else
		{
			assert('&' == propertyNode->m_keyPassing->m_nodeType);
			sprintf_s(buf, "%s%s* res = &%s::getKey_%s(iterator);\n", /*propertyNode->isKeyConstant() ? "const " :*/ "",
				typeName.c_str(), className.c_str(), propertyNode->m_name->m_str.c_str());
		}
		writeStringToFile(buf, file, indentation + 1);
	}
	else
	{
		sprintf_s(buf, "%s* self;\n", className.c_str());
		writeStringToFile(buf, file, indentation + 1);
		if (classNode->isValueType())
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
		if (0 == propertyNode->m_keyPassing)
		{
			if (primitive_type == typeCategory || enum_type == typeCategory)
			{
				sprintf_s(buf, "%s res = self->getKey_%s(iterator);\n", typeName.c_str(), propertyNode->m_name->m_str.c_str());
			}
			else
			{
				sprintf_s(buf, "%s* res = paf_new %s(self->getKey_%s(iterator));\n", typeName.c_str(), typeName.c_str(), propertyNode->m_name->m_str.c_str());
			}
		}
		else if ('*' == propertyNode->m_keyPassing->m_nodeType)
		{
			sprintf_s(buf, "%s%s* res = self->getKey_%s(iterator);\n", /*propertyNode->isKeyConstant() ? "const " :*/ "",
				typeName.c_str(), propertyNode->m_name->m_str.c_str());
		}
		else
		{
			assert('&' == propertyNode->m_keyPassing->m_nodeType);
			sprintf_s(buf, "%s%s* res = &self->getKey_%s(iterator);\n", /*propertyNode->isKeyConstant() ? "const " :*/ "",
				typeName.c_str(), propertyNode->m_name->m_str.c_str());
		}
		writeStringToFile(buf, file, indentation + 1);
	}

	const char* varSemantic;
	if (propertyNode->isKeyByPtr())
	{
		varSemantic = s_variantSemantic_ByPtr;
	}
	//else if (propertyNode->isKeyByRef())
	//{
	//	varSemantic = s_variantSemantic_ByRef;
	//}
	else
	{
		assert(propertyNode->isKeyByValue());
		varSemantic = s_variantSemantic_ByValue;
	}

	if (0 == propertyNode->m_keyPassing)
	{
		switch (typeCategory)
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
		switch (typeCategory)
		{
		case void_type:
			sprintf_s(buf, "value->assignVoidPtr(res, %s);\n", /*propertyNode->isKeyConstant() ? "true" : */"false");
			break;
		case primitive_type:
			sprintf_s(buf, "value->assignPrimitivePtr(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), res, %s, %s);\n",
				typeName.c_str(), /*propertyNode->isKeyConstant() ? "true" : */"false", varSemantic);
			break;
		case enum_type:
			sprintf_s(buf, "value->assignEnumPtr(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), res, %s, %s);\n",
				typeName.c_str(), /*propertyNode->isKeyConstant() ? "true" : */"false", varSemantic);
			break;
		case value_type:
			sprintf_s(buf, "value->assignValuePtr(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), res, %s, %s);\n",
				typeName.c_str(), /*propertyNode->isKeyConstant() ? "true" : */"false", varSemantic);
			break;
		case reference_type:
			sprintf_s(buf, "value->assignReferencePtr(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), res, %s, %s);\n",
				typeName.c_str(), /*propertyNode->isKeyConstant() ? "true" : */"false", varSemantic);
			break;
		default:
			assert(false);
		}
	}
	writeStringToFile(buf, file, indentation + 1);
	writeStringToFile("return ::pafcore::s_ok;\n", file, indentation + 1);
	writeStringToFile("}\n\n", file, indentation);
}

void writeMetaProperty_GetValue_Impl(ClassNode* classNode, TemplateArguments* templateArguments, PropertyNode* propertyNode, const char* funcPrefix, FILE* file, int indentation)
{
	char buf[4096];
	std::string typeName;
	std::string className;
	std::string metaClassName;

	bool isByValue, isByPtr, isByRef;
	isByValue = propertyNode->isByValue();
	isByPtr = propertyNode->isByPtr();
	isByRef = propertyNode->isByRef();

	classNode->getNativeName(className, templateArguments);
	GetMetaTypeFullName(metaClassName, classNode, templateArguments);

	writeStringToFile(g_metaPropertyImplPrefix, sizeof(g_metaPropertyImplPrefix) - 1, file, indentation);
	sprintf_s(buf, "%s::%s_%s_%s", metaClassName.c_str(),
		classNode->m_name->m_str.c_str(), funcPrefix, propertyNode->m_name->m_str.c_str());
	writeStringToFile(buf, file);
	if (propertyNode->isStatic())
	{
		writeStringToFile(g_metaStaticPropertyImplGetValuePostfix, sizeof(g_metaStaticPropertyImplGetValuePostfix) - 1, file);
	}
	else
	{
		writeStringToFile(g_metaPropertyImplGetValuePostfix, sizeof(g_metaPropertyImplGetValuePostfix) - 1, file);
	}
	writeStringToFile("{\n", file, indentation);

	TypeCategory typeCategory = CalcTypeNativeName(typeName, propertyNode->m_typeName, templateArguments);

	TokenNode* passing = propertyNode->m_passing;

	if (propertyNode->isStatic())
	{
		if (0 == passing)
		{
			if (primitive_type == typeCategory || enum_type == typeCategory)
			{
				sprintf_s(buf, "%s res = %s::%s_%s(iterator);\n", typeName.c_str(), className.c_str(), funcPrefix, propertyNode->m_name->m_str.c_str());
			}
			else
			{
				sprintf_s(buf, "%s* res = paf_new %s(%s::%s_%s(iterator));\n", typeName.c_str(), typeName.c_str(), className.c_str(), funcPrefix, propertyNode->m_name->m_str.c_str());
			}
		}
		else if ('*' == passing->m_nodeType)
		{
			sprintf_s(buf, "%s* res = %s::%s_%s(iterator);\n", typeName.c_str(), className.c_str(), funcPrefix, propertyNode->m_name->m_str.c_str());
		}
		else
		{
			assert('&' == passing->m_nodeType);
			sprintf_s(buf, "%s* res = &%s::%s_%s(iterator);\n", typeName.c_str(), className.c_str(), funcPrefix, propertyNode->m_name->m_str.c_str());
		}
		writeStringToFile(buf, file, indentation + 1);
	}
	else
	{
		sprintf_s(buf, "%s* self;\n", className.c_str());
		writeStringToFile(buf, file, indentation + 1);
		if (classNode->isValueType())
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
		if (0 == passing)
		{
			if (primitive_type == typeCategory || enum_type == typeCategory)
			{
				sprintf_s(buf, "%s res = self->%s_%s(iterator);\n", typeName.c_str(), funcPrefix, propertyNode->m_name->m_str.c_str());
			}
			else
			{
				sprintf_s(buf, "%s* res = paf_new %s(self->%s_%s(iterator));\n", typeName.c_str(), typeName.c_str(), funcPrefix, propertyNode->m_name->m_str.c_str());
			}
		}
		else if ('*' == passing->m_nodeType)
		{
			sprintf_s(buf, "%s* res = self->%s_%s(iterator);\n", typeName.c_str(), funcPrefix, propertyNode->m_name->m_str.c_str());
		}
		else
		{
			assert('&' == passing->m_nodeType);
			sprintf_s(buf, "%s* res = &self->%s_%s(iterator);\n", typeName.c_str(), funcPrefix, propertyNode->m_name->m_str.c_str());
		}
		writeStringToFile(buf, file, indentation + 1);
	}

	const char* varSemantic;
	if (isByPtr)
	{
		varSemantic = s_variantSemantic_ByPtr;
	}
	else if (isByRef)
	{
		varSemantic = s_variantSemantic_ByRef;
	}
	else
	{
		assert(isByValue);
		varSemantic = s_variantSemantic_ByValue;
	}

	if (0 == passing)
	{
		switch (typeCategory)
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
		switch (typeCategory)
		{
		case void_type:
			sprintf_s(buf, "value->assignVoidPtr(res, %s);\n", false ? "true" : "false");
			break;
		case primitive_type:
			sprintf_s(buf, "value->assignPrimitivePtr(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), res, %s, %s);\n",
				typeName.c_str(), false ? "true" : "false", varSemantic);
			break;
		case enum_type:
			sprintf_s(buf, "value->assignEnumPtr(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), res, %s, %s);\n",
				typeName.c_str(), false ? "true" : "false", varSemantic);
			break;
		case value_type:
			sprintf_s(buf, "value->assignValuePtr(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), res, %s, %s);\n",
				typeName.c_str(), false ? "true" : "false", varSemantic);
			break;
		case reference_type:
			sprintf_s(buf, "value->assignReferencePtr(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), res, %s, %s);\n",
				typeName.c_str(), false ? "true" : "false", varSemantic);
			break;
		default:
			assert(false);
		}
	}
	writeStringToFile(buf, file, indentation + 1);
	writeStringToFile("return ::pafcore::s_ok;\n", file, indentation + 1);
	writeStringToFile("}\n\n", file, indentation);
}


void writeMetaProperty_Insert_Impl(ClassNode* classNode, TemplateArguments* templateArguments, PropertyNode* propertyNode, const char* funcPrefix, FILE* file, int indentation)
{
	char buf[4096];
	std::string typeName;
	std::string className;
	std::string metaClassName;

	bool isAllowNull, isByValue, isByPtr;
	if (propertyNode->m_set)
	{
		isAllowNull = propertyNode->m_set->isSetterAllowNull();
	}
	else
	{
		isAllowNull = false;
	}
	isByValue = propertyNode->isByValue();
	isByPtr = propertyNode->isByPtr();

	classNode->getNativeName(className, templateArguments);
	GetMetaTypeFullName(metaClassName, classNode, templateArguments);

	writeStringToFile(g_metaPropertyImplPrefix, sizeof(g_metaPropertyImplPrefix) - 1, file, indentation);
	sprintf_s(buf, "%s::%s_%s_%s", metaClassName.c_str(),
		classNode->m_name->m_str.c_str(), funcPrefix, propertyNode->m_name->m_str.c_str());
	writeStringToFile(buf, file);
	if (propertyNode->isStatic())
	{
		writeStringToFile(g_metaStaticPropertyImplInsertPostfix, sizeof(g_metaStaticPropertyImplInsertPostfix) - 1, file);
	}
	else
	{
		writeStringToFile(g_metaPropertyImplInsertPostfix, sizeof(g_metaPropertyImplInsertPostfix) - 1, file);
	}
	writeStringToFile("{\n", file, indentation);

	TypeCategory typeCategory = CalcTypeNativeName(typeName, propertyNode->m_typeName, templateArguments);

	if (!propertyNode->isStatic())
	{
		if (g_options.m_checkConstant)
		{
			writeStringToFile("if(that->isConstant())\n", file, indentation + 1);
			writeStringToFile("{\n", file, indentation + 1);
			writeStringToFile("return ::pafcore::e_this_is_constant;\n", file, indentation + 2);
			writeStringToFile("}\n", file, indentation + 1);
		}
		sprintf_s(buf, "%s* self;\n", className.c_str());
		writeStringToFile(buf, file, indentation + 1);
		if (classNode->isValueType())
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

	switch (typeCategory)
	{
	case void_type:
		sprintf_s(buf, "%s* arg;\n", typeName.c_str());
		writeStringToFile(buf, file, indentation + 1);
		sprintf_s(buf, "if(!value->%s((void**)&arg))\n", isAllowNull ? "castToVoidPtrAllowNull" : "castToVoidPtr");
		writeStringToFile(buf, file, indentation + 1);
		break;
	case primitive_type:
		if (isByValue)
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
			sprintf_s(buf, "if(!value->%s(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), (void**)&arg))\n",
				isAllowNull ? "castToPrimitivePtrAllowNull" : "castToPrimitivePtr", typeName.c_str());
			writeStringToFile(buf, file, indentation + 1);
		}
		break;
	case enum_type:
		if (isByValue)
		{
			sprintf_s(buf, "%s arg;\n", typeName.c_str());
			writeStringToFile(buf, file, indentation + 1);
			sprintf_s(buf, "if(!value->castToEnum(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), &arg))\n", typeName.c_str());
			writeStringToFile(buf, file, indentation + 1);
		}
		else
		{
			sprintf_s(buf, "%s* arg;\n", typeName.c_str());
			writeStringToFile(buf, file, indentation + 1);
			sprintf_s(buf, "if(!value->%s(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), (void**)&arg))\n",
				isAllowNull ? "castToEnumPtrAllowNull" : "castToEnumPtr", typeName.c_str());
			writeStringToFile(buf, file, indentation + 1);
		}
		break;
	case value_type:
		sprintf_s(buf, "%s* arg;\n", typeName.c_str());
		writeStringToFile(buf, file, indentation + 1);
		sprintf_s(buf, "if(!value->%s(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), (void**)&arg))\n",
			isAllowNull ? "castToValuePtrAllowNull" : "castToValuePtr", typeName.c_str());
		writeStringToFile(buf, file, indentation + 1);
		break;
	case reference_type:
		sprintf_s(buf, "%s* arg;\n", typeName.c_str());
		writeStringToFile(buf, file, indentation + 1);
		sprintf_s(buf, "if(!value->%s(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), (void**)&arg))\n",
			isAllowNull ? "castToReferencePtrAllowNull" : "castToReferencePtr", typeName.c_str());
		writeStringToFile(buf, file, indentation + 1);
		break;
	default:
		assert(false);
	}

	writeStringToFile("{\n", file, indentation + 1);
	writeStringToFile("return ::pafcore::e_invalid_property_type;\n", file, indentation + 2);
	writeStringToFile("}\n", file, indentation + 1);
	if (propertyNode->isStatic())
	{
		sprintf_s(buf, "%s::%s_%s(iterator, ", className.c_str(), funcPrefix, propertyNode->m_name->m_str.c_str());
	}
	else
	{
		sprintf_s(buf, "self->%s_%s(iterator, ", funcPrefix, propertyNode->m_name->m_str.c_str());
	}
	writeStringToFile(buf, file, indentation + 1);

	if (primitive_type == typeCategory || enum_type == typeCategory)
	{
		//if (isByRef && !isConstant)
		//{
		//	strcpy_s(buf, "*arg);\n");
		//}
		//else
		{
			strcpy_s(buf, "arg);\n");
		}
	}
	else
	{
		if (isByPtr)
		{
			strcpy_s(buf, "arg);\n");
		}
		else
		{
			strcpy_s(buf, "*arg);\n");
		}
	}
	writeStringToFile(buf, file, 0);
	writeStringToFile("return ::pafcore::s_ok;\n", file, indentation + 1);
	writeStringToFile("}\n\n", file, indentation);
}


void writeMetaProperty_Erase_Impl(ClassNode* classNode, TemplateArguments* templateArguments, PropertyNode* propertyNode, const char* funcPrefix, FILE* file, int indentation)
{
	char buf[4096];
	std::string typeName;
	std::string className;
	std::string metaClassName;

	bool isAllowNull, isByValue, isByPtr;
	if (propertyNode->m_set)
	{
		isAllowNull = propertyNode->m_set->isSetterAllowNull();
	}
	else
	{
		isAllowNull = false;
	}
	isByValue = propertyNode->isByValue();
	isByPtr = propertyNode->isByPtr();

	classNode->getNativeName(className, templateArguments);
	GetMetaTypeFullName(metaClassName, classNode, templateArguments);

	writeStringToFile(g_metaPropertyImplPrefix, sizeof(g_metaPropertyImplPrefix) - 1, file, indentation);
	sprintf_s(buf, "%s::%s_%s_%s", metaClassName.c_str(),
		classNode->m_name->m_str.c_str(), funcPrefix, propertyNode->m_name->m_str.c_str());
	writeStringToFile(buf, file);
	if (propertyNode->isStatic())
	{
		writeStringToFile(g_metaStaticPropertyImplErasePostfix, sizeof(g_metaStaticPropertyImplErasePostfix) - 1, file);
	}
	else
	{
		writeStringToFile(g_metaPropertyImplErasePostfix, sizeof(g_metaPropertyImplErasePostfix) - 1, file);
	}
	writeStringToFile("{\n", file, indentation);

	if (!propertyNode->isStatic())
	{
		if (g_options.m_checkConstant)
		{
			writeStringToFile("if(that->isConstant())\n", file, indentation + 1);
			writeStringToFile("{\n", file, indentation + 1);
			writeStringToFile("return ::pafcore::e_this_is_constant;\n", file, indentation + 2);
			writeStringToFile("}\n", file, indentation + 1);
		}
		sprintf_s(buf, "%s* self;\n", className.c_str());
		writeStringToFile(buf, file, indentation + 1);
		if (classNode->isValueType())
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
	if (propertyNode->isStatic())
	{
		sprintf_s(buf, "%s::%s_%s(iterator);\n", className.c_str(), funcPrefix, propertyNode->m_name->m_str.c_str());
	}
	else
	{
		sprintf_s(buf, "self->%s_%s(iterator);\n", funcPrefix, propertyNode->m_name->m_str.c_str());
	}
	writeStringToFile(buf, file, indentation + 1);
	writeStringToFile("return ::pafcore::s_ok;\n", file, indentation + 1);
	writeStringToFile("}\n\n", file, indentation);
}


void writeMetaPropertyImpls(ClassNode* classNode, TemplateArguments* templateArguments, std::vector<PropertyNode*>& propertyNodes, FILE* file, int indentation)
{
	size_t propertyCount = propertyNodes.size();
	if (0 < propertyCount)
	{
		for (size_t i = 0; i < propertyCount; ++i)
		{
			PropertyNode* propertyNode = propertyNodes[i];
			if (0 != propertyNode->m_get)
			{
				writeMetaGetPropertyImpl(classNode, templateArguments, propertyNodes[i], file, indentation);
			}
			if (0 != propertyNode->m_set)
			{
				writeMetaSetPropertyImpl(classNode, templateArguments, propertyNodes[i], file, indentation);
			}
			if (propertyNode->isSimple())
			{
				if (propertyNode->hasCandidate())
				{
					writeMetaProperty_Size_CandidateCount_Impl(classNode, templateArguments, propertyNodes[i], "candidateCount", file, indentation);
					writeMetaProperty_GetCandidate_Impl(classNode, templateArguments, propertyNodes[i], "getCandidate", file, indentation);
				}
			}
			else if (propertyNode->isFixedArray() || propertyNode->isDynamicArray())
			{
				writeMetaProperty_Size_CandidateCount_Impl(classNode, templateArguments, propertyNodes[i], "size", file, indentation);
				if (propertyNode->isDynamicArray())
				{
					writeMetaPropertyResizeImpl(classNode, templateArguments, propertyNodes[i], file, indentation);
				}
				writeMetaPropertyGetIteratorImpl(classNode, templateArguments, propertyNodes[i], file, indentation);
				writeMetaProperty_GetValue_Impl(classNode, templateArguments, propertyNodes[i], "getValue", file, indentation);
			}
			else if (propertyNode->isList())
			{
				writeMetaProperty_PushBack_Impl(classNode, templateArguments, propertyNodes[i], "pushBack", file, indentation);
				writeMetaPropertyGetIteratorImpl(classNode, templateArguments, propertyNodes[i], file, indentation);
				writeMetaProperty_GetValue_Impl(classNode, templateArguments, propertyNodes[i], "getValue", file, indentation);
				writeMetaProperty_Insert_Impl(classNode, templateArguments, propertyNodes[i], "insert", file, indentation);
				writeMetaProperty_Erase_Impl(classNode, templateArguments, propertyNodes[i], "erase", file, indentation);
			}
			else if (propertyNode->isMap())
			{
				writeMetaPropertyGetIteratorImpl(classNode, templateArguments, propertyNodes[i], file, indentation);
				writeMetaPropertyGetKeyImpl(classNode, templateArguments, propertyNodes[i], file, indentation);
				writeMetaProperty_GetValue_Impl(classNode, templateArguments, propertyNodes[i], "getValue", file, indentation);
			}
		}
	}
}

const char g_metaMethodImplPrefix[] = "::pafcore::ErrorCode ";
const char g_metaMethodImplPostfix[] = "(::pafcore::Variant* result, ::pafcore::Variant** args, int_t numArgs)\n";

void writeMetaMethodImpl_CastSelf(ClassNode* classNode, TemplateArguments* templateArguments, MethodNode* methodNode, bool checkType, FILE* file, int indentation)
{
	std::string className;
	classNode->getNativeName(className, templateArguments);

	if (checkType)
	{
		if (!methodNode->isConstant())
		{
			if (g_options.m_checkConstant)
			{
				writeStringToFile("if(args[0]->isConstant())\n", file, indentation);
				writeStringToFile("{\n", file, indentation);
				writeStringToFile("return ::pafcore::e_this_is_constant;\n", file, indentation + 1);
				writeStringToFile("}\n", file, indentation);
			}
		}
	}
	char buf[4096];
	sprintf_s(buf, "%s%s* self;\n", methodNode->isConstant() ? "const " : "", className.c_str());
	writeStringToFile(buf, file, indentation);
	const char* content;
	if (classNode->isValueType())
	{
		content = "args[0]->castToValuePtr(GetSingleton(), (void**)&self)";
	}
	else
	{
		content = "args[0]->castToReferencePtr(GetSingleton(), (void**)&self)";
	}
	if (checkType)
	{
		writeStringToFile("if(!", file, indentation);
		writeStringToFile(content, file, 0);
		writeStringToFile(")\n", file, 0);
		writeStringToFile("{\n", file, indentation);
		writeStringToFile("return ::pafcore::e_invalid_this_type;\n", file, indentation + 1);
		writeStringToFile("}\n", file, indentation);
	}
	else
	{
		writeStringToFile(content, file, indentation);
		writeStringToFile(";\n", file, 0);
	}
}

void writeMetaMethodImpl_CastParam(ClassNode* classNode, TemplateArguments* templateArguments, ParameterNode* parameterNode, size_t argIndex, size_t paramIndex, bool checkType, FILE* file, int indentation)
{
	char buf[4096];
	std::string typeName;
	TypeCategory typeCategory = CalcTypeNativeName(typeName, parameterNode->m_typeName, templateArguments);

	const char* strConstant = (parameterNode->isConstant() || parameterNode->isByValue()) ? "const " : "";

	if (parameterNode->isInput())
	{
		if (primitive_type == typeCategory && !parameterNode->isByValue())
		{
			sprintf_s(buf, "if(args[%d]->isTemporary())\n", argIndex);
			writeStringToFile(buf, file, indentation);
			writeStringToFile("{\n", file, indentation);
			sprintf_s(buf, "return ::pafcore::e_invalid_arg_type_%d;\n", paramIndex + 1);
			writeStringToFile(buf, file, indentation + 1);
			writeStringToFile("}\n", file, indentation);
		}

		switch (typeCategory)
		{
		case void_type:
			assert(parameterNode->isByPtr());
			sprintf_s(buf, "%s%s* a%d;\n", strConstant, typeName.c_str(), paramIndex);
			writeStringToFile(buf, file, indentation);
			sprintf_s(buf, "args[%d]->%s((void**)&a%d)", argIndex,
				parameterNode->isAllowNull() ? "castToVoidPtrAllowNull" : "castToVoidPtr", paramIndex);
			break;
		case primitive_type:
			if (parameterNode->isByValue())
			{
				sprintf_s(buf, "%s a%d;\n", typeName.c_str(), paramIndex);
				writeStringToFile(buf, file, indentation);
				sprintf_s(buf, "args[%d]->castToPrimitive(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), &a%d)", argIndex, typeName.c_str(), paramIndex);
			}
			else
			{
				sprintf_s(buf, "%s%s* a%d;\n", strConstant, typeName.c_str(), paramIndex);
				writeStringToFile(buf, file, indentation);
				sprintf_s(buf, "args[%d]->%s(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), (void**)&a%d)", argIndex,
					parameterNode->isAllowNull() ? "castToPrimitivePtrAllowNull" : "castToPrimitivePtr", typeName.c_str(), paramIndex);
			}
			break;
		case enum_type:
			if (parameterNode->isByValue())
			{
				sprintf_s(buf, "%s a%d;\n", typeName.c_str(), paramIndex);
				writeStringToFile(buf, file, indentation);
				sprintf_s(buf, "args[%d]->castToEnum(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), &a%d)", argIndex, typeName.c_str(), paramIndex);
			}
			else
			{
				sprintf_s(buf, "%s%s* a%d;\n", strConstant, typeName.c_str(), paramIndex);
				writeStringToFile(buf, file, indentation);
				sprintf_s(buf, "args[%d]->%s(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), (void**)&a%d)", argIndex,
					parameterNode->isAllowNull() ? "castToEnumPtrAllowNull" : "castToEnumPtr", typeName.c_str(), paramIndex);
			}
			break;
		case value_type:
			sprintf_s(buf, "%s%s* a%d;\n", strConstant, typeName.c_str(), paramIndex);
			writeStringToFile(buf, file, indentation);
			sprintf_s(buf, "args[%d]->%s(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), (void**)&a%d)", argIndex,
				parameterNode->isAllowNull() ? "castToValuePtrAllowNull" : "castToValuePtr", typeName.c_str(), paramIndex);
			break;
		case reference_type:
			sprintf_s(buf, "%s%s* a%d;\n", strConstant, typeName.c_str(), paramIndex);
			writeStringToFile(buf, file, indentation);
			sprintf_s(buf, "args[%d]->%s(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), (void**)&a%d)", argIndex,
				parameterNode->isAllowNull() ? "castToReferencePtrAllowNull" : "castToReferencePtr", typeName.c_str(), paramIndex);
			break;
		default:
			assert(false);
		}
		if (checkType)
		{
			writeStringToFile("if(!", file, indentation);
			writeStringToFile(buf, file, 0);
			writeStringToFile(")\n", file, 0);
			writeStringToFile("{\n", file, indentation);
			sprintf_s(buf, "return ::pafcore::e_invalid_arg_type_%d;\n", paramIndex + 1);
			writeStringToFile(buf, file, indentation + 1);
			writeStringToFile("}\n", file, indentation);
		}
		else
		{
			writeStringToFile(buf, file, indentation);
			writeStringToFile(";\n", file, 0);
		}
		if (parameterNode->isByDecRefPtr())
		{
			if (reference_type == typeCategory)
			{
				sprintf_s(buf, "if(a%d)\n", paramIndex);
				writeStringToFile(buf, file, indentation);
				writeStringToFile("{\n", file, indentation);
				sprintf_s(buf, "a%d->addRef();\n", paramIndex);
				writeStringToFile(buf, file, indentation + 1);
				writeStringToFile("}\n", file, indentation);
			}
			else
			{
				sprintf_s(buf, "args[%d]->unhold();\n", argIndex);
				writeStringToFile(buf, file, indentation);
			}
		}
	}
	else
	{
		sprintf_s(buf, "%s* a%d = 0;\n", typeName.c_str(), paramIndex);
		writeStringToFile(buf, file, indentation);
	}
}

void writeMetaMethodImpl_UseParam(ClassNode* classNode, TemplateArguments* templateArguments, ParameterNode* parameterNode, size_t paramIndex, FILE* file)
{
	char buf[4096];
	std::string typeName;
	TypeCategory typeCategory = CalcTypeNativeName(typeName, parameterNode->m_typeName, templateArguments);
	if (parameterNode->isInput())
	{
		if (primitive_type == typeCategory || enum_type == typeCategory)
		{
			if (parameterNode->isByRef())
			{
				if (parameterNode->isConstant())
				{
					sprintf_s(buf, "*(const %s*)&a%d", typeName.c_str(), paramIndex);

				}
				else
				{
					sprintf_s(buf, "*a%d", paramIndex);
				}
			}
			else
			{
				sprintf_s(buf, "a%d", paramIndex);
			}
		}
		else
		{
			if (parameterNode->isByPtr())
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
		if (parameterNode->isOutputPtr())
		{
			sprintf_s(buf, "&a%d", paramIndex);
		}
		else
		{
			assert(parameterNode->isOutputRef());
			sprintf_s(buf, "a%d", paramIndex);
		}
	}
	if (0 != paramIndex)
	{
		writeStringToFile(", ", 2, file, 0);
	}
	writeStringToFile(buf, file, 0);
}

void writeMetaMethodImpl_AssignOutputParam(ClassNode* classNode, TemplateArguments* templateArguments, ParameterNode* parameterNode, size_t argIndex, size_t paramIndex, FILE* file, int indentation)
{
	char buf[4096];
	std::string typeName;
	TypeCategory typeCategory = CalcTypeNativeName(typeName, parameterNode->m_typeName, templateArguments);

	if (parameterNode->isArray())
	{
		assert(parameterNode->isByIncRefPtr());
		sprintf_s(buf, "args[%d]->assignArray(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), a%d, paf_new_array_size_of<%s>(a%d), %s, %s);\n",
			argIndex, typeName.c_str(), paramIndex, typeName.c_str(), paramIndex, parameterNode->isConstant() ? "true" : "false", s_variantSemantic_ByNewArray);
	}
	else
	{
		const char* varSemantic;
		if (parameterNode->isByIncRefPtr())
		{
			varSemantic = s_variantSemantic_ByNewPtr;
		}
		else
		{
			varSemantic = s_variantSemantic_ByPtr;
		}

		switch (typeCategory)
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
	char buf[4096];
	if (methodNode->m_resultArray)
	{
		assert(methodNode->byNew());
		sprintf_s(buf, "result->assignArray(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), res, paf_new_array_size_of<%s>(res), %s, %s);\n",
			typeName.c_str(), typeName.c_str(), methodNode->m_resultConst ? "true" : "false", s_variantSemantic_ByNewArray);
		writeStringToFile(buf, file, indentation);
		return;
	}


	const char* varSemantic;
	if (methodNode->byRef())
	{
		varSemantic = s_variantSemantic_ByRef;
	}
	else if (methodNode->byPtr())
	{
		varSemantic = s_variantSemantic_ByPtr;
	}
	else if (methodNode->byNew())
	{
		varSemantic = s_variantSemantic_ByNewPtr;
	}
	else
	{
		assert(methodNode->byValue());
		varSemantic = s_variantSemantic_ByValue;
	}

	if (methodNode->byValue())
	{
		switch (typeCategory)
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
				typeName.c_str(), methodNode->m_resultConst ? "true" : "false", s_variantSemantic_ByNewPtr);
			break;
		case reference_type:
			sprintf_s(buf, "result->assignReferencePtr(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), res, %s, %s);\n",
				typeName.c_str(), methodNode->m_resultConst ? "true" : "false", s_variantSemantic_ByNewPtr);
			break;
		default:
			assert(false);
		}
	}
	else
	{
		switch (typeCategory)
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


void writeMetaMethodImpl_Call(ClassNode* classNode, TemplateArguments* templateArguments, MethodNode* methodNode, std::vector<ParameterNode*>& parameterNodes, FILE* file, int indentation)
{
	char buf[4096];
	std::string typeName;
	std::string className;
	classNode->getNativeName(className, templateArguments);
	TypeCategory typeCategory = CalcTypeNativeName(typeName, methodNode->m_resultTypeName, templateArguments);

	IdentifyNode* methodNameNode = methodNode->m_nativeName ? methodNode->m_nativeName : methodNode->m_name;

	size_t paramCount = parameterNodes.size();
	if (void_type == typeCategory && 0 == methodNode->m_passing)
	{
		writeStringToFile("", 0, file, indentation);
	}
	else
	{
		if (methodNode->byValue())
		{
			if (primitive_type == typeCategory || enum_type == typeCategory)
			{
				sprintf_s(buf, "%s res = ", typeName.c_str());
			}
			else
			{
				sprintf_s(buf, "%s* res = paf_new %s(", typeName.c_str(), typeName.c_str());
			}
		}
		else
		{
			sprintf_s(buf, "%s%s* res = %s", methodNode->m_resultConst ? "const " : "", typeName.c_str(), methodNode->byRef() ? "&" : "");
		}
		writeStringToFile(buf, file, indentation);
	}
	if (methodNode->isStatic())
	{
		if (methodNode->m_nativeName)
		{
			sprintf_s(buf, "%s(", methodNameNode->m_str.c_str());
		}
		else
		{
			sprintf_s(buf, "%s::%s(", className.c_str(), methodNameNode->m_str.c_str());
		}
	}
	else
	{
		if (snt_method == methodNode->m_nodeType)
		{
			if (methodNameNode->m_str.find(':') != std::string::npos)
			{
				sprintf_s(buf, "%s(self%s", methodNameNode->m_str.c_str(), 0 == paramCount ? "" : ", ");
			}
			else
			{
				sprintf_s(buf, "self->%s(", methodNameNode->m_str.c_str());
			}
		}
		else
		{
			assert(snt_operator == methodNode->m_nodeType);
			OperatorNode* operatorNode = static_cast<OperatorNode*>(methodNode);
			if ('(' == operatorNode->m_sign->m_nodeType)
			{
				sprintf_s(buf, "(*self)(");
			}
			else if ('[' == operatorNode->m_sign->m_nodeType)
			{
				sprintf_s(buf, "(*self)[");
			}
			else if (0 == paramCount
				&& snt_operator_post_inc != operatorNode->m_sign->m_nodeType
				&& snt_operator_post_dec != operatorNode->m_sign->m_nodeType)
			{
				std::string opStr;
				operatorNode->getOperatorString(opStr);
				sprintf_s(buf, "%s(*self)", opStr.c_str());
			}
			else
			{
				bool unary = 0 == paramCount;
				const char* blank = unary ? "" : " ";
				std::string opStr;
				operatorNode->getOperatorString(opStr);
				sprintf_s(buf, "%s(*self)%s%s%s", unary ? "" : "(", blank, opStr.c_str(), blank);
			}
		}
	}
	writeStringToFile(buf, file, 0);
	for (size_t i = 0; i < paramCount; ++i)
	{
		ParameterNode* parameterNode = parameterNodes[i];
		writeMetaMethodImpl_UseParam(classNode, templateArguments, parameterNode, i, file);
	}
	if (snt_method == methodNode->m_nodeType)
	{
		writeStringToFile(")", file, 0);
	}
	else
	{
		assert(snt_operator == methodNode->m_nodeType);
		OperatorNode* operatorNode = static_cast<OperatorNode*>(methodNode);
		if ('(' == operatorNode->m_sign->m_nodeType)
		{
			writeStringToFile(")", file, 0);
		}
		else if ('[' == operatorNode->m_sign->m_nodeType)
		{
			writeStringToFile("]", file, 0);
		}
		else
		{
			if (0 != paramCount)
			{
				writeStringToFile(")", file, 0);
			}
		}
	}
	if (methodNode->byValue() && (value_type == typeCategory || reference_type == typeCategory))
	{
		writeStringToFile(");\n", file, 0);
	}
	else
	{
		writeStringToFile(";\n", file, 0);
	}
	if (!(void_type == typeCategory && 0 == methodNode->m_passing))
	{
		writeMetaMethodImpl_AssignResult(typeName, typeCategory, methodNode, file, indentation);
	}
}

void writeMetaMethodImpl_OneOverload(ClassNode* classNode, TemplateArguments* templateArguments,
	MethodNode* methodNode, bool isStatic, bool noOverloads, FILE* file, int indentation)
{
	assert(methodNode->isStatic() == isStatic);

	std::vector<ParameterNode*> parameterNodes;
	methodNode->m_parameterList->collectParameterNodes(parameterNodes);
	size_t paramCount = parameterNodes.size();

	if (!isStatic)
	{
		writeMetaMethodImpl_CastSelf(classNode, templateArguments, methodNode, noOverloads, file, indentation);
	}
	for (size_t i = 0; i < paramCount; ++i)
	{
		ParameterNode* parameterNode = parameterNodes[i];
		size_t argIndex = isStatic ? i : i + 1;
		writeMetaMethodImpl_CastParam(classNode, templateArguments, parameterNode, argIndex, i, noOverloads, file, indentation);
	}
	writeMetaMethodImpl_Call(classNode, templateArguments, methodNode, parameterNodes, file, indentation);
	for (size_t i = 0; i < paramCount; ++i)
	{
		ParameterNode* parameterNode = parameterNodes[i];
		if (parameterNode->isOutput())
		{
			size_t argIndex = isStatic ? i : i + 1;
			writeMetaMethodImpl_AssignOutputParam(classNode, templateArguments, parameterNode, argIndex, i, file, indentation);
		}
	}
	writeStringToFile("return ::pafcore::s_ok;\n", file, indentation);
}

void writeMetaMethodImpl_SameParamCount(ClassNode* classNode, TemplateArguments* templateArguments,
	std::vector<MethodNode*>::iterator begin, std::vector<MethodNode*>::iterator end,
	bool isStatic, size_t methodIndex, size_t overloadIndex, size_t maxParamCount, FILE* file, int indentation)
{
	char buf[4096];

	size_t overloadCount = end - begin;
	size_t paramCount = (*begin)->getParameterCount();
	size_t argCount = isStatic ? paramCount : paramCount + 1;

	sprintf_s(buf, "if(%d %s numArgs)\n", argCount, (paramCount == maxParamCount && !g_options.m_strictArgumentsCount) ? "<=" : "==");
	writeStringToFile(buf, file, indentation);
	writeStringToFile("{\n", file, indentation);

	if (1 == overloadCount)
	{
		writeMetaMethodImpl_OneOverload(classNode, templateArguments, *begin, isStatic, true, file, indentation + 1);
	}
	else
	{
		sprintf_s(buf, "size_t candidates[%d];\n", overloadCount);
		writeStringToFile(buf, file, indentation + 1);
		sprintf_s(buf, "char argMatches[%d];\n", overloadCount * argCount);
		writeStringToFile(buf, file, indentation + 1);
		sprintf_s(buf, "size_t matched = ::pafcore::Overload::Resolution(&GetSingleton()->%s[%d].m_overloads[%d], args, %d, %d, candidates, argMatches);\n",
			isStatic ? "m_staticMethods" : "m_instanceMethods", methodIndex, overloadIndex, argCount, overloadCount);
		writeStringToFile(buf, file, indentation + 1);
		sprintf_s(buf, "switch(matched)\n");
		writeStringToFile(buf, file, indentation + 1);
		writeStringToFile("{\n", file, indentation + 1);
		for (size_t i = 0; i < overloadCount; ++i)
		{
			sprintf_s(buf, "case %d:\n", i);
			writeStringToFile(buf, file, indentation + 1);
			writeStringToFile("{\n", file, indentation + 1);
			writeMetaMethodImpl_OneOverload(classNode, templateArguments, *(begin + i), isStatic, true, file, indentation + 2);
			writeStringToFile("}\n", file, indentation + 1);
		}
		sprintf_s(buf, "case %d:\n", overloadCount);
		writeStringToFile(buf, file, indentation + 1);
		writeStringToFile("return ::pafcore::e_no_match_overload;\n", file, indentation + 2);
		sprintf_s(buf, "case %d:\n", overloadCount + 1);
		writeStringToFile(buf, file, indentation + 1);
		writeStringToFile("return ::pafcore::e_ambiguous_overload;\n", file, indentation + 2);
		writeStringToFile("}\n", file, indentation + 1);
	}

	writeStringToFile("}\n", file, indentation);
}

void writeMetaMethodImpl(ClassNode* classNode, TemplateArguments* templateArguments,
	const char* funcName, std::vector<MethodNode*>::iterator begin, std::vector<MethodNode*>::iterator end,
	bool isStatic, size_t methodIndex, FILE* file, int indentation)
{
	char buf[4096];
	std::string typeName;
	std::string metaClassName;
	GetMetaTypeFullName(metaClassName, classNode, templateArguments);

	writeStringToFile(g_metaMethodImplPrefix, sizeof(g_metaMethodImplPrefix) - 1, file, indentation);
	sprintf_s(buf, "%s::%s_%s", metaClassName.c_str(),
		classNode->m_name->m_str.c_str(), funcName);
	writeStringToFile(buf, file);
	writeStringToFile(g_metaMethodImplPostfix, sizeof(g_metaMethodImplPostfix) - 1, file);
	writeStringToFile("{\n", file, indentation);

	std::vector<MethodNode*>::iterator first = begin;
	std::vector<MethodNode*>::iterator last = begin;
	size_t maxParamCount = (*(end - 1))->getParameterCount();
	size_t overloadIndex = 0;
	for (; first != end;)
	{
		++last;
		if (last == end || (*last)->getParameterCount() != (*first)->getParameterCount())
		{
			writeMetaMethodImpl_SameParamCount(classNode, templateArguments, first, last, isStatic, methodIndex, overloadIndex, maxParamCount, file, indentation + 1);
			overloadIndex += last - first;
			first = last;
		}
	}
	writeStringToFile("return ::pafcore::e_invalid_arg_num;\n", file, indentation + 1);
	writeStringToFile("}\n\n", file, indentation);
}

void writeMetaMethodImpls(ClassNode* classNode, TemplateArguments* templateArguments, std::vector<MethodNode*>& methodNodes, bool isStatic, FILE* file, int indentation)
{
	std::vector<MethodNode*>::iterator first = methodNodes.begin();
	std::vector<MethodNode*>::iterator last = first;
	std::vector<MethodNode*>::iterator end = methodNodes.end();
	size_t methodIndex = 0;
	for (; first != end;)
	{
		++last;
		if (last == end || (*last)->m_name->m_str != (*first)->m_name->m_str)
		{
			writeMetaMethodImpl(classNode, templateArguments, (*first)->m_name->m_str.c_str(), first, last, isStatic, methodIndex, file, indentation);
			++methodIndex;
			first = last;
		}
	}
}

void writeMetaConstructor_attributesForType(std::map<SyntaxNodeImpl*, size_t> attributesOffsets, SyntaxNodeImpl* memberNode, FILE* file, int indentation)
{
	char buf[4096];
	auto it = attributesOffsets.find(memberNode);
	if (it != attributesOffsets.end())
	{
		sprintf(buf, "m_attributes = &s_attributeses[%d];\n", it->second);
		writeStringToFile(buf, file, indentation);
	}
}

struct AttributeOffsetAndCount
{
	SyntaxNodeImpl* node;
	size_t offset;
	size_t count;
};

template<typename T>
void writeMetaConstructor_Attributes_Member(std::vector<AttributeOffsetAndCount>& attributeOffsetAndCounts, size_t& offset,
	T* memberNode, FILE* file, int indentation)
{
	AttributeListNode* attributeList = memberNode->m_attributeList;
	if (attributeList)
	{
		std::vector<AttributeNode*> attributeNodes;
		attributeList->collectAttributeNodes(attributeNodes);
		std::sort(attributeNodes.begin(), attributeNodes.end(), CompareAttributePtr());
		size_t count = attributeNodes.size();
		for (size_t i = 0; i < count; ++i)
		{
			AttributeNode* attributeNode = attributeNodes[i];
			writeStringToFile("{ \"", file, indentation);
			writeStringToFile(attributeNode->m_name->m_str.c_str(), file);
			if (attributeNode->m_u8content)
			{
				writeStringToFile("\", u8\"", file);
			}
			else
			{
				writeStringToFile("\", \"", file);
			}
			if (attributeNode->m_content)
			{
				writeStringToFile(attributeNode->m_content->m_str.c_str(), file);
			}
			writeStringToFile("\" },\n", file);
		}
		AttributeOffsetAndCount aoac;
		aoac.node = memberNode;
		aoac.offset = offset;
		aoac.count = count;
		attributeOffsetAndCounts.push_back(aoac);
		offset += count;
	}
}

void writeMetaConstructor_Attributes_Method(std::vector<AttributeOffsetAndCount>& attributeOffsetAndCounts, size_t& offset,
	std::vector<MethodNode*>::iterator first, std::vector<MethodNode*>::iterator last, FILE* file, int indentation)
{
	std::vector<AttributeNode*> attributeNodes;
	for (auto it = first; it != last; ++it)
	{
		MethodNode* methodNode = *it;
		AttributeListNode* attributeList = methodNode->m_attributeList;
		if (attributeList)
		{
			attributeList->collectAttributeNodes(attributeNodes);
		}
	}
	if (!attributeNodes.empty())
	{
		std::sort(attributeNodes.begin(), attributeNodes.end(), CompareAttributePtr());
		size_t count = attributeNodes.size();
		for (size_t i = 0; i < count; ++i)
		{
			AttributeNode* attributeNode = attributeNodes[i];
			writeStringToFile("{ \"", file, indentation);
			writeStringToFile(attributeNode->m_name->m_str.c_str(), file);
			writeStringToFile("\", u8\"", file);
			if (attributeNode->m_content)
			{
				writeStringToFile(attributeNode->m_content->m_str.c_str(), file);
			}
			writeStringToFile("\" },\n", file);
		}
		AttributeOffsetAndCount aoac;
		aoac.node = *first;
		aoac.offset = offset;
		aoac.count = count;
		attributeOffsetAndCounts.push_back(aoac);
		offset += count;
	}
}

template<typename T>
void writeMetaConstructor_Attributes_Members(std::vector<AttributeOffsetAndCount>& attributeOffsetAndCounts, size_t& offset,
	std::vector<T*>& memberNodes, FILE* file, int indentation)
{
	size_t count = memberNodes.size();
	for (size_t i = 0; i < count; ++i)
	{
		T* node = memberNodes[i];
		writeMetaConstructor_Attributes_Member(attributeOffsetAndCounts, offset, node, file, indentation);
	}
}

void writeMetaConstructor_Attributes_Methods(std::vector<AttributeOffsetAndCount>& attributeOffsetAndCounts, size_t& offset,
	std::vector<MethodNode*>& methodNodes, FILE* file, int indentation)
{
	std::vector<MethodNode*>::iterator begin = methodNodes.begin();
	std::vector<MethodNode*>::iterator end = methodNodes.end();
	std::vector<MethodNode*>::iterator first = begin;
	std::vector<MethodNode*>::iterator last = begin;
	for (; first != end;)
	{
		++last;
		if (last == end || (*last)->m_name->m_str != (*first)->m_name->m_str)
		{
			writeMetaConstructor_Attributes_Method(attributeOffsetAndCounts, offset, first, last, file, indentation);
			first = last;
		}
	}
}

template<typename T>
bool noAttributes(T& t)
{
	size_t count = t.size();
	for (size_t i = 0; i < count; ++i)
	{
		AttributeListNode* node = t[i]->m_attributeList;
		if (node)
		{
			return false;
		}
	}
	return true;
}


void writeMetaConstructor_Attributeses(std::map<SyntaxNodeImpl*, size_t>& attributessOffsets,
	ClassNode* classNode,
	std::vector<FieldNode*>& staticFieldNodes,
	std::vector<PropertyNode*>& staticPropertyNodes,
	std::vector<MethodNode*>& staticMethodNodes,
	std::vector<FieldNode*>& fieldNodes,
	std::vector<PropertyNode*>& propertyNodes,
	std::vector<MethodNode*>& methodNodes,
	FILE* file, int indentation)
{
	char buf[4096];
	if (0 == classNode->m_attributeList
		&& noAttributes(staticFieldNodes)
		&& noAttributes(staticPropertyNodes)
		&& noAttributes(staticMethodNodes)
		&& noAttributes(fieldNodes)
		&& noAttributes(propertyNodes)
		&& noAttributes(methodNodes))
	{
		return;
	}

	size_t offset = 0;
	std::vector<AttributeOffsetAndCount> attributeOffsetAndCounts;

	writeStringToFile("static ::pafcore::Attribute s_attributes[] = \n", file, indentation);
	writeStringToFile("{\n", file, indentation);

	writeMetaConstructor_Attributes_Member(attributeOffsetAndCounts, offset, classNode, file, indentation + 1);
	writeMetaConstructor_Attributes_Members(attributeOffsetAndCounts, offset, staticFieldNodes, file, indentation + 1);
	writeMetaConstructor_Attributes_Members(attributeOffsetAndCounts, offset, staticPropertyNodes, file, indentation + 1);
	writeMetaConstructor_Attributes_Methods(attributeOffsetAndCounts, offset, staticMethodNodes, file, indentation + 1);
	writeMetaConstructor_Attributes_Members(attributeOffsetAndCounts, offset, fieldNodes, file, indentation + 1);
	writeMetaConstructor_Attributes_Members(attributeOffsetAndCounts, offset, propertyNodes, file, indentation + 1);
	writeMetaConstructor_Attributes_Methods(attributeOffsetAndCounts, offset, methodNodes, file, indentation + 1);
	writeStringToFile("};\n", file, indentation);

	size_t size = attributeOffsetAndCounts.size();

	writeStringToFile("static ::pafcore::Attributes s_attributeses[] = \n", file, indentation);
	writeStringToFile("{\n", file, indentation);
	for (size_t i = 0; i < size; ++i)
	{
		AttributeOffsetAndCount& aoac = attributeOffsetAndCounts[i];
		sprintf(buf, "{ %d, &s_attributes[%d] },\n", aoac.count, aoac.offset);
		writeStringToFile(buf, file, indentation + 1);
		attributessOffsets.insert(std::make_pair(aoac.node, i));
	}
	writeStringToFile("};\n", file, indentation);
}

void writeEnumMetaConstructor_Attributeses(std::map<SyntaxNodeImpl*, size_t>& attributessOffsets,
	EnumNode* enumNode, std::vector<EnumeratorNode*>& enumeratorNodes,
	FILE* file, int indentation)
{
	char buf[4096];
	if (0 == enumNode->m_attributeList
		&& noAttributes(enumeratorNodes))
	{
		return;
	}
	size_t offset = 0;
	std::vector<AttributeOffsetAndCount> attributeOffsetAndCounts;
	writeStringToFile("static ::pafcore::Attribute s_attributes[] = \n", file, indentation);
	writeStringToFile("{\n", file, indentation);
	writeMetaConstructor_Attributes_Member(attributeOffsetAndCounts, offset, enumNode, file, indentation + 1);
	writeMetaConstructor_Attributes_Members(attributeOffsetAndCounts, offset, enumeratorNodes, file, indentation + 1);
	writeStringToFile("};\n", file, indentation);

	size_t size = attributeOffsetAndCounts.size();

	writeStringToFile("static ::pafcore::Attributes s_attributeses[] = \n", file, indentation);
	writeStringToFile("{\n", file, indentation);
	for (size_t i = 0; i < size; ++i)
	{
		AttributeOffsetAndCount& aoac = attributeOffsetAndCounts[i];
		sprintf(buf, "{ %d, &s_attributes[%d] },\n", aoac.count, aoac.offset);
		writeStringToFile(buf, file, indentation + 1);
		attributessOffsets.insert(std::make_pair(aoac.node, i));
	}
	writeStringToFile("};\n", file, indentation);
}

void writeTypeDefMetaConstructor_Attributeses(std::map<SyntaxNodeImpl*, size_t>& attributessOffsets,
	MemberNode* memberNode, FILE* file, int indentation)
{
	char buf[4096];
	if (0 == memberNode->m_attributeList)
	{
		return;
	}
	size_t offset = 0;
	std::vector<AttributeOffsetAndCount> attributeOffsetAndCounts;
	writeStringToFile("static ::pafcore::Attribute s_attributes[] = \n", file, indentation);
	writeStringToFile("{\n", file, indentation);
	writeMetaConstructor_Attributes_Member(attributeOffsetAndCounts, offset, memberNode, file, indentation + 1);
	writeStringToFile("};\n", file, indentation);

	size_t size = attributeOffsetAndCounts.size();

	writeStringToFile("static ::pafcore::Attributes s_attributeses[] = \n", file, indentation);
	writeStringToFile("{\n", file, indentation);
	for (size_t i = 0; i < size; ++i)
	{
		AttributeOffsetAndCount& aoac = attributeOffsetAndCounts[i];
		sprintf(buf, "{ %d, &s_attributes[%d] },\n", aoac.count, aoac.offset);
		writeStringToFile(buf, file, indentation + 1);
		attributessOffsets.insert(std::make_pair(aoac.node, i));
	}
	writeStringToFile("};\n", file, indentation);
}

void writeMetaConstructor_Fields(ClassNode* classNode, TemplateArguments* templateArguments, std::map<SyntaxNodeImpl*, size_t>& attributesOffsets,
	std::vector<FieldNode*>& fieldNodes, bool isStatic, FILE* file, int indentation)
{
	char buf[4096];
	char strAttributes[256];
	if (fieldNodes.empty())
	{
		return;
	}
	std::string className;
	classNode->getNativeName(className, templateArguments);
	size_t count = fieldNodes.size();

	if (isStatic)
	{
		writeStringToFile("static ::pafcore::StaticField s_staticFields[] = \n", file, indentation);
	}
	else
	{
		writeStringToFile("static ::pafcore::InstanceField s_instanceFields[] = \n", file, indentation);
	}
	writeStringToFile("{\n", file, indentation);

	for (size_t i = 0; i < count; ++i)
	{
		FieldNode* fieldNode = fieldNodes[i];

		if (fieldNode->m_attributeList)
		{
			auto it = attributesOffsets.find(fieldNode);
			assert(it != attributesOffsets.end());
			sprintf_s(strAttributes, "&s_attributeses[%d]", it->second);
		}
		else
		{
			strcpy_s(strAttributes, "0");
		}

		IdentifyNode* fieldNameNode = fieldNode->m_nativeName ? fieldNode->m_nativeName : fieldNode->m_name;
		char arraySize[512];
		if (fieldNode->isArray())
		{
			sprintf_s(arraySize, "paf_field_array_size_of(%s, %s)", className.c_str(), fieldNameNode->m_str.c_str());
		}
		else
		{
			strcpy_s(arraySize, "0");
		}
		std::string typeName;
		TypeCategory typeCategory = CalcTypeNativeName(typeName, fieldNode->m_typeName, templateArguments);
		const char* typeCompound = "::pafcore::Metadata::tc_none";
		if (fieldNode->isPointer())
		{
			typeCompound = "::pafcore::Metadata::tc_pointer";
		}
		else if (fieldNode->isArray())
		{
			typeCompound = "::pafcore::Metadata::tc_array";
		}
		if (isStatic)
		{
			sprintf_s(buf, "::pafcore::StaticField(\"%s\", %s, RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), (size_t)&%s::%s, %s, %s, %s),\n",
				fieldNode->m_name->m_str.c_str(), strAttributes, typeName.c_str(), className.c_str(), fieldNameNode->m_str.c_str(),
				arraySize, fieldNode->isConstant() ? "true" : "false", typeCompound);
		}
		else
		{
			sprintf_s(buf, "::pafcore::InstanceField(\"%s\", %s, GetSingleton(), RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), offsetof(%s, %s), %s, %s, %s),\n",
				fieldNode->m_name->m_str.c_str(), strAttributes, typeName.c_str(), className.c_str(), fieldNameNode->m_str.c_str(),
				arraySize, fieldNode->isConstant() ? "true" : "false", typeCompound);
		}

		writeStringToFile(buf, file, indentation + 1);
	}
	writeStringToFile("};\n", file, indentation);

	if (isStatic)
	{
		writeStringToFile("m_staticFields = s_staticFields;\n", file, indentation);
		writeStringToFile("m_staticFieldCount = paf_array_size_of(s_staticFields);\n", file, indentation);
	}
	else
	{
		writeStringToFile("m_instanceFields = s_instanceFields;\n", file, indentation);
		writeStringToFile("m_instanceFieldCount = paf_array_size_of(s_instanceFields);\n", file, indentation);
	}
}

void writeMetaConstructor_Properties(ClassNode* classNode, TemplateArguments* templateArguments, std::map<SyntaxNodeImpl*, size_t> attributesOffsets,
	std::vector<PropertyNode*>& propertyNodes, bool isStatic, FILE* file, int indentation)
{
	char buf[4096];
	char strAttributes[256];
	char getterFunc[256];
	char setterFunc[256];
	char valueType[256];

	if (propertyNodes.empty())
	{
		return;
	}
	size_t count = propertyNodes.size();

	if (isStatic)
	{
		writeStringToFile("static ::pafcore::StaticProperty s_staticProperties[] = \n", file, indentation);
	}
	else
	{
		writeStringToFile("static ::pafcore::InstanceProperty s_instanceProperties[] = \n", file, indentation);
	}

	writeStringToFile("{\n", file, indentation);

	for (size_t i = 0; i < count; ++i)
	{
		PropertyNode* propertyNode = propertyNodes[i];
		if (propertyNode->m_attributeList)
		{
			auto it = attributesOffsets.find(propertyNode);
			assert(it != attributesOffsets.end());
			sprintf_s(strAttributes, "&s_attributeses[%d]", it->second);
		}
		else
		{
			strcpy_s(strAttributes, "0");
		}

		bool isPtr = propertyNode->isByPtr();
		std::string typeName;
		TypeCategory typeCategory = CalcTypeNativeName(typeName, propertyNode->m_typeName, templateArguments);
		sprintf_s(valueType, "RuntimeTypeOf<%s>::RuntimeType::GetSingleton()", typeName.c_str());

		if (propertyNode->m_get)
		{
			sprintf_s(getterFunc, "%s_get_%s", classNode->m_name->m_str.c_str(), propertyNode->m_name->m_str.c_str());
		}
		else
		{
			strcpy_s(getterFunc, "0");
		}
		if (propertyNode->m_set)
		{
			sprintf_s(setterFunc, "%s_set_%s", classNode->m_name->m_str.c_str(), propertyNode->m_name->m_str.c_str());
		}
		else
		{
			strcpy_s(setterFunc, "0");
		}

		if (propertyNode->isFixedArray() || propertyNode->isDynamicArray())
		{
			char sizerFunc[256];
			char resizerFunc[256];
			char getIteratorFunc[256];
			char getValueFunc[256];
			sprintf_s(sizerFunc, "%s_size_%s", classNode->m_name->m_str.c_str(), propertyNode->m_name->m_str.c_str());
			sprintf_s(getIteratorFunc, "%s_getIterator_%s", classNode->m_name->m_str.c_str(), propertyNode->m_name->m_str.c_str());
			sprintf_s(getValueFunc, "%s_getValue_%s", classNode->m_name->m_str.c_str(), propertyNode->m_name->m_str.c_str());

			if (propertyNode->isDynamicArray())
			{
				sprintf_s(resizerFunc, "%s_resize_%s", classNode->m_name->m_str.c_str(), propertyNode->m_name->m_str.c_str());
			}
			else
			{
				strcpy_s(resizerFunc, "0");
			}
			if (isStatic)
			{
				sprintf_s(buf, "::pafcore::StaticProperty(\"%s\", %s, %s, %s, %s, %s, %s, %s, %s, %s),\n",
					propertyNode->m_name->m_str.c_str(), strAttributes,
					valueType, isPtr ? "true" : "false",
					getterFunc, setterFunc, sizerFunc, resizerFunc, getIteratorFunc, getValueFunc);
			}
			else
			{
				sprintf_s(buf, "::pafcore::InstanceProperty(\"%s\", %s, GetSingleton(), %s, %s, %s, %s, %s, %s, %s, %s),\n",
					propertyNode->m_name->m_str.c_str(), strAttributes,
					valueType, isPtr ? "true" : "false",
					getterFunc, setterFunc, sizerFunc, resizerFunc, getIteratorFunc, getValueFunc);
			}
		}
		else if (propertyNode->isList())
		{
			char pushBackFunc[256];
			char getIteratorFunc[256];
			char getValueFunc[256];
			char insertFunc[256];
			char eraseFunc[256];

			sprintf_s(pushBackFunc, "%s_pushBack_%s", classNode->m_name->m_str.c_str(), propertyNode->m_name->m_str.c_str());
			sprintf_s(getIteratorFunc, "%s_getIterator_%s", classNode->m_name->m_str.c_str(), propertyNode->m_name->m_str.c_str());
			sprintf_s(getValueFunc, "%s_getValue_%s", classNode->m_name->m_str.c_str(), propertyNode->m_name->m_str.c_str());
			sprintf_s(insertFunc, "%s_insert_%s", classNode->m_name->m_str.c_str(), propertyNode->m_name->m_str.c_str());
			sprintf_s(eraseFunc, "%s_erase_%s", classNode->m_name->m_str.c_str(), propertyNode->m_name->m_str.c_str());

			if (isStatic)
			{
				sprintf_s(buf, "::pafcore::StaticProperty(\"%s\", %s, %s, %s, %s, %s, %s, %s, %s),\n",
					propertyNode->m_name->m_str.c_str(), strAttributes,
					valueType, isPtr ? "true" : "false",
					pushBackFunc, getIteratorFunc, getValueFunc, insertFunc, eraseFunc);
			}
			else
			{
				sprintf_s(buf, "::pafcore::InstanceProperty(\"%s\", %s, GetSingleton(), %s, %s, %s, %s, %s, %s, %s),\n",
					propertyNode->m_name->m_str.c_str(), strAttributes,
					valueType, isPtr ? "true" : "false",
					pushBackFunc, getIteratorFunc, getValueFunc, insertFunc, eraseFunc);
			}
		}
		else if (propertyNode->isMap())
		{
			char getIteratorFunc[256];
			char getKeyFunc[256];
			char getValueFunc[256];
			char keyType[256];
			bool isKeyPtr;

			sprintf_s(getIteratorFunc, "%s_getIterator_%s", classNode->m_name->m_str.c_str(), propertyNode->m_name->m_str.c_str());
			sprintf_s(getKeyFunc, "%s_getKey_%s", classNode->m_name->m_str.c_str(), propertyNode->m_name->m_str.c_str());
			sprintf_s(getValueFunc, "%s_getValue_%s", classNode->m_name->m_str.c_str(), propertyNode->m_name->m_str.c_str());
			std::string keyTypeName;
			TypeCategory keyTypeCategory = CalcTypeNativeName(keyTypeName, propertyNode->m_keyTypeName, templateArguments);
			sprintf_s(keyType, "RuntimeTypeOf<%s>::RuntimeType::GetSingleton()", keyTypeName.c_str());
			isKeyPtr = propertyNode->isKeyByPtr();
			if (isStatic)
			{
				sprintf_s(buf, "::pafcore::StaticProperty(\"%s\", %s, %s, %s, %s, %s, %s, %s, %s, %s, %s),\n",
					propertyNode->m_name->m_str.c_str(), strAttributes,
					valueType, isPtr ? "true" : "false", keyType, isKeyPtr ? "true" : "false",
					getterFunc, setterFunc, getIteratorFunc, getKeyFunc, getValueFunc);
			}
			else
			{
				sprintf_s(buf, "::pafcore::InstanceProperty(\"%s\", %s, GetSingleton(), %s, %s, %s, %s, %s, %s, %s, %s, %s),\n",
					propertyNode->m_name->m_str.c_str(), strAttributes,
					valueType, isPtr ? "true" : "false", keyType, isKeyPtr ? "true" : "false",
					getterFunc, setterFunc, getIteratorFunc, getKeyFunc, getValueFunc);
			}
		}
		else
		{
			assert(propertyNode->isSimple());

			char candidateCountFunc[256];
			char getCandidateFunc[256];
			if (propertyNode->hasCandidate())
			{
				sprintf_s(candidateCountFunc, "%s_candidateCount_%s", classNode->m_name->m_str.c_str(), propertyNode->m_name->m_str.c_str());
				sprintf_s(getCandidateFunc, "%s_getCandidate_%s", classNode->m_name->m_str.c_str(), propertyNode->m_name->m_str.c_str());
			}
			else
			{
				strcpy_s(candidateCountFunc, "0");
				strcpy_s(getCandidateFunc, "0");
			}
			if (isStatic)
			{
				sprintf_s(buf, "::pafcore::StaticProperty(\"%s\", %s, %s, %s, %s, %s, %s, %s),\n",
					propertyNode->m_name->m_str.c_str(), strAttributes,
					valueType, isPtr ? "true" : "false",
					getterFunc, setterFunc, candidateCountFunc, getCandidateFunc);
			}
			else
			{
				sprintf_s(buf, "::pafcore::InstanceProperty(\"%s\", %s, GetSingleton(), %s, %s, %s, %s, %s, %s),\n",
					propertyNode->m_name->m_str.c_str(), strAttributes,
					valueType, isPtr ? "true" : "false",
					getterFunc, setterFunc, candidateCountFunc, getCandidateFunc);
			}
		}
		writeStringToFile(buf, file, indentation + 1);
	}

	writeStringToFile("};\n", file, indentation);

	if (isStatic)
	{
		writeStringToFile("m_staticProperties = s_staticProperties;\n", file, indentation);
		writeStringToFile("m_staticPropertyCount = paf_array_size_of(s_staticProperties);\n", file, indentation);
	}
	else
	{
		writeStringToFile("m_instanceProperties = s_instanceProperties;\n", file, indentation);
		writeStringToFile("m_instancePropertyCount = paf_array_size_of(s_instanceProperties);\n", file, indentation);
	}
}

void writeMetaConstructor_Method_Result(ClassNode* classNode, TemplateArguments* templateArguments, MethodNode* methodNode, size_t index, FILE* file, int indentation)
{
	char buf[4096];
	std::string typeName;
	char passing[32];
	strcpy_s(passing, "::pafcore::Result::by_value");
	if (0 != methodNode->m_passing)
	{
		switch (methodNode->m_passing->m_nodeType)
		{
		case '&':
			strcpy_s(passing, "::pafcore::Result::by_ref");
			break;
		case '*':
			strcpy_s(passing, "::pafcore::Result::by_ptr");
			break;
		case '+':
			if (methodNode->m_resultArray)
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
	if (snt_type_name == methodNode->m_resultTypeName->m_nodeType)
	{
		TypeCategory typeCategory = CalcTypeNativeName(typeName, (TypeNameNode*)methodNode->m_resultTypeName, templateArguments);
	}
	else
	{
		typeName = "void";
	}
	sprintf_s(buf, "::pafcore::Result(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), %s, %s),\n",
		typeName.c_str(), methodNode->m_resultConst ? "true" : "false", passing);
	writeStringToFile(buf, file, indentation);
}

void writeMetaConstructor_Method_Arguments(ClassNode* classNode, TemplateArguments* templateArguments, MethodNode* methodNode, size_t index, bool isStatic, FILE* file, int indentation)
{
	char buf[4096];
	std::string typeName;
	char passing[32];
	assert(methodNode->isStatic() == isStatic);
	size_t paramCount = methodNode->getParameterCount();
	//size_t argCount = isStatic ? paramCount : paramCount + 1;

	if (0 < paramCount)
	{
		//if(!isStatic)
		//{
		//	sprintf_s(buf, "::pafcore::Argument(\"this\", GetSingleton(), ::pafcore::Argument::by_ptr, %s),\n",
		//		methodNode->isConstant() ? "true" : "false");
		//	writeStringToFile(buf, file, indentation);
		//}
		std::vector<ParameterNode*> parameterNodes;
		methodNode->m_parameterList->collectParameterNodes(parameterNodes);
		assert(parameterNodes.size() == paramCount);

		for (size_t i = 0; i < paramCount; ++i)
		{
			ParameterNode* parameterNode = parameterNodes[i];
			if (parameterNode->isByRef())
			{
				strcpy_s(passing, "::pafcore::Argument::by_ref");
			}
			else if (parameterNode->isByPtr())
			{
				strcpy_s(passing, "::pafcore::Argument::by_ptr");
			}
			else
			{
				strcpy_s(passing, "::pafcore::Argument::by_value");
			}
			TypeCategory typeCategory = CalcTypeNativeName(typeName, parameterNode->m_typeName, templateArguments);
			sprintf_s(buf, "::pafcore::Argument(\"%s\", RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), %s, %s),\n",
				parameterNode->m_name->m_str.c_str(), typeName.c_str(), passing,
				parameterNode->isConstant() ? "true" : "false");
			writeStringToFile(buf, file, indentation);
		}
	}
}

void writeMetaConstructor_Methods(ClassNode* classNode, TemplateArguments* templateArguments, std::map<SyntaxNodeImpl*, size_t> attributesOffsets,
	std::vector<MethodNode*>& methodNodes, bool isStatic, FILE* file, int indentation)
{
	char buf[4096];

	if (methodNodes.empty())
	{
		return;
	}

	//Result & Arguments
	size_t count = methodNodes.size();

	if (isStatic)
	{
		writeStringToFile("static ::pafcore::Result s_staticResults[] = \n", file, indentation);
	}
	else
	{
		writeStringToFile("static ::pafcore::Result s_instanceResults[] = \n", file, indentation);
	}
	writeStringToFile("{\n", file, indentation);
	for (size_t i = 0; i < count; ++i)
	{
		MethodNode* methodNode = methodNodes[i];
		writeMetaConstructor_Method_Result(classNode, templateArguments, methodNode, i, file, indentation + 1);
	}
	writeStringToFile("};\n", file, indentation);


	bool hasArguments = false;
	for (size_t i = 0; i < count; ++i)
	{
		MethodNode* methodNode = methodNodes[i];
		size_t paramCount = methodNode->getParameterCount();
		if (paramCount > 0)
		{
			hasArguments = true;
			break;
		}
	}

	if (hasArguments)
	{
		if (isStatic)
		{
			writeStringToFile("static ::pafcore::Argument s_staticArguments[] = \n", file, indentation);
		}
		else
		{
			writeStringToFile("static ::pafcore::Argument s_instanceArguments[] = \n", file, indentation);
		}
		writeStringToFile("{\n", file, indentation);
		for (size_t i = 0; i < count; ++i)
		{
			MethodNode* methodNode = methodNodes[i];
			writeMetaConstructor_Method_Arguments(classNode, templateArguments, methodNode, i, isStatic, file, indentation + 1);
		}
		writeStringToFile("};\n", file, indentation);
	}

	//Overloads
	if (isStatic)
	{
		writeStringToFile("static ::pafcore::Overload s_staticOverloads[] = \n", file, indentation);
	}
	else
	{
		writeStringToFile("static ::pafcore::Overload s_instanceOverloads[] = \n", file, indentation);
	}
	writeStringToFile("{\n", file, indentation);

	std::vector<MethodNode*>::iterator begin = methodNodes.begin();
	std::vector<MethodNode*>::iterator end = methodNodes.end();
	std::vector<MethodNode*>::iterator first = begin;
	std::vector<MethodNode*>::iterator last = begin;

	size_t resultOffset = 0;
	size_t argumentOffset = 0;
	for (; first != end;)
	{
		++last;
		if (last == end || (*last)->m_name->m_str != (*first)->m_name->m_str)
		{
			for (auto it = first; it != last; ++it)
			{
				char strArguments[256];
				MethodNode* methodNode = *it;
				size_t parameterCount = methodNode->getParameterCount();
				if (parameterCount > 0)
				{
					sprintf_s(strArguments, "&%s[%d]", isStatic ? "s_staticArguments" : "s_instanceArguments", argumentOffset);
				}
				else
				{
					strcpy_s(strArguments, "0");
				}
				sprintf_s(buf, "::pafcore::Overload(&%s[%d], %s, %d, %s, %s),\n",
					isStatic ? "s_staticResults" : "s_instanceResults", resultOffset,
					strArguments, parameterCount, isStatic ? "true" : "false", methodNode->isConstant() ? "true" : "false");
				writeStringToFile(buf, file, indentation + 1);
				++resultOffset;
				argumentOffset += parameterCount;
			}
			first = last;
		}
	}
	writeStringToFile("};\n", file, indentation);

	//Method
	if (isStatic)
	{
		writeStringToFile("static ::pafcore::StaticMethod s_staticMethods[] = \n", file, indentation);
	}
	else
	{
		writeStringToFile("static ::pafcore::InstanceMethod s_instanceMethods[] = \n", file, indentation);
	}
	writeStringToFile("{\n", file, indentation);

	first = begin;
	last = first;
	size_t overloadOffset = 0;

	for (; first != end;)
	{
		++last;
		if (last == end || (*last)->m_name->m_str != (*first)->m_name->m_str)
		{
			char strAttributes[256];
			const char* methodName = (*first)->m_name->m_str.c_str();
			auto it = attributesOffsets.find(*first);
			if (it != attributesOffsets.end())
			{
				sprintf_s(strAttributes, "&s_attributeses[%d]", it->second);
			}
			else
			{
				strcpy_s(strAttributes, "0");
			}
			int overloadCount = last - first;

			sprintf_s(buf, "::pafcore::%s(\"%s\", %s, %s_%s, &%s[%d], %d),\n",
				isStatic ? "StaticMethod" : "InstanceMethod",
				methodName, strAttributes, classNode->m_name->m_str.c_str(), methodName,
				isStatic ? "s_staticOverloads" : "s_instanceOverloads", overloadOffset, overloadCount);
			writeStringToFile(buf, file, indentation + 1);

			overloadOffset += overloadCount;
			first = last;
		}
	}
	writeStringToFile("};\n", file, indentation);

	if (isStatic)
	{
		writeStringToFile("m_staticMethods = s_staticMethods;\n", file, indentation);
		writeStringToFile("m_staticMethodCount = paf_array_size_of(s_staticMethods);\n", file, indentation);
	}
	else
	{
		writeStringToFile("m_instanceMethods = s_instanceMethods;\n", file, indentation);
		writeStringToFile("m_instanceMethodCount = paf_array_size_of(s_instanceMethods);\n", file, indentation);
	}
}

bool MethodNodeNameEqual(MethodNode* arg1, MethodNode* arg2)
{
	return arg1->m_name->m_str == arg2->m_name->m_str;
}

void writeMetaConstructor_Member(
	std::vector<MemberNode*>& nestedTypeNodes,
	std::vector<MemberNode*>& nestedTypeAliasNodes,
	std::vector<FieldNode*>& staticFieldNodes,
	std::vector<PropertyNode*>& staticPropertyNodes,
	const std::vector<MethodNode*>& staticMethodNodes_,
	std::vector<FieldNode*>& fieldNodes,
	std::vector<PropertyNode*>& propertyNodes,
	const std::vector<MethodNode*>& methodNodes_,
	FILE* file, int indentation)
{
	char buf[4096];

	std::vector<MethodNode*> staticMethodNodes = staticMethodNodes_;
	std::vector<MethodNode*> methodNodes = methodNodes_;

	auto it = std::unique(staticMethodNodes.begin(), staticMethodNodes.end(), MethodNodeNameEqual);
	staticMethodNodes.erase(it, staticMethodNodes.end());

	it = std::unique(methodNodes.begin(), methodNodes.end(), MethodNodeNameEqual);
	methodNodes.erase(it, methodNodes.end());

	if (nestedTypeNodes.empty() && nestedTypeAliasNodes.empty() &&
		staticFieldNodes.empty() && staticPropertyNodes.empty() && staticMethodNodes.empty()
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
	while (true)
	{
		MemberNode* current = 0;
		MemberCategory category = unknown_member;
		if (currentNestedType < nestedTypeCount)
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
		if (currentStaticProperty < staticPropertyCount)
		{
			MemberNode* memberNode = staticPropertyNodes[currentStaticProperty];
			if (0 == current || memberNode->m_name->m_str < current->m_name->m_str)
			{
				current = memberNode;
				category = static_property;
			}
		}
		if (currentStaticMethod < staticMethodCount)
		{
			MemberNode* memberNode = staticMethodNodes[currentStaticMethod];
			if (0 == current || memberNode->m_name->m_str < current->m_name->m_str)
			{
				current = memberNode;
				category = static_method;
			}
		}
		if (currentField < fieldCount)
		{
			MemberNode* memberNode = fieldNodes[currentField];
			if (0 == current || memberNode->m_name->m_str < current->m_name->m_str)
			{
				current = memberNode;
				category = instance_field;
			}
		}
		if (currentProperty < propertyCount)
		{
			MemberNode* memberNode = propertyNodes[currentProperty];
			if (0 == current || memberNode->m_name->m_str < current->m_name->m_str)
			{
				current = memberNode;
				category = instance_property;
			}
		}
		if (currentMethod < methodCount)
		{
			MemberNode* memberNode = methodNodes[currentMethod];
			if (0 == current || memberNode->m_name->m_str < current->m_name->m_str)
			{
				current = memberNode;
				category = instance_method;
			}
		}
		if (unknown_member == category)
		{
			break;
		}
		switch (category)
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
			sprintf_s(buf, "&s_staticFields[%d],\n", staticFieldNodes[currentStaticField]->m_orderIndex);
			++currentStaticField;
			break;
		case static_property:
			sprintf_s(buf, "&s_staticProperties[%d],\n", staticPropertyNodes[currentStaticProperty]->m_orderIndex);
			++currentStaticProperty;
			break;
		case static_method:
			sprintf_s(buf, "&s_staticMethods[%d],\n", currentStaticMethod);
			++currentStaticMethod;
			break;
		case instance_field:
			sprintf_s(buf, "&s_instanceFields[%d],\n", fieldNodes[currentField]->m_orderIndex);
			++currentField;
			break;
		case instance_property:
			sprintf_s(buf, "&s_instanceProperties[%d],\n", propertyNodes[currentProperty]->m_orderIndex);
			++currentProperty;
			break;
		case instance_method:
			sprintf_s(buf, "&s_instanceMethods[%d],\n", currentMethod);
			++currentMethod;
			break;
		default:
			assert(false);
		}
		writeStringToFile(buf, file, indentation + 1);
	}

	writeStringToFile("};\n", file, indentation);
	writeStringToFile("m_members = s_members;\n", file, indentation);
	writeStringToFile("m_memberCount = paf_array_size_of(s_members);\n", file, indentation);

	bool findDynamicInstanceField = false;
	bool findDynamicInstanceFieldCount = false;
	bool findToString = false;
	bool findFromString = false;
	for (MethodNode* methodNode : methodNodes)
	{
		if (methodNode->m_name->m_str == "dynamicInstanceField__")
		{
			findDynamicInstanceField = true;
		}
		else if (methodNode->m_name->m_str == "dynamicInstanceFieldCount__")
		{
			findDynamicInstanceFieldCount = true;
		}
		else if (methodNode->m_name->m_str == "toString__")
		{
			findToString = true;
		}
		else if (methodNode->m_name->m_str == "fromString__")
		{
			findFromString = true;
		}
	}
	if (findDynamicInstanceField && findDynamicInstanceFieldCount)
	{
		writeStringToFile("m_hasDynamicInstanceField = true;\n", file, indentation);
	}
	if (findToString && findFromString)
	{
		writeStringToFile("m_specialClass = string_class;\n", file, indentation);
	}
}

void writeMetaConstructor_BaseClasses(ClassNode* classNode, TemplateArguments* templateArguments, FILE* file, int indentation)
{
	char buf[4096];
	std::string typeName;
	std::vector<std::pair<TokenNode*, TypeNameNode*>> tempNodes;
	classNode->m_baseList->collectTypeNameNodesNotNoMeta(tempNodes);
	std::vector<TypeNameNode*> typeNameNodes;
	size_t count = tempNodes.size();
	for (size_t i = 0; i < count; ++i)
	{
		TypeNameNode* typeNameNode = tempNodes[i].second;
		TypeNode* typeNode = typeNameNode->getActualTypeNode(templateArguments);
		if (!typeNode->getSyntaxNode()->isNoMeta())
		{
			typeNameNodes.push_back(typeNameNode);
		}
	}

	if (typeNameNodes.empty())
	{
		return;
	}
	std::string className;
	classNode->getNativeName(className, templateArguments);

	writeStringToFile("static BaseClass s_baseClasses[] =\n", file, indentation);
	writeStringToFile("{\n", file, indentation);
	
	count = typeNameNodes.size();
	for (size_t i = 0; i < count; ++i)
	{
		TypeNameNode* typeNameNode = typeNameNodes[i];

		TypeCategory typeCategory = CalcTypeNativeName(typeName, typeNameNode, templateArguments);
			sprintf_s(buf, "{RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), paf_base_offset_of(%s, %s)},\n",
				typeName.c_str(), className.c_str(), typeName.c_str());
			writeStringToFile(buf, file, indentation + 1);	
	}
	writeStringToFile("};\n", file, indentation);
	writeStringToFile("m_baseClasses = s_baseClasses;\n", file, indentation);
	writeStringToFile("m_baseClassCount = paf_array_size_of(s_baseClasses);\n", file, indentation);
}

void writeMetaConstructor_ClassTypeIterators(ClassNode* classNode, TemplateArguments* templateArguments, FILE* file, int indentation)
{
	char buf[4096];
	std::string typeName;
	std::vector<std::pair<TokenNode*, TypeNameNode*>> tempNodes;
	classNode->m_baseList->collectTypeNameNodesNotNoMeta(tempNodes);
	std::vector<TypeNameNode*> typeNameNodes;
	size_t count = tempNodes.size();
	for (size_t i = 0; i < count; ++i)
	{
		TypeNameNode* typeNameNode = tempNodes[i].second;
		TypeNode* typeNode = typeNameNode->getActualTypeNode(templateArguments);
		if (!typeNode->getSyntaxNode()->isNoMeta())
		{
			typeNameNodes.push_back(typeNameNode);
		}
	}

	if (typeNameNodes.empty())
	{
		return;
	}
	//std::string className;
	//classNode->getNativeName(className, templateArguments);

	writeStringToFile("static ::pafcore::ClassTypeIterator s_classTypeIterators[] =\n", file, indentation);
	writeStringToFile("{\n", file, indentation);
	count = typeNameNodes.size();
	for (size_t i = 0; i < count; ++i)
	{
		TypeNameNode* typeNameNode = typeNameNodes[i];
		TypeCategory typeCategory = CalcTypeNativeName(typeName, typeNameNode, templateArguments);
		sprintf_s(buf, "::pafcore::ClassTypeIterator(RuntimeTypeOf<%s>::RuntimeType::GetSingleton()->m_firstDerivedClass, this),\n",
			typeName.c_str());
		writeStringToFile(buf, file, indentation + 1);
	}
	writeStringToFile("};\n", file, indentation);
	for (size_t i = 0; i < count; ++i)
	{
		TypeNameNode* typeNameNode = typeNameNodes[i];
		TypeCategory typeCategory = CalcTypeNativeName(typeName, typeNameNode, templateArguments);
		sprintf_s(buf, "RuntimeTypeOf<%s>::RuntimeType::GetSingleton()->m_firstDerivedClass = &s_classTypeIterators[%d];\n",
			typeName.c_str(), i);
		writeStringToFile(buf, file, indentation);
	}
	writeStringToFile("m_classTypeIterators = s_classTypeIterators;\n", file, indentation);
}

void writeMetaConstructor_NestedTypes(ClassNode* classNode, TemplateArguments* templateArguments, std::vector<MemberNode*>& nestedTypeNodes, FILE* file, int indentation)
{
	char buf[4096];
	if (nestedTypeNodes.empty())
	{
		return;
	}
	size_t count = nestedTypeNodes.size();
	writeStringToFile("static ::pafcore::Type* s_nestedTypes[] = \n", file, indentation);
	writeStringToFile("{\n", file, indentation);

	for (size_t i = 0; i < count; ++i)
	{
		MemberNode* typeNode = nestedTypeNodes[i];
		std::string metaTypeName;
		GetMetaTypeFullName(metaTypeName, typeNode, templateArguments);

		sprintf_s(buf, "%s::GetSingleton(),\n", metaTypeName.c_str());
		writeStringToFile(buf, file, indentation + 1);
	}
	writeStringToFile("};\n", file, indentation);

	writeStringToFile("m_nestedTypes = s_nestedTypes;\n", file, indentation);
	writeStringToFile("m_nestedTypeCount = paf_array_size_of(s_nestedTypes);\n", file, indentation);
}

void writeMetaConstructor_NestedTypeAliases(ClassNode* classNode, TemplateArguments* templateArguments, std::vector<MemberNode*>& nestedTypeAliasNodes, FILE* file, int indentation)
{
	char buf[4096];
	if (nestedTypeAliasNodes.empty())
	{
		return;
	}
	size_t count = nestedTypeAliasNodes.size();
	writeStringToFile("static ::pafcore::TypeAlias* s_nestedTypeAliases[] = \n", file, indentation);
	writeStringToFile("{\n", file, indentation);

	for (size_t i = 0; i < count; ++i)
	{
		MemberNode* typeAliasNode = nestedTypeAliasNodes[i];
		std::string metaTypeName;
		GetMetaTypeFullName(metaTypeName, typeAliasNode, templateArguments);
		sprintf_s(buf, "%s::GetSingleton(),\n", metaTypeName.c_str());
		writeStringToFile(buf, file, indentation + 1);
	}
	writeStringToFile("};\n", file, indentation);

	writeStringToFile("m_nestedTypeAliases = s_nestedTypeAliases;\n", file, indentation);
	writeStringToFile("m_nestedTypeAliasCount = paf_array_size_of(s_nestedTypeAliases);\n", file, indentation);
}

void writeMetaConstructor_Scope(MemberNode* memberNode, TemplateArguments* templateArguments, FILE* file, int indentation)
{
	char buf[4096];
	assert(0 != memberNode->m_enclosing);
	if (snt_namespace == memberNode->m_enclosing->m_nodeType)
	{
		writeStringToFile("::pafcore::NameSpace::GetGlobalNameSpace()", file, indentation);

		std::vector<ScopeNode*> enclosings;
		memberNode->getEnclosings(enclosings);
		assert(!enclosings.empty());
		size_t count = enclosings.size();
		for (size_t i = 1; i < count; ++i)//enclosings[0] is global namespace 
		{
			ScopeNode* enclosing = enclosings[i];
			if (snt_namespace == enclosing->m_nodeType)
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
	else if (snt_class == memberNode->m_enclosing->m_nodeType)
	{
		std::string metaTypeName;
		GetMetaTypeFullName(metaTypeName, memberNode->m_enclosing, templateArguments);
		sprintf_s(buf, "m_enclosing = %s::GetSingleton();\n", metaTypeName.c_str());
		writeStringToFile(buf, file, indentation);
	}
	else
	{
		assert(false);
	}
}

void writeMetaConstructor(ClassNode* classNode,
	TemplateArguments* templateArguments,
	std::vector<MemberNode*>& nestedTypeNodes,
	std::vector<MemberNode*>& nestedTypeAliasNodes,
	std::vector<FieldNode*>& staticFieldNodes,
	std::vector<PropertyNode*>& staticPropertyNodes,
	std::vector<MethodNode*>& staticMethodNodes,
	std::vector<FieldNode*>& fieldNodes,
	std::vector<PropertyNode*>& propertyNodes,
	std::vector<MethodNode*>& methodNodes,
	FILE* file, int indentation)
{
	char buf[4096];
	std::string localClassName;
	std::string className;
	std::string metaClassName;
	classNode->getLocalName(localClassName, templateArguments);
	classNode->getNativeName(className, templateArguments);
	GetMetaTypeFullName(metaClassName, classNode, templateArguments);


	std::sort(nestedTypeNodes.begin(), nestedTypeNodes.end(), CompareMemberNodeByName());
	std::sort(nestedTypeAliasNodes.begin(), nestedTypeAliasNodes.end(), CompareMemberNodeByName());
	//std::sort(fieldNodes.begin(), fieldNodes.end(), CompareMemberNodeByName());
	//std::sort(propertyNodes.begin(), propertyNodes.end(), CompareMemberNodeByName());
	std::sort(methodNodes.begin(), methodNodes.end(), CompareMethodNode());
	//std::sort(staticFieldNodes.begin(), staticFieldNodes.end(), CompareMemberNodeByName());
	//std::sort(staticPropertyNodes.begin(), staticPropertyNodes.end(), CompareMemberNodeByName());
	std::sort(staticMethodNodes.begin(), staticMethodNodes.end(), CompareMethodNode());

	sprintf_s(buf, "%s::%s() : ::pafcore::ClassType(\"%s\", ::pafcore::%s, \"%s\")\n",
		metaClassName.c_str(), metaClassName.c_str(),
		localClassName.c_str(),
		classNode->m_category ? classNode->m_category->m_str.c_str() :
		classNode->isValueType() ? "value_object" : "reference_object",
		classNode->getSourceFilePath().c_str());

	writeStringToFile(buf, file, indentation);
	writeStringToFile("{\n", file, indentation);

	std::map<SyntaxNodeImpl*, size_t> attributesOffsets;
	writeMetaConstructor_Attributeses(attributesOffsets, classNode, staticFieldNodes, staticPropertyNodes, staticMethodNodes,
		fieldNodes, propertyNodes, methodNodes, file, indentation + 1);

	writeMetaConstructor_attributesForType(attributesOffsets, classNode, file, indentation + 1);

	sprintf_s(buf, "m_size = sizeof(%s);\n", className.c_str());
	writeStringToFile(buf, file, indentation + 1);

	writeMetaConstructor_BaseClasses(classNode, templateArguments, file, indentation + 1);
	writeMetaConstructor_ClassTypeIterators(classNode, templateArguments, file, indentation + 1);
	writeMetaConstructor_NestedTypes(classNode, templateArguments, nestedTypeNodes, file, indentation + 1);
	writeMetaConstructor_NestedTypeAliases(classNode, templateArguments, nestedTypeAliasNodes, file, indentation + 1);
	writeMetaConstructor_Fields(classNode, templateArguments, attributesOffsets, staticFieldNodes, true, file, indentation + 1);
	writeMetaConstructor_Properties(classNode, templateArguments, attributesOffsets, staticPropertyNodes, true, file, indentation + 1);
	writeMetaConstructor_Methods(classNode, templateArguments, attributesOffsets, staticMethodNodes, true, file, indentation + 1);

	writeMetaConstructor_Fields(classNode, templateArguments, attributesOffsets, fieldNodes, false, file, indentation + 1);
	writeMetaConstructor_Properties(classNode, templateArguments, attributesOffsets, propertyNodes, false, file, indentation + 1);
	writeMetaConstructor_Methods(classNode, templateArguments, attributesOffsets, methodNodes, false, file, indentation + 1);

	std::sort(fieldNodes.begin(), fieldNodes.end(), CompareMemberNodeByName());
	std::sort(propertyNodes.begin(), propertyNodes.end(), CompareMemberNodeByName());
	std::sort(staticFieldNodes.begin(), staticFieldNodes.end(), CompareMemberNodeByName());
	std::sort(staticPropertyNodes.begin(), staticPropertyNodes.end(), CompareMemberNodeByName());

	writeMetaConstructor_Member(nestedTypeNodes, nestedTypeAliasNodes, staticFieldNodes, staticPropertyNodes,
		staticMethodNodes, fieldNodes, propertyNodes, methodNodes, file, indentation + 1);

	writeMetaConstructor_Scope(classNode, templateArguments, file, indentation + 1);

	writeStringToFile("}\n\n", file, indentation);
}

void writeEnumMetaConstructor_Enumerators(EnumNode* enumNode, TemplateArguments* templateArguments, std::map<SyntaxNodeImpl*, size_t> attributesOffsets,
	std::vector<EnumeratorNode*>& enumerators, FILE* file, int indentation)
{
	char buf[4096];
	char strAttributes[256];
	if (enumerators.empty())
	{
		return;
	}
	std::string metaClassName;
	GetMetaTypeFullName(metaClassName, enumNode, templateArguments);
	size_t count = enumerators.size();

	writeStringToFile("static ::pafcore::Enumerator s_enumerators[] = \n", file, indentation);
	writeStringToFile("{\n", file, indentation);
	for (size_t i = 0; i < count; ++i)
	{
		EnumeratorNode* enumerator = enumerators[i];
		if (enumerator->m_attributeList)
		{
			auto it = attributesOffsets.find(enumerator);
			assert(it != attributesOffsets.end());
			sprintf_s(strAttributes, "&s_attributeses[%d]", it->second);
		}
		else
		{
			strcpy_s(strAttributes, "0");
		}

		std::string enumScopeName;
		enumNode->m_enclosing->getNativeName(enumScopeName, 0);
		if (enumNode->isStronglyTypedEnum())
		{
			sprintf_s(buf, "::pafcore::Enumerator(\"%s\", %s, %s::GetSingleton(), int(%s::%s::%s)),\n",
				enumerator->m_name->m_str.c_str(), strAttributes,
				metaClassName.c_str(), enumScopeName.c_str(), enumNode->m_name->m_str.c_str(), enumerator->m_name->m_str.c_str());
		}
		else
		{
			sprintf_s(buf, "::pafcore::Enumerator(\"%s\", %s, %s::GetSingleton(), %s::%s),\n",
				enumerator->m_name->m_str.c_str(), strAttributes,
				metaClassName.c_str(), enumScopeName.c_str(), enumerator->m_name->m_str.c_str());
		}
		writeStringToFile(buf, file, indentation + 1);
	}
	writeStringToFile("};\n", file, indentation);

	writeStringToFile("m_enumerators = s_enumerators;\n", file, indentation);
	writeStringToFile("m_enumeratorCount = paf_array_size_of(s_enumerators);\n", file, indentation);
}

void writeEnumMetaConstructor(EnumNode* enumNode, TemplateArguments* templateArguments, std::vector<EnumeratorNode*>& enumerators, FILE* file, int indentation)
{
	char buf[4096];
	std::string typeName;
	std::string metaTypeName;
	enumNode->getNativeName(typeName, 0);
	GetMetaTypeFullName(metaTypeName, enumNode, templateArguments);

	sprintf_s(buf, "%s::%s() : ::pafcore::EnumType(\"%s\", \"%s\")\n",
		metaTypeName.c_str(),
		metaTypeName.c_str(),
		enumNode->m_name->m_str.c_str(),
		enumNode->getSourceFilePath().c_str());

	writeStringToFile(buf, file, indentation);
	writeStringToFile("{\n", file, indentation);

	std::map<SyntaxNodeImpl*, size_t> attributesOffsets;
	writeEnumMetaConstructor_Attributeses(attributesOffsets, enumNode, enumerators, file, indentation + 1);
	writeMetaConstructor_attributesForType(attributesOffsets, enumNode, file, indentation + 1);

	sprintf_s(buf, "m_size = sizeof(%s);\n", typeName.c_str());
	writeStringToFile(buf, file, indentation + 1);

	writeEnumMetaConstructor_Enumerators(enumNode, templateArguments, attributesOffsets, enumerators, file, indentation + 1);
	writeMetaConstructor_Scope(enumNode, templateArguments, file, indentation + 1);
	writeStringToFile("}\n\n", file, indentation);
}

void writeMetaGetSingletonImpls(MemberNode* memberNode, TemplateArguments* templateArguments, FILE* file, int indentation)
{
	char buf[4096];
	std::string metaClassName;
	GetMetaTypeFullName(metaClassName, memberNode, templateArguments);

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

void MetaSourceFileGenerator::generateCode_Typedef(FILE* file, TypedefNode* typedefNode, TemplateArguments* templateArguments, int indentation)
{
	if (typedefNode->isNoMeta())
	{
		return;
	}

	char buf[4096];
	std::string typeName;
	std::string metaTypeName;
	typedefNode->getNativeName(typeName, templateArguments);
	GetMetaTypeFullName(metaTypeName, typedefNode, templateArguments);

	sprintf_s(buf, "%s::%s() : TypeAlias(\"%s\", RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), \"%s\")\n",
		metaTypeName.c_str(), metaTypeName.c_str(), typedefNode->m_name->m_str.c_str(), typeName.c_str(), typedefNode->getSourceFilePath().c_str());
	writeStringToFile(buf, file, indentation);
	writeStringToFile("{\n", file, indentation);

	std::map<SyntaxNodeImpl*, size_t> attributesOffsets;
	writeTypeDefMetaConstructor_Attributeses(attributesOffsets, typedefNode, file, indentation + 1);
	writeMetaConstructor_attributesForType(attributesOffsets, typedefNode, file, indentation + 1);

	writeMetaConstructor_Scope(typedefNode, templateArguments, file, indentation + 1);
	writeStringToFile("}\n\n", file, indentation);
	writeMetaGetSingletonImpls(typedefNode, templateArguments, file, indentation);
}

void MetaSourceFileGenerator::generateCode_TypeDeclaration(FILE* file, TypeDeclarationNode* typeDeclarationNode, TemplateArguments* templateArguments, int indentation)
{
	if (typeDeclarationNode->isNoMeta())
	{
		return;
	}

	char buf[4096];
	std::string typeName;
	std::string metaTypeName;
	typeDeclarationNode->getNativeName(typeName, templateArguments);
	GetMetaTypeFullName(metaTypeName, typeDeclarationNode, templateArguments);

	sprintf_s(buf, "%s::%s() : TypeAlias(\"%s\", RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), \"%s\")\n",
		metaTypeName.c_str(), metaTypeName.c_str(), typeDeclarationNode->m_name->m_str.c_str(), typeName.c_str(), typeDeclarationNode->getSourceFilePath().c_str());
	writeStringToFile(buf, file, indentation);
	writeStringToFile("{\n", file, indentation);
	std::map<SyntaxNodeImpl*, size_t> attributesOffsets;
	writeTypeDefMetaConstructor_Attributeses(attributesOffsets, typeDeclarationNode, file, indentation + 1);
	writeMetaConstructor_attributesForType(attributesOffsets, typeDeclarationNode, file, indentation + 1);
	writeMetaConstructor_Scope(typeDeclarationNode, templateArguments, file, indentation + 1);
	writeStringToFile("}\n\n", file, indentation);
	writeMetaGetSingletonImpls(typeDeclarationNode, templateArguments, file, indentation);
}

void writeOverrideMethodParameter(MethodNode* methodNode, ParameterNode* parameterNode, FILE* file);

void writeInterfaceMethodImpl_AssignThis(ClassNode* classNode, MethodNode* methodNode, FILE* file, int indentation)
{
	std::string className;
	classNode->getFullName(className, 0);
	char buf[4096];
	if (classNode->isValueType())
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


void writeInterfaceMethodImpl_SetOutputParamType(ParameterNode* parameterNode, size_t argIndex, FILE* file, int indentation)
{
	char buf[4096];
	std::string typeName;
	TypeCategory typeCategory = CalcTypeNativeName(typeName, parameterNode->m_typeName, 0);
	sprintf_s(buf, "__arguments__[%d].assignNullPtr(RuntimeTypeOf<%s>::RuntimeType::GetSingleton());\n",
		argIndex, typeName.c_str());
	writeStringToFile(buf, file, indentation);
}

void writeInterfaceMethodImpl_AssignInputParam(ParameterNode* parameterNode, size_t argIndex, FILE* file, int indentation)
{
	char buf[4096];
	std::string typeName;
	TypeCategory typeCategory = CalcTypeNativeName(typeName, parameterNode->m_typeName, 0);
	const char* varSemantic;
	if (parameterNode->isByRef())
	{
		varSemantic = s_variantSemantic_ByRef;
	}
	else if (parameterNode->isByPtr())
	{
		varSemantic = s_variantSemantic_ByPtr;
	}
	else
	{
		assert(parameterNode->isByValue());
		varSemantic = s_variantSemantic_ByValue;
	}
	bool isConstant = parameterNode->isConstant();

	const char* sign = parameterNode->isByPtr() ? "" : "&";
	if (parameterNode->isByValue())
	{
		switch (typeCategory)
		{
			//case void_type: impossible
		case primitive_type:
			sprintf_s(buf, "__arguments__[%d].assignPrimitive(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), &%s);\n",
				argIndex, typeName.c_str(), parameterNode->m_name->m_str.c_str());
			break;
		case enum_type:
			sprintf_s(buf, "__arguments__[%d].assignEnum(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), &%s);\n",
				argIndex, typeName.c_str(), parameterNode->m_name->m_str.c_str());
			break;
		case value_type:
			sprintf_s(buf, "__arguments__[%d].assignValuePtr(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), %s%s, %s, %s);\n",
				argIndex, typeName.c_str(), sign, parameterNode->m_name->m_str.c_str(),
				isConstant ? "true" : "false", s_variantSemantic_ByValue);
			break;
		case reference_type:
			sprintf_s(buf, "__arguments__[%d].assignReferencePtr(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), %s%s, %s, %s);\n",
				argIndex, typeName.c_str(), sign, parameterNode->m_name->m_str.c_str(),
				isConstant ? "true" : "false", s_variantSemantic_ByValue);
			break;
		default:
			assert(false);
		}
	}
	else
	{
		switch (typeCategory)
		{
		case void_type:
			sprintf_s(buf, "__arguments__[%d].assignVoidPtr(%s%s, %s);\n",
				argIndex, sign, parameterNode->m_name->m_str.c_str(),
				isConstant ? "true" : "false");
			break;
		case primitive_type:
			sprintf_s(buf, "__arguments__[%d].assignPrimitivePtr(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), %s%s, %s, %s);\n",
				argIndex, typeName.c_str(), sign, parameterNode->m_name->m_str.c_str(),
				isConstant ? "true" : "false", varSemantic);
			break;
		case enum_type:
			sprintf_s(buf, "__arguments__[%d].assignEnumPtr(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), %s%s, %s, %s);\n",
				argIndex, typeName.c_str(), sign, parameterNode->m_name->m_str.c_str(),
				isConstant ? "true" : "false", varSemantic);
			break;
		case value_type:
			sprintf_s(buf, "__arguments__[%d].assignValuePtr(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), %s%s, %s, %s);\n",
				argIndex, typeName.c_str(), sign, parameterNode->m_name->m_str.c_str(),
				isConstant ? "true" : "false", varSemantic);
			break;
		case reference_type:
			sprintf_s(buf, "__arguments__[%d].assignReferencePtr(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), %s%s, %s, %s);\n",
				argIndex, typeName.c_str(), sign, parameterNode->m_name->m_str.c_str(),
				isConstant ? "true" : "false", varSemantic);
			break;
		default:
			assert(false);
		}
	}
	writeStringToFile(buf, file, indentation);
}

void writeInterfaceMethodImpl_CastOutputParam(ParameterNode* parameterNode, size_t argIndex, FILE* file, int indentation)
{
	char buf[4096];
	std::string typeName;
	TypeCategory typeCategory = CalcTypeNativeName(typeName, parameterNode->m_typeName, 0);
	assert(parameterNode->isOutput() && parameterNode->isByPtr());

	const char* sign = parameterNode->isOutputPtr() ? "" : "&";
	switch (typeCategory)
	{
	case void_type:
		sprintf_s(buf, "__arguments__[%d].castToVoidPtr((void**)%s%s);\n",
			argIndex, sign, parameterNode->m_name->m_str.c_str());
		break;
	case primitive_type:
		sprintf_s(buf, "__arguments__[%d].castToPrimitivePtr(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), (void**)%s%s);\n",
			argIndex, typeName.c_str(), sign, parameterNode->m_name->m_str.c_str());
		break;
	case enum_type:
		sprintf_s(buf, "__arguments__[%d].castToEnumPtr(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), (void**)%s%s);\n",
			argIndex, typeName.c_str(), sign, parameterNode->m_name->m_str.c_str());
		break;
	case value_type:
		sprintf_s(buf, "__arguments__[%d].castToValuePtr(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), (void**)%s%s);\n",
			argIndex, typeName.c_str(), sign, parameterNode->m_name->m_str.c_str());
		break;
	case reference_type:
		sprintf_s(buf, "__arguments__[%d].castToReferencePtr(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), (void**)%s%s);\n",
			argIndex, typeName.c_str(), sign, parameterNode->m_name->m_str.c_str());
		break;
	default:
		assert(false);
	}
	writeStringToFile(buf, file, indentation);
	if (parameterNode->isByIncRefPtr())
	{
		sprintf_s(buf, "__arguments__[%d].unhold();\n", argIndex);
		writeStringToFile(buf, file, indentation);
	}
}

void writeInterfaceMethodImpl_SetResultType(ClassNode* classNode, MethodNode* methodNode, FILE* file, int indentation)
{
	char buf[4096];
	std::string typeName;
	TypeCategory typeCategory = CalcTypeNativeName(typeName, methodNode->m_resultTypeName, 0);

	if (methodNode->byValue() && (primitive_type == typeCategory || enum_type == typeCategory))
	{
		if (primitive_type == typeCategory)
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

void writeInterfaceMethodImpl_CastResult(MethodNode* methodNode, FILE* file, int indentation)
{
	char buf[4096];
	std::string typeName;
	TypeCategory typeCategory = CalcTypeNativeName(typeName, methodNode->m_resultTypeName, 0);

	const char* sign;
	if (methodNode->byValue() && (primitive_type == typeCategory || enum_type == typeCategory))
	{
		sign = "";
	}
	else
	{
		sign = "*";
	}
	sprintf_s(buf, "%s%s __res__;\n", typeName.c_str(), sign);
	writeStringToFile(buf, file, indentation);

	TypeNameNode* resultNode = static_cast<TypeNameNode*>(methodNode->m_resultTypeName);
	if (methodNode->byValue())
	{
		switch (typeCategory)
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
		if (primitive_type == typeCategory || enum_type == typeCategory)
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
		switch (typeCategory)
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
		if (methodNode->byNew())
		{
			writeStringToFile("__result__.unhold();\n", file, indentation);
		}
		if (methodNode->byRef())
		{
			writeStringToFile("return *__res__;\n", file, indentation);
		}
		else
		{
			writeStringToFile("return __res__;\n", file, indentation);
		}
	}
}

void writeInterfaceMethodImpl(ClassNode* classNode, TemplateArguments* templateArguments, MethodNode* methodNode, FILE* file, int indentation)
{
	char buf[4096];
	std::string subclassProxyName;
	GetSubclassProxyFullName(subclassProxyName, classNode, templateArguments);
	IdentifyNode* methodNameNode = methodNode->m_nativeName ? methodNode->m_nativeName : methodNode->m_name;

	std::string resultName;
	if (0 != methodNode->m_resultConst)
	{
		resultName = "const ";
	}
	assert(0 != methodNode->m_resultTypeName);
	TypeNode* resultTypeNode = methodNode->m_resultTypeName->getTypeNode(templateArguments);
	std::string typeName;
	resultTypeNode->getFullName(typeName);
	resultName += typeName;

	if (methodNode->byRef())
	{
		resultName += "&";
	}
	else if (methodNode->byPtr() || methodNode->byNew())
	{
		resultName += "*";
	}
	sprintf_s(buf, "%s %s::%s( ", resultName.c_str(), subclassProxyName.c_str(), methodNameNode->m_str.c_str());
	writeStringToFile(buf, file, indentation);

	std::vector<ParameterNode*> parameterNodes;
	methodNode->m_parameterList->collectParameterNodes(parameterNodes);
	size_t paramCount = parameterNodes.size();
	for (size_t i = 0; i < paramCount; ++i)
	{
		if (0 != i)
		{
			writeStringToFile(", ", file);
		}
		writeOverrideMethodParameter(methodNode, parameterNodes[i], file);
	}
	writeStringToFile(")", file);
	if (methodNode->m_constant)
	{
		writeStringToFile(" const", file, indentation);
	}
	writeStringToFile("\n", file);
	writeStringToFile("{\n", file, indentation);

	writeStringToFile("pafcore::Variant __result__, __self__;\n", file, indentation + 1);
	if (0 < paramCount)
	{
		sprintf_s(buf, "pafcore::Variant __arguments__[%d];\n", paramCount);
		writeStringToFile(buf, file, indentation + 1);
	}

	bool isVoid = (void_type == resultTypeNode->getTypeCategory(templateArguments) && 0 == methodNode->m_passing);
	if (!isVoid)
	{
		writeInterfaceMethodImpl_SetResultType(classNode, methodNode, file, indentation + 1);
	}
	writeInterfaceMethodImpl_AssignThis(classNode, methodNode, file, indentation + 1);
	for (size_t i = 0; i < paramCount; ++i)
	{
		ParameterNode* parameterNode = parameterNodes[i];
		if (parameterNode->isInput())
		{
			writeInterfaceMethodImpl_AssignInputParam(parameterNode, i, file, indentation + 1);
		}
		else
		{
			writeInterfaceMethodImpl_SetOutputParamType(parameterNode, i, file, indentation + 1);
		}
	}
	writeStringToFile("if(m_subclassInvoker)\n", file, indentation + 1);
	writeStringToFile("{\n", file, indentation + 1);
	sprintf_s(buf, "::pafcore::ErrorCode __error__ = m_subclassInvoker->invoke(\"%s\", &__result__, &__self__, %s, %d);\n",
		methodNode->m_name->m_str.c_str(), paramCount > 0 ? "__arguments__" : "0", paramCount);
	writeStringToFile(buf, file, indentation + 2);
	writeStringToFile("}\n", file, indentation + 1);

	//if(!methodNode->isAbstract() || methodNode->m_enclosing != classNode)
	//{
	//	writeInterfaceMethodImpl_CallBaseClass(classNode, templateArguments, methodNode, parameterNodes, file, indentation + 1);
	//}
	for (size_t i = 0; i < paramCount; ++i)
	{
		ParameterNode* parameterNode = parameterNodes[i];
		if (parameterNode->isOutput())
		{
			writeInterfaceMethodImpl_CastOutputParam(parameterNode, i, file, indentation + 1);
		}
	}
	if (!isVoid)
	{
		writeInterfaceMethodImpl_CastResult(methodNode, file, indentation + 1);
	}
	writeStringToFile("}\n\n", file, indentation);
}

void writeInterfaceMethodsImpl(ClassNode* classNode, TemplateArguments* templateArguments, FILE* file, int indentation)
{
	std::vector<MethodNode*> methodNodes;
	classNode->collectOverrideMethods(methodNodes, templateArguments);
	size_t count = methodNodes.size();
	for (size_t i = 0; i < count; ++i)
	{
		MethodNode* methodNode = methodNodes[i];
		assert(snt_method == methodNode->m_nodeType && methodNode->m_override && methodNode->isVirtual());
		writeInterfaceMethodImpl(classNode, templateArguments, methodNode, file, indentation);
	}
}

void MetaSourceFileGenerator::generateCode_SubclassProxy(FILE* file, ClassNode* classNode, TemplateArguments* templateArguments, int indentation)
{
	char buf[4096];
	std::string subclassProxyName;
	GetSubclassProxyFullName(subclassProxyName, classNode, templateArguments);

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

	writeInterfaceMethodsImpl(classNode, templateArguments, file, indentation);
}

