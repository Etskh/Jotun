#pragma once


////////////////////////////////////////////////////////////////////
//
// MaterialContext.h
//
class MaterialContext
{
public:
	typedef std::shared_ptr<MaterialContext> Handle; // TODO - change this to: typedef SmrtPtr<MaterialContext> Handle;
	
public:
	static MaterialContext::Handle	Create	( Material::Handle material );
	
public:
	Material::Handle	material			( void );
	
public:
	bool				SetProjectionMatrix	( core::Matrix4& matrix );
	bool				SetWorldViewMatrix	( core::Matrix4& matrix );
	
public:
	bool				SetValue			( const char* valName, float value );
	bool				SetValue			( const char* valName, core::Vector3& vector );
	bool				SetValue			( const char* valName, core::Colour& colour );
	bool				SetValue			( const char* valName, core::Matrix4& matrix );
	bool				SetValue			( const char* valName, Texture::Handle texture );
						~MaterialContext	( void );
	
protected:
						MaterialContext		( Material::Handle material );

private:
	Material::Handle					_material;
	std::vector<Parameter::HInstance>	_params;
};

