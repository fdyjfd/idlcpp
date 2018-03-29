#import "../../paf/src/pafcore/Delegate.i"

namespace tutorial
{
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


