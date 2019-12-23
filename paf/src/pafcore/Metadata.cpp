#include "Metadata.h"
#include "Metadata.mh"
#include "Metadata.ic"
#include "Metadata.mc"
#include "Type.h"
#include <string.h>
#include <algorithm>

BEGIN_PAFCORE

class CompareAttributeByName
{
public:
	bool operator()(const Attribute& a1, const Attribute& a2)
	{
		return strcmp(a1.name, a2.name) < 0;
	}
};

Metadata::Metadata(const char* name, Attributes* attributes)
{
	m_name = name;
	m_attributes = attributes;
}

long_t Metadata::addRef()
{
	return 0x40000000;
};

long_t Metadata::release()
{
	return 0x40000000;
};

Category Metadata::get__category_() const
{
	Type* type = const_cast<Metadata*>(this)->getType();
	return type->m_category;
}

string_t Metadata::_getAttributeName_(size_t index)
{
	if (m_attributes && index < m_attributes->count)
	{
		return m_attributes->attributes[index].name;
	}
	return "";
}

string_t Metadata::_getAttributeContent_(size_t index)
{
	if (m_attributes && index < m_attributes->count)
	{
		return m_attributes->attributes[index].content;
	}
	return "";
}

string_t Metadata::_getAttributeContentByName_(string_t attributeName)
{
	if (0 != m_attributes)
	{
		Attribute* begin = &m_attributes->attributes[0];
		Attribute* end = begin + m_attributes->count;
		Attribute dummy;
		dummy.name = attributeName;
		Attribute* it = std::lower_bound(begin, end, dummy, CompareAttributeByName());
		if (end != it && strcmp(attributeName, it->name) == 0)
		{
			return it->content;
		}
	}
	return "";
}

bool Metadata::_hasAttribute_(string_t attributeName)
{
	if (0 != m_attributes)
	{
		Attribute* begin = &m_attributes->attributes[0];
		Attribute* end = begin + m_attributes->count;
		Attribute dummy;
		dummy.name = attributeName;
		Attribute* it = std::lower_bound(begin, end, dummy, CompareAttributeByName());
		if (end != it && strcmp(attributeName, it->name) == 0)
		{
			return true;
		}
	}
	return false;
}

bool Metadata::operator < (const Metadata& arg) const
{
	return strcmp(m_name, arg.m_name) < 0;
}

bool CompareMetaDataPtrByName::operator()(const Metadata* m1, const Metadata* m2)
{
	return strcmp(m1->m_name, m2->m_name) < 0;
}


const char* g_errorStrings[] =
{
	"s_ok",
	"e_invalid_namespace",
	"e_name_conflict",
	"e_void_variant",
	"e_is_not_type",
	"e_is_not_class",
	"e_invalid_subscript_type",
	"e_member_not_found",
	"e_index_out_of_range",
	"e_is_not_array_property",
	"e_is_not_dynamic_array_property",
	"e_is_not_list_property",
	"e_is_not_map_property",
	"e_property_is_not_readable",
	"e_property_is_not_writable",
	"e_property_is_not_iterable",
	"e_property_is_not_dereferenceable",
	"e_item_is_constant",
	"e_field_is_an_array",
	"e_field_is_constant",
	"e_invalid_type",
	"e_invalid_object_type",
	"e_invalid_field_type",
	"e_invalid_property_type",
	"e_invalid_arg_num",
	"e_no_match_overload",
	"e_ambiguous_overload",
	"e_invalid_this_type",
	"e_invalid_arg_type_1",
	"e_invalid_arg_type_2",
	"e_invalid_arg_type_3",
	"e_invalid_arg_type_4",
	"e_invalid_arg_type_5",
	"e_invalid_arg_type_6",
	"e_invalid_arg_type_7",
	"e_invalid_arg_type_8",
	"e_invalid_arg_type_9",
	"e_invalid_arg_type_10",
	"e_invalid_arg_type_11",
	"e_invalid_arg_type_12",
	"e_invalid_arg_type_13",
	"e_invalid_arg_type_14",
	"e_invalid_arg_type_15",
	"e_invalid_arg_type_16",
	"e_invalid_arg_type_17",
	"e_invalid_arg_type_18",
	"e_invalid_arg_type_19",
	"e_this_is_constant",
	"e_arg_is_constant_1",
	"e_arg_is_constant_2",
	"e_arg_is_constant_3",
	"e_arg_is_constant_4",
	"e_arg_is_constant_5",
	"e_arg_is_constant_6",
	"e_arg_is_constant_7",
	"e_arg_is_constant_8",
	"e_arg_is_constant_9",
	"e_arg_is_constant_10",
	"e_arg_is_constant_11",
	"e_arg_is_constant_12",
	"e_arg_is_constant_13",
	"e_arg_is_constant_14",
	"e_arg_is_constant_15",
	"e_arg_is_constant_16",
	"e_arg_is_constant_17",
	"e_arg_is_constant_18",
	"e_arg_is_constant_19",
	"e_not_implemented",
	"e_script_error",
	"e_script_dose_not_override",
};


const char* ErrorCodeToString(ErrorCode errorCode)
{
	if (errorCode < paf_array_size_of(g_errorStrings))
	{
		return g_errorStrings[errorCode];
	}
	return "unknown error";
}

END_PAFCORE
