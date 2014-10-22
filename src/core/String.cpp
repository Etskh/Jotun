
#include "String.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>


core::String::String			( void )
	: _data("")
	, _hash(0)
	, _changed(false)
{
	//empty
}

core::String::String			( const String& ref )
	: _data(ref._data)
	, _hash(ref._hash)
	, _changed(false)
{
	//empty
}

core::String::String			( const char* str )
	: _data(str)
	, _hash( jotun::Hash(str) )
	, _changed(false)
{
	//empty
}

core::String::~String			( void )
{
	// empty
}

	
core::String&		core::String::operator=		( const String& ref )
{
	_data = ref._data;
	_hash = ref._hash;
	_changed = ref._changed;
	
	return *this;
}

core::String&		core::String::operator+=		( const String& ref )
{
	_data += ref._data;
	_changed = true;
	
	return *this;
}

core::String		core::String::operator+		( const String& ref ) const
{
	return String( ((std::string)(_data + ref._data)).c_str() );
}

core::String&		core::String::operator=		( const char* str )
{
	_data = str;
	_changed = true;
	
	return *this;
}

core::String&		core::String::operator+=		( const char* str )
{
	_data += str;
	_changed = true;
	
	return *this;
}

core::String		core::String::operator+		( const char* str ) const
{
	std::string temp = str;
	return String( ((std::string)(_data + temp)).c_str() );
}



bool			core::String::operator==		( const String& ref ) const
{
	return ( _hash == ref.hash() );
}

bool			core::String::operator!=		( const String& ref ) const
{
	return ( _hash != ref.hash() );
}

bool			core::String::operator==		( const char* str ) const
{
	return ( _hash == jotun::Hash(str) );
}

bool			core::String::operator!=		( const char* str ) const
{
	return ( _hash != jotun::Hash(str) );
}



core::String::operator 		bool			( void )				const
{
	// Isn't an empty string
	return ( _data[0] != '\0' );
}



uint		core::String::size			( void ) const
{
	return _data.size();
}

const char*	core::String::c_str			( void ) const
{
	return _data.c_str();
}

const char*	core::String::c_str			( void )
{
	return _data.c_str();
}

uint		core::String::hash			( void ) const
{
	if( _changed ) {
		_hash = jotun::Hash(_data.c_str());
	}
	return _hash;
}


uint		core::String::Split			( const char* delimiters, core::List<String>* strList )
{
	const uint	bufferSize	= this->size() + 8;
	uint		count		= 0;
	char*		buffer		= NULL;
	char*		pointer		= NULL;
	
	buffer = new char[ bufferSize ];
	memset( buffer, 0, bufferSize );
	
	pointer = strtok( buffer, delimiters );
	while (pointer != NULL) {
		
		// Add the string to the list
		(*strList) += String(pointer);
		count++;
		
		pointer = strtok (NULL, delimiters);
	}
	delete[] buffer;
	
	return count;
}


uint			core::String::CompareToEnum	( const char** enumStrs, uint enumCount )
{
	// make sure we got a hash
	this->hash();
	for( uint i=0; i< enumCount; i++) {
		if ( _hash == jotun::Hash( enumStrs[i] ) ) {
			return i;
		}
	}
	return 0xDEADFACE;	
}


bool		core::String::EndsWith			( const char* str ) const
{
	if (  (_data.rfind(str)+ strlen(str)) == _data.length() ) {
		return true;
	}
	return false;
}
bool		core::String::StartsWith		( const char* str ) const
{
	if ( _data.find(str) == 0 ) {
		return true;
	}
	return false;
}





int				core::String::ToInteger		( void ) const
{
	return atoi( _data.c_str() );
}

uint			core::String::ToUInteger	( void ) const
{
	uint u;
	sscanf(_data.c_str(), "%u", &u );
	return u;
}

float			core::String::ToFloat		( void ) const
{
	float f;
	sscanf(_data.c_str(), "%f", &f );
	return f;
}

double			core::String::ToDouble		( void ) const
{
	return atof( _data.c_str() );
}

bool			core::String::ToBoolean		( void ) const
{
	if( _data[0] == '0' ) {
		return false;
	}

	if( strcmp(_data.c_str(), "true") == 0 ) {
		return true;
	}
	
	if( strcmp(_data.c_str(), "false") == 0) {
		return false;
	}
	
	if( strcmp(_data.c_str(), "yes") == 0 ) {
		return true;
	}
	
	if( strcmp(_data.c_str(), "no") == 0 ) {
		return false;
	}
	
	if( _data[0] != '0' ) {
		return true;
	}
	
	return false;
}





