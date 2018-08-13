
namespace tutorial
{
	struct Point
	{
		float x;
		float y;
		nocode Point();
		nocode void getX(float* f) const;
		nocode string_t test();
#{
		void getX(float* f) const
		{
			*f = x;
		}
		string_t test()
		{
			return "test";
		}
#}
	};

}
