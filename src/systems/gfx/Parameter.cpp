#include "Gfx.h"


////////////////////////////////////////////////////////////////////
//
// Parameter.cpp
//
Parameter::HInstance	Parameter::CreateInstance		( void )
{
	HInstance hParamInst( new Instance(this) );
	
	return hParamInst;
}


Parameter::Parameter						( void )
	: _name ( "Invalid-Parameter" )
	, _type ( Invalid )
	, _purpose ( None )
{

}

Parameter::Parameter						( const char* name, Type type, Purpose purpose )
	: _name ( name )
	, _type ( type )
	, _purpose ( purpose )
{
	// empty
}

Parameter::~Parameter						( void )
{
	// empty
}


const char*			Parameter::name			( void ) const
{
	return _name.c_str();
}


Parameter::Type		Parameter::type			( void ) const
{
	return _type;
}


uint				Parameter::size			( void ) const
{
	return _size;
}


Parameter::Purpose	Parameter::purpose		( void ) const
{
	return _purpose;
}




bool	Parameter::Instance::MakeActive		( void )
{
	return false;
}

bool	Parameter::Instance::SetValue		( float value )
{
	if( _host->type() != Parameter::Float ) {
		return _data != NULL;
	}
	return false;
}

bool	Parameter::Instance::SetValue		( core::Vector3& vector )
{
	return false;
}

bool	Parameter::Instance::SetValue		( core::Colour& colour )
{
	return false;
}

bool	Parameter::Instance::SetValue		( core::Matrix4& matrix )
{
	printf("\n\nHOMg! Setting a matrix to be the thing!\n\n");
	return false;
}

bool	Parameter::Instance::SetValue		( Texture::Handle texture )
{
	return false;
}

const char*	Parameter::Instance::name		( void ) const
{
	ASSERT( _host != NULL );
	return _host->name();
}

const Parameter* Parameter::Instance::host	( void ) const
{
	ASSERT( _host != NULL );
	return _host;
}

Parameter::Instance::~Instance				( void )
{
	// empty
}

Parameter::Instance::Instance				( const Parameter* host )
	: _host( host )
	, _data( NULL )
{
	// empty
}





