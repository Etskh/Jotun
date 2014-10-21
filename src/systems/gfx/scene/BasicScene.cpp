
#include "../Gfx.h"
#include "BasicScene.h"

////////////////////////////////////////////////////////////////////
//
// BasicScene.cpp
//


BasicScene::BasicScene			( void )
	: Scene ()
{
	// empty
}

BasicScene::~BasicScene			( void )
{
	// empty
}

SceneNode::Handle	BasicScene::Add					( SceneNode::Handle node )
{
	_nodes.push_back(node);
	return node;
}
bool				BasicScene::Render				( CameraNode::Handle camera )
{
	printf(" using %s\n", camera->name() );
	
	math::Matrix4	proj;
	math::Matrix4	view;
	Renderable		renderable;
	
	camera->GetProjectionMatrix( &proj );
	camera->GetWorldViewMatrix( &view );
	
	for( uint n=0, len=_nodes.size(); n < len; n++ ) {
		
		if( _nodes[n]->GetRenderable( renderable ) ) {

			printf(" - rendering %s\n", _nodes[n]->name() );
			printf("   with Mesh %s\n", renderable.meshContext->mesh()->name() );
			printf("   and Material %s\n", renderable.materialContext->material()->name() );
			printf("   setting matrices\n");
			
			if( renderable.materialContext->SetProjectionMatrix(proj) ) {
				printf("    - projection matrix\n");
			}
			if( renderable.materialContext->SetWorldViewMatrix(proj) ) {
				printf("    - world-view matrix\n");
			}
		}
		
	}
	
	return true;
}
