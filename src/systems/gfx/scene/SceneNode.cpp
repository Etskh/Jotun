#include "../Gfx.h"


////////////////////////////////////////////////////////////////////
//
// SceneNode.cpp
//
void	SceneNode::Transform		( const core::Matrix4* mat ) const
{
	mat = &_transform;
}

void	SceneNode::Transform		( core::Matrix4* mat )
{
	mat =  &_transform;
}

SceneNode::SceneNode		( const char* name )
	: _name( name )
{
	// empty
}

SceneNode::~SceneNode		( void )
{
	// empty
}

const char*		SceneNode::name			( void ) const
{
	return _name.c_str();
}

const char*		SceneNode::name			( const char* pName )
{
	_name = pName;
	return _name.c_str();
}

bool			SceneNode::GetRenderable	( Renderable& renderable )
{
	return false;
}