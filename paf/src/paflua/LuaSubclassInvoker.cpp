#include "LuaSubclassInvoker.h"
#include "lua.hpp"
#include <new>

BEGIN_PAFLUA

extern const char* variant_metatable_name;
void stackDump (lua_State *L);
pafcore::Variant* LuaToVariant(pafcore::Variant* value, lua_State *L, int index);

pafcore::Variant* VariantToLua2(lua_State *L, pafcore::Variant* variant)
{
	void* p = lua_newuserdata(L, sizeof(pafcore::Variant));
	pafcore::Variant* res = new(p)pafcore::Variant;
	res->move(*variant);
	luaL_getmetatable(L, variant_metatable_name);
	lua_setmetatable(L, -2);
	return res;
}

LuaSubclassInvoker::LuaSubclassInvoker(lua_State* luaState)
{
	m_luaState = luaState;
	lua_rawsetp(luaState, LUA_REGISTRYINDEX, this);
}

LuaSubclassInvoker::~LuaSubclassInvoker()
{
	lua_pushnil(m_luaState);
	lua_rawsetp(m_luaState, LUA_REGISTRYINDEX, this);
}

pafcore::ErrorCode LuaSubclassInvoker::invoke(const char* name, pafcore::Variant* result, pafcore::Variant* self, pafcore::Variant* args, size_t numArgs)
{
	pafcore::Variant* luaArgs[20];
	lua_rawgetp(m_luaState, LUA_REGISTRYINDEX, this);
	lua_getfield(m_luaState, -1, name);
	lua_pushvalue(m_luaState, -2);
	for(size_t i = 0; i < numArgs; ++i)
	{
		luaArgs[i] = VariantToLua2(m_luaState, &args[i]);
	}
	int error = lua_pcall(m_luaState, numArgs + 1, 1, 0);
	if (error)
	{
		const char* str = lua_tostring(m_luaState, -1);
		lua_pop(m_luaState, 1);
	}
	pafcore::Variant* value = LuaToVariant(result, m_luaState, -1);
	if(value != result)
	{
		result->move(*value);
	}
	for(size_t i = 0; i < numArgs; ++i)
	{
		args[i].move(*luaArgs[i]);
	}
	return (0 == error) ? pafcore::s_ok : pafcore::e_script_dose_not_override;
}

END_PAFLUA
