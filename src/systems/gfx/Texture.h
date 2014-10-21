#pragma once

////////////////////////////////////////////////////////////////////
//
// Texture.h
//
class Texture
{
public:
	//
	// The handle to the Texture
	//
	typedef std::shared_ptr<Texture> Handle; // TODO - change this to: typedef SmrtPtr<Texture> Handle;
	
public:
	//
	// Want one? Come at me bro
	//
	static Texture::Handle	CreateEmpty			( const char* name );
	static Texture::Handle	CreateFromData		( const char* name, const char* pData, uint nsize );

public:
	//
	// Use dis 4 stuff
	//
	uint					GetUID				( void ) const;
							~Texture			( void );

private:
	//
	// No touchy
	//
							Texture				( const char* name );

private:
	std::string	_name;
	uint		_textureID;
};
