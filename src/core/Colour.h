#ifndef __INCLUDED_JOTUN_Colour_h
#define __INCLUDED_JOTUN_Colour_h


#include "core/Patterns.h"
#include "core/Compiler.h"

namespace core {

struct Colour
{
					Colour			( void );
					Colour			( const Colour& ref );
					Colour			( const float* rgbColours );
					Colour			( uint argb );
					Colour			( uchar _r, uchar _g, uchar _b );
					Colour			( uchar _r, uchar _g, uchar _b, uchar _a );
					Colour			( uint _r, uint _g, uint _b );
					Colour			( uint _r, uint _g, uint _b, uint _a );
					Colour			( float _r, float _g, float _b );
					Colour			( float _r, float _g, float _b, float _a );

	const float*	GetFloatPtr		(void) const;


	uchar			red8			(void) const;
	uchar			green8			(void) const;
	uchar			blue8			(void) const;
	uchar			alpha8			(void) const;


	uint			ToUInt32		(void) const;
	uint			ToUInt32_argb	(void) const;

	//
	// Colours that you might need
	//
	static const Colour	White;
	static const Colour	Black;
	static const Colour	Green;
	static const Colour	Yellow;
	static const Colour	Red;

	static const Colour	SkyBlue;
	static const Colour	SlateGrey;

	union {
		struct {
			float r;
			float g;
			float b;
			float a;
		};
		float data[4];
	};
};


// For the Amuricuns
typedef Colour Color;



} // namespace core

#endif // __INCLUDED_JOTUN_Colour_h
