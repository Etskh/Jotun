
#include "Colour.h"

#include "core/Assert.h"



union ColourConverter {
	uint	u32;
	struct colours {
		uchar	r;
		uchar	g;
		uchar	b;
		uchar	a;
	};
	uchar data[4];
};



core::Colour::Colour ( void )
	: r( 0.0f )
	, g( 0.0f )
	, b( 0.0f )
	, a( 0.0f )
{
	// empty
}


core::Colour::Colour ( const Colour& ref )
	: r( ref.r)
	, g( ref.g)
	, b( ref.b)
	, a( ref.a)
{
	// empty
}


core::Colour::Colour ( const float* rgbColours )
	: r( rgbColours[0] )
	, g( rgbColours[1] )
	, b( rgbColours[2] )
	, a( 0.0f )
{
	ASSERT( rgbColours != 0 );
}


//
// Where	0xCC9944 = 0x00CC9944
//
core::Colour::Colour ( uint argb )
	: r( 0.0f )
	, g( 0.0f )
	, b( 0.0f )
	, a( 0.0f )
{
	ColourConverter cc;
	cc.u32 = argb;

	a = ((float)cc.data[3]) / 255.0f ;
	r = ((float)cc.data[2]) / 255.0f ;
	g = ((float)cc.data[1]) / 255.0f ;
	b = ((float)cc.data[0]) / 255.0f ;
}



core::Colour::Colour ( uint _r, uint _g, uint _b )
	: r( ((float)_r) / 255.0f )
	, g( ((float)_g) / 255.0f )
	, b( ((float)_b) / 255.0f )
	, a( 0.0f )
{
	// empty
}



core::Colour::Colour ( uint _r, uint _g, uint _b, uint _a )
	: r( ((float)_r) / 255.0f )
	, g( ((float)_g) / 255.0f )
	, b( ((float)_b) / 255.0f )
	, a( ((float)_a) / 255.0f )
{
	// empty
}



core::Colour::Colour ( uchar _r, uchar _g, uchar _b )
	: r( ((float)_r) / 255.0f )
	, g( ((float)_g) / 255.0f )
	, b( ((float)_b) / 255.0f )
	, a( 0.0f )
{
	// empty
}



core::Colour::Colour ( uchar _r, uchar _g, uchar _b, uchar _a )
	: r( ((float)_r) / 255.0f )
	, g( ((float)_g) / 255.0f )
	, b( ((float)_b) / 255.0f )
	, a( ((float)_a) / 255.0f )
{
	// empty
}



core::Colour::Colour ( float _r, float _g, float _b )
	: r ( _r )
	, g ( _g )
	, b ( _b )
	, a ( 0.0f )
{
	// empty
}




core::Colour::Colour ( float _r, float _g, float _b, float _a )
	: r ( _r )
	, g ( _g )
	, b ( _b )
	, a ( _a )
{
	// empty
}


const float*	core::Colour::GetFloatPtr(void) const
{
	return data;
}





uchar	core::Colour::red8			(void) const
{
	return (unsigned char)(r*255.0f);
}

uchar	core::Colour::green8			(void) const
{
	return (unsigned char)(g*255.0f);
}

uchar	core::Colour::blue8			(void) const
{
	return (unsigned char)(b*255.0f);
}

uchar	core::Colour::alpha8			(void) const
{
	return (unsigned char)(a*255.0f);
}



uint		core::Colour::ToUInt32(void) const
{
	ColourConverter cc;
	cc.u32 = 0;
	for(int i=0; i<4; i++) {
		cc.data[i] = (unsigned char)(data[i]*255.0f);
	}
	return cc.u32;
}



uint		core::Colour::ToUInt32_argb(void) const
{
	ColourConverter cc;
	cc.data[3] = (unsigned char)(a*255.0f);
	cc.data[2] = (unsigned char)(r*255.0f);
	cc.data[1] = (unsigned char)(g*255.0f);
	cc.data[0] = (unsigned char)(b*255.0f);
	return cc.u32;
}




const core::Colour core::Colour::White	= core::Colour( 1U,1U,1U, 1U);
const core::Colour core::Colour::Black	= core::Colour( 0U, 0, 0, 1U);
const core::Colour core::Colour::Green	= core::Colour( 0, 1U, 0, 1U);
const core::Colour core::Colour::Yellow	= core::Colour( 1U,1U, 0, 1U);
const core::Colour core::Colour::Red	= core::Colour( 1U, 0, 0, 1U);

const core::Colour core::Colour::SkyBlue= core::Colour( 0.633f, 0.832f, 0.98f, 1.f );
const core::Colour core::Colour::SlateGrey= core::Colour( 0x336699 );



