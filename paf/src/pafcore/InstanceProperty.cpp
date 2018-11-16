#include "InstanceProperty.h"
#include "InstanceProperty.mh"
#include "InstanceProperty.ic"
#include "InstanceProperty.mc"

BEGIN_PAFCORE

InstanceProperty::InstanceProperty(const char* name, Attributes* attributes, ClassType* objectType,
	InstancePropertyGetter getter, Type* getterType, Passing getterPassing, bool getterConstant,
	InstancePropertySetter setter, Type* setterType, Passing setterPassing, bool setterConstant)
	:Metadata(name, attributes)
{
	m_objectType = objectType;
	m_getter = getter;
	m_setter = setter;
	m_getterType = getterType;
	m_setterType = setterType;
	m_keyType = 0;
	m_getterPassing = getterPassing;
	m_setterPassing = setterPassing;
	m_keyPassing = by_value;
	m_getterConstant = getterConstant;
	m_setterConstant = setterConstant;
	m_keyConstant = false;
	m_category = simple_property;
}

InstanceProperty::InstanceProperty(const char* name, Attributes* attributes, ClassType* objectType,
	ArrayInstancePropertyGetter getter, Type* getterType, Passing getterPassing, bool getterConstant,
	ArrayInstancePropertySetter setter, Type* setterType, Passing setterPassing, bool setterConstant,
	ArrayInstancePropertySizer sizer, ArrayInstancePropertyResizer resizer)
	:Metadata(name, attributes)
{
	m_objectType = objectType;
	m_arrayGetter = getter;
	m_arraySetter = setter;
	m_getterType = getterType;
	m_setterType = setterType;
	m_keyType = 0;
	m_getterPassing = getterPassing;
	m_setterPassing = setterPassing;
	m_keyPassing = by_value;
	m_getterConstant = getterConstant;
	m_setterConstant = setterConstant;
	m_keyConstant = false;
	m_arraySizer = sizer;
	m_arrayResizer = resizer;
	m_category = array_property;
}

InstanceProperty::InstanceProperty(const char* name, Attributes* attributes, ClassType* objectType,
	ListInstancePropertyGetter getter, Type* getterType, Passing getterPassing, bool getterConstant,
	ListInstancePropertySetter setter, Type* setterType, Passing setterPassing, bool setterConstant,
	ListInstancePropertyPushBack pushBack,
	ListInstancePropertyGetIterator getIterator,
	ListInstancePropertyGetValue getValue)
	:Metadata(name, attributes)
{
	m_objectType = objectType;
	m_listGetter = getter;
	m_listSetter = setter;
	m_getterType = getterType;
	m_setterType = setterType;
	m_keyType = 0;
	m_getterPassing = getterPassing;
	m_setterPassing = setterPassing;
	m_keyPassing = by_value;
	m_getterConstant = getterConstant;
	m_setterConstant = setterConstant;
	m_keyConstant = false;
	m_listPushBack = pushBack;
	m_listGetIterator = getIterator;
	m_listGetValue = getValue;
	m_category = list_property;
}

InstanceProperty::InstanceProperty(const char* name, Attributes* attributes, ClassType* objectType,
	MapInstancePropertyGetter getter, Type* getterType, Passing getterPassing, bool getterConstant,
	MapInstancePropertySetter setter, Type* setterType, Passing setterPassing, bool setterConstant,
	MapInstancePropertyGetIterator getIterator,
	MapInstancePropertyGetKey getKey,
	MapInstancePropertyGetValue getValue,
	Type* keyType, Passing keyPassing, bool keyConstant)
	:Metadata(name, attributes)
{
	m_objectType = objectType;
	m_mapGetter = getter;
	m_mapSetter = setter;
	m_getterType = getterType;
	m_setterType = setterType;
	m_keyType = keyType;
	m_getterPassing = getterPassing;
	m_setterPassing = setterPassing;
	m_keyPassing = keyPassing;
	m_getterConstant = getterConstant;
	m_setterConstant = setterConstant;
	m_keyConstant = keyConstant;
	m_mapGetIterator = getIterator;
	m_mapGetKey = getKey;
	m_mapGetValue = getValue;
	m_category = map_property;
}

ClassType* InstanceProperty::get_objectType()
{
	return m_objectType;
}

bool InstanceProperty::get_isSimple() const
{
	return simple_property == m_category;
}

bool InstanceProperty::get_isArray() const
{
	return array_property == m_category;
}

bool InstanceProperty::get_isList() const
{
	return list_property == m_category;
}

bool InstanceProperty::get_isMap() const
{
	return map_property == m_category;
}

bool InstanceProperty::get_hasGetter() const
{
	return (0 != m_getter);
}

bool InstanceProperty::get_hasSetter() const
{
	return (0 != m_setter);
}

bool InstanceProperty::get_hasSizer() const
{
	return (0 != m_arraySizer);
}

bool InstanceProperty::get_hasResizer() const
{
	return (0 != m_arrayResizer);
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

Type* InstanceProperty::get_keyType()
{
	return m_keyType;
}

bool InstanceProperty::get_keyByValue() const
{
	return (by_value == m_keyPassing);
}

bool InstanceProperty::get_keyByRef() const
{
	return (by_ref == m_keyPassing);
}

bool InstanceProperty::get_keyByPtr() const
{
	return (by_ptr == m_keyPassing);
}

bool InstanceProperty::get_keyConstant() const
{
	return m_keyConstant;
}



END_PAFCORE