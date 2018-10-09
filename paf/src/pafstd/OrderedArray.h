#pragma once

#include "Utility.h"
#include <vector>
#include <algorithm>

BEGIN_PAFSTD

template<typename T, class Pred = std::less<T>, class A = std::allocator<T> >
class PAFSTD_TEMPLATE OrderedArray : private std::vector<T, A>
{
public:
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
public:
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
	iterator insert(const value_type& x)
	{
		typename vector_type::iterator it = std::lower_bound(vector_type::begin(), vector_type::end(), x, Pred());
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
		typename vector_type::iterator first = std::lower_bound(vector_type::begin(), vector_type::end(), t, Pred());
		typename vector_type::iterator last = std::upper_bound(vector_type::begin(), vector_type::end(), t, Pred());
		size_type count = distance(first, last);
		vector_type::erase(first, last);
		return count;
	}
	void clear()
	{
		vector_type::clear();
	}
	const_iterator find(const T& t) const
	{
		return std::lower_bound(vector_type::begin(), vector_type::end(), t, Pred());
	}
	iterator find(const T& t)
	{
		return std::lower_bound(vector_type::begin(), vector_type::end(), t, Pred());
	}
	size_type count(const T& t) const
	{
		typename vector_type::iterator first = std::lower_bound(vector_type::begin(), vector_type::end(), t, Pred());
		typename vector_type::iterator last = std::upper_bound(vector_type::begin(), vector_type::end(), t, Pred());
		return distance(first, last);
	}
    const_iterator lower_bound(const T& t) const
	{
		return std::lower_bound(vector_type::begin(), vector_type::end(), t, Pred());
	}
	const_iterator upper_bound(const T& t) const
	{
		return std::upper_bound(vector_type::begin(), vector_type::end(), t, Pred());
	}
    iterator lower_bound(const T& t)
	{
		return std::lower_bound(vector_type::begin(), vector_type::end(), t, Pred());
	}
	iterator upper_bound(const T& t)
	{
		return std::upper_bound(vector_type::begin(), vector_type::end(), t, Pred());
	}
};	

END_PAFSTD
