#include "StaticArrayProperty.h"
#include "StaticArrayProperty.mh"
#include "StaticArrayProperty.ic"
#include "StaticArrayProperty.mc"

BEGIN_PAFCORE

StaticArrayProperty::StaticArrayProperty(const char* name, Attributes* attributes,
	StaticArrayPropertyGetter getter, Type* getterType, Passing getterPassing, bool getterConstant,
	StaticArrayPropertySetter setter, Type* setterType, Passing setterPassing, bool setterConstant,
	StaticArrayPropertySizer sizer, StaticArrayPropertyResizer resizer)
: Metadata(name, attributes)
{
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

bool StaticArrayProperty::get_hasGetter() const
{
	return (0 != m_getter);
}

bool StaticArrayProperty::get_hasSetter() const
{
	return (0 != m_setter);
}

bool StaticArrayProperty::get_hasSizer() const
{
	return (0 != m_sizer);
}

bool StaticArrayProperty::get_hasResizer() const
{
	return (0 != m_resizer);
}

Type* StaticArrayProperty::get_getterType()
{
	return m_getterType;
}

bool StaticArrayProperty::get_getterByValue() const
{
	return (by_value == m_getterPassing);
}

bool StaticArrayProperty::get_getterByRef() const
{
	return (by_ref == m_getterPassing);
}

bool StaticArrayProperty::get_getterByPtr() const
{
	return (by_ptr == m_getterPassing);
}

bool StaticArrayProperty::get_getterConstant() const
{
	return m_getterConstant;
}

Type* StaticArrayProperty::get_setterType()
{
	return m_setterType;
}

bool StaticArrayProperty::get_setterByValue() const
{
	return (by_value == m_setterPassing);
}

bool StaticArrayProperty::get_setterByRef() const
{
	return (by_ref == m_setterPassing);
}

bool StaticArrayProperty::get_setterByPtr() const
{
	return (by_ptr == m_setterPassing);
}

bool StaticArrayProperty::get_setterConstant() const
{
	return m_setterConstant;
}


END_PAFCORE