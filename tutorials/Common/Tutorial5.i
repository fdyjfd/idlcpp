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
		nocode Point(const Point ref pt);
	};

	override class Shape : Reference
	{
		override abstract float getArea();
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
		nocode Triangle();
		$$virtual float getArea();
	};

}
