//DO NOT EDIT THIS FILE, it is generated by idlcpp
//http://www.idlcpp.org

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
#include "VoidType.h"
#include "RefCountImpl.h"
#include "Iterator.h"
#include <new>


namespace idlcpp
{

	__bool_t_Type::__bool_t_Type() : TypeAlias("bool_t", RuntimeTypeOf<::bool_t>::RuntimeType::GetSingleton(), "D:/DeepEye2018/deepeye/src/paf/pafcore/Typedef.i")
	{
		::pafcore::NameSpace::GetGlobalNameSpace()->registerMember(this);
	}

	__bool_t_Type* __bool_t_Type::GetSingleton()
	{
		static __bool_t_Type* s_instance = 0;
		static char s_buffer[sizeof(__bool_t_Type)];
		if(0 == s_instance)
		{
			s_instance = (__bool_t_Type*)s_buffer;
			new (s_buffer)__bool_t_Type;
		}
		return s_instance;
	}

	__char_t_Type::__char_t_Type() : TypeAlias("char_t", RuntimeTypeOf<::char_t>::RuntimeType::GetSingleton(), "D:/DeepEye2018/deepeye/src/paf/pafcore/Typedef.i")
	{
		::pafcore::NameSpace::GetGlobalNameSpace()->registerMember(this);
	}

	__char_t_Type* __char_t_Type::GetSingleton()
	{
		static __char_t_Type* s_instance = 0;
		static char s_buffer[sizeof(__char_t_Type)];
		if(0 == s_instance)
		{
			s_instance = (__char_t_Type*)s_buffer;
			new (s_buffer)__char_t_Type;
		}
		return s_instance;
	}

	__schar_t_Type::__schar_t_Type() : TypeAlias("schar_t", RuntimeTypeOf<::schar_t>::RuntimeType::GetSingleton(), "D:/DeepEye2018/deepeye/src/paf/pafcore/Typedef.i")
	{
		::pafcore::NameSpace::GetGlobalNameSpace()->registerMember(this);
	}

	__schar_t_Type* __schar_t_Type::GetSingleton()
	{
		static __schar_t_Type* s_instance = 0;
		static char s_buffer[sizeof(__schar_t_Type)];
		if(0 == s_instance)
		{
			s_instance = (__schar_t_Type*)s_buffer;
			new (s_buffer)__schar_t_Type;
		}
		return s_instance;
	}

	__uchar_t_Type::__uchar_t_Type() : TypeAlias("uchar_t", RuntimeTypeOf<::uchar_t>::RuntimeType::GetSingleton(), "D:/DeepEye2018/deepeye/src/paf/pafcore/Typedef.i")
	{
		::pafcore::NameSpace::GetGlobalNameSpace()->registerMember(this);
	}

	__uchar_t_Type* __uchar_t_Type::GetSingleton()
	{
		static __uchar_t_Type* s_instance = 0;
		static char s_buffer[sizeof(__uchar_t_Type)];
		if(0 == s_instance)
		{
			s_instance = (__uchar_t_Type*)s_buffer;
			new (s_buffer)__uchar_t_Type;
		}
		return s_instance;
	}

	__short_t_Type::__short_t_Type() : TypeAlias("short_t", RuntimeTypeOf<::short_t>::RuntimeType::GetSingleton(), "D:/DeepEye2018/deepeye/src/paf/pafcore/Typedef.i")
	{
		::pafcore::NameSpace::GetGlobalNameSpace()->registerMember(this);
	}

	__short_t_Type* __short_t_Type::GetSingleton()
	{
		static __short_t_Type* s_instance = 0;
		static char s_buffer[sizeof(__short_t_Type)];
		if(0 == s_instance)
		{
			s_instance = (__short_t_Type*)s_buffer;
			new (s_buffer)__short_t_Type;
		}
		return s_instance;
	}

	__ushort_t_Type::__ushort_t_Type() : TypeAlias("ushort_t", RuntimeTypeOf<::ushort_t>::RuntimeType::GetSingleton(), "D:/DeepEye2018/deepeye/src/paf/pafcore/Typedef.i")
	{
		::pafcore::NameSpace::GetGlobalNameSpace()->registerMember(this);
	}

	__ushort_t_Type* __ushort_t_Type::GetSingleton()
	{
		static __ushort_t_Type* s_instance = 0;
		static char s_buffer[sizeof(__ushort_t_Type)];
		if(0 == s_instance)
		{
			s_instance = (__ushort_t_Type*)s_buffer;
			new (s_buffer)__ushort_t_Type;
		}
		return s_instance;
	}

	__long_t_Type::__long_t_Type() : TypeAlias("long_t", RuntimeTypeOf<::long_t>::RuntimeType::GetSingleton(), "D:/DeepEye2018/deepeye/src/paf/pafcore/Typedef.i")
	{
		::pafcore::NameSpace::GetGlobalNameSpace()->registerMember(this);
	}

	__long_t_Type* __long_t_Type::GetSingleton()
	{
		static __long_t_Type* s_instance = 0;
		static char s_buffer[sizeof(__long_t_Type)];
		if(0 == s_instance)
		{
			s_instance = (__long_t_Type*)s_buffer;
			new (s_buffer)__long_t_Type;
		}
		return s_instance;
	}

	__ulong_t_Type::__ulong_t_Type() : TypeAlias("ulong_t", RuntimeTypeOf<::ulong_t>::RuntimeType::GetSingleton(), "D:/DeepEye2018/deepeye/src/paf/pafcore/Typedef.i")
	{
		::pafcore::NameSpace::GetGlobalNameSpace()->registerMember(this);
	}

	__ulong_t_Type* __ulong_t_Type::GetSingleton()
	{
		static __ulong_t_Type* s_instance = 0;
		static char s_buffer[sizeof(__ulong_t_Type)];
		if(0 == s_instance)
		{
			s_instance = (__ulong_t_Type*)s_buffer;
			new (s_buffer)__ulong_t_Type;
		}
		return s_instance;
	}

	__longlong_t_Type::__longlong_t_Type() : TypeAlias("longlong_t", RuntimeTypeOf<::longlong_t>::RuntimeType::GetSingleton(), "D:/DeepEye2018/deepeye/src/paf/pafcore/Typedef.i")
	{
		::pafcore::NameSpace::GetGlobalNameSpace()->registerMember(this);
	}

	__longlong_t_Type* __longlong_t_Type::GetSingleton()
	{
		static __longlong_t_Type* s_instance = 0;
		static char s_buffer[sizeof(__longlong_t_Type)];
		if(0 == s_instance)
		{
			s_instance = (__longlong_t_Type*)s_buffer;
			new (s_buffer)__longlong_t_Type;
		}
		return s_instance;
	}

	__ulonglong_t_Type::__ulonglong_t_Type() : TypeAlias("ulonglong_t", RuntimeTypeOf<::ulonglong_t>::RuntimeType::GetSingleton(), "D:/DeepEye2018/deepeye/src/paf/pafcore/Typedef.i")
	{
		::pafcore::NameSpace::GetGlobalNameSpace()->registerMember(this);
	}

	__ulonglong_t_Type* __ulonglong_t_Type::GetSingleton()
	{
		static __ulonglong_t_Type* s_instance = 0;
		static char s_buffer[sizeof(__ulonglong_t_Type)];
		if(0 == s_instance)
		{
			s_instance = (__ulonglong_t_Type*)s_buffer;
			new (s_buffer)__ulonglong_t_Type;
		}
		return s_instance;
	}

	__int_t_Type::__int_t_Type() : TypeAlias("int_t", RuntimeTypeOf<::int_t>::RuntimeType::GetSingleton(), "D:/DeepEye2018/deepeye/src/paf/pafcore/Typedef.i")
	{
		::pafcore::NameSpace::GetGlobalNameSpace()->registerMember(this);
	}

	__int_t_Type* __int_t_Type::GetSingleton()
	{
		static __int_t_Type* s_instance = 0;
		static char s_buffer[sizeof(__int_t_Type)];
		if(0 == s_instance)
		{
			s_instance = (__int_t_Type*)s_buffer;
			new (s_buffer)__int_t_Type;
		}
		return s_instance;
	}

	__uint_t_Type::__uint_t_Type() : TypeAlias("uint_t", RuntimeTypeOf<::uint_t>::RuntimeType::GetSingleton(), "D:/DeepEye2018/deepeye/src/paf/pafcore/Typedef.i")
	{
		::pafcore::NameSpace::GetGlobalNameSpace()->registerMember(this);
	}

	__uint_t_Type* __uint_t_Type::GetSingleton()
	{
		static __uint_t_Type* s_instance = 0;
		static char s_buffer[sizeof(__uint_t_Type)];
		if(0 == s_instance)
		{
			s_instance = (__uint_t_Type*)s_buffer;
			new (s_buffer)__uint_t_Type;
		}
		return s_instance;
	}

	__float_t_Type::__float_t_Type() : TypeAlias("float_t", RuntimeTypeOf<::float_t>::RuntimeType::GetSingleton(), "D:/DeepEye2018/deepeye/src/paf/pafcore/Typedef.i")
	{
		::pafcore::NameSpace::GetGlobalNameSpace()->registerMember(this);
	}

	__float_t_Type* __float_t_Type::GetSingleton()
	{
		static __float_t_Type* s_instance = 0;
		static char s_buffer[sizeof(__float_t_Type)];
		if(0 == s_instance)
		{
			s_instance = (__float_t_Type*)s_buffer;
			new (s_buffer)__float_t_Type;
		}
		return s_instance;
	}

	__double_t_Type::__double_t_Type() : TypeAlias("double_t", RuntimeTypeOf<::double_t>::RuntimeType::GetSingleton(), "D:/DeepEye2018/deepeye/src/paf/pafcore/Typedef.i")
	{
		::pafcore::NameSpace::GetGlobalNameSpace()->registerMember(this);
	}

	__double_t_Type* __double_t_Type::GetSingleton()
	{
		static __double_t_Type* s_instance = 0;
		static char s_buffer[sizeof(__double_t_Type)];
		if(0 == s_instance)
		{
			s_instance = (__double_t_Type*)s_buffer;
			new (s_buffer)__double_t_Type;
		}
		return s_instance;
	}

	__longdouble_t_Type::__longdouble_t_Type() : TypeAlias("longdouble_t", RuntimeTypeOf<::longdouble_t>::RuntimeType::GetSingleton(), "D:/DeepEye2018/deepeye/src/paf/pafcore/Typedef.i")
	{
		::pafcore::NameSpace::GetGlobalNameSpace()->registerMember(this);
	}

	__longdouble_t_Type* __longdouble_t_Type::GetSingleton()
	{
		static __longdouble_t_Type* s_instance = 0;
		static char s_buffer[sizeof(__longdouble_t_Type)];
		if(0 == s_instance)
		{
			s_instance = (__longdouble_t_Type*)s_buffer;
			new (s_buffer)__longdouble_t_Type;
		}
		return s_instance;
	}

	__byte_t_Type::__byte_t_Type() : TypeAlias("byte_t", RuntimeTypeOf<::byte_t>::RuntimeType::GetSingleton(), "D:/DeepEye2018/deepeye/src/paf/pafcore/Typedef.i")
	{
		::pafcore::NameSpace::GetGlobalNameSpace()->registerMember(this);
	}

	__byte_t_Type* __byte_t_Type::GetSingleton()
	{
		static __byte_t_Type* s_instance = 0;
		static char s_buffer[sizeof(__byte_t_Type)];
		if(0 == s_instance)
		{
			s_instance = (__byte_t_Type*)s_buffer;
			new (s_buffer)__byte_t_Type;
		}
		return s_instance;
	}

	__int8_t_Type::__int8_t_Type() : TypeAlias("int8_t", RuntimeTypeOf<::int8_t>::RuntimeType::GetSingleton(), "D:/DeepEye2018/deepeye/src/paf/pafcore/Typedef.i")
	{
		::pafcore::NameSpace::GetGlobalNameSpace()->registerMember(this);
	}

	__int8_t_Type* __int8_t_Type::GetSingleton()
	{
		static __int8_t_Type* s_instance = 0;
		static char s_buffer[sizeof(__int8_t_Type)];
		if(0 == s_instance)
		{
			s_instance = (__int8_t_Type*)s_buffer;
			new (s_buffer)__int8_t_Type;
		}
		return s_instance;
	}

	__uint8_t_Type::__uint8_t_Type() : TypeAlias("uint8_t", RuntimeTypeOf<::uint8_t>::RuntimeType::GetSingleton(), "D:/DeepEye2018/deepeye/src/paf/pafcore/Typedef.i")
	{
		::pafcore::NameSpace::GetGlobalNameSpace()->registerMember(this);
	}

	__uint8_t_Type* __uint8_t_Type::GetSingleton()
	{
		static __uint8_t_Type* s_instance = 0;
		static char s_buffer[sizeof(__uint8_t_Type)];
		if(0 == s_instance)
		{
			s_instance = (__uint8_t_Type*)s_buffer;
			new (s_buffer)__uint8_t_Type;
		}
		return s_instance;
	}

	__int16_t_Type::__int16_t_Type() : TypeAlias("int16_t", RuntimeTypeOf<::int16_t>::RuntimeType::GetSingleton(), "D:/DeepEye2018/deepeye/src/paf/pafcore/Typedef.i")
	{
		::pafcore::NameSpace::GetGlobalNameSpace()->registerMember(this);
	}

	__int16_t_Type* __int16_t_Type::GetSingleton()
	{
		static __int16_t_Type* s_instance = 0;
		static char s_buffer[sizeof(__int16_t_Type)];
		if(0 == s_instance)
		{
			s_instance = (__int16_t_Type*)s_buffer;
			new (s_buffer)__int16_t_Type;
		}
		return s_instance;
	}

	__uint16_t_Type::__uint16_t_Type() : TypeAlias("uint16_t", RuntimeTypeOf<::uint16_t>::RuntimeType::GetSingleton(), "D:/DeepEye2018/deepeye/src/paf/pafcore/Typedef.i")
	{
		::pafcore::NameSpace::GetGlobalNameSpace()->registerMember(this);
	}

	__uint16_t_Type* __uint16_t_Type::GetSingleton()
	{
		static __uint16_t_Type* s_instance = 0;
		static char s_buffer[sizeof(__uint16_t_Type)];
		if(0 == s_instance)
		{
			s_instance = (__uint16_t_Type*)s_buffer;
			new (s_buffer)__uint16_t_Type;
		}
		return s_instance;
	}

	__int32_t_Type::__int32_t_Type() : TypeAlias("int32_t", RuntimeTypeOf<::int32_t>::RuntimeType::GetSingleton(), "D:/DeepEye2018/deepeye/src/paf/pafcore/Typedef.i")
	{
		::pafcore::NameSpace::GetGlobalNameSpace()->registerMember(this);
	}

	__int32_t_Type* __int32_t_Type::GetSingleton()
	{
		static __int32_t_Type* s_instance = 0;
		static char s_buffer[sizeof(__int32_t_Type)];
		if(0 == s_instance)
		{
			s_instance = (__int32_t_Type*)s_buffer;
			new (s_buffer)__int32_t_Type;
		}
		return s_instance;
	}

	__uint32_t_Type::__uint32_t_Type() : TypeAlias("uint32_t", RuntimeTypeOf<::uint32_t>::RuntimeType::GetSingleton(), "D:/DeepEye2018/deepeye/src/paf/pafcore/Typedef.i")
	{
		::pafcore::NameSpace::GetGlobalNameSpace()->registerMember(this);
	}

	__uint32_t_Type* __uint32_t_Type::GetSingleton()
	{
		static __uint32_t_Type* s_instance = 0;
		static char s_buffer[sizeof(__uint32_t_Type)];
		if(0 == s_instance)
		{
			s_instance = (__uint32_t_Type*)s_buffer;
			new (s_buffer)__uint32_t_Type;
		}
		return s_instance;
	}

	__int64_t_Type::__int64_t_Type() : TypeAlias("int64_t", RuntimeTypeOf<::int64_t>::RuntimeType::GetSingleton(), "D:/DeepEye2018/deepeye/src/paf/pafcore/Typedef.i")
	{
		::pafcore::NameSpace::GetGlobalNameSpace()->registerMember(this);
	}

	__int64_t_Type* __int64_t_Type::GetSingleton()
	{
		static __int64_t_Type* s_instance = 0;
		static char s_buffer[sizeof(__int64_t_Type)];
		if(0 == s_instance)
		{
			s_instance = (__int64_t_Type*)s_buffer;
			new (s_buffer)__int64_t_Type;
		}
		return s_instance;
	}

	__uint64_t_Type::__uint64_t_Type() : TypeAlias("uint64_t", RuntimeTypeOf<::uint64_t>::RuntimeType::GetSingleton(), "D:/DeepEye2018/deepeye/src/paf/pafcore/Typedef.i")
	{
		::pafcore::NameSpace::GetGlobalNameSpace()->registerMember(this);
	}

	__uint64_t_Type* __uint64_t_Type::GetSingleton()
	{
		static __uint64_t_Type* s_instance = 0;
		static char s_buffer[sizeof(__uint64_t_Type)];
		if(0 == s_instance)
		{
			s_instance = (__uint64_t_Type*)s_buffer;
			new (s_buffer)__uint64_t_Type;
		}
		return s_instance;
	}

	__size_t_Type::__size_t_Type() : TypeAlias("size_t", RuntimeTypeOf<::size_t>::RuntimeType::GetSingleton(), "D:/DeepEye2018/deepeye/src/paf/pafcore/Typedef.i")
	{
		::pafcore::NameSpace::GetGlobalNameSpace()->registerMember(this);
	}

	__size_t_Type* __size_t_Type::GetSingleton()
	{
		static __size_t_Type* s_instance = 0;
		static char s_buffer[sizeof(__size_t_Type)];
		if(0 == s_instance)
		{
			s_instance = (__size_t_Type*)s_buffer;
			new (s_buffer)__size_t_Type;
		}
		return s_instance;
	}

	__ptrdiff_t_Type::__ptrdiff_t_Type() : TypeAlias("ptrdiff_t", RuntimeTypeOf<::ptrdiff_t>::RuntimeType::GetSingleton(), "D:/DeepEye2018/deepeye/src/paf/pafcore/Typedef.i")
	{
		::pafcore::NameSpace::GetGlobalNameSpace()->registerMember(this);
	}

	__ptrdiff_t_Type* __ptrdiff_t_Type::GetSingleton()
	{
		static __ptrdiff_t_Type* s_instance = 0;
		static char s_buffer[sizeof(__ptrdiff_t_Type)];
		if(0 == s_instance)
		{
			s_instance = (__ptrdiff_t_Type*)s_buffer;
			new (s_buffer)__ptrdiff_t_Type;
		}
		return s_instance;
	}

	__Nil_Type::__Nil_Type() : ::pafcore::ClassType("Nil", ::pafcore::value_object, "D:/DeepEye2018/deepeye/src/paf/pafcore/Typedef.i")
	{
		m_size = sizeof(::Nil);
		::pafcore::NameSpace::GetGlobalNameSpace()->registerMember(this);
	}

	void __Nil_Type::destroyInstance(void* address)
	{
		delete reinterpret_cast<::Nil*>(address);
	}

	void __Nil_Type::destroyArray(void* address)
	{
		paf_delete_array(reinterpret_cast<::Nil*>(address));
	}

	bool __Nil_Type::assign(void* dst, const void* src)
	{
		*(::Nil*)dst = *(const ::Nil*)src;
		return true;
	}

	__Nil_Type* __Nil_Type::GetSingleton()
	{
		static __Nil_Type* s_instance = 0;
		static char s_buffer[sizeof(__Nil_Type)];
		if(0 == s_instance)
		{
			s_instance = (__Nil_Type*)s_buffer;
			new (s_buffer)__Nil_Type;
		}
		return s_instance;
	}

	__pafcore__Buffer_Type::__pafcore__Buffer_Type() : ::pafcore::ClassType("Buffer", ::pafcore::value_object, "D:/DeepEye2018/deepeye/src/paf/pafcore/Typedef.i")
	{
		m_size = sizeof(::pafcore::Buffer);
		::pafcore::NameSpace::GetGlobalNameSpace()->getNameSpace("pafcore")->registerMember(this);
	}

	void __pafcore__Buffer_Type::destroyInstance(void* address)
	{
		delete reinterpret_cast<::pafcore::Buffer*>(address);
	}

	void __pafcore__Buffer_Type::destroyArray(void* address)
	{
		paf_delete_array(reinterpret_cast<::pafcore::Buffer*>(address));
	}

	bool __pafcore__Buffer_Type::assign(void* dst, const void* src)
	{
		*(::pafcore::Buffer*)dst = *(const ::pafcore::Buffer*)src;
		return true;
	}

	__pafcore__Buffer_Type* __pafcore__Buffer_Type::GetSingleton()
	{
		static __pafcore__Buffer_Type* s_instance = 0;
		static char s_buffer[sizeof(__pafcore__Buffer_Type)];
		if(0 == s_instance)
		{
			s_instance = (__pafcore__Buffer_Type*)s_buffer;
			new (s_buffer)__pafcore__Buffer_Type;
		}
		return s_instance;
	}

	__pafcore__MethodAsProperty_Type::__pafcore__MethodAsProperty_Type() : ::pafcore::ClassType("MethodAsProperty", ::pafcore::value_object, "D:/DeepEye2018/deepeye/src/paf/pafcore/Typedef.i")
	{
		m_size = sizeof(::pafcore::MethodAsProperty);
		::pafcore::NameSpace::GetGlobalNameSpace()->getNameSpace("pafcore")->registerMember(this);
	}

	void __pafcore__MethodAsProperty_Type::destroyInstance(void* address)
	{
		delete reinterpret_cast<::pafcore::MethodAsProperty*>(address);
	}

	void __pafcore__MethodAsProperty_Type::destroyArray(void* address)
	{
		paf_delete_array(reinterpret_cast<::pafcore::MethodAsProperty*>(address));
	}

	bool __pafcore__MethodAsProperty_Type::assign(void* dst, const void* src)
	{
		*(::pafcore::MethodAsProperty*)dst = *(const ::pafcore::MethodAsProperty*)src;
		return true;
	}

	__pafcore__MethodAsProperty_Type* __pafcore__MethodAsProperty_Type::GetSingleton()
	{
		static __pafcore__MethodAsProperty_Type* s_instance = 0;
		static char s_buffer[sizeof(__pafcore__MethodAsProperty_Type)];
		if(0 == s_instance)
		{
			s_instance = (__pafcore__MethodAsProperty_Type*)s_buffer;
			new (s_buffer)__pafcore__MethodAsProperty_Type;
		}
		return s_instance;
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
AUTO_REGISTER_TYPE(::idlcpp::__longdouble_t_Type)
static_assert(RuntimeTypeOf<::longdouble_t>::type_category == ::pafcore::primitive_object, "type category error");
AUTO_REGISTER_TYPE(::idlcpp::__byte_t_Type)
static_assert(RuntimeTypeOf<::byte_t>::type_category == ::pafcore::primitive_object, "type category error");
AUTO_REGISTER_TYPE(::idlcpp::__int8_t_Type)
static_assert(RuntimeTypeOf<::int8_t>::type_category == ::pafcore::primitive_object, "type category error");
AUTO_REGISTER_TYPE(::idlcpp::__uint8_t_Type)
static_assert(RuntimeTypeOf<::uint8_t>::type_category == ::pafcore::primitive_object, "type category error");
AUTO_REGISTER_TYPE(::idlcpp::__int16_t_Type)
static_assert(RuntimeTypeOf<::int16_t>::type_category == ::pafcore::primitive_object, "type category error");
AUTO_REGISTER_TYPE(::idlcpp::__uint16_t_Type)
static_assert(RuntimeTypeOf<::uint16_t>::type_category == ::pafcore::primitive_object, "type category error");
AUTO_REGISTER_TYPE(::idlcpp::__int32_t_Type)
static_assert(RuntimeTypeOf<::int32_t>::type_category == ::pafcore::primitive_object, "type category error");
AUTO_REGISTER_TYPE(::idlcpp::__uint32_t_Type)
static_assert(RuntimeTypeOf<::uint32_t>::type_category == ::pafcore::primitive_object, "type category error");
AUTO_REGISTER_TYPE(::idlcpp::__int64_t_Type)
static_assert(RuntimeTypeOf<::int64_t>::type_category == ::pafcore::primitive_object, "type category error");
AUTO_REGISTER_TYPE(::idlcpp::__uint64_t_Type)
static_assert(RuntimeTypeOf<::uint64_t>::type_category == ::pafcore::primitive_object, "type category error");
AUTO_REGISTER_TYPE(::idlcpp::__size_t_Type)
static_assert(RuntimeTypeOf<::size_t>::type_category == ::pafcore::primitive_object, "type category error");
AUTO_REGISTER_TYPE(::idlcpp::__ptrdiff_t_Type)
static_assert(RuntimeTypeOf<::ptrdiff_t>::type_category == ::pafcore::primitive_object, "type category error");
AUTO_REGISTER_TYPE(::idlcpp::__Nil_Type)
AUTO_REGISTER_TYPE(::idlcpp::__pafcore__Buffer_Type)
AUTO_REGISTER_TYPE(::idlcpp::__pafcore__MethodAsProperty_Type)
