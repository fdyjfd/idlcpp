#import "Type.i"

namespace pafcore
{
	abstract class(type_alias)#PAFCORE_EXPORT TypeAlias : Metadata
	{
		Type* type { get };
#{
	public:
		TypeAlias(const char* name, Type* type);
		~TypeAlias();
	public:
		Type* m_type;
		Metadata* m_enclosing;
#}
	};

}