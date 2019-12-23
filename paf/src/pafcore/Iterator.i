#import "Reference.i"

#{
#include "Utility.h"
#}

namespace pafcore
{
	class #PAFCORE_EXPORT Iterator : Reference
	{
		virtual bool isEnd() const;
		virtual void moveNext();
		virtual void reset();
		virtual bool equal(Iterator* other) const;
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
		typedef IteratorImpl<C, I> ThisType;
	public:
		IteratorImpl(C* container) :
			m_container(container),
			m_end(container->end()),
			m_iterator(m_container->begin())
		{}

		IteratorImpl(C* container, const I& iterator) :
			m_container(container),
			m_end(container->end()),
			m_iterator(iterator)
		{}

		IteratorImpl(C* container, const I& end, const I& iterator) :
			m_container(container),
			m_end(end),
			m_iterator(iterator)
		{}
	public:
		virtual bool isEnd() const
		{
			return (m_end == m_iterator);
		}
		virtual void moveNext()
		{
			if (m_end != m_iterator)
			{
				++m_iterator;
			}
		}
		virtual void reset()
		{
			//m_end = m_container->end();
			m_iterator = m_container->begin();
		}
		virtual bool equal(Iterator* other) const
		{
			return (static_cast<ThisType*>(other)->m_iterator == m_iterator);
		}
	public:
		ContainerType* getContainer()
		{
			return m_container;
		}
		IteratorType& getIterator()
		{
			return m_iterator;
		}
	protected:
		ContainerType* m_container;
		IteratorType m_end;
		IteratorType m_iterator;
	};

	template<typename T>
	class ArrayIteratorImpl : public Iterator
	{
	public:
		typedef ArrayIteratorImpl<T> ThisType;
	public:
		ArrayIteratorImpl(T* begin, size_t size) :
			m_begin(begin),
			m_size(size),
			m_index(0)
		{}
		ArrayIteratorImpl(T* begin, size_t size, size_t index) :
			m_begin(begin),
			m_size(size),
			m_index(index)
		{}
	public:
		virtual bool isEnd() const
		{
			return (m_index == m_size);
		}
		virtual void moveNext()
		{
			if (m_index != m_size)
			{
				++m_index;
			}
		}
		virtual void reset()
		{
			m_index = 0;
		}
		virtual bool equal(Iterator* other) const
		{
			ThisType* that = static_cast<ThisType*>(other);
			return (that->m_begin + that->m_index == m_begin + m_index);
		}
	public:
		T* getBegin()
		{
			return m_begin;
		}
		size_t getIndex()
		{
			return m_index;
		}
	protected:
		T* m_begin;
		size_t m_size;
		size_t m_index;
	};

	template<typename C, typename I>
	static IteratorImpl<C, I> MakeIterator(C* c, const I& i)
	{
		return IteratorImpl<C, I>(c, i);
	}
	template<typename C>
	static IteratorImpl<C, typename C::iteartor> MakeIterator(C* c)
	{
		return IteratorImpl<C>IteratorImpl(c);
	}

	template<typename T>
	static ArrayIteratorImpl<T> MakeIterator(T* begin, size_t size)
	{
		return ArrayIteratorImpl<T>(begin, size);
	}

	template<typename T>
	static ArrayIteratorImpl<T> MakeIterator(T* begin, size_t size, size_t index)
	{
		return ArrayIteratorImpl<T>(begin, size, index);
	}

#}


}
