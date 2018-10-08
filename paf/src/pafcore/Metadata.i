#import "Reference.i"

namespace pafcore
{
#{
	enum ErrorCode
	{
		s_ok,
		e_invalid_namespace,
		e_name_conflict,
		e_void_variant,
		e_is_not_array_property,
		e_is_not_type,
		e_is_not_class,
		e_invalid_subscript_type,
		e_member_not_found,
		e_index_out_of_range,
		e_property_is_not_readable,
		e_property_is_not_writable,
		e_array_property_is_not_dynamic,
		e_is_not_map_property,
		e_property_is_not_iterable,
		e_property_is_not_dereferenceable,
		e_item_is_constant,
		e_field_is_an_array,
		e_field_is_constant,
		e_invalid_type,
		e_invalid_object_type,
		e_invalid_field_type,
		e_invalid_property_type,
		e_invalid_arg_num,
		e_no_match_overload,
		e_ambiguous_overload,
		e_invalid_this_type,
		e_invalid_arg_type_1,
		e_invalid_arg_type_2,
		e_invalid_arg_type_3,
		e_invalid_arg_type_4,
		e_invalid_arg_type_5,
		e_invalid_arg_type_6,
		e_invalid_arg_type_7,
		e_invalid_arg_type_8,
		e_invalid_arg_type_9,
		e_invalid_arg_type_10,
		e_invalid_arg_type_11,
		e_invalid_arg_type_12,
		e_invalid_arg_type_13,
		e_invalid_arg_type_14,
		e_invalid_arg_type_15,
		e_invalid_arg_type_16,
		e_invalid_arg_type_17,
		e_invalid_arg_type_18,
		e_invalid_arg_type_19,
		e_invalid_arg_type_20,
		e_this_is_constant,
		e_arg_is_constant_1,
		e_arg_is_constant_2,
		e_arg_is_constant_3,
		e_arg_is_constant_4,
		e_arg_is_constant_5,
		e_arg_is_constant_6,
		e_arg_is_constant_7,
		e_arg_is_constant_8,
		e_arg_is_constant_9,
		e_arg_is_constant_10,
		e_arg_is_constant_11,
		e_arg_is_constant_12,
		e_arg_is_constant_13,
		e_arg_is_constant_14,
		e_arg_is_constant_15,
		e_arg_is_constant_16,
		e_arg_is_constant_17,
		e_arg_is_constant_18,
		e_arg_is_constant_19,
		e_arg_is_constant_20,
		e_not_implemented,
		e_script_error,
		e_script_dose_not_override,
	};

	extern const char* g_errorStrings[];

	PAFCORE_EXPORT const char* ErrorCodeToString(ErrorCode errorCode);

	struct Attribute
	{
		const char* name;
		const char* content;
	};
	struct Attributes
	{
		size_t count;
		Attribute* attributes;
	};
#}
	enum Category
	{
		void_object,
		primitive_object,
		enum_object,
		value_object,
		reference_object,
##		atomic_reference_object = reference_object,
		enumerator,
		instance_field,
		static_field,
		instance_property,
		static_property,
		instance_method,
		static_method,
		function_argument,
		function_result,
		void_type,
		primitive_type,
		enum_type,
		class_type,
		type_alias,
		name_space,
	};

	abstract class #PAFCORE_EXPORT Metadata : Reference
	{
		string_t _name_ get;
		Category _category_ get;
		size_t _attributeCount_ get;
		string_t _getAttributeName_(size_t index);
		string_t _getAttributeContent_(size_t index);
		string_t _getAttributeContentByName_(string_t attributeName);
#{
	public:
		enum Passing
		{
			by_value,
			by_ref,
			by_ptr,
			by_out_ptr,
			by_out_ref,
			by_new,
			by_new_array,
			by_new_ptr,
			by_new_ref,
			by_new_array_ptr,
			by_new_array_ref,
		};
		enum TypeCompound
		{
			tc_none,
			tc_pointer,
			tc_array,
		};
		enum PropertyCategory
		{
			simple_property,
			array_property,
			map_property,
		};
	public:
		Metadata(const char* name, Attributes* attributes = 0);
		//Metadata(const Metadata&) = default;
		//Metadata& operator=(const Metadata&) = default;
	public:
		bool operator < (const Metadata& arg) const;
	public:
		virtual long_t addRef();
		virtual long_t release();
	public:
		const char* m_name;
		Attributes* m_attributes;
#}
	};

#{

	inline size_t Metadata::get__attributeCount_() const
	{
		return m_attributes ? m_attributes->count : 0;
	}

	inline string_t Metadata::get__name_() const
	{
		return m_name;
	}

	class CompareMetaDataPtrByName
	{
	public:
		bool operator()(const Metadata* m1, const Metadata* m2);
	};

#}

}