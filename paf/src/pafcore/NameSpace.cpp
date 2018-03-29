#include "NameSpace.h"
#include "NameSpace.mh"
#include "NameSpace.ic"
#include "NameSpace.mc"
#include "Metadata.h"
#include "Type.h"
#include "String.h"
#include <vector>
#include <assert.h>

BEGIN_PAFCORE

size_t NameSpace::Hash_Metadata::operator ()(const Metadata* metadata) const
{
	return StringToHash(metadata->m_name);
}

bool NameSpace::Equal_Metadata::operator() (const Metadata* lhs, const Metadata* rhs) const
{
	return (0 == strcmp(lhs->m_name, rhs->m_name));
};

NameSpace::NameSpace(const char* name) : 
	Metadata(name),
	m_enclosing(0)
{
}

NameSpace::~NameSpace()
{
	auto it = m_members.begin();
	auto end = m_members.end();
	for (; it != end; ++it)
	{
		Metadata* member = *it;
		Category category = member->get__category_();
		switch (category)
		{
		case name_space:
			PAF_ASSERT(static_cast<NameSpace*>(member)->m_enclosing == this);
			delete static_cast<NameSpace*>(member);
			break;
		case type_alias:
			PAF_ASSERT(static_cast<TypeAlias*>(member)->m_enclosing == this);
			static_cast<TypeAlias*>(member)->m_enclosing = 0;
			break;
		default:
			PAF_ASSERT(void_type == category || primitive_type == category || enum_type == category || class_type == category);
			PAF_ASSERT(static_cast<Type*>(member)->m_enclosing == this);
			static_cast<Type*>(member)->m_enclosing = 0;
		}
	}
}

NameSpace* NameSpace::getNameSpace(const char* name)
{
	char buffer[sizeof(Metadata)];
	Metadata* fakeMetadata = (Metadata*)buffer;
	fakeMetadata->m_name = name;
	NameSpace* subNameSpace = 0;
	if(0 != this)
	{
		auto it = m_members.find(fakeMetadata);
		if(m_members.end() == it)
		{
			subNameSpace = paf_new NameSpace(name);
			m_members.insert(subNameSpace);
			subNameSpace->m_enclosing = this;
		}
		else
		{
			Metadata* member = *it;
			if(name_space == member->get__category_())
			{
				subNameSpace = static_cast<NameSpace*>(member);
				PAF_ASSERT(this == subNameSpace->m_enclosing);
			}
		}
	}
	return subNameSpace;
}

ErrorCode NameSpace::registerMember(Metadata* member)
{
	if(0 == this)
	{
		return e_invalid_namespace;
	}
	Category category = member->get__category_();
	if (type_alias == category)
	{
		static_cast<TypeAlias*>(member)->m_enclosing = this;
	}
	else
	{
		PAF_ASSERT(void_type == category || primitive_type == category || enum_type == category || class_type == category);
		static_cast<Type*>(member)->m_enclosing = this;
	}
	return m_members.insert(member).second ? s_ok : e_name_conflict;
}

void NameSpace::unregisterMember(Metadata* metadata)
{
	m_members.erase(metadata);
}


Metadata* NameSpace::_findMember_(const char* name)
{
	Metadata* member = 0;
	char buffer[sizeof(Metadata)];
	Metadata* fakeMetadata = (Metadata*)buffer;
	fakeMetadata->m_name = name;
	auto it = m_members.find(fakeMetadata);
	if (m_members.end() != it)
	{
		member = *it;
	}
	return member;
}

size_t NameSpace::_getMemberCount_()
{
	return m_members.size();
}

Metadata* NameSpace::_getMember_(size_t index)
{
	if (index < m_members.size())
	{
		auto it = m_members.begin();
		std::advance(it, index);
		return *it;
	}
	else
	{
		return 0;
	}
}

Metadata* NameSpace::findMember(const char * name)
{
	Metadata* member = _findMember_(name);
	if(0 != member)
	{
		if(member->get__category_() == type_alias)
		{
			member = static_cast<TypeAlias*>(member)->m_type;
		}
	}
	return member;
}

NameSpace* NameSpace::GetGlobalNameSpace()
{
	static NameSpace s_globalNameSpace("");
	return &s_globalNameSpace;
}

END_PAFCORE
