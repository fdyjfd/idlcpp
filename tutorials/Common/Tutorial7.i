#import "../../paf/src/pafcore/Delegate.i"

#{
#include <map>
#}

namespace tutorial
{
	class Test : Reference
	{
		//int fap[ ] get set;
		//int dap[?] get set;
		nocode Test();
		int mp[string_t] get set;
#{
		std::map<std::string, int> m_test;
#}
	};

	class Button : Reference
	{
		nocode Button();
		EventHandler click;
		void raiseClick();
	};

#{
	inline void Button::raiseClick()
	{
		click.invoke(this);
	}
#}
}


