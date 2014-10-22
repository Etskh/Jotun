#ifndef INCLUDED_JOTUN_Metrics_H
#define INCLUDED_JOTUN_Metrics_H

namespace core {


	struct Metrics2D {
		
		inline Metrics2D		( void );
		inline Metrics2D		( const Metrics2D& ref );
		inline Metrics2D		( float _x, float _y );
		inline Metrics2D		( float _x, float _y, float _w, float _h);
		
		float x, y;
		float width, height;

		
		inline float	GetSize	(void)	const	{ return width*height;}
		inline float	Top		(void)	const	{ return y; }
		inline float	Left	(void)	const	{ return x; }
		inline float	Bottom	(void)	const	{ return height + y; }
		inline float	Right	(void)	const	{ return width + x; }
		
		
		inline void	 Set	(const Metrics2D& ref) {
			x = ref.x; y = ref.y; width = ref.width; height = ref.height;
		}
		inline void  Set	( float _x, float _y, float _width, float _height ) {
			x = _x; y = _y; width = _width; height = _height;
		}
	};

	
	Metrics2D::Metrics2D	( void )
		: x(0)
		, y(0)
		, width(0)
		, height(0)
	{
		// empty
	}
	
	Metrics2D::Metrics2D	( const Metrics2D& ref )
		: x(ref.x)
		, y(ref.y)
		, width(ref.width)
		, height(ref.height)
	{
		// empty
	}
	
	Metrics2D::Metrics2D	( float _x, float _y )
		: x(_x)
		, y(_y)
		, width(0)
		, height(0)
	{
		// empty
	}
	Metrics2D::Metrics2D	( float _x, float _y, float _w, float _h)
		: x(_x)
		, y(_y)
		, width(_w)
		, height(_h)
	{
		// empty
	}

} // namespace core

#endif // INCLUDED_JOTUN_Metrics_H