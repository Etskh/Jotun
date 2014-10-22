#include "Gfx.h"


////////////////////////////////////////////////////////////////////
//
// Material.cpp
//
Material::Handle	Material::Create	( const char* name, Shader::Handle vertexShader, Shader::Handle fragmentShader )
{
	Material::Handle material( new Material(name) );
	
	material->_vertexShader = vertexShader;
	material->_fragmentShader = fragmentShader;
	
	// TODO - some checks to make sure that the shaders' parameters don't collide
	
	return material;
}


const char*		Material::name			( void ) const
{
	return _name.c_str();
}




Shader::Handle	Material::fragmentShader( void )
{
	return _fragmentShader;
}


Shader::Handle	Material::pixelShader	( void )
{
	return _fragmentShader;
}


Shader::Handle	Material::vertexShader	( void )
{
	return _vertexShader;
}



Material::~Material		( void )
{
	// empty
}

Material::Material		( const char* name )
	: _name( name )
	, _vertexShader(NULL)
	, _fragmentShader(NULL)
{
	// empty
}

