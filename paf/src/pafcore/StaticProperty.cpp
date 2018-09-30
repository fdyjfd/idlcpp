#include "StaticProperty.h"
#include "StaticProperty.mh"
#include "StaticProperty.ic"
#include "StaticProperty.mc"

BEGIN_PAFCORE

StaticProperty::StaticProperty(const char* name, Attributes* attributes,
	StaticPropertyGetter getter, Type* getterType, Passing getterPassing, bool getterConstant, 
	StaticPropertySetter setter, Type* setterType, Passing setterPassing, bool setterConstant)
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
	m_array = false;
}

StaticProperty::StaticProperty(const char* name, Attributes* attributes,
	ArrayStaticPropertyGetter getter, Type* getterType, Passing getterPassing, bool getterConstant,
	ArrayStaticPropertySetter setter, Type* setterType, Passing setterPassing, bool setterConstant,
	ArrayStaticPropertySizer sizer, ArrayStaticPropertyResizer resizer)
	: Metadata(name, attributes)
{
	m_arrayGetter = getter;
	m_arraySetter = setter;
	m_getterType = getterType;
	m_setterType = setterType;
	m_getterPassing = getterPassing;
	m_setterPassing = setterPassing;
	m_getterConstant = getterConstant;
	m_setterConstant = setterConstant;
	m_arraySizer = sizer;
	m_arrayResizer = resizer;
	m_array = true;
}


bool StaticProperty::get_isArray() const
{
	return m_array;
}

bool StaticProperty::get_hasGetter() const
{
	return (0 != m_getter);
}

bool StaticProperty::get_hasSetter() const
{
	return (0 != m_setter);
}

bool StaticProperty::get_hasSizer() const
{
	return (0 != m_arraySizer);
}

bool StaticProperty::get_hasResizer() const
{
	return (0 != m_arrayResizer);
}

Type* StaticProperty::get_getterType()
{
	return m_getterType;
}

bool StaticProperty::get_getterByValue() const
{
	return (by_value == m_getterPassing);
}

bool StaticProperty::get_getterByRef() const
{
	return (by_ref == m_getterPassing);
}

bool StaticProperty::get_getterByPtr() const
{
	return (by_ptr == m_getterPassing);
}

bool StaticProperty::get_getterConstant() const
{
	return m_getterConstant;
}

Type* StaticProperty::get_setterType()
{
	return m_setterType;
}

bool StaticProperty::get_setterByValue() const
{
	return (by_value == m_setterPassing);
}

bool StaticProperty::get_setterByRef() const
{
	return (by_ref == m_setterPassing);
}

bool StaticProperty::get_setterByPtr() const
{
	return (by_ptr == m_setterPassing);
}

bool StaticProperty::get_setterConstant() const
{
	return m_setterConstant;
}



END_PAFCORE