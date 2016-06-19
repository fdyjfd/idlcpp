#include "Overload.h"
#include "Argument.h"
#include "Variant.h"
#include "Type.h"
#include "PrimitiveType.h"
#include "ClassType.h"
#include <assert.h>

BEGIN_PAFCORE

Overload::Overload(Result* result, Argument* args, size_t argCount)
{
	m_result = result;
	m_args = args;
	m_argCount = argCount;
}

const char nm = no_match;
const char tc = type_conversion;
const char tp = type_promotion;
const char em = exact_match;
const char m1 = sizeof(unsigned short) < sizeof(int) ? tp : tc;
const char m2 = sizeof(unsigned short) < sizeof(int) ? tc : tp;

char g_primitiveArgumentMatchTable[primitive_type_count][primitive_type_count] =
{
	{ em, tc, tc, tc, tc, tc, tc, tc, tc, tc, tc, tc, tc, tc, tc, tc },//bool
	{ tc, em, tc, tc, tc, tc, tc, tc, tc, tc, tc, tc, tc, tc, tc, tc },//char
	{ tc, tc, em, tc, tc, tc, tc, tc, tc, tc, tc, tc, tc, tc, tc, tc },//signed char
	{ tc, tc, tc, em, tc, tc, tc, tc, tc, tc, tc, tc, tc, tc, tc, tc },//unsigned char
	{ tc, tc, tc, tc, em, tc, tc, tc, tc, tc, tc, tc, tc, tc, tc, tc },//wchar_t
	{ tc, tc, tc, tc, tc, em, tc, tc, tc, tc, tc, tc, tc, tc, tc, tc },//short
	{ tc, tc, tc, tc, tc, tc, em, tc, tc, tc, tc, tc, tc, tc, tc, tc },//unsigned short
	{ tp, tp, tp, tp, tp, tp, m1, em, tc, tc, tc, tc, tc, tc, tc, tc },//int
	{ tc, tc, tc, tc, tc, tc, m2, tc, em, tc, tc, tc, tc, tc, tc, tc },//unsigned int
	{ tc, tc, tc, tc, tc, tc, tc, tc, tc, em, tc, tc, tc, tc, tc, tc },//long
	{ tc, tc, tc, tc, tc, tc, tc, tc, tc, tc, em, tc, tc, tc, tc, tc },//unsigned long
	{ tc, tc, tc, tc, tc, tc, tc, tc, tc, tc, tc, em, tc, tc, tc, tc },//long long
	{ tc, tc, tc, tc, tc, tc, tc, tc, tc, tc, tc, tc, em, tc, tc, tc },//unsigned long long
	{ tc, tc, tc, tc, tc, tc, tc, tc, tc, tc, tc, tc, tc, em, tc, tc },//float
	{ tc, tc, tc, tc, tc, tc, tc, tc, tc, tc, tc, tc, tc, tp, em, tc },//double
	{ tc, tc, tc, tc, tc, tc, tc, tc, tc, tc, tc, tc, tc, tc, tc, em },//long double
};

inline ArgumentMatch MatchPrimitive(PrimitiveTypeCategory dst, PrimitiveTypeCategory src)
{
	return static_cast<ArgumentMatch>(g_primitiveArgumentMatchTable[dst][src]);
}

ArgumentMatch MatchArgumentByPassingValue(Type* dstType, Type* srcType)
{
	switch (dstType->m_category)
	{
	case primitive_object:
		switch (srcType->m_category)
		{
		case primitive_object:
			return MatchPrimitive(static_cast<PrimitiveType*>(dstType)->m_typeCategory, static_cast<PrimitiveType*>(srcType)->m_typeCategory);
		case enum_object:
			return int_type == static_cast<PrimitiveType*>(dstType)->m_typeCategory ? type_promotion : type_conversion;
		default:
			return no_match;
		}
	case enum_object:
		switch (srcType->m_category)
		{
		case primitive_object:
			return type_conversion;
		case enum_object:
			return dstType == srcType ? exact_match : no_match;
		default:
			return no_match;
		}
	case value_object:
		if (dstType == srcType)
		{
			return exact_match;
		}
		else if (value_object == srcType->m_category &&
			static_cast<ClassType*>(srcType)->isType(static_cast<ClassType*>(dstType)))
		{
			return type_conversion;
		}
		else
		{
			return no_match;
		}
	default:
		assert(void_object != dstType->m_category);
		if (dstType == srcType)
		{
			return exact_match;
		}
		else if (dstType->m_category == srcType->m_category &&
			static_cast<ClassType*>(srcType)->isType(static_cast<ClassType*>(dstType)))
		{
			return type_conversion;
		}
		else
		{
			return no_match;
		}
	}
}

ArgumentMatch MatchArgumentByPassingPtr(Type* dstType, Type* srcType)
{
	switch (dstType->m_category)
	{
	case void_object:
		return dstType == srcType ? exact_match : type_conversion;
	case primitive_object:
	case enum_object:
		return dstType == srcType ? exact_match : no_match;
	case value_object:
		if (dstType == srcType)
		{
			return exact_match;
		}
		else if(value_object == srcType->m_category &&
			static_cast<ClassType*>(srcType)->isType(static_cast<ClassType*>(dstType)))
		{
			return type_conversion;
		}
		else
		{
			return no_match;
		}
	default:
		if (dstType == srcType)
		{
			return exact_match;
		}
		else if (dstType->m_category == srcType->m_category &&
			static_cast<ClassType*>(srcType)->isType(static_cast<ClassType*>(dstType)))
		{
			return type_conversion;
		}
		else
		{
			return no_match;
		}
	}
};


bool Overload::matchArguments(char* matches, Variant** variants)
{
	for (size_t i = 0; i < m_argCount; ++i)
	{
		ArgumentMatch match;
		switch (m_args[i].m_passing)
		{
		case Argument::by_value:
			match = MatchArgumentByPassingValue(m_args[i].m_type, variants[i]->m_type);
			break;
		case Argument::by_ref:
			if (m_args[i].m_constant)
			{
				match = MatchArgumentByPassingValue(m_args[i].m_type, variants[i]->m_type);
				if (exact_match == match && !variants[i]->m_constant)
				{
					match = const_transformation;
				}
			}
			else if(variants[i]->m_constant)
			{
				return false;
			}
			else
			{
				match = MatchArgumentByPassingPtr(m_args[i].m_type, variants[i]->m_type);
			}
			break;
		case Argument::by_ptr:
			if (!m_args[i].m_constant && variants[i]->m_constant)
			{
				return false;
			}
			match  = MatchArgumentByPassingPtr(m_args[i].m_type, variants[i]->m_type);
			if(exact_match == match && m_args[i].m_constant && !variants[i]->m_constant)
			{
				match = const_transformation;
			}
			break;
		default:
			match = exact_match;
			break;
		}
		if (no_match == match)
		{
			return false;
		}
		matches[i] = match;
	}
	return true;
}

size_t Overload::Resolution(Overload* overloads, Variant** variants, size_t argCount, size_t overloadCount, size_t* candidates, char* argMatches)
{
	size_t candidateCount = 0;
	for (size_t i = 0; i < overloadCount; ++i)
	{
		assert(argCount == overloads[i].m_argCount);
		if (overloads[i].matchArguments(&argMatches[i*argCount], variants))
		{
			candidates[candidateCount] = i;
			++candidateCount;
		}
	}
	if (0 == candidateCount)
	{
		size_t error_no_match = overloadCount;
		return error_no_match;
	}
	else if (1 == candidateCount)
	{
		return candidates[0];
	}
	assert(candidateCount <= sizeof(size_t) * 8);
	
	size_t candidateMask = (1 << candidateCount) - 1;
	for (size_t i = 0; i < argCount; ++i)
	{
		char bestMatch = type_conversion;
		for (size_t j = 0; j < candidateCount; ++j)
		{
			char match = argMatches[candidates[j] * argCount + i];
			if (bestMatch < match)
			{
				bestMatch = match;
			}
		}
		if (bestMatch != type_conversion)
		{
			for (size_t j = 0; j < candidateCount; ++j)
			{
				char match = argMatches[candidates[j] * argCount + i];
				if (match != bestMatch)
				{
					candidateMask &= ~(1 << j);
				}
			}
		}
	}
	size_t index = 0;
	size_t value = 1;
	while (value <= candidateMask)
	{
		if (value == candidateMask)
		{
			return candidates[index];
		}
		++index;
		value = 1 << index;
	}
	size_t error_ambiguous = overloadCount + 1;
	return error_ambiguous;
}


END_PAFCORE