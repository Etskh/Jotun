
#include "../Gfx.h"
#include "BasicScene.h"


////////////////////////////////////////////////////////////////////
//
// Scene.cpp
//

Scene::Handle	Scene::CreateBasicScene	( void )
{
	Scene::Handle scene( (Scene*)(new BasicScene()) );
	return scene;
}

StaticMeshNode::Handle	Scene::CreateStaticMeshNode	( const char* name, Mesh::Handle mesh, Material::Handle material  )
{
	StaticMeshNode::Handle staticMesh( new StaticMeshNode(name, mesh, material) );
	
	Add( staticMesh );
	
	return staticMesh;
}

CameraNode::Handle	Scene::CreateCamera		( const char* name )
{
	CameraNode::Handle camera( new CameraNode(name) );
	//CameraNode::Handle nullCamera
	
	if( _activeCamera == NULL ) {
		_activeCamera = camera;
	}
	
	return camera;
}

bool				Scene::SetActiveCamera	( CameraNode::Handle camera )
{
	_activeCamera = camera;
	return true;
}

bool			Scene::Render				( void )
{
	ASSERT( _activeCamera != NULL );
	return Render( _activeCamera );
}


Scene::Scene			( void )
{
	// empty
}

Scene::~Scene			( void )
{
	// empty
}
