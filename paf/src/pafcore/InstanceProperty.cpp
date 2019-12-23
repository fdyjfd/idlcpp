#include "InstanceProperty.h"
#include "InstanceProperty.mh"
#include "InstanceProperty.ic"
#include "InstanceProperty.mc"

BEGIN_PAFCORE

InstanceProperty::InstanceProperty(
	const char* name,
	Attributes* attributes,
	ClassType* objectType,
	Type* type,
	bool isPtr,
	InstancePropertyGetter getter,
	InstancePropertySetter setter,
	InstancePropertyCandidateCount candidateCount,
	InstancePropertyGetCandidate getCandidate)
	:Metadata(name, attributes)
{
	m_objectType = objectType;
	m_type = type;
	m_isPtr = isPtr;
	m_keyType = 0;
	m_isKeyPtr = false;
	m_getter = getter;
	m_setter = setter;
	m_candidateCount = candidateCount;
	m_getCandidate = getCandidate;
	m_category = simple_property;
	m_serializable = !_hasAttribute_("NonSerialized");
}

InstanceProperty::InstanceProperty(
	const char* name,
	Attributes* attributes,
	ClassType* objectType,
	Type* type,
	bool isPtr,
	ArrayInstancePropertyGetter getter,
	ArrayInstancePropertySetter setter,
	ArrayInstancePropertySizer sizer,
	ArrayInstancePropertyResizer resizer,
	ArrayInstancePropertyGetIterator getIterator,
	ArrayInstancePropertyGetValue getValue)
	:Metadata(name, attributes)
{
	m_objectType = objectType;
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
	m_serializable = !_hasAttribute_("NonSerialized");
}

InstanceProperty::InstanceProperty(
	const char* name,
	Attributes* attributes,
	ClassType* objectType,
	Type* type,
	bool isPtr,
	ListInstancePropertyPushBack pushBack,
	ListInstancePropertyGetIterator getIterator,
	ListInstancePropertyGetValue getValue,
	ListInstancePropertyInsert insert,
	ListInstancePropertyErase erase)
:Metadata(name, attributes)
{
	m_objectType = objectType;
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
	m_serializable = !_hasAttribute_("NonSerialized");
}

InstanceProperty::InstanceProperty(
	const char* name,
	Attributes* attributes,
	ClassType* objectType,
	Type* type,
	bool isPtr,
	Type* keyType,
	bool isKeyPtr,
	MapInstancePropertyGetter getter,
	MapInstancePropertySetter setter,
	MapInstancePropertyGetIterator getIterator,
	MapInstancePropertyGetKey getKey,
	MapInstancePropertyGetValue getValue)
	:Metadata(name, attributes)
{
	m_objectType = objectType;
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
	m_serializable = !_hasAttribute_("NonSerialized");
}

END_PAFCORE