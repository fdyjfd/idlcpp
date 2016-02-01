#import "Type.i"

namespace pafcore
{
	abstract class $PAFCORE_EXPORT TypeAlias(type_alias) : Metadata
	{
		Type ptr type get;
		$*
	public:
		TypeAlias(const char* name, Type* type);
	public:
		Type* m_type;
		*$
	};

}