#import "Type.i"

namespace pafcore
{
	abstract class(type_alias)$PAFCORE_EXPORT TypeAlias : Metadata
	{
		Type* type get;
		$*
	public:
		TypeAlias(const char* name, Type* type);
	public:
		Type* m_type;
		*$
	};

}