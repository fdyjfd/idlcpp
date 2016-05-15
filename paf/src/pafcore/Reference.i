#import "Typedef.i"

$$#include "Utility.h"

namespace pafcore
{
	$$	class ClassType;

	class $PAFCORE_EXPORT Reference
	{
	native:
		virtual long_t addRef();
		virtual long_t release();
	all:
		long_t refCount get;
		$*
		void* castTo(ClassType* classType);
		template<typename T>
		void* castTo(ClassType* classType)
		{
			return reinterpret_cast<T*>(castTo(T::GetType()));
		}
		*$
	};
}