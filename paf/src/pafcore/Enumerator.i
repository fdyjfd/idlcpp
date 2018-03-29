#import "Type.i"

namespace pafcore
{

	abstract class(enumerator)#PAFCORE_EXPORT Enumerator : Metadata
	{
		Type* _type_ get;
		int _value_ get;
#{
	public:
		Type* m_type;
		int m_value;
	public:
		Enumerator(const char* name, Attributes* attributes, Type* type, int value);
#}
	};

}