#include "yyfuncs.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>
#include <set>
#include <string>
#include <algorithm>
#include "ErrorList.h"
#include "SourceFile.h"
#include "TokenNode.h"
#include "IdentifyNode.h"
#include "ScopeListNode.h"
#include "EnumeratorListNode.h"
#include "TypeNameNode.h"
#include "TypeNameListNode.h"
#include "FieldNode.h"
#include "GetterSetterNode.h"
#include "PropertyNode.h"
#include "ParameterNode.h"
#include "ParameterListNode.h"
#include "MethodNode.h"
#include "FilterNode.h"
#include "MemberListNode.h"
#include "ClassNode.h"
#include "EnumNode.h"
#include "TypeAliasNode.h"
#include "TemplateParameterNode.h"
#include "TemplateParameterListNode.h"
#include "TemplateParametersNode.h"
#include "TemplateClassInstanceNode.h"
#include "NamespaceNode.h"
#include "ProgramNode.h"

extern "C"
{
extern int yylineno;
extern int yycolumnno;
extern int yytokenno;
typedef struct yy_buffer_state *YY_BUFFER_STATE;
YY_BUFFER_STATE yy_create_buffer ( FILE *file, int size );
void yy_switch_to_buffer( YY_BUFFER_STATE new_buffer );
void yy_delete_buffer( YY_BUFFER_STATE b );
#define YY_BUF_SIZE 16384
}

std::vector<SyntaxNodeImpl*> g_syntaxNodes;

SyntaxNode* newToken(int nodeType)
{
	TokenNode* res = new TokenNode(nodeType, yytokenno, yylineno, yycolumnno);
	g_syntaxNodes.push_back(res);
	return res;
}

SyntaxNode* newIdentify(const char* str)
{
	IdentifyNode* res = new IdentifyNode(str, yytokenno, yylineno, yycolumnno);
	g_syntaxNodes.push_back(res);
	return res;
}

void newCodeBlock(const char* str)
{
	g_sourceFileManager.m_currentSourceFile->addEmbededCodeBlock(str, yytokenno);
}

SyntaxNode* newPrimitiveType(SyntaxNode* keyword, PrimitiveType type)
{
	assert((snt_keyword_begin_primitive < keyword->m_nodeType && keyword->m_nodeType < snt_keyword_end_primitive)
		|| snt_keyword_void == keyword->m_nodeType);
	assert(pt_unknown != type);
	TypeNameNode* res = new TypeNameNode((TokenNode*)keyword, type);
	g_syntaxNodes.push_back(res);
	return res;
}

SyntaxNode* newScopeList(SyntaxNode* scopeList, SyntaxNode* identify)
{
	assert(0 == scopeList || snt_scope_list == scopeList->m_nodeType);
	assert(snt_identify == identify->m_nodeType);
	ScopeListNode* res = new ScopeListNode((ScopeListNode*)scopeList, (IdentifyNode*)identify);
	g_syntaxNodes.push_back(res);
	return res;
}

void setScopeListGlobal(SyntaxNode* scopeList)
{
	assert(snt_scope_list == scopeList->m_nodeType);
	static_cast<ScopeListNode*>(scopeList)->m_global = true;
}

SyntaxNode* newTypeName(SyntaxNode* scopeList)
{
	assert(0 != scopeList && snt_scope_list == scopeList->m_nodeType);
	TypeNameNode* res = new TypeNameNode((ScopeListNode*)scopeList);
	g_syntaxNodes.push_back(res);
	return res;
}

SyntaxNode* newTemplateTypeName(SyntaxNode* scopeList, SyntaxNode* lab, SyntaxNode* parameterList, SyntaxNode* rab)
{
	assert(0 != scopeList && snt_scope_list == scopeList->m_nodeType);
	assert(0 != lab && '<' == lab->m_nodeType);	
	assert(0 != parameterList && snt_type_name_list == parameterList->m_nodeType);
	assert(0 != rab && '>' == rab->m_nodeType);	
	TypeNameNode* res = new TypeNameNode((ScopeListNode*)scopeList, (TokenNode*)lab, 
		(TypeNameListNode*)parameterList, (TokenNode*)rab);
	g_syntaxNodes.push_back(res);
	return res;
}

SyntaxNode* newTypeNameList(SyntaxNode* typeNameList, SyntaxNode* delimiter, SyntaxNode* typeName)
{
	assert(0 == typeNameList || snt_type_name_list == typeNameList->m_nodeType);
	assert(0 == delimiter || ',' == delimiter->m_nodeType);
	assert((0 == delimiter && 0 == typeNameList) || (0 != delimiter && 0 != typeNameList));	
	assert(snt_type_name == typeName->m_nodeType);
	TypeNameListNode* res = new TypeNameListNode((TypeNameListNode*)typeNameList, (TokenNode*)delimiter, (TypeNameNode*)typeName);
	g_syntaxNodes.push_back(res);
	return res;
}

SyntaxNode* newField(SyntaxNode* type, SyntaxNode* name, SyntaxNode* leftBracket, SyntaxNode* rightBracket, SyntaxNode* semicolon)
{
	assert(snt_type_name == type->m_nodeType && snt_identify == name->m_nodeType && ';' == semicolon->m_nodeType);
	assert((0 == leftBracket || '[' == leftBracket->m_nodeType) && (0 == rightBracket || ']' == rightBracket->m_nodeType));

	FieldNode* res = new FieldNode((TypeNameNode*) type, (IdentifyNode*) name, (TokenNode*)leftBracket, (TokenNode*)rightBracket, (TokenNode*)semicolon);
	g_syntaxNodes.push_back(res);
	return res;
}

void setFieldStatic(SyntaxNode* syntaxNode, SyntaxNode* stat)
{
	assert(snt_field == syntaxNode->m_nodeType);
	assert(snt_keyword_static == stat->m_nodeType);
	FieldNode* fieldNode = (FieldNode*)syntaxNode;
	fieldNode->m_static = (TokenNode*)stat;
}

void setFieldConstant(SyntaxNode* syntaxNode, SyntaxNode* constant)
{
	assert(snt_field == syntaxNode->m_nodeType);
	assert(snt_keyword_const == constant->m_nodeType);
	FieldNode* fieldNode = (FieldNode*)syntaxNode;
	fieldNode->m_constant = (TokenNode*)constant;
}

SyntaxNode* newGetterSetter(SyntaxNode* keyword, SyntaxNode* constant, SyntaxNode* type, SyntaxNode* passing)
{
	assert(snt_keyword_get == keyword->m_nodeType || snt_keyword_set == keyword->m_nodeType);
	assert(0 == constant || snt_keyword_const == constant->m_nodeType);
	assert(0 == type || snt_type_name == type->m_nodeType);
	assert(0 == passing || snt_keyword_ptr == passing->m_nodeType || snt_keyword_ref == passing->m_nodeType);
	GetterSetterNode* res = new GetterSetterNode((TokenNode*)keyword, 
		(TokenNode*)constant, (TypeNameNode*)type, (TokenNode*)passing); 
	g_syntaxNodes.push_back(res);
	return res;
}

SyntaxNode* newProperty(SyntaxNode* constant, SyntaxNode* type, SyntaxNode* passing, SyntaxNode* name)
{
	assert(0 == constant || snt_keyword_const == constant->m_nodeType);
	assert(0 == type || snt_type_name == type->m_nodeType);
	assert(0 == passing || snt_keyword_ptr == passing->m_nodeType || snt_keyword_ref == passing->m_nodeType);
	assert(snt_identify == name->m_nodeType);
	PropertyNode* res = new PropertyNode((TokenNode*)constant, (TypeNameNode*)type, (TokenNode*)passing, (IdentifyNode*) name);
	g_syntaxNodes.push_back(res);
	return res;
}

void setPropertyGetter(SyntaxNode* property, SyntaxNode* getter)
{
	assert(snt_property == property->m_nodeType);
	assert(snt_getter_setter == getter->m_nodeType);
	((PropertyNode*)property)->setGetter((GetterSetterNode*)getter);
}

void setPropertySetter(SyntaxNode* property, SyntaxNode* setter)
{
	assert(snt_property == property->m_nodeType);
	assert(snt_getter_setter == setter->m_nodeType);
	((PropertyNode*)property)->setSetter((GetterSetterNode*)setter);
}

void setPropertyModifier(SyntaxNode* syntaxNode, SyntaxNode* modifier)
{
	assert(snt_property == syntaxNode->m_nodeType);
	assert(snt_keyword_abstract == modifier->m_nodeType || snt_keyword_virtual == modifier->m_nodeType || snt_keyword_static == modifier->m_nodeType);
	PropertyNode* propertyNode = (PropertyNode*)syntaxNode;
	propertyNode->m_modifier = (TokenNode*)modifier;
}

SyntaxNode* newParameter(SyntaxNode* type, SyntaxNode* out, SyntaxNode* passing, SyntaxNode* name)
{
	assert(snt_type_name == type->m_nodeType && snt_identify == name->m_nodeType);
	assert(0 == out || snt_keyword_ptr == out->m_nodeType|| snt_keyword_new == out->m_nodeType);
	assert(0 == passing || snt_keyword_ptr == passing->m_nodeType|| snt_keyword_ref == passing->m_nodeType);
	ParameterNode* res = new ParameterNode((TypeNameNode*) type, (TokenNode*)out, (TokenNode*)passing, (IdentifyNode*) name);
	g_syntaxNodes.push_back(res);
	return res;
}

void setParameterArray(SyntaxNode* parameter)
{
	assert(snt_parameter == parameter->m_nodeType);
	static_cast<ParameterNode*>(parameter)->m_array = true;
}

void setParameterConst(SyntaxNode* parameter, SyntaxNode* constant)
{
	assert(snt_parameter == parameter->m_nodeType && snt_keyword_const == constant->m_nodeType);
	static_cast<ParameterNode*>(parameter)->m_constant = (TokenNode*)constant;
}

SyntaxNode* newParameterList(SyntaxNode* parameterList, SyntaxNode* delimiter, SyntaxNode* parameter)
{
	assert(0 == parameterList || snt_parameter_list == parameterList->m_nodeType);
	assert(0 == delimiter || ',' == delimiter->m_nodeType);
	assert(snt_parameter == parameter->m_nodeType);
	ParameterListNode* res = new ParameterListNode((ParameterListNode*)parameterList, (TokenNode*)delimiter, (ParameterNode*)parameter);
	g_syntaxNodes.push_back(res);
	return res;
}

SyntaxNode* newMethod(SyntaxNode* name, SyntaxNode* leftParenthesis, SyntaxNode* parameterList, SyntaxNode* rightParenthesis, SyntaxNode* constant, SyntaxNode* semicolon)
{
	assert(snt_identify == name->m_nodeType);
	assert('(' == leftParenthesis->m_nodeType && ')' == rightParenthesis->m_nodeType && ';' == semicolon->m_nodeType);	
	assert(0 == constant || snt_keyword_const == constant->m_nodeType);
	assert(0 == parameterList || snt_parameter_list == parameterList->m_nodeType);
	MethodNode* res = new MethodNode((IdentifyNode*)name, (TokenNode*)leftParenthesis, (ParameterListNode*)parameterList,
		(TokenNode*)rightParenthesis, (TokenNode*)constant, (TokenNode*)semicolon);
	g_syntaxNodes.push_back(res);
	return res;
}

void setMethodResult(SyntaxNode* method, SyntaxNode* result, SyntaxNode* passing)
{
	assert(snt_method == method->m_nodeType && snt_type_name == result->m_nodeType);
	assert(0 == passing || snt_keyword_ref == passing->m_nodeType || snt_keyword_ptr == passing->m_nodeType || snt_keyword_new == passing->m_nodeType);
	((MethodNode*)method)->m_result = (TypeNameNode*)result;
	((MethodNode*)method)->m_passing = (TokenNode*)passing;
}

void setMethodResultArray(SyntaxNode* method)
{
	assert(snt_method == method->m_nodeType);
	((MethodNode*)method)->m_resultArray = true;
}

void setMethodResultConst(SyntaxNode* method, SyntaxNode* constant)
{
	assert(snt_method == method->m_nodeType && snt_keyword_const == constant->m_nodeType);
	((MethodNode*)method)->m_resultConst = (TokenNode*)constant;
}

void setMethodModifier(SyntaxNode* method, SyntaxNode* modifier)
{
	assert(snt_method == method->m_nodeType);
	assert(snt_keyword_abstract == modifier->m_nodeType || snt_keyword_virtual == modifier->m_nodeType || snt_keyword_static == modifier->m_nodeType);
	((MethodNode*)method)->m_modifier = (TokenNode*)modifier;
}

void setMethodExport(SyntaxNode* method)
{
	assert(snt_method == method->m_nodeType);
	((MethodNode*)method)->m_export = true;
}

SyntaxNode* newFilter(int native, int meta)
{
	FilterNode* res = new FilterNode(native != 0, meta != 0);
	g_syntaxNodes.push_back(res);
	return res;
}

SyntaxNode* newClassMemberList(SyntaxNode* memberList, SyntaxNode* member)
{
	assert(0 == memberList || snt_member_list == memberList->m_nodeType);
	assert(snt_field == member->m_nodeType || snt_property == member->m_nodeType || snt_method == member->m_nodeType
		|| snt_filter == member->m_nodeType || snt_class == member->m_nodeType || snt_enum == member->m_nodeType);
	MemberListNode* res = new MemberListNode((MemberListNode*)memberList, (MemberNode*)member);
	g_syntaxNodes.push_back(res);
	return res;
}

SyntaxNode* newClass(SyntaxNode* keyword, SyntaxNode* name, SyntaxNode* category)
{
	assert(snt_keyword_class == keyword->m_nodeType || snt_keyword_struct == keyword->m_nodeType);
	assert(snt_identify == name->m_nodeType);
	assert(0 == category || snt_identify == category->m_nodeType);
	ClassNode* res = new ClassNode((TokenNode*)keyword, (IdentifyNode*)name, (IdentifyNode*)category);
	g_syntaxNodes.push_back(res);
	return res;	
}

void setClassBaseList(SyntaxNode* cls, SyntaxNode* colon, SyntaxNode* baseList)
{
	assert(snt_class == cls->m_nodeType);
	assert(0 == colon || ':' == colon->m_nodeType);
	assert(0 == baseList || snt_type_name_list == baseList->m_nodeType);
	((ClassNode*)cls)->m_colon = (TokenNode*)colon;
	((ClassNode*)cls)->m_baseList = (TypeNameListNode*)baseList;
}

void setClassMemberList(SyntaxNode* cls, SyntaxNode* leftBrace, SyntaxNode* memberList, SyntaxNode* rightBrace, SyntaxNode* semicolon)
{
	assert(snt_class == cls->m_nodeType);
	assert('{' == leftBrace->m_nodeType);	
	assert(0 == memberList || snt_member_list == memberList->m_nodeType);
	assert('}' == rightBrace->m_nodeType);
	assert(';' == semicolon->m_nodeType);	
	((ClassNode*)cls)->setMemberList((TokenNode*)leftBrace, (MemberListNode*)memberList, (TokenNode*)rightBrace, (TokenNode*)semicolon);
}

void setClassModifier(SyntaxNode* cls, SyntaxNode* modifier)
{
	assert(snt_class == cls->m_nodeType);
	assert(snt_keyword_abstract == modifier->m_nodeType);
	((ClassNode*)cls)->m_modifier = (TokenNode*)modifier;
}

void setClassExport(SyntaxNode* cls)
{
	assert(snt_class == cls->m_nodeType);
	((ClassNode*)cls)->m_export = true;
}

void setClassTemplateParameters(SyntaxNode* cls, SyntaxNode* parameters)
{
	assert(snt_class == cls->m_nodeType);
	assert(snt_template_parameters == parameters->m_nodeType);
	((ClassNode*)cls)->m_templateParameters = (TemplateParametersNode*)parameters;
}

SyntaxNode* newEnumeratorList(SyntaxNode* enumeratorList, SyntaxNode* delimiter, SyntaxNode* identify)
{
	assert(0 == enumeratorList || snt_enumerator_list == enumeratorList->m_nodeType);
	assert(0 == delimiter || ',' == delimiter->m_nodeType);
	assert((0 == delimiter && 0 == enumeratorList) || (0 != delimiter && 0 != enumeratorList));
	assert(snt_identify == identify->m_nodeType);
	EnumeratorListNode* res = new EnumeratorListNode((EnumeratorListNode*)enumeratorList, (TokenNode*)delimiter, (IdentifyNode*)identify);
	g_syntaxNodes.push_back(res);
	return res;
}

SyntaxNode* newEnum(SyntaxNode* keyword, SyntaxNode* name, SyntaxNode* leftBrace, SyntaxNode* enumeratorList, SyntaxNode* rightBrace, SyntaxNode* semicolon)
{
	assert(snt_keyword_enum == keyword->m_nodeType);
	assert(snt_identify == name->m_nodeType);
	assert('{' == leftBrace->m_nodeType);	
	assert(0 == enumeratorList || snt_enumerator_list == enumeratorList->m_nodeType);
	assert('}' == rightBrace->m_nodeType);
	assert(';' == semicolon->m_nodeType);
	
	EnumNode* res = new EnumNode((TokenNode*)keyword, (IdentifyNode*)name, 
		(TokenNode*)leftBrace, (EnumeratorListNode*)enumeratorList, (TokenNode*)rightBrace,
		(TokenNode*)semicolon);
	g_syntaxNodes.push_back(res);
	return res;
}

SyntaxNode* newTypeAlias(SyntaxNode* name, TypeCategory typeCategory)
{
	assert(snt_identify == name->m_nodeType);
	TypeAliasNode* res;
	res = new TypeAliasNode((IdentifyNode*)name, typeCategory);
	g_syntaxNodes.push_back(res);
	return res;
}

SyntaxNode* newTypeDef(SyntaxNode* keyword, SyntaxNode* name, SyntaxNode* typeName)
{
	assert(snt_keyword_typedef == keyword->m_nodeType);
	assert(snt_identify == name->m_nodeType);
	assert(snt_type_name == typeName->m_nodeType);
	TypeAliasNode* res;
	res = new TypeAliasNode((TokenNode*)keyword, (IdentifyNode*)name, (TypeNameNode*)typeName);
	g_syntaxNodes.push_back(res);
	return res;
}


SyntaxNode* newTemplateParameter(SyntaxNode* keyword, SyntaxNode* name)
{
	assert(snt_keyword_class == keyword->m_nodeType || snt_keyword_typename == keyword->m_nodeType);
	assert(snt_identify == name->m_nodeType);
	TemplateParameterNode* res = new TemplateParameterNode((TokenNode*)keyword, (IdentifyNode*)name);
	g_syntaxNodes.push_back(res);
	return res;
}

SyntaxNode* newTemplateParameterList(SyntaxNode* list, SyntaxNode* delimiter, SyntaxNode* identify)
{
	assert(0 == list || snt_template_parameter_list == list->m_nodeType);
	assert(0 == delimiter || ',' == delimiter->m_nodeType);
	assert(snt_template_parameter == identify->m_nodeType);
	TemplateParameterListNode* res = new TemplateParameterListNode((TemplateParameterListNode*)list, 
		(TokenNode*)delimiter, (TemplateParameterNode*)identify);
	g_syntaxNodes.push_back(res);
	return res;
}

SyntaxNode* newTemplateParameters(SyntaxNode* keyword, SyntaxNode* lab, SyntaxNode* parameterList, SyntaxNode* rab)
{
	assert(snt_keyword_template == keyword->m_nodeType);
	assert('<' == lab->m_nodeType);
	assert(snt_template_parameter_list == parameterList->m_nodeType);
	assert('>' == rab->m_nodeType);
	TemplateParametersNode* res = new TemplateParametersNode((TokenNode*)keyword, 
		(TokenNode*)lab, (TemplateParameterListNode*)parameterList, (TokenNode*)rab);
	g_syntaxNodes.push_back(res);
	return res;
}

//SyntaxNode* newTemplateClass(SyntaxNode* keyword, SyntaxNode* lab, SyntaxNode* parameterList, SyntaxNode* rab, SyntaxNode* cls)
//{
//	assert(snt_keyword_template == keyword->m_nodeType);
//	assert('<' == lab->m_nodeType);
//	assert(snt_template_parameter_list == parameterList->m_nodeType);
//	assert('>' == rab->m_nodeType);
//	assert(snt_class == cls->m_nodeType);
//	TemplateClassNode* res = new TemplateClassNode((TokenNode*)keyword, 
//		(TokenNode*)lab, (TemplateParameterListNode*)parameterList, (TokenNode*)rab, (ClassNode*)cls);
//	g_syntaxNodes.push_back(res);
//	return res;
//}

SyntaxNode* newTemplateClassInstance(SyntaxNode* keyword, SyntaxNode* keyword2, SyntaxNode* templateName, 
	SyntaxNode* lab, SyntaxNode* typeNameList, SyntaxNode* rab, SyntaxNode* semicolon)
{
	assert(snt_keyword_template == keyword->m_nodeType);
	assert(snt_keyword_class == keyword2->m_nodeType || snt_keyword_struct == keyword2->m_nodeType);
	assert(snt_identify == templateName->m_nodeType);
	assert('<' == lab->m_nodeType);
	assert(snt_type_name_list == typeNameList->m_nodeType);
	assert('>' == rab->m_nodeType);
	assert(';' == semicolon->m_nodeType);
	TemplateClassInstanceNode* res = new TemplateClassInstanceNode((TokenNode*)keyword, (TokenNode*)keyword2, 
		(IdentifyNode*)templateName, (TokenNode*)lab, (TypeNameListNode*)typeNameList, (TokenNode*)rab, (TokenNode*)semicolon);
	g_syntaxNodes.push_back(res);
	return res;
}

SyntaxNode* newNamespaceMemberList(SyntaxNode* memberList, SyntaxNode* member)
{
	assert(0 == memberList || snt_member_list == memberList->m_nodeType);
	assert(snt_class == member->m_nodeType 
		|| snt_enum == member->m_nodeType 
		|| snt_template_class_instance == member->m_nodeType
		|| snt_type_alias == member->m_nodeType 
		|| snt_namespace == member->m_nodeType);
	MemberListNode* res = new MemberListNode((MemberListNode*)memberList, (MemberNode*)member);
	g_syntaxNodes.push_back(res);
	return res;
}

SyntaxNode* newNamespace(SyntaxNode* keyword, SyntaxNode* name, SyntaxNode* leftBrace, SyntaxNode* memberList, SyntaxNode* rightBrace)
{
	assert(snt_keyword_namespace == keyword->m_nodeType);
	assert(snt_identify == name->m_nodeType);
	assert('{' == leftBrace->m_nodeType);
	assert(0 == memberList || snt_member_list == memberList->m_nodeType);
	assert('}' == rightBrace->m_nodeType);
	NamespaceNode* res = new NamespaceNode((TokenNode*)keyword, (IdentifyNode*)name, (TokenNode*)leftBrace, (MemberListNode*)memberList, (TokenNode*)rightBrace);
	g_syntaxNodes.push_back(res);
	return res;
}

SyntaxNode* newProgram(SyntaxNode* memberList)
{
	assert(0 == memberList || snt_member_list == memberList->m_nodeType);
	ProgramNode* res = new ProgramNode((MemberListNode*)memberList);
	g_syntaxNodes.push_back(res);
	return res;
}

//
//void setPackageName(SyntaxNode* identify)
//{
//	assert(snt_identify == identify->m_nodeType);
//	setCurrentPackageName(((IdentifyNode*)identify)->m_str.c_str());
//}

int calcColumnAfterCodeBlock(char* s)
{
	char* p = strrchr(s, '\n');
	if(0 == p)
	{
		p = s;
	}
	return strlen(p) + 1;
}

void invalidString(char* s)
{
	ErrorList_AddItem_CurrentFile(syntax_error_invalid_string, s);
}

void unterminatedCode()
{
	ErrorList_AddItem_CurrentFile(syntax_error_unterminated_code, "unterminated cpp code block, cannot find \"*$\"");
}

void unterminatedComment()
{
	ErrorList_AddItem_CurrentFile(syntax_error_unterminated_comment, "unterminated comment block, cannot find \"*/\"");
}

void attachSyntaxTree(SyntaxNode* tree)
{
	assert(snt_namespace == tree->m_nodeType);
	g_sourceFileManager.attachSyntaxTree((ProgramNode*)tree);
}

void freetree()
{
	size_t count = g_syntaxNodes.size();
	for(size_t i = 0; i < count; ++i)
	{
		delete g_syntaxNodes[i];
	}
	g_syntaxNodes.clear();
}

void yyerror(char* s)
{
	ErrorList_AddItem_CurrentFile(syntax_error_internal, s);
}
//
//void yyerror(char* s, ...)
//{
//	va_list ap;
//	va_start(ap, s);
//	fprintf(stderr, "%s(%d,): error:", g_inputFileName, yylineno);
//	vfprintf(stderr, s, ap);
//	fprintf(stderr, "\n");
//}
