#include "PrimitiveType.h"
#include "PrimitiveType.mh"
#include "PrimitiveType.ic"
#include "PrimitiveType.mc"
#include "TypeAlias.h"
#include "AutoRun.h"
#include <assert.h>

BEGIN_PAFCORE

size_t PrimitiveType::_getMemberCount_()
{
	return m_staticMethodCount;
}

Metadata* PrimitiveType::_getMember_(size_t index)
{
	if(index < m_staticMethodCount)
	{
		return &m_staticMethods[index];
	}
	return 0;
}

Metadata* PrimitiveType::_findMember_(const char* name)
{
	return findTypeMember(name);
}

Metadata* PrimitiveType::findMember(const char* name)
{
	return findTypeMember(name);
}

Metadata* PrimitiveType::findTypeMember(const char* name)
{
	Metadata dummy(name);
	StaticMethod* res = std::lower_bound(m_staticMethods, m_staticMethods + m_staticMethodCount, dummy);
	if(m_staticMethods + m_staticMethodCount != res && strcmp(name, res->m_name) == 0)
	{
		return res;
	}
	return 0;
}

PrimitiveTypeCategory PrimitiveType::GetPromotedTypeCategory(PrimitiveTypeCategory typeCategory)
{
	if(typeCategory <= unsigned_short_type)
	{
		return int_type;
	}
	return typeCategory;
}

PrimitiveTypeCategory PrimitiveType::GetPromotedTypeCategory(PrimitiveTypeCategory typeCategory1, PrimitiveTypeCategory typeCategory2)
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
	return large;
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

ErrorCode PrimitiveType::Primitive___op_pos_(Variant* result, Variant** args, int_t numArgs)
{
	if(1 == numArgs)
	{
		if(!args[0]->m_type->isPrimitive())
		{
			return e_invalid_arg_type_1;
		}
		PrimitiveType* arg0Type = static_cast<PrimitiveType*>(args[0]->m_type);
		PrimitiveTypeCategory resTypeCategory = GetPromotedTypeCategory(arg0Type->m_typeCategory);
		PrimitiveType* resType = GetPrimitiveTypeFromTypeCategory(resTypeCategory);

		char value0[max_primitive_type_size];
		char resultValue[max_primitive_type_size];
		arg0Type->castTo(value0, resType, args[0]->m_pointer);
		resType->_op_pos_(resultValue, value0);
		result->assignPrimitive(resType, resultValue);
		return s_ok;
	}
	return e_invalid_arg_num;
}

ErrorCode PrimitiveType::Primitive___op_neg_(Variant* result, Variant** args, int_t numArgs)
{
	if(1 == numArgs)
	{
		if(!args[0]->m_type->isPrimitive())
		{
			return e_invalid_arg_type_1;
		}
		PrimitiveType* arg0Type = static_cast<PrimitiveType*>(args[0]->m_type);
		PrimitiveTypeCategory resTypeCategory = GetPromotedTypeCategory(arg0Type->m_typeCategory);
		PrimitiveType* resType = GetPrimitiveTypeFromTypeCategory(resTypeCategory);

		char value0[max_primitive_type_size];
		char resultValue[max_primitive_type_size];
		arg0Type->castTo(value0, resType, args[0]->m_pointer);
		resType->_op_neg_(resultValue, value0);
		result->assignPrimitive(resType, resultValue);
		return s_ok;
	}
	return e_invalid_arg_num;
}

ErrorCode PrimitiveType::Primitive___op_add_(Variant* result, Variant** args, int_t numArgs)
{
	if(2 == numArgs)
	{
		if(!args[0]->m_type->isPrimitive())
		{
			return e_invalid_arg_type_1;
		}
		if(!args[1]->m_type->isPrimitive())
		{
			return e_invalid_arg_type_2;
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
		resType->_op_add_(resultValue, value0, value1);
		result->assignPrimitive(resType, resultValue);
		return s_ok;
	}
	return e_invalid_arg_num;
}


ErrorCode PrimitiveType::Primitive___op_sub_(Variant* result, Variant** args, int_t numArgs)
{
	if(2 == numArgs)
	{
		if(!args[0]->m_type->isPrimitive())
		{
			return e_invalid_arg_type_1;
		}
		if(!args[1]->m_type->isPrimitive())
		{
			return e_invalid_arg_type_2;
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
		resType->_op_sub_(resultValue, value0, value1);
		result->assignPrimitive(resType, resultValue);
		return s_ok;
	}
	return e_invalid_arg_num;
}


ErrorCode PrimitiveType::Primitive___op_mul_(Variant* result, Variant** args, int_t numArgs)
{
	if(2 == numArgs)
	{
		if(!args[0]->m_type->isPrimitive())
		{
			return e_invalid_arg_type_1;
		}
		if(!args[1]->m_type->isPrimitive())
		{
			return e_invalid_arg_type_2;
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
		resType->_op_mul_(resultValue, value0, value1);
		result->assignPrimitive(resType, resultValue);
		return s_ok;
	}
	return e_invalid_arg_num;
}


ErrorCode PrimitiveType::Primitive___op_div_(Variant* result, Variant** args, int_t numArgs)
{
	if(2 == numArgs)
	{
		if(!args[0]->m_type->isPrimitive())
		{
			return e_invalid_arg_type_1;
		}
		if(!args[1]->m_type->isPrimitive())
		{
			return e_invalid_arg_type_2;
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
		resType->_op_div_(resultValue, value0, value1);
		result->assignPrimitive(resType, resultValue);
		return s_ok;
	}
	return e_invalid_arg_num;
}

ErrorCode PrimitiveType::Primitive___op_less_than_(Variant* result, Variant** args, int_t numArgs)
{
	if(2 == numArgs)
	{
		if(!args[0]->m_type->isPrimitive())
		{
			return e_invalid_arg_type_1;
		}
		if(!args[1]->m_type->isPrimitive())
		{
			return e_invalid_arg_type_2;
		}
		PrimitiveType* arg0Type = static_cast<PrimitiveType*>(args[0]->m_type);
		PrimitiveType* arg1Type = static_cast<PrimitiveType*>(args[1]->m_type);
		PrimitiveTypeCategory resTypeCategory = GetPromotedTypeCategory(arg0Type->m_typeCategory, arg1Type->m_typeCategory);
		PrimitiveType* resType = GetPrimitiveTypeFromTypeCategory(resTypeCategory);

		char value0[max_primitive_type_size];
		char value1[max_primitive_type_size];

		arg0Type->castTo(value0, resType, args[0]->m_pointer);
		arg1Type->castTo(value1, resType, args[1]->m_pointer);
		bool res = resType->_op_less_than_(value0, value1);
		result->assignPrimitive(BoolType::GetSingleton(), &res);
		return s_ok;
	}
	return e_invalid_arg_num;
}

ErrorCode PrimitiveType::Primitive___op_less_equal_(Variant* result, Variant** args, int_t numArgs)
{
	if(2 == numArgs)
	{
		if(!args[0]->m_type->isPrimitive())
		{
			return e_invalid_arg_type_1;
		}
		if(!args[1]->m_type->isPrimitive())
		{
			return e_invalid_arg_type_2;
		}
		PrimitiveType* arg0Type = static_cast<PrimitiveType*>(args[0]->m_type);
		PrimitiveType* arg1Type = static_cast<PrimitiveType*>(args[1]->m_type);
		PrimitiveTypeCategory resTypeCategory = GetPromotedTypeCategory(arg0Type->m_typeCategory, arg1Type->m_typeCategory);
		PrimitiveType* resType = GetPrimitiveTypeFromTypeCategory(resTypeCategory);

		char value0[max_primitive_type_size];
		char value1[max_primitive_type_size];

		arg0Type->castTo(value0, resType, args[0]->m_pointer);
		arg1Type->castTo(value1, resType, args[1]->m_pointer);
		bool res = resType->_op_less_equal_(value0, value1);
		result->assignPrimitive(BoolType::GetSingleton(), &res);
		return s_ok;
	}
	return e_invalid_arg_num;
}

ErrorCode PrimitiveType::Primitive___op_equal_to_(Variant* result, Variant** args, int_t numArgs)
{
	if(2 == numArgs)
	{
		if(!args[0]->m_type->isPrimitive())
		{
			return e_invalid_arg_type_1;
		}
		if(!args[1]->m_type->isPrimitive())
		{
			return e_invalid_arg_type_2;
		}
		PrimitiveType* arg0Type = static_cast<PrimitiveType*>(args[0]->m_type);
		PrimitiveType* arg1Type = static_cast<PrimitiveType*>(args[1]->m_type);
		PrimitiveTypeCategory resTypeCategory = GetPromotedTypeCategory(arg0Type->m_typeCategory, arg1Type->m_typeCategory);
		PrimitiveType* resType = GetPrimitiveTypeFromTypeCategory(resTypeCategory);

		char value0[max_primitive_type_size];
		char value1[max_primitive_type_size];

		arg0Type->castTo(value0, resType, args[0]->m_pointer);
		arg1Type->castTo(value1, resType, args[1]->m_pointer);
		bool res = resType->_op_equal_to_(value0, value1);
		result->assignPrimitive(BoolType::GetSingleton(), &res);
		return s_ok;
	}
	return e_invalid_arg_num;
}

ErrorCode PrimitiveType::Primitive___op_not_equal_to_(Variant* result, Variant** args, int_t numArgs)
{
	if(2 == numArgs)
	{
		if(!args[0]->m_type->isPrimitive())
		{
			return e_invalid_arg_type_1;
		}
		if(!args[1]->m_type->isPrimitive())
		{
			return e_invalid_arg_type_2;
		}
		PrimitiveType* arg0Type = static_cast<PrimitiveType*>(args[0]->m_type);
		PrimitiveType* arg1Type = static_cast<PrimitiveType*>(args[1]->m_type);
		PrimitiveTypeCategory resTypeCategory = GetPromotedTypeCategory(arg0Type->m_typeCategory, arg1Type->m_typeCategory);
		PrimitiveType* resType = GetPrimitiveTypeFromTypeCategory(resTypeCategory);

		char value0[max_primitive_type_size];
		char value1[max_primitive_type_size];

		arg0Type->castTo(value0, resType, args[0]->m_pointer);
		arg1Type->castTo(value1, resType, args[1]->m_pointer);
		bool res = resType->_op_not_equal_to_(value0, value1);
		result->assignPrimitive(BoolType::GetSingleton(), &res);
		return s_ok;
	}
	return e_invalid_arg_num;
}

ErrorCode PrimitiveType::Primitive___op_greater_equal_(Variant* result, Variant** args, int_t numArgs)
{
	if(2 == numArgs)
	{
		if(!args[0]->m_type->isPrimitive())
		{
			return e_invalid_arg_type_1;
		}
		if(!args[1]->m_type->isPrimitive())
		{
			return e_invalid_arg_type_2;
		}
		PrimitiveType* arg0Type = static_cast<PrimitiveType*>(args[0]->m_type);
		PrimitiveType* arg1Type = static_cast<PrimitiveType*>(args[1]->m_type);
		PrimitiveTypeCategory resTypeCategory = GetPromotedTypeCategory(arg0Type->m_typeCategory, arg1Type->m_typeCategory);
		PrimitiveType* resType = GetPrimitiveTypeFromTypeCategory(resTypeCategory);

		char value0[max_primitive_type_size];
		char value1[max_primitive_type_size];

		arg0Type->castTo(value0, resType, args[0]->m_pointer);
		arg1Type->castTo(value1, resType, args[1]->m_pointer);
		bool res = resType->_op_greater_equal_(value0, value1);
		result->assignPrimitive(BoolType::GetSingleton(), &res);
		return s_ok;
	}
	return e_invalid_arg_num;
}

ErrorCode PrimitiveType::Primitive___op_greater_than_(Variant* result, Variant** args, int_t numArgs)
{
	if(2 == numArgs)
	{
		if(!args[0]->m_type->isPrimitive())
		{
			return e_invalid_arg_type_1;
		}
		if(!args[1]->m_type->isPrimitive())
		{
			return e_invalid_arg_type_2;
		}
		PrimitiveType* arg0Type = static_cast<PrimitiveType*>(args[0]->m_type);
		PrimitiveType* arg1Type = static_cast<PrimitiveType*>(args[1]->m_type);
		PrimitiveTypeCategory resTypeCategory = GetPromotedTypeCategory(arg0Type->m_typeCategory, arg1Type->m_typeCategory);
		PrimitiveType* resType = GetPrimitiveTypeFromTypeCategory(resTypeCategory);

		char value0[max_primitive_type_size];
		char value1[max_primitive_type_size];

		arg0Type->castTo(value0, resType, args[0]->m_pointer);
		arg1Type->castTo(value1, resType, args[1]->m_pointer);
		bool res = resType->_op_greater_than_(value0, value1);
		result->assignPrimitive(BoolType::GetSingleton(), &res);
		return s_ok;
	}
	return e_invalid_arg_num;
}

ErrorCode PrimitiveType::Primitive___op_not_(Variant* result, Variant** args, int_t numArgs)
{
	if(1 == numArgs)
	{
		if(!args[0]->m_type->isPrimitive())
		{
			return e_invalid_arg_type_1;
		}
		PrimitiveType* arg0Type = static_cast<PrimitiveType*>(args[0]->m_type);
		bool res = arg0Type->_op_not_(args[0]->m_pointer);
		result->assignPrimitive(BoolType::GetSingleton(), &res);
		return s_ok;
	}
	return e_invalid_arg_num;
}

ErrorCode PrimitiveType::Primitive___op_and_(Variant* result, Variant** args, int_t numArgs)
{
	if(2 == numArgs)
	{
		if(!args[0]->m_type->isPrimitive())
		{
			return e_invalid_arg_type_1;
		}
		if(!args[1]->m_type->isPrimitive())
		{
			return e_invalid_arg_type_2;
		}
		PrimitiveType* arg0Type = static_cast<PrimitiveType*>(args[0]->m_type);
		PrimitiveType* arg1Type = static_cast<PrimitiveType*>(args[1]->m_type);
		BoolType* resType = BoolType::GetSingleton();
		bool value0[1], value1[1];
		arg0Type->castTo(value0, resType, args[0]->m_pointer);
		arg1Type->castTo(value1, resType, args[1]->m_pointer);
		bool res = resType->_op_and_(value0, value1);
		result->assignPrimitive(resType, &res);
		return s_ok;
	}
	return e_invalid_arg_num;
}

ErrorCode PrimitiveType::Primitive___op_or_(Variant* result, Variant** args, int_t numArgs)
{
	if(2 == numArgs)
	{
		if(!args[0]->m_type->isPrimitive())
		{
			return e_invalid_arg_type_1;
		}
		if(!args[1]->m_type->isPrimitive())
		{
			return e_invalid_arg_type_2;
		}
		PrimitiveType* arg0Type = static_cast<PrimitiveType*>(args[0]->m_type);
		PrimitiveType* arg1Type = static_cast<PrimitiveType*>(args[1]->m_type);
		BoolType* resType = BoolType::GetSingleton();
		bool value0[1], value1[1];
		arg0Type->castTo(value0, resType, args[0]->m_pointer);
		arg1Type->castTo(value1, resType, args[1]->m_pointer);
		bool res = resType->_op_or_(value0, value1);
		result->assignPrimitive(resType, &res);
		return s_ok;
	}
	return e_invalid_arg_num;
}
	
//ErrorCode PrimitiveType::Primitive___op_add_assign_(Variant* result, Variant** args, int_t numArgs)
//{
//	if(2 == numArgs)
//	{
//		if(!args[0]->m_type->isPrimitive())
//		{
//			return e_invalid_arg_type_1;
//		}
//		if(!args[1]->m_type->isPrimitive())
//		{
//			return e_invalid_arg_type_2;
//		}
//		PrimitiveType* arg0Type = static_cast<PrimitiveType*>(args[0]->m_type);
//		PrimitiveType* arg1Type = static_cast<PrimitiveType*>(args[1]->m_type);
//		PrimitiveTypeCategory resTypeCategory = GetPromotedTypeCategory(arg0Type->m_typeCategory, arg1Type->m_typeCategory);
//		PrimitiveType* resType = GetPrimitiveTypeFromTypeCategory(resTypeCategory);
//
//		char value0[max_primitive_type_size];
//		char value1[max_primitive_type_size];
//		char resultValue[max_primitive_type_size];
//
//		arg0Type->castTo(value0, resType, args[0]->m_pointer);
//		arg1Type->castTo(value1, resType, args[1]->m_pointer);
//		resType->_op_add_(resultValue, value0, value1);
//		resType->castTo(args[0]->m_pointer, arg0Type, resultValue);
//
//		return s_ok;
//	}
//	return e_invalid_arg_num;
//}
//
//ErrorCode PrimitiveType::Primitive___op_sub_assign_(Variant* result, Variant** args, int_t numArgs)
//{
//	return e_invalid_arg_num;
//}
//
//ErrorCode PrimitiveType::Primitive___op_mul_assign_(Variant* result, Variant** args, int_t numArgs)
//{
//	return e_invalid_arg_num;
//}
//
//ErrorCode PrimitiveType::Primitive___op_div_assign_(Variant* result, Variant** args, int_t numArgs)
//{
//	return e_invalid_arg_num;
//}

//integer only
ErrorCode PrimitiveType::Primitive___op_inc_(Variant* result, Variant** args, int_t numArgs)
{
	if(1 == numArgs)
	{
		if(!args[0]->m_type->isPrimitive())
		{
			return e_invalid_arg_type_1;
		}
		PrimitiveType* arg0Type = static_cast<PrimitiveType*>(args[0]->m_type);
		if(arg0Type->m_typeCategory >= float_type)
		{
			return e_invalid_arg_type_1;
		}
		PrimitiveType* resType = arg0Type;
		char resultValue[max_primitive_type_size];
		resType->_op_inc_(resultValue, args[0]->m_pointer);
		result->assignPrimitive(resType, resultValue);
		return s_ok;
	}
	return e_invalid_arg_num;
}

ErrorCode PrimitiveType::Primitive___op_post_inc_(Variant* result, Variant** args, int_t numArgs)
{
	if(1 == numArgs)
	{
		if(!args[0]->m_type->isPrimitive())
		{
			return e_invalid_arg_type_1;
		}
		PrimitiveType* arg0Type = static_cast<PrimitiveType*>(args[0]->m_type);
		if(arg0Type->m_typeCategory >= float_type)
		{
			return e_invalid_arg_type_1;
		}
		PrimitiveType* resType = arg0Type;
		char resultValue[max_primitive_type_size];
		resType->_op_post_inc_(resultValue, args[0]->m_pointer);
		result->assignPrimitive(resType, resultValue);
		return s_ok;
	}
	return e_invalid_arg_num;
}

ErrorCode PrimitiveType::Primitive___op_dec_(Variant* result, Variant** args, int_t numArgs)
{
	if(1 == numArgs)
	{
		if(!args[0]->m_type->isPrimitive())
		{
			return e_invalid_arg_type_1;
		}
		PrimitiveType* arg0Type = static_cast<PrimitiveType*>(args[0]->m_type);
		if(arg0Type->m_typeCategory >= float_type)
		{
			return e_invalid_arg_type_1;
		}
		PrimitiveType* resType = arg0Type;
		char resultValue[max_primitive_type_size];
		resType->_op_dec_(resultValue, args[0]->m_pointer);
		result->assignPrimitive(resType, resultValue);
		return s_ok;
	}
	return e_invalid_arg_num;
}

ErrorCode PrimitiveType::Primitive___op_post_dec_(Variant* result, Variant** args, int_t numArgs)
{
	if(1 == numArgs)
	{
		if(!args[0]->m_type->isPrimitive())
		{
			return e_invalid_arg_type_1;
		}
		PrimitiveType* arg0Type = static_cast<PrimitiveType*>(args[0]->m_type);
		if(arg0Type->m_typeCategory >= float_type)
		{
			return e_invalid_arg_type_1;
		}
		PrimitiveType* resType = arg0Type;
		char resultValue[max_primitive_type_size];
		resType->_op_post_dec_(resultValue, args[0]->m_pointer);
		result->assignPrimitive(resType, resultValue);
		return s_ok;
	}
	return e_invalid_arg_num;
}

ErrorCode PrimitiveType::Primitive___op_mod_(Variant* result, Variant** args, int_t numArgs)
{
	if(2 == numArgs)
	{
		if(!args[0]->m_type->isPrimitive())
		{
			return e_invalid_arg_type_1;
		}
		if(!args[1]->m_type->isPrimitive())
		{
			return e_invalid_arg_type_2;
		}
		PrimitiveType* arg0Type = static_cast<PrimitiveType*>(args[0]->m_type);
		PrimitiveType* arg1Type = static_cast<PrimitiveType*>(args[1]->m_type);
		if(arg0Type->m_typeCategory >= float_type)
		{
			return e_invalid_arg_type_1;
		}
		if(arg1Type->m_typeCategory >= float_type)
		{
			return e_invalid_arg_type_2;
		}
		PrimitiveTypeCategory resTypeCategory = GetPromotedTypeCategory(arg0Type->m_typeCategory, arg1Type->m_typeCategory);
		PrimitiveType* resType = GetPrimitiveTypeFromTypeCategory(resTypeCategory);

		char value0[max_primitive_type_size];
		char value1[max_primitive_type_size];
		char resultValue[max_primitive_type_size];

		arg0Type->castTo(value0, resType, args[0]->m_pointer);
		arg1Type->castTo(value1, resType, args[1]->m_pointer);
		resType->_op_mod_(resultValue, value0, value1);
		result->assignPrimitive(resType, resultValue);
		return s_ok;
	}
	return e_invalid_arg_num;
}

ErrorCode PrimitiveType::Primitive___op_bit_not_(Variant* result, Variant** args, int_t numArgs)
{
	if(1 == numArgs)
	{
		if(!args[0]->m_type->isPrimitive())
		{
			return e_invalid_arg_type_1;
		}
		PrimitiveType* arg0Type = static_cast<PrimitiveType*>(args[0]->m_type);
		if(arg0Type->m_typeCategory >= float_type)
		{
			return e_invalid_arg_type_1;
		}
		PrimitiveTypeCategory resTypeCategory = GetPromotedTypeCategory(arg0Type->m_typeCategory);
		PrimitiveType* resType = GetPrimitiveTypeFromTypeCategory(resTypeCategory);
		char value0[max_primitive_type_size];
		char resultValue[max_primitive_type_size];
		arg0Type->castTo(value0, resType, args[0]->m_pointer);
		resType->_op_bit_not_(resultValue, value0);
		result->assignPrimitive(resType, resultValue);
		return s_ok;
	}
	return e_invalid_arg_num;
}

ErrorCode PrimitiveType::Primitive___op_bit_and_(Variant* result, Variant** args, int_t numArgs)
{
	if(2 == numArgs)
	{
		if(!args[0]->m_type->isPrimitive())
		{
			return e_invalid_arg_type_1;
		}
		if(!args[1]->m_type->isPrimitive())
		{
			return e_invalid_arg_type_2;
		}
		PrimitiveType* arg0Type = static_cast<PrimitiveType*>(args[0]->m_type);
		PrimitiveType* arg1Type = static_cast<PrimitiveType*>(args[1]->m_type);
		if(arg0Type->m_typeCategory >= float_type)
		{
			return e_invalid_arg_type_1;
		}
		if(arg1Type->m_typeCategory >= float_type)
		{
			return e_invalid_arg_type_2;
		}
		PrimitiveTypeCategory resTypeCategory = GetPromotedTypeCategory(arg0Type->m_typeCategory, arg1Type->m_typeCategory);
		PrimitiveType* resType = GetPrimitiveTypeFromTypeCategory(resTypeCategory);

		char value0[max_primitive_type_size];
		char value1[max_primitive_type_size];
		char resultValue[max_primitive_type_size];

		arg0Type->castTo(value0, resType, args[0]->m_pointer);
		arg1Type->castTo(value1, resType, args[1]->m_pointer);
		resType->_op_bit_and_(resultValue, value0, value1);
		result->assignPrimitive(resType, resultValue);
		return s_ok;
	}
	return e_invalid_arg_num;
}

ErrorCode PrimitiveType::Primitive___op_bit_or_(Variant* result, Variant** args, int_t numArgs)
{
	if(2 == numArgs)
	{
		if(!args[0]->m_type->isPrimitive())
		{
			return e_invalid_arg_type_1;
		}
		if(!args[1]->m_type->isPrimitive())
		{
			return e_invalid_arg_type_2;
		}
		PrimitiveType* arg0Type = static_cast<PrimitiveType*>(args[0]->m_type);
		PrimitiveType* arg1Type = static_cast<PrimitiveType*>(args[1]->m_type);
		if(arg0Type->m_typeCategory >= float_type)
		{
			return e_invalid_arg_type_1;
		}
		if(arg1Type->m_typeCategory >= float_type)
		{
			return e_invalid_arg_type_2;
		}
		PrimitiveTypeCategory resTypeCategory = GetPromotedTypeCategory(arg0Type->m_typeCategory, arg1Type->m_typeCategory);
		PrimitiveType* resType = GetPrimitiveTypeFromTypeCategory(resTypeCategory);

		char value0[max_primitive_type_size];
		char value1[max_primitive_type_size];
		char resultValue[max_primitive_type_size];

		arg0Type->castTo(value0, resType, args[0]->m_pointer);
		arg1Type->castTo(value1, resType, args[1]->m_pointer);
		resType->_op_bit_or_(resultValue, value0, value1);
		result->assignPrimitive(resType, resultValue);
		return s_ok;
	}
	return e_invalid_arg_num;
}

ErrorCode PrimitiveType::Primitive___op_bit_xor_(Variant* result, Variant** args, int_t numArgs)
{
	if(2 == numArgs)
	{
		if(!args[0]->m_type->isPrimitive())
		{
			return e_invalid_arg_type_1;
		}
		if(!args[1]->m_type->isPrimitive())
		{
			return e_invalid_arg_type_2;
		}
		PrimitiveType* arg0Type = static_cast<PrimitiveType*>(args[0]->m_type);
		PrimitiveType* arg1Type = static_cast<PrimitiveType*>(args[1]->m_type);
		if(arg0Type->m_typeCategory >= float_type)
		{
			return e_invalid_arg_type_1;
		}
		if(arg1Type->m_typeCategory >= float_type)
		{
			return e_invalid_arg_type_2;
		}
		PrimitiveTypeCategory resTypeCategory = GetPromotedTypeCategory(arg0Type->m_typeCategory, arg1Type->m_typeCategory);
		PrimitiveType* resType = GetPrimitiveTypeFromTypeCategory(resTypeCategory);

		char value0[max_primitive_type_size];
		char value1[max_primitive_type_size];
		char resultValue[max_primitive_type_size];

		arg0Type->castTo(value0, resType, args[0]->m_pointer);
		arg1Type->castTo(value1, resType, args[1]->m_pointer);
		resType->_op_bit_xor_(resultValue, value0, value1);
		result->assignPrimitive(resType, resultValue);
		return s_ok;
	}
	return e_invalid_arg_num;
}

ErrorCode PrimitiveType::Primitive___op_left_shift_(Variant* result, Variant** args, int_t numArgs)
{
	if(2 == numArgs)
	{
		if(!args[0]->m_type->isPrimitive())
		{
			return e_invalid_arg_type_1;
		}
		if(!args[1]->m_type->isPrimitive())
		{
			return e_invalid_arg_type_2;
		}
		PrimitiveType* arg0Type = static_cast<PrimitiveType*>(args[0]->m_type);
		PrimitiveType* arg1Type = static_cast<PrimitiveType*>(args[1]->m_type);
		if(arg0Type->m_typeCategory >= float_type)
		{
			return e_invalid_arg_type_1;
		}
		if(arg1Type->m_typeCategory >= float_type)
		{
			return e_invalid_arg_type_2;
		}
		PrimitiveTypeCategory resTypeCategory = GetPromotedTypeCategory(arg0Type->m_typeCategory);
		PrimitiveType* resType = GetPrimitiveTypeFromTypeCategory(resTypeCategory);

		char value0[max_primitive_type_size];
		char value1[max_primitive_type_size];
		char resultValue[max_primitive_type_size];

		arg0Type->castTo(value0, resType, args[0]->m_pointer);
		arg1Type->castTo(value1, resType, args[1]->m_pointer);
		resType->_op_left_shift_(resultValue, value0, value1);
		result->assignPrimitive(resType, resultValue);
		return s_ok;
	}
	return e_invalid_arg_num;
}

ErrorCode PrimitiveType::Primitive___op_right_shift_(Variant* result, Variant** args, int_t numArgs)
{
	if(2 == numArgs)
	{
		if(!args[0]->m_type->isPrimitive())
		{
			return e_invalid_arg_type_1;
		}
		if(!args[1]->m_type->isPrimitive())
		{
			return e_invalid_arg_type_2;
		}
		PrimitiveType* arg0Type = static_cast<PrimitiveType*>(args[0]->m_type);
		PrimitiveType* arg1Type = static_cast<PrimitiveType*>(args[1]->m_type);
		if(arg0Type->m_typeCategory >= float_type)
		{
			return e_invalid_arg_type_1;
		}
		if(arg1Type->m_typeCategory >= float_type)
		{
			return e_invalid_arg_type_2;
		}
		PrimitiveTypeCategory resTypeCategory = GetPromotedTypeCategory(arg0Type->m_typeCategory);
		PrimitiveType* resType = GetPrimitiveTypeFromTypeCategory(resTypeCategory);

		char value0[max_primitive_type_size];
		char value1[max_primitive_type_size];
		char resultValue[max_primitive_type_size];

		arg0Type->castTo(value0, resType, args[0]->m_pointer);
		arg1Type->castTo(value1, resType, args[1]->m_pointer);
		resType->_op_right_shift_(resultValue, value0, value1);
		result->assignPrimitive(resType, resultValue);
		return s_ok;
	}
	return e_invalid_arg_num;
}

const char* PrimitiveTypeTraits<bool>::s_typeName					= "bool";
const char* PrimitiveTypeTraits<char>::s_typeName					= "char";
const char* PrimitiveTypeTraits<signed char>::s_typeName			= "signed char";
const char* PrimitiveTypeTraits<unsigned char>::s_typeName			= "unsigned char";
const char* PrimitiveTypeTraits<wchar_t>::s_typeName				= "wchar_t";
const char* PrimitiveTypeTraits<short>::s_typeName					= "short";
const char* PrimitiveTypeTraits<unsigned short>::s_typeName			= "unsigned short";
const char* PrimitiveTypeTraits<long>::s_typeName					= "long";
const char* PrimitiveTypeTraits<unsigned long>::s_typeName			= "unsigned long";
const char* PrimitiveTypeTraits<long long>::s_typeName				= "long long";
const char* PrimitiveTypeTraits<unsigned long long>::s_typeName		= "unsigned long long";
const char* PrimitiveTypeTraits<int>::s_typeName					= "int";
const char* PrimitiveTypeTraits<unsigned int>::s_typeName			= "unsigned int";
const char* PrimitiveTypeTraits<float>::s_typeName					= "float";
const char* PrimitiveTypeTraits<double>::s_typeName					= "double";
const char* PrimitiveTypeTraits<long double>::s_typeName			= "long double";



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
