#import "Type.i"

$*
#include "Variant.h"
#include "Argument.h"
#include "Result.h"
#include "StaticMethod.h"
#include "NameSpace.h"
#include <algorithm>

#pragma warning( push )
#pragma warning( disable : 4804 )
#pragma warning( disable : 4800 )
#pragma warning( disable : 4146 )
*$

namespace pafcore
{
	$*
	enum PrimitiveTypeCategory
	{
		bool_type,
		char_type,
		signed_char_type,
		unsigned_char_type,
		wchar_type,
		short_type,
		unsigned_short_type,
		int_type,
		unsigned_int_type,
		long_type,
		unsigned_long_type,
		long_long_type,
		unsigned_long_long_type,
		float_type,
		double_type,
		long_double_type,
	};	
	*$

	abstract class $PAFCORE_EXPORT PrimitiveType(primitive_type) : Type
	{
		size_t _getMemberCount_();
		Metadata ptr _getMember_(size_t index);
		Metadata ptr _findMember_(const char ptr name);

		$*
	public:
		PrimitiveType(const char* name) : Type(name, primitive_object)
		{}
	public:
		static PrimitiveTypeCategory GetPromotedTypeCategory(PrimitiveTypeCategory typeCategory);
		static PrimitiveTypeCategory GetPromotedTypeCategory(PrimitiveTypeCategory typeCategory1, PrimitiveTypeCategory typeCategory2);
	public:
		Metadata* findTypeMember(const char* name);
		virtual Metadata* findMember(const char* name);
		virtual bool castTo(void* dst, Type* otherType, const void* src) = 0;
		//dst = +arg
		virtual void _op_pos_(void* dst, const void* arg) = 0;
		//dst = -arg
		virtual void _op_neg_(void* dst, const void* arg) = 0;
		//dst = ++arg
		virtual void _op_inc_(void* dst, void* arg) = 0;
		//dst = arg++
		virtual void _op_post_inc_(void* dst, void* arg) = 0;
		//dst = --arg
		virtual void _op_dec_(void* dst, void* arg) = 0;
		//dst = arg--
		virtual void _op_post_dec_(void* dst, void* arg) = 0;
		//dst = arg1 + arg2
		virtual void _op_add_(void* dst, const void* arg1, const void* arg2) = 0;
		//dst = arg1 - arg2
		virtual void _op_sub_(void* dst, const void* arg1, const void* arg2) = 0;
		//dst = arg1 * arg2
		virtual void _op_mul_(void* dst, const void* arg1, const void* arg2) = 0;
		//dst = arg1 / arg2
		virtual void _op_div_(void* dst, const void* arg1, const void* arg2) = 0;
		//dst = arg1 % arg2
		virtual void _op_mod_(void* dst, const void* arg1, const void* arg2) = 0;
		//arg1 < arg2
		virtual bool _op_less_than_(const void* arg1, const void* arg2) = 0;
		//arg1 <= arg2
		virtual bool _op_less_equal_(const void* arg1, const void* arg2) = 0;
		//arg1 == arg2
		virtual bool _op_equal_to_(const void* arg1, const void* arg2) = 0;
		//arg1 != arg2
		virtual bool _op_not_equal_to_(const void* arg1, const void* arg2) = 0;
		//arg1 >= arg2
		virtual bool _op_greater_equal_(const void* arg1, const void* arg2) = 0;
		//arg1 > arg2
		virtual bool _op_greater_than_(const void* arg1, const void* arg2) = 0;
		//!arg1
		virtual bool _op_not_(const void* arg) = 0;
		//arg1 && arg2
		virtual bool _op_and_(const void* arg1, const void* arg2) = 0;
		//arg1 || arg2
		virtual bool _op_or_(const void* arg1, const void* arg2) = 0;
		//dst = ~arg
		virtual void _op_bit_not_(void* dst, const void* arg) = 0;
		//dst = arg1 & arg2
		virtual void _op_bit_and_(void* dst, const void* arg1, const void* arg2) = 0;
		//dst = arg1 | arg2
		virtual void _op_bit_or_(void* dst, const void* arg1, const void* arg2) = 0;
		//dst = arg1 ^ arg2
		virtual void _op_bit_xor_(void* dst, const void* arg1, const void* arg2) = 0;
		//dst = arg1 << arg2
		virtual void _op_left_shift_(void* dst, const void* arg1, const void* arg2) = 0;
		//dst = arg1 >> arg2
		virtual void _op_right_shift_(void* dst, const void* arg1, const void* arg2) = 0;
	public:
		static ErrorCode Primitive___op_pos_(Variant* result, Variant** args, int_t numArgs);
		static ErrorCode Primitive___op_neg_(Variant* result, Variant** args, int_t numArgs);
		static ErrorCode Primitive___op_add_(Variant* result, Variant** args, int_t numArgs);
		static ErrorCode Primitive___op_sub_(Variant* result, Variant** args, int_t numArgs);
		static ErrorCode Primitive___op_mul_(Variant* result, Variant** args, int_t numArgs);
		static ErrorCode Primitive___op_div_(Variant* result, Variant** args, int_t numArgs);
		static ErrorCode Primitive___op_less_than_(Variant* result, Variant** args, int_t numArgs);
		static ErrorCode Primitive___op_less_equal_(Variant* result, Variant** args, int_t numArgs);
		static ErrorCode Primitive___op_equal_to_(Variant* result, Variant** args, int_t numArgs);
		static ErrorCode Primitive___op_not_equal_to_(Variant* result, Variant** args, int_t numArgs);
		static ErrorCode Primitive___op_greater_equal_(Variant* result, Variant** args, int_t numArgs);
		static ErrorCode Primitive___op_greater_than_(Variant* result, Variant** args, int_t numArgs);
		static ErrorCode Primitive___op_not_(Variant* result, Variant** args, int_t numArgs);
		static ErrorCode Primitive___op_and_(Variant* result, Variant** args, int_t numArgs);
		static ErrorCode Primitive___op_or_(Variant* result, Variant** args, int_t numArgs);
		static ErrorCode Primitive___op_add_assign_(Variant* result, Variant** args, int_t numArgs);
		static ErrorCode Primitive___op_sub_assign_(Variant* result, Variant** args, int_t numArgs);
		static ErrorCode Primitive___op_mul_assign_(Variant* result, Variant** args, int_t numArgs);
		static ErrorCode Primitive___op_div_assign_(Variant* result, Variant** args, int_t numArgs);

		//integer only
		static ErrorCode Primitive___op_inc_(Variant* result, Variant** args, int_t numArgs);
		static ErrorCode Primitive___op_post_inc_(Variant* result, Variant** args, int_t numArgs);
		static ErrorCode Primitive___op_dec_(Variant* result, Variant** args, int_t numArgs);
		static ErrorCode Primitive___op_post_dec_(Variant* result, Variant** args, int_t numArgs);
		static ErrorCode Primitive___op_mod_(Variant* result, Variant** args, int_t numArgs);
		static ErrorCode Primitive___op_bit_not_(Variant* result, Variant** args, int_t numArgs);
		static ErrorCode Primitive___op_bit_and_(Variant* result, Variant** args, int_t numArgs);
		static ErrorCode Primitive___op_bit_or_(Variant* result, Variant** args, int_t numArgs);
		static ErrorCode Primitive___op_bit_xor_(Variant* result, Variant** args, int_t numArgs);
		static ErrorCode Primitive___op_left_shift_(Variant* result, Variant** args, int_t numArgs);
		static ErrorCode Primitive___op_right_shift_(Variant* result, Variant** args, int_t numArgs);
	public:
		PrimitiveTypeCategory m_typeCategory;
		StaticMethod* m_staticMethods;
		size_t m_staticMethodCount;
		*$
	};

	$*
	template<typename T>
	struct PAFCORE_EXPORT PrimitiveTypeTraits
	{
	};

	template<>
	struct PAFCORE_EXPORT PrimitiveTypeTraits<bool>
	{
		enum { type_category = bool_type };
		typedef int PromotedType;
		static const char* s_typeName;;
	};

	template<>
	struct PAFCORE_EXPORT PrimitiveTypeTraits<char>
	{
		enum { type_category = char_type };
		typedef int PromotedType;
		static const char* s_typeName;;
	};

	template<>
	struct PAFCORE_EXPORT PrimitiveTypeTraits<unsigned char>
	{
		enum { type_category = unsigned_char_type };
		typedef int PromotedType;
		static const char* s_typeName;;
	};


	template<>
	struct PAFCORE_EXPORT PrimitiveTypeTraits<signed char>
	{
		enum { type_category = signed_char_type };
		typedef int PromotedType;
		static const char* s_typeName;;
	};

	template<>
	struct PAFCORE_EXPORT PrimitiveTypeTraits<wchar_t>
	{
		enum { type_category = wchar_type };
		typedef int PromotedType;
		static const char* s_typeName;;
	};

	template<>
	struct PAFCORE_EXPORT PrimitiveTypeTraits<short>
	{
		enum { type_category = short_type };
		typedef int PromotedType;
		static const char* s_typeName;;
	};

	template<>
	struct PAFCORE_EXPORT PrimitiveTypeTraits<unsigned short>
	{
		enum { type_category = unsigned_short_type };
		typedef int PromotedType;
		static const char* s_typeName;;
	};

	template<>
	struct PAFCORE_EXPORT PrimitiveTypeTraits<int>
	{
		enum { type_category = int_type };
		typedef int PromotedType;
		static const char* s_typeName;;
	};

	template<>
	struct PAFCORE_EXPORT PrimitiveTypeTraits<unsigned int>
	{
		enum { type_category = unsigned_int_type };
		typedef unsigned int PromotedType;
		static const char* s_typeName;;
	};

	template<>
	struct PAFCORE_EXPORT PrimitiveTypeTraits<long>
	{
		enum { type_category = long_type };
		typedef long PromotedType;
		static const char* s_typeName;;
	};

	template<>
	struct PAFCORE_EXPORT PrimitiveTypeTraits<unsigned long>
	{
		enum { type_category = unsigned_long_type };
		typedef unsigned long PromotedType;
		static const char* s_typeName;;
	};

	template<>
	struct PAFCORE_EXPORT PrimitiveTypeTraits<long long>
	{
		enum { type_category = long_long_type };
		typedef long long PromotedType;
		static const char* s_typeName;;
	};

	template<>
	struct PAFCORE_EXPORT PrimitiveTypeTraits<unsigned long long>
	{
		enum { type_category = unsigned_long_long_type };
		typedef unsigned long long PromotedType;
		static const char* s_typeName;;
	};

	template<>
	struct PAFCORE_EXPORT PrimitiveTypeTraits<float>
	{
		enum { type_category = float_type };
		typedef float PromotedType;
		static const char* s_typeName;;
	};

	template<>
	struct PAFCORE_EXPORT PrimitiveTypeTraits<double>
	{
		enum { type_category = double_type };
		typedef double PromotedType;
		static const char* s_typeName;;
	};

	template<>
	struct PAFCORE_EXPORT PrimitiveTypeTraits<long double>
	{
		enum { type_category = long_double_type };
		typedef long double PromotedType;
		static const char* s_typeName;;
	};

	template<typename T1, typename T2>
	struct PrimitiveTypeConversion_2
	{
		typedef T2 ConvertedType;
	};

	template<>
	struct PrimitiveTypeConversion_2<unsigned int, long>
	{
		typedef unsigned long ConvertedType;
	};

	template<typename T1, typename T2, bool less>
	struct PrimitiveTypeConversion_1
	{
		typedef typename PrimitiveTypeConversion_2<T1, T2>::ConvertedType ConvertedType;
	};

	template<typename T1, typename T2>
	struct PrimitiveTypeConversion_1<T1, T2, false>
	{
		typedef typename PrimitiveTypeConversion_2<T2, T1>::ConvertedType ConvertedType;
	};

	template<typename T1, typename T2>
	struct PrimitiveTypeConversion
	{
		enum { less = PrimitiveTypeTraits<T1>::type_category < PrimitiveTypeTraits<T2>::type_category ?  1 : 0};

		typedef typename PrimitiveTypeConversion_1<typename PrimitiveTypeTraits<T1>::PromotedType, 
			typename PrimitiveTypeTraits<T2>::PromotedType, less>::ConvertedType  ConvertedType;
	};

	template<typename T>
	class PAFCORE_EXPORT PrimitiveTypeImpl : public PrimitiveType
	{
	public:
		typedef T ValueType;
	public:
		PrimitiveTypeImpl(const char* name) : PrimitiveType(name)
		{
			m_typeCategory = (PrimitiveTypeCategory)PrimitiveTypeTraits<T>::type_category;
			m_name = name;
			m_size = sizeof(T);

			static Result s_Clone_1_Result(this, false, Result::by_new);
			static Argument s_Clone_1_Arguments[] = 
			{
				Argument("value", this, Argument::by_ref),
			};
			static ::pafcore::Overload s_Clone_Overloads[] = 
			{
				::pafcore::Overload(&s_Clone_1_Result, s_Clone_1_Arguments, 1),
			};

			static Result s_New_0_Result(this, false, Result::by_new);
			static Result s_New_1_Result(this, false, Result::by_new);
			static Argument s_New_1_Arguments[] = 
			{
				Argument("value", this, Argument::by_value),
			};

			static Overload s_New_Overloads[] =
			{
				Overload(&s_New_0_Result, 0, 0),
				Overload(&s_New_1_Result, s_New_1_Arguments, 1),
			};

			static Result s_NewArray_1_Result(this, false, Result::by_new_array);
			static Argument s_NewArray_1_Arguments[] = 
			{
				Argument("count", RuntimeTypeOf<size_t>::RuntimeType::GetSingleton(), Argument::by_value),
			};
			static Overload s_NewArray_Overloads[] =
			{
				Overload(&s_NewArray_1_Result, s_NewArray_1_Arguments, 1),
			};
			static StaticMethod s_staticMethods[] = 
			{
				StaticMethod("Clone", Primitive_Clone, s_Clone_Overloads, 1),
				StaticMethod("New", Primitive_New, s_New_Overloads, 2),
				StaticMethod("NewArray", Primitive_NewArray, s_NewArray_Overloads, 1),			
			};

			m_staticMethods = s_staticMethods;
			m_staticMethodCount = array_size_of(s_staticMethods);

			NameSpace::GetGlobalNameSpace()->registerMember(this);
		}
		static ErrorCode Primitive_Clone(Variant* result, Variant** args, int_t numArgs)
		{
			if(1 == numArgs)
			{
				T a0;
				if(!args[0]->castToPrimitive(RuntimeTypeOf<T>::RuntimeType::GetSingleton(), &a0))
				{
					return e_invalid_arg_type_1;
				}
				result->assignPrimitive(RuntimeTypeOf<T>::RuntimeType::GetSingleton(), &a0);
				return s_ok;
			}
			return e_invalid_arg_num;
		}
		static ErrorCode Primitive_New(Variant* result, Variant** args, int_t numArgs)
		{
			if(1 < numArgs)
			{
				return e_invalid_arg_num;
			}
			T a0 = 0;
			if(1 == numArgs)
			{
				if(!args[0]->castToPrimitive(RuntimeTypeOf<T>::RuntimeType::GetSingleton(), &a0))
				{
					return e_invalid_arg_type_1;
				}
			}
			result->assignPrimitive(RuntimeTypeOf<T>::RuntimeType::GetSingleton(), &a0);
			return s_ok;
		}
		static ErrorCode Primitive_NewArray(Variant* result, Variant** args, int_t numArgs)
		{
			if(1 == numArgs)
			{
				size_t count;
				if(!args[0]->castToPrimitive(RuntimeTypeOf<size_t>::RuntimeType::GetSingleton(), &count))
				{
					return e_invalid_arg_type_1;
				}
				T* ptr = new_array<T>(count);
				result->assignArray(RuntimeTypeOf<T>::RuntimeType::GetSingleton(), ptr, count, false, Variant::by_new_array);
				return s_ok;
			}
			return e_invalid_arg_num;
		}
		virtual void destroyArray(void* address)
		{
			delete_array((T*)address);
		}
		virtual bool castTo(void* dst, Type* otherType, const void* src)
		{
			if(!otherType->isPrimitive())
			{
				return false;
			}
			switch (static_cast<PrimitiveType*>(otherType)->m_typeCategory)
			{
			case bool_type:
				*reinterpret_cast<bool_t*>(dst) = *reinterpret_cast<const T*>(src) != 0;
				break;
			case char_type:
				*reinterpret_cast<char_t*>(dst) = static_cast<char_t>(*reinterpret_cast<const T*>(src));
				break;
			case signed_char_type:
				*reinterpret_cast<schar_t*>(dst) = static_cast<char_t>(*reinterpret_cast<const T*>(src));
				break;
			case unsigned_char_type:
				*reinterpret_cast<uchar_t*>(dst) = static_cast<uchar_t>(*reinterpret_cast<const T*>(src));
				break;
			case wchar_type:
				*reinterpret_cast<wchar_t*>(dst) = static_cast<wchar_t>(*reinterpret_cast<const T*>(src));
				break;
			case short_type:
				*reinterpret_cast<short_t*>(dst) = static_cast<short_t>(*reinterpret_cast<const T*>(src));
				break;
			case unsigned_short_type:
				*reinterpret_cast<ushort_t*>(dst) = static_cast<ushort_t>(*reinterpret_cast<const T*>(src));
				break;
			case int_type:
				*reinterpret_cast<int_t*>(dst) = static_cast<int_t>(*reinterpret_cast<const T*>(src));
				break;
			case unsigned_int_type:
				*reinterpret_cast<uint_t*>(dst) = static_cast<uint_t>(*reinterpret_cast<const T*>(src));
				break;
			case long_type:
				*reinterpret_cast<long_t*>(dst) = static_cast<long_t>(*reinterpret_cast<const T*>(src));
				break;
			case unsigned_long_type:
				*reinterpret_cast<ulong_t*>(dst) = static_cast<ulong_t>(*reinterpret_cast<const T*>(src));
				break;
			case long_long_type:
				*reinterpret_cast<longlong_t*>(dst) = static_cast<longlong_t>(*reinterpret_cast<const T*>(src));
				break;
			case unsigned_long_long_type:
				*reinterpret_cast<ulonglong_t*>(dst) = static_cast<ulonglong_t>(*reinterpret_cast<const T*>(src));
				break;
			case float_type:
				*reinterpret_cast<float_t*>(dst) = static_cast<float_t>(*reinterpret_cast<const T*>(src));
				break;
			case double_type:
				*reinterpret_cast<double_t*>(dst) = static_cast<double_t>(*reinterpret_cast<const T*>(src));
				break;
			case long_double_type:
				*reinterpret_cast<longdouble_t*>(dst) = static_cast<longdouble_t>(*reinterpret_cast<const T*>(src));
				break;
			default:
				return false;
			}
			return true;
		}
		virtual void _op_pos_(void* dst, const void* arg)
		{
			*reinterpret_cast<T*>(dst) = *reinterpret_cast<const T*>(arg);
		}
		virtual void _op_neg_(void* dst, const void* arg)
		{
			*reinterpret_cast<T*>(dst) = -*reinterpret_cast<const T*>(arg);
		}
		virtual void _op_add_(void* dst, const void* arg1, const void* arg2)
		{
			*reinterpret_cast<T*>(dst) = *reinterpret_cast<const T*>(arg1) + *reinterpret_cast<const T*>(arg2);
		}
		virtual void _op_sub_(void* dst, const void* arg1, const void* arg2)
		{
			*reinterpret_cast<T*>(dst) = *reinterpret_cast<const T*>(arg1) - *reinterpret_cast<const T*>(arg2);
		}
		void _op_mul_(void* dst, const void* arg1, const void* arg2)
		{
			*reinterpret_cast<T*>(dst) = *reinterpret_cast<const T*>(arg1) * *reinterpret_cast<const T*>(arg2);
		}
		virtual void _op_div_(void* dst, const void* arg1, const void* arg2)
		{
			*reinterpret_cast<T*>(dst) = *reinterpret_cast<const T*>(arg1) / *reinterpret_cast<const T*>(arg2);
		}
		virtual bool _op_less_than_(const void* arg1, const void* arg2)
		{
			return *reinterpret_cast<const T*>(arg1) < *reinterpret_cast<const T*>(arg2);
		}
		virtual bool _op_less_equal_(const void* arg1, const void* arg2)
		{
			return *reinterpret_cast<const T*>(arg1) <= *reinterpret_cast<const T*>(arg2);
		}
		virtual bool _op_equal_to_(const void* arg1, const void* arg2)
		{
			return *reinterpret_cast<const T*>(arg1) == *reinterpret_cast<const T*>(arg2);
		}
		virtual bool _op_not_equal_to_(const void* arg1, const void* arg2)
		{
			return *reinterpret_cast<const T*>(arg1) != *reinterpret_cast<const T*>(arg2);
		}
		virtual bool _op_greater_equal_(const void* arg1, const void* arg2)
		{
			return *reinterpret_cast<const T*>(arg1) >= *reinterpret_cast<const T*>(arg2);
		}
		virtual bool _op_greater_than_(const void* arg1, const void* arg2)
		{
			return *reinterpret_cast<const T*>(arg1) > *reinterpret_cast<const T*>(arg2);
		}
		virtual bool _op_not_(const void* arg)
		{
			return !*reinterpret_cast<const T*>(arg);
		}
		virtual bool _op_and_(const void* arg1, const void* arg2)
		{
			return *reinterpret_cast<const T*>(arg1) && *reinterpret_cast<const T*>(arg2);
		}
		virtual bool _op_or_(const void* arg1, const void* arg2)
		{
			return *reinterpret_cast<const T*>(arg1) || *reinterpret_cast<const T*>(arg2);
		}
	};
	
	template<typename T>
	class PAFCORE_EXPORT PrimitiveTypeImpl_Bool : public PrimitiveTypeImpl<T>
	{
	public:
		typedef PrimitiveTypeImpl_Bool<T> ThisType;
	public:
		PrimitiveTypeImpl_Bool(const char* name) : PrimitiveTypeImpl(name)
		{}
		static ThisType* GetSingleton()
		{
			static ThisType s_instance(PrimitiveTypeTraits<T>::s_typeName);
			return &s_instance;
		}
		virtual void _op_inc_(void* dst, void* arg)
		{}
		virtual void _op_post_inc_(void* dst, void* arg)
		{}
		virtual void _op_dec_(void* dst, void* arg)
		{}
		virtual void _op_post_dec_(void* dst, void* arg)
		{}
		void _op_mod_(void* dst, const void* arg1, const void* arg2)
		{}
		virtual void _op_bit_not_(void* dst, const void* arg)
		{}
		virtual void _op_bit_and_(void* dst, const void* arg1, const void* arg2)
		{}
		virtual void _op_bit_or_(void* dst, const void* arg1, const void* arg2)
		{}
		virtual void _op_bit_xor_(void* dst, const void* arg1, const void* arg2)
		{}
		virtual void _op_left_shift_(void* dst, const void* arg1, const void* arg2)
		{}
		virtual void _op_right_shift_(void* dst, const void* arg1, const void* arg2)
		{}
	};

	template<typename T>
	class PAFCORE_EXPORT PrimitiveTypeImpl_Integer : public PrimitiveTypeImpl<T>
	{
	public:
		typedef PrimitiveTypeImpl_Integer<T> ThisType;
	public:
		PrimitiveTypeImpl_Integer(const char* name) : PrimitiveTypeImpl(name)
		{}
		static ThisType* GetSingleton()
		{
			static ThisType s_instance(PrimitiveTypeTraits<T>::s_typeName);
			return &s_instance;
		}
		virtual void _op_inc_(void* dst, void* arg)
		{
			*reinterpret_cast<T*>(dst) = ++(*reinterpret_cast<T*>(arg));
		}
		virtual void _op_post_inc_(void* dst, void* arg)
		{
			*reinterpret_cast<T*>(dst) = (*reinterpret_cast<T*>(arg))++;
		}
		virtual void _op_dec_(void* dst, void* arg)
		{
			*reinterpret_cast<T*>(dst) = --*reinterpret_cast<T*>(arg);
		}
		virtual void _op_post_dec_(void* dst, void* arg)
		{
			*reinterpret_cast<T*>(dst) = (*reinterpret_cast<T*>(arg))--;
		}
		virtual void _op_mod_(void* dst, const void* arg1, const void* arg2)
		{
			*reinterpret_cast<T*>(dst) = *reinterpret_cast<const T*>(arg1) % *reinterpret_cast<const T*>(arg2);
		}
		virtual void _op_bit_not_(void* dst, const void* arg)
		{
			*reinterpret_cast<T*>(dst) = ~*reinterpret_cast<const T*>(arg);
		}
		virtual void _op_bit_and_(void* dst, const void* arg1, const void* arg2)
		{
			*reinterpret_cast<T*>(dst) = *reinterpret_cast<const T*>(arg1) & *reinterpret_cast<const T*>(arg2);
		}
		virtual void _op_bit_or_(void* dst, const void* arg1, const void* arg2)
		{
			*reinterpret_cast<T*>(dst) = *reinterpret_cast<const T*>(arg1) | *reinterpret_cast<const T*>(arg2);
		}
		virtual void _op_bit_xor_(void* dst, const void* arg1, const void* arg2)
		{
			*reinterpret_cast<T*>(dst) = *reinterpret_cast<const T*>(arg1) ^ *reinterpret_cast<const T*>(arg2);
		}
		virtual void _op_left_shift_(void* dst, const void* arg1, const void* arg2)
		{
			*reinterpret_cast<T*>(dst) = *reinterpret_cast<const T*>(arg1) << *reinterpret_cast<const char*>(arg2);
		}
		virtual void _op_right_shift_(void* dst, const void* arg1, const void* arg2)
		{
			*reinterpret_cast<T*>(dst) = *reinterpret_cast<const T*>(arg1) >> *reinterpret_cast<const char*>(arg2);
		}
	};

	template<typename T>
	class PAFCORE_EXPORT PrimitiveTypeImpl_Real : public PrimitiveTypeImpl<T>
	{
	public:
		typedef PrimitiveTypeImpl_Real<T> ThisType;
	public:
		PrimitiveTypeImpl_Real(const char* name) : PrimitiveTypeImpl(name)
		{}
		static ThisType* GetSingleton()
		{
			static ThisType s_instance(PrimitiveTypeTraits<T>::s_typeName);
			return &s_instance;
		}
		virtual void _op_inc_(void* dst, void* arg)
		{}
		virtual void _op_post_inc_(void* dst, void* arg)
		{}
		virtual void _op_dec_(void* dst, void* arg)
		{}
		virtual void _op_post_dec_(void* dst, void* arg)
		{}
		void _op_mod_(void* dst, const void* arg1, const void* arg2)
		{}
		virtual void _op_bit_not_(void* dst, const void* arg)
		{}
		virtual void _op_bit_and_(void* dst, const void* arg1, const void* arg2)
		{}
		virtual void _op_bit_or_(void* dst, const void* arg1, const void* arg2)
		{}
		virtual void _op_bit_xor_(void* dst, const void* arg1, const void* arg2)
		{}
		virtual void _op_left_shift_(void* dst, const void* arg1, const void* arg2)
		{}
		virtual void _op_right_shift_(void* dst, const void* arg1, const void* arg2)
		{}
	};

	typedef PrimitiveTypeImpl_Bool<bool>					BoolType;
	typedef PrimitiveTypeImpl_Integer<char>					CharType;
	typedef PrimitiveTypeImpl_Integer<signed char>			SignedCharType;
	typedef PrimitiveTypeImpl_Integer<unsigned char>		UnsignedCharType;
	typedef PrimitiveTypeImpl_Integer<wchar_t>				WcharType;
	typedef PrimitiveTypeImpl_Integer<short>				ShortType;
	typedef PrimitiveTypeImpl_Integer<unsigned short>		UnsignedShortType;
	typedef PrimitiveTypeImpl_Integer<int>					IntType;
	typedef PrimitiveTypeImpl_Integer<unsigned int>			UnsignedIntType;
	typedef PrimitiveTypeImpl_Integer<long>					LongType;
	typedef PrimitiveTypeImpl_Integer<unsigned long>		UnsignedLongType;
	typedef PrimitiveTypeImpl_Integer<long long>			LongLongType;
	typedef PrimitiveTypeImpl_Integer<unsigned long long>	UnsignedLongLongType;
	typedef PrimitiveTypeImpl_Real<float>					FloatType;
	typedef PrimitiveTypeImpl_Real<double>					DoubleType;
	typedef PrimitiveTypeImpl_Real<long double>				LongDoubleType;

	*$
}

$*
template<>
struct RuntimeTypeOf<bool>
{
	typedef ::pafcore::BoolType RuntimeType;
	enum {type_category = ::pafcore::primitive_object};
};

template<>
struct RuntimeTypeOf<char>
{
	typedef ::pafcore::CharType RuntimeType;
	enum {type_category = ::pafcore::primitive_object};
};

template<>
struct RuntimeTypeOf<signed char>
{
	typedef ::pafcore::SignedCharType RuntimeType;
	enum {type_category = ::pafcore::primitive_object};
};

template<>
struct RuntimeTypeOf<unsigned char>
{
	typedef ::pafcore::UnsignedCharType RuntimeType;
	enum {type_category = ::pafcore::primitive_object};
};

template<>
struct RuntimeTypeOf<wchar_t>
{
	typedef ::pafcore::WcharType RuntimeType;
	enum {type_category = ::pafcore::primitive_object};
};

template<>
struct RuntimeTypeOf<short>
{
	typedef ::pafcore::ShortType RuntimeType;
	enum {type_category = ::pafcore::primitive_object};
};

template<>
struct RuntimeTypeOf<unsigned short>
{
	typedef ::pafcore::UnsignedShortType RuntimeType;
	enum {type_category = ::pafcore::primitive_object};
};

template<>
struct RuntimeTypeOf<long>
{
	typedef ::pafcore::LongType RuntimeType;
	enum {type_category = ::pafcore::primitive_object};
};

template<>
struct RuntimeTypeOf<unsigned long>
{
	typedef ::pafcore::UnsignedLongType RuntimeType;
	enum {type_category = ::pafcore::primitive_object};
};

template<>
struct RuntimeTypeOf<long long>
{
	typedef ::pafcore::LongLongType RuntimeType;
	enum {type_category = ::pafcore::primitive_object};
};

template<>
struct RuntimeTypeOf<unsigned long long>
{
	typedef ::pafcore::UnsignedLongLongType RuntimeType;
	enum {type_category = ::pafcore::primitive_object};
};

template<>
struct RuntimeTypeOf<int>
{
	typedef ::pafcore::IntType RuntimeType;
	enum {type_category = ::pafcore::primitive_object};
};

template<>
struct RuntimeTypeOf<unsigned int>
{
	typedef ::pafcore::UnsignedIntType RuntimeType;
	enum {type_category = ::pafcore::primitive_object};
};

template<>
struct RuntimeTypeOf<float>
{
	typedef ::pafcore::FloatType RuntimeType;
	enum {type_category = ::pafcore::primitive_object};
};

template<>
struct RuntimeTypeOf<double>
{
	typedef ::pafcore::DoubleType RuntimeType;
	enum {type_category = ::pafcore::primitive_object};
};

template<>
struct RuntimeTypeOf<long double>
{
	typedef ::pafcore::LongDoubleType RuntimeType;
	enum {type_category = ::pafcore::primitive_object};
};

#pragma warning( pop ) 
*$