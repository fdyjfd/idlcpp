
namespace tutorial
{
	template<typename N>
	struct Vector3
	{
		Vector3();
		Vector3(const Vector3 ref v);
		Vector3(N a, N b, N c);
		Vector3(const N ptr p);
		N getLength();
		N length get;
		N lengthSquare get;

		static Vector3 s_zero;
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
	inline Vector3<N>::Vector3()
	{
	}

	template<typename N>
	inline Vector3<N>::Vector3(const Vector3<N>& v) : x(v.x), y(v.y), z(v.z)
	{}

	template<typename N>
	inline Vector3<N>::Vector3(N a, N b, N c) : x(a), y(b), z(c)
	{}

	template<typename N>
	inline Vector3<N>::Vector3(const N* p) : x(p[0]), y(p[1]), z(p[2])
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


