#pragma once


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
	bool					GetProjectionMatrix	( OUT math::Matrix4* matrix ) const;
	bool					GetWorldViewMatrix	( OUT math::Matrix4* matrix ) const;

	bool					LookAt				( math::Vector3& where );
	virtual					~CameraNode			( void );

private:
							CameraNode			( const char* name );
};

