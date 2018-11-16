#pragma once

#include "Utility.h"


BEGIN_PAFSTD

//侵入式链表
template<typename T, int t_id> class LinkedList;

template<typename T, int t_id = 0>
struct PAFSTD_TEMPLATE LinkBase
{
	friend class LinkedList<T, t_id>;
protected:
	LinkBase()
	{
		m_next = 0;
		m_prev = 0;
	}
	LinkBase(const LinkBase&)
	{
		m_next = 0;
		m_prev = 0;
	};
	~LinkBase()
	{
		unlink();
	}
protected:
	LinkBase<T, t_id>* getNext() const
	{
		return m_next;
	}
	LinkBase<T, t_id>** getPrev() const
	{
		return m_prev;
	}
	bool isFree() const
	{
		return 0 == m_prev;
	}
	void unlink()
	{
		if (m_prev)
		{
			PAF_ASSERT(this == *m_prev);
			*m_prev = m_next;
			if (m_next)
			{
				PAF_ASSERT(&m_next == m_next->m_prev);
				m_next->m_prev = m_prev;
				m_next = 0;
			}
			m_prev = 0;
		}
		PAF_ASSERT(0 == m_next);
	}
	void linkBefore(LinkBase<T, t_id>* node)
	{
		PAF_ASSERT(0 == m_prev && 0 == m_next && 0 != node && 0 != node->m_prev);
		m_prev = node->m_prev;
		m_next = node;
		*node->m_prev = this;
		node->m_prev = &m_next;
	}
	void linkAfter(LinkBase<T, t_id>* node)
	{
		PAF_ASSERT(0 == m_prev && 0 == m_next && 0 != node && 0 != node->m_prev);
		if (node->m_next)
		{
			PAF_ASSERT(&node->m_next == node->m_next->m_prev);
			m_next = node->m_next;
			node->m_next->m_prev = &m_next;
 		}
		node->m_next = this;
		m_prev = &node->m_next;
	}
protected:
	LinkBase<T, t_id>* m_next;
	LinkBase<T, t_id>** m_prev;
};

template<typename T, int t_id = 0>
class PAFSTD_TEMPLATE LinkedList
{
public:
	typedef LinkBase<T, t_id> NodeType;
public:
	LinkedList()
	{
		m_head = 0;
	}
private:
	LinkedList(const LinkedList&);
public:
	LinkBase<T, t_id>* getHead()
	{
		return m_head;
	}
	LinkBase<T, t_id>* getNil()
	{
		return 0;
	}
	bool empty()
	{
		return 0 == m_head;
	}
	size_t length()
	{
		size_t res = 0;
		LinkBase<T, t_id>* current = m_head;
		while (current)
		{
			++res;
			current = current->m_next;
		}
		return res;
	}
	bool find(LinkBase<T, t_id>* node)
	{
		LinkBase<T, t_id>* current = m_head;
		while (current)
		{
			if (node == current)
			{
				return true;
			}
			current = current->m_next;
		}
		return false;
	}
	void addHead(LinkBase<T, t_id>* node)
	{
		PAF_ASSERT(node->isFree());
		node->m_next = m_head;
		node->m_prev = &m_head;
		if (m_head)
		{
			m_head->m_prev = &node->m_next;
		}
		m_head = node;
	}
	void swap(LinkedList<T, t_id>& list)
	{
		LinkBase<T, t_id>* tmp = m_head;
		m_head = list.m_head;
		list.m_head = tmp;
	}
	void unlinkAll()
	{
		NodeType* node = m_head;
		while (node)
		{
			NodeType* next = node->m_next;
			node->unlink();
			node = next;
		}
		PAF_ASSERT(0 == m_head);	
	}
protected:
	LinkBase<T, t_id>* m_head;
};


//侵入式双向链表

template<typename T, int t_id > class DoublyLinkedList;
template<typename T, int t_id > class DoublyLinkedListIterator;

template<typename T, int t_id = 0>
struct PAFSTD_TEMPLATE DoublyLinkBase
{
	friend class DoublyLinkedList<T, t_id>;
	friend class DoublyLinkedListIterator<T, t_id>;
public:
	DoublyLinkBase()
	{
		m_next = this;
		m_prev = this;
	}
	DoublyLinkBase(const DoublyLinkBase& arg)
	{
		m_next = this;
		m_prev = this;
	}
	~DoublyLinkBase()
	{
		unlink();
	}
public:
	DoublyLinkBase<T, t_id>* getNext() const
	{
		return m_next;
	}
	DoublyLinkBase<T, t_id>* getPrev() const
	{
		return m_prev;
	}
	bool isFree() const
	{
		return (this == m_next);
	}
	void unlink()
	{
		m_prev->m_next = m_next;
		m_next->m_prev = m_prev;
		m_next = this;
		m_prev = this;
	}
protected:
	DoublyLinkBase<T, t_id>* m_next;
	DoublyLinkBase<T, t_id>* m_prev;
};

template<typename T, int t_id = 0>
class PAFSTD_TEMPLATE DoublyLinkedListIterator
{
public:
	DoublyLinkedListIterator(DoublyLinkBase<T, t_id>* ptr) : m_ptr(ptr)
	{}
public:
	DoublyLinkedListIterator& operator++()
	{
		m_ptr = m_ptr->m_next;
		return *this;
	}
	DoublyLinkedListIterator operator++(int)
	{
		DoublyLinkedListIterator it = *this;
		m_ptr = m_ptr->m_next;
		return it;
	}
	DoublyLinkedListIterator& operator--()
	{
		m_ptr = m_ptr->m_prev;
		return *this;
	}
	DoublyLinkedListIterator operator--(int)
	{
		DoublyLinkedListIterator it = *this;
		m_ptr = m_ptr->m_prev;
		return it;
	}
	bool operator == (const DoublyLinkedListIterator& arg) const
	{
		return arg.m_ptr == m_ptr;
	}
	bool operator != (const DoublyLinkedListIterator& arg) const
	{
		return arg.m_ptr != m_ptr;
	}
	T* operator*()
	{
		return static_cast<T*>(m_ptr);
	}
protected:
	DoublyLinkBase<T, t_id>* m_ptr;
};


template<typename T, int t_id = 0>
class PAFSTD_TEMPLATE DoublyLinkedList : public DoublyLinkBase<T, t_id>
{
public:
	typedef DoublyLinkedListIterator<T, t_id> iterator;
public:
	iterator begin()
	{
		return iterator(getHead());
	}
	iterator end()
	{
		return iterator(getNil());
	}
	DoublyLinkBase<T, t_id>* getHead();
	DoublyLinkBase<T, t_id>* getTail();
	DoublyLinkBase<T, t_id>* getNil();
	bool empty();
	size_t length();
	bool find(DoublyLinkBase<T, t_id>* node);
	bool findInverse(DoublyLinkBase<T, t_id>* node);
	void addHead(DoublyLinkBase<T, t_id>* node);
	void addTail(DoublyLinkBase<T, t_id>* node);
	void insert(DoublyLinkBase<T, t_id>* node, DoublyLinkBase<T, t_id>* right);
	void insertAfter(DoublyLinkBase<T, t_id>* node, DoublyLinkBase<T, t_id>* left);
	void removeHead();
	void removeTail();
	void spliceTail(DoublyLinkedList<T, t_id>& list);
	void spliceHead(DoublyLinkedList<T, t_id>& list);
	void splice(DoublyLinkBase<T, t_id>* right, DoublyLinkedList<T, t_id>& list);
	void splice(DoublyLinkBase<T, t_id>* right, DoublyLinkedList<T, t_id>& list, DoublyLinkBase<T, t_id>* first);
	void splice(DoublyLinkBase<T, t_id>* right, DoublyLinkedList<T, t_id>& list, DoublyLinkBase<T, t_id>* first, DoublyLinkBase<T, t_id>* last);
	void swap(DoublyLinkedList<T, t_id>& list);
};

//------------------------------------------------------------------------------

template<typename T, int t_id>
inline DoublyLinkBase<T, t_id>* DoublyLinkedList<T, t_id>::getHead()
{
	return this->m_next;
}

template<typename T, int t_id>
inline DoublyLinkBase<T, t_id>* DoublyLinkedList<T, t_id>::getTail()
{
	return this->m_prev;
}

template<typename T, int t_id>
inline DoublyLinkBase<T, t_id>* DoublyLinkedList<T, t_id>::getNil()
{
	return this;
}

template<typename T, int t_id>
inline bool DoublyLinkedList<T, t_id>::empty()
{
	return (this == this->m_next);
}

template<typename T, int t_id>
inline size_t DoublyLinkedList<T, t_id>::length()
{
	size_t length = 0;
	DoublyLinkBase<T, t_id>* current = this->m_next;
	while(this != current)
	{
		++length;
		current = current->m_next;
	}
	return length;
}

template<typename T, int t_id>
inline bool DoublyLinkedList<T, t_id>::find(DoublyLinkBase<T, t_id>* node)
{
	DoublyLinkBase<T, t_id>* current = this->m_next;
	while(this != current)
	{
		if(node == current)
		{
			return true;
		}
		current = current->m_next;
	}
	return false;
}

template<typename T, int t_id>
inline bool DoublyLinkedList<T, t_id>::findInverse(DoublyLinkBase<T, t_id>* node)
{
	DoublyLinkBase<T, t_id>* current = this->m_prev;
	while(this != current)
	{
		if(node == current)
		{
			return true;
		}
		current = current->m_prev;
	}
	return false;
}

template<typename T, int t_id>
inline void DoublyLinkedList<T, t_id>::addHead(DoublyLinkBase<T, t_id>* node)
{
	PAF_ASSERT(node->isFree());
	node->m_prev = this;
	node->m_next = this->m_next;
	this->m_next->m_prev = node;
	this->m_next = node;
}

template<typename T, int t_id>
inline void DoublyLinkedList<T, t_id>::addTail(DoublyLinkBase<T, t_id>* node)
{
	PAF_ASSERT(node->isFree());
	node->m_prev = this->m_prev;
	node->m_next = this;
	this->m_prev->m_next = node;
	this->m_prev = node;
}

template<typename T, int t_id>
inline void DoublyLinkedList<T, t_id>::insert(DoublyLinkBase<T, t_id>* node, DoublyLinkBase<T, t_id>* right)
{
	PAF_ASSERT(node->isFree());
	DoublyLinkBase<T, t_id>* left = right->m_prev;
	node->m_prev = left;
	node->m_next = right;
	left->m_next = node;
	right->m_prev = node;
}

template<typename T, int t_id>
inline void DoublyLinkedList<T, t_id>::insertAfter(DoublyLinkBase<T, t_id>* node, DoublyLinkBase<T, t_id>* left)
{
	PAF_ASSERT(node->isFree());
	DoublyLinkBase<T, t_id>* right = left->m_next;
	node->m_prev = left;
	node->m_next = right;
	left->m_next = node;
	right->m_prev = node;
}

template<typename T, int t_id>
inline void DoublyLinkedList<T, t_id>::removeHead()
{
	this->m_next->Remove();
}

template<typename T, int t_id>
inline void DoublyLinkedList<T, t_id>::removeTail()
{
	this->m_prev->Remove();
}

template<typename T, int t_id>
inline void DoublyLinkedList<T, t_id>::spliceTail(DoublyLinkedList<T, t_id>& list)
{
	if(!list.Empty())
	{
		list.m_next->m_prev = this->m_prev;
		list.m_prev->m_next = this;
		this->m_prev->m_next = list.m_next;
		this->m_prev = list.m_prev;
		list.m_next = &list;
		list.m_prev = &list;
	}
}

template<typename T, int t_id>
inline void DoublyLinkedList<T, t_id>::spliceHead(DoublyLinkedList<T, t_id>& list)
{
	if(!list.Empty())
	{
		list.m_next->m_prev = this;
		list.m_prev->m_next = this->m_next;
		this->m_next->m_prev = list.m_prev;
		this->m_next = list.m_next;
		list.m_next = &list;
		list.m_prev = &list;
	}
}

template<typename T, int t_id>
inline void DoublyLinkedList<T, t_id>::splice(DoublyLinkBase<T, t_id>* right, DoublyLinkedList<T, t_id>& list)
{
	if(!list.Empty())
	{
		DoublyLinkBase<T, t_id>* left = right->m_prev;
		list.m_next->m_prev = left;
		list.m_prev->m_next = right;
		left->m_next = list.m_next;
		right->m_prev = list.m_prev;		
		list.m_next = &list;
		list.m_prev = &list;
	}
}

template<typename T, int t_id>
inline void DoublyLinkedList<T, t_id>::splice(DoublyLinkBase<T, t_id>* right, DoublyLinkedList<T, t_id>& list, DoublyLinkBase<T, t_id>* first)
{
	if(first != &list)
	{
		DoublyLinkBase<T, t_id>* left = right->m_prev;
		DoublyLinkBase<T, t_id>* prevFirst = first->m_prev;
		
		first->m_prev = left;
		list.m_prev->m_next = right;
		left->m_next = first;
		right->m_prev = list.m_prev;		
		
		prevFirst->m_next = &list;
		list.m_prev = prevFirst;
	}
}

template<typename T, int t_id>
inline void DoublyLinkedList<T, t_id>::splice(DoublyLinkBase<T, t_id>* right, DoublyLinkedList<T, t_id>& list, DoublyLinkBase<T, t_id>* first, DoublyLinkBase<T, t_id>* last)
{
	if(first != &list && first != last)
	{
		DoublyLinkBase<T, t_id>* left = right->m_prev;
		DoublyLinkBase<T, t_id>* prevLast = last->m_prev;
		DoublyLinkBase<T, t_id>* prevFirst = first->m_prev;
		
		first->m_prev = left;
		prevLast->m_next = right;
		left->m_next = first;
		right->m_prev = prevLast;

		prevFirst->m_next = last;
		last->m_prev = prevFirst;
	}
}

template<typename T, int t_id>
inline void DoublyLinkedList<T, t_id>::swap(DoublyLinkedList<T, t_id>& list)
{
	bool b1 = empty();
	bool b2 = list.empty();
	if(b1)
	{
		if(!b2)
		{
			list.m_next->m_prev = this;
			this->m_next = list.m_next;
			list.m_prev->m_next = this;
			this->m_prev = list.m_prev;
			list.m_next = &list;
			list.m_prev = &list;
		}
	}
	else
	{
		if(b2)
		{
			this->m_next->m_prev = &list;
			list.m_next = this->m_next;
			this->m_prev->m_next = &list;
			list.m_prev = this->m_prev;
			this->m_next = this;
			this->m_prev = this;
		}
		else
		{
			list.m_next->m_prev = this;
			list.m_prev->m_next = this;
			this->m_next->m_prev = &list;
			this->m_prev->m_next = &list;
			DoublyLinkBase<T, t_id>* tmp;
			tmp = this->m_next;
			this->m_next = list.m_next;
			list.m_next = tmp;
			tmp = this->m_prev;
			this->m_prev = list.m_prev;
			list.m_prev = tmp;
		}
	}
}

END_PAFSTD
