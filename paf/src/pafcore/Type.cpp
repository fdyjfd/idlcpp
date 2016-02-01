#include "Type.h"
#include "Variant.h"
#include "InstanceField.h"
#include "InstanceProperty.h"
#include "InstanceMethod.h"
#include "StaticField.h"
#include "StaticProperty.h"
#include "StaticMethod.h"
#include "Type.mh"
#include "Type.ic"
#include "Type.mc"
#include <algorithm>
#include <assert.h>

BEGIN_PAFCORE

Type::Type(const char* name, Category category)
: Metadata(name)
{
	m_category = category;
	m_size = 0;
}

void Type::destroyInstance(void* address)
{
	assert(false);
}

void Type::destroyArray(void* address)
{
	assert(false);
}

void Type::assign(void* dst, const void* src)
{
	assert(false);
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