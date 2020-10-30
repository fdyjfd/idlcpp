%{
#include "yyfuncs.h"
%}

%union
{
	struct SyntaxNode* sn;
}

%token <sn> ',' '.' ':' ';' '(' ')' '[' ']' '{' '}' '<' '>' '*' '&' '+' '^' '-' '/' '%' '|' '~' '!' '='
%token <sn> ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN BIT_XOR_ASSIGN BIT_AND_ASSIGN BIT_OR_ASSIGN LEFT_SHIFT_ASSIGN RIGHT_SHIFT_ASSIGN
%token <sn> LEFT_SHIFT RIGHT_SHIFT EQUAL NOT_EQUAL LESS_EQUAL GREATER_EQUAL AND OR INC DEC
%token <sn> BOOL CHAR WCHAR_T SHORT LONG INT FLOAT DOUBLE SIGNED UNSIGNED STRING_T
%token <sn> NAMESPACE ENUM CLASS STRUCT STATIC VIRTUAL VOID CONST OPERATOR TYPEDEF PRIMITIVE
%token <sn> ABSTRACT GET SET CANDIDATE NOMETA NOCODE EXPORT OVERRIDE SCOPE IDENTIFY STRING U8STRING TEMPLATE DELEGATE
%type <sn> identifyList enumerator enumeratorList enum_0 enum 
%type <sn> field_0 field_1 field_2 field getter_0 getter_1 getter setter_0 setter_1 setter_2 setter candidate property_0 property_1 property_2 property
%type <sn> parameter_0 parameter_1 parameter parameterList method_0 method_1 method_2 method_3 method_4 method
%type <sn> operatorSign operator_0 operator_1 operator_2 operator_3 operator classMember_0 classMember
%type <sn> delegate_0 delegate_1 delegate
%type <sn> primitive scopeName scopeNameList_0 scopeNameList typeName_0 typeName typeNameList classMemberList tokenList
%type <sn> templateParameterList templateParameters templateClassInstance_0 templateClassInstance
%type <sn> class_0 class_1 class_2 class_3 class_4 class_5 class namespaceMember_0 namespaceMember namespaceMemberList namespace program
%type <sn> typeAlias attribute attributeList attributes

%start program

%%

primitive				: VOID												{$$ = newPrimitiveType($1, pt_void);}
						| BOOL												{$$ = newPrimitiveType($1, pt_bool);}
						| CHAR												{$$ = newPrimitiveType($1, pt_char);}
						| SIGNED CHAR										{$$ = newPrimitiveType($1, pt_schar);}
						| UNSIGNED CHAR										{$$ = newPrimitiveType($1, pt_uchar);}
						| WCHAR_T											{$$ = newPrimitiveType($1, pt_wchar_t);}
						| SHORT												{$$ = newPrimitiveType($1, pt_short);}
						| SHORT INT											{$$ = newPrimitiveType($1, pt_short);}
						| SIGNED SHORT										{$$ = newPrimitiveType($1, pt_short);}
						| SIGNED SHORT INT									{$$ = newPrimitiveType($1, pt_short);}
						| UNSIGNED SHORT									{$$ = newPrimitiveType($1, pt_ushort);}
						| UNSIGNED SHORT INT								{$$ = newPrimitiveType($1, pt_ushort);}
						| LONG												{$$ = newPrimitiveType($1, pt_long);}
						| LONG INT											{$$ = newPrimitiveType($1, pt_long);}
						| SIGNED LONG										{$$ = newPrimitiveType($1, pt_long);}
						| SIGNED LONG INT									{$$ = newPrimitiveType($1, pt_long);}
						| UNSIGNED LONG										{$$ = newPrimitiveType($1, pt_ulong);}
						| UNSIGNED LONG INT									{$$ = newPrimitiveType($1, pt_ulong);}
						| LONG LONG											{$$ = newPrimitiveType($1, pt_longlong);}
						| LONG LONG INT										{$$ = newPrimitiveType($1, pt_longlong);}
						| SIGNED LONG LONG									{$$ = newPrimitiveType($1, pt_longlong);}
						| SIGNED LONG LONG INT								{$$ = newPrimitiveType($1, pt_longlong);}
						| UNSIGNED LONG LONG								{$$ = newPrimitiveType($1, pt_ulonglong);}
						| UNSIGNED LONG LONG INT							{$$ = newPrimitiveType($1, pt_ulonglong);}
						| INT												{$$ = newPrimitiveType($1, pt_int);}
						| SIGNED INT										{$$ = newPrimitiveType($1, pt_int);}
						| SIGNED											{$$ = newPrimitiveType($1, pt_int);}
						| UNSIGNED INT										{$$ = newPrimitiveType($1, pt_uint);}
						| UNSIGNED											{$$ = newPrimitiveType($1, pt_uint);}
						| FLOAT												{$$ = newPrimitiveType($1, pt_float);}
						| DOUBLE											{$$ = newPrimitiveType($1, pt_double);}
						| LONG DOUBLE										{$$ = newPrimitiveType($1, pt_long_double);}
						| STRING_T											{$$ = newPrimitiveType($1, pt_string_t);}
;

attribute				: IDENTIFY											{$$ = newAttribute($1, NULL, 0);}
						| IDENTIFY '=' STRING								{$$ = newAttribute($1, $3, 0);}
						| IDENTIFY '=' U8STRING								{$$ = newAttribute($1, $3, 1);}
;

attributeList			: attribute											{$$ = newAttributeList(NULL, $1);}
						| attributeList ',' attribute						{$$ = newAttributeList($1, $3);}
;

attributes				: '[' attributeList ']'								{$$ = $2;}
						| '[' attributeList ',' ']'							{$$ = $2;}
						| '[' ']'											{$$ = NULL;}
;

identifyList			: IDENTIFY											{$$ = newIdentifyList(NULL, NULL, $1);}
						| identifyList ',' IDENTIFY							{$$ = newIdentifyList($1, $2, $3);}
;

enumerator				: IDENTIFY											{$$ = newEnumerator(NULL, $1);}
						| attributes IDENTIFY								{$$ = newEnumerator($1, $2);}
;

enumeratorList			: enumerator										{$$ = newEnumeratorList(NULL, NULL, $1);}
						| enumeratorList ',' enumerator						{$$ = newEnumeratorList($1, $2, $3);}
;


enum_0					: ENUM IDENTIFY '{' enumeratorList '}'				{$$ = newEnum($1, NULL, $2, $3, $4, $5);}
						| ENUM IDENTIFY '{' enumeratorList ',' '}'			{$$ = newEnum($1, NULL, $2, $3, $4, $6);}
						| ENUM IDENTIFY '{' '}'								{$$ = newEnum($1, NULL, $2, $3, NULL, $4);}
						| ENUM CLASS IDENTIFY '{' enumeratorList '}'		{$$ = newEnum($1, $2, $3, $4, $5, $6);}
						| ENUM CLASS IDENTIFY '{' enumeratorList ',' '}'	{$$ = newEnum($1, $2, $3, $4, $5, $7);}
						| ENUM CLASS IDENTIFY '{' '}'						{$$ = newEnum($1, $2, $3, $4, NULL, $5);}
;

enum					: enum_0 ';'										{$$ = $1; setEnumSemicolon($$, $2);}
						| enum_0 '=' STRING ';'								{$$ = $1; setNativeName($$, $3); setEnumSemicolon($$, $4);}
;

scopeName				: IDENTIFY											{$$ = newScopeName($1, NULL, NULL, NULL);}
						| IDENTIFY '<' typeNameList '>'						{$$ = newScopeName($1, $2, $3, $4);}	
;

scopeNameList_0			: scopeName											{$$ = newScopeNameList(NULL, $1);}
						| scopeNameList_0 SCOPE scopeName					{$$ = newScopeNameList($1, $3);}
;

scopeNameList			: scopeNameList_0									{$$ = $1;}
						| SCOPE scopeNameList_0								{$$ = $2; setScopeNameListGlobal($$);}
;

typeName_0				: primitive											{$$ = $1;}
						| scopeNameList										{$$ = newTypeName($1);}
;

typeName				: typeName_0										{$$ = $1;}
						| NOCODE typeName_0									{$$ = $2; setTypeNameFilter($$, $1);}
						| NOMETA typeName_0									{$$ = $2; setTypeNameFilter($$, $1);}
;

typeNameList			: typeName											{$$ = newTypeNameList(NULL, NULL, $1);}
						| typeNameList ',' typeName							{$$ = newTypeNameList($1, $2, $3);}
;

typeAlias				: TYPEDEF typeName IDENTIFY ';'						{$$ = newTypedef($1, $3, $2);}
						| PRIMITIVE IDENTIFY ';'							{$$ = newTypeDeclaration($2, primitive_type);}
						| ENUM IDENTIFY ';'									{$$ = newTypeDeclaration($2, enum_type);}
						| STRUCT IDENTIFY ';'								{$$ = newTypeDeclaration($2, value_type);}
						| CLASS IDENTIFY ';'								{$$ = newTypeDeclaration($2, reference_type);}
						| PRIMITIVE IDENTIFY '=' STRING ';'					{$$ = newTypeDeclaration($2, primitive_type); setNativeName($$, $4);}
						| ENUM IDENTIFY '=' STRING ';'						{$$ = newTypeDeclaration($2, enum_type); setNativeName($$, $4);}
						| STRUCT IDENTIFY '=' STRING ';'					{$$ = newTypeDeclaration($2, value_type); setNativeName($$, $4);}
						| CLASS IDENTIFY '=' STRING ';'						{$$ = newTypeDeclaration($2, reference_type); setNativeName($$, $4);}
;

field_0					: typeName IDENTIFY									{$$ = newField($1, NULL, $2, NULL, NULL);}
						| typeName IDENTIFY '[' ']'							{$$ = newField($1, NULL, $2, $3, $4);}
						| typeName '*' IDENTIFY								{$$ = newField($1, $2, $3, NULL, NULL);}
;

field_1					: field_0											{$$ = $1;}
						| CONST field_0										{$$ = $2; setFieldConstant($$, $1);}
;

field_2					: field_1											{$$ = $1;}
						| STATIC field_1									{$$ = $2; setFieldStatic($$, $1);}
;

field					: field_2 ';'										{$$ = $1; setFieldSemicolon($$, $2);}
						| field_2 '=' STRING ';'							{$$ = $1; setNativeName($$, $3); setFieldSemicolon($$, $4);}
;


getter_0				: GET												{$$ = newGetterSetter($1);}
;

getter_1				: getter_0											{$$ = $1;}
						| getter_0 '+'										{$$ = $1; setGetterIncRef($$);}
;

getter					: getter_1											{$$ = $1;}
						| getter_1 '=' STRING								{$$ = $1; setGetterSetterNativeName($$, $3);}
;

setter_0				: SET												{$$ = newGetterSetter($1);}
;

setter_1				: setter_0											{$$ = $1;}
						| setter_0 '-'										{$$ = $1; setSetterDecRef($$);}
;

setter_2				: setter_1											{$$ = $1;}
						| setter_1 '?'										{$$ = $1; setSetterAllowNull($$);}
;

setter					: setter_2											{$$ = $1;}
						| setter_2 '=' STRING								{$$ = $1; setGetterSetterNativeName($$, $3);}
;

candidate				: CANDIDATE											{$$ = $1;}
;

property_0				: IDENTIFY											{$$ = newProperty($1, simple_property);}
						| IDENTIFY '[' ']'									{$$ = newProperty($1, fixed_array_property);}
						| IDENTIFY '[' '?' ']'								{$$ = newProperty($1, dynamic_array_property);}
						| IDENTIFY '[' '*' ']'								{$$ = newProperty($1, list_property);}
						| IDENTIFY '[' typeName ']'							{$$ = newProperty($1, map_property); setMapPropertyKeyType($$, $3, NULL);}
						| IDENTIFY '[' typeName '*' ']'						{$$ = newProperty($1, map_property); setMapPropertyKeyType($$, $3, $4);}
;

property_1				: typeName property_0								{$$ = $2; setPropertyType($$, $1, NULL);}
						| typeName '*' property_0							{$$ = $3; setPropertyType($$, $1, $2);}
						| typeName '&' property_0							{$$ = $3; setPropertyType($$, $1, $2);}
;

property_2				: property_1 '{' '}' ';'							{$$ = $1;}
						| property_1 '{' getter '}' ';'						{$$ = $1; setPropertyGetter($$, $3);}
						| property_1 '{' setter '}' ';'						{$$ = $1; setPropertySetter($$, $3);}
						| property_1 '{' getter setter '}' ';'				{$$ = $1; setPropertyGetter($$, $3); setPropertySetter($1, $4);}
						| property_1 '{' setter getter '}' ';'				{$$ = $1; setPropertyGetter($$, $4); setPropertySetter($1, $3);}
						| property_1 '{' getter candidate '}' ';'			{$$ = $1; setPropertyGetter($$, $3); setPropertyCandidate($$);}
						| property_1 '{' setter candidate '}' ';'			{$$ = $1; setPropertySetter($$, $3); setPropertyCandidate($$);}
						| property_1 '{' getter setter candidate '}' ';'	{$$ = $1; setPropertyGetter($$, $3); setPropertySetter($1, $4); setPropertyCandidate($$);}
						| property_1 '{' setter getter candidate '}' ';'	{$$ = $1; setPropertyGetter($$, $4); setPropertySetter($1, $3); setPropertyCandidate($$);}
;

property				: property_2										{$$ = $1;}
						| STATIC property_2									{$$ = $2; setPropertyModifier($$, $1);}
;


parameter_0				: typeName IDENTIFY									{$$ = newParameter($1, NULL, NULL, $2);}
						| typeName '&' IDENTIFY								{$$ = newParameter($1, $2, NULL, $3);}
						| typeName '*' IDENTIFY								{$$ = newParameter($1, $2, NULL, $3);}
						| typeName '-' IDENTIFY								{$$ = newParameter($1, $2, NULL, $3);}
						| typeName '*' '&' IDENTIFY							{$$ = newParameter($1, $2, $3, $4);}
						| typeName '*' '*' IDENTIFY							{$$ = newParameter($1, $2, $3, $4);}
						| typeName '+' '&' IDENTIFY							{$$ = newParameter($1, $2, $3, $4);}
						| typeName '+' '*' IDENTIFY							{$$ = newParameter($1, $2, $3, $4);}
						| typeName '+' '[' ']' '&' IDENTIFY					{$$ = newParameter($1, $2, $5, $6); setParameterArray($$);}
						| typeName '+' '[' ']' '*' IDENTIFY					{$$ = newParameter($1, $2, $5, $6); setParameterArray($$);}
;

parameter_1				: parameter_0										{$$ = $1;}
						| CONST parameter_0									{$$ = $2; setParameterConst($$, $1);}
;

parameter				: parameter_1										{$$ = $1;}
						| parameter_1 '?'									{$$ = $1; setParameterAllowNull($$);}
;

parameterList			: parameter											{$$ = newParameterList(NULL, NULL, $1);}
						| parameterList ',' parameter						{$$ = newParameterList($1, $2, $3);}
;

method_0				: IDENTIFY '(' ')'									{$$ = newMethod($1, $2, NULL, $3, NULL);}
						| IDENTIFY '(' VOID ')'								{$$ = newMethod($1, $2, NULL, $4, NULL);}
						| IDENTIFY '(' parameterList ')'					{$$ = newMethod($1, $2, $3, $4, NULL);}
						| IDENTIFY '(' ')' CONST							{$$ = newMethod($1, $2, NULL, $3, $4);}
						| IDENTIFY '(' VOID ')' CONST						{$$ = newMethod($1, $2, NULL, $4, $5);}
						| IDENTIFY '(' parameterList ')' CONST				{$$ = newMethod($1, $2, $3, $4, $5);}
;

method_1				: method_0											{$$ = $1;}
						| typeName method_0									{$$ = $2; setMethodResult($$, $1, NULL);}
						| typeName '&' method_0								{$$ = $3; setMethodResult($$, $1, $2);}
						| typeName '*' method_0								{$$ = $3; setMethodResult($$, $1, $2);}
						| typeName '+' method_0								{$$ = $3; setMethodResult($$, $1, $2);}
						| typeName '+' '[' ']' method_0						{$$ = $5; setMethodResult($$, $1, $2); setMethodResultArray($$);}
;

method_2				: method_1											{$$ = $1;}
						| CONST method_1									{$$ = $2; setMethodResultConst($$, $1);}
;

method_3				: method_2											{$$ = $1;}
						| ABSTRACT method_2									{$$ = $2; setMethodModifier($$, $1);}
						| VIRTUAL method_2									{$$ = $2; setMethodModifier($$, $1);}
						| STATIC method_2									{$$ = $2; setMethodModifier($$, $1);}
;

method_4				: method_3											{$$ = $1;}
						| OVERRIDE method_3									{$$ = $2; setMethodOverride($$);}
;

method					: method_4 ';'										{$$ = $1; setMethodSemicolon($$, $2);}
						| method_4 '=' STRING ';'							{$$ = $1; setNativeName($$, $3); setMethodSemicolon($$, $4);}
;

operatorSign			: '+'
						| '-'
						| '*'
						| '/'
						| '%'
						| '^'
						| '&'
						| '|'
						| '~'
						| '!'
						| '='
						| '<'
						| '>'
						| ','
						| '[' ']'
						| '(' ')'
						| ADD_ASSIGN
						| SUB_ASSIGN
						| MUL_ASSIGN
						| DIV_ASSIGN
						| MOD_ASSIGN
						| BIT_XOR_ASSIGN
						| BIT_AND_ASSIGN
						| BIT_OR_ASSIGN
						| LEFT_SHIFT
						| RIGHT_SHIFT
						| LEFT_SHIFT_ASSIGN
						| RIGHT_SHIFT_ASSIGN
						| EQUAL
						| NOT_EQUAL
						| LESS_EQUAL
						| GREATER_EQUAL
						| AND
						| OR
						| INC
						| DEC
;


operator_0				: OPERATOR operatorSign '(' ')' ';'						{$$ = newOperator($1, $2, $3, NULL, $4, NULL, $5);}
						| OPERATOR operatorSign '(' parameterList ')' ';'		{$$ = newOperator($1, $2, $3, $4, $5, NULL, $6);}
						| OPERATOR operatorSign '(' ')' CONST ';'				{$$ = newOperator($1, $2, $3, NULL, $4, $5, $6);}
						| OPERATOR operatorSign '(' parameterList ')' CONST ';'	{$$ = newOperator($1, $2, $3, $4, $5, $6, $7);}
;


operator_1				: typeName operator_0									{$$ = $2; setOperatorResult($$, $1, NULL);}
						| typeName '&' operator_0								{$$ = $3; setOperatorResult($$, $1, $2);}
						| typeName '*' operator_0								{$$ = $3; setOperatorResult($$, $1, $2);}
						| typeName '+' operator_0								{$$ = $3; setOperatorResult($$, $1, $2);}
						| typeName '+' '[' ']' operator_0						{$$ = $5; setOperatorResult($$, $1, $2); setOperatorResultArray($$);}
;

operator_2				: operator_1											{$$ = $1;}
						| CONST operator_1										{$$ = $2; setOperatorResultConst($$, $1);}
;

operator_3				: operator_2											{$$ = $1;}
						| ABSTRACT operator_2									{$$ = $2; setOperatorModifier($$, $1);}
						| VIRTUAL operator_2									{$$ = $2; setOperatorModifier($$, $1);}
;

operator				: operator_3											{$$ = $1;}
						| OVERRIDE operator_3									{$$ = $2; setOperatorOverride($$);}
;

delegate_0				: IDENTIFY '(' ')' ';'									{$$ = newDelegate($1, $2, NULL, $3, $4);}
						| IDENTIFY '(' VOID ')' ';'								{$$ = newDelegate($1, $2, NULL, $4, $5);}
						| IDENTIFY '(' parameterList ')' ';'					{$$ = newDelegate($1, $2, $3, $4, $5);}
;

delegate_1				: typeName delegate_0									{$$ = $2; setDelegateResult($$, $1, NULL);}
						| typeName '&' delegate_0								{$$ = $3; setDelegateResult($$, $1, $2);}
						| typeName '*' delegate_0								{$$ = $3; setDelegateResult($$, $1, $2);}
						| typeName '+' delegate_0								{$$ = $3; setDelegateResult($$, $1, $2);}
						| typeName '+' '[' ']' delegate_0						{$$ = $5; setDelegateResult($$, $1, $2); setDelegateResultArray($$);}
;

delegate				: DELEGATE delegate_1									{$$ = $2; setDelegateKeyword($$, $1)}
						| DELEGATE CONST delegate_1								{$$ = $3; setDelegateKeyword($$, $1); setDelegateResultConst($$, $2);}
;

classMember_0			: field													{$$ = $1;}
						| property												{$$ = $1;}
						| method												{$$ = $1;}
						| operator												{$$ = $1;}
						| class													{$$ = $1;}
						| delegate												{$$ = $1;}
						| enum													{$$ = $1;}
						| typeAlias												{$$ = $1;}
						| NOCODE classMember_0									{$$ = $2; setMemberFilter($$, $1);}
						| NOMETA classMember_0									{$$ = $2; setMemberFilter($$, $1);}
;
			
classMember				: classMember_0											{$$ = $1;}
						| attributes classMember_0								{$$ = $2; setAttributeList($$, $1);}
;

classMemberList			: classMember											{$$ = newClassMemberList(NULL, $1);}
						| ';'													{$$ = NULL;}
						| classMemberList classMember							{$$ = newClassMemberList($1, $2);}
						| classMemberList ';'									{$$ = $1;}
;

templateParameterList	: IDENTIFY												{$$ = newTemplateParameterList(NULL, NULL, $1);}
						| templateParameterList ',' IDENTIFY					{$$ = newTemplateParameterList($1, $2, $3);}
;

templateParameters		: TEMPLATE '<' templateParameterList '>'				{$$ = newTemplateParameters($1, $2, $3, $4);}
;

class_0					: CLASS IDENTIFY										{$$ = newClass($1, NULL, $2);}
						| CLASS '(' identifyList ')' IDENTIFY 					{$$ = newClass($1, $3, $5);}
						| STRUCT IDENTIFY										{$$ = newClass($1, NULL, $2);}
						| STRUCT '(' identifyList ')' IDENTIFY 					{$$ = newClass($1, $3, $5);}
;

class_1					: class_0												{$$ = $1;}
						| class_0 ':' typeNameList								{$$ = $1; setClassBaseList($$, $2, $3);}
;

class_2					: class_1 '{' '}'										{$$ = $1; setClassMemberList($$, $2, NULL, $3);}
						| class_1 '{' classMemberList '}'						{$$ = $1; setClassMemberList($$, $2, $3, $4);}
;

class_3					: class_2 ';'											{$$ = $1; setClassSemicolon($$, $2);}
						| class_2 '=' STRING ';'								{$$ = $1; setNativeName($$, $3); setClassSemicolon($$, $4);}
;

class_4					: class_3												{$$ = $1;}
						| ABSTRACT class_3										{$$ = $2; setClassModifier($$, $1);}
;

class_5					: class_4												{$$ = $1;}
						| OVERRIDE class_4										{$$ = $2; setClassOverride($$);}
;

class					: class_5												{$$ = $1;}
						| templateParameters class_5							{$$ = $2; setClassTemplateParameters($$, $1);}
;


tokenList				: IDENTIFY												{$$ = newTokenList(NULL, $1);}
						| operatorSign											{$$ = newTokenList(NULL, $1);}
						| tokenList ',' IDENTIFY								{$$ = newTokenList($1, $3);}
						| tokenList ',' operatorSign							{$$ = newTokenList($1, $3);}
;

templateClassInstance_0	: EXPORT IDENTIFY '<' typeNameList '>'					{$$ = newTemplateClassInstance($2, $4);}
;
						
templateClassInstance	: templateClassInstance_0 ';'							{$$ = $1;}
						| templateClassInstance_0 '{' '}' ';'					{$$ = $1;}
						| templateClassInstance_0 '{' tokenList '}' ';'			{$$ = $1; setTemplateClassInstanceTokenList($1, $3);}
						| templateClassInstance_0 '{' tokenList ',' '}' ';'		{$$ = $1; setTemplateClassInstanceTokenList($1, $3);}
;


namespaceMember_0		: class													{$$ = $1;}
						| delegate												{$$ = $1;}
						| enum													{$$ = $1;}
						| templateClassInstance									{$$ = $1;}
						| typeAlias												{$$ = $1;}
						| namespace												{$$ = $1;}
						| NOCODE namespaceMember_0								{$$ = $2; setMemberFilter($$, $1);}
						| NOMETA namespaceMember_0								{$$ = $2; setMemberFilter($$, $1);}
;

namespaceMember			: namespaceMember_0										{$$ = $1;}
						| attributes namespaceMember_0							{$$ = $2; setAttributeList($$, $1);}
;

namespaceMemberList		: namespaceMember										{$$ = newNamespaceMemberList(NULL, $1);}
						| ';'													{$$ = NULL;}
						| namespaceMemberList namespaceMember					{$$ = newNamespaceMemberList($1, $2);}
						| namespaceMemberList ';'								{$$ = $1;}
;

namespace				: NAMESPACE	IDENTIFY '{' '}'							{$$ = newNamespace($1, $2, $3, NULL, $4);}
						| NAMESPACE	IDENTIFY '{' namespaceMemberList '}'		{$$ = newNamespace($1, $2, $3, $4, $5);}
;

program					:														{$$ = newProgram(NULL); attachSyntaxTree($$);}
						| namespaceMemberList									{$$ = newProgram($1); attachSyntaxTree($$);}
;
