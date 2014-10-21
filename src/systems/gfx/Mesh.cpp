#include "Gfx.h"


////////////////////////////////////////////////////////////////////
//
// Mesh.cpp
//

Mesh::Handle	Mesh::CreateEmpty			( const char* name )
{
	Mesh::Handle mesh( new Mesh(name) );
	return mesh;
}

const char*		Mesh::name				( void ) const
{
	return _name.c_str();
}

Mesh::Mesh		( const char* name )
	: _name (name )
	, _vertexBuffer( 0 )
	, _indexBuffer( 0 )
{
	// empty
}

Mesh::~Mesh		( void )
{
	// empty
}

