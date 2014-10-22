#pragma once

#include "core/Patterns.h"

////////////////////////////////////////////////////////////////////
//
// CameraNode.h
//
class Scene;

class CameraNode
	: public SceneNode
{
public:
	typedef std::shared_ptr<CameraNode> Handle; // TODO - change this to: typedef SmrtPtr<Mesh> Handle;
	friend class Scene;
	
public:
	bool					GetProjectionMatrix	( OUT core::Matrix4* matrix ) const;
	bool					GetWorldViewMatrix	( OUT core::Matrix4* matrix ) const;

	bool					LookAt				( core::Vector3& where );
	virtual					~CameraNode			( void );

private:
							CameraNode			( const char* name );
};

