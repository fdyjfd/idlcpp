#import "Argument.i"
#import "Result.i"

namespace pafcore
{
	abstract class $PAFCORE_EXPORT InstanceMethod(instance_method) : Metadata
	{
		size_t overloadCount get;
		Result ptr getResult(size_t overloadIndex);
		size_t getArgumentCount(size_t overloadIndex);
		Argument ptr getArgument(size_t overloadIndex, size_t index);
		$*
	public:
		InstanceMethod(const char* name, FunctionInvoker invoker, Overload* overloads, size_t overloadCount);
	public:
		FunctionInvoker m_invoker;
		Overload* m_overloads;
		size_t m_overloadCount;
		*$
	};

}