%{
#include "yyfuncs.h"
%}

%union
{
	struct SyntaxNode* sn;
}

%token <sn> BOOL CHAR WCHAR_T SHORT LONG INT FLOAT DOUBLE SIGNED UNSIGNED
%token <sn> NAMESPACE ENUM CLASS STRUCT STATIC VIRTUAL VOID CONST TEMPLATE TYPENAME TYPEDEF NEW
%token <sn> ABSTRACT GET SET ALL NATIVE META REF PTR LAB RAB EXPORT
%token <sn> ',' '.' ':' ';' '(' ')' '[' ']' '{' '}' SCOPE IDENTIFY
%type <sn> field_0 field_1 field getter setter property_0 property_1 property
%type <sn> parameter_0 parameter parameterList method_0 method_1 method_2 method_3 method filter
%type <sn> primitive scopeList_0 scopeList typeName typeNameList enumeratorList classMemberList 
%type <sn> templateParameter templateParameterList templateParameters templateClassInstance typeAlias
%type <sn> class_0 class_1 class_2 class_3 class_4 class enum namespaceMemberList namespace program
%start program

%%

primitive				: BOOL												{$$ = newPrimitiveType($1, pt_bool);}
						| CHAR												{$$ = newPrimitiveType($1, pt_char);}
						| SIGNED CHAR										{$$ = newPrimitiveType($1, pt_schar);}
						| UNSIGNED CHAR										{$$ = newPrimitiveType($1, pt_uchar);}
						| WCHAR_T											{$$ = newPrimitiveType($1, pt_wchar_t);}
						| SHORT												{$$ = newPrimitiveType($1, pt_short);}
						| SIGNED SHORT										{$$ = newPrimitiveType($1, pt_short);}
						| UNSIGNED SHORT									{$$ = newPrimitiveType($1, pt_ushort);}
						| LONG												{$$ = newPrimitiveType($1, pt_long);}
						| SIGNED LONG										{$$ = newPrimitiveType($1, pt_long);}
						| UNSIGNED LONG										{$$ = newPrimitiveType($1, pt_ulong);}
						| LONG LONG											{$$ = newPrimitiveType($1, pt_longlong);}
						| SIGNED LONG LONG									{$$ = newPrimitiveType($1, pt_longlong);}
						| UNSIGNED LONG LONG								{$$ = newPrimitiveType($1, pt_ulonglong);}
						| INT												{$$ = newPrimitiveType($1, pt_int);}
						| SIGNED INT										{$$ = newPrimitiveType($1, pt_int);}
						| SIGNED											{$$ = newPrimitiveType($1, pt_int);}
						| UNSIGNED INT										{$$ = newPrimitiveType($1, pt_uint);}
						| UNSIGNED											{$$ = newPrimitiveType($1, pt_uint);}
						| FLOAT												{$$ = newPrimitiveType($1, pt_float);}
						| DOUBLE											{$$ = newPrimitiveType($1, pt_double);}
						| VOID												{$$ = newPrimitiveType($1, pt_void);}
;

enumeratorList			: IDENTIFY											{$$ = newEnumeratorList(NULL, NULL, $1);}
						| enumeratorList ',' IDENTIFY						{$$ = newEnumeratorList($1, $2, $3);}
;

enum					: ENUM IDENTIFY '{' enumeratorList '}' ';'			{$$ = newEnum($1, $2, $3, $4, $5, $6);}
						| ENUM IDENTIFY '{' enumeratorList ',' '}' ';'		{$$ = newEnum($1, $2, $3, $4, $6, $7);}
						| ENUM IDENTIFY '{' '}' ';'							{$$ = newEnum($1, $2, $3, NULL, $4, $5);}
;

scopeList_0				: IDENTIFY											{$$ = newScopeList(NULL, $1);}
						| scopeList_0 SCOPE IDENTIFY						{$$ = newScopeList($1, $3);}
;

scopeList				: scopeList_0										{$$ = $1;}
						| SCOPE scopeList_0									{$$ = $2; setScopeListGlobal($$);}
;

typeName				: primitive											{$$ = $1;}
						| scopeList											{$$ = newTypeName($1);}
						| scopeList	LAB typeNameList RAB					{$$ = newTemplateTypeName($1, $2, $3, $4);}
;

typeNameList			: typeName											{$$ = newTypeNameList(NULL, NULL, $1);}
						| typeNameList ',' typeName							{$$ = newTypeNameList($1, $2, $3);}
;

field_0					: typeName IDENTIFY ';'								{$$ = newField($1, $2, NULL, NULL, $3);}
						| typeName IDENTIFY '[' ']'	';'						{$$ = newField($1, $2, $3, $4, $5);}
;

field_1					: field_0											{$$ = $1;}
						| CONST field_0										{$$ = $2; setFieldConstant($$, $1);}
;

field					: field_1											{$$ = $1;}
						| STATIC field_1									{$$ = $2; setFieldStatic($$, $1);}
;

getter					: GET												{$$ = newGetterSetter($1, NULL, NULL, NULL);}
						| GET '(' typeName ')'								{$$ = newGetterSetter($1, NULL, $3, NULL);}
						| GET '(' typeName PTR ')'							{$$ = newGetterSetter($1, NULL, $3, $4);}
						| GET '(' typeName REF ')'							{$$ = newGetterSetter($1, NULL, $3, $4);}
						| GET '(' CONST typeName PTR ')'					{$$ = newGetterSetter($1, $3, $4, $5);}
						| GET '(' CONST typeName REF ')'					{$$ = newGetterSetter($1, $3, $4, $5);}
;

setter					: SET												{$$ = newGetterSetter($1, NULL, NULL, NULL);}
						| SET '(' typeName ')'								{$$ = newGetterSetter($1, NULL, $3, NULL);}
						| SET '(' typeName PTR ')'							{$$ = newGetterSetter($1, NULL, $3, $4);}
						| SET '(' typeName REF ')'							{$$ = newGetterSetter($1, NULL, $3, $4);}
						| SET '(' CONST typeName PTR ')'					{$$ = newGetterSetter($1, $3, $4, $5);}
						| SET '(' CONST typeName REF ')'					{$$ = newGetterSetter($1, $3, $4, $5);}
;


property_0				: typeName IDENTIFY									{$$ = newProperty(NULL, $1, NULL, $2);}
						| typeName PTR IDENTIFY								{$$ = newProperty(NULL, $1, $2, $3);}
						| typeName REF IDENTIFY 							{$$ = newProperty(NULL, $1, $2, $3);}
						| CONST typeName PTR IDENTIFY						{$$ = newProperty($1, $2, $3, $4);}
						| CONST typeName REF IDENTIFY						{$$ = newProperty($1, $2, $3, $4);}
;


property_1				: property_0 getter ';'								{$$ = $1; setPropertyGetter($1, $2);}
						| property_0 setter ';'								{$$ = $1; setPropertySetter($1, $2);}
						| property_0 getter setter ';'						{$$ = $1; setPropertyGetter($1, $2); setPropertySetter($1, $3);}
						| property_0 setter getter ';'						{$$ = $1; setPropertyGetter($1, $3); setPropertySetter($1, $2);}
;


property				: property_1										{$$ = $1;}
						| STATIC property_1									{$$ = $2; setPropertyModifier($$, $1);}
;

parameter_0				: typeName IDENTIFY									{$$ = newParameter($1, NULL, NULL, $2);}
						| typeName PTR IDENTIFY								{$$ = newParameter($1, NULL, $2, $3);}
						| typeName REF IDENTIFY								{$$ = newParameter($1, NULL, $2, $3);}
						| typeName PTR PTR IDENTIFY							{$$ = newParameter($1, $2, $3, $4);}
						| typeName NEW PTR IDENTIFY							{$$ = newParameter($1, $2, $3, $4);}
						| typeName NEW '[' ']' PTR IDENTIFY					{$$ = newParameter($1, $2, $5, $6); setParameterArray($$);}
						| typeName PTR REF IDENTIFY							{$$ = newParameter($1, $2, $3, $4);}
						| typeName NEW REF IDENTIFY							{$$ = newParameter($1, $2, $3, $4);}
						| typeName NEW '[' ']' REF IDENTIFY					{$$ = newParameter($1, $2, $5, $6); setParameterArray($$);}
;

parameter				: parameter_0										{$$ = $1;}
						| CONST parameter_0									{$$ = $2; setParameterConst($$, $1);}
;

parameterList			: parameter											{$$ = newParameterList(NULL, NULL, $1);}
						| parameterList ',' parameter						{$$ = newParameterList($1, $2, $3);}
;

method_0				: IDENTIFY '(' ')' ';'								{$$ = newMethod($1, $2, NULL, $3, NULL, $4);}
						| IDENTIFY '(' parameterList ')' ';'				{$$ = newMethod($1, $2, $3, $4, NULL, $5);}
						| IDENTIFY '(' ')' CONST ';'						{$$ = newMethod($1, $2, NULL, $3, $4, $5);}
						| IDENTIFY '(' parameterList ')' CONST ';'			{$$ = newMethod($1, $2, $3, $4, $5, $6);}
;

method_1				: method_0											{$$ = $1;}
						| typeName method_0									{$$ = $2; setMethodResult($$, $1, NULL);}
						| typeName REF method_0								{$$ = $3; setMethodResult($$, $1, $2);}
						| typeName PTR method_0								{$$ = $3; setMethodResult($$, $1, $2);}
						| typeName NEW method_0								{$$ = $3; setMethodResult($$, $1, $2);}
						| typeName NEW '[' ']' method_0						{$$ = $5; setMethodResult($$, $1, $2); setMethodResultArray($$);}
;

method_2				: method_1											{$$ = $1;}
						| CONST method_1									{$$ = $2; setMethodResultConst($$, $1);}
;

method_3				: method_2											{$$ = $1;}
						| ABSTRACT method_2									{$$ = $2; setMethodModifier($$, $1);}
						| VIRTUAL method_2									{$$ = $2; setMethodModifier($$, $1);}
						| STATIC method_2									{$$ = $2; setMethodModifier($$, $1);}
;

method					: method_3											{$$ = $1;}
						| EXPORT method_3									{$$ = $2; setMethodExport($$);}
;

filter					: ALL ':'											{$$ = newFilter(1, 1);}
						| NATIVE ':'										{$$ = newFilter(1, 0);}
						| META ':'											{$$ = newFilter(0, 1);}
;

classMemberList			: property											{$$ = newClassMemberList(NULL, $1);}
						| method											{$$ = newClassMemberList(NULL, $1);}
						| field												{$$ = newClassMemberList(NULL, $1);}
						| class_4											{$$ = newClassMemberList(NULL, $1);}
						| enum												{$$ = newClassMemberList(NULL, $1);}
						| filter											{$$ = newClassMemberList(NULL, $1);}
						| ';'												{$$ = NULL;}
						| classMemberList property							{$$ = newClassMemberList($1, $2);}
						| classMemberList method							{$$ = newClassMemberList($1, $2);}
						| classMemberList field								{$$ = newClassMemberList($1, $2);}
						| classMemberList class_4							{$$ = newClassMemberList($1, $2);}
						| classMemberList enum								{$$ = newClassMemberList($1, $2);}
						| classMemberList filter							{$$ = newClassMemberList($1, $2);}
						| classMemberList ';'								{$$ = $1;}
;

templateParameter		: CLASS IDENTIFY									{$$ = newTemplateParameter($1, $2);}
						| TYPENAME IDENTIFY									{$$ = newTemplateParameter($1, $2);}
;

templateParameterList	: templateParameter									{$$ = newTemplateParameterList(NULL, NULL, $1);}
						| templateParameterList ',' templateParameter		{$$ = newTemplateParameterList($1, $2, $3);}
;

templateParameters		: TEMPLATE LAB templateParameterList RAB			{$$ = newTemplateParameters($1, $2, $3, $4);}
;

class_0					: CLASS IDENTIFY									{$$ = newClass($1, $2, NULL);}
						| CLASS IDENTIFY '(' IDENTIFY ')' 					{$$ = newClass($1, $2, $4);}
						| STRUCT IDENTIFY									{$$ = newClass($1, $2, NULL);}
						| STRUCT IDENTIFY '(' IDENTIFY ')' 					{$$ = newClass($1, $2, $4);}
;

class_1					: class_0											{$$ = $1;}
						| class_0 ':' typeNameList							{$$ = $1; setClassBaseList($$, $2, $3);}
;

class_2					: class_1 '{' '}' ';'								{$$ = $1; setClassMemberList($$, $2, NULL, $3, $4);}
						| class_1 '{' classMemberList '}' ';'				{$$ = $1; setClassMemberList($$, $2, $3, $4, $5);}
;

class_3					: class_2											{$$ = $1;}
						| ABSTRACT class_2									{$$ = $2; setClassModifier($$, $1);}
;

class_4					: class_3											{$$ = $1;}
						| EXPORT class_3									{$$ = $2; setClassExport($$);}
;

class					: class_4											{$$ = $1;}
						| templateParameters class_4						{$$ = $2; setClassTemplateParameters($$, $1);}
;

templateClassInstance	: TEMPLATE CLASS IDENTIFY LAB typeNameList RAB ';'	{$$ = newTemplateClassInstance($1, $2, $3, $4, $5, $6, $7);}
						| TEMPLATE STRUCT IDENTIFY LAB typeNameList RAB ';'	{$$ = newTemplateClassInstance($1, $2, $3, $4, $5, $6, $7);}
;

typeAlias				: TYPENAME IDENTIFY ';'								{$$ = newTypeAlias($2, primitive_type);}
						| TYPENAME STRUCT IDENTIFY ';'						{$$ = newTypeAlias($3, value_type);}
						| TYPENAME CLASS IDENTIFY ';'						{$$ = newTypeAlias($3, reference_type);}
						| TYPEDEF typeName IDENTIFY ';'						{$$ = newTypeDef($1, $3, $2);}
;

namespaceMemberList		: class												{$$ = newNamespaceMemberList(NULL, $1);}
						| enum												{$$ = newNamespaceMemberList(NULL, $1);}
						| templateClassInstance								{$$ = newNamespaceMemberList(NULL, $1);}
						| typeAlias											{$$ = newNamespaceMemberList(NULL, $1);}
						| namespace											{$$ = newNamespaceMemberList(NULL, $1);}
						| ';'												{$$ = NULL;}
						| namespaceMemberList class							{$$ = newNamespaceMemberList($1, $2);}
						| namespaceMemberList enum							{$$ = newNamespaceMemberList($1, $2);}
						| namespaceMemberList templateClassInstance			{$$ = newNamespaceMemberList($1, $2);}
						| namespaceMemberList typeAlias						{$$ = newNamespaceMemberList($1, $2);}
						| namespaceMemberList namespace						{$$ = newNamespaceMemberList($1, $2);}
						| namespaceMemberList ';'							{$$ = $1;}
;

namespace				: NAMESPACE	IDENTIFY '{' '}'						{$$ = newNamespace($1, $2, $3, NULL, $4);}
						| NAMESPACE	IDENTIFY '{' namespaceMemberList '}'	{$$ = newNamespace($1, $2, $3, $4, $5);}
;

program					: namespaceMemberList								{$$ = newProgram($1); attachSyntaxTree($$);}
;
