#pragma once

#include "../pafcore/Utility.h"

#if defined PAFPYTHON_EXPORTS
	#define PAFPYTHON_EXPORT __declspec(dllexport)
#else
	#define PAFPYTHON_EXPORT __declspec(dllimport)
#endif

#define BEGIN_PAFPYTHON namespace pafpython {
#define END_PAFPYTHON }
