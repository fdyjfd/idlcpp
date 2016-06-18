#include "Utility.h"
#include <string.h>
#include <malloc.h>

BEGIN_PAFCORE

const char* g_errorStrings[] = 
{
	"s_ok",
	"e_invalid_namespace",
	"e_name_conflict",
	"e_void_variant",
	"e_is_not_array",
	"e_is_not_type",
	"e_is_not_class",
	"e_invalid_subscript_type",
	"e_member_not_found",
	"e_index_out_of_range",
	"e_property_is_read_only",
	"e_property_is_write_only",
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
	if(errorCode < paf_array_size_of(g_errorStrings))
	{
		return g_errorStrings[errorCode];
	}
	return "unknown error";
}

size_t stringBinarySearch(const char** strs, size_t stride, size_t count, const char* value)
{
	size_t left = 0;
	size_t right = count;
	while (left < right)
	{
		size_t mid = (left + right) / 2;
		int_t cmp = strcmp(value, *reinterpret_cast<const char**>(reinterpret_cast<size_t>(strs)+stride*mid));
		if (0 == cmp)
		{
			return mid;
		}
		if (cmp < 0)
		{
			right = mid;
		}
		else
		{
			left = mid + 1;
		}
	}
	return count;
}

void* allocateMemory(size_t n)
{
	return malloc(n);
}

void freeMemory(void* p)
{
	free(p);
}

END_PAFCORE