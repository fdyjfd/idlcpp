#import "../../paf/src/pafcore/Delegate.i"

#{
#include <map>
#}

namespace tutorial
{
	struct AA
	{
		int a;
	};

	class Test
	{
		int* m_a;
	public:
		void useIntPtr(int* p)
		{
			*m_a = *p;
		}
		void setIntPtr(int* p)
		{
			m_a = p;
		}
		void deleteIntPtr(int* p)
		{
			delete p;
		}
	};

	class Test : Reference
	{
		static AA* abc{ get+ set - };
		//void test0(AA a);
		void test1(AA& a);
		void test2(AA* a);
		void test3(AA- a);
		void test4(AA** a);
		void test5(AA*& a);
		void test6(AA + *a);
		void test7(AA + &a);
		void test8(AA + [] *a);
		void test9(AA + [] &a);
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


