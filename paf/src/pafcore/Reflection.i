#import "Type.i"
#import "TypeAlias.i"
#import "PrimitiveType.i"
#import "EnumType.i"
#import "String.i"

#{
#include "Utility.h"
#include "Variant.h"
#include "PrimitiveType.h"
#include "EnumType.h"
#}

namespace pafcore
{
	class(value_object) #PAFCORE_EXPORT Reflection
	{
		static String GetTypeFullName(Type* type);
		static String GetTypeAliasFullName(TypeAlias* typeAlias);
		static Type* GetTypeFromFullName(const char* fullName);
#{
		static String PrimitiveToString(const Variant& value);
		static void StringToPrimitive(Variant& value, PrimitiveType* primitiveType, const char* str);
		
		static String EnumToString(const Variant& value);
		static bool StringToEnum(Variant& value, EnumType* enumType, const char* str);
		
		static String ObjectToString(const Variant& value);
		static bool StringToObject(Variant& value, ClassType* classType, const char* str);

		static String InstancePropertyToString(Reference* that, InstanceProperty* instanceProperty);
		static String InstancePropertyToString(Variant* that, InstanceProperty* instanceProperty);
		static ErrorCode StringToInstanceProperty(Variant& that, InstanceProperty* instanceProperty, const char* str);
		static ErrorCode StringToInstanceProperty(Variant& that, const char* propertyName, const char* str);

		static ErrorCode NewObject(Variant& result, ClassType* type);

		//static ErrorCode CallInstanceMethod(Variant& result, Reference* that, const char* methodName, Variant** args, int_t numArgs);
#}
	};
}
