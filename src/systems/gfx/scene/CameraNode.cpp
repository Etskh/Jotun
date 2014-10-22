#include "../Gfx.h"



////////////////////////////////////////////////////////////////////
//
// CameraNode.cpp
//



bool		CameraNode::GetProjectionMatrix	( OUT math::Matrix4* matrix ) const
{
	return false;
}
bool		CameraNode::GetWorldViewMatrix	( OUT math::Matrix4* matrix ) const
{
	return false;
}



bool		CameraNode::LookAt			( math::Vector3& where )
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
