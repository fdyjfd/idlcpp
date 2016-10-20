#import "Typedef.i"

###include "RefCount.h"

namespace pafcore
{
	##	class ClassType;

	class #PAFCORE_EXPORT Reference ## : public RefCount
	{
		nometa virtual long_t addRef();
		nometa virtual long_t release();
		long_t refCount get;
#{
		void* castTo(ClassType* classType);
		template<typename T>
		void* castTo(ClassType* classType)
		{
			return reinterpret_cast<T*>(castTo(T::GetType()));
		}
#}
	};
}