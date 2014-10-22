
#include <memory.h>
#include "core/Assert.h"

namespace core {

	//----------------------------
	//
	// Matrix
	//

	Matrix4::Matrix4(void) {
		memset(m,0,sizeof(m));
	}
	Matrix4::Matrix4(float* pa16) {
		memcpy(m,pa16, sizeof(m));
	}
	Matrix4::Matrix4(const Matrix4& ref) {
		memcpy(m,ref.m,sizeof(m));
	}

	void		Matrix4::Identity	( void ) {
		memset(m,0,sizeof(m));
		m[0] = m[5] = m[10] = m[15] = 1.0f;
	}

	void		Matrix4::Translate	( const Vector3& delta) {
		m[4] += delta.x;
		m[8] += delta.y;
		m[12]+= delta.z;
	}
	void		Matrix4::TranslateTo( const Vector3& loc) {
		m[4] = loc.x;
		m[8] = loc.y;
		m[12]= loc.z;
	}

	void		Matrix4::Rotate		( const Vector3&) {
		ASSERT(false);
	}
	void		Matrix4::Scale		( const Vector3& delta) {
		m[0] *= delta.x;
		m[5] *= delta.y;
		m[10]*= delta.z;
	}
	void		Matrix4::ScaleTo	( const Vector3& size) {
		m[0] = size.x;
		m[5] = size.y;
		m[10]= size.z;
	}



	Matrix4&	Matrix4::operator*=	(const Matrix4& ref) {
		for(uint d=0; d<16; d++) {
			m[d]*=ref.m[d];
		}
		return *this;
	}

}