#pragma once
//
//#ifdef __cplusplus
//extern "C"
//{
//#endif
//

enum ErrorCode
{
	no_error,
	import_error_file_not_existing,
	import_error_open_file_failed,

	syntax_error_internal,
	syntax_error_invalid_string,
	syntax_error_unterminated_code,
	syntax_error_unterminated_comment,
	
	semantic_error_namespace_redefined,
	semantic_error_type_redefined,
	semantic_error_template_redefined,
	semantic_error_enumerator_redefined,
	semantic_error_nested_template_class,
	semantic_error_missing_type_specifier,
	semantic_error_constructor_with_return_type,
	semantic_error_constructor_with_modifier,
	semantic_error_member_name_equal_to_class_name,
	semantic_error_member_redefined,
	semantic_error_primitive_type_as_base,
	semantic_error_base_type,
	semantic_error_base_redeclared,
	semantic_error_invalid_package_name,
	semantic_error_invalid_type_name,
	semantic_error_invalid_parameter,
	semantic_error_invalid_result,
	semantic_error_invalid_field,
	semantic_error_invalid_property,
	semantic_error_invalid_class_template_name,
	semantic_error_missing_template_argument_list,
	semantic_error_too_few_template_arguments,
	semantic_error_too_many_template_arguments,
	semantic_error_invalid_template_argument,
	semantic_error_ambiguous_type_name,
	semantic_error_ambiguous_template_name,
	semantic_error_template_parameter_redefinition,
	semantic_error_template_class_not_instantiton,
	semantic_error_template_interface_not_supported,
	semantic_error_missing_reference_base_type,
	semantic_error_template_class_instance_internal,
	semantic_error_too_few_formal_parameters,
	semantic_error_too_many_formal_parameters,
	semantic_error_operator_can_not_be_static,
	semantic_error_override_method_must_be_virtual_or_abstract,
	semantic_error_attribute_redefined,
};

typedef enum ErrorCode ErrorCode;

void ErrorList_AddItem(const char* fileName, int lineNo, int columnNo, ErrorCode errorCode, const char* errorText);
void ErrorList_AddItem_CurrentFile(ErrorCode errorCode, const char* errorText);
void ErrorList_AddItem_CurrentFile(int lineNo, int columnNo, ErrorCode errorCode, const char* errorText);
size_t ErrorList_ErrorCount();
void ErrorList_Output();
//
//#ifdef __cplusplus
//}
//#endif

#ifdef __cplusplus
#include <set>
#include <vector>
#include <string>


struct TemplateClassInstanceNode;
class ErrorList
{
public:
	struct ErrorInfo
	{
		const char* fileName;
		int lineNo;
		int columnNo;
		ErrorCode errorCode;
		std::string errorText;
	};
public:
	ErrorList();
	void addItem(const char* fileName, int lineNo, int columnNo, ErrorCode errorCode, const char* errorText);
	void setTemplateClassInstance(TemplateClassInstanceNode* templateClassInstanceNode);
private:
	void addItem_(const char* fileName, int lineNo, int columnNo, ErrorCode errorCode, const char* errorText);
public:
	std::set<std::string> m_fileNames;
	typedef std::vector<ErrorInfo> ErrorInfoContainer;
	ErrorInfoContainer m_errorInfos;
	TemplateClassInstanceNode* m_templateClassInstanceNode;
};

extern ErrorList g_errorList;

#endif
