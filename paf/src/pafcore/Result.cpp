#include "Result.h"
#include "Result.mh"
#include "Result.ic"
#include "Result.mc"

BEGIN_PAFCORE

Result::Result(Type* type, bool constant, Passing passing)
: Metadata(0)
{
	m_type = type;
	m_constant = constant;
	m_passing = passing;
}

bool Result::get_isConstant() const
{
	return m_constant;
}

Type* Result::get_type() const
{
	return m_type;
}

bool Result::get_byValue() const
{
	return by_value == m_passing;
}
bool Result::get_byRef() const
{
	return by_ref == m_passing;
}
bool Result::get_byPtr() const
{
	return by_ptr == m_passing;
}

bool Result::get_byNew() const
{
	return by_new == m_passing;
}

bool Result::get_byNewArray() const
{
	return by_new_array == m_passing;
}

END_PAFCORE