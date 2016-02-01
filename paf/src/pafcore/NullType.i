#import "Type.i"

namespace pafcore
{
	abstract class $PAFCORE_EXPORT NullType(null_type) : Type
	{
		$*
	public:
		NullType();
	public:
		virtual Metadata* findMember(const char* name);
	public:
		static NullType* GetSingleton();
		*$
	};
}

$*
template<>
struct RuntimeTypeOf<void>
{
	typedef ::pafcore::NullType RuntimeType;
	enum {type_category = ::pafcore::null_object};
};
*$
