#include "LuaCallBack.h"
#include "LuaCallBack.mh"
#include "LuaCallBack.ic"
#include "LuaCallBack.mc"
#include "lua.hpp"
#include <Windows.h>

BEGIN_PAFLUA

pafcore::Variant* LuaToVariant(pafcore::Variant* value, lua_State *L, int index);
void VariantToLua(lua_State *L, pafcore::Variant* variant);
void stackDump(lua_State *L);

LuaCallBack::LuaCallBack(lua_State* luaState, const char* funcName)
{
	m_luaState = luaState;
	lua_pop(m_luaState, 1);
	int type = lua_type(m_luaState, LUA_REGISTRYINDEX);
	lua_rawsetp(luaState, LUA_REGISTRYINDEX, this);
	m_funcName = funcName;
}

LuaCallBack::~LuaCallBack()
{
	lua_pushnil(m_luaState);
	lua_rawsetp(m_luaState, LUA_REGISTRYINDEX, this);
}

void LuaCallBack::invoke(pafcore::Variant* result, pafcore::Variant** args, int_t numArgs)
{
#ifdef _DEBUG
	int top = lua_gettop(m_luaState);
	//stackDump(m_luaState);
#endif

	lua_rawgetp(m_luaState, LUA_REGISTRYINDEX, this);
	lua_getfield(m_luaState, -1, m_funcName.c_str());
	lua_insert(m_luaState, -2);
	for (size_t i = 1; i < numArgs; ++i)
	{
		VariantToLua(m_luaState, args[i]);
	}
	int error = lua_pcall(m_luaState, numArgs, 1, 0);
	if (error)
	{
		const char* str = lua_tostring(m_luaState, -1);
#ifdef _DEBUG
		OutputDebugStringA(str);
		OutputDebugStringA("\n");
#endif
		lua_pop(m_luaState, 1);
	}
	else
	{
		pafcore::Variant* value = LuaToVariant(result, m_luaState, -1);
		if (value != result)
		{
			result->move(*value);
		}
		lua_pop(m_luaState, 1);
		//for(size_t i = 0; i < numArgs; ++i)
		//{
		//	args[i].move(*luaArgs[i]);
		//}
	}

#ifdef _DEBUG
	PAF_ASSERT(lua_gettop(m_luaState) == top);
	//stackDump(m_luaState);
#endif

	//return (0 == error) ? pafcore::s_ok : pafcore::e_script_dose_not_override;
}

bool LuaCallBack::equal(CallBack* arg)
{
	return false;
}



LuaCallBack2::LuaCallBack2(lua_State* luaState)
{
	m_luaState = luaState;
	int type = lua_type(m_luaState, LUA_REGISTRYINDEX);
	lua_rawsetp(luaState, LUA_REGISTRYINDEX, this);
}

LuaCallBack2::~LuaCallBack2()
{
	lua_pushnil(m_luaState);
	lua_rawsetp(m_luaState, LUA_REGISTRYINDEX, this);
}

void LuaCallBack2::invoke(pafcore::Variant* result, pafcore::Variant** args, int_t numArgs)
{
#ifdef _DEBUG
	int top = lua_gettop(m_luaState);
	//stackDump(m_luaState);
#endif

	lua_rawgetp(m_luaState, LUA_REGISTRYINDEX, this);
	//stackDump(m_luaState);
	for (size_t i = 1; i < numArgs; ++i)
	{
		VariantToLua(m_luaState, args[i]);
	}
	int error = lua_pcall(m_luaState, numArgs - 1, 1, 0);
	if (error)
	{
		const char* str = lua_tostring(m_luaState, -1);
#ifdef _DEBUG
		OutputDebugStringA(str);
		OutputDebugStringA("\n");
#endif
		lua_pop(m_luaState, 1);
	}
	else
	{
		pafcore::Variant* value = LuaToVariant(result, m_luaState, -1);
		if (value != result)
		{
			result->move(*value);
		}
		lua_pop(m_luaState, 1);
		//for(size_t i = 0; i < numArgs; ++i)
		//{
		//	args[i].move(*luaArgs[i]);
		//}
	}

#ifdef _DEBUG
	//stackDump(m_luaState);
	PAF_ASSERT(lua_gettop(m_luaState) == top);
#endif

	//return (0 == error) ? pafcore::s_ok : pafcore::e_script_dose_not_override;
}

bool LuaCallBack2::equal(CallBack* arg)
{
	return false;
}


END_PAFLUA
