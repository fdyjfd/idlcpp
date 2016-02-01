#import "Metadata.i"

$$#include "VectorSet.h"

namespace pafcore
{

	abstract class $PAFCORE_EXPORT NameSpace(name_space) : Metadata
	{
		size_t _getMemberCount_();
		Metadata ptr _getMember_(size_t index);
		Metadata ptr _findMember_(const char ptr name);
		$*
	private:
		class PAFCORE_EXPORT MetadataTrieTree
		{
		public:
			struct PAFCORE_EXPORT Node
			{
				size_t m_ptr;
				Node()
				{
					m_ptr = 0;
				}
				bool isNull()
				{
					return 0 == m_ptr;
				}
				bool isMetadata()
				{
					return ((m_ptr & 1) == 0);
				}
				Metadata* getMetadata()
				{
					return (Metadata*)m_ptr;
				}
				void setMetadata(Metadata* metadata)
				{
					m_ptr = (size_t)metadata;
				}
				Node* getChildren()
				{
					return (Node*)(m_ptr & ~size_t(1));
				}
				void setChildren(Node* node)
				{
					m_ptr = (size_t)node | 1;
				}
				bool insert(Metadata* metadata, int offset);
				Metadata* find(const char* name, int offset);
				static size_t GetIndex(char c);
			};
		public:
			Node m_root;
			size_t m_size;
			MetadataTrieTree()
			{
				m_size = 0;
			}
			Metadata* find(const char* name)
			{
				return m_root.find(name, 0);
			}
			bool insert(Metadata* metadata)
			{
				bool res = m_root.insert(metadata, 0);
				if(res)
				{
					++m_size;
				}
				return res;
			}
			size_t size()
			{
				return m_size;
			}
			Metadata* getItem(size_t index);
		};
	public:
		NameSpace(const char* name);
	public:
		NameSpace* getNameSpace(const char* name);
		ErrorCode registerMember(Metadata* metadata);
		Metadata* findMember(const char* name);
	public:
		typedef MetadataTrieTree MetadataContainer;
		MetadataContainer m_members;
	public:
		static NameSpace* GetGlobalNameSpace();
		*$
	};

}