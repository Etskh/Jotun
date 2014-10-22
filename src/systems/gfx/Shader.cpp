#include "Gfx.h"


////////////////////////////////////////////////////////////////////
//
// Shader.cpp
//

Shader::Handle	Shader::CreateEmpty			( const char* name )
{
	Shader::Handle shader( new Shader(name) );
	
	return shader;
}

Shader::Handle	Shader::CreateFromData		( const char* name, const char* pData, uint nsize )
{
	ASSERT( pData != NULL );

	Shader::Handle shader( new Shader(name) );
	
	//
	// Process the file in here
	printf("Processing: shader...\n");
	
	return shader;
}


bool			Shader::setProjectionMatrix	( const char* name )
{
	return AddValue( name, Parameter::Matrix, Parameter::Projection );
}

bool			Shader::setWorldViewMatrix	( const char* name )
{
	return AddValue( name, Parameter::Matrix, Parameter::WorldView );
}

bool			Shader::AddValue			( const char* value, Parameter::Type type )
{
	return AddValue( value, type, Parameter::None );
}

bool			Shader::AddValue			( const char* value, Parameter::Type type, Parameter::Purpose purpose )
{
	//
	// TODO - make sure there is only one parameter with this name
	//
	_params.push_back( Parameter(value, type, purpose) );
	return true;
}

bool			Shader::GetParameter		( Parameter* param, Parameter::Purpose purpose )
{
	ASSERT( param != NULL );
	
	for( uint p=0, len=_params.size(); p < len; p++ ) {
		if( _params[p].purpose() == purpose ) {
			
			*param = _params[p];
			return true;
			
		}
	} 
	return false;
}

bool		Shader::GetParameter	( Parameter* param, const char* name )
{
	ASSERT( param != NULL );
	return false;
}



bool		Shader::GetParameterAt	( Parameter* param, uint index )
{
	ASSERT( index < _params.size() );	
	
	*param = _params[index];

	return true;
}



uint		Shader::GetParameterCount	( void ) const
{
	return _params.size();
}





Shader::Shader				( const char* name )
	: _name ( name )
	, _programID ( 0 )
{
	// empty
}

Shader::~Shader				( void )
{
	// empty
}