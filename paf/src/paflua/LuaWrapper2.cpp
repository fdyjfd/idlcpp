#include "paflua.h"
#include "LuaSubclassInvoker2.h"
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
#include "../pafcore/VoidType.h"
#include "../pafcore/PrimitiveType.h"

#include <new.h>
#include <string.h>
#include <assert.h>


BEGIN_PAFLUA2

static void stackDump(lua_State *L)
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
			if (lua_isinteger(L, i))
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


const size_t max_param_count = 20;
const char* variant_metatable_name = "paf2.Variant";
const char* instanceArrayProperty_metatable_name = "paf2.ArrayInstanceProperty";
const char* staticArrayProperty_metatable_name = "paf2.ArrayStaticProperty";

struct InstanceArrayPropertyInstance
{
	pafcore::InstanceProperty* property;
	pafcore::Variant* object;
};

struct StaticArrayPropertyInstance
{
	pafcore::StaticProperty* property;
};

void Variant_Error(lua_State *L, const char* name, pafcore::ErrorCode errorCode)
{
	luaL_error(L, "idlcpp error: %s, Error: %d, %s\n", name, errorCode, pafcore::ErrorCodeToString(errorCode));
}

int Variant_GC(lua_State *L)
{
	pafcore::Variant* variant = (pafcore::Variant*)lua_touserdata(L, 1);
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
		if (value->m_type->isPrimitive() && value->byValue())
		{
			pafcore::PrimitiveType* primitiveType = static_cast<pafcore::PrimitiveType*>(value->m_type);
			if (pafcore::float_type == primitiveType->m_typeCategory ||
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
			char* p = paf_new_array<char>(len + 1);
			memcpy(p, s, len + 1);
			value->assignPrimitivePtr(RuntimeTypeOf<char>::RuntimeType::GetSingleton(), p, false, ::pafcore::Variant::by_new_array);
		}
	}
	break;
	case LUA_TBOOLEAN:
	{
		bool b = lua_toboolean(L, index) != 0;
		value->assignPrimitive(RuntimeTypeOf<bool>::RuntimeType::GetSingleton(), &b);
		value->setTemporary();
	}
	break;
	case LUA_TNUMBER:
		if (lua_isinteger(L, index))
		{
			lua_Integer i = lua_tointeger(L, index);
			value->assignPrimitive(RuntimeTypeOf<lua_Integer>::RuntimeType::GetSingleton(), &i);
			value->setTemporary();
		}
		else
		{
			lua_Number n = lua_tonumber(L, index);
			value->assignPrimitive(RuntimeTypeOf<lua_Number>::RuntimeType::GetSingleton(), &n);
			value->setTemporary();
		}
		break;
	case LUA_TUSERDATA:
	{
		pafcore::Variant* variant = (pafcore::Variant*)luaL_checkudata(L, index, variant_metatable_name);
		if (variant)
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
	char argumentsBuf[sizeof(pafcore::Variant)*max_param_count];
	pafcore::Variant* args[max_param_count];
	if (numArgs > max_param_count)
	{
		numArgs = max_param_count;
	}
	for (int i = 0; i < numArgs; i++)
	{
		pafcore::Variant* argument = (pafcore::Variant*)&argumentsBuf[sizeof(pafcore::Variant)*i];
		new(argument)pafcore::Variant;
		args[i] = LuaToVariant(argument, L, i + startIndex);
	}
	pafcore::Variant result;
	pafcore::ErrorCode errorCode = (*invoker)(&result, args, numArgs);
	for (int i = 0; i < numArgs; i++)
	{
		pafcore::Variant* argument = (pafcore::Variant*)&argumentsBuf[sizeof(pafcore::Variant)*i];
		argument->~Variant();
	}
	if (pafcore::s_ok == errorCode)
	{
		if (pafcore::VoidType::GetSingleton() == result.m_type && result.byValue())
		{
			return 0;
		}
		else
		{
			VariantToLua(L, &result);
			return 1;
		}
	}
	luaL_error(L, "%s\n", ErrorCodeToString(errorCode));
	return 0;
}

int InvokeFunction_Method(lua_State *L, pafcore::FunctionInvoker invoker)
{
	int numArgs = lua_gettop(L) - 1;
	return InvokeFunction(L, invoker, numArgs, 2);
}

int InvokeFunction_Operator(lua_State *L, pafcore::FunctionInvoker invoker)
{
	int numArgs = lua_gettop(L);
	return InvokeFunction(L, invoker, numArgs, 1);
}

int InvokeFunction_ComparisonOperator(lua_State *L, pafcore::FunctionInvoker invoker)
{
	int numArgs = lua_gettop(L);
	pafcore::Variant arguments[max_param_count];
	pafcore::Variant* args[max_param_count];
	if (numArgs > max_param_count)
	{
		numArgs = max_param_count;
	}
	for (int i = 0; i < numArgs; i++)
	{
		args[i] = LuaToVariant(&arguments[i], L, i + 1);
	}
	pafcore::Variant result;
	pafcore::ErrorCode errorCode = (*invoker)(&result, args, numArgs);
	if (pafcore::s_ok == errorCode)
	{
		if (pafcore::BoolType::GetSingleton() == result.m_type && result.byValue())
		{
			bool b = *reinterpret_cast<bool*>(result.m_pointer);
			lua_pushboolean(L, b ? 1 : 0);
		}
		else
		{
			VariantToLua(L, &result);
		}
		return 1;
	}
	luaL_error(L, "%s\n", ErrorCodeToString(errorCode));
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
	if (0 == property->m_getter)
	{
		return pafcore::e_property_is_not_writable;
	}
	pafcore::Variant value;
	pafcore::ErrorCode errorCode = (*property->m_getter)(property, that, &value);
	if (pafcore::s_ok == errorCode)
	{
		VariantToLua(L, &value);
	}
	return errorCode;
}

pafcore::ErrorCode GetInstanceArrayPropertySize(lua_State *L, pafcore::Variant* that, pafcore::InstanceProperty* property)
{
	assert(property->get_isArray());
	pafcore::Variant value;
	pafcore::ErrorCode errorCode = (*property->m_arraySizer)(property, that, &value);
	if (pafcore::s_ok == errorCode)
	{
		VariantToLua(L, &value);
	}
	return errorCode;
}

pafcore::ErrorCode GetInstanceArrayProperty(lua_State *L, pafcore::Variant* that, pafcore::InstanceProperty* property, size_t index)
{
	assert(property->get_isArray());

	if (0 == property->m_arrayGetter)
	{
		return pafcore::e_property_is_not_writable;
	}
	pafcore::Variant value;
	pafcore::ErrorCode errorCode = (*property->m_arrayGetter)(property, that, index, &value);
	if (pafcore::s_ok == errorCode)
	{
		VariantToLua(L, &value);
	}
	return errorCode;
}

pafcore::ErrorCode SetInstanceProperty(lua_State *L, pafcore::Variant* that, pafcore::InstanceProperty* property)
{
	if (0 == property->m_setter)
	{
		return pafcore::e_property_is_not_readable;
	}
	pafcore::Variant value;
	pafcore::Variant* arg = LuaToVariant(&value, L, 3);
	pafcore::ErrorCode errorCode = (*property->m_setter)(property, that, arg);
	return errorCode;
}

pafcore::ErrorCode SetInstanceArrayPropertySize(lua_State *L, pafcore::Variant* that, pafcore::InstanceProperty* property)
{
	assert(property->get_isArray());
	if (0 == property->m_arrayResizer)
	{
		return pafcore::e_array_property_is_not_dynamic;
	}
	pafcore::Variant value;
	pafcore::Variant* arg = LuaToVariant(&value, L, 3);
	pafcore::ErrorCode errorCode = (*property->m_arrayResizer)(property, that, arg);
	return errorCode;
}

pafcore::ErrorCode SetInstanceArrayProperty(lua_State *L, pafcore::Variant* that, pafcore::InstanceProperty* property, size_t index)
{
	assert(property->get_isArray());
	if (0 == property->m_arraySetter)
	{
		return pafcore::e_property_is_not_readable;
	}
	pafcore::Variant value;
	pafcore::Variant* arg = LuaToVariant(&value, L, 3);
	pafcore::ErrorCode errorCode = (*property->m_arraySetter)(property, that, index, arg);
	return errorCode;
}

pafcore::ErrorCode MakeInstanceArrayProperty(lua_State *L, pafcore::Variant* that, pafcore::InstanceProperty* property)
{
	assert(property->get_isArray());

	void* p = lua_newuserdata(L, sizeof(InstanceArrayPropertyInstance));
	((InstanceArrayPropertyInstance*)p)->property = property;
	((InstanceArrayPropertyInstance*)p)->object = that;
	luaL_getmetatable(L, instanceArrayProperty_metatable_name);
	lua_setmetatable(L, -2);
	return pafcore::s_ok;
}

pafcore::ErrorCode GetStaticProperty(lua_State *L, pafcore::StaticProperty* property)
{
	if (0 == property->m_getter)
	{
		return pafcore::e_property_is_not_writable;
	}
	pafcore::Variant value;
	pafcore::ErrorCode errorCode = (*property->m_getter)(&value);
	if (pafcore::s_ok == errorCode)
	{
		VariantToLua(L, &value);
	}
	return errorCode;
}

pafcore::ErrorCode GetStaticArrayPropertySize(lua_State *L, pafcore::StaticProperty* property)
{
	assert(property->get_isArray());

	pafcore::Variant value;
	pafcore::ErrorCode errorCode = (*property->m_arraySizer)(&value);
	if (pafcore::s_ok == errorCode)
	{
		VariantToLua(L, &value);
	}
	return errorCode;
}

pafcore::ErrorCode GetStaticArrayProperty(lua_State *L, pafcore::StaticProperty* property, size_t index)
{
	assert(property->get_isArray());

	if (0 == property->m_arrayGetter)
	{
		return pafcore::e_property_is_not_writable;
	}
	pafcore::Variant value;
	pafcore::ErrorCode errorCode = (*property->m_arrayGetter)(index, &value);
	if (pafcore::s_ok == errorCode)
	{
		VariantToLua(L, &value);
	}
	return errorCode;
}

pafcore::ErrorCode SetStaticProperty(lua_State *L, pafcore::StaticProperty* property)
{
	if (0 == property->m_setter)
	{
		return pafcore::e_property_is_not_readable;
	}

	pafcore::Variant value;
	pafcore::Variant* arg = LuaToVariant(&value, L, 3);
	pafcore::ErrorCode errorCode = (*property->m_setter)(arg);
	return errorCode;
}

pafcore::ErrorCode SetStaticArrayPropertySize(lua_State *L, pafcore::StaticProperty* property)
{
	assert(property->get_isArray());
	if (0 == property->m_arrayResizer)
	{
		return pafcore::e_array_property_is_not_dynamic;
	}
	pafcore::Variant value;
	pafcore::Variant* arg = LuaToVariant(&value, L, 3);
	pafcore::ErrorCode errorCode = (*property->m_arrayResizer)(arg);
	return errorCode;
}

pafcore::ErrorCode SetStaticArrayProperty(lua_State *L, pafcore::StaticProperty* property, size_t index)
{
	assert(property->get_isArray());

	if (0 == property->m_arraySetter)
	{
		return pafcore::e_property_is_not_readable;
	}

	pafcore::Variant value;
	pafcore::Variant* arg = LuaToVariant(&value, L, 3);
	pafcore::ErrorCode errorCode = (*property->m_arraySetter)(index, arg);
	return errorCode;
}

pafcore::ErrorCode MakeStaticArrayProperty(lua_State *L, pafcore::StaticProperty* property)
{
	assert(property->get_isArray());

	void* p = lua_newuserdata(L, sizeof(StaticArrayPropertyInstance));
	((StaticArrayPropertyInstance*)p)->property = property;
	luaL_getmetatable(L, staticArrayProperty_metatable_name);
	lua_setmetatable(L, -2);
	return pafcore::s_ok;
}

pafcore::ErrorCode GetNestedType(lua_State *L, pafcore::Type* nestedType)
{
	pafcore::Variant value;
	value.assignReferencePtr(RuntimeTypeOf<pafcore::Type>::RuntimeType::GetSingleton(), nestedType, false, ::pafcore::Variant::by_ptr);
	VariantToLua(L, &value);
	return pafcore::s_ok;
}

pafcore::ErrorCode GetInstanceFieldRef(lua_State *L, pafcore::Variant* that, pafcore::InstanceField* field)
{
	size_t baseOffset;
	if (!static_cast<pafcore::ClassType*>(that->m_type)->getClassOffset(baseOffset, field->m_objectType))
	{
		return pafcore::e_invalid_type;
	}
	size_t fieldAddress = (size_t)that->m_pointer + baseOffset + field->m_offset;
	pafcore::Variant value;

	if (field->isArray())
	{
		value.assignArray(field->m_type, (void*)fieldAddress, field->m_arraySize, field->m_constant, ::pafcore::Variant::by_array);
	}
	else if (field->isPointer())
	{
		value.assignPtr(field->m_type, *(void**)fieldAddress, field->m_constant, ::pafcore::Variant::by_ref);
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
	if (field->isArray())
	{
		return pafcore::e_field_is_an_array;
	}
	if (field->isConstant())
	{
		return pafcore::e_field_is_constant;
	}
	size_t baseOffset;
	if (!static_cast<pafcore::ClassType*>(that->m_type)->getClassOffset(baseOffset, field->m_objectType))
	{
		return pafcore::e_invalid_object_type;
	}
	size_t fieldAddress = (size_t)that->m_pointer + baseOffset + field->m_offset;
	pafcore::Variant value;
	pafcore::Variant* arg = LuaToVariant(&value, L, 3);
	if (field->isPointer())
	{
		if (!arg->castToObjectPtr(field->m_type, (void**)fieldAddress))
		{
			return pafcore::e_invalid_field_type;
		}
	}
	else
	{
		if (!arg->castToObject(field->m_type, (void*)fieldAddress))
		{
			return pafcore::e_invalid_field_type;
		}
	}
	return pafcore::s_ok;
}

pafcore::ErrorCode GetStaticField(lua_State *L, pafcore::StaticField* field)
{
	pafcore::Variant value;
	if (field->isArray())
	{
		value.assignArray(field->m_type, (void*)field->m_address, field->m_arraySize, field->m_constant, ::pafcore::Variant::by_array);
	}
	else if (field->isPointer())
	{
		value.assignPtr(field->m_type, *(void**)field->m_address, field->m_constant, ::pafcore::Variant::by_ref);
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
	if (field->isArray())
	{
		return pafcore::e_field_is_an_array;
	}
	if (field->isConstant())
	{
		return pafcore::e_field_is_constant;
	}
	pafcore::Variant value;
	pafcore::Variant* arg = LuaToVariant(&value, L, 3);
	if (field->isPointer())
	{
		if (!arg->castToObjectPtr(field->m_type, (void**)field->m_address))
		{
			return pafcore::e_invalid_field_type;
		}
	}
	else
	{
		if (!arg->castToObject(field->m_type, (void*)field->m_address))
		{
			return pafcore::e_invalid_field_type;
		}
	}
	return pafcore::s_ok;
}

pafcore::ErrorCode SetArraySize(lua_State *L, pafcore::Variant* that)
{
	pafcore::Variant value;
	pafcore::Variant* arg = LuaToVariant(&value, L, 3);
	if (!arg->castToPrimitive(RuntimeTypeOf<size_t>::RuntimeType::GetSingleton(), &that->m_arraySize))
	{
		return pafcore::e_invalid_property_type;
	}
	return pafcore::s_ok;
}

pafcore::ErrorCode GetPrimitiveOrEnum(lua_State *L, pafcore::Variant* variant)
{
	if (variant->m_type->isPrimitive())
	{
		if (variant->byValue() || variant->byRef())
		{
			pafcore::PrimitiveType* primitiveType = static_cast<pafcore::PrimitiveType*>(variant->m_type);
			switch (primitiveType->m_typeCategory)
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
			if (pafcore::char_type == primitiveType->m_typeCategory)
			{
				lua_pushstring(L, (const char*)variant->m_pointer);
				return pafcore::s_ok;
			}
		}
	}
	else if (variant->m_type->isEnum())
	{
		if (variant->byValue() || variant->byRef())
		{
			lua_Integer value;
			variant->castToPrimitive(RuntimeTypeOf<lua_Integer>::RuntimeType::GetSingleton(), &value);
			lua_pushinteger(L, value);
			return pafcore::s_ok;
		}
	}
	return pafcore::e_invalid_type;
}

pafcore::ErrorCode SetPrimitiveOrEnum(lua_State *L, pafcore::Variant* variant)
{
	assert(variant->m_type->isPrimitive() || variant->m_type->isEnum());
	if (variant->isConstant())
	{
		return pafcore::e_this_is_constant;
	}
	pafcore::Variant value;
	pafcore::Variant* arg = LuaToVariant(&value, L, 3);
	if (!arg->castToObject(variant->m_type, (void*)variant->m_pointer))
	{
		return pafcore::e_invalid_property_type;
	}
	return pafcore::s_ok;
}

int Variant_Call(lua_State *L)
{
	int numArgs = lua_gettop(L);
	pafcore::Variant* variant = (pafcore::Variant*)lua_touserdata(L, 1);
	switch (variant->m_type->m_category)
	{
	case pafcore::instance_method:
	{
		pafcore::InstanceMethod* method = (pafcore::InstanceMethod*)variant->m_pointer;
		return InvokeFunction_Method(L, method->m_invoker);
	}
	break;
	case pafcore::static_method:
	{
		pafcore::StaticMethod* method = (pafcore::StaticMethod*)variant->m_pointer;
		return InvokeFunction_Method(L, method->m_invoker);
	}
	break;
	case pafcore::primitive_type:
	{
		pafcore::PrimitiveType* type = (pafcore::PrimitiveType*)variant->m_pointer;
		assert(strcmp(type->m_staticMethods[0].m_name, "New") == 0);
		return InvokeFunction_Method(L, type->m_staticMethods[0].m_invoker);
	}
	break;
	case pafcore::class_type:
	{
		pafcore::ClassType* type = (pafcore::ClassType*)variant->m_pointer;
		pafcore::StaticMethod* method = type->findStaticMethod("New", false);
		if (0 != method)
		{
			return InvokeFunction_Method(L, method->m_invoker);
		}
	}
	break;
	case pafcore::value_object:
	case pafcore::reference_object:
	{
		pafcore::ClassType* type = (pafcore::ClassType*)variant->m_type;
		pafcore::InstanceMethod* method = type->findInstanceMethod("op_call", true);
		if (0 != method)
		{
			return InvokeFunction_Operator(L, method->m_invoker);
		}
	}
	break;
	}
	Variant_Error(L, "", pafcore::e_is_not_type);
	return 0;
}

int Variant_Len(lua_State *L)
{
	pafcore::ErrorCode errorCode;
	pafcore::Variant* variant = (pafcore::Variant*)lua_touserdata(L, 1);

	if (pafcore::void_object == variant->m_type->m_category && variant->byValue())
	{
		errorCode = pafcore::e_void_variant;
	}
	else
	{
		errorCode = pafcore::s_ok;
		lua_pushinteger(L, variant->m_arraySize);
	}

	if (pafcore::s_ok == errorCode)
	{
		return 1;
	}
	else
	{
		Variant_Error(L, "#", errorCode);
		return 0;
	}
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
	while (c = *str++)
	{
		if (c < '0' || '9' < c)
		{
			return false;
		}
	}
	return true;
}

int Variant_Operator(lua_State *L, const char* op)
{
	int numArgs = lua_gettop(L);
	pafcore::Variant* variant = (pafcore::Variant*)lua_touserdata(L, 1);

	pafcore::InstanceMethod* method;
	switch (variant->m_type->m_category)
	{
	case pafcore::primitive_object:
	{
		pafcore::PrimitiveType* type = (pafcore::PrimitiveType*)variant->m_type;
		method = type->findInstanceMethod(op);
	}
	break;
	case pafcore::value_object:
	case pafcore::reference_object:
	{
		pafcore::ClassType* type = (pafcore::ClassType*)variant->m_type;
		method = type->findInstanceMethod(op, true);
	}
	break;
	default:
		method = 0;
	}
	if (0 != method)
	{
		return InvokeFunction_Operator(L, method->m_invoker);
	}
	else
	{
		luaL_error(L, "%s\n", ErrorCodeToString(pafcore::e_member_not_found));
		return 0;
	}
}

int Variant_ComparisonOperator(lua_State *L, const char* op)
{
	pafcore::Variant* variant;
	if (LUA_TUSERDATA == lua_type(L, 1))
	{
		variant = (pafcore::Variant*)luaL_checkudata(L, 1, variant_metatable_name);
	}
	else
	{
		variant = (pafcore::Variant*)luaL_checkudata(L, 2, variant_metatable_name);
	}
	switch (variant->m_type->m_category)
	{
	case pafcore::primitive_object:
	{
		pafcore::PrimitiveType* type = (pafcore::PrimitiveType*)variant->m_type;
		pafcore::InstanceMethod* method = type->findInstanceMethod(op);
		if (0 != method)
		{
			return InvokeFunction_ComparisonOperator(L, method->m_invoker);
		}
	}
	break;
	case pafcore::value_object:
	case pafcore::reference_object:
	{
		pafcore::ClassType* type = (pafcore::ClassType*)variant->m_type;
		pafcore::InstanceMethod* method = type->findInstanceMethod(op, true);
		if (0 != method)
		{
			return InvokeFunction_ComparisonOperator(L, method->m_invoker);
		}
	}
	break;
	}
	luaL_error(L, "%s\n", ErrorCodeToString(pafcore::e_member_not_found));
	return 0;
}

int Variant_Add(lua_State *L)
{
	return Variant_Operator(L, "op_add");
}

int Variant_Sub(lua_State *L)
{
	return Variant_Operator(L, "op_subtract");
}

int Variant_Mul(lua_State *L)
{
	return Variant_Operator(L, "op_multiply");
}

int Variant_Div(lua_State *L)
{
	return Variant_Operator(L, "op_divide");
}

int Variant_Mod(lua_State *L)
{
	return Variant_Operator(L, "op_mod");
}

int Variant_Unm(lua_State *L)
{
	return Variant_Operator(L, "op_negate");
}

int Variant_Less(lua_State *L)
{
	return Variant_ComparisonOperator(L, "op_less");
}

int Variant_LessEqual(lua_State *L)
{
	return Variant_ComparisonOperator(L, "op_lessEqual");
}

int Variant_Equal(lua_State *L)
{
	return Variant_ComparisonOperator(L, "op_equal");
}

int Subclassing(lua_State *L)
{
	const void* p = lua_topointer(L, lua_upvalueindex(1));
	pafcore::ClassType* classType = (pafcore::ClassType*)p;
	int numArgs = lua_gettop(L);
	if (1 == numArgs && lua_type(L, -1) == LUA_TTABLE)
	{
		LuaSubclassInvoker* subclassInvoker = paf_new LuaSubclassInvoker(L);
		void* implementor = classType->createSubclassProxy(subclassInvoker);
		pafcore::Variant impVar;
		if (classType->isValue())
		{
			impVar.assignValuePtr(classType, implementor, false, ::pafcore::Variant::by_new_ptr);
		}
		else
		{
			impVar.assignReferencePtr(classType, implementor, false, ::pafcore::Variant::by_new_ptr);
		}
		impVar.setSubClassProxy();
		VariantToLua(L, &impVar);
		return 1;
	}
	Variant_Error(L, "the argument of _Derive_ must be a table", pafcore::e_invalid_arg_type_1);
	return 0;
}

int CastPtr(lua_State *L)
{
	const void* p = lua_topointer(L, lua_upvalueindex(1));
	pafcore::Type* type = (pafcore::Type*)p;
	int numArgs = lua_gettop(L);
	if (1 == numArgs)
	{
		pafcore::Variant value;
		pafcore::Variant* arg = LuaToVariant(&value, L, 1);
		pafcore::Variant dstPtr;
		arg->reinterpretCastToPtr(dstPtr, type);
		VariantToLua(L, &dstPtr);
		return 1;
	}
	Variant_Error(L, "_CastPtr_", pafcore::e_invalid_arg_type_1);
	return 0;
}

pafcore::ErrorCode Variant_Index_Identify(lua_State *L, pafcore::Variant* variant, const char *name)
{
	switch (variant->m_type->m_category)
	{
	case pafcore::name_space:
	{
		pafcore::NameSpace* ns = (pafcore::NameSpace*)variant->m_pointer;
		pafcore::Metadata* member = ns->findMember(name);
		if (0 != member)
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
		pafcore::Metadata* member = type->findClassMember(name, true, true);
		if (0 != member)
		{
			pafcore::Type* memberType = member->getType();
			switch (memberType->m_category)
			{
			case pafcore::static_field:
				return GetStaticField(L, static_cast<pafcore::StaticField*>(member));
			case pafcore::static_property:
				if (static_cast<pafcore::StaticProperty*>(member)->get_isArray())
				{
					return MakeStaticArrayProperty(L, static_cast<pafcore::StaticProperty*>(member));
				}
				else
				{
					return GetStaticProperty(L, static_cast<pafcore::StaticProperty*>(member));
				}
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
			case pafcore::enum_type:
			case pafcore::class_type:
				return GetNestedType(L, static_cast<pafcore::Type*>(member));
			}
		}
	}
	break;
	case pafcore::primitive_type:
	{
		pafcore::PrimitiveType* type = (pafcore::PrimitiveType*)variant->m_pointer;
		pafcore::Metadata* member = type->findTypeMember(name);
		if (0 != member)
		{
			pafcore::Type* memberType = member->getType();
			switch (memberType->m_category)
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
		if (0 != enumerator)
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
	if (0 != member)
	{
		pafcore::Type* memberType = member->getType();
		switch (memberType->m_category)
		{
		case pafcore::instance_field:
			return GetInstanceFieldRef(L, variant, static_cast<pafcore::InstanceField*>(member));
		case pafcore::static_field:
			return GetStaticField(L, static_cast<pafcore::StaticField*>(member));
		case pafcore::instance_property:
			if (static_cast<pafcore::InstanceProperty*>(member)->get_isArray())
			{
				return MakeInstanceArrayProperty(L, variant, static_cast<pafcore::InstanceProperty*>(member));
			}
			else
			{
				return GetInstanceProperty(L, variant, static_cast<pafcore::InstanceProperty*>(member));
			}
		case pafcore::static_property:
			if (static_cast<pafcore::StaticProperty*>(member)->get_isArray())
			{
				return MakeStaticArrayProperty(L, static_cast<pafcore::StaticProperty*>(member));
			}
			else
			{
				return GetStaticProperty(L, static_cast<pafcore::StaticProperty*>(member));
			}
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
		case pafcore::enum_type:
		case pafcore::class_type:
			return GetNestedType(L, static_cast<pafcore::Type*>(member));
		default:
			assert(false);
		}
	}
	else if (name[0] == '_')
	{
		switch (name[1])
		{
		case '\0':
			if (variant->m_type->isPrimitive() || variant->m_type->isEnum())//_
			{
				return GetPrimitiveOrEnum(L, variant);
			}
			break;
		case 'C':
			if (strcmp(&name[2], "astPtr_") == 0)//_CastPtr_
			{
				if (pafcore::void_type == variant->m_type->m_category ||
					pafcore::primitive_type == variant->m_type->m_category ||
					pafcore::enum_type == variant->m_type->m_category ||
					pafcore::class_type == variant->m_type->m_category)
				{
					pafcore::Type* type = (pafcore::Type*)variant->m_pointer;
					lua_pushlightuserdata(L, type);
					lua_pushcclosure(L, CastPtr, 1);
					return pafcore::s_ok;
				}
				else
				{
					return pafcore::e_is_not_type;
				}
			}
			break;
		case 'D':
			if (strcmp(&name[2], "erive_") == 0)//_Derive_
			{
				if (pafcore::class_type == variant->m_type->m_category)
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
			break;
		case 'a':
			if (strcmp(&name[2], "ddress_") == 0)//_address_
			{
				//lua_pushinteger(L, (size_t)variant->m_pointer);
				pafcore::Variant address;
				address.assignPrimitive(RuntimeTypeOf<size_t>::RuntimeType::GetSingleton(), &variant->m_pointer);
				VariantToLua(L, &address);
				return pafcore::s_ok;
			}
			break;
		case 'c':
			if (strcmp(&name[2], "ount_") == 0)//_count_
			{
				//lua_pushinteger(L, variant->m_arraySize);
				pafcore::Variant count;
				count.assignPrimitive(RuntimeTypeOf<size_t>::RuntimeType::GetSingleton(), &variant->m_arraySize);
				VariantToLua(L, &count);
				return pafcore::s_ok;
			}
			break;
		case 'i':
			if (strcmp(&name[2], "sNullPtr_") == 0)//_isNullPtr_
			{
				//lua_pushboolean(L, 0 == variant->m_pointer ? 1 : 0);
				bool isNullPtr = (0 == variant->m_pointer);
				pafcore::Variant var;
				var.assignPrimitive(RuntimeTypeOf<bool>::RuntimeType::GetSingleton(), &isNullPtr);
				VariantToLua(L, &var);
				return pafcore::s_ok;
			}
			break;
		case 'n':
			if (strcmp(&name[2], "ullPtr_") == 0)//_nullPtr_
			{
				if (pafcore::void_type == variant->m_type->m_category ||
					pafcore::primitive_type == variant->m_type->m_category ||
					pafcore::enum_type == variant->m_type->m_category ||
					pafcore::class_type == variant->m_type->m_category)
				{
					pafcore::Type* type = (pafcore::Type*)variant->m_pointer;
					pafcore::Variant var;
					var.assignPtr(type, 0, false, pafcore::Variant::by_ptr);
					VariantToLua(L, &var);
					return pafcore::s_ok;
				}
				else
				{
					return pafcore::e_is_not_type;
				}
			}
			break;
		case 's':
			if (strcmp(&name[2], "ize_") == 0)//_size_
			{
				//lua_pushinteger(L, variant->m_type->m_size);
				pafcore::Variant size;
				size.assignPrimitive(RuntimeTypeOf<size_t>::RuntimeType::GetSingleton(), &variant->m_type->m_size);
				VariantToLua(L, &size);
				return pafcore::s_ok;
			}
			break;
		case 't':
			if (strcmp(&name[2], "ype_") == 0)//_type_
			{
				pafcore::Variant typeVar;
				typeVar.assignReferencePtr(RuntimeTypeOf<pafcore::Type>::RuntimeType::GetSingleton(), variant->m_type, false, ::pafcore::Variant::by_ptr);
				VariantToLua(L, &typeVar);
				return pafcore::s_ok;
			}
			break;
		}
	}
	return pafcore::e_member_not_found;
}

pafcore::ErrorCode Variant_NewIndex_Identify(lua_State *L, pafcore::Variant* variant, const char *name)
{
	switch (variant->m_type->m_category)
	{
	case pafcore::class_type:
	{
		pafcore::ClassType* type = (pafcore::ClassType*)variant->m_pointer;
		pafcore::Metadata* member = type->findClassMember(name, true, true);
		if (0 != member)
		{
			pafcore::Type* memberType = member->getType();
			switch (memberType->m_category)
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
	if (0 != member)
	{
		pafcore::Type* memberType = member->getType();
		switch (memberType->m_category)
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
	else if (name[0] == '_')
	{
		switch (name[1])
		{
		case '\0':
			if ((variant->m_type->isPrimitive() || variant->m_type->isEnum()) &&
				(variant->byValue() || variant->byRef()))//_
			{
				return SetPrimitiveOrEnum(L, variant);
			}
			break;
		case 'c':
			if (strcmp(&name[2], "ount_") == 0)//_count_
			{
				return SetArraySize(L, variant);
			}
			break;
		}
	}
	return pafcore::e_member_not_found;
}

pafcore::ErrorCode Variant_Index_Subscript(lua_State *L, pafcore::Variant* variant, size_t index)
{
	pafcore::Variant item;
	if (!variant->subscript(item, index))
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
		if (variant)
		{
			if (variant->byValue() || variant->byRef())
			{
				if (variant->castToPrimitive(RuntimeTypeOf<size_t>::RuntimeType::GetSingleton(), &num))
				{
					return sc_integer;
				}
			}
			else
			{
				pafcore::PrimitiveType* primitiveType = static_cast<pafcore::PrimitiveType*>(variant->m_type);
				if (pafcore::char_type == primitiveType->m_typeCategory)
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
	size_t num;
	const char* str;
	SubscriptCategory sc = Variant_ParseSubscript(num, str, L);

	pafcore::ErrorCode errorCode = pafcore::e_invalid_subscript_type;
	pafcore::Variant* variant = (pafcore::Variant*)lua_touserdata(L, 1);
	if (variant->isNull())
	{
		if (sc_string == sc && strcmp(str, "_isNullPtr_") == 0)//_isNullPtr_
		{
			//lua_pushboolean(L, 0 == variant->m_pointer ? 1 : 0);
			bool isNullPtr = (0 == variant->m_pointer);
			pafcore::Variant var;
			var.assignPrimitive(RuntimeTypeOf<bool>::RuntimeType::GetSingleton(), &isNullPtr);
			VariantToLua(L, &var);
			errorCode = pafcore::s_ok;
		}
		else
		{
			errorCode = pafcore::e_void_variant;
		}
	}
	else
	{
		if (sc_integer == sc)
		{
			errorCode = Variant_Index_Subscript(L, variant, num);
		}
		else if (sc_string == sc)
		{
			errorCode = Variant_Index_Identify(L, variant, str);
		}
	}
	if (pafcore::s_ok != errorCode)
	{
		Variant_Error(L, "", errorCode);
		return 0;
	}
	return 1;
}

pafcore::ErrorCode Variant_NewIndex_Subscript(lua_State *L, pafcore::Variant* variant, size_t index)
{
	pafcore::Variant item;
	if (!variant->subscript(item, index))
	{
		return pafcore::e_index_out_of_range;
	}
	if (item.isConstant())
	{
		return pafcore::e_item_is_constant;
	}
	pafcore::Variant value;
	pafcore::Variant* arg = LuaToVariant(&value, L, 3);
	if (!arg->castToObject(item.m_type, item.m_pointer))
	{
		return pafcore::e_invalid_type;
	}
	return pafcore::s_ok;
}


int Variant_NewIndex(lua_State *L)
{
	pafcore::Variant* variant = (pafcore::Variant*)lua_touserdata(L, 1);
	if (variant->isNull())
	{
		Variant_Error(L, "", pafcore::e_void_variant);
		return 0;
	}
	size_t num;
	const char* str;
	SubscriptCategory sc = Variant_ParseSubscript(num, str, L);

	pafcore::ErrorCode errorCode = pafcore::e_invalid_subscript_type;
	if (sc_integer == sc)
	{
		errorCode = Variant_NewIndex_Subscript(L, variant, num);
	}
	else if (sc_string == sc)
	{
		errorCode = Variant_NewIndex_Identify(L, variant, str);
	}
	if (pafcore::s_ok != errorCode)
	{
		Variant_Error(L, "", errorCode);
		return 0;
	}
	return 1;
}

struct luaL_Reg g_variant_reg[] =
{
	{ "__gc", Variant_GC },
	{ "__index", Variant_Index },
	{ "__newindex", Variant_NewIndex },
	{ "__call", Variant_Call },
	{ "__len", Variant_Len },
	{ "__add", Variant_Add },
	{ "__sub", Variant_Sub },
	{ "__mul", Variant_Mul },
	{ "__div", Variant_Div },
	{ "__mod", Variant_Mod },
	{ "__unm", Variant_Unm },
	{ "__lt", Variant_Less },
	{ "__eq", Variant_Equal },
	{ "__le", Variant_LessEqual },
	{ NULL, NULL }
};

int InstanceArrayProperty_Index(lua_State *L)
{
	pafcore::ErrorCode errorCode;
	InstanceArrayPropertyInstance* instance = (InstanceArrayPropertyInstance*)lua_touserdata(L, 1);
	if (0 == instance->object)
	{
		Variant_Error(L, "", pafcore::e_void_variant);
		return 0;
	}
	size_t num;
	const char* str;
	SubscriptCategory sc = Variant_ParseSubscript(num, str, L);
	if (sc_integer == sc)
	{
		errorCode = GetInstanceArrayProperty(L, instance->object, instance->property, num);
	}
	else if (sc_string == sc)
	{
		if (strcmp("_count_", str) == 0)
		{
			errorCode = GetInstanceArrayPropertySize(L, instance->object, instance->property);
		}
		else
		{
			errorCode = pafcore::e_member_not_found;
		}
	}
	else
	{
		errorCode = pafcore::e_invalid_subscript_type;
	}
	if (pafcore::s_ok != errorCode)
	{
		Variant_Error(L, "", errorCode);
		return 0;
	}
	return 1;
}

int InstanceArrayProperty_NewIndex(lua_State *L)
{
	pafcore::ErrorCode errorCode;
	InstanceArrayPropertyInstance* instance = (InstanceArrayPropertyInstance*)lua_touserdata(L, 1);
	if (0 == instance->object)
	{
		Variant_Error(L, "", pafcore::e_void_variant);
		return 0;
	}
	size_t num;
	const char* str;
	SubscriptCategory sc = Variant_ParseSubscript(num, str, L);
	if (sc_integer == sc)
	{
		errorCode = SetInstanceArrayProperty(L, instance->object, instance->property, num);
	}
	else if (sc_string == sc)
	{
		if (strcmp("_count_", str) == 0)
		{
			errorCode = SetInstanceArrayPropertySize(L, instance->object, instance->property);
		}
		else
		{
			errorCode = pafcore::e_member_not_found;
		}
	}
	else
	{
		errorCode = pafcore::e_invalid_subscript_type;
	}
	if (pafcore::s_ok != errorCode)
	{
		Variant_Error(L, "", errorCode);
		return 0;
	}
	return 1;
}


int InstanceArrayProperty_Len(lua_State *L)
{
	pafcore::ErrorCode errorCode;
	InstanceArrayPropertyInstance* instance = (InstanceArrayPropertyInstance*)lua_touserdata(L, 1);
	if (0 == instance->object)
	{
		Variant_Error(L, "", pafcore::e_void_variant);
		return 0;
	}
	pafcore::InstanceProperty* property = instance->property;
	assert(property->get_isArray());
	pafcore::Variant value;
	errorCode = (*property->m_arraySizer)(property, instance->object, &value);
	if (pafcore::s_ok == errorCode)
	{
		lua_Integer len;
		value.castToPrimitive(RuntimeTypeOf<lua_Integer>::RuntimeType::GetSingleton(), &len);
		lua_pushinteger(L, len);
		return 1;
	}
	else
	{
		Variant_Error(L, "#", errorCode);
		return 0;
	}
}

struct luaL_Reg g_instanceArrayPropertyInstance_reg[] =
{
	{ "__index", InstanceArrayProperty_Index },
	{ "__newindex", InstanceArrayProperty_NewIndex },
	{ "__len", InstanceArrayProperty_Len },
	{ NULL, NULL }
};



int StaticArrayProperty_Index(lua_State *L)
{
	pafcore::ErrorCode errorCode;
	StaticArrayPropertyInstance* instance = (StaticArrayPropertyInstance*)lua_touserdata(L, 1);
	size_t num;
	const char* str;
	SubscriptCategory sc = Variant_ParseSubscript(num, str, L);
	if (sc_integer == sc)
	{
		errorCode = GetStaticArrayProperty(L, instance->property, num);
	}
	else if (sc_string == sc)
	{
		if (strcmp("_count_", str) == 0)
		{
			errorCode = GetStaticArrayPropertySize(L, instance->property);
		}
		else
		{
			errorCode = pafcore::e_member_not_found;
		}
	}
	else
	{
		errorCode = pafcore::e_invalid_subscript_type;
	}
	if (pafcore::s_ok != errorCode)
	{
		Variant_Error(L, "", errorCode);
		return 0;
	}
	return 1;
}

int StaticArrayProperty_NewIndex(lua_State *L)
{
	pafcore::ErrorCode errorCode;
	StaticArrayPropertyInstance* instance = (StaticArrayPropertyInstance*)lua_touserdata(L, 1);
	size_t num;
	const char* str;
	SubscriptCategory sc = Variant_ParseSubscript(num, str, L);
	if (sc_integer == sc)
	{
		errorCode = SetStaticArrayProperty(L, instance->property, num);
	}
	else if (sc_string == sc)
	{
		if (strcmp("_count_", str) == 0)
		{
			errorCode = SetStaticArrayPropertySize(L, instance->property);
		}
		else
		{
			errorCode = pafcore::e_member_not_found;
		}
	}
	else
	{
		errorCode = pafcore::e_invalid_subscript_type;
	}
	if (pafcore::s_ok != errorCode)
	{
		Variant_Error(L, "", errorCode);
		return 0;
	}
	return 1;
}


int StaticArrayProperty_Len(lua_State *L)
{
	pafcore::ErrorCode errorCode;
	StaticArrayPropertyInstance* instance = (StaticArrayPropertyInstance*)lua_touserdata(L, 1);
	pafcore::StaticProperty* property = instance->property;
	assert(property->get_isArray());
	pafcore::Variant value;
	errorCode = (*property->m_arraySizer)(&value);
	if (pafcore::s_ok == errorCode)
	{
		lua_Integer len;
		value.castToPrimitive(RuntimeTypeOf<lua_Integer>::RuntimeType::GetSingleton(), &len);
		lua_pushinteger(L, len);
		return 1;
	}
	else
	{
		Variant_Error(L, "#", errorCode);
		return 0;
	}
}

struct luaL_Reg g_staticArrayPropertyInstance_reg[] =
{
	{ "__index", StaticArrayProperty_Index },
	{ "__newindex", StaticArrayProperty_NewIndex },
	{ "__len", StaticArrayProperty_Len },
	{ NULL, NULL }
};

END_PAFLUA2
