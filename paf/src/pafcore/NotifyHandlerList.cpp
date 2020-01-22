#include "NotifyHandlerList.h"
#include "NotifyHandlerList.mh"
#include "NotifyHandlerList.ic"
#include "NotifyHandlerList.mc"

BEGIN_PAFCORE

NotifyHandlerLink::~NotifyHandlerLink()
{
}

NotifyHandlerLink* NotifyHandlerLink::New(NotifyHandler* first, NotifyHandler* second)
{
	return paf_new NotifyHandlerLink(first, second);
}

bool NotifyHandlerLink::find(NotifyHandler* p)
{
	PAF_ASSERT(!p->isStrictTypeOf<NotifyHandlerLink>());
	if (p == m_first || p == m_second)
	{
		return true;
	}
	if (m_first->isStrictTypeOf<NotifyHandlerLink>())
	{
		PAF_ASSERT(!m_second->isStrictTypeOf<NotifyHandlerLink>());
		return static_cast<NotifyHandlerLink*>(m_first)->find(p);
	}
	else if (m_second->isStrictTypeOf<NotifyHandlerLink>())
	{
		return static_cast<NotifyHandlerLink*>(m_second)->find(p);
	}
	return false;
}

NotifyHandler* NotifyHandlerLink::remove(NotifyHandler* p)
{
	NotifyHandler* res = static_cast<NotifyHandlerLink*>(this);
	if (p == m_first)
	{
		res = m_second;
		static_cast<NotifyHandlerLink*>(this)->release();
	}
	else if (p == m_second)
	{
		res = m_first;
		static_cast<NotifyHandlerLink*>(this)->release();
	}
	else if (m_first->isStrictTypeOf<NotifyHandlerLink>())
	{
		PAF_ASSERT(!m_second->isStrictTypeOf<NotifyHandlerLink>());
		m_first = static_cast<NotifyHandlerLink*>(m_first)->remove(p);
	}
	else
	{
		PAF_ASSERT(!m_second->isStrictTypeOf<NotifyHandlerLink>());
	}
	//else if (m_second->isStrictTypeOf<NotifyHandlerLink>())
	//{
	//	m_second = static_cast<NotifyHandlerLink*>(m_second)->remove(p);
	//}
	return res;
}

void NotifyHandlerLink::AddToList(NotifyHandler*& root, NotifyHandler* p)
{
	PAF_ASSERT(0 != p);
	PAF_ASSERT(!p->isTypeOf<NotifyHandlerLink>());
	if (0 != p)
	{
		if (0 == root)
		{
			root = p;
		}
		else
		{
			root = NotifyHandlerLink::New(root, p);
		}
	}
}

void NotifyHandlerLink::RemoveFromList(NotifyHandler*& root, NotifyHandler* p)
{
	PAF_ASSERT(0 != p);
	PAF_ASSERT(!p->isTypeOf<NotifyHandlerLink>());
	if (0 != p)
	{
		if (root == p)
		{
			root = 0;
		}
		else if (root->isStrictTypeOf<NotifyHandlerLink>())
		{
			root = static_cast<NotifyHandlerLink*>(root)->remove(p);
		}
	}
}

bool NotifyHandlerLink::FindInList(NotifyHandler* root, NotifyHandler* p)
{
	if (0 != p)
	{
		if (root == p)
		{
			return true;
		}
		if (root && root->isStrictTypeOf<NotifyHandlerLink>())
		{
			return static_cast<NotifyHandlerLink*>(root)->find(p);
		}
	}
	return false;
}

NotifyHandlerList::NotifyHandlerList() : m_notifyHandler(0)
{}

NotifyHandlerList::~NotifyHandlerList()
{
	//NotifyHandlerList 拥有 NotifyHandlerLink 引用计数，但不拥有 NotifyHandler 引用计数
	if (m_notifyHandler)
	{
		if (m_notifyHandler->isStrictTypeOf<NotifyHandlerLink>())
		{
			m_notifyHandler->release();
		}
	}
}

void NotifyHandlerList::addNotifyHandler(NotifyHandler* handler) const
{
	if (!NotifyHandlerLink::FindInList(m_notifyHandler, handler))
	{
		NotifyHandlerLink::AddToList(m_notifyHandler, handler);
	}
}

void NotifyHandlerList::removeNotifyHandler(NotifyHandler* handler) const
{
	if (NotifyHandlerLink::FindInList(m_notifyHandler, handler))
	{
		pafcore::NotifyHandlerLink::RemoveFromList(m_notifyHandler, handler);
	}
}

bool NotifyHandlerList::findNotifyHandler(NotifyHandler* handler) const
{
	return NotifyHandlerLink::FindInList(m_notifyHandler, handler);
}

void PropertyChangedNotifySource::notifyPropertyChanged(string_t propertyName, PropertyChangedFlag flag, Iterator* iterator)
{
	if (m_notifyHandlerList.m_notifyHandler)
	{
		NotifyHandlerLink::TransmitNotify<PropertyChangedNotifyHandler>(m_notifyHandlerList.m_notifyHandler, this, propertyName, flag, iterator, &PropertyChangedNotifyHandler::onPropertyChanged);
	}
}

void PropertyChangedNotifySource::nodifyPropertyAvailabilityChanged(string_t propertyName)
{
	if (m_notifyHandlerList.m_notifyHandler)
	{
		NotifyHandlerLink::TransmitNotify<PropertyChangedNotifyHandler>(m_notifyHandlerList.m_notifyHandler, this, propertyName, &PropertyChangedNotifyHandler::onPropertyAvailabilityChanged);
	}
}

void PropertyChangedNotifySource::notifyDynamicPropertyChanged(string_t propertyName, PropertyChangedFlag flag, Iterator* iterator)
{
	if (m_notifyHandlerList.m_notifyHandler)
	{
		NotifyHandlerLink::TransmitNotify<PropertyChangedNotifyHandler>(m_notifyHandlerList.m_notifyHandler, this, propertyName, flag, iterator, &PropertyChangedNotifyHandler::onDynamicPropertyChanged);
	}
}

void PropertyChangedNotifySource::notifyUpdateDynamicProperty()
{
	if (m_notifyHandlerList.m_notifyHandler)
	{
		NotifyHandlerLink::TransmitNotify<PropertyChangedNotifyHandler>(m_notifyHandlerList.m_notifyHandler, this, &PropertyChangedNotifyHandler::onUpdateDynamicProperty);
	}
}


END_PAFCORE
