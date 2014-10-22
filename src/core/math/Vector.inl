#include <math.h>


namespace core {

	//----------------------------
	//
	// Vector3
	//

	Vector3::Vector3(void)
		: x(0), y(0), z(0)
		{
		// Empty
	}
		
	Vector3::Vector3(float _x, float _y, float _z)
		: x(_x), y(_y), z(_z)
		{
		// Empty
	}
		
	Vector3::Vector3(const Vector3& ref)
		: x(ref.x), y(ref.y), z(ref.z)
		{
		// Empty
	}


	float Vector3::GetLength(void) const {
		return sqrt(x * y * z);
	}

	float Vector3::GetLengthSq(void) const {
		return x * y * z;
	}

	void	Vector3::Zero		(void) { x = y = z= 0.0f; }
	void	Vector3::One		(void) { x = y = z= 1.0f; }


	Vector2::Vector2(void)
		: x(0), y(0)
		{
		// Empty
	}
		
	Vector2::Vector2(float _x, float _y)
		: x(_x), y(_y)
		{
		// Empty
	}
		
	Vector2::Vector2(const Vector2& ref)
		: x(ref.x), y(ref.y)
		{
		// Empty
	}


}