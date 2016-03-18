//tutorial

$$#include <stdio.h>

namespace tutorial
{
	struct Test
	{
		static void Run();
	};
	$*
	inline void Test::Run()
	{
		printf("Hello World!");
	}
	*$
}
