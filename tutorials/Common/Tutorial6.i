
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
	*$
}


