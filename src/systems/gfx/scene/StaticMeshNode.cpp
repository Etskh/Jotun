#include "../Gfx.h"

////////////////////////////////////////////////////////////////////
//
// StaticMeshNode.cpp
//
StaticMeshNode::StaticMeshNode		( const char* name, Mesh::Handle mesh, Material::Handle material )
	: SceneNode( name )
	, _meshContext ( MeshContext::Create(mesh) )
	, _materialContext ( MaterialContext::Create(material) )
{
	// empty
}

StaticMeshNode::~StaticMeshNode		( void )
{
	// empty
}


MeshContext::Handle		StaticMeshNode::meshContext			( void )
{
	return _meshContext;
}

MaterialContext::Handle	StaticMeshNode::materialContext		( void )
{
	return _materialContext;
}

bool		StaticMeshNode::GetRenderable		( Renderable& renderable )
{
	renderable.meshContext = _meshContext;
	renderable.materialContext = _materialContext;
	return true;
}