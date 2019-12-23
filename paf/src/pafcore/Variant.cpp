#pragma once

#include "Variant.h"
#include "VoidType.h"
#include "PrimitiveType.h"
#include "EnumType.h"
#include "ClassType.h"
#include "Reference.h"
#include "Debug.h"
#include <assert.h>
#include <memory.h>

BEGIN_PAFCORE


#ifdef _DEBUG

class VariantLeakReporter
{
public:
	~VariantLeakReporter()
	{
		m_liveObjects.lock();
		for (auto& item : m_liveObjects.m_objects)
		{
			Variant* variant = item.first;
			size_t serialNumber = item.second;
			char buf[1024];
#ifdef _WIN64
			sprintf_s(buf, "pafcore Warning: Live Variant at 0x%p, SerialNumber:%llu\n",
				variant, serialNumber);
#else
			sprintf_s(buf, "pafcore Warning: Live Variant at 0x%p, SerialNumber:%lu\n",
				variant, serialNumber);
#endif
			OutputDebugStringA(buf);
		}
		m_liveObjects.unlock();
	}
public:
	void onVariantConstruct(Variant* variant)
	{
		m_liveObjects.addPtr(variant);
	}
	void onVariantDestruct(Variant* variant)
	{
		m_liveObjects.removePtr(variant);
	}
public:
	LiveObjects<Variant> m_liveObjects;
public:
	static VariantLeakReporter* GetInstance()
	{
		static VariantLeakReporter s_instance;
		return &s_instance;
	}
};

#endif//_DEBUG

Variant::Variant()
{
	m_type = VoidType::GetSingleton();
	m_pointer = 0;
	m_arraySize = 0;
	m_semantic = by_value;
	m_constant = false;
	m_temporary = false;
	m_subClassProxy = false;

#ifdef _DEBUG
	VariantLeakReporter::GetInstance()->onVariantConstruct(this);
#endif//_DEBUG
}

Variant::~Variant()
{
	if (0 != m_pointer && m_primitiveValue != m_pointer &&
		(by_value == m_semantic || by_new_ptr == m_semantic || by_new_array == m_semantic))
	{
		assert(m_primitiveValue != m_pointer);
		if (by_new_array == m_semantic)
		{
			m_type->destroyArray(m_pointer);
		}
		else
		{
			if (m_subClassProxy)
			{
				PAF_ASSERT(m_type->isValue() || m_type->isReference());
				static_cast<ClassType*>(m_type)->destroySubclassProxy(m_pointer);
			}
			else
			{
				m_type->destroyInstance(m_pointer);
			}
		}
	}

#ifdef _DEBUG
	VariantLeakReporter::GetInstance()->onVariantDestruct(this);
#endif//_DEBUG
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

bool Variant::unhold()
{
	if(by_new_ptr == m_semantic)
	{
		m_semantic = by_ptr;
		return true;
	}
	else if(by_new_array == m_semantic)
	{
		m_semantic = by_array;
		return true;
	}
	return false;
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

void Variant::assignPrimitiveForNew(Type* type, const void* pointer)
{
	assert(type->isPrimitive());
	clear();
	m_type = type;
	m_pointer = m_primitiveValue;
	memcpy(m_pointer, pointer, type->m_size);
	m_constant = false;
	m_semantic = by_ptr;
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

void Variant::assignReferencePtr(Reference* pointer, bool constant, Semantic semantic)
{
	clear();
	if (0 != pointer)
	{
		m_type = pointer->getType();
		m_pointer = (void*)pointer->getAddress();
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

void Variant::assignNullPtr()
{
	clear();
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
		switch (m_type->m_size)
		{
		case 1:
			CharType::GetSingleton()->castTo(dst, dstType, m_pointer);
			return true;
		case 2:
			ShortType::GetSingleton()->castTo(dst, dstType, m_pointer);
			return true;
		case 4:
			IntType::GetSingleton()->castTo(dst, dstType, m_pointer);
			return true;
		default:
			assert(false);
		}
	}
	return false;
}

bool Variant::castToEnum(Type* dstType, void* dst) const
{
	assert(dstType->isEnum());
	int tmp;
	if(m_type->isPrimitive())
	{
		static_cast<PrimitiveType*>(m_type)->castTo(&tmp, IntType::GetSingleton(), m_pointer);
	}
	else if(m_type->isEnum())
	{
		switch (m_type->m_size)
		{
		case 1:
			CharType::GetSingleton()->castTo(&tmp, IntType::GetSingleton(), m_pointer);
			break;
		case 2:
			ShortType::GetSingleton()->castTo(&tmp, IntType::GetSingleton(), m_pointer);
			break;
		case 4:
			IntType::GetSingleton()->castTo(&tmp, IntType::GetSingleton(), m_pointer);
			break;
		default:
			assert(false);
		}
	}
	else
	{
		return false;
	}
	switch (dstType->m_size)
	{
	case 1:
		IntType::GetSingleton()->castTo(dst, CharType::GetSingleton(), &tmp);
		return true;
	case 2:
		IntType::GetSingleton()->castTo(dst, ShortType::GetSingleton(), &tmp);
		return true;
	case 4:
		IntType::GetSingleton()->castTo(dst, IntType::GetSingleton(), &tmp);
		return true;
	default:
		assert(false);
	}
	return false;
}

bool Variant::castToValue(Type* dstType, void* dst) const
{
	assert(dstType->isValue());
	void* ptr;
	if(castToValuePtr(dstType, &ptr) && ptr)
	{
		return dstType->assign(dst, ptr);
	}
	return false;
}

bool Variant::castToReference(Type* dstType, void* dst) const
{
	assert(dstType->isReference());
	void* ptr;
	if(castToReferencePtr(dstType, &ptr) && ptr)
	{
		return dstType->assign(dst, ptr);
	}
	return false;
}

bool Variant::castToVoidPtr(void** dst) const
{
	if (0 != m_pointer)
	{
		*dst = m_pointer;
		return true;
	}
	return false;
}

bool Variant::castToPrimitivePtr(Type* dstType, void** dst) const
{
	assert(dstType->isPrimitive());
	if(m_type == dstType && 0 != m_pointer)
	{
		*dst = m_pointer;
		return true;
	}
	return false;
}

bool Variant::castToEnumPtr(Type* dstType, void** dst) const
{
	assert(dstType->isEnum());
	if(m_type == dstType && 0 != m_pointer)
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
		return false;
	}
	size_t offset;
	if (static_cast<ClassType*>(m_type)->getClassOffset(offset, static_cast<ClassType*>(dstType)))
	{
		*dst = (void*)((size_t)m_pointer + offset);
		return true;
	}
	return false;
}

bool Variant::castToReferencePtr(Type* dstType, void** dst) const
{
	assert(dstType->isReference());
	if(0 == m_pointer)
	{
		return false;
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


bool Variant::castToVoidPtrAllowNull(void** dst) const
{
	*dst = m_pointer;
	return true;
}

bool Variant::castToPrimitivePtrAllowNull(Type* dstType, void** dst) const
{
	if (0 == m_pointer)
	{
		*dst = 0;
		return true;
	}
	assert(dstType->isPrimitive());
	if (m_type == dstType)
	{
		*dst = m_pointer;
		return true;
	}
	return false;
}

bool Variant::castToEnumPtrAllowNull(Type* dstType, void** dst) const
{
	if (0 == m_pointer)
	{
		*dst = 0;
		return true;
	}
	assert(dstType->isEnum());
	if (m_type == dstType)
	{
		*dst = m_pointer;
		return true;
	}
	return false;
}

bool Variant::castToValuePtrAllowNull(Type* dstType, void** dst) const
{
	if (0 == m_pointer)
	{
		*dst = 0;
		return true;
	}
	assert(dstType->isValue());
	if (m_type->isValue())
	{
		size_t offset;
		if (static_cast<ClassType*>(m_type)->getClassOffset(offset, static_cast<ClassType*>(dstType)))
		{
			*dst = (void*)((size_t)m_pointer + offset);
			return true;
		}
	}
	return false;
}

bool Variant::castToReferencePtrAllowNull(Type* dstType, void** dst) const
{
	if (0 == m_pointer)
	{
		*dst = 0;
		return true;
	}
	assert(dstType->isReference());
	if (m_type->isReference())
	{
		size_t offset;
		if (static_cast<ClassType*>(m_type)->getClassOffset(offset, static_cast<ClassType*>(dstType)))
		{
			*(size_t*)dst = (size_t)m_pointer + offset;
			return true;
		}
	}
	return false;
}

bool Variant::castToObjectPtr(Type* dstType, void** dst) const
{
	switch (dstType->m_category)
	{
	case void_object:
		return castToVoidPtr(dst);
	case primitive_object:
		return castToPrimitivePtr(dstType, dst);
	case enum_object:
		return castToEnumPtr(dstType, dst);
	case value_object:
		return castToValuePtr(dstType, dst);
	case reference_object:
		return castToReferencePtr(dstType, dst);
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

