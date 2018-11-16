#{
#include "Utility.h"
#}

namespace pafcore
{
	struct #PAFCORE_EXPORT System
	{
		static void LoadDLL(string_t fileName);
		static void OutputDebug(string_t str);
	};
}

