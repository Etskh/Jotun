#ifndef INCLUDED_MATRIX_H
#define INCLUDED_MATRIX_H

#include "Vector.h"

namespace core {

	struct Matrix4 {

		inline			Matrix4		( void );
		inline			Matrix4		( float* pa16 );
		inline			Matrix4		( const Matrix4& ref );

		inline void		Identity	( void );

		inline void		Translate	( const Vector3& delta );
		inline void		TranslateTo	( const Vector3& loc );
		inline void		Rotate		( const Vector3& delta );
		inline void		Scale		( const Vector3& delta );
		inline void		ScaleTo		( const Vector3& size );

		inline Matrix4&	operator*=	( const Matrix4& ref );

		float m[16];

		/*
		struct Data {
			Data(float* m);
			Data(Matrix4& ref);
			Data(Data& ref);

			union {
				struct {
					float&	m_1_1,	m_1_2,	m_1_3,	m_1_4,
							m_2_1,	m_2_2,	m_2_3,	m_2_4,
							m_3_1,	m_3_2,	m_3_3,	m_3_4,
							m_4_1,	m_4_2,	m_4_3,	m_4_4;
				};
				struct {
					float&	m_1,	m_2,	m_3,	m_4,
							m_5,	m_6,	m_7,	m_8,
							m_9,	m_10,	m_11,	m_12,
							m_13,	m_14,	m_15,	m_16;
				};
			};
		};

		Data*	GetData		(void);
		*/
	};

} // namespace core

#include "Matrix.inl"

#endif // INCLUDED_MATRIX_H
