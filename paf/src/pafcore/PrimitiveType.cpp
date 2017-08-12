#include "PrimitiveType.h"
#include "PrimitiveType.mh"
#include "PrimitiveType.ic"
#include "PrimitiveType.mc"
#include "TypeAlias.h"
#include "AutoRun.h"
#include <assert.h>
#include <algorithm>

BEGIN_PAFCORE

size_t PrimitiveType::_getMemberCount_()
{
	return m_memberCount;
}

Metadata* PrimitiveType::_getMember_(size_t index)
{
	if (index < m_memberCount)
	{
		return m_members[index];
	}
	return 0;
}

Metadata* PrimitiveType::_findMember_(const char* name)
{
	Metadata dummy(name);
	Metadata** it = std::lower_bound(m_members, m_members + m_memberCount, &dummy, CompareMetaDataPtrByName());
	if (m_members + m_memberCount != it && strcmp(name, (*it)->m_name) == 0)
	{
		return *it;
	}
	return 0;
}

Metadata* PrimitiveType::findMember(const char* name)
{
	return _findMember_(name);
}

InstanceMethod* PrimitiveType::findInstanceMethod(const char* name)
{
	Metadata dummy(name);
	InstanceMethod* res = std::lower_bound(m_instanceMethods, m_instanceMethods + m_instanceMethodCount, dummy);
	if (m_instanceMethods + m_instanceMethodCount != res && strcmp(name, res->m_name) == 0)
	{
		return res;
	}
	return 0;
}

StaticMethod* PrimitiveType::findStaticMethod(const char* name)
{
	Metadata dummy(name);
	StaticMethod* res = std::lower_bound(m_staticMethods, m_staticMethods + m_staticMethodCount, dummy);
	if (m_staticMethods + m_staticMethodCount != res && strcmp(name, res->m_name) == 0)
	{
		return res;
	}
	return 0;
}

Metadata* PrimitiveType::findTypeMember(const char* name)
{
	return findStaticMethod(name);
}

template<bool short_less_int>
struct TypePromoter
{
	static PrimitiveTypeCategory GetPromotedTypeCategory(PrimitiveTypeCategory typeCategory)
	{
		if (typeCategory <= unsigned_short_type)
		{
			return int_type;
		}
		return typeCategory;
	}
};

template<>
struct TypePromoter<false>
{
	static PrimitiveTypeCategory GetPromotedTypeCategory(PrimitiveTypeCategory typeCategory)
	{
		if (typeCategory < unsigned_short_type)
		{
			return int_type;
		}
		else if (typeCategory == unsigned_short_type)
		{
			return unsigned_int_type;
		}
		return typeCategory;
	}
};

inline PrimitiveTypeCategory GetPromotedTypeCategory(PrimitiveTypeCategory typeCategory)
{
	return TypePromoter<sizeof(unsigned short) < sizeof(int)>::GetPromotedTypeCategory(typeCategory);
}

inline PrimitiveTypeCategory GetPromotedTypeCategory(PrimitiveTypeCategory typeCategory1, PrimitiveTypeCategory typeCategory2)
{
	PrimitiveTypeCategory small, large; 
	if(typeCategory1 < typeCategory2)
	{
		small = typeCategory1;
		large = typeCategory2;
	}
	else
	{
		small = typeCategory2;
		large = typeCategory1;
	}
	if(unsigned_int_type == small && long_type == large)
	{
		return unsigned_long_type;
	}
	return GetPromotedTypeCategory(large);
}

PrimitiveType* GetPrimitiveTypeFromTypeCategory(PrimitiveTypeCategory typeCategory)
{
	PrimitiveType* res = 0;
	switch(typeCategory)
	{
	case bool_type:
		res = BoolType::GetSingleton();
		break;
	case char_type:
		res = CharType::GetSingleton();
		break;
	case signed_char_type:
		res = SignedCharType::GetSingleton();
		break;
	case unsigned_char_type:
		res = UnsignedCharType::GetSingleton();
		break;
	case wchar_type:
		res = WcharType::GetSingleton();
		break;
	case short_type:
		res = ShortType::GetSingleton();
		break;
	case unsigned_short_type:
		res = UnsignedShortType::GetSingleton();
		break;
	case int_type:
		res = IntType::GetSingleton();
		break;
	case unsigned_int_type:
		res = UnsignedIntType::GetSingleton();
		break;
	case long_type:
		res = LongType::GetSingleton();
		break;
	case unsigned_long_type:
		res = UnsignedLongType::GetSingleton();
		break;
	case long_long_type:
		res = LongLongType::GetSingleton();
		break;
	case unsigned_long_long_type:
		res = UnsignedLongLongType::GetSingleton();
		break;
	case float_type:
		res = FloatType::GetSingleton();
		break;
	case double_type:
		res = DoubleType::GetSingleton();
		break;
	case long_double_type:
		res = LongDoubleType::GetSingleton();
		break;
	default:
		assert(false);
	}
	return res;
}

ErrorCode PrimitiveType::Primitive_op_plus(Variant* result, Variant** args, int_t numArgs)
{
	if(1 == numArgs)
	{
		if(!args[0]->m_type->isPrimitive())
		{
			return e_invalid_this_type;
		}
		PrimitiveType* arg0Type = static_cast<PrimitiveType*>(args[0]->m_type);
		PrimitiveTypeCategory resTypeCategory = GetPromotedTypeCategory(arg0Type->m_typeCategory);
		PrimitiveType* resType = GetPrimitiveTypeFromTypeCategory(resTypeCategory);

		char value0[max_primitive_type_size];
		char resultValue[max_primitive_type_size];
		arg0Type->castTo(value0, resType, args[0]->m_pointer);
		resType->op_plus(resultValue, value0);
		result->assignPrimitive(resType, resultValue);
		return s_ok;
	}
	return e_invalid_arg_num;
}

ErrorCode PrimitiveType::Primitive_op_negate(Variant* result, Variant** args, int_t numArgs)
{
	if(1 == numArgs)
	{
		if(!args[0]->m_type->isPrimitive())
		{
			return e_invalid_this_type;
		}
		PrimitiveType* arg0Type = static_cast<PrimitiveType*>(args[0]->m_type);
		switch (arg0Type->m_typeCategory)
		{
		case unsigned_int_type:
		case unsigned_long_type:
		case unsigned_long_long_type:
			return e_invalid_this_type;
		}
		PrimitiveTypeCategory resTypeCategory = GetPromotedTypeCategory(arg0Type->m_typeCategory);
		PrimitiveType* resType = GetPrimitiveTypeFromTypeCategory(resTypeCategory);

		char value0[max_primitive_type_size];
		char resultValue[max_primitive_type_size];
		arg0Type->castTo(value0, resType, args[0]->m_pointer);
		resType->op_negate(resultValue, value0);
		result->assignPrimitive(resType, resultValue);
		return s_ok;
	}
	return e_invalid_arg_num;
}

ErrorCode PrimitiveType::Primitive_op_increment(Variant* result, Variant** args, int_t numArgs)
{
	if (1 == numArgs)
	{
		if (!args[0]->m_type->isPrimitive())
		{
			return e_invalid_this_type;
		}
		PrimitiveType* arg0Type = static_cast<PrimitiveType*>(args[0]->m_type);
		if (float_type <= arg0Type->m_typeCategory)
		{
			return e_invalid_this_type;
		}
		PrimitiveType* resType = arg0Type;
		char resultValue[max_primitive_type_size];
		resType->op_increment(resultValue, args[0]->m_pointer);
		result->assignPrimitivePtr(arg0Type, args[0]->m_pointer, false, ::pafcore::Variant::by_ref);
		return s_ok;
	}
	return e_invalid_arg_num;
}

ErrorCode PrimitiveType::Primitive_op_postIncrement(Variant* result, Variant** args, int_t numArgs)
{
	if (1 == numArgs)
	{
		if (!args[0]->m_type->isPrimitive())
		{
			return e_invalid_this_type;
		}
		PrimitiveType* arg0Type = static_cast<PrimitiveType*>(args[0]->m_type);
		if (float_type <= arg0Type->m_typeCategory)
		{
			return e_invalid_this_type;
		}
		PrimitiveType* resType = arg0Type;
		char resultValue[max_primitive_type_size];
		resType->op_postIncrement(resultValue, args[0]->m_pointer);
		result->assignPrimitive(resType, resultValue);
		return s_ok;
	}
	return e_invalid_arg_num;
}

ErrorCode PrimitiveType::Primitive_op_decrement(Variant* result, Variant** args, int_t numArgs)
{
	if (1 == numArgs)
	{
		if (!args[0]->m_type->isPrimitive())
		{
			return e_invalid_this_type;
		}
		PrimitiveType* arg0Type = static_cast<PrimitiveType*>(args[0]->m_type);
		if (bool_type == arg0Type->m_typeCategory  || float_type <= arg0Type->m_typeCategory)
		{
			return e_invalid_this_type;
		}
		PrimitiveType* resType = arg0Type;
		char resultValue[max_primitive_type_size];
		resType->op_decrement(resultValue, args[0]->m_pointer);
		result->assignPrimitivePtr(arg0Type, args[0]->m_pointer, false, ::pafcore::Variant::by_ref);
		return s_ok;
	}
	return e_invalid_arg_num;
}

ErrorCode PrimitiveType::Primitive_op_postDecrement(Variant* result, Variant** args, int_t numArgs)
{
	if (1 == numArgs)
	{
		if (!args[0]->m_type->isPrimitive())
		{
			return e_invalid_this_type;
		}
		PrimitiveType* arg0Type = static_cast<PrimitiveType*>(args[0]->m_type);
		if (bool_type == arg0Type->m_typeCategory || float_type <= arg0Type->m_typeCategory)
		{
			return e_invalid_this_type;
		}
		PrimitiveType* resType = arg0Type;
		char resultValue[max_primitive_type_size];
		resType->op_postDecrement(resultValue, args[0]->m_pointer);
		result->assignPrimitive(resType, resultValue);
		return s_ok;
	}
	return e_invalid_arg_num;
}

ErrorCode PrimitiveType::Primitive_op_not(Variant* result, Variant** args, int_t numArgs)
{
	if (1 == numArgs)
	{
		if (!args[0]->m_type->isPrimitive())
		{
			return e_invalid_this_type;
		}
		PrimitiveType* arg0Type = static_cast<PrimitiveType*>(args[0]->m_type);
		bool res = arg0Type->op_not(args[0]->m_pointer);
		result->assignPrimitive(BoolType::GetSingleton(), &res);
		return s_ok;
	}
	return e_invalid_arg_num;
}

ErrorCode PrimitiveType::Primitive_op_bitwiseNot(Variant* result, Variant** args, int_t numArgs)
{
	if (1 == numArgs)
	{
		if (!args[0]->m_type->isPrimitive())
		{
			return e_invalid_this_type;
		}
		PrimitiveType* arg0Type = static_cast<PrimitiveType*>(args[0]->m_type);
		if (float_type <= arg0Type->m_typeCategory)
		{
			return e_invalid_this_type;
		}
		PrimitiveTypeCategory resTypeCategory = GetPromotedTypeCategory(arg0Type->m_typeCategory);
		PrimitiveType* resType = GetPrimitiveTypeFromTypeCategory(resTypeCategory);
		char value0[max_primitive_type_size];
		char resultValue[max_primitive_type_size];
		arg0Type->castTo(value0, resType, args[0]->m_pointer);
		resType->op_bitwiseNot(resultValue, value0);
		result->assignPrimitive(resType, resultValue);
		return s_ok;
	}
	return e_invalid_arg_num;
}

template<typename Func>
inline ErrorCode Primitive_op_binary(Variant* result, Variant** args, int_t numArgs, Func func)
{
	if (2 == numArgs)
	{
		if (!args[0]->m_type->isPrimitive())
		{
			return e_invalid_this_type;
		}
		if (!args[1]->m_type->isPrimitive())
		{
			return e_invalid_arg_type_1;
		}
		PrimitiveType* arg0Type = static_cast<PrimitiveType*>(args[0]->m_type);
		PrimitiveType* arg1Type = static_cast<PrimitiveType*>(args[1]->m_type);
		PrimitiveTypeCategory resTypeCategory = GetPromotedTypeCategory(arg0Type->m_typeCategory, arg1Type->m_typeCategory);
		PrimitiveType* resType = GetPrimitiveTypeFromTypeCategory(resTypeCategory);

		char value0[max_primitive_type_size];
		char value1[max_primitive_type_size];
		char resultValue[max_primitive_type_size];

		arg0Type->castTo(value0, resType, args[0]->m_pointer);
		arg1Type->castTo(value1, resType, args[1]->m_pointer);
		(resType->*func)(resultValue, value0, value1);
		result->assignPrimitive(resType, resultValue);
		return s_ok;
	}
	return e_invalid_arg_num;
}

template<typename Func>
inline ErrorCode Primitive_op_binaryIntegerOnly(Variant* result, Variant** args, int_t numArgs, Func func)
{
	if (2 == numArgs)
	{
		if (!args[0]->m_type->isPrimitive())
		{
			return e_invalid_this_type;
		}
		if (!args[1]->m_type->isPrimitive())
		{
			return e_invalid_arg_type_1;
		}
		PrimitiveType* arg0Type = static_cast<PrimitiveType*>(args[0]->m_type);
		if(float_type <= arg0Type->m_typeCategory)
		{
			return e_invalid_this_type;
		}
		PrimitiveType* arg1Type = static_cast<PrimitiveType*>(args[1]->m_type);
		if(float_type <= arg1Type->m_typeCategory)
		{
			return e_invalid_arg_type_1;
		}
		PrimitiveTypeCategory resTypeCategory = GetPromotedTypeCategory(arg0Type->m_typeCategory, arg1Type->m_typeCategory);
		PrimitiveType* resType = GetPrimitiveTypeFromTypeCategory(resTypeCategory);

		char value0[max_primitive_type_size];
		char value1[max_primitive_type_size];
		char resultValue[max_primitive_type_size];

		arg0Type->castTo(value0, resType, args[0]->m_pointer);
		arg1Type->castTo(value1, resType, args[1]->m_pointer);
		(resType->*func)(resultValue, value0, value1);
		result->assignPrimitive(resType, resultValue);
		return s_ok;
	}
	return e_invalid_arg_num;
}

ErrorCode PrimitiveType::Primitive_op_add(Variant* result, Variant** args, int_t numArgs)
{
	return Primitive_op_binary(result, args, numArgs, &op_add);
}

ErrorCode PrimitiveType::Primitive_op_subtract(Variant* result, Variant** args, int_t numArgs)
{
	return Primitive_op_binary(result, args, numArgs, &op_subtract);
}

ErrorCode PrimitiveType::Primitive_op_multiply(Variant* result, Variant** args, int_t numArgs)
{
	return Primitive_op_binary(result, args, numArgs, &op_multiply);
}

ErrorCode PrimitiveType::Primitive_op_divide(Variant* result, Variant** args, int_t numArgs)
{
	return Primitive_op_binary(result, args, numArgs, &op_divide);
}

ErrorCode PrimitiveType::Primitive_op_mod(Variant* result, Variant** args, int_t numArgs)
{
	return Primitive_op_binaryIntegerOnly(result, args, numArgs, &op_mod);
}

ErrorCode PrimitiveType::Primitive_op_bitwiseAnd(Variant* result, Variant** args, int_t numArgs)
{
	return Primitive_op_binaryIntegerOnly(result, args, numArgs, &op_bitwiseAnd);
}

ErrorCode PrimitiveType::Primitive_op_bitwiseOr(Variant* result, Variant** args, int_t numArgs)
{
	return Primitive_op_binaryIntegerOnly(result, args, numArgs, &op_bitwiseOr);
}

ErrorCode PrimitiveType::Primitive_op_bitwiseXor(Variant* result, Variant** args, int_t numArgs)
{
	return Primitive_op_binaryIntegerOnly(result, args, numArgs, &op_bitwiseXor);
}

ErrorCode PrimitiveType::Primitive_op_leftShift(Variant* result, Variant** args, int_t numArgs)
{
	return Primitive_op_binaryIntegerOnly(result, args, numArgs, &op_leftShift);
}

ErrorCode PrimitiveType::Primitive_op_rightShift(Variant* result, Variant** args, int_t numArgs)
{
	return Primitive_op_binaryIntegerOnly(result, args, numArgs, &op_rightShift);
}



template<typename Func>
inline ErrorCode Primitive_op_compare(Variant* result, Variant** args, int_t numArgs, Func func)
{
	if (2 == numArgs)
	{
		if (!args[0]->m_type->isPrimitive())
		{
			return e_invalid_this_type;
		}
		if (!args[1]->m_type->isPrimitive())
		{
			return e_invalid_arg_type_1;
		}
		PrimitiveType* arg0Type = static_cast<PrimitiveType*>(args[0]->m_type);
		PrimitiveType* arg1Type = static_cast<PrimitiveType*>(args[1]->m_type);
		PrimitiveTypeCategory resTypeCategory = GetPromotedTypeCategory(arg0Type->m_typeCategory, arg1Type->m_typeCategory);
		PrimitiveType* resType = GetPrimitiveTypeFromTypeCategory(resTypeCategory);

		char value0[max_primitive_type_size];
		char value1[max_primitive_type_size];

		arg0Type->castTo(value0, resType, args[0]->m_pointer);
		arg1Type->castTo(value1, resType, args[1]->m_pointer);
		bool res = (resType->*func)(value0, value1);
		result->assignPrimitive(BoolType::GetSingleton(), &res);
		return s_ok;
	}
	return e_invalid_arg_num;
}

ErrorCode PrimitiveType::Primitive_op_less(Variant* result, Variant** args, int_t numArgs)
{
	return Primitive_op_compare(result, args, numArgs, &op_less);
}

ErrorCode PrimitiveType::Primitive_op_lessEqual(Variant* result, Variant** args, int_t numArgs)
{
	return Primitive_op_compare(result, args, numArgs, &op_lessEqual);
}

ErrorCode PrimitiveType::Primitive_op_equal(Variant* result, Variant** args, int_t numArgs)
{
	return Primitive_op_compare(result, args, numArgs, &op_equal);
}

ErrorCode PrimitiveType::Primitive_op_notEqual(Variant* result, Variant** args, int_t numArgs)
{
	return Primitive_op_compare(result, args, numArgs, &op_notEqual);
}

ErrorCode PrimitiveType::Primitive_op_greaterEqual(Variant* result, Variant** args, int_t numArgs)
{
	return Primitive_op_compare(result, args, numArgs, &op_greaterEqual);
}

ErrorCode PrimitiveType::Primitive_op_greater(Variant* result, Variant** args, int_t numArgs)
{
	return Primitive_op_compare(result, args, numArgs, &op_greater);
}
	
ErrorCode PrimitiveType::Primitive_op_assign(Variant* result, Variant** args, int_t numArgs)
{
	if (2 == numArgs)
	{
		if (!args[0]->m_type->isPrimitive())
		{
			return e_invalid_this_type;
		}
		if (!args[1]->m_type->isPrimitive())
		{
			return e_invalid_arg_type_1;
		}
		PrimitiveType* arg0Type = static_cast<PrimitiveType*>(args[0]->m_type);
		PrimitiveType* arg1Type = static_cast<PrimitiveType*>(args[1]->m_type);
		arg1Type->castTo(args[0]->m_pointer, arg0Type, args[1]->m_pointer);
		result->assignPrimitivePtr(arg0Type, args[0]->m_pointer, false, ::pafcore::Variant::by_ref);
		return s_ok;
	}
	return e_invalid_arg_num;
}

template<typename Func>
inline ErrorCode Primitive_op_compoundAssign(Variant* result, Variant** args, int_t numArgs, Func func)
{
	if (2 == numArgs)
	{
		if (!args[0]->m_type->isPrimitive())
		{
			return e_invalid_this_type;
		}
		if (!args[1]->m_type->isPrimitive())
		{
			return e_invalid_arg_type_1;
		}
		PrimitiveType* arg0Type = static_cast<PrimitiveType*>(args[0]->m_type);
		PrimitiveType* arg1Type = static_cast<PrimitiveType*>(args[1]->m_type);
		PrimitiveTypeCategory resTypeCategory = GetPromotedTypeCategory(arg0Type->m_typeCategory, arg1Type->m_typeCategory);
		PrimitiveType* resType = GetPrimitiveTypeFromTypeCategory(resTypeCategory);

		char value0[max_primitive_type_size];
		char value1[max_primitive_type_size];
		char resultValue[max_primitive_type_size];

		arg0Type->castTo(value0, resType, args[0]->m_pointer);
		arg1Type->castTo(value1, resType, args[1]->m_pointer);
		(resType->*func)(resultValue, value0, value1);
		resType->castTo(args[0]->m_pointer, arg0Type, resultValue);
		result->assignPrimitivePtr(arg0Type, args[0]->m_pointer, false, ::pafcore::Variant::by_ref);
		return s_ok;
	}
	return e_invalid_arg_num;
}


template<typename Func>
inline ErrorCode Primitive_op_compoundAssign_IntegerOnly(Variant* result, Variant** args, int_t numArgs, Func func)
{
	if (2 == numArgs)
	{
		if (!args[0]->m_type->isPrimitive())
		{
			return e_invalid_this_type;
		}
		if (!args[1]->m_type->isPrimitive())
		{
			return e_invalid_arg_type_1;
		}
		PrimitiveType* arg0Type = static_cast<PrimitiveType*>(args[0]->m_type);
		if(float_type <= arg0Type->m_typeCategory)
		{
			return e_invalid_this_type;
		}
		PrimitiveType* arg1Type = static_cast<PrimitiveType*>(args[1]->m_type);
		if(float_type <= arg1Type->m_typeCategory)
		{
			return e_invalid_arg_type_1;
		}
		PrimitiveTypeCategory resTypeCategory = GetPromotedTypeCategory(arg0Type->m_typeCategory, arg1Type->m_typeCategory);
		PrimitiveType* resType = GetPrimitiveTypeFromTypeCategory(resTypeCategory);

		char value0[max_primitive_type_size];
		char value1[max_primitive_type_size];
		char resultValue[max_primitive_type_size];

		arg0Type->castTo(value0, resType, args[0]->m_pointer);
		arg1Type->castTo(value1, resType, args[1]->m_pointer);
		(resType->*func)(resultValue, value0, value1);
		resType->castTo(args[0]->m_pointer, arg0Type, resultValue);
		result->assignPrimitivePtr(arg0Type, args[0]->m_pointer, false, ::pafcore::Variant::by_ref);
		return s_ok;
	}
	return e_invalid_arg_num;
}

ErrorCode PrimitiveType::Primitive_op_addAssign(Variant* result, Variant** args, int_t numArgs)
{
	return Primitive_op_compoundAssign(result, args, numArgs, &op_add);
}

ErrorCode PrimitiveType::Primitive_op_subtractAssign(Variant* result, Variant** args, int_t numArgs)
{
	return Primitive_op_compoundAssign(result, args, numArgs, &op_subtract);
}

ErrorCode PrimitiveType::Primitive_op_multiplyAssign(Variant* result, Variant** args, int_t numArgs)
{
	return Primitive_op_compoundAssign(result, args, numArgs, &op_multiply);
}

ErrorCode PrimitiveType::Primitive_op_divideAssign(Variant* result, Variant** args, int_t numArgs)
{
	return Primitive_op_compoundAssign(result, args, numArgs, &op_divide);
}

ErrorCode PrimitiveType::Primitive_op_modAssign(Variant* result, Variant** args, int_t numArgs)
{
	return Primitive_op_compoundAssign_IntegerOnly(result, args, numArgs, &op_mod);
}

ErrorCode PrimitiveType::Primitive_op_bitwiseXorAssign(Variant* result, Variant** args, int_t numArgs)
{
	return Primitive_op_compoundAssign_IntegerOnly(result, args, numArgs, &op_bitwiseXor);
}

ErrorCode PrimitiveType::Primitive_op_bitwiseAndAssign(Variant* result, Variant** args, int_t numArgs)
{
	return Primitive_op_compoundAssign_IntegerOnly(result, args, numArgs, &op_bitwiseAnd);
}

ErrorCode PrimitiveType::Primitive_op_bitwiseOrAssign(Variant* result, Variant** args, int_t numArgs)
{
	return Primitive_op_compoundAssign_IntegerOnly(result, args, numArgs, &op_bitwiseOr);
}

ErrorCode PrimitiveType::Primitive_op_leftShiftAssign(Variant* result, Variant** args, int_t numArgs)
{
	return Primitive_op_compoundAssign_IntegerOnly(result, args, numArgs, &op_leftShift);
}

ErrorCode PrimitiveType::Primitive_op_rightShiftAssign(Variant* result, Variant** args, int_t numArgs)
{
	return Primitive_op_compoundAssign_IntegerOnly(result, args, numArgs, &op_rightShift);
}

//const char* PrimitiveTypeTraits<bool>::s_typeName					= "bool";
//const char* PrimitiveTypeTraits<char>::s_typeName					= "char";
//const char* PrimitiveTypeTraits<signed char>::s_typeName			= "signed char";
//const char* PrimitiveTypeTraits<unsigned char>::s_typeName			= "unsigned char";
//const char* PrimitiveTypeTraits<wchar_t>::s_typeName				= "wchar_t";
//const char* PrimitiveTypeTraits<short>::s_typeName					= "short";
//const char* PrimitiveTypeTraits<unsigned short>::s_typeName			= "unsigned short";
//const char* PrimitiveTypeTraits<long>::s_typeName					= "long";
//const char* PrimitiveTypeTraits<unsigned long>::s_typeName			= "unsigned long";
//const char* PrimitiveTypeTraits<long long>::s_typeName				= "long long";
//const char* PrimitiveTypeTraits<unsigned long long>::s_typeName		= "unsigned long long";
//const char* PrimitiveTypeTraits<int>::s_typeName					= "int";
//const char* PrimitiveTypeTraits<unsigned int>::s_typeName			= "unsigned int";
//const char* PrimitiveTypeTraits<float>::s_typeName					= "float";
//const char* PrimitiveTypeTraits<double>::s_typeName					= "double";
//const char* PrimitiveTypeTraits<long double>::s_typeName			= "long double";


BoolType				BoolType::				s_instance("bool");
CharType				CharType::				s_instance("char");
SignedCharType			SignedCharType::		s_instance("signed char");
UnsignedCharType		UnsignedCharType::		s_instance("unsigned char");
WcharType				WcharType::				s_instance("wchar_t");
ShortType				ShortType::				s_instance("short");
UnsignedShortType		UnsignedShortType::		s_instance("unsigned short");
LongType				LongType::				s_instance("long");
UnsignedLongType		UnsignedLongType::		s_instance("unsigned long");
LongLongType			LongLongType::			s_instance("long long");
UnsignedLongLongType	UnsignedLongLongType::	s_instance("unsigned long long");
IntType					IntType::				s_instance("int");
UnsignedIntType			UnsignedIntType::		s_instance("unsigned int");
FloatType				FloatType::				s_instance("float");
DoubleType				DoubleType::			s_instance("double");
LongDoubleType			LongDoubleType::		s_instance("long double");

END_PAFCORE

AUTO_REGISTER_TYPE(pafcore::BoolType)
AUTO_REGISTER_TYPE(pafcore::CharType)
AUTO_REGISTER_TYPE(pafcore::SignedCharType)
AUTO_REGISTER_TYPE(pafcore::UnsignedCharType)
AUTO_REGISTER_TYPE(pafcore::WcharType)
AUTO_REGISTER_TYPE(pafcore::ShortType)
AUTO_REGISTER_TYPE(pafcore::UnsignedShortType)
AUTO_REGISTER_TYPE(pafcore::LongType)
AUTO_REGISTER_TYPE(pafcore::UnsignedLongType)
AUTO_REGISTER_TYPE(pafcore::LongLongType)
AUTO_REGISTER_TYPE(pafcore::UnsignedLongLongType)
AUTO_REGISTER_TYPE(pafcore::IntType)
AUTO_REGISTER_TYPE(pafcore::UnsignedIntType)
AUTO_REGISTER_TYPE(pafcore::FloatType)
AUTO_REGISTER_TYPE(pafcore::DoubleType)
