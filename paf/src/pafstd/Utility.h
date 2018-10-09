#pragma once

#include "../pafcore/Utility.h"

#if defined PAFSTD_EXPORTS
	#define PAFSTD_EXPORT __declspec(dllexport)
	#define PAFSTD_TEMPLATE __declspec(dllexport)
#else
	#define PAFSTD_EXPORT __declspec(dllimport)
	#define PAFSTD_TEMPLATE
#endif

#define BEGIN_PAFSTD	namespace pafstd {
#define END_PAFSTD		}
