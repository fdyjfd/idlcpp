#include "Argument.h"
#include "Argument.mh"
#include "Argument.ic"
#include "Argument.mc"

BEGIN_PAFCORE

Argument::Argument(const char* name, Type* type, Passing passing, bool constant)
: Metadata(name)
{
	m_type = type;
	m_passing = passing;
	m_constant = constant;
}

Type* Argument::get_type() const
{
	return m_type;
}

bool Argument::get_byValue() const
{
	return by_value == m_passing;
}

bool Argument::get_byRef() const
{
	return by_ref == m_passing;
}

bool Argument::get_byPtr() const
{
	return by_ptr == m_passing;
}

bool Argument::get_byOutPtr() const
{
	return by_out_ptr == m_passing;
}

bool Argument::get_byOutRef() const
{
	return by_out_ref == m_passing;
}

bool Argument::get_byNewPtr() const
{
	return by_new_ptr == m_passing;
}

bool Argument::get_byNewRef() const
{
	return by_new_ref == m_passing;
}

bool Argument::get_byNewArrayPtr() const
{
	return by_new_array_ptr == m_passing;
}

bool Argument::get_byNewArrayRef() const
{
	return by_new_array_ref == m_passing;
}

bool Argument::get_isConstant() const
{
	return m_constant;
}


END_PAFCORE