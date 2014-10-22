#pragma once


////////////////////////////////////////////////////////////////////
//
// Material.h
//


class Material
{
public:
	//
	// The handle to the Shader
	//
	typedef std::shared_ptr<Material> Handle; // TODO - change this to: typedef SmrtPtr<Material> Handle;
	
public:
	//
	// Want one? Come at me bro
	//
	static Material::Handle	Create			( const char* name, Shader::Handle vertexShader, Shader::Handle fragmentShader );

public:
	//
	// The long setup
	//
	const char*				name			( void ) const;
	/*
	bool					AddValue		( const char* alias, float value );
	bool					AddValue		( const char* alias, math::Vector3& vector );
	bool					AddValue		( const char* alias, core::Colour& colour );
	bool					AddValue		( const char* alias, math::Matrix4& matrix );
	bool					AddValue		( const char* alias, Texture::Handle texture );
	*/
	Shader::Handle			fragmentShader	( void );
	Shader::Handle			pixelShader		( void );
	Shader::Handle			vertexShader	( void );
							~Material		( void );

private:
							Material		( const char* name );

private:
	std::string				_name;
	Shader::Handle			_vertexShader;
	Shader::Handle			_fragmentShader;
};

