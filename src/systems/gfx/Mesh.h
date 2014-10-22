#pragma once

struct Surface {
	uint	indices[3];
};




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
	enum Component {
		Position,
		Normal,
		Colour,
		Weight,
		UV
	};
	bool				AddNormal			( void );
	bool				AddColour			( void );
	//bool				AddWeight			( void );
	bool				AddUV				( void );

	bool				HasNormal			( void ) const;
	bool				HasColour			( void ) const;
	//bool				HasWeight			( void ) const;
	bool				HasUV				( void ) const;

	uint				GetVertexType		( void ) const;

public:
	uint				surfaceCount		( void ) const;
	uint				vertexCount			( void ) const;

public:
	const char*			name				( void ) const;
	uint				vertexBuffer		( void ) const;
	uint				indexBuffer			( void ) const;
						~Mesh				( void );


private:
						Mesh				( const char* name );

private:
	std::string					_name;
	uint						_vertexBuffer;
	uint						_indexBuffer;

	bool						_locked;
	bool						_modified;
	uint						_vertexCount;


	std::vector<Surface>		_surfaces;

	std::vector<math::Vector3>	_pos;
	std::vector<math::Vector3>	_norm;
	std::vector<core::Colour>	_colour;
	//std::vector<Weight>		_weight;
	std::vector<math::Vector2>	_uv;
};

