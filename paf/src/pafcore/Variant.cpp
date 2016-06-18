#pragma once

#include "Variant.h"
#include "VoidType.h"
#include "PrimitiveType.h"
#include "EnumType.h"
#include "ClassType.h"
#include "Reference.h"
#include "Reference.mh"
#include <assert.h>
#include <memory.h>

BEGIN_PAFCORE

Variant::Variant()
{
	m_type = VoidType::GetSingleton();
	m_pointer = 0;
	m_arraySize = 0;
	m_semantic = by_value;
	m_constant = false;
}

Variant::~Variant()
{
	clear();
}

void Variant::clear()
{
	if(0 != m_pointer && (by_new_ptr == m_semantic || by_new_array == m_semantic))
	{
		assert(m_primitiveValue != m_pointer);
		if(by_new_array == m_semantic)
		{
			m_type->destroyArray(m_pointer);
		}
		else
		{
			m_type->destroyInstance(m_pointer);
		}
	}
	m_type = VoidType::GetSingleton();
	m_pointer = 0;
	m_arraySize = 0;
	m_semantic = by_value;
	m_constant = false;
}

void Variant::unhold()
{
	if(by_new_ptr == m_semantic)
	{
		m_semantic = by_ptr;
	}
	else if(by_new_array == m_semantic)
	{
		m_semantic = by_array;
	}
}

void Variant::move(Variant& var)
{
	clear();
	memcpy(this, &var, sizeof(Variant));
	if(var.m_pointer == var.m_primitiveValue)
	{
		m_pointer = m_primitiveValue;
	}
	var.m_semantic = by_value;
	var.m_pointer = 0;
}

bool Variant::subscript(Variant& var, size_t index)
{
	if(by_value != m_semantic && (0 == index || index < m_arraySize))
	{
		var.assignPtr(m_type, (void*)((size_t)m_pointer + m_type->m_size * index), m_constant, by_ref);
		//var.assignArray(m_type, (void*)((size_t)m_pointer + m_type->m_size * index), m_arraySize - index, m_constant, by_ref);
		return true;
	}
	return false;
}

void Variant::assignPrimitive(Type* type, const void* pointer)
{
	assert(type->isPrimitive());
	clear();
	m_type = type;
	m_pointer = m_primitiveValue;
	memcpy(m_pointer, pointer, type->m_size);
}

void Variant::assignEnum(Type* type, const void* pointer)
{
	assert(type->isEnum());
	clear();
	m_type = type;
	m_pointer = m_primitiveValue;
	memcpy(m_pointer, pointer, type->m_size);
}

void Variant::assignVoidPtr(const void* pointer, bool constant)
{
	clear();
	m_pointer = (void*)pointer;
	m_constant = constant;
	m_semantic = by_ptr;
}

void Variant::assignPrimitivePtr(Type* type, const void* pointer, bool constant, Semantic semantic)
{
	assert(type->isPrimitive());
	clear();
	m_type = type;
	m_pointer = (void*)pointer;
	m_constant = constant;
	m_semantic = semantic;
}

void Variant::assignEnumPtr(Type* type, const void* pointer, bool constant, Semantic semantic)
{
	assert(type->isEnum());
	clear();
	m_type = type;
	m_pointer = (void*)pointer;
	m_constant = constant;
	m_semantic = semantic;
}

void Variant::assignValuePtr(Type* type, const void* pointer, bool constant, Semantic semantic)
{
	assert(type->isValue());
	clear();
	m_type = type;
	m_pointer = (void*)pointer;
	m_constant = constant;
	m_semantic = semantic;
}

void Variant::assignReferencePtr(Type* type, const void* pointer, bool constant, Semantic semantic)
{
	assert(type->isReference());
	clear();
	if(0 != pointer)
	{
		m_type = ((Reference*)pointer)->getType();
		m_pointer = (void*)((Reference*)pointer)->getAddress();
	}
	else
	{
		m_type = type;
		m_pointer = 0;
	}
	m_constant = constant;
	m_semantic = semantic;
}

void Variant::assignNullPrimitive(Type* type)
{
	assert(type->isPrimitive());
	clear();
	m_type = type;
	m_pointer = m_primitiveValue;
	memset(m_pointer, 0, sizeof(m_primitiveValue));
}

void Variant::assignNullEnum(Type* type)
{
	assert(type->isEnum());
	clear();
	m_type = type;
	m_pointer = m_primitiveValue;
	memset(m_pointer, 0, sizeof(m_primitiveValue));
}

void Variant::assignNullPtr(Type* type)
{
	clear();
	m_type = type;
	m_semantic = by_ptr;
}

void Variant::assignPtr(Type* type, const void* pointer, bool constant, Semantic semantic)
{
	switch(type->m_category)
	{
	case void_object:
		assignVoidPtr(pointer, constant);
		break;
	case primitive_object:
		assignPrimitivePtr(type, pointer, constant, semantic);
		break;
	case enum_object:
		assignEnumPtr(type, pointer, constant, semantic);
		break;
	case value_object:
		assignValuePtr(type, pointer, constant, semantic);
		break;
	default:
		assignReferencePtr(type, pointer, constant, semantic);
	}
}

void Variant::assignArray(Type* type, const void* pointer, size_t arraySize, bool constant, Semantic semantic)
{
	clear();
	m_type = type;
	m_pointer = (void*)pointer;
	m_arraySize = arraySize;
	m_constant = constant;
	m_semantic = semantic;
}

//void Variant::assignObject(Type* type, const void* pointer, bool constant, bool hold)
//{
//	switch(type->m_category)
//	{
//	case primitive_object:
//		assignPrimitive(type, pointer);
//		break;
//	case enum_object:
//		assignEnum(type, pointer);
//		break;
//	case value_object:
//		assignValuePtr(type, pointer, constant, hold);
//		break;
//	default:
//		assignReferencePtr(type, pointer, constant, hold);
//	}
//}

bool Variant::castToPrimitive(Type* dstType, void* dst) const
{
	assert(dstType->isPrimitive());
	if(m_type->isPrimitive())
	{
		return static_cast<PrimitiveType*>(m_type)->castTo(dst, dstType, m_pointer);
	}
	if(m_type->isEnum())
	{
		IntType::GetSingleton()->castTo(dst, dstType, m_pointer);
		return true;
	}
	return false;
}

bool Variant::castToEnum(Type* dstType, void* dst) const
{
	assert(dstType->isEnum());
	if(m_type->isPrimitive())
	{
		return static_cast<PrimitiveType*>(m_type)->castTo(dst, IntType::GetSingleton(), m_pointer);
	}
	if(m_type->isEnum())
	{
		memcpy(dst, m_pointer, m_type->m_size);
		return true;
	}
	return false;
}

bool Variant::castToValue(Type* dstType, void* dst) const
{
	assert(dstType->isValue());
	void* ptr;
	if(castToValuePtr(dstType, &ptr) && ptr)
	{
		dstType->assign(dst, ptr);
		return true;
	}
	return false;
}

bool Variant::castToReference(Type* dstType, void* dst) const
{
	assert(dstType->isReference());
	void* ptr;
	if(castToReferencePtr(dstType, &ptr) && ptr)
	{
		dstType->assign(dst, ptr);
		return true;
	}
	return false;
}

bool Variant::castToVoidPtr(void** dst) const
{
	*dst = m_pointer;
	return true;
}

bool Variant::castToPrimitivePtr(Type* dstType, void** dst) const
{
	assert(dstType->isPrimitive());
	if(m_type == dstType)
	{
		*dst = m_pointer;
		return true;
	}
	return false;
}

bool Variant::castToEnumPtr(Type* dstType, void** dst) const
{
	assert(dstType->isEnum());
	if(m_type == dstType)
	{
		*dst = m_pointer;
		return true;
	}
	return false;
}

bool Variant::castToValuePtr(Type* dstType, void** dst) const
{
	assert(dstType->isValue());
	if(0 == m_pointer)
	{
		*dst = 0;
		return true;
	}
	if(m_type->isValue())
	{
		size_t offset;
		if(static_cast<ClassType*>(m_type)->getClassOffset(offset, static_cast<ClassType*>(dstType)))
		{
			*dst = (void*)((size_t)m_pointer + offset);
			return true;
		}
	}
	return false;
}

bool Variant::castToReferencePtr(Type* dstType, void** dst) const
{
	assert(dstType->isReference());
	if(0 == m_pointer)
	{
		*dst = 0;
		return true;
	}
	if(m_type->isReference())
	{
		size_t offset;
		if(static_cast<ClassType*>(m_type)->getClassOffset(offset, static_cast<ClassType*>(dstType)))
		{
			*(size_t*)dst = (size_t)m_pointer + offset;
			return true;
		}
	}
	return false;
}

bool Variant::castToObject(Type* dstType, void* dst) const
{
	switch(dstType->m_category)
	{
	case primitive_object:
		return castToPrimitive(dstType, dst);
	case enum_object:
		return castToEnum(dstType, dst);
	case value_object:
		return castToValue(dstType, dst);
	case reference_object:
		return castToReference(dstType, dst);
	}
	return false;
}

void Variant::reinterpretCastToPtr(Variant& var, Type* dstType) const
{
	assert(var.isNull() && 0 == var.m_arraySize);
	assert(dstType && dstType->m_size);
	var.m_type = dstType;
	var.m_pointer = m_pointer;
	var.m_constant = m_constant;
	size_t size = m_type->m_size *(0 == m_arraySize ? 1 : m_arraySize);
	var.m_arraySize = size / dstType->m_size;
	var.m_semantic = by_ptr;
}

END_PAFCORE

