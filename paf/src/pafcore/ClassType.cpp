#include "ClassType.h"
#include "ClassType.mh"
#include "ClassType.ic"
#include "ClassType.mc"
#include "Variant.h"
#include "InstanceField.h"
#include "InstanceProperty.h"
#include "InstanceMethod.h"
#include "StaticField.h"
#include "StaticProperty.h"
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
	m_instanceMethods = 0;
	m_instanceMethodCount = 0;
	m_staticFields = 0;
	m_staticFieldCount = 0;
	m_staticProperties = 0;
	m_staticPropertyCount = 0;
	m_staticMethods = 0;
	m_staticMethodCount = 0;
	m_classTypeIterators = 0;
	m_firstDerivedClass = 0;
}

Type* ClassType::findNestedType(const char* name, bool includeBaseClasses, bool typeAliasToType)
{
	Metadata dummy(name);
	Type** it = std::lower_bound(m_nestedTypes, m_nestedTypes + m_nestedTypeCount, &dummy, CompareMetaDataPtrByName());
	if (m_nestedTypes + m_nestedTypeCount != it && strcmp(name, (*it)->m_name) == 0)
	{
		return *it;
	}
	if (typeAliasToType)
	{
		TypeAlias** it = std::lower_bound(m_nestedTypeAliases, m_nestedTypeAliases + m_nestedTypeAliasCount, &dummy, CompareMetaDataPtrByName());
		if (m_nestedTypeAliases + m_nestedTypeAliasCount != it && strcmp(name, (*it)->m_name) == 0)
		{
			return (*it)->m_type;
		}
	}
	if(includeBaseClasses)
	{
		for(size_t i = 0; i < m_baseClassCount; ++i)
		{
			Type* res = m_baseClasses[i].m_type->findNestedType(name, includeBaseClasses, typeAliasToType);
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
	Metadata* member = _findMember_(name, includeBaseClasses);
	if (member && instance_field == member->get__category_())
	{
		return static_cast<InstanceField*>(member);
	}
	return 0;
}

StaticField* ClassType::findStaticField(const char* name, bool includeBaseClasses)
{
	Metadata* member = _findMember_(name, includeBaseClasses);
	if (member && static_field == member->get__category_())
	{
		return static_cast<StaticField*>(member);
	}
	return 0;
	/*
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
	*/
}

InstanceProperty* ClassType::findInstanceProperty(const char* name, bool includeBaseClasses)
{
	Metadata* member = _findMember_(name, includeBaseClasses);
	if (member && instance_property == member->get__category_())
	{
		return static_cast<InstanceProperty*>(member);
	}
	return 0;
	/*
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
	*/
}

StaticProperty* ClassType::findStaticProperty(const char* name, bool includeBaseClasses)
{
	Metadata* member = _findMember_(name, includeBaseClasses);
	if (member && static_property == member->get__category_())
	{
		return static_cast<StaticProperty*>(member);
	}
	return 0;
	/*
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
	*/
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

Metadata* ClassType::findMember(const char* name, bool includeBaseClasses, bool typeAliasToType)
{
	Metadata* member = _findMember_(name, includeBaseClasses);
	if (0 != member && typeAliasToType && member->get__category_() == type_alias)
	{
		member = static_cast<TypeAlias*>(member)->m_type;
	}
	return member;
}

Metadata* ClassType::findClassMember(const char* name, bool includeBaseClasses, bool typeAliasToType)
{
	Type* type = findNestedType(name, false, false);
	if (0 != type)
	{
		return type;
	}
	TypeAlias* typeAlias = findNestedTypeAlias(name, false);
	if (0 != typeAlias)
	{
		if (typeAliasToType)
		{
			return typeAlias->m_type;
		}
		else
		{
			return typeAlias;
		}
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
			Metadata* res = m_baseClasses[i].m_type->findClassMember(name, includeBaseClasses, typeAliasToType);
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
	return findMember(name, true, true);
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
		InstanceProperty* res = getInstanceProperty_(index);
		return res;
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

InstanceProperty* ClassType::getInstanceProperty_(size_t& index)//派生property在前
{
	if (index < m_instancePropertyCount)
	{
		return &m_instanceProperties[index];
	}
	index -= m_instancePropertyCount;
	for (size_t i = 0; i < m_baseClassCount; ++i)
	{
		InstanceProperty* res = m_baseClasses[i].m_type->getInstanceProperty_(index);
		if (res)
		{
			return res;
		}
	}
	return 0;
}

InstanceProperty* ClassType::getInstancePropertyBaseClassFirst_(size_t& index)//基类property在前
{
	for (size_t i = 0; i < m_baseClassCount; ++i)
	{
		InstanceProperty* res = m_baseClasses[i].m_type->getInstancePropertyBaseClassFirst_(index);
		if (res)
		{
			return res;
		}
	}
	if (index < m_instancePropertyCount)
	{
		return &m_instanceProperties[index];
	}
	index -= m_instancePropertyCount;
	return 0;
}

size_t ClassType::_getInstanceFieldCount_(bool includeBaseClasses)
{
	size_t count = m_instanceFieldCount;
	if (includeBaseClasses)
	{
		for (size_t i = 0; i < m_baseClassCount; ++i)
		{
			count += m_baseClasses[i].m_type->_getInstanceFieldCount_(includeBaseClasses);
		}
	}
	return count;
}

InstanceField* ClassType::_getInstanceField_(size_t index, bool includeBaseClasses)
{
	if (includeBaseClasses)
	{
		InstanceField* res = getInstanceField_(index);
		return res;
	}
	else
	{
		if (index < m_instanceFieldCount)
		{
			return &m_instanceFields[index];
		}
		return 0;
	}
}

InstanceField* ClassType::getInstanceField_(size_t& index)//派生property在前
{
	if (index < m_instanceFieldCount)
	{
		return &m_instanceFields[index];
	}
	index -= m_instanceFieldCount;
	for (size_t i = 0; i < m_baseClassCount; ++i)
	{
		InstanceField* res = m_baseClasses[i].m_type->getInstanceField_(index);
		if (res)
		{
			return res;
		}
	}
	return 0;
}

InstanceField* ClassType::getInstanceFieldBaseClassFirst_(size_t& index)
{
	for (size_t i = 0; i < m_baseClassCount; ++i)
	{
		InstanceField* res = m_baseClasses[i].m_type->getInstanceFieldBaseClassFirst_(index);
		if (res)
		{
			return res;
		}
	}
	if (index < m_instanceFieldCount)
	{
		return &m_instanceFields[index];
	}
	index -= m_instanceFieldCount;
	return 0;
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