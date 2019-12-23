#include "StaticProperty.h"
#include "StaticProperty.mh"
#include "StaticProperty.ic"
#include "StaticProperty.mc"

BEGIN_PAFCORE

StaticProperty::StaticProperty(
	const char* name,
	Attributes* attributes,
	Type* type,
	bool isPtr,
	StaticPropertyGetter getter,
	StaticPropertySetter setter,
	StaticPropertyCandidateCount candidateCount,
	StaticPropertyGetCandidate getCandidate)
	: Metadata(name, attributes)
{
	m_type = type;
	m_isPtr = isPtr;
	m_keyType = 0;
	m_isKeyPtr = false;
	m_getter = getter;
	m_setter = setter;
	m_candidateCount = candidateCount;
	m_getCandidate = getCandidate;
	m_category = simple_property;
}

StaticProperty::StaticProperty(
	const char* name,
	Attributes* attributes,
	Type* type,
	bool isPtr,
	ArrayStaticPropertyGetter getter,
	ArrayStaticPropertySetter setter,
	ArrayStaticPropertySizer sizer,
	ArrayStaticPropertyResizer resizer,
	ArrayStaticPropertyGetIterator getIterator,
	ArrayStaticPropertyGetValue getValue)
	: Metadata(name, attributes)
{
	m_type = type;
	m_isPtr = isPtr;
	m_keyType = 0;
	m_isKeyPtr = false;
	m_arrayGetter = getter;
	m_arraySetter = setter;
	m_arraySizer = sizer;
	m_arrayResizer = resizer;
	m_arrayGetIterator = getIterator;
	m_arrayGetValue = getValue;
	m_category = array_property;
}

StaticProperty::StaticProperty(
	const char* name,
	Attributes* attributes,
	Type* type,
	bool isPtr,
	ListStaticPropertyPushBack pushBack,
	ListStaticPropertyGetIterator getIterator,
	ListStaticPropertyGetValue getValue,
	ListStaticPropertyInsert insert,
	ListStaticPropertyErase erase)
	: Metadata(name, attributes)
{
	m_type = type;
	m_isPtr = isPtr;
	m_keyType = 0;
	m_isKeyPtr = false;
	m_listPushBack = pushBack;
	m_listGetIterator = getIterator;
	m_listGetValue = getValue;
	m_listInsert = insert;
	m_listErase = erase;
	m_category = list_property;
}

StaticProperty::StaticProperty(
	const char* name,
	Attributes* attributes,
	Type* type,
	bool isPtr,
	Type* keyType,
	bool isKeyPtr,
	MapStaticPropertyGetter getter,
	MapStaticPropertySetter setter,
	MapStaticPropertyGetIterator getIterator,
	MapStaticPropertyGetKey getKey,
	MapStaticPropertyGetValue getValue)
	: Metadata(name, attributes)
{
	m_type = type;
	m_isPtr = isPtr;
	m_keyType = keyType;
	m_isKeyPtr = isKeyPtr;
	m_mapGetter = getter;
	m_mapSetter = setter;
	m_mapGetIterator = getIterator;
	m_mapGetKey = getKey;
	m_mapGetValue = getValue;
	m_category = map_property;
}

bool StaticProperty::get_isSimple() const
{
	return simple_property == m_category;
}

bool StaticProperty::get_isArray() const
{
	return array_property == m_category;
}

bool StaticProperty::get_isList() const
{
	return list_property == m_category;
}

bool StaticProperty::get_isMap() const
{
	return map_property == m_category;
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

bool StaticProperty::get_hasCandidate() const
{
	return get_isSimple() && m_candidateCount && m_getCandidate;
}

Type* StaticProperty::get_type() const
{
	return m_type;
}

bool StaticProperty::get_isPtr() const
{
	return m_isPtr;
}

Type* StaticProperty::get_keyType() const
{
	return m_keyType;
}

bool StaticProperty::get_isKeyPtr() const
{
	return m_isKeyPtr;
}

END_PAFCORE