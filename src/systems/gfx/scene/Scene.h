#pragma once

////////////////////////////////////////////////////////////////////
//
// Scene.h
//
class Scene
{
public:
	typedef std::shared_ptr<Scene> Handle; // TODO - change this to: typedef SmrtPtr<Mesh> Handle;
	
public:
	static	Scene::Handle	CreateBasicScene	( void );
	
public:
	StaticMeshNode::Handle	CreateStaticMeshNode( const char* name, Mesh::Handle mesh, Material::Handle material );
	CameraNode::Handle		CreateCamera		( const char* name );

public:
	bool					SetActiveCamera		( CameraNode::Handle camera );
	CameraNode::Handle		GetActiveCamera		( void );
	virtual bool			Render				( void );
	virtual bool			Render				( CameraNode::Handle camera ) = 0;
							~Scene				( void );
protected:
	virtual SceneNode::Handle	Add				( SceneNode::Handle node )=0;
							Scene				( void );
						
private:
	CameraNode::Handle	_activeCamera;
};

