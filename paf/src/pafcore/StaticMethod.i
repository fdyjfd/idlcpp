#import "Argument.i"
#import "Result.i"

$$#include "Overload.h"

namespace pafcore
{
	abstract class(static_method)$PAFCORE_EXPORT StaticMethod : Metadata
	{
		size_t overloadCount get;
		Result* getResult(size_t overloadIndex);
		size_t getArgumentCount(size_t overloadIndex);
		Argument* getArgument(size_t overloadIndex, size_t index);
		$*
	public:
		StaticMethod(const char* name, FunctionInvoker invoker, Overload* overloads, size_t overloadCount);
	public:
		FunctionInvoker m_invoker;
		Overload* m_overloads;
		size_t m_overloadCount;
		*$
	};

}