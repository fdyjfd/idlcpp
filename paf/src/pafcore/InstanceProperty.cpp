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

bool InstanceProperty::get_hasGetter()
{
	return (0 != m_getter);
}

bool InstanceProperty::get_hasSetter()
{
	return (0 != m_setter);
}

Type* InstanceProperty::get_getterType()
{
	return m_getterType;
}

bool InstanceProperty::get_getterByValue()
{
	return (by_value == m_getterPassing);
}

bool InstanceProperty::get_getterByRef()
{
	return (by_ref == m_getterPassing);
}

bool InstanceProperty::get_getterByPtr()
{
	return (by_ptr == m_getterPassing);
}

bool InstanceProperty::get_getterConstant()
{
	return m_getterConstant;
}

Type* InstanceProperty::get_setterType()
{
	return m_setterType;
}

bool InstanceProperty::get_setterByValue()
{
	return (by_value == m_setterPassing);
}

bool InstanceProperty::get_setterByRef()
{
	return (by_ref == m_setterPassing);
}

bool InstanceProperty::get_setterByPtr()
{
	return (by_ptr == m_setterPassing);
}

bool InstanceProperty::get_setterConstant()
{
	return m_setterConstant;
}


END_PAFCORE