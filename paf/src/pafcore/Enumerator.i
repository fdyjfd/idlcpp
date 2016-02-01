#import "Type.i"

namespace pafcore
{

	abstract class $PAFCORE_EXPORT Enumerator(enumerator) : Metadata
	{
		Type ptr _type_ get;
		int _value_ get;
		$*
	public:
		Type* m_type;
		int m_value;
	public:
		Enumerator(const char* name, Type* type, size_t value);
		*$
	};

}