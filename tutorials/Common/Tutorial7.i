#import "Tutorial6.i"

namespace tutorial
{
	template<T>
	struct Ray3
	{
		Ray3();
		Ray3(const Vector3<T>& origin, const Vector3<T>& direction);
		void getPoint(Vector3<T>& point, T t) const;
		Vector3<T> getPoint(T t) const;
		Vector3<T> m_origin;
		Vector3<T> m_direction;
	};

	export Ray3<float>;
	export Ray3<double>;
	typedef Ray3<float> Ray3f;
	typedef Ray3<double> Ray3d;


#{

	template<typename T>
	inline Ray3<T>::Ray3()
	{}

	template<typename T>
	inline Ray3<T>::Ray3(const Vector3<T>& origin, const Vector3<T>& direction) :
		m_origin(origin), m_direction(direction)
	{}

	template<typename T>
	inline void Ray3<T>::getPoint(Vector3<T>& point, T t) const
	{
		point.x = m_origin.x + m_direction.x * t;
		point.y = m_origin.y + m_direction.y * t;
		point.z = m_origin.z + m_direction.z * t;
	}
	template<typename T>
	inline Vector3<T> Ray3<T>::getPoint(T t) const
	{
		return Vector3<T>(m_origin.x + m_direction.x * t,
			m_origin.y + m_direction.y * t,
			m_origin.z + m_direction.z * t);
	}

#}
}


