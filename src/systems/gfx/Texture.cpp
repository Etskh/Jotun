#include "Gfx.h"


////////////////////////////////////////////////////////////////////
//
// Texture.cpp
//
Texture::Handle	Texture::CreateEmpty			( const char* name )
{
	Texture::Handle texture( new Texture(name) );
	
	return texture;
}

Texture::Handle	Texture::CreateFromData		( const char* name, const char* pData, uint nsize )
{
	ASSERT( false );
	
	return Texture::Handle( NULL );
}


Texture::Texture			( const char* name )
	: _name ( name )
	, _textureID ( 0 )
{
	// empty
}

Texture::~Texture			( void )
{
	// empty
}
	