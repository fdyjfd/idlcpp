#include "NameSpace.h"
#include "Metadata.h"
#include "Type.h"
#include <vector>
#include <assert.h>
#include "TypeAlias.mh"
#include "NameSpace.mh"
#include "NameSpace.ic"
#include "NameSpace.mc"

BEGIN_PAFCORE

NameSpace::MetadataTrieTree::Node::~Node()
{
	if (!isNull())
	{
		if (isMetadata())
		{
			Metadata* metadata = getMetadata();
			if (name_space == metadata->get__category_())
			{
				NameSpace* nameSpace = static_cast<NameSpace*>(metadata);
				delete nameSpace;
			}
		}
		else
		{
			Node* node = getChildren();
			delete[] node;
		}
	}

}

const size_t num_metadata_name_char = 68;

size_t NameSpace::MetadataTrieTree::Node::GetIndex(char c)
{
	assert('\0' == c || ' ' == c || ':' == c || '<' == c || '>' == c || '_' == c
		|| '0' <= c && c <= '9' || 'A' <= c && c <= 'Z' || 'a' <= c && c <= 'z');
	switch(c)
	{
	case '\0':
		return 0;
	case ' ':
		return 1;
	case ':':
		return 2;
	case '<':
		return 3;
	case '>':
		return 4;
	case '_':
		return 5;
 	}
	if(c <= '9')
	{
		return c - '0' + 6;
	}
	if(c <= 'Z')
	{
		return c - 'A' + 16;
	}
	return c - 'a' + 42;
}

bool NameSpace::MetadataTrieTree::Node::insert(Metadata* metadata, int offset)
{
	assert(0 == ((size_t)metadata & 1));
	if(isNull())
	{
		setMetadata(metadata);
		return true;
	}
	else if(isMetadata())
	{
		Metadata* currentMetadata = getMetadata();
		Node* children = paf_new Node[num_metadata_name_char];
		assert(0 == ((size_t)children & 1));
		setChildren(children);
		size_t currentIndex = GetIndex(currentMetadata->m_name[offset]);
		children[currentIndex].setMetadata(currentMetadata);
		size_t index = GetIndex(metadata->m_name[offset]);
		if(0 == currentIndex && 0 == index)
		{
			return false;
		}
		else
		{
			return children[index].insert(metadata, offset + 1);
		}
	}
	else
	{
		Node* children = getChildren();
		size_t index = GetIndex(metadata->m_name[offset]);
		return children[index].insert(metadata, offset + 1);
	}
}

Metadata* NameSpace::MetadataTrieTree::Node::find(const char* name, int offset)
{
	if(isNull())
	{
		return 0;
	}
	else if(isMetadata())
	{
		Metadata* metadata = getMetadata();
		if(0 == strcmp(metadata->m_name + offset, name + offset))
		{
			assert(0 == strcmp(metadata->m_name, name));
			return metadata;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		size_t index = GetIndex(name[offset]);
		Node* children = getChildren();
		if(0 == index)
		{
			if(!children[index].isNull())
			{
				assert(children[index].isMetadata());
				Metadata* metadata = children[index].getMetadata();
				assert(0 == strcmp(metadata->m_name, name));
				return metadata;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return children[index].find(name, offset + 1);
		}
	}
}

Metadata* NameSpace::MetadataTrieTree::getItem(size_t index)
{
	if(index < m_size)
	{
		std::vector<Node> nodes;
		nodes.push_back(m_root);	
		while(!nodes.empty())
		{
			Node node = nodes.back();
			nodes.pop_back();
			if(!node.isNull())
			{
				if(node.isMetadata())
				{
					if(0 == index)
					{
						return node.getMetadata();
					}
					else
					{
						--index;
					}
				}
				else
				{
					Node* children = node.getChildren();
					for(size_t i = 0; i < num_metadata_name_char; ++i)
					{
						Node child = children[num_metadata_name_char - 1 - i];
						if(!child.isNull())
						{
							nodes.push_back(child);
						}
					}
				}
			}
		}
	}
	return 0;
}

NameSpace::NameSpace(const char* name)
	: Metadata(name)
{}


NameSpace* NameSpace::getNameSpace(const char* name)
{
	NameSpace* subNameSpace = 0;
	if(0 != this)
	{
		Metadata* member = m_members.find(name);
		if(0 == member)
		{
			subNameSpace = paf_new NameSpace(name);
			m_members.insert(subNameSpace);
		}
		else
		{
			if(name_space == member->get__category_())
			{
				subNameSpace = static_cast<NameSpace*>(member);
			}
		}
	}
	return subNameSpace;
}

ErrorCode NameSpace::registerMember(Metadata* member)
{
	if(0 == this)
	{
		return e_invalid_namespace;
	}
	return m_members.insert(member) ? s_ok : e_name_conflict;
}


Metadata* NameSpace::_findMember_(const char* name)
{
	return m_members.find(name);
}

size_t NameSpace::_getMemberCount_()
{
	return m_members.size();
}

Metadata* NameSpace::_getMember_(size_t index)
{
	return m_members.getItem(index);
}

Metadata* NameSpace::findMember(const char * name)
{
	Metadata* member = m_members.find(name);
	if(0 != member)
	{
		if(member->get__category_() == type_alias)
		{
			member = static_cast<TypeAlias*>(member)->m_type;
		}
	}
	return member;
}

NameSpace* NameSpace::GetGlobalNameSpace()
{
	static NameSpace s_globalNameSpace("");
	return &s_globalNameSpace;
}

END_PAFCORE
