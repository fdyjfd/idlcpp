#import "Argument.i"
#import "Result.i"

###include "Overload.h"

namespace pafcore
{
	abstract class(instance_method)#PAFCORE_EXPORT InstanceMethod : Metadata
	{
		size_t overloadCount get;
		Result* getResult(size_t overloadIndex);
		size_t getArgumentCount(size_t overloadIndex);
		Argument* getArgument(size_t overloadIndex, size_t index);
#{
	public:
		InstanceMethod(const char* name, FunctionInvoker invoker, Overload* overloads, size_t overloadCount);
	public:
		FunctionInvoker m_invoker;
		Overload* m_overloads;
		size_t m_overloadCount;
#}
	};

}