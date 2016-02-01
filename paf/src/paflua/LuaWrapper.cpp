#include "LuaWrapper.h"
#include "lua.hpp"
#include "../pafcore/Variant.h"
#include "../pafcore/NameSpace.h"
#include "../pafcore/NameSpace.mh"
#include "../pafcore/Metadata.mh"
#include "../pafcore/Type.mh"
#include "../pafcore/ClassType.h"
#include "../pafcore/EnumType.h"
#include "../pafcore/EnumType.mh"
#include "../pafcore/InstanceField.h"
#include "../pafcore/StaticField.h"
#include "../pafcore/InstanceProperty.h"
#include "../pafcore/StaticProperty.h"
#include "../pafcore/InstanceMethod.h"
#include "../pafcore/StaticMethod.h"
#include "../pafcore/Enumerator.h"
#include "../pafcore/PrimitiveType.h"
#include "LuaSubclassInvoker.h"

#include <new.h>
#include <string.h>
#include <assert.h>


BEGIN_PAFLUA


void stackDump (lua_State *L) 
{
	int i;
	int top = lua_gettop(L);
	for (i = 1; i <= top; i++) {
		int t = lua_type(L, i);
		switch (t) {
		case LUA_TSTRING:
			printf("string: %s", lua_tostring(L, i));
			break;
		case LUA_TBOOLEAN:
			printf(lua_toboolean(L, i) ? "true" : "false");
			break;
		case LUA_TNUMBER:
			if(lua_isinteger(L, i))
			{
				printf("integer: %lld", lua_tointeger(L, i));
			}
			else
			{
				printf("number: %g", lua_tonumber(L, i));
			}
			break;
		case LUA_TUSERDATA:
			printf("userdata: %s", lua_tostring(L, i));	
			break;
		default:
			printf("other: %s", lua_typename(L, t));
			break;
		}
		printf("\n");
	}
	printf("\n");
}


const char* metadata_metatable_name = "paf.Metadata";
const char* variant_metatable_name = "paf.Variant";
const size_t max_param_count = 20;


void Variant_Error(lua_State *L, const char* name, pafcore::ErrorCode errorCode)
{
	luaL_error(L, "idlcpp error: %s, Error: %d, %s", name, errorCode, pafcore::ErrorCodeToString(errorCode));
}

int Variant_GC(lua_State *L) 
{
	pafcore::Variant* variant = (pafcore::Variant*)luaL_checkudata(L, 1, variant_metatable_name);
	variant->~Variant();
	return 0;
}

pafcore::Variant* LuaToVariant(pafcore::Variant* value, lua_State *L, int index)
{
	pafcore::Variant* res = value;
	int type = lua_type(L, index);
	switch (type)
	{
	case LUA_TSTRING:
		{
			size_t len;
			const char* s = lua_tolstring(L, index, &len);
			if(value->m_type->isPrimitive() && value->byValue())
			{
				pafcore::PrimitiveType* primitiveType = static_cast<pafcore::PrimitiveType*>(value->m_type);
				if(pafcore::float_type == primitiveType->m_typeCategory ||
					pafcore::double_type == primitiveType->m_typeCategory ||
					pafcore::long_double_type == primitiveType->m_typeCategory)
				{
					lua_Number n = lua_tonumber(L, index);
					value->assignPrimitive(RuntimeTypeOf<lua_Number>::RuntimeType::GetSingleton(), &n);
				}
				else
				{
					lua_Integer i = lua_tointeger(L, index);
					value->assignPrimitive(RuntimeTypeOf<lua_Integer>::RuntimeType::GetSingleton(), &i);
				}
			}
			else
			{
				char* p = new_array<char>(len + 1);
				memcpy(p, s, len + 1);
				value->assignPrimitivePtr(RuntimeTypeOf<char>::RuntimeType::GetSingleton(), p, false, ::pafcore::Variant::by_new_array);
			}
		}
		break;
	case LUA_TBOOLEAN:
		{
			bool b = lua_toboolean(L, index) != 0;
			value->assignPrimitive(RuntimeTypeOf<bool>::RuntimeType::GetSingleton(), &b);
		}
		break;
	case LUA_TNUMBER:
		if(lua_isinteger(L, index))
		{
			lua_Integer i = lua_tointeger(L, index);
			value->assignPrimitive(RuntimeTypeOf<lua_Integer>::RuntimeType::GetSingleton(), &i);
		}
		else
		{
			lua_Number n = lua_tonumber(L, index);
			value->assignPrimitive(RuntimeTypeOf<lua_Number>::RuntimeType::GetSingleton(), &n);
		}
		break;
	case LUA_TUSERDATA:
		{
			pafcore::Variant* variant = (pafcore::Variant*)luaL_checkudata(L, index, variant_metatable_name);
			if(variant)
			{
				res = variant;
			}
		}
		break;
	}
	return res;
}

pafcore::Variant* VariantToLua(lua_State *L, pafcore::Variant* variant)
{
	void* p = lua_newuserdata(L, sizeof(pafcore::Variant));
	pafcore::Variant* res = new(p)pafcore::Variant;
	res->move(*variant);
	luaL_getmetatable(L, variant_metatable_name);
	lua_setmetatable(L, -2);
	return res;
}

int InvokeFunction(lua_State *L, pafcore::FunctionInvoker invoker, int numArgs, int startIndex)
{
	pafcore::Variant arguments[max_param_count];
	pafcore::Variant* args[max_param_count]; 
	if(numArgs > max_param_count)
	{
		numArgs = max_param_count;
	}
	for (int i = 0; i < numArgs; i++)
	{
		args[i] = LuaToVariant(&arguments[i], L, i + startIndex);
	}
	pafcore::Variant result;
	pafcore::ErrorCode errorCode = (*invoker)(&result, args, numArgs);
	if(pafcore::s_ok == errorCode)
	{
		VariantToLua(L, &result);
		return 1;
	}
	luaL_error(L, ErrorCodeToString(errorCode));
	return 0;
}

int InvokeFunction_CallOperator(lua_State *L, pafcore::FunctionInvoker invoker)
{
	int numArgs = lua_gettop(L) - 1;
	return InvokeFunction(L, invoker, numArgs, 2);
}

int InvokeFunction_ArithmeticOperator(lua_State *L, pafcore::FunctionInvoker invoker)
{
	int numArgs = lua_gettop(L);
	return InvokeFunction(L, invoker, numArgs, 1);
}

int InvokeFunction_ComparisonOperator(lua_State *L, pafcore::FunctionInvoker invoker)
{
	int numArgs = lua_gettop(L);
	pafcore::Variant arguments[max_param_count];
	pafcore::Variant* args[max_param_count]; 
	if(numArgs > max_param_count)
	{
		numArgs = max_param_count;
	}
	for (int i = 0; i < numArgs; i++)
	{
		args[i] = LuaToVariant(&arguments[i], L, i + 1);
	}
	pafcore::Variant result;
	pafcore::ErrorCode errorCode = (*invoker)(&result, args, numArgs);
	if(pafcore::s_ok == errorCode)
	{
		bool b = *reinterpret_cast<bool*>(result.m_pointer);
		lua_pushboolean(L, b ? 1 : 0);
		return 1;
	}
	luaL_error(L, ErrorCodeToString(errorCode));
	return 0;
}

int FunctionInvoker_Closure(lua_State *L)
{
	const void* p = lua_topointer(L, lua_upvalueindex(1));
	pafcore::FunctionInvoker invoker = (pafcore::FunctionInvoker)p;
	int numArgs = lua_gettop(L);
	return InvokeFunction(L, invoker, numArgs, 1);
}

int FunctionInvoker_Clone(lua_State *L, pafcore::FunctionInvoker invoker)
{
	return InvokeFunction(L, invoker, 1, 1);
}

pafcore::ErrorCode GetInstanceProperty(lua_State *L, pafcore::Variant* that, pafcore::InstanceProperty* property)
{
	if(0 == property->m_getter)
	{
		return pafcore::e_property_is_write_only;
	}
	pafcore::Variant value;
	pafcore::ErrorCode errorCode = (*property->m_getter)(that, &value);
	if(pafcore::s_ok == errorCode)
	{
		VariantToLua(L, &value);
	}
	return errorCode;
}

pafcore::ErrorCode SetInstanceProperty(lua_State *L, pafcore::Variant* that, pafcore::InstanceProperty* property)
{
	if(0 == property->m_setter)
	{
		return pafcore::e_property_is_read_only;
	}
	pafcore::Variant value;
	pafcore::Variant* arg = LuaToVariant(&value, L, 3);
	pafcore::ErrorCode errorCode = (*property->m_setter)(that, arg);
	return errorCode;
}


pafcore::ErrorCode GetStaticProperty(lua_State *L, pafcore::StaticProperty* property)
{
	if(0 == property->m_getter)
	{
		return pafcore::e_property_is_write_only;
	}
	pafcore::Variant value;
	pafcore::ErrorCode errorCode = (*property->m_getter)(&value);
	if(pafcore::s_ok == errorCode)
	{
		VariantToLua(L, &value);
	}
	return errorCode;
}

pafcore::ErrorCode SetStaticProperty(lua_State *L, pafcore::StaticProperty* property)
{
	if(0 == property->m_setter)
	{
		return pafcore::e_property_is_read_only;
	}

	pafcore::Variant value;
	pafcore::Variant* arg = LuaToVariant(&value, L, 3);
	pafcore::ErrorCode errorCode = (*property->m_setter)(arg);
	return errorCode;
}


pafcore::ErrorCode GetNestedType(lua_State *L, pafcore::Type* nestedType)
{
	pafcore::Variant value;
	value.assignReferencePtr(RuntimeTypeOf<pafcore::Type>::RuntimeType::GetSingleton(), nestedType, false, ::pafcore::Variant::by_ptr);
	VariantToLua(L, &value);
	return pafcore::s_ok;
}

pafcore::ErrorCode GetInstanceField(lua_State *L, pafcore::Variant* that, pafcore::InstanceField* field)
{
	size_t baseOffset;
	if(!static_cast<pafcore::ClassType*>(that->m_type)->getBaseClassOffset(baseOffset, field->m_objectType))
	{
		return pafcore::e_invalid_type;
	}
	size_t fieldAddress = (size_t)that->m_pointer + baseOffset + field->m_offset;
	pafcore::Variant value;
	
	if(field->isArray())
	{
		value.assignArray(field->m_type, (void*)fieldAddress, field->m_arraySize, field->m_constant, ::pafcore::Variant::by_array);
	}
	else
	{
		value.assignPtr(field->m_type, (void*)fieldAddress, field->m_constant, ::pafcore::Variant::by_ref);
	}
	VariantToLua(L, &value);
	return pafcore::s_ok;
}

pafcore::ErrorCode SetInstanceField(lua_State *L, pafcore::Variant* that, pafcore::InstanceField* field)
{
	if(field->isArray())
	{
		return pafcore::e_field_is_an_array;
	}
	if(field->isConstant())
	{
		return pafcore::e_field_is_constant;
	}
	size_t baseOffset;
	if(!static_cast<pafcore::ClassType*>(that->m_type)->getBaseClassOffset(baseOffset, field->m_objectType))
	{
		return pafcore::e_invalid_object_type;
	}
	size_t fieldAddress = (size_t)that->m_pointer + baseOffset + field->m_offset;
	pafcore::Variant value;
	pafcore::Variant* arg = LuaToVariant(&value, L, 3);
	if(!arg->castToObject(field->m_type, (void*)fieldAddress))
	{
		return pafcore::e_invalid_field_type;
	}
	return pafcore::s_ok;
}

pafcore::ErrorCode GetStaticField(lua_State *L, pafcore::StaticField* field)
{
	pafcore::Variant value;
	if(field->isArray())
	{
		value.assignArray(field->m_type, (void*)field->m_address, field->m_arraySize, field->m_constant, ::pafcore::Variant::by_array);
	}
	else
	{
		value.assignPtr(field->m_type, (void*)field->m_address, field->m_constant, ::pafcore::Variant::by_ref);
	}
	VariantToLua(L, &value);
	return pafcore::s_ok;
}

pafcore::ErrorCode SetStaticField(lua_State *L, pafcore::StaticField* field)
{
	if(field->isArray())
	{
		return pafcore::e_field_is_an_array;
	}
	if(field->isConstant())
	{
		return pafcore::e_field_is_constant;
	}
	pafcore::Variant value;
	pafcore::Variant* arg = LuaToVariant(&value, L, 3);
	if(!arg->castToObject(field->m_type, (void*)field->m_address))
	{
		return pafcore::e_invalid_field_type;
	}
	return pafcore::s_ok;
}

pafcore::ErrorCode GetPrimitiveOrEnum(lua_State *L, pafcore::Variant* variant)
{
	if(variant->m_type->isPrimitive())
	{
		if(variant->byValue() || variant->byRef())
		{
			pafcore::PrimitiveType* primitiveType = static_cast<pafcore::PrimitiveType*>(variant->m_type);
			switch(primitiveType->m_typeCategory)
			{
			case pafcore::float_type:
			case pafcore::double_type:
				{
					lua_Number value;
					primitiveType->castTo(&value, RuntimeTypeOf<lua_Number>::RuntimeType::GetSingleton(), variant->m_pointer);
					lua_pushnumber(L, value);
				}
				break;
			case pafcore::bool_type:
				{
					bool value;
					primitiveType->castTo(&value, RuntimeTypeOf<bool>::RuntimeType::GetSingleton(), variant->m_pointer);
					lua_pushboolean(L, value ? 1 : 0);
				}
				break;
			default:
				{
					lua_Integer value;
					primitiveType->castTo(&value, RuntimeTypeOf<lua_Integer>::RuntimeType::GetSingleton(), variant->m_pointer);
					lua_pushinteger(L, value);
				}
			}
			return pafcore::s_ok;
		}
		else
		{
			pafcore::PrimitiveType* primitiveType = static_cast<pafcore::PrimitiveType*>(variant->m_type);
			if(pafcore::char_type == primitiveType->m_typeCategory)
			{
				lua_pushstring(L, (const char*)variant->m_pointer);
				return pafcore::s_ok;
			}
		}
	}
	else if(variant->m_type->isEnum())
	{
		if(variant->byValue() || variant->byRef())
		{
			lua_Integer value;
			variant->castToPrimitive(RuntimeTypeOf<lua_Integer>::RuntimeType::GetSingleton(), &value);
			lua_pushinteger(L, value);
			return pafcore::s_ok;
		}
	}
	return pafcore::e_invalid_type;
}

int Variant_Call(lua_State *L)
{
	int numArgs = lua_gettop(L);
	pafcore::Variant* variant = (pafcore::Variant*)luaL_checkudata(L, 1, variant_metatable_name);
	switch(variant->m_type->m_category)
	{
	case pafcore::instance_method:
		{
			pafcore::InstanceMethod* method = (pafcore::InstanceMethod*)variant->m_pointer;
			return InvokeFunction_CallOperator(L, method->m_invoker);
		}
		break;
	case pafcore::static_method:
		{
			pafcore::StaticMethod* method = (pafcore::StaticMethod*)variant->m_pointer;
			return InvokeFunction_CallOperator(L, method->m_invoker);
		}
		break;
	case pafcore::primitive_type:
		{
			pafcore::PrimitiveType* type = (pafcore::PrimitiveType*)variant->m_pointer;
			assert(strcmp(type->m_staticMethods[1].m_name, "New") == 0);
			return InvokeFunction_CallOperator(L, type->m_staticMethods[1].m_invoker);
		}
		break;
	case pafcore::class_type:
		{
			pafcore::ClassType* type = (pafcore::ClassType*)variant->m_pointer;
			pafcore::StaticMethod* method = type->findStaticMethod("New", false);
			if(0 != method)
			{
				return InvokeFunction_CallOperator(L, method->m_invoker);
			}
		}
		break;
	}
	Variant_Error(L, "", pafcore::e_is_not_type);
	return 0;
}

int Variant_Len(lua_State *L)
{
	pafcore::Variant* variant = (pafcore::Variant*)luaL_checkudata(L, 1, variant_metatable_name);
	if(pafcore::null_object == variant->m_type->m_category)
	{
		Variant_Error(L, "#", pafcore::e_null_variant);
		return 0;
	}
	lua_pushinteger(L, variant->m_arraySize);
	return 1;
}

int GetEnumerator(lua_State *L, pafcore::Enumerator* enumerator)
{
	pafcore::Variant value;
	value.assignEnum(enumerator->m_type, &enumerator->m_value);
	VariantToLua(L, &value);
	return 1;
}

inline bool isNumberString(const char* str)
{
	char c;
	while(c = *str++)
	{
		if(c < '0' || '9' < c)
		{
			return false;
		}
	}
	return true;
}

int Variant_Add(lua_State *L)
{
	return InvokeFunction_ArithmeticOperator(L, pafcore::PrimitiveType::Primitive___op_add_);
}

int Variant_Sub(lua_State *L)
{
	return InvokeFunction_ArithmeticOperator(L, pafcore::PrimitiveType::Primitive___op_sub_);
}

int Variant_Mul(lua_State *L)
{
	return InvokeFunction_ArithmeticOperator(L, pafcore::PrimitiveType::Primitive___op_mul_);
}

int Variant_Div(lua_State *L)
{
	return InvokeFunction_ArithmeticOperator(L, pafcore::PrimitiveType::Primitive___op_div_);
}

int Variant_Mod(lua_State *L)
{
	return InvokeFunction_ArithmeticOperator(L, pafcore::PrimitiveType::Primitive___op_mod_);
}

int Variant_Unm(lua_State *L)
{
	return InvokeFunction_ArithmeticOperator(L, pafcore::PrimitiveType::Primitive___op_neg_);
}

int Variant_LessThan(lua_State *L)
{
	return InvokeFunction_ComparisonOperator(L, pafcore::PrimitiveType::Primitive___op_less_than_);
}

int Variant_LessEqual(lua_State *L)
{
	return InvokeFunction_ComparisonOperator(L, pafcore::PrimitiveType::Primitive___op_less_equal_);
}

int Variant_EqualTo(lua_State *L)
{
	return InvokeFunction_ComparisonOperator(L, pafcore::PrimitiveType::Primitive___op_equal_to_);
}

int Subclassing(lua_State *L)
{
	const void* p = lua_topointer(L, lua_upvalueindex(1));
	pafcore::ClassType* classType = (pafcore::ClassType*)p;
	int numArgs = lua_gettop(L);
	if(lua_type(L, -1) == LUA_TTABLE)
	{
		LuaSubclassInvoker* subclassInvoker = new LuaSubclassInvoker(L);
		void* implementor = classType->createSubclassProxy(subclassInvoker);
		pafcore::Variant impVar;
		if(classType->isValue())
		{
			impVar.assignValuePtr(classType, implementor, false, ::pafcore::Variant::by_new_ptr);
		}
		else
		{
			impVar.assignReferencePtr(classType, implementor, false, ::pafcore::Variant::by_new_ptr);
		}
		VariantToLua(L, &impVar);
		return 1;
	}
	Variant_Error(L, "the argument of _inherit_() must be a table", pafcore::e_script_error);
	return 0;
}

pafcore::ErrorCode Variant_Index_Identify(lua_State *L, pafcore::Variant* variant, const char *name)
{
	switch(variant->m_type->m_category)
	{
	case pafcore::name_space:
		{
			pafcore::NameSpace* ns = (pafcore::NameSpace*)variant->m_pointer;
			pafcore::Metadata* member = ns->findMember(name);
			if(0 != member)
			{
				pafcore::Variant value;
				value.assignReferencePtr(RuntimeTypeOf<pafcore::Metadata>::RuntimeType::GetSingleton(), member, false, ::pafcore::Variant::by_ptr);
				VariantToLua(L, &value);
				return pafcore::s_ok;
			}
		}
		break;
	case pafcore::class_type:
		{
			pafcore::ClassType* type = (pafcore::ClassType*)variant->m_pointer;
			pafcore::Metadata* member = type->findClassMember(name, true);
			if(0 != member)
			{
				pafcore::Type* memberType = member->getType();
				switch(memberType->m_category)
				{
				case pafcore::static_field:
					return GetStaticField(L, static_cast<pafcore::StaticField*>(member));
				case pafcore::static_property:
					return GetStaticProperty(L, static_cast<pafcore::StaticProperty*>(member));
				case pafcore::static_method:
					lua_pushlightuserdata(L, static_cast<pafcore::StaticMethod*>(member)->m_invoker);
					lua_pushcclosure(L, FunctionInvoker_Closure, 1);
					return pafcore::s_ok;
				//case pafcore::static_method:
				//	{
				//		pafcore::Variant value;
				//		value.assignReferencePtr(RuntimeTypeOf<pafcore::Metadata>::RuntimeType::GetSingleton(), member, false, ::pafcore::Variant::by_ptr);
				//		VariantToLua(L, &value);
				//		return pafcore::s_ok;
				//	}
				}
			}
		}
		break;
	case pafcore::primitive_type:
		{
			pafcore::PrimitiveType* type = (pafcore::PrimitiveType*)variant->m_pointer;
			pafcore::Metadata* member = type->findTypeMember(name);
			if(0 != member)
			{
				pafcore::Type* memberType = member->getType();
				switch(memberType->m_category)
				{
				case pafcore::static_method:
					lua_pushlightuserdata(L, static_cast<pafcore::StaticMethod*>(member)->m_invoker);
					lua_pushcclosure(L, FunctionInvoker_Closure, 1);
					return pafcore::s_ok;
				//case pafcore::static_method:
				//	{
				//		pafcore::Variant value;
				//		value.assignReferencePtr(RuntimeTypeOf<pafcore::Metadata>::RuntimeType::GetSingleton(), member, false, ::pafcore::Variant::by_ptr);
				//		VariantToLua(L, &value);
				//		return pafcore::s_ok;
				//	}
				default:
					assert(false);
				}
			}
		}
		break;
	case pafcore::enum_type:
		{
			pafcore::EnumType* et = (pafcore::EnumType*)variant->m_pointer;
			pafcore::Enumerator* enumerator = et->findEnumerator(name);
			if(0 != enumerator)
			{
				pafcore::Variant value;
				value.assignEnum(enumerator->m_type, &enumerator->m_value);
				VariantToLua(L, &value);
				return pafcore::s_ok;
			}
		}
		break;
	}
	pafcore::Metadata* member;
	member = variant->m_type->findMember(name);
	if(0 != member)
	{
		pafcore::Type* memberType = member->getType();
		switch(memberType->m_category)
		{
		case pafcore::enum_type:
		case pafcore::class_type:
			return GetNestedType(L, static_cast<pafcore::Type*>(member));
		case pafcore::instance_field:
			return GetInstanceField(L, variant, static_cast<pafcore::InstanceField*>(member));
		case pafcore::static_field:
			return GetStaticField(L, static_cast<pafcore::StaticField*>(member));
		case pafcore::instance_property:
			return GetInstanceProperty(L, variant, static_cast<pafcore::InstanceProperty*>(member));
		case pafcore::static_property:
			return GetStaticProperty(L, static_cast<pafcore::StaticProperty*>(member));
		case pafcore::instance_method:
			lua_pushlightuserdata(L, static_cast<pafcore::InstanceMethod*>(member)->m_invoker);
			lua_pushcclosure(L, FunctionInvoker_Closure, 1);
			return pafcore::s_ok;
		case pafcore::static_method:
			lua_pushlightuserdata(L, static_cast<pafcore::StaticMethod*>(member)->m_invoker);
			lua_pushcclosure(L, FunctionInvoker_Closure, 1);
			return pafcore::s_ok;
		//case pafcore::static_method:
		//case pafcore::instance_method:
		//	{
		//		pafcore::Variant value;
		//		value.assignReferencePtr(RuntimeTypeOf<pafcore::Metadata>::RuntimeType::GetSingleton(), member, false, ::pafcore::Variant::by_ptr);
		//		VariantToLua(L, &value);
		//		return pafcore::s_ok;
		//	}
		default:
			assert(false);
		}
	}
	if(strcmp(name, "_") == 0)
	{
		if(variant->m_type->isPrimitive() || variant->m_type->isEnum())
		{
			return GetPrimitiveOrEnum(L, variant);
		}
	}
	else if(strcmp(name, "_type_") == 0)
	{
		pafcore::Variant typeVar;
		typeVar.assignReferencePtr(RuntimeTypeOf<pafcore::Type>::RuntimeType::GetSingleton(), variant->m_type, false, ::pafcore::Variant::by_ptr);
		VariantToLua(L, &typeVar);
		return pafcore::s_ok;
	}
	else if(strcmp(name, "_address_") == 0)
	{
		lua_pushlightuserdata(L, variant->m_pointer);
		return pafcore::s_ok;
	}
	else if(strcmp(name, "_size_") == 0)
	{
		lua_pushinteger(L, variant->m_type->m_size);
		return pafcore::s_ok;
	}
	else if(strcmp(name, "_count_") == 0)
	{
		lua_pushinteger(L, variant->m_arraySize);
		return pafcore::s_ok;
	}
	else if(strcmp(name, "_clone_") == 0)
	{
		switch(variant->m_type->m_category)
		{
		case pafcore::value_object:
		case pafcore::reference_object:
			{
				pafcore::ClassType* type = (pafcore::ClassType*)variant->m_type;
				pafcore::StaticMethod* method = type->findStaticMethod("Clone", false);
				if(0 != method)
				{
					if(FunctionInvoker_Clone(L, method->m_invoker))
					{
						return pafcore::s_ok; 
					}
				}
			}
			break;
		case pafcore::primitive_object:
			{
				pafcore::PrimitiveType* type = (pafcore::PrimitiveType*)variant->m_type;
				assert(strcmp(type->m_staticMethods[0].m_name, "Clone") == 0);
				if(FunctionInvoker_Clone(L, type->m_staticMethods[0].m_invoker))
				{
					return pafcore::s_ok; 
				}
			}
			break;
		}
	}
	else if(strcmp(name, "_inherit_") == 0)
	{
		if(pafcore::class_type == variant->m_type->m_category)
		{
			pafcore::ClassType* classType = (pafcore::ClassType*)variant->m_pointer;		
			lua_pushlightuserdata(L, classType);
			lua_pushcclosure(L, Subclassing, 1);
			return pafcore::s_ok;
		}
		else
		{
			return pafcore::e_is_not_class;
		}
	}
	return pafcore::e_member_not_found;
}

pafcore::ErrorCode Variant_NewIndex_Identify(lua_State *L, pafcore::Variant* variant, const char *name)
{
	switch(variant->m_type->m_category)
	{
	case pafcore::class_type:
		{
			pafcore::ClassType* type = (pafcore::ClassType*)variant->m_pointer;
			pafcore::Metadata* member = type->findClassMember(name, true);
			if(0 != member)
			{
				pafcore::Type* memberType = member->getType();
				switch(memberType->m_category)
				{
				case pafcore::static_field:
					return SetStaticField(L, static_cast<pafcore::StaticField*>(member));
				case pafcore::static_property:
					return SetStaticProperty(L, static_cast<pafcore::StaticProperty*>(member));
				}
			}
		}
		break;
	}
	pafcore::Metadata* member;
	member = variant->m_type->findMember(name);
	if(0 != member)
	{
		pafcore::Type* memberType = member->getType();
		switch(memberType->m_category)
		{
		case pafcore::instance_field:
			return SetInstanceField(L, variant, static_cast<pafcore::InstanceField*>(member));
		case pafcore::static_field:
			return SetStaticField(L, static_cast<pafcore::StaticField*>(member));
		case pafcore::instance_property:
			return SetInstanceProperty(L, variant, static_cast<pafcore::InstanceProperty*>(member));
		case pafcore::static_property:
			return SetStaticProperty(L, static_cast<pafcore::StaticProperty*>(member));
		}
	}
	return pafcore::e_member_not_found;
}

pafcore::ErrorCode Variant_Index_Subscript(lua_State *L, pafcore::Variant* variant, size_t index)
{
	pafcore::Variant item;
	if(!variant->subscript(item, index))
	{
		return pafcore::e_index_out_of_range;
	}
	VariantToLua(L, &item);
	return pafcore::s_ok;
}

enum SubscriptCategory
{
	sc_error,
	sc_string,
	sc_integer,
};

SubscriptCategory Variant_ParseSubscript(size_t& num, const char*& str, lua_State *L)
{
	int index = 2;
	int type = lua_type(L, index);
	switch (type)
	{
	case LUA_TSTRING:
		{
			str = lua_tostring(L, index);
			return sc_string;
		}
		break;
	case LUA_TBOOLEAN:
		{
			num = lua_toboolean(L, index) ? 1 : 0;
			return sc_integer;
		}
		break;
	case LUA_TNUMBER:
		{
			num = lua_tointeger(L, index);
			return sc_integer;
		}
		break;
	case LUA_TUSERDATA:
		{
			pafcore::Variant* variant = (pafcore::Variant*)luaL_checkudata(L, index, variant_metatable_name);
			if(variant)
			{
				if(variant->byValue() || variant->byRef())
				{
					if(variant->castToPrimitive(RuntimeTypeOf<size_t>::RuntimeType::GetSingleton(), &num))
					{
						return sc_integer;
					}
				}
				else
				{
					pafcore::PrimitiveType* primitiveType = static_cast<pafcore::PrimitiveType*>(variant->m_type);
					if(pafcore::char_type == primitiveType->m_typeCategory)
					{
						str = (const char*)variant->m_pointer;
						return sc_string;
					}
				}
			}
		}
	}
	return sc_error;
}

int Variant_Index(lua_State *L) 
{
	pafcore::Variant* variant = (pafcore::Variant*)luaL_checkudata(L, 1, variant_metatable_name);
	if(variant->isNull())
	{
		Variant_Error(L, "", pafcore::e_null_variant);
		return 0;
	}
	size_t num;
	const char* str;
	SubscriptCategory sc = Variant_ParseSubscript(num, str, L);

	pafcore::ErrorCode errorCode = pafcore::e_invalid_subscript_type;
	if(sc_integer == sc)
	{
		errorCode = Variant_Index_Subscript(L, variant, num);
	}
	else if(sc_string == sc)
	{
		errorCode = Variant_Index_Identify(L, variant, str);
	}
	if(pafcore::s_ok != errorCode)
	{
		Variant_Error(L, "", errorCode);
		return 0;
	}
	return 1;
}

pafcore::ErrorCode Variant_NewIndex_Subscript(lua_State *L, pafcore::Variant* variant, size_t index)
{
	pafcore::Variant item;
	if(!variant->subscript(item, index))
	{
		return pafcore::e_index_out_of_range;
	}
	if(item.isConstant())
	{
		return pafcore::e_item_is_constant;
	}
	pafcore::Variant value;
	pafcore::Variant* arg = LuaToVariant(&value, L, 3);
	if(!arg->castToObject(item.m_type, item.m_pointer))
	{
		return pafcore::e_invalid_type;
	}
	return pafcore::s_ok;
}


int Variant_NewIndex(lua_State *L) 
{
	pafcore::Variant* variant = (pafcore::Variant*)luaL_checkudata(L, 1, variant_metatable_name);
	if(variant->isNull())
	{
		Variant_Error(L, "", pafcore::e_null_variant);
		return 0;
	}
	size_t num;
	const char* str;
	SubscriptCategory sc = Variant_ParseSubscript(num, str, L);

	pafcore::ErrorCode errorCode = pafcore::e_invalid_subscript_type;
	if(sc_integer == sc)
	{
		errorCode = Variant_NewIndex_Subscript(L, variant, num);
	}
	else if(sc_string == sc)
	{
		errorCode = Variant_NewIndex_Identify(L, variant, str);
	}
	if(pafcore::s_ok != errorCode)
	{
		Variant_Error(L, "", errorCode);
		return 0;
	}
	return 1;
}

const struct luaL_Reg g_variant_reg [] = 
{
	{"__gc", Variant_GC},
	{"__index", Variant_Index},
	{"__newindex", Variant_NewIndex},
	{"__call", Variant_Call},
	{"__len", Variant_Len},
	{"__add", Variant_Add},
	{"__sub", Variant_Sub},
	{"__mul", Variant_Mul},
	{"__div", Variant_Div},
	{"__mod", Variant_Mod},
	{"__unm", Variant_Unm},
	{"__lt", Variant_LessThan},
	{"__eq", Variant_EqualTo},
	{"__le", Variant_LessEqual},
	{NULL, NULL}
};

END_PAFLUA

int luaopen_paflua (lua_State *L)
{
	luaL_newmetatable(L, paflua::variant_metatable_name);
	luaL_setfuncs(L, paflua::g_variant_reg, 0);

	void* p = lua_newuserdata(L, sizeof(pafcore::Variant));
	pafcore::Variant* variant = new(p)pafcore::Variant;
	variant->assignReferencePtr(RuntimeTypeOf<pafcore::NameSpace>::RuntimeType::GetSingleton(), pafcore::NameSpace::GetGlobalNameSpace(), false, ::pafcore::Variant::by_ptr);
	luaL_getmetatable(L, paflua::variant_metatable_name);
	lua_setmetatable(L, -2);
	lua_setglobal(L, "paf");

	//paflua::stackDump(L);
	return 1;
}
