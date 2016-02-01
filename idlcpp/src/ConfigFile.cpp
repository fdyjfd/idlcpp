#include <Windows.h>
#include <tchar.h>

/*
#include "../../thirdparty/lua/src/lua.hpp"

#include "Options.h"

static void stackDump (lua_State *L) 
{
	int i;
	int top = lua_gettop(L);
	for (i = 1; i <= top; i++) {
		int t = lua_type(L, i);
		switch (t) {
		case LUA_TSTRING:
			printf("`%s'", lua_tostring(L, i));
			break;
		case LUA_TBOOLEAN:
			printf(lua_toboolean(L, i) ? "true" : "false");
			break;
		case LUA_TNUMBER:
			printf("%g", lua_tonumber(L, i));
			break;
		default:
			printf("%s", lua_typename(L, t));
			break;
		}
		printf(" ");
	}
	printf("\n");
}

const char* GetGlobalString(lua_State *L, const char* name)
{
	const char* str = 0;
	lua_getglobal(L, name);
	if (lua_isstring(L, -1))
	{
		str = lua_tostring(L, -1);
	}
	lua_pop(L, 1);
	return str;
}

const char* GetFieldString(lua_State *L, int index)
{
	const char* str = 0;
	lua_rawgeti(L, -1, index);
	if (lua_isstring(L, -1))
	{
		str = lua_tostring(L, -1);
	}
	lua_pop(L, 1);
	return str;
}

void ParseConfigFile(const char* fileName)
{
	int error;
	lua_State *L = luaL_newstate();
	luaL_openlibs(L);
	error = luaL_loadfile(L, fileName) || lua_pcall(L, 0, 0, 0);
	if(error)
	{
		lua_pop(L, 1);
	}
	else
	{
		const char* str;
		str = GetGlobalString(L, "PafCore");
		if(str)
		{
			g_options.setPafcorePath(str);
		}
		str = GetGlobalString(L, "HeaderPostfix");
		if(str)
		{
			g_options.m_metaHeaderFilePostfix = str;
		}
		str = GetGlobalString(L, "SourcePostfix");
		if(str)
		{
			g_options.m_metaSourceFilePostfix = str;
		}
		str = GetGlobalString(L, "TypePostfix");
		if(str)
		{
			g_options.m_metaTypePostfix = str;
		}
	}
	lua_close(L);
}
*/

void ParseConfigFile()
{
	//char fileName[MAX_PATH];
	//GetModuleFileName(0, fileName, MAX_PATH);
	//char* end = _tcsrchr(fileName, '\\');
	//strcpy_s(end + 1, "idlcpp.config");
	//ParseConfigFile(fileName);
}

