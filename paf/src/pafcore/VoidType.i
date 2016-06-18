#import "Type.i"

namespace pafcore
{
	abstract class $PAFCORE_EXPORT VoidType(void_type) : Type
	{
		static void* AddressToPtr(size_t address);
		static void* NullPtr get;
		$*
	public:
		VoidType();
	public:
		virtual Metadata* findMember(const char* name);
	public:
		static VoidType* GetSingleton();
		*$
	};
	$*
	inline void* VoidType::AddressToPtr(size_t address)
	{
		return (void*)address;
	}
	inline void* VoidType::get_NullPtr()
	{
		return 0;
	}
	*$
}

$*
template<>
struct RuntimeTypeOf<void>
{
	typedef ::pafcore::VoidType RuntimeType;
	enum {type_category = ::pafcore::void_object};
};
*$
