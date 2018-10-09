#import "Reference.i"
#import "../stdport/string_port.i"
#import "Blob.i"

#{
#include "Utility.h"
#include "../../../../thirdparty/rapidxml-1.13/rapidxml.hpp"
#}

#{
namespace pafcore
{
	class Type;
	class Reference;
	class Variant;
}

namespace pugi
{
	class xml_node;
}

namespace rapidxml
{
	template<class Ch> class xml_document;
	template<class Ch> class xml_node;
	template<class Ch> class xml_attribute;
}

#}

namespace pafstd
{

#{
	typedef rapidxml::xml_document<char> xml_document;
	typedef rapidxml::xml_node<char> xml_node;
	typedef rapidxml::xml_attribute<char> xml_attribute;
#}

	class(value_object) #PAFSTD_EXPORT XmlSerializer
	{
#{
	public:
		static xml_node* Serialize(pafcore::Reference* reference, const char* name, xml_document& doc);
		static xml_node* Serialize(void* object, pafcore::Type* type, const char* name, xml_document& doc);

		static void Unserialize(pafcore::Reference* reference, xml_node* node);
		static void Unserialize(void* object, pafcore::Type* type, xml_node* xmlNode);
		static void Unserialize(pafcore::Variant& object, xml_node* xmlNode, pafcore::Type* type = 0);
#}
	};
}

