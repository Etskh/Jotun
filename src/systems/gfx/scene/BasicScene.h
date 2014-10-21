#pragma once

////////////////////////////////////////////////////////////////////
//
// BasicScene.h
//
class BasicScene
	: Scene
{	
public:
							~BasicScene			( void );
							BasicScene			( void );
						
public:
	SceneNode::Handle		Add					( SceneNode::Handle node );
	bool					Render				( CameraNode::Handle camera );
						
private:
	std::vector<SceneNode::Handle>	_nodes;
};
