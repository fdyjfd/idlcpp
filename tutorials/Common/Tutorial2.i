
namespace tutorial
{
	struct Point
	{
		float x;
		float y;
		meta Point();
		meta Point(float a, float b);
		$*
		Point()
		{}
		Point(float a, float b)
		{
			x = a;
			y = b;
		}
		*$
	};

	struct Rectangle
	{
		Point m_min;
		Point m_max;

		float left set get;
		float right set get;

		meta float bottom set get;
		meta float top set get;
		meta float area get;
		meta float getArea();

		Rectangle(const Point ref min, const Point ref max);
		Rectangle();
		meta Rectangle(const Rectangle ref pt);
		$*
		void set_bottom(float bottom)
		{
			m_min.y = bottom;
		}
		float get_bottom()
		{
			return m_min.y;
		}
		void set_top(float top)
		{
			m_max.y = top;
		}
		float get_top()
		{
			return m_max.y;
		}
		float get_area()
		{
			return (m_max.x - m_min.x)*(m_max.y - m_min.y);
		}
		float getArea()
		{
			return (m_max.x - m_min.x)*(m_max.y - m_min.y);
		}
		*$
	};
	$*
	inline Rectangle::Rectangle(const Point& min, const Point& max) : m_min(min), m_max(max)
	{
	}
	inline Rectangle::Rectangle()
	{}
	inline float Rectangle::get_left()
	{
		return m_min.x;
	}
	inline void Rectangle::set_left(float left)
	{
		m_min.x = left;
	}
	inline float Rectangle::get_right()
	{
		return m_max.x;
	}
	inline void Rectangle::set_right(float right)
	{
		m_max.x = right;
	}
	*$
}
