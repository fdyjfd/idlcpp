#pragma once

#include "Utility.h"

#ifdef __cplusplus
extern "C" {
#endif 

	typedef struct lua_State lua_State;

	int PAFLUA_EXPORT luaopen_paflua(lua_State *L);

#ifdef __cplusplus
}
#endif 

