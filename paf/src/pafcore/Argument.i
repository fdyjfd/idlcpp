#import "Type.i"

namespace pafcore
{
	abstract class $PAFCORE_EXPORT Argument(function_argument) : Metadata
	{
		Type ptr type get;
		bool byValue get;
		bool byRef get;
		bool byPtr get;
		bool byOutPtr get;
		bool byOutRef get;
		bool byNewPtr get;
		bool byNewRef get;
		bool byNewArrayPtr get;
		bool byNewArrayRef get;
		$*
	public:
		Argument(const char* name, Type* type, Passing passing);
	public:
		Type* m_type;
		Passing m_passing;
		*$
	};
}