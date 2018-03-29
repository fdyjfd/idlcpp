#import "Metadata.i"

#{
#include <unordered_set>
#}

namespace pafcore
{

	abstract class(name_space)#PAFCORE_EXPORT NameSpace : Metadata
	{
		size_t _getMemberCount_();
		Metadata* _getMember_(size_t index);
		Metadata* _findMember_(const char* name);
#{
	private:
		struct Hash_Metadata
		{
			size_t operator ()(const Metadata* metadata) const;
		};
		struct Equal_Metadata
		{
			bool operator() (const Metadata* lhs, const Metadata* rhs) const;
		};
	public:
		NameSpace(const char* name);
		~NameSpace();
	public:
		NameSpace* getNameSpace(const char* name);
		ErrorCode registerMember(Metadata* metadata);
		Metadata* findMember(const char* name);
		void unregisterMember(Metadata* metadata);
	public:	
		typedef std::unordered_set<Metadata*, Hash_Metadata, Equal_Metadata> MetadataContainer;
		MetadataContainer m_members;
		Metadata* m_enclosing;
	public:
		static NameSpace* GetGlobalNameSpace();
#}
	};

}