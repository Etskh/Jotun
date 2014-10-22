#pragma once

////////////////////////////////////////////////////////////////////
//
// StaticMeshNode.h
//
class Scene;

class StaticMeshNode
	: public SceneNode
{
public:
	typedef std::shared_ptr<StaticMeshNode> Handle; // TODO - change this to: typedef SmrtPtr<Mesh> Handle;
	friend class Scene;
	
public:
	MeshContext::Handle		meshContext			( void );
	MaterialContext::Handle	materialContext		( void );
	virtual					~StaticMeshNode		( void );

	virtual bool			GetRenderable		( Renderable& renderable );

private:
							StaticMeshNode		( const char* name, Mesh::Handle mesh, Material::Handle material );

private:
	MeshContext::Handle			_meshContext;
	MaterialContext::Handle		_materialContext;
};


