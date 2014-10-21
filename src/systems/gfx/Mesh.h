#pragma once

////////////////////////////////////////////////////////////////////
//
// Mesh.h
//
class Mesh
{
public:
	typedef std::shared_ptr<Mesh> Handle; // TODO - change this to: typedef SmrtPtr<Mesh> Handle;
	
public:
	static Mesh::Handle	CreateEmpty			( const char* name );
	static Mesh::Handle	CreateQuad			( const char* name ); // TODO - implement this
	
	
public:
	const char*			name				( void ) const;
						~Mesh				( void );
	
	
private:
						Mesh				( const char* name );
						
private:

	std::string	_name;
	uint		_vertexBuffer;
	uint		_indexBuffer;
};

