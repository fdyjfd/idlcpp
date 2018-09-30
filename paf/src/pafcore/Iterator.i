#import "Reference.i"

#{
#include "Utility.h"
#}

namespace pafcore
{
	class #PAFCORE_EXPORT Iterator : Reference
	{
		virtual bool isEnd();
		virtual void moveNext();
		virtual void reset();
#{
	protected:
		Iterator() : m_refCount(1)
		{}
	public:
		virtual long_t addRef();
		virtual long_t release();
	protected: 
		long_t m_refCount; 
#}
	};

#{
	template<typename C, typename I = C::iterator>
	class IteratorImpl : public Iterator
	{
	public:
		typedef C ContainerType;
		typedef I IteratorType;
	public:
		IteratorImpl(C* container) : m_container(container)
		{
			m_iterator = m_container->begin();
		}
	public:
		virtual bool isEnd()
		{
			return (m_container->end() == m_iterator);
		}
		virtual void moveNext()
		{
			if (m_container->end() != m_iterator)
			{
				++m_iterator;
			}
		}
		virtual void reset()
		{
			m_iterator = m_container->begin();
		}
	protected:
		ContainerType* m_container;
		IteratorType m_iterator;
	};
#}


}
