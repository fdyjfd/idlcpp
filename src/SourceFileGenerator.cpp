#include "SourceFileGenerator.h"
#include "Utility.h"
#include "SourceFile.h"
#include "ProgramNode.h"
#include "NamespaceNode.h"
#include "TokenNode.h"
#include "IdentifyNode.h"
#include "EnumeratorListNode.h"
#include "ScopeNameListNode.h"
#include "MemberListNode.h"
#include "EnumNode.h"
#include "ClassNode.h"
#include "DelegateNode.h"
#include "TemplateParametersNode.h"
#include "TemplateParameterListNode.h"
#include "TypeNameListNode.h"
#include "TypeNameNode.h"
#include "FieldNode.h"
#include "PropertyNode.h"
#include "MethodNode.h"
#include "ParameterNode.h"
#include "ParameterListNode.h"
#include "TypedefNode.h"
#include "Options.h"
#include "Platform.h"
#include "CommonFuncs.h"
#include "TypeTree.h"
#include <assert.h>

void generateCode_Token(FILE* file, TokenNode* tokenNode, int indentation);
void generateCode_Identify(FILE* file, IdentifyNode* identifyNode, int indentation, bool addSpace = true);
void generateCode_Parameter(FILE* file, ParameterNode* parameterNode, ScopeNode* scopeNode);
void generateCode_TypeName(FILE* file, TypeNameNode* typeNameNode, ScopeNode* scopeNode, bool addKeyword, int indentation);
void generateCode_ParameterList(FILE* file, ParameterListNode* parameterListNode, ScopeNode* scopeNode);
void writeInterfaceMethodImpl_AssignInputParam(ParameterNode* parameterNode, size_t argIndex, FILE* file, int indentation);
void writeInterfaceMethodImpl_SetOutputParamType(ParameterNode* parameterNode, size_t argIndex, FILE* file, int indentation);
void writeInterfaceMethodImpl_CastOutputParam(ParameterNode* parameterNode, size_t argIndex, FILE* file, int indentation);

//void writeDelegateImpl_InitRes(DelegateNode* delegateNode, FILE* file, int indentation)
//{
//	if (0 != delegateNode->m_resultConst)
//	{
//		generateCode_Token(file, delegateNode->m_resultConst, indentation);
//		generateCode_TypeName(file, delegateNode->m_resultTypeName, delegateNode->m_enclosing, true, 0);
//	}
//	else
//	{
//		generateCode_TypeName(file, delegateNode->m_resultTypeName, delegateNode->m_enclosing, true, indentation);
//	}
//	if (0 != delegateNode->m_passing)
//	{
//		generateCode_Token(file, delegateNode->m_passing, 0);
//	}
//	writeStringToFile(" __res__;\n", file, 0);
//}

void writeDelegateImpl_InitResult(DelegateNode* delegateNode, FILE* file, int indentation)
{
	char buf[4096];
	std::string typeName;
	TypeCategory typeCategory = CalcTypeNativeName(typeName, delegateNode->m_resultTypeName, 0);
	const char* sign;
	if (delegateNode->byValue())
	{
		sign = "";
	}
	else
	{
		sign = "*";
	}
	sprintf_s(buf, "%s%s __res__;\n", typeName.c_str(), sign);
	writeStringToFile(buf, file, indentation);
}

void writeDelegateImpl_ReturnResult(DelegateNode* delegateNode, FILE* file, int indentation)
{
	if (delegateNode->byRef())
	{
		writeStringToFile("return *__res__;\n", file, indentation);
	}
	else
	{
		writeStringToFile("return __res__;\n", file, indentation);
	}
}

void writeDelegateImpl_CastResult(DelegateNode* delegateNode, FILE* file, int indentation)
{
	char buf[4096];
	std::string typeName;
	TypeCategory typeCategory = CalcTypeNativeName(typeName, delegateNode->m_resultTypeName, 0);

	TypeNameNode* resultNode = static_cast<TypeNameNode*>(delegateNode->m_resultTypeName);
	if (delegateNode->byValue())
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
			sprintf_s(buf, "__result__.castToValue(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), &__res__);\n", typeName.c_str());
			break;
		case reference_type:
			sprintf_s(buf, "__result__.castToReference(RuntimeTypeOf<%s>::RuntimeType::GetSingleton(), &__res__);\n", typeName.c_str());
			break;
		default:
			assert(false);
		}
		writeStringToFile(buf, file, indentation);
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
		if (delegateNode->byNew())
		{
			writeStringToFile("__result__.unhold();\n", file, indentation);
		}
	}
}

void writeDelegateImpl_SetResultType(DelegateNode* delegateNode, FILE* file, int indentation)
{
	char buf[4096];
	std::string typeName;
	TypeCategory typeCategory = CalcTypeNativeName(typeName, delegateNode->m_resultTypeName, 0);

	if (delegateNode->byValue() && (primitive_type == typeCategory || enum_type == typeCategory))
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

void SourceFileGenerator::generateCode(FILE* dstFile, SourceFile* sourceFile, const char* fullPathName, const char* baseName)
{
	generateCode_Program(dstFile, sourceFile->m_syntaxTree, fullPathName, baseName);
}

void SourceFileGenerator::generateCode_Program(FILE* file, ProgramNode* programNode, const char* fileName, const char* cppName)
{
	char buf[4096];
	std::string pafcorePath;
	GetRelativePath(pafcorePath, fileName, g_options.m_pafcorePath.c_str());
	FormatPathForInclude(pafcorePath);

	writeStringToFile("#pragma once\n\n", file);

	sprintf_s(buf, "#include \"%s.h\"\n", cppName);
	writeStringToFile(buf, file);

	sprintf_s(buf, "#include \"%s%s\"\n", cppName, g_options.m_metaHeaderFilePostfix.c_str());
	writeStringToFile(buf, file);

	sprintf_s(buf, "#include \"%sRefCountImpl.h\"\n\n", pafcorePath.c_str());
	writeStringToFile(buf, file);

	generateCode_Namespace(file, programNode, -1);
}

void SourceFileGenerator::generateCode_Namespace(FILE* file, NamespaceNode* namespaceNode, int indentation)
{
	//if (namespaceNode->isNoCode())
	//{
	//	file = 0;
	//}

	char buf[4096];
	if(!namespaceNode->isGlobalNamespace())
	{
		sprintf_s(buf, "namespace %s\n", namespaceNode->m_name->m_str.c_str());
		writeStringToFile(buf, file, indentation);
		writeStringToFile("{\n\n", file, indentation);
	}
	std::vector<MemberNode*> memberNodes;
	namespaceNode->m_memberList->collectMemberNodes(memberNodes);
	size_t count = memberNodes.size();
	for(size_t i = 0; i < count; ++i)
	{
		MemberNode* memberNode = memberNodes[i];
		switch (memberNode->m_nodeType)
		{
		case snt_namespace:
			generateCode_Namespace(file, static_cast<NamespaceNode*>(memberNode), indentation + 1);
			break;
		case snt_class:
			generateCode_Class(file, static_cast<ClassNode*>(memberNode), "", indentation + 1);
			break;
		case snt_delegate:
			generateCode_Delegate(file, static_cast<DelegateNode*>(memberNode), namespaceNode, "", indentation + 1);
			break;
		}
	}

	if(!namespaceNode->isGlobalNamespace())
	{
		writeStringToFile("}\n\n", file, indentation);
	}
}

void GetClassName(std::string& className, ClassNode* classNode)
{
	className = classNode->m_name->m_str;
	if(classNode->m_templateParametersNode)
	{
		std::vector<IdentifyNode*> templateParameterNodes;
		classNode->m_templateParametersNode->collectParameterNodes(templateParameterNodes);
		className += "<";
		size_t count = templateParameterNodes.size();
		for(size_t i = 0; i < count; ++i)
		{
			if(0 != i)
			{
				className += ", ";
			}
			className += templateParameterNodes[i]->m_str;
		}
		className += ">";
	}
}

void SourceFileGenerator::generateCode_Class(FILE* file, ClassNode* classNode, const std::string& scopeClassName, int indentation)
{
	//if (classNode->isNoCode())
	//{
	//	file = 0;
	//}
	std::string typeName;
	GetClassName(typeName, classNode);
	typeName = scopeClassName + typeName;

	bool isInline = 0 != classNode->m_templateParametersNode;

	if (!(classNode->isNoCode() || classNode->isNoMeta()))
	{
		generateCode_TemplateHeader(file, classNode, indentation);
		if (isInline)
		{
			writeStringToFile("inline ::pafcore::ClassType* ", file, indentation);
		}
		else
		{
			writeStringToFile("::pafcore::ClassType* ", file, indentation);
		}
		writeStringToFile(typeName.c_str(), file);
		writeStringToFile("::GetType()\n", file);
		writeStringToFile("{\n", file, indentation);
		writeStringToFile("return ::RuntimeTypeOf<", file, indentation + 1);
		writeStringToFile(typeName.c_str(), file);
		writeStringToFile(">::RuntimeType::GetSingleton();\n", file);
		writeStringToFile("}\n\n", file, indentation);

		if (!classNode->isValueType())
		{
			generateCode_TemplateHeader(file, classNode, indentation);
			if (isInline)
			{
				writeStringToFile("inline ::pafcore::ClassType* ", file, indentation);
			}
			else
			{
				writeStringToFile("::pafcore::ClassType* ", file, indentation);
			}
			writeStringToFile(typeName.c_str(), file);
			writeStringToFile("::getType()\n", file);
			writeStringToFile("{\n", file, indentation);
			writeStringToFile("return ::RuntimeTypeOf<", file, indentation + 1);
			writeStringToFile(typeName.c_str(), file);
			writeStringToFile(">::RuntimeType::GetSingleton();\n", file);
			writeStringToFile("}\n\n", file, indentation);

			generateCode_TemplateHeader(file, classNode, indentation);
			if (isInline)
			{
				writeStringToFile("inline size_t ", file, indentation);
			}
			else
			{
				writeStringToFile("size_t ", file, indentation);
			}
			writeStringToFile(typeName.c_str(), file);
			writeStringToFile("::getAddress()\n", file);
			writeStringToFile("{\n", file, indentation);
			writeStringToFile("return (size_t)this;\n", file, indentation + 1);
			writeStringToFile("}\n\n", file, indentation);
		}
	}

	if (!classNode->isNoCode())
	{
		if (!classNode->m_additionalMethods.empty())
		{
			size_t count = classNode->m_additionalMethods.size();
			for (size_t i = 0; i < count; ++i)
			{
				generateCode_AdditionalMethod(file, classNode->m_additionalMethods[i], typeName, indentation);
			}
		}
	}


	typeName += "::";
	std::vector<MemberNode*> memberNodes;
	classNode->m_memberList->collectMemberNodes(memberNodes);
	size_t count = memberNodes.size();
	for (size_t i = 0; i < count; ++i)
	{
		MemberNode* memberNode = memberNodes[i];
		switch (memberNode->m_nodeType)
		{
		case snt_class:
			generateCode_Class(file, static_cast<ClassNode*>(memberNode), typeName, indentation);
			break;
		case snt_delegate:
			generateCode_Delegate(file, static_cast<DelegateNode*>(memberNode), classNode, typeName, indentation);
			break;
		}
	}
}

void SourceFileGenerator::generateCode_Delegate(FILE* file, DelegateNode* delegateNode, ScopeNode* scopeNode, const std::string& scopeClassName, int indentation)
{
	char buf[4096];
	if (delegateNode->isNoCode())
	{
		file = 0;
	}
	TypeNode* resultTypeNode = delegateNode->m_resultTypeName->getTypeNode(0);
	bool isVoid = (void_type == resultTypeNode->getTypeCategory(0) && 0 == delegateNode->m_passing);

	std::string typeName = scopeClassName + delegateNode->m_name->m_str;

	if (0 != delegateNode->m_resultConst)
	{
		generateCode_Token(file, delegateNode->m_resultConst, indentation);
		generateCode_TypeName(file, delegateNode->m_resultTypeName, delegateNode->m_enclosing, true, 0);
	}
	else
	{
		generateCode_TypeName(file, delegateNode->m_resultTypeName, delegateNode->m_enclosing, true, indentation);
	}
	if (0 != delegateNode->m_passing)
	{
		generateCode_Token(file, delegateNode->m_passing, 0);
	}
	writeSpaceToFile(file);
	writeStringToFile(typeName.c_str(), file);
	writeStringToFile("::invoke", file);
	generateCode_Token(file, delegateNode->m_leftParenthesis, 0);
	generateCode_ParameterList(file, delegateNode->m_parameterList, delegateNode->m_enclosing);
	generateCode_Token(file, delegateNode->m_rightParenthesis, 0);
	writeStringToFile("\n", file);
	writeStringToFile("{\n", file, indentation);

	std::vector<ParameterNode*> parameterNodes;
	delegateNode->m_parameterList->collectParameterNodes(parameterNodes);
	size_t paramCount = parameterNodes.size();

	writeStringToFile("bool __arguments_init__ = false;\n", file, indentation + 1);
	if (!isVoid)
	{
		writeStringToFile("bool __res_init__ = false;\n", file, indentation + 1);
		writeDelegateImpl_InitResult(delegateNode, file, indentation + 1);
	}
	
	writeStringToFile("pafcore::Variant __result__;\n", file, indentation + 1);
	if (0 < paramCount)
	{
		sprintf_s(buf, "::pafcore::Variant __arguments__[%d];\n", paramCount);
		writeStringToFile(buf, file, indentation + 1);
	}
	sprintf_s(buf, "::pafcore::Variant* __args__[%d] = {0", paramCount + 1);
	writeStringToFile(buf, file, indentation + 1);
	for (size_t i = 0; i < paramCount; ++i)
	{
		sprintf_s(buf, ", &__arguments__[%d]", i);
		writeStringToFile(buf, file, 0);
	}
	writeStringToFile("};\n", file, 0);

	writeStringToFile("::pafcore::CallBack* __callBack__ = getCallBack();\n", file, indentation + 1);
	writeStringToFile("while (__callBack__)\n", file, indentation + 1);
	writeStringToFile("{\n", file, indentation + 1);
	writeStringToFile("::pafcore::CallBack* __next__ = __callBack__->getNext();\n", file, indentation + 2);
	writeStringToFile("::pafcore::ClassType* __classType__ = __callBack__->getType();\n", file, indentation + 2);
	writeStringToFile("if (__classType__ == ::pafcore::FunctionCallBack::GetType())\n", file, indentation + 2);
	writeStringToFile("{\n", file, indentation + 2);
	writeStringToFile("::pafcore::FunctionCallBack* __functionCallBack__ = static_cast<::pafcore::FunctionCallBack*>(__callBack__);\n", file, indentation + 3);
	writeStringToFile(isVoid ? "" : "__res__ = ", file, indentation + 3);
	writeStringToFile("(*(CallBackFunction)__functionCallBack__->m_function)(__functionCallBack__->m_userData", file, 0);
	for (size_t i = 0; i < paramCount; ++i)
	{
		sprintf_s(buf, ", %s", parameterNodes[i]->m_name->m_str.c_str());
		writeStringToFile(buf, file, 0);
	}
	writeStringToFile(");\n", file, 0);
	writeStringToFile("}\n", file, indentation + 2);

	writeStringToFile("else\n", file, indentation + 2);
	writeStringToFile("{\n", file, indentation + 2);

	writeStringToFile("if(!__arguments_init__)\n", file, indentation + 3);
	writeStringToFile("{\n", file, indentation + 3);
	writeStringToFile("__arguments_init__ = true;\n", file, indentation + 4);
	//if (!isVoid)
	//{
	//	writeDelegateImpl_SetResultType(delegateNode, file, indentation + 4);
	//}
	for (size_t i = 0; i < paramCount; ++i)
	{
		ParameterNode* parameterNode = parameterNodes[i];
		if (parameterNode->isInput())
		{
			writeInterfaceMethodImpl_AssignInputParam(parameterNode, i, file, indentation + 4);
		}
		else
		{
			writeInterfaceMethodImpl_SetOutputParamType(parameterNode, i, file, indentation + 4);
		}
	}
	writeStringToFile("}\n", file, indentation + 3);

	sprintf_s(buf, "__callBack__->invoke(&__result__, __args__, %d);\n", paramCount + 1);
	writeStringToFile(buf, file, indentation + 3);

	if (!isVoid)
	{
		writeStringToFile("if(!__res_init__)\n", file, indentation + 3);
		writeStringToFile("{\n", file, indentation + 3);
		writeStringToFile("__res_init__ = false;\n", file, indentation + 4);
		for (size_t i = 0; i < paramCount; ++i)
		{
			ParameterNode* parameterNode = parameterNodes[i];
			if (parameterNode->isOutput())
			{
				writeInterfaceMethodImpl_CastOutputParam(parameterNode, i, file, indentation + 4);
			}
		}
		writeDelegateImpl_CastResult(delegateNode, file, indentation + 4);
		writeStringToFile("}\n", file, indentation + 3);
	}
	writeStringToFile("}\n", file, indentation + 2);
	writeStringToFile("__callBack__ = __next__;\n", file, indentation + 2);
	writeStringToFile("}\n", file, indentation + 1);//while
	if (!isVoid)
	{
		writeStringToFile("return __res__;\n", file, indentation + 1);
	}
	writeStringToFile("}\n", file, indentation);

	//void EventHandler::invoke(Reference* sender)
	//{
	//	Variant __result__;
	//	Variant __arguments__[1];
	//	__arguments__[0].assignReferencePtr(sender, false, Variant::by_ptr);
	//	Variant* __args__[2] = { 0, &__arguments__[0] };
	//	bool __arguments_uninit__ = true;
	//	CallBack* __callBack__ = getCallBack();
	//	while (__callBack__)
	//	{
	//		int __category__ = __callBack__->getCategory();
	//		if (__arguments_uninit__ && __category__ != CallBack::native_function)
	//		{
	//			__arguments_uninit__ = false;
	//		}
	//		CallBack* __next__ = __callBack__->getNext();
	//		switch (__category__)
	//		{
	//		case CallBack::instance_method:
	//			__callBack__->invokeInstanceMethod(&__result__, __args__, 2);
	//			break;
	//		case CallBack::static_method:
	//			__callBack__->invokeInstanceMethod(&__result__, __args__, 2);
	//			break;
	//		case CallBack::native_function:
	//			__res__ = (*(CallBackFunction)__callBack__->m_function)(__callBack__->m_userData, sender);
	//			break;
	//		}
	//		if (0 == __next__ && __category__ != CallBack::native_function)
	//		{
	//			__result__.castTo...
	//		}
	//		__callBack__ = __next__;
	//	}
	//	return __res__;
	//}

}

void SourceFileGenerator::generateCode_TemplateHeader(FILE* file, ClassNode* classNode, int indentation)
{
	if(classNode->m_templateParametersNode)
	{
		std::vector<IdentifyNode*> templateParameterNodes;
		classNode->m_templateParametersNode->collectParameterNodes(templateParameterNodes);
		writeStringToFile("template<", file, indentation);
		size_t count = templateParameterNodes.size();
		for(size_t i = 0; i < count; ++i)
		{
			if(0 != i)
			{
				writeStringToFile(",", file);
			}
			writeStringToFile("typename ", file);
			writeStringToFile(templateParameterNodes[i]->m_str.c_str(), file);
		}
		writeStringToFile(">\n", file);
	}
}


void SourceFileGenerator::generateCode_AdditionalMethod(FILE* file, MethodNode* methodNode, const std::string& typeName, int indentation)
{
	char buf[4096];

	if (methodNode->isNoCode())
	{
		file = 0;
	}

	ClassNode* classNode = static_cast<ClassNode*>(methodNode->m_enclosing);
	//std::string typeName;
	//GetClassName(typeName, classNode);
	bool isInline = 0 != classNode->m_templateParametersNode;

	generateCode_TemplateHeader(file, classNode, indentation);

	if (isInline)
	{
		writeStringToFile("inline ", file, indentation);
		writeStringToFile(typeName.c_str(), file);
	}
	else
	{
		writeStringToFile(typeName.c_str(), file, indentation);
	}

	if (0 != methodNode->m_passing)
	{
		generateCode_Token(file, methodNode->m_passing, 0);
	}
	writeSpaceToFile(file);
	writeStringToFile(typeName.c_str(), file);
	writeStringToFile("::", file);

	generateCode_Identify(file, methodNode->m_name, 0);

	generateCode_Token(file, methodNode->m_leftParenthesis, 0);
	std::vector<ParameterNode*> parameterNodes;

	methodNode->m_parameterList->collectParameterNodes(parameterNodes);
	size_t parameterCount = parameterNodes.size();
	for (size_t i = 0; i < parameterCount; ++i)
	{
		if (0 != i)
		{
			writeStringToFile(", ", file);
		}
		generateCode_Parameter(file, parameterNodes[i], classNode->m_enclosing);
	}
	generateCode_Token(file, methodNode->m_rightParenthesis, 0);
	writeStringToFile("\n", file);
	writeStringToFile("{\n", file, indentation);

	if ("New" == methodNode->m_name->m_str)
	{
		if (classNode->isValueType())
		{
			sprintf_s(buf, "return paf_new %s(", typeName.c_str());
		}
		else
		{
			if (classNode->m_category && classNode->m_category->m_str == "atomic_reference_object")
			{
				sprintf_s(buf, "return paf_new ::pafcore::AtomicRefCountImpl<%s>(", typeName.c_str());
			}
			else
			{
				sprintf_s(buf, "return paf_new ::pafcore::RefCountImpl<%s>(", typeName.c_str());
			}
		}
	}
	//else if ("NewARC" == methodNode->m_name->m_str)
	//{
	//	sprintf_s(buf, "return paf_new ::pafcore::AtomicRefCountImpl<%s>(", typeName.c_str());
	//}
	else
	{
		assert("NewArray" == methodNode->m_name->m_str);
		assert(classNode->isValueType());
		sprintf_s(buf, "return paf_new_array<%s>(", typeName.c_str());
	}

	writeStringToFile(buf, file, indentation + 1);
	for (size_t i = 0; i < parameterCount; ++i)
	{
		if (i != 0)
		{
			writeStringToFile(", ", file);
		}
		writeStringToFile(parameterNodes[i]->m_name->m_str.c_str(), file);
	}
	writeStringToFile(");\n", file);
	
	writeStringToFile("}\n\n", file, indentation);
}