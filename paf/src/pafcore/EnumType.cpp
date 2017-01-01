#include "EnumType.h"
#include "InstanceProperty.h"
#include "EnumType.mh"
#include "EnumType.ic"
#include "EnumType.mc"

BEGIN_PAFCORE

EnumType::EnumType(const char* name) 
: Type(name, enum_object)
{
	m_enumerators = 0;
	m_enumeratorCount = 0;
	static pafcore::InstanceProperty s_properties[] = 
	{
		pafcore::InstanceProperty("_name_", 0, Enum_get__name_, RuntimeTypeOf<char>::RuntimeType::GetSingleton(), Metadata::by_ptr, true, 0, 0, Metadata::by_value, false),
	};
	m_properties = s_properties;
	m_propertyCount = paf_array_size_of(s_properties);
}

size_t EnumType::_getEnumeratorCount_()
{
	return m_enumeratorCount;
}

Enumerator* EnumType::_getEnumerator_(size_t index)
{
	if(index < m_enumeratorCount)
	{
		return &m_enumerators[index];
	}
	return 0;
}

Enumerator* EnumType::_getEnumeratorByValue_(int value)
{
	for(size_t i = 0; i < m_enumeratorCount; ++i)
	{
		Enumerator* enumerator = &m_enumerators[i];
		if(value == enumerator->m_value)
		{
			return enumerator;
		}
	}
	return 0;
}

Enumerator* EnumType::_getEnumeratorByName_(const char* name)
{
	Metadata dummy(name);
	Enumerator* res = std::lower_bound(m_enumerators, m_enumerators + m_enumeratorCount, dummy);
	if(m_enumerators + m_enumeratorCount != res && strcmp(name, res->m_name) == 0)
	{
		return res;
	}
	return 0;
}

Enumerator* EnumType::get__enumerators_(size_t index)
{
	if (index < m_enumeratorCount)
	{
		return &m_enumerators[index];
	}
	return 0;
}

size_t EnumType::size__enumerators_() const
{
	return m_enumeratorCount;
}

Enumerator* EnumType::findEnumerator(const char* name)
{
	Metadata dummy(name);
	Enumerator* res = std::lower_bound(m_enumerators, m_enumerators + m_enumeratorCount, dummy);
	if(m_enumerators + m_enumeratorCount != res && strcmp(name, res->m_name) == 0)
	{
		return res;
	}
	return 0;
}

pafcore::ErrorCode EnumType::Enum_get__name_(pafcore::Variant* that, pafcore::Variant* value)
{
	if(enum_object != that->m_type->m_category)
	{
		return pafcore::e_invalid_this_type;
	}
	int e;
	if(!that->castToPrimitive(RuntimeTypeOf<int>::RuntimeType::GetSingleton(), &e))
	{
		return pafcore::e_invalid_this_type;
	}
	EnumType* enumType = static_cast<EnumType*>(that->m_type);
	Enumerator* enumerator = enumType->_getEnumeratorByValue_(e);
	if(0 == enumerator)
	{	
		return pafcore::e_invalid_this_type;
	}
	const char* res = enumerator->get__name_();
	value->assignPrimitivePtr(RuntimeTypeOf<char>::RuntimeType::GetSingleton(), res, true, Variant::by_ptr);
	return pafcore::s_ok;
}

Metadata* EnumType::findMember(const char* name)
{
	Metadata dummy(name);
	InstanceProperty* res = std::lower_bound(m_properties, m_properties + m_propertyCount, dummy);
	if (m_properties + m_propertyCount != res && strcmp(name, res->m_name) == 0)
	{
		return res;
	}
	return 0;
}


END_PAFCORE
