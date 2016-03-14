
namespace tutorial
{
	template<typename N>
	struct Vector3
	{
		Vector3();
		Vector3(const Vector3 ref v);
		Vector3(N a, N b, N c);
		N getLength();
		N length get;
		N lengthSquare get;

		static Vector3 s_zero;
		static Vector3 s_unitX;
		static Vector3 s_unitY;
		static Vector3 s_unitZ;
		meta:
		N x;
		N y;
		N z;
		N v[$3];

		$*
		union
		{
			struct
			{
				N x,y,z;
			};
			N v[3];
		};
		*$
	};

	template class Vector3<float>;
	template class Vector3<double>;
	typedef Vector3<float> Vector3f;
	typedef Vector3<double> Vector3d;


	template<typename T>
	struct Ray3
	{
		Ray3();
		Ray3(const Vector3<T> ref origin, const Vector3<T> ref direction);
		void getPoint(Vector3<T> ref point, T t) const;
		Vector3<T> getPoint(T t) const;
		Vector3<T> m_origin;
		Vector3<T> m_direction;
	};

	template struct Ray3<float>;
	template struct Ray3<double>;
	typedef Ray3<float> Ray3f;
	typedef Ray3<double> Ray3d;


	$*

	template<typename N>
	Vector3<N> Vector3<N>::s_zero(0, 0, 0);

	template<typename N>
	Vector3<N> Vector3<N>::s_unitX(1, 0, 0);

	template<typename N>
	Vector3<N> Vector3<N>::s_unitY(0, 1, 0);

	template<typename N>
	Vector3<N> Vector3<N>::s_unitZ(0, 0, 1);

	template<typename N>
	inline Vector3<N>::Vector3()
	{
	}

	template<typename N>
	inline Vector3<N>::Vector3(N a, N b, N c) : x(a), y(b), z(c)
	{}

	template<typename N>
	inline Vector3<N>::Vector3(const Vector3<N>& v) : x(v.x), y(v.y), z(v.z)
	{}

	template<typename N>
	inline N Vector3<N>::getLength()
	{
		return N(sqrt(x * x + y * y + z * z));
	}

	template<typename N>
	inline N Vector3<N>::get_length()
	{
		return N(sqrt(x * x + y * y + z * z));
	}

	template<typename N>
	inline N Vector3<N>::get_lengthSquare()
	{
		return (x * x + y * y + z * z);
	}

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

	*$
}


