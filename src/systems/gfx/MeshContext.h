#pragma once

////////////////////////////////////////////////////////////////////
//
// MeshContext.h
//
class MeshContext
{
public:
	typedef std::shared_ptr<MeshContext> Handle; // TODO - change this to: typedef SmrtPtr<Mesh> Handle;
	
public:
	static MeshContext::Handle	Create	( Mesh::Handle mesh );
	
public:
	Mesh::Handle		mesh			( void );
	
						~MeshContext	( void );
	
protected:
						MeshContext		( void );

private:
	Mesh::Handle		_mesh;
};

