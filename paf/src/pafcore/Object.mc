//DO NOT EDIT THIS FILE, it is generated by idlcpp
//http://www.idlcpp.org

#pragma once

#include "./Reference.mh"
#include "Object.mh"
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

	__pafcore__Object_Type::__pafcore__Object_Type() : ::pafcore::ClassType("Object", ::pafcore::reference_object, "D:/DeepEye2018/deepeye/src/paf/pafcore/Object.i")
	{
		m_size = sizeof(::pafcore::Object);
		static BaseClass s_baseClasses[] =
		{
			{RuntimeTypeOf<::pafcore::Reference>::RuntimeType::GetSingleton(), paf_base_offset_of(::pafcore::Object, ::pafcore::Reference)},
		};
		m_baseClasses = s_baseClasses;
		m_baseClassCount = paf_array_size_of(s_baseClasses);
		static ::pafcore::ClassTypeIterator s_classTypeIterators[] =
		{
			::pafcore::ClassTypeIterator(RuntimeTypeOf<::pafcore::Reference>::RuntimeType::GetSingleton()->m_firstDerivedClass, this),
		};
		RuntimeTypeOf<::pafcore::Reference>::RuntimeType::GetSingleton()->m_firstDerivedClass = &s_classTypeIterators[0];
		m_classTypeIterators = s_classTypeIterators;
		::pafcore::NameSpace::GetGlobalNameSpace()->getNameSpace("pafcore")->registerMember(this);
	}

	void __pafcore__Object_Type::destroyInstance(void* address)
	{
		reinterpret_cast<::pafcore::Reference*>(address)->release();
	}

	void __pafcore__Object_Type::destroyArray(void* address)
	{
		paf_delete_array(reinterpret_cast<::pafcore::RefCountImpl<::pafcore::Object>*>(address));
	}

	bool __pafcore__Object_Type::assign(void* dst, const void* src)
	{
		return false;
	}

	__pafcore__Object_Type* __pafcore__Object_Type::GetSingleton()
	{
		static __pafcore__Object_Type* s_instance = 0;
		static char s_buffer[sizeof(__pafcore__Object_Type)];
		if(0 == s_instance)
		{
			s_instance = (__pafcore__Object_Type*)s_buffer;
			new (s_buffer)__pafcore__Object_Type;
		}
		return s_instance;
	}

}

AUTO_REGISTER_TYPE(::idlcpp::__pafcore__Object_Type)
