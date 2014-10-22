#pragma once



struct Renderable
{
	MeshContext::Handle meshContext;
	MaterialContext::Handle materialContext;
};



////////////////////////////////////////////////////////////////////
//
// SceneNode.h
//
class SceneNode
{
public:
	typedef std::shared_ptr<SceneNode> Handle; // TODO - change this to: typedef SmrtPtr<Mesh> Handle;
	
public:
	void					Transform		( const core::Matrix4* mat ) const;
	void					Transform		( core::Matrix4* mat );
	virtual					~SceneNode		( void );
	const char*				name			( void ) const;
	const char*				name			( const char* pName );
	
	virtual bool			GetRenderable	( Renderable& renderable );

protected:
							SceneNode		( const char* name );

private:
	std::string				_name;
	core::Matrix4			_transform;
};

