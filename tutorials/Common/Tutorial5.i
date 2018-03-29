#import "../../paf/src/pafcore/Reference.i"
###include <vector>

namespace tutorial
{
	struct Point
	{
		float x;
		float y;
		Point();
		Point(float a, float b);
		nocode Point(const Point& pt);
	};

	override class Shape : Reference
	{
		override abstract void getArea2(float* area);
		##		virtual ~Shape() {}
	};

	class(value_object)ShapeManager
	{
		void addShape(Shape* shape);
		float getTotalArea();
		static ShapeManager* GetInstance();
#{
		~ShapeManager();
	private:
		std::vector<Shape*> m_shapes;
#}
	};


	class Triangle : Shape
	{
		Point m_vertices[#3];
		nocode Triangle();
		##virtual float getArea();
		##virtual void getArea2(float* area);

	};

}
