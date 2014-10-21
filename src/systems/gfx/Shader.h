#pragma once


////////////////////////////////////////////////////////////////////
//
// Shader.h
//
class Shader
{
public:
	//
	// The handle to the Shader
	//
	typedef std::shared_ptr<Shader> Handle; // TODO - change this to: typedef SmrtPtr<Shader> Handle;
	
public:
	//
	// Want one? Come at me bro
	//
	static Shader::Handle	CreateEmpty			( const char* name );
	static Shader::Handle	CreateFromData		( const char* name, const char* pData, uint nsize );

public:
	//
	// Rendering business
	//
	//	TODO: implement this
	bool					MakeActive			( void );
	
public:
	//
	// A couple quick little helpers
	//
	bool					setProjectionMatrix	( const char* name );
	bool					setWorldViewMatrix	( const char* name );

public:
	//
	// The long setup
	//
	bool					AddValue			( const char* value, Parameter::Type type );
	bool					AddValue			( const char* value, Parameter::Type type, Parameter::Purpose purpose );
	bool					GetParameter		( Parameter* param, Parameter::Purpose purpose );
	bool					GetParameter		( Parameter* param, const char* name );
	
	bool					GetParameterAt		( Parameter* param, uint index );
	uint					GetParameterCount	( void ) const;
	/*
	bool					SetValue			( const char* valName, float value );
	bool					SetValue			( const char* valName, math::Vector3& vector );
	bool					SetValue			( const char* valName, core::Colour& colour );
	bool					SetValue			( const char* valName, math::Matrix4& matrix );
	bool					SetValue			( const char* valName, Texture::Handle texture );
	*/
							~Shader				( void );
	
private:
	//
	// Y u here? no touch - it's private!
	//
							Shader				( const char* name );

private:
	std::string				_name;
	uint					_programID;
	std::vector<Parameter>	_params;
};
