#include "Gfx.h"


////////////////////////////////////////////////////////////////////
//
// MeshContext.cpp
//

MeshContext::Handle	MeshContext::Create( Mesh::Handle mesh )
{
	MeshContext::Handle meshContext( new MeshContext() );
	
	meshContext->_mesh = mesh;
	
	return meshContext;
}
	
Mesh::Handle		MeshContext::mesh	( void )
{
	return _mesh;
}
	
MeshContext::~MeshContext				( void )
{
	// empty
}

MeshContext::MeshContext				( void )
{
	// empty
}
