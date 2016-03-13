#import "../../paf/src/pafcore/Reference.i"
$$#include <vector>

namespace tutorial
{
	struct Point
	{
		float x;
		float y;
		Point();
		Point(float a, float b);
	meta:
		Point(const Point ref pt);
	};

	class Shape : Reference
	{
		abstract float getArea();
		$$		virtual ~Shape() {}
	};

	class ShapeManager(value_object)
	{
		void addShape(Shape ptr shape);
		float getTotalArea();
		static ShapeManager ptr GetInstance();
		$*
		~ShapeManager();
	private:
		std::vector<Shape*> m_shapes;
		*$
	};


	class Rectangle : Shape
	{

		Rectangle(const Point ref min, const Point ref max);
		Rectangle();
	meta:
		Rectangle(const Rectangle ref pt);
	native:
		virtual float getArea();
	all:
		float left set get;
		float right set get;
		float bottom set get;
		float top set get;
		float area get;	
		Point m_min;
		Point m_max;
	};


	class Triangle : Shape
	{
		Point m_vertices[$3];
	meta:
		Triangle();
		$$virtual float getArea();
	};

}
