#include "paflua.h"
#include "lua.hpp"
#include "LuaWrapper.h"
#include "LuaWrapper2.h"
#include "../pafcore/Variant.h"
#include "../pafcore/NameSpace.h"
#include "../pafcore/NameSpace.mh"
#include <new.h>
#include <Windows.h>

void init_paf(lua_State *L)
{
	luaL_newmetatable(L, paflua::instanceArrayProperty_metatable_name);
	luaL_setfuncs(L, paflua::g_instanceArrayPropertyInstance_reg, 0);

	luaL_newmetatable(L, paflua::staticArrayProperty_metatable_name);
	luaL_setfuncs(L, paflua::g_staticArrayPropertyInstance_reg, 0);

	luaL_newmetatable(L, paflua::instanceMapProperty_metatable_name);
	luaL_setfuncs(L, paflua::g_instanceMapPropertyInstance_reg, 0);

	luaL_newmetatable(L, paflua::staticMapProperty_metatable_name);
	luaL_setfuncs(L, paflua::g_staticMapPropertyInstance_reg, 0);

	luaL_newmetatable(L, paflua::variant_metatable_name);
	luaL_setfuncs(L, paflua::g_variant_reg, 0);

	void* p = lua_newuserdata(L, sizeof(pafcore::Variant));
	pafcore::Variant* variant = new(p)pafcore::Variant;
	variant->assignReferencePtr(RuntimeTypeOf<pafcore::NameSpace>::RuntimeType::GetSingleton(), pafcore::NameSpace::GetGlobalNameSpace(), false, ::pafcore::Variant::by_ptr);
	luaL_getmetatable(L, paflua::variant_metatable_name);
	lua_setmetatable(L, -2);
	lua_setglobal(L, "idlcpp");
}

void init_paf2(lua_State *L)
{
	luaL_newmetatable(L, paflua2::instanceArrayProperty_metatable_name);
	luaL_setfuncs(L, paflua2::g_instanceArrayPropertyInstance_reg, 0);

	luaL_newmetatable(L, paflua2::staticArrayProperty_metatable_name);
	luaL_setfuncs(L, paflua2::g_staticArrayPropertyInstance_reg, 0);

	luaL_newmetatable(L, paflua2::variant_metatable_name);
	luaL_setfuncs(L, paflua2::g_variant_reg, 0);

	void* p = lua_newuserdata(L, sizeof(pafcore::Variant));
	pafcore::Variant* variant = new(p)pafcore::Variant;
	variant->assignReferencePtr(RuntimeTypeOf<pafcore::NameSpace>::RuntimeType::GetSingleton(), pafcore::NameSpace::GetGlobalNameSpace(), false, ::pafcore::Variant::by_ptr);
	luaL_getmetatable(L, paflua2::variant_metatable_name);
	lua_setmetatable(L, -2);
	lua_setglobal(L, "idlcpp2");
}

int luaopen_paflua(lua_State *L)
{
	init_paf(L);
	//init_paf2(L);
	return 1;
}

BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	if (DLL_PROCESS_ATTACH == dwReason)
	{
		OutputDebugStringA("paflua Process Attach\n");
	}
	else if (DLL_PROCESS_DETACH == dwReason)
	{
		OutputDebugStringA("paflua Process Detach\n");
	}
	return TRUE;
}
