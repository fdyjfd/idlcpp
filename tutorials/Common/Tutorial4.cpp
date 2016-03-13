#include "Tutorial4.h"
#include "Tutorial4.mh"
#include "Tutorial4.ic"
#include "Tutorial4.mc"


namespace tutorial
{

	Point::Point()
	{}

	Point::Point(float a, float b)
	{
		x = a;
		y = b;
	}
	
	ShapeManager* ShapeManager::GetInstance()
	{
		static ShapeManager s_instance;
		return &s_instance;
	}
	ShapeManager::~ShapeManager()
	{
		auto it = m_shapes.begin();
		auto end = m_shapes.end();
		for (; it != end; ++it)
		{
			Shape* shape = (*it);
			shape->release();
		}
	}
	void ShapeManager::addShape(Shape* shape)
	{
		shape->addRef();
		m_shapes.push_back(shape);
	}

	float ShapeManager::getTotalArea()
	{
		float area = 0;
		auto it = m_shapes.begin();
		auto end = m_shapes.end();
		for (; it != end; ++it)
		{
			Shape* shape = (*it);
			area += shape->getArea();
		}
		return area;
	}

	Rectangle::Rectangle()
	{}
	Rectangle::Rectangle(const Point& min, const Point& max) : m_min(min), m_max(max)
	{}

	void Rectangle::set_bottom(float bottom)
	{
		m_min.y = bottom;
	}
	float Rectangle::get_bottom()
	{
		return m_min.y;
	}
	void Rectangle::set_top(float top)
	{
		m_max.y = top;
	}
	float Rectangle::get_top()
	{
		return m_max.y;
	}
	float Rectangle::get_area()
	{
		return (m_max.x - m_min.x)*(m_max.y - m_min.y);
	}
	
	float Rectangle::getArea()
	{
		return (m_max.x - m_min.x)*(m_max.y - m_min.y);
	}
	
	float Rectangle::get_left()
	{
		return m_min.x;
	}
	void Rectangle::set_left(float left)
	{
		m_min.x = left;
	}
	float Rectangle::get_right()
	{
		return m_max.x;
	}
	void Rectangle::set_right(float right)
	{
		m_max.x = right;
	}
	float Triangle::getArea()
	{
		return fabs(m_vertices[0].x * m_vertices[1].y + m_vertices[1].x * m_vertices[2].y + m_vertices[2].x * m_vertices[0].y
			- m_vertices[0].x * m_vertices[2].y - m_vertices[1].x * m_vertices[0].y - m_vertices[2].x * m_vertices[1].y) * 0.5;
	}

}