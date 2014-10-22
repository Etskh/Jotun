#include "Gfx.h"

MaterialContext::Handle	MaterialContext::Create	( Material::Handle material )
{
	MaterialContext::Handle context( new MaterialContext(material) );
	return context;
}
	
Material::Handle	MaterialContext::material			( void )
{
	return _material;
}


bool		MaterialContext::SetProjectionMatrix	( math::Matrix4& matrix )
{
	// Set the parameter, based on the shaders in the material
	// to the right parameter name
	Parameter param;
	
	if( _material->vertexShader()->GetParameter( &param, Parameter::Projection )) {
		return SetValue( param.name(), matrix );
	}
		
	return false;
}

bool		MaterialContext::SetWorldViewMatrix	( math::Matrix4& matrix )
{
	// Set the parameter, based on the shaders in the material
	// to the right parameter name
	Parameter param;
	
	if( _material->vertexShader()->GetParameter( &param, Parameter::WorldView )) {
		return SetValue( param.name(), matrix );
	}
	
	return false;
}


bool		MaterialContext::SetValue			( const char* valName, float value )
{
	return false;
}
bool		MaterialContext::SetValue			( const char* valName, math::Vector3& vector )
{
	return false;
}
bool		MaterialContext::SetValue			( const char* valName, core::Colour& colour )
{
	return false;
}
bool		MaterialContext::SetValue			( const char* valName, math::Matrix4& matrix )
{
	//
	// TODO - replace strcmp with hash
	//
	for( uint pi=0, len=_params.size(); pi<len; pi++) {
	
		printf( "setting the thing: '%s'", _params[pi]->name() );
		
		//if( strcmp( valName, _params[pi]->name()) == 0 ) {
			_params[pi]->SetValue( matrix );
			return true;
		//}
	}
	return false;
}
bool		MaterialContext::SetValue			( const char* valName, Texture::Handle texture )
{
	return false;
}
	
MaterialContext::MaterialContext	( Material::Handle material )
	: _material ( material )
{
	// Create the params for the shaders
	// 
	Parameter param;
	
	for( uint p=0, len = material->fragmentShader()->GetParameterCount(); p < len; p++) {
		material->fragmentShader()->GetParameterAt(&param, p);
		_params.push_back( param.CreateInstance() );
	}
	for( uint p=0, len = material->vertexShader()->GetParameterCount(); p < len; p++) {
		material->vertexShader()->GetParameterAt(&param, p);
		_params.push_back( param.CreateInstance() );
	}
}


MaterialContext::~MaterialContext	( void )
{
	// empty
}
