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


Mesh::Handle	Mesh::CreateQuad			( const char* name )
{
	Mesh::Handle mesh( new Mesh(name) );
	

		
	return mesh;
}

bool			Mesh::AddNormal			( void )
{
	return false;
}

bool			Mesh::AddColour			( void )
{
	return false;
}

/*bool			Mesh::AddWeight			( void )
{
	return false;
}*/

bool			Mesh::AddUV				( void )
{
	return false;
}



bool		Mesh::HasNormal			( void ) const
{
	return false;
}

bool		Mesh::HasColour			( void ) const
{
	return false;
}

//bool		Mesh::HasWeight			( void ) const;

bool		Mesh::HasUV				( void ) const
{
	return false;
}

uint		Mesh::GetVertexType		( void ) const
{
	return false;
}
	
uint		Mesh::surfaceCount		( void ) const
{
	return _surfaces.size();
}

uint		Mesh::vertexCount		( void ) const
{
	return _vertexCount;
}











const char*		Mesh::name				( void ) const
{
	return _name.c_str();
}

uint			Mesh::vertexBuffer		( void ) const
{
	return _vertexBuffer;
}

uint			Mesh::indexBuffer			( void ) const
{
	return _indexBuffer;
}


Mesh::Mesh		( const char* name )
	: _name (name )
	, _vertexBuffer( 0 )
	, _indexBuffer( 0 )
	, _locked ( false )
	, _modified ( false )
	, _vertexCount ( 0 )
{
	// empty
}

Mesh::~Mesh		( void )
{
	// empty
}

