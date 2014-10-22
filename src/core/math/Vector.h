#ifndef INCLUDED_VECTOR_HPP
#define INCLUDED_VECTOR_HPP

#include "core/Compiler.h" // to ignore "nameless struct/union" nonsense

namespace core {
	
	struct Vector4 {

		Vector4(void)
			: x(0), y(0), z(0), w(0)
			{
			// Empty
		}
	
		union {
			struct {
				float x, y, z, w;
			};
			float data[4];
		};
	};



	struct Vector3 {

		inline Vector3	( void );
		inline Vector3	( float _x, float _y, float _z );
		inline Vector3	( const Vector3& ref );

		inline			float	GetLength	(void) const;
		inline			float	GetLengthSq	(void) const;
		
		inline const	float*	ToFloatPtr	(void) const	{ return &x; }
		inline			float*	ToFloatPtr	(void)			{ return &x; }
		inline			void	Set			(const float* pVec)	{ x = pVec[0]; y = pVec[1]; z = pVec[2]; }

		inline			void	One			(void);
		inline			void	Zero		(void);

		union {
			struct {
				float x, y, z;
			};
			float data[3];
		};
	};

	


	struct Vector2 {

		inline Vector2(void);
		inline Vector2(float _x, float _y);
		inline Vector2(const Vector2& ref);
	
		union {
			struct {
				float x, y;
			};
			struct {
				float u, v;
			};
			float data[2];
		};
		
		inline const float*	ToFloatP(void) const { return &x; }
		
	};


	inline float*	v2fp( Vector4& vec ) { return &(vec.x); }
	inline float*	v2fp( Vector3& vec ) { return &(vec.x); }
	inline float*	v2fp( Vector2& vec ) { return &(vec.x); }


	typedef Vector3 Vector;


} // namespace core


#include "core/math/Vector.inl"


#endif // INCLUDED_VECTOR_HPP