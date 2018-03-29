#include "Type.h"
#include "Type.mh"
#include "Type.ic"
#include "Type.mc"
#include "NameSpace.h"

BEGIN_PAFCORE

Type::Type(const char* name, Category category) : 
	Metadata(name),
	m_category(category),
	m_size(0),
	m_enclosing(0)
{
}

Type::~Type()
{
	if (m_enclosing && name_space == m_enclosing->get__category_())
	{
		static_cast<NameSpace*>(m_enclosing)->unregisterMember(this);
	}
}

void Type::destroyInstance(void* address)
{
}

void Type::destroyArray(void* address)
{
}

void Type::assign(void* dst, const void* src)
{
}

//Metadata* Type::findMember(const char* name)
//{
//	return 0;
//}

//Metadata* Type::findTypeMember(const char* name)
//{
//	return 0;
//}

END_PAFCORE