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


	class Triangle : Shape
	{
		Point m_vertices[$3];
	meta:
		Triangle();
$$		virtual float getArea();
	};

}
