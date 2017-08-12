#include "ClassType.h"
#include "ClassType.mh"
#include "ClassType.ic"
#include "ClassType.mc"
#include "Variant.h"
#include "InstanceField.h"
#include "InstanceProperty.h"
#include "InstanceArrayProperty.h"
#include "InstanceMethod.h"
#include "StaticField.h"
#include "StaticProperty.h"
#include "StaticArrayProperty.h"
#include "StaticMethod.h"
#include <algorithm>

BEGIN_PAFCORE

ClassType::ClassType(const char* name, Category category)
: Type(name, category)
{
	m_baseClasses = 0;
	m_baseClassCount = 0;
	m_members = 0;
	m_memberCount = 0;
	m_nestedTypes = 0;
	m_nestedTypeCount = 0;
	m_nestedTypeAliases = 0;
	m_nestedTypeAliasCount = 0;
	m_instanceFields = 0;
	m_instanceFieldCount = 0;
	m_instanceProperties = 0;
	m_instancePropertyCount = 0;
	m_instanceArrayProperties = 0;
	m_instanceArrayPropertyCount = 0;
	m_instanceMethods = 0;
	m_instanceMethodCount = 0;
	m_staticFields = 0;
	m_staticFieldCount = 0;
	m_staticProperties = 0;
	m_staticPropertyCount = 0;
	m_staticArrayProperties = 0;
	m_staticArrayPropertyCount = 0;
	m_staticMethods = 0;
	m_staticMethodCount = 0;
	m_classTypeIterators = 0;
	m_firstDerivedClass = 0;
}

Type* ClassType::findNestedType(const char* name, bool includeBaseClasses)
{
	Metadata dummy(name);
	Type** it = std::lower_bound(m_nestedTypes, m_nestedTypes + m_nestedTypeCount, &dummy, CompareMetaDataPtrByName());
	if (m_nestedTypes + m_nestedTypeCount != it && strcmp(name, (*it)->m_name) == 0)
	{
		return *it;
	}
	if(includeBaseClasses)
	{
		for(size_t i = 0; i < m_baseClassCount; ++i)
		{
			Type* res = m_baseClasses[i].m_type->findNestedType(name, includeBaseClasses);
			if(0 != res)
			{
				return res;
			}
		}
	}
	return 0;
}

TypeAlias* ClassType::findNestedTypeAlias(const char* name, bool includeBaseClasses)
{
	Metadata dummy(name);
	TypeAlias** it = std::lower_bound(m_nestedTypeAliases, m_nestedTypeAliases + m_nestedTypeAliasCount, &dummy, CompareMetaDataPtrByName());
	if (m_nestedTypeAliases + m_nestedTypeAliasCount != it && strcmp(name, (*it)->m_name) == 0)
	{
		return *it;
	}
	if (includeBaseClasses)
	{
		for (size_t i = 0; i < m_baseClassCount; ++i)
		{
			TypeAlias* res = m_baseClasses[i].m_type->findNestedTypeAlias(name, includeBaseClasses);
			if (0 != res)
			{
				return res;
			}
		}
	}
	return 0;
}

InstanceField* ClassType::findInstanceField(const char* name, bool includeBaseClasses)
{
	Metadata dummy(name);
	InstanceField* res = std::lower_bound(m_instanceFields, m_instanceFields + m_instanceFieldCount, dummy);
	if (m_instanceFields + m_instanceFieldCount != res && strcmp(name, res->m_name) == 0)
	{
		return res;
	}
	if(includeBaseClasses)
	{
		for(size_t i = 0; i < m_baseClassCount; ++i)
		{
			res = m_baseClasses[i].m_type->findInstanceField(name, includeBaseClasses);
			if(0 != res)
			{
				return res;
			}
		}
	}
	return 0;
}

StaticField* ClassType::findStaticField(const char* name, bool includeBaseClasses)
{
	Metadata dummy(name);
	StaticField* res = std::lower_bound(m_staticFields, m_staticFields + m_staticFieldCount, dummy);
	if (m_staticFields + m_staticFieldCount != res && strcmp(name, res->m_name) == 0)
	{
		return res;
	}
	if(includeBaseClasses)
	{
		for(size_t i = 0; i < m_baseClassCount; ++i)
		{
			res = m_baseClasses[i].m_type->findStaticField(name, includeBaseClasses);
			if(0 != res)
			{
				return res;
			}
		}
	}
	return 0;
}

InstanceProperty* ClassType::findInstanceProperty(const char* name, bool includeBaseClasses)
{
	Metadata dummy(name);
	InstanceProperty* res = std::lower_bound(m_instanceProperties, m_instanceProperties + m_instancePropertyCount, dummy);
	if (m_instanceProperties + m_instancePropertyCount != res && strcmp(name, res->m_name) == 0)
	{
		return res;
	}
	if (includeBaseClasses)
	{
		for (size_t i = 0; i < m_baseClassCount; ++i)
		{
			res = m_baseClasses[i].m_type->findInstanceProperty(name, includeBaseClasses);
			if (0 != res)
			{
				return res;
			}
		}
	}
	return 0;
}

InstanceArrayProperty* ClassType::findInstanceArrayProperty(const char* name, bool includeBaseClasses)
{
	Metadata dummy(name);
	InstanceArrayProperty* res = std::lower_bound(m_instanceArrayProperties, m_instanceArrayProperties + m_instanceArrayPropertyCount, dummy);
	if (m_instanceArrayProperties + m_instanceArrayPropertyCount != res && strcmp(name, res->m_name) == 0)
	{
		return res;
	}
	if (includeBaseClasses)
	{
		for (size_t i = 0; i < m_baseClassCount; ++i)
		{
			res = m_baseClasses[i].m_type->findInstanceArrayProperty(name, includeBaseClasses);
			if (0 != res)
			{
				return res;
			}
		}
	}
	return 0;
}

StaticProperty* ClassType::findStaticProperty(const char* name, bool includeBaseClasses)
{
	Metadata dummy(name);
	StaticProperty* res = std::lower_bound(m_staticProperties, m_staticProperties + m_staticPropertyCount, dummy);
	if (m_staticProperties + m_staticPropertyCount != res && strcmp(name, res->m_name) == 0)
	{
		return res;
	}
	if (includeBaseClasses)
	{
		for (size_t i = 0; i < m_baseClassCount; ++i)
		{
			res = m_baseClasses[i].m_type->findStaticProperty(name, includeBaseClasses);
			if (0 != res)
			{
				return res;
			}
		}
	}
	return 0;
}

StaticArrayProperty* ClassType::findStaticArrayProperty(const char* name, bool includeBaseClasses)
{
	Metadata dummy(name);
	StaticArrayProperty* res = std::lower_bound(m_staticArrayProperties, m_staticArrayProperties + m_staticArrayPropertyCount, dummy);
	if (m_staticArrayProperties + m_staticArrayPropertyCount != res && strcmp(name, res->m_name) == 0)
	{
		return res;
	}
	if (includeBaseClasses)
	{
		for (size_t i = 0; i < m_baseClassCount; ++i)
		{
			res = m_baseClasses[i].m_type->findStaticArrayProperty(name, includeBaseClasses);
			if (0 != res)
			{
				return res;
			}
		}
	}
	return 0;
}

InstanceMethod* ClassType::findInstanceMethod(const char* name, bool includeBaseClasses)
{
	Metadata dummy(name);
	InstanceMethod* res = std::lower_bound(m_instanceMethods, m_instanceMethods + m_instanceMethodCount, dummy);
	if (m_instanceMethods + m_instanceMethodCount != res && strcmp(name, res->m_name) == 0)
	{
		return res;
	}
	if(includeBaseClasses)
	{
		for(size_t i = 0; i < m_baseClassCount; ++i)
		{
			res = m_baseClasses[i].m_type->findInstanceMethod(name, includeBaseClasses);
			if(0 != res)
			{
				return res;
			}
		}
	}
	return 0;
}

StaticMethod* ClassType::findStaticMethod(const char* name, bool includeBaseClasses)
{
	Metadata dummy(name);
	StaticMethod* res = std::lower_bound(m_staticMethods, m_staticMethods + m_staticMethodCount, dummy);
	if(m_staticMethods + m_staticMethodCount != res && strcmp(name, res->m_name) == 0)
	{
		return res;
	}
	if(includeBaseClasses)
	{
		for(size_t i = 0; i < m_baseClassCount; ++i)
		{
			res = m_baseClasses[i].m_type->findStaticMethod(name, includeBaseClasses);
			if(0 != res)
			{
				return res;
			}
		}
	}
	return 0;
}

Metadata* ClassType::_findMember_(const char* name, bool includeBaseClasses)
{
	Metadata dummy(name);
	Metadata** it = std::lower_bound(m_members, m_members + m_memberCount, &dummy, CompareMetaDataPtrByName());
	if(m_members + m_memberCount != it && strcmp(name, (*it)->m_name) == 0)
	{
		return *it;
	}
	if(includeBaseClasses)
	{
		for(size_t i = 0; i < m_baseClassCount; ++i)
		{
			Metadata* res = m_baseClasses[i].m_type->_findMember_(name, includeBaseClasses);
			if(0 != res)
			{
				return res;
			}
		}
	}
	return 0;
}

Metadata* ClassType::findMember(const char* name, bool includeBaseClasses)
{
	return _findMember_(name, includeBaseClasses);
}

Metadata* ClassType::findClassMember(const char* name, bool includeBaseClasses)
{
	Type* type = findNestedType(name, false);
	if (0 != type)
	{
		return type;
	}
	TypeAlias* typeAlias = findNestedTypeAlias(name, false);
	if (0 != typeAlias)
	{
		return typeAlias;
	}
	StaticField* field = findStaticField(name, false);
	if(0 != field)
	{
		return field;
	}
	StaticProperty* prop = findStaticProperty(name, false);
	if (0 != prop)
	{
		return prop;
	}
	StaticArrayProperty* arrayProp = findStaticArrayProperty(name, false);
	if (0 != arrayProp)
	{
		return arrayProp;
	}
	StaticMethod* method = findStaticMethod(name, false);
	if(0 != method)
	{
		return method;
	}
	InstanceMethod* instanceMethod = findInstanceMethod(name, false);
	if(0 != instanceMethod)
	{
		return instanceMethod;
	}
	if(includeBaseClasses)
	{
		for(size_t i = 0; i < m_baseClassCount; ++i)
		{
			Metadata* res = m_baseClasses[i].m_type->findClassMember(name, includeBaseClasses);
			if(0 != res)
			{
				return res;
			}
		}
	}
	return 0;
}



Metadata* ClassType::findMember(const char* name)
{
	return _findMember_(name, true);
}

void* ClassType::createSubclassProxy(SubclassInvoker* subclassInvoker)
{
	return 0;
}

void ClassType::destroySubclassProxy(void* subclassProxy)
{}

size_t ClassType::_getMemberCount_(bool includeBaseClasses)
{
	size_t count = m_memberCount;
	if(includeBaseClasses)
	{
		for(size_t i = 0; i < m_baseClassCount; ++i)
		{
			count += m_baseClasses[i].m_type->_getMemberCount_(includeBaseClasses);
		}
	}
	return count;
}
	
Metadata* ClassType::_getMember_(size_t index, bool includeBaseClasses)
{
	if(includeBaseClasses)
	{
		if(index < m_memberCount)
		{
			return m_members[index];
		}
		else
		{
			index -= m_memberCount;
			for(size_t i = 0; i < m_baseClassCount; ++i)
			{
				size_t baseMemberCount = m_baseClasses[i].m_type->_getMemberCount_(includeBaseClasses);
				if(index < baseMemberCount)
				{
					return m_baseClasses[i].m_type->_getMember_(index, includeBaseClasses);
				}
				index -= baseMemberCount;
			}
			return 0;
		}
	}
	else
	{
		if(index < m_memberCount)
		{
			return m_members[index];
		}
		return 0;
	}
}

size_t ClassType::_getBaseClassCount_()
{
	return m_baseClassCount;
}

Metadata* ClassType::_getBaseClass_(size_t index)
{
	if(index < m_baseClassCount)
	{
		return m_baseClasses[index].m_type;
	}
	return 0;
}

bool ClassType::getClassOffset_(size_t& offset, ClassType* otherType)
{
	if(this == otherType)
	{
		return true;
	}
	size_t curOffset = offset;
	for(size_t i = 0; i < m_baseClassCount; ++i)
	{
		offset = curOffset + m_baseClasses[i].m_offset;
		if(m_baseClasses[i].m_type->getClassOffset_(offset, otherType))
		{
			return true;
		}
	}
	return false;
}

bool ClassType::getClassOffset(size_t& offset, ClassType* otherType)
{
	offset = 0;
	return getClassOffset_(offset, otherType);
}

ClassTypeIterator* ClassType::_getFirstDerivedClass_()
{
	return m_firstDerivedClass;
}

size_t ClassType::_getInstancePropertyCount_(bool includeBaseClasses)
{
	size_t count = m_instancePropertyCount;
	if (includeBaseClasses)
	{
		for (size_t i = 0; i < m_baseClassCount; ++i)
		{
			count += m_baseClasses[i].m_type->_getInstancePropertyCount_(includeBaseClasses);
		}
	}
	return count;
}

InstanceProperty* ClassType::_getInstanceProperty_(size_t index, bool includeBaseClasses)
{
	if (includeBaseClasses)
	{
		if (index < m_instancePropertyCount)
		{
			return &m_instanceProperties[index];
		}
		else
		{
			index -= m_instancePropertyCount;
			for (size_t i = 0; i < m_baseClassCount; ++i)
			{
				size_t baseMemberCount = m_baseClasses[i].m_type->_getInstancePropertyCount_(includeBaseClasses);
				if (index < baseMemberCount)
				{
					return m_baseClasses[i].m_type->_getInstanceProperty_(index, includeBaseClasses);
				}
				index -= baseMemberCount;
			}
			return 0;
		}
	}
	else
	{
		if (index < m_instancePropertyCount)
		{
			return &m_instanceProperties[index];
		}
		return 0;
	}
}

size_t ClassType::_getInstanceArrayPropertyCount_(bool includeBaseClasses)
{
	size_t count = m_instanceArrayPropertyCount;
	if (includeBaseClasses)
	{
		for (size_t i = 0; i < m_baseClassCount; ++i)
		{
			count += m_baseClasses[i].m_type->_getInstanceArrayPropertyCount_(includeBaseClasses);
		}
	}
	return count;
}

InstanceArrayProperty* ClassType::_getInstanceArrayProperty_(size_t index, bool includeBaseClasses)
{
	if (includeBaseClasses)
	{
		if (index < m_instanceArrayPropertyCount)
		{
			return &m_instanceArrayProperties[index];
		}
		else
		{
			index -= m_instanceArrayPropertyCount;
			for (size_t i = 0; i < m_baseClassCount; ++i)
			{
				size_t baseMemberCount = m_baseClasses[i].m_type->_getInstanceArrayPropertyCount_(includeBaseClasses);
				if (index < baseMemberCount)
				{
					return m_baseClasses[i].m_type->_getInstanceArrayProperty_(index, includeBaseClasses);
				}
				index -= baseMemberCount;
			}
			return 0;
		}
	}
	else
	{
		if (index < m_instanceArrayPropertyCount)
		{
			return &m_instanceArrayProperties[index];
		}
		return 0;
	}
}

bool ClassType::isType(ClassType* otherType)
{
	if (this == otherType)
	{
		return true;
	}
	for (size_t i = 0; i < m_baseClassCount; ++i)
	{
		if (m_baseClasses[i].m_type->isType(otherType))
		{
			return true;
		}
	}
	return false;
}

END_PAFCORE