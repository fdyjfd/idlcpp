#include "InstanceField.h"
#include "InstanceField.mh"
#include "InstanceField.ic"
#include "InstanceField.mc"

BEGIN_PAFCORE

InstanceField::InstanceField(const char* name, ClassType* objectType, Type* type, size_t offset, size_t arraySize, bool constant, TypeCompound tc)
: Metadata(name)
{
	m_objectType = objectType;
	m_type = type;
	m_offset = offset;
	m_arraySize = arraySize;
	m_constant = constant;
	m_typeCompound = tc;
}

Type* InstanceField::get_type()
{
	return m_type;
}

ClassType* InstanceField::get_objectType()
{
	return m_objectType;
}

bool InstanceField::get_isArray()
{
	return tc_array == m_typeCompound;
}

bool InstanceField::get_isPointer()
{
	return tc_pointer == m_typeCompound;
}

bool InstanceField::get_isConstant()
{
	return m_constant;
}

size_t InstanceField::get_offset()
{
	return m_offset;
}


END_PAFCORE
