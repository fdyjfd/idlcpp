#import "Typedef.i"

###include "RefCount.h"

namespace pafcore
{
	##	class ClassType;

	class #PAFCORE_EXPORT Reference ## : public RefCount
	{
#{
		bool isTypeOf(ClassType* classType);

		template<typename T>
		bool isTypeOf()
		{
			return isTypeOf(T::GetType());
		}

		bool isStrictTypeOf(ClassType* classType)
		{
			return getType() == classType;
		}

		template<typename T>
		bool isStrictTypeOf()
		{
			return isStrictTypeOf(T::GetType());
		}

		void* castTo(ClassType* classType);

		template<typename T>
		void* castTo()
		{
			return reinterpret_cast<T*>(castTo(T::GetType()));
		}
#}
	};
}