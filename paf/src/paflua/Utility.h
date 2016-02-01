#pragma once

#include "../pafcore/Utility.h"

#if defined PAFLUA_EXPORTS
	#define PAFLUA_EXPORT __declspec(dllexport)
#else
	#define PAFLUA_EXPORT __declspec(dllimport)
#endif

#define BEGIN_PAFLUA namespace paflua {
#define END_PAFLUA }
