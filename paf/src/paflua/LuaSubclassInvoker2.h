#pragma once

#include "Utility.h"
#include "../pafcore/SubclassInvoker.h"
#include "lua.hpp"

BEGIN_PAFLUA2

struct LuaSubclassInvoker : public pafcore::SubclassInvoker
{
public:
	LuaSubclassInvoker(lua_State* luaState);
	~LuaSubclassInvoker();
public:
	virtual pafcore::ErrorCode invoke(const char* name, pafcore::Variant* result, pafcore::Variant* self, pafcore::Variant* args, size_t numArgs);
public:
	lua_State* m_luaState;
};

END_PAFLUA2
