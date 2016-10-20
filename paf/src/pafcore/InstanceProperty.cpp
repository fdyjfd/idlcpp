#include "InstanceProperty.h"
#include "InstanceProperty.mh"
#include "InstanceProperty.ic"
#include "InstanceProperty.mc"

BEGIN_PAFCORE

InstanceProperty::InstanceProperty(const char* name, ClassType* objectType, 
	InstancePropertyGetter getter, Type* getterType, Passing getterPassing, bool getterConstant,
	InstancePropertySetter setter, Type* setterType, Passing setterPassing, bool setterConstant)
: Metadata(name)
{
	m_objectType = objectType;
	m_getter = getter;
	m_setter = setter;
	m_getterType = getterType;
	m_setterType = setterType;
	m_getterPassing = getterPassing;
	m_setterPassing = setterPassing;
	m_getterConstant = getterConstant;
	m_setterConstant = setterConstant;
}

ClassType* InstanceProperty::get_objectType()
{
	return m_objectType;
}

bool InstanceProperty::get_hasGetter() const
{
	return (0 != m_getter);
}

bool InstanceProperty::get_hasSetter() const
{
	return (0 != m_setter);
}

Type* InstanceProperty::get_getterType()
{
	return m_getterType;
}

bool InstanceProperty::get_getterByValue() const
{
	return (by_value == m_getterPassing);
}

bool InstanceProperty::get_getterByRef() const
{
	return (by_ref == m_getterPassing);
}

bool InstanceProperty::get_getterByPtr() const
{
	return (by_ptr == m_getterPassing);
}

bool InstanceProperty::get_getterConstant() const
{
	return m_getterConstant;
}

Type* InstanceProperty::get_setterType()
{
	return m_setterType;
}

bool InstanceProperty::get_setterByValue() const
{
	return (by_value == m_setterPassing);
}

bool InstanceProperty::get_setterByRef() const
{
	return (by_ref == m_setterPassing);
}

bool InstanceProperty::get_setterByPtr() const
{
	return (by_ptr == m_setterPassing);
}

bool InstanceProperty::get_setterConstant() const
{
	return m_setterConstant;
}


END_PAFCORE