//DO NOT EDIT THIS FILE, it is generated by idlcpp
//aifeng_peng@hotmail.com

#pragma once

#include "Typedef.mh"
#include "AutoRun.h"
#include "NameSpace.h"
#include "Result.h"
#include "Argument.h"
#include "InstanceField.h"
#include "StaticField.h"
#include "InstanceProperty.h"
#include "StaticProperty.h"
#include "InstanceMethod.h"
#include "StaticMethod.h"
#include "Enumerator.h"
#include "PrimitiveType.h"
#include "NullType.h"


namespace idlcpp
{

	__bool_t_Type::__bool_t_Type() : TypeAlias("bool_t", RuntimeTypeOf<::bool_t>::RuntimeType::GetSingleton())
	{
		::pafcore::NameSpace::GetGlobalNameSpace()->registerMember(this);
	}

	__bool_t_Type* __bool_t_Type::GetSingleton()
	{
		static __bool_t_Type s_instance;
		return &s_instance;
	}

	__char_t_Type::__char_t_Type() : TypeAlias("char_t", RuntimeTypeOf<::char_t>::RuntimeType::GetSingleton())
	{
		::pafcore::NameSpace::GetGlobalNameSpace()->registerMember(this);
	}

	__char_t_Type* __char_t_Type::GetSingleton()
	{
		static __char_t_Type s_instance;
		return &s_instance;
	}

	__schar_t_Type::__schar_t_Type() : TypeAlias("schar_t", RuntimeTypeOf<::schar_t>::RuntimeType::GetSingleton())
	{
		::pafcore::NameSpace::GetGlobalNameSpace()->registerMember(this);
	}

	__schar_t_Type* __schar_t_Type::GetSingleton()
	{
		static __schar_t_Type s_instance;
		return &s_instance;
	}

	__uchar_t_Type::__uchar_t_Type() : TypeAlias("uchar_t", RuntimeTypeOf<::uchar_t>::RuntimeType::GetSingleton())
	{
		::pafcore::NameSpace::GetGlobalNameSpace()->registerMember(this);
	}

	__uchar_t_Type* __uchar_t_Type::GetSingleton()
	{
		static __uchar_t_Type s_instance;
		return &s_instance;
	}

	__short_t_Type::__short_t_Type() : TypeAlias("short_t", RuntimeTypeOf<::short_t>::RuntimeType::GetSingleton())
	{
		::pafcore::NameSpace::GetGlobalNameSpace()->registerMember(this);
	}

	__short_t_Type* __short_t_Type::GetSingleton()
	{
		static __short_t_Type s_instance;
		return &s_instance;
	}

	__ushort_t_Type::__ushort_t_Type() : TypeAlias("ushort_t", RuntimeTypeOf<::ushort_t>::RuntimeType::GetSingleton())
	{
		::pafcore::NameSpace::GetGlobalNameSpace()->registerMember(this);
	}

	__ushort_t_Type* __ushort_t_Type::GetSingleton()
	{
		static __ushort_t_Type s_instance;
		return &s_instance;
	}

	__long_t_Type::__long_t_Type() : TypeAlias("long_t", RuntimeTypeOf<::long_t>::RuntimeType::GetSingleton())
	{
		::pafcore::NameSpace::GetGlobalNameSpace()->registerMember(this);
	}

	__long_t_Type* __long_t_Type::GetSingleton()
	{
		static __long_t_Type s_instance;
		return &s_instance;
	}

	__ulong_t_Type::__ulong_t_Type() : TypeAlias("ulong_t", RuntimeTypeOf<::ulong_t>::RuntimeType::GetSingleton())
	{
		::pafcore::NameSpace::GetGlobalNameSpace()->registerMember(this);
	}

	__ulong_t_Type* __ulong_t_Type::GetSingleton()
	{
		static __ulong_t_Type s_instance;
		return &s_instance;
	}

	__longlong_t_Type::__longlong_t_Type() : TypeAlias("longlong_t", RuntimeTypeOf<::longlong_t>::RuntimeType::GetSingleton())
	{
		::pafcore::NameSpace::GetGlobalNameSpace()->registerMember(this);
	}

	__longlong_t_Type* __longlong_t_Type::GetSingleton()
	{
		static __longlong_t_Type s_instance;
		return &s_instance;
	}

	__ulonglong_t_Type::__ulonglong_t_Type() : TypeAlias("ulonglong_t", RuntimeTypeOf<::ulonglong_t>::RuntimeType::GetSingleton())
	{
		::pafcore::NameSpace::GetGlobalNameSpace()->registerMember(this);
	}

	__ulonglong_t_Type* __ulonglong_t_Type::GetSingleton()
	{
		static __ulonglong_t_Type s_instance;
		return &s_instance;
	}

	__int_t_Type::__int_t_Type() : TypeAlias("int_t", RuntimeTypeOf<::int_t>::RuntimeType::GetSingleton())
	{
		::pafcore::NameSpace::GetGlobalNameSpace()->registerMember(this);
	}

	__int_t_Type* __int_t_Type::GetSingleton()
	{
		static __int_t_Type s_instance;
		return &s_instance;
	}

	__uint_t_Type::__uint_t_Type() : TypeAlias("uint_t", RuntimeTypeOf<::uint_t>::RuntimeType::GetSingleton())
	{
		::pafcore::NameSpace::GetGlobalNameSpace()->registerMember(this);
	}

	__uint_t_Type* __uint_t_Type::GetSingleton()
	{
		static __uint_t_Type s_instance;
		return &s_instance;
	}

	__float_t_Type::__float_t_Type() : TypeAlias("float_t", RuntimeTypeOf<::float_t>::RuntimeType::GetSingleton())
	{
		::pafcore::NameSpace::GetGlobalNameSpace()->registerMember(this);
	}

	__float_t_Type* __float_t_Type::GetSingleton()
	{
		static __float_t_Type s_instance;
		return &s_instance;
	}

	__double_t_Type::__double_t_Type() : TypeAlias("double_t", RuntimeTypeOf<::double_t>::RuntimeType::GetSingleton())
	{
		::pafcore::NameSpace::GetGlobalNameSpace()->registerMember(this);
	}

	__double_t_Type* __double_t_Type::GetSingleton()
	{
		static __double_t_Type s_instance;
		return &s_instance;
	}

	__byte_t_Type::__byte_t_Type() : TypeAlias("byte_t", RuntimeTypeOf<::byte_t>::RuntimeType::GetSingleton())
	{
		::pafcore::NameSpace::GetGlobalNameSpace()->registerMember(this);
	}

	__byte_t_Type* __byte_t_Type::GetSingleton()
	{
		static __byte_t_Type s_instance;
		return &s_instance;
	}

	__size_t_Type::__size_t_Type() : TypeAlias("size_t", RuntimeTypeOf<::size_t>::RuntimeType::GetSingleton())
	{
		::pafcore::NameSpace::GetGlobalNameSpace()->registerMember(this);
	}

	__size_t_Type* __size_t_Type::GetSingleton()
	{
		static __size_t_Type s_instance;
		return &s_instance;
	}

	__ptrdiff_t_Type::__ptrdiff_t_Type() : TypeAlias("ptrdiff_t", RuntimeTypeOf<::ptrdiff_t>::RuntimeType::GetSingleton())
	{
		::pafcore::NameSpace::GetGlobalNameSpace()->registerMember(this);
	}

	__ptrdiff_t_Type* __ptrdiff_t_Type::GetSingleton()
	{
		static __ptrdiff_t_Type s_instance;
		return &s_instance;
	}

}

AUTO_REGISTER_TYPE(::idlcpp::__bool_t_Type)
static_assert(RuntimeTypeOf<::bool_t>::type_category == ::pafcore::primitive_object, "type category error");
AUTO_REGISTER_TYPE(::idlcpp::__char_t_Type)
static_assert(RuntimeTypeOf<::char_t>::type_category == ::pafcore::primitive_object, "type category error");
AUTO_REGISTER_TYPE(::idlcpp::__schar_t_Type)
static_assert(RuntimeTypeOf<::schar_t>::type_category == ::pafcore::primitive_object, "type category error");
AUTO_REGISTER_TYPE(::idlcpp::__uchar_t_Type)
static_assert(RuntimeTypeOf<::uchar_t>::type_category == ::pafcore::primitive_object, "type category error");
AUTO_REGISTER_TYPE(::idlcpp::__short_t_Type)
static_assert(RuntimeTypeOf<::short_t>::type_category == ::pafcore::primitive_object, "type category error");
AUTO_REGISTER_TYPE(::idlcpp::__ushort_t_Type)
static_assert(RuntimeTypeOf<::ushort_t>::type_category == ::pafcore::primitive_object, "type category error");
AUTO_REGISTER_TYPE(::idlcpp::__long_t_Type)
static_assert(RuntimeTypeOf<::long_t>::type_category == ::pafcore::primitive_object, "type category error");
AUTO_REGISTER_TYPE(::idlcpp::__ulong_t_Type)
static_assert(RuntimeTypeOf<::ulong_t>::type_category == ::pafcore::primitive_object, "type category error");
AUTO_REGISTER_TYPE(::idlcpp::__longlong_t_Type)
static_assert(RuntimeTypeOf<::longlong_t>::type_category == ::pafcore::primitive_object, "type category error");
AUTO_REGISTER_TYPE(::idlcpp::__ulonglong_t_Type)
static_assert(RuntimeTypeOf<::ulonglong_t>::type_category == ::pafcore::primitive_object, "type category error");
AUTO_REGISTER_TYPE(::idlcpp::__int_t_Type)
static_assert(RuntimeTypeOf<::int_t>::type_category == ::pafcore::primitive_object, "type category error");
AUTO_REGISTER_TYPE(::idlcpp::__uint_t_Type)
static_assert(RuntimeTypeOf<::uint_t>::type_category == ::pafcore::primitive_object, "type category error");
AUTO_REGISTER_TYPE(::idlcpp::__float_t_Type)
static_assert(RuntimeTypeOf<::float_t>::type_category == ::pafcore::primitive_object, "type category error");
AUTO_REGISTER_TYPE(::idlcpp::__double_t_Type)
static_assert(RuntimeTypeOf<::double_t>::type_category == ::pafcore::primitive_object, "type category error");
AUTO_REGISTER_TYPE(::idlcpp::__byte_t_Type)
static_assert(RuntimeTypeOf<::byte_t>::type_category == ::pafcore::primitive_object, "type category error");
AUTO_REGISTER_TYPE(::idlcpp::__size_t_Type)
static_assert(RuntimeTypeOf<::size_t>::type_category == ::pafcore::primitive_object, "type category error");
AUTO_REGISTER_TYPE(::idlcpp::__ptrdiff_t_Type)
static_assert(RuntimeTypeOf<::ptrdiff_t>::type_category == ::pafcore::primitive_object, "type category error");
