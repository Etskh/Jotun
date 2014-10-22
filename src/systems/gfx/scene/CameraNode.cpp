#include "../Gfx.h"



////////////////////////////////////////////////////////////////////
//
// CameraNode.cpp
//



bool		CameraNode::GetProjectionMatrix	( OUT core::Matrix4* matrix ) const
{
	return false;
}
bool		CameraNode::GetWorldViewMatrix	( OUT core::Matrix4* matrix ) const
{
	return false;
}



bool		CameraNode::LookAt			( core::Vector3& where )
{
	// add some stuff in here
	return true;
}


CameraNode::CameraNode		( const char* name )
	: SceneNode( name )
{
	// empty
}

CameraNode::~CameraNode		( void )
{
	// empty
}
