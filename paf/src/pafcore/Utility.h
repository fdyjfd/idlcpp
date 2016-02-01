#pragma once

#include "Typedef.h"

#if defined PAFCORE_EXPORTS
	#define PAFCORE_EXPORT __declspec(dllexport)
#else
	#define PAFCORE_EXPORT __declspec(dllimport)
#endif

#define BEGIN_PAFCORE namespace pafcore {
#define END_PAFCORE }

#define array_size_of(a)	(sizeof(a)/sizeof(a[0]))
#define field_size_of(s, m)	sizeof(((s*)0)->m)
#define field_array_size_of(s, m)	(sizeof(((s*)0)->m)/sizeof(((s*)0)->m[0]))
#define base_offset_of(d, b) reinterpret_cast<ptrdiff_t>(static_cast<d*>(reinterpret_cast<b*>(0)))

#define AUTO_NEW_ARRAY_SIZE

#ifdef AUTO_NEW_ARRAY_SIZE

inline size_t new_array_size_of(void* p)
{
	return *((size_t*)p - 1);
}

template<typename T>
inline T* new_array(size_t count)
{
	size_t* p = (size_t*)malloc(sizeof(T)*count + sizeof(size_t));
	if(0 != p)
	{
		*p = count;
		++p;
		new(p)T[count];
	}
	return (T*)p;
}

template<typename T>
inline void delete_array(T* p)
{
	if(0 != p)
	{
		size_t* addr = (size_t*)p - 1;
		size_t count = *addr;
		for(size_t i = 0; i < count; ++i)
		{
			p->~T();
			++p;
		}
		free(addr);
	}
}
#else

inline size_t new_array_size_of(void* p)
{
	return 1;
}

template<typename T>
inline T* new_array(size_t count)
{
	return new T[count];
}

template<typename T>
inline void delete_array(T* p)
{
	delete []p;
}

#endif

BEGIN_PAFCORE

enum ErrorCode
{
	s_ok,
	e_invalid_namespace,
	e_name_conflict,
	e_null_variant,
	e_is_not_array,
	e_is_not_type,
	e_is_not_class,
	e_invalid_subscript_type,
	e_member_not_found,
	e_index_out_of_range,
	e_property_is_read_only,
	e_property_is_write_only,
	e_item_is_constant,
	e_field_is_an_array,
	e_field_is_constant,
	e_invalid_type,
	e_invalid_object_type,
	e_invalid_field_type,
	e_invalid_property_type,
	e_invalid_arg_num,
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
	e_not_implemented,
	e_script_error,
};

extern const char* g_errorStrings[];

PAFCORE_EXPORT const char* ErrorCodeToString(ErrorCode errorCode);


END_PAFCORE
