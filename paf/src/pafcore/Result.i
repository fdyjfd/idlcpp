#import "Type.i"

namespace pafcore
{
	$$class Variant;

	abstract class $PAFCORE_EXPORT Result(function_result) : Metadata
	{
		Type ptr type get;
		bool byValue get;
		bool byRef get;
		bool byPtr get;
		bool byNew get;
		bool byNewArray get;
		bool isConstant get;
		$*
	public:
		Result(Type* type, bool constant, Passing passing);
	public:
		Type* m_type;
		bool m_constant;
		byte_t m_passing;
		*$
	};

}