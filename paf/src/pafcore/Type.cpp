#include "Type.h"
#include "Type.mh"
#include "Type.ic"
#include "Type.mc"

BEGIN_PAFCORE

Type::Type(const char* name, Category category)
: Metadata(name)
{
	m_category = category;
	m_size = 0;
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