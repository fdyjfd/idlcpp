
namespace tutorial
{
	struct Point
	{
		float x;
		float y;
		nocode Point();
		nocode void getX(float* f) const;
#{
		void getX(float* f) const
		{
			*f = x;
		}
#}
	};

}
