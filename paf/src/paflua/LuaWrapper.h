#pragma once

#include "Utility.h"
#include "lua.hpp"

BEGIN_PAFLUA

extern const char* variant_metatable_name;
extern const char* instanceArrayProperty_metatable_name;
extern const char* staticArrayProperty_metatable_name;

extern struct luaL_Reg g_instanceArrayPropertyInstance_reg[];
extern struct luaL_Reg g_staticArrayPropertyInstance_reg[];
extern struct luaL_Reg g_variant_reg[];

END_PAFLUA


