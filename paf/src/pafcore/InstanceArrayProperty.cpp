#include "InstanceArrayProperty.h"
#include "InstanceArrayProperty.mh"
#include "InstanceArrayProperty.ic"
#include "InstanceArrayProperty.mc"

BEGIN_PAFCORE

InstanceArrayProperty::InstanceArrayProperty(const char* name, ClassType* objectType,
	InstanceArrayPropertyGetter getter, Type* getterType, Passing getterPassing, bool getterConstant,
	InstanceArrayPropertySetter setter, Type* setterType, Passing setterPassing, bool setterConstant,
	InstanceArrayPropertySizer sizer, InstanceArrayPropertyResizer resizer)
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
	m_sizer = sizer;
	m_resizer = resizer;
}

ClassType* InstanceArrayProperty::get_objectType()
{
	return m_objectType;
}

bool InstanceArrayProperty::get_hasGetter() const
{
	return (0 != m_getter);
}

bool InstanceArrayProperty::get_hasSetter() const
{
	return (0 != m_setter);
}

bool InstanceArrayProperty::get_hasSizer() const
{
	return (0 != m_sizer);
}

bool InstanceArrayProperty::get_hasResizer() const
{
	return (0 != m_resizer);
}

Type* InstanceArrayProperty::get_getterType()
{
	return m_getterType;
}

bool InstanceArrayProperty::get_getterByValue() const
{
	return (by_value == m_getterPassing);
}

bool InstanceArrayProperty::get_getterByRef() const
{
	return (by_ref == m_getterPassing);
}

bool InstanceArrayProperty::get_getterByPtr() const
{
	return (by_ptr == m_getterPassing);
}

bool InstanceArrayProperty::get_getterConstant() const
{
	return m_getterConstant;
}

Type* InstanceArrayProperty::get_setterType()
{
	return m_setterType;
}

bool InstanceArrayProperty::get_setterByValue() const
{
	return (by_value == m_setterPassing);
}

bool InstanceArrayProperty::get_setterByRef() const
{
	return (by_ref == m_setterPassing);
}

bool InstanceArrayProperty::get_setterByPtr() const
{
	return (by_ptr == m_setterPassing);
}

bool InstanceArrayProperty::get_setterConstant() const
{
	return m_setterConstant;
}


END_PAFCORE