#pragma once

#include "Utility.h"
#include <vector>
#include <algorithm>

BEGIN_PAFCORE

template<class T, class Pred = std::less<T>>
class VectorSet : private std::vector<T>
{
public:
	typedef T key_type;
	typedef Pred key_compare;
	typedef Pred value_compare;
	typedef std::vector<T> vector_type;
	typedef typename vector_type::size_type size_type;
	typedef typename vector_type::difference_type difference_type;
	typedef typename vector_type::allocator_type allocator_type;
	typedef typename vector_type::value_type value_type;
	typedef typename vector_type::reference reference;
	typedef typename vector_type::const_reference const_reference;
	typedef typename vector_type::iterator iterator;
	typedef typename vector_type::const_iterator const_iterator;
	typedef typename vector_type::reverse_iterator reverse_iterator;
	typedef typename vector_type::const_reverse_iterator const_reverse_iterator;
	typedef std::pair<iterator, bool> _Pairib;
	typedef std::pair<iterator, iterator> _Pairii;
	typedef std::pair<const_iterator, const_iterator> _Paircc;
public:
	void reserve(size_t count)
	{
		vector_type::reserve(count);
	}
	iterator begin()
	{
		return vector_type::begin();
	}
	const_iterator begin() const
	{
		return vector_type::begin();
	}
	iterator end()
	{
		return vector_type::end();
	}
	const_iterator end() const
	{
		return vector_type::end();
	}
	reverse_iterator rbegin()
	{
		return vector_type::rbegin();
	}
	const_reverse_iterator rbegin() const
	{
		return vector_type::rbegin();
	}
	reverse_iterator rend()
	{
		return vector_type::rend();
	}
	const_reverse_iterator rend() const
	{
		return vector_type::rend();
	}
	size_type size() const
	{
		return vector_type::size();
	}
	size_type max_size() const
	{
		return vector_type::max_size();
	}
	bool empty() const
	{
		return vector_type::empty();
	}
	reference operator[](size_type n)
	{
		return *(begin() + n);
	}
	const_reference operator[](size_type n) const
	{
		return *(begin() + n);
	}
	reference front()
	{
		return vector_type::front();
	}
	const_reference front( ) const
	{
		return vector_type::front();
	}
	reference back()
	{
		return vector_type::back();
	}
	const_reference back() const
	{
		return vector_type::back();
	}
	_Pairib insert(const value_type& x)
	{
		typename vector_type::iterator it = std::lower_bound(vector_type::begin(), vector_type::end(), x, Pred());
		if(vector_type::end() == it)
		{
			return _Pairib(vector_type::insert(vector_type::end(), x), true);
		}
		else
		{
			if(key_compare()(x, *it))
			{
				return _Pairib(vector_type::insert(it, x), true);
			}
			else
			{
				return _Pairib(it, false);
			}
		}
	}
	iterator insert2(iterator it, const value_type& x)
	{
		AN3D_ASSERT(end() == it || key_compare()(x, *it));
		AN3D_ASSERT(begin() == it || key_compare()(*(it-1), x));
		return vector_type::insert(it, x);
	}
	iterator erase(iterator it)
	{
		return vector_type::erase(it);
	}
	iterator erase(iterator first, iterator last)
	{
		return vector_type::erase(first, last);
	}
	size_type erase(const T& t)
	{
		std::pair<iterator, iterator> range = std::equal_range(vector_type::begin(), vector_type::end(), t, Pred());
		size_type count = std::distance(range.first, range.second);
		vector_type::erase(range.first, range.second);
		return count;
	}
	void clear()
	{
		vector_type::clear();
	}
	const_iterator find(const T& t) const
	{
		const_iterator it = std::lower_bound(vector_type::begin(), vector_type::end(), t, Pred());
		if(it != vector_type::end())
		{
			if(key_compare()(t, *it))
			{
				return vector_type::end();
			}
		}
		return it;
	}
	iterator find(const T& t)
	{
		iterator it = std::lower_bound(vector_type::begin(), vector_type::end(), t, Pred());
		if(it != vector_type::end())
		{
			if(key_compare()(t, *it))
			{
				return vector_type::end();
			}
		}
		return it;
	}
	size_type count(const T& t) const
	{
		std::pair<iterator, iterator> range = equal_range(vector_type::begin(), vector_type::end(), t, Pred());
		return std::distance(range.first, range.second);
	}
	const_iterator lower_bound(const T& t) const
	{
		return std::lower_bound(vector_type::begin(), vector_type::end(), t, Pred());
	}
	const_iterator upper_bound(const T& t) const
	{
		return std::upper_bound(vector_type::begin(), vector_type::end(), t, Pred());
	}
	_Paircc equal_range(const T& t) const
	{
		return std::equal_range(vector_type::begin(), vector_type::end(), t, Pred());
	}
	iterator lower_bound(const T& t)
	{
		return std::lower_bound(vector_type::begin(), vector_type::end(), t, Pred());
	}
	iterator upper_bound(const T& t)
	{
		return std::upper_bound(vector_type::begin(), vector_type::end(), t, Pred());
	}
	_Pairii equal_range(const T& t)
	{
		return std::equal_range(vector_type::begin(), vector_type::end(), t, Pred());
	}
};

END_PAFCORE
