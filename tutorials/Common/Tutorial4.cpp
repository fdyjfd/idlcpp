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
	

	float Triangle::getArea()
	{
		return fabs(m_vertices[0].x * m_vertices[1].y + m_vertices[1].x * m_vertices[2].y + m_vertices[2].x * m_vertices[0].y
			- m_vertices[0].x * m_vertices[2].y - m_vertices[1].x * m_vertices[0].y - m_vertices[2].x * m_vertices[1].y) * 0.5;
	}

}