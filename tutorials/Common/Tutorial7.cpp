#include "Tutorial7.h"
#include "Tutorial7.mh"
#include "Tutorial7.mc"
#include "Tutorial7.ic"

namespace tutorial
{
	typedef pafcore::IteratorImpl<std::map<std::string, int>> TestIterator;

	//int Test::get_mp(string_t str) const
	//{
	//	auto it = m_test.find(str.c_str());
	//	if (m_test.end() != it)
	//	{
	//		return it->second;
	//	}
	//	return 0;
	//}

	//void Test::set_mp(string_t str, int value)
	//{
	//	m_test[std::string(str)] = value;
	//}

	//::pafcore::Iterator* Test::getIterator_mp()
	//{
	//	return paf_new TestIterator(&m_test);
	//}
	//
	//string_t Test::getKey_mp(::pafcore::Iterator* iterator)
	//{
	//	TestIterator* it = static_cast<TestIterator*>(iterator);
	//	if (it->getContainer() == &m_test)
	//	{
	//		if (it->getIterator() != m_test.end())
	//		{
	//			return it->getIterator()->first.c_str();
	//		}
	//	}
	//	return "";
	//}

	//int Test::getValue_mp(::pafcore::Iterator* iterator)
	//{
	//	TestIterator* it = static_cast<TestIterator*>(iterator);
	//	if (it->getContainer() == &m_test)
	//	{
	//		if (it->getIterator() != m_test.end())
	//		{
	//			return it->getIterator()->second;
	//		}
	//	}
	//	return 0;
	//}

}