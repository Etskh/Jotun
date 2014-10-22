

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "Assert.h"

template<int _WIDTH>
core::TStringN<_WIDTH>::TStringN			( void )
	: _hash(0)
	, _changed(true)
{
	memset( _data, 0, _WIDTH );
}

template<int _WIDTH>
core::TStringN<_WIDTH>::TStringN			( const TStringN<_WIDTH>& ref )
	: _hash(0)
	, _changed(true)
{
	memcpy( _data, ref._data, _WIDTH );
}

template<int _WIDTH>
core::TStringN<_WIDTH>::TStringN			( const char* str )
	: _hash(0)
	, _changed(true)
{
	memset( _data, 0, _WIDTH );
	memcpy( _data, str, strlen(str) );
}

template<int _WIDTH>
core::TStringN<_WIDTH>::~TStringN		( void )
{
	// empty
}

template<int _WIDTH>	
core::TStringN<_WIDTH>&		core::TStringN<_WIDTH>::operator=		( const TStringN<_WIDTH>& ref )
{
	memcpy( _data, ref._data, _WIDTH );
	_changed = true;
	
	return *this;
}

template<int _WIDTH>
core::TStringN<_WIDTH>&		core::TStringN<_WIDTH>::operator+=		( const TStringN<_WIDTH>& ref )
{
	uint endIndex		= strlen( _data );
	uint newStrLength	= strlen( ref._data );
	
	ASSERT( endIndex + newStrLength > _WIDTH );
	
	memcpy( _data+endIndex, ref._data, newStrLength );
	
	_changed = true;
	return *this;
}

template<int _WIDTH>
core::TStringN<_WIDTH>		core::TStringN<_WIDTH>::operator+		( const TStringN<_WIDTH>& ref ) const
{
	uint endIndex		= strlen( _data );
	uint newStrLength	= strlen( ref._data );
	char buffer[ _WIDTH ];
	
	ASSERT( endIndex + newStrLength > _WIDTH );
	
	memcpy( buffer, _data, _WIDTH );
	memcpy( buffer+endIndex, ref._data, newStrLength );
	
	return TStringN<_WIDTH>( buffer );
}

template<int _WIDTH>
core::TStringN<_WIDTH>&		core::TStringN<_WIDTH>::operator=		( const char* str )
{
	ASSERT( str != NULL );
	
	memset( _data, 0, _WIDTH );
	memcpy( _data, str, strlen(str) );
	
	_changed = true;
	return *this;
}

template<int _WIDTH>
core::TStringN<_WIDTH>&		core::TStringN<_WIDTH>::operator+=		( const char* str )
{
	ASSERT( str != NULL );
	uint endIndex		= strlen( _data );
	uint newStrLength	= strlen( str );
	
	ASSERT( endIndex + newStrLength > _WIDTH );
	
	memcpy( _data+endIndex, str, newStrLength );
	
	_changed = true;
	return *this;
}

template<int _WIDTH>
core::TStringN<_WIDTH>		core::TStringN<_WIDTH>::operator+		( const char* str ) const
{
	ASSERT( str != NULL );

	uint endIndex		= strlen( _data );
	uint newStrLength	= strlen( str );
	char buffer[ _WIDTH ];
	
	ASSERT( endIndex + newStrLength > _WIDTH );
	
	memcpy( buffer, _data, _WIDTH );
	memcpy( buffer+endIndex, str, newStrLength );
	
	return TStringN<_WIDTH>( buffer );
}


template<int _WIDTH>
bool			core::TStringN<_WIDTH>::operator==		( const TStringN<_WIDTH>& ref ) const
{
	return ( hash() == ref.hash() );
}

template<int _WIDTH>
bool			core::TStringN<_WIDTH>::operator!=		( const TStringN<_WIDTH>& ref ) const
{
	return ( hash() != ref.hash() );
}

template<int _WIDTH>
bool			core::TStringN<_WIDTH>::operator==		( const char* str ) const
{
	return ( hash() == jotun::Hash(str) );
}

template<int _WIDTH>
bool			core::TStringN<_WIDTH>::operator!=		( const char* str ) const
{
	return ( hash() != jotun::Hash(str) );
}

template<int _WIDTH>
core::TStringN<_WIDTH>::operator 		bool			( void )			const
{
	// Isn't an empty string
	return !( strcmp( _data, "") ==0);
}


template<int _WIDTH>
uint		core::TStringN<_WIDTH>::size			( void ) const
{
	return _WIDTH;
}

template<int _WIDTH>
const char*	core::TStringN<_WIDTH>::c_str			( void ) const
{
	return _data;
}

template<int _WIDTH>
uint		core::TStringN<_WIDTH>::hash			( void ) const
{
	if( _changed ) {
		_hash = jotun::Hash(_data);
	}
	return _hash;
}

template<int _WIDTH>
uint			core::TStringN<_WIDTH>::CompareToEnum	( const char** enumStrs, uint enumCount )
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

template<int _WIDTH>
core::TStringN<_WIDTH>&	core::TStringN<_WIDTH>::RemoveAll		( const char* characters )
{
	char* pChar = _data;
	uint charLen = strlen(characters);
	
	//
	// Go throught the current string
	//
	while(pChar) {
		
		// And for each character they gave us
		//
		for( uint c=0; c < charLen; c++ ) {
		
			// If it is the current character in the string,
			//
			if( *pChar == characters[c] ) {
				
				// Shift the string left one place, replacing
				// the current character with the one to the right
				//
				char *currentChar= pChar;
				while(currentChar) {
					*currentChar = *(currentChar+1);
					currentChar++;
				}
			}
		}
		
		pChar++;
	}
	
	// Return this
	//
	return *this;
}


template<int _WIDTH>
int				core::TStringN<_WIDTH>::ToInteger	( void ) const
{
	return atoi( _data );
}

template<int _WIDTH>
uint			core::TStringN<_WIDTH>::ToUInteger	( void ) const
{
	uint u;
	sscanf(_data, "%u", &u );
	return u;
}

template<int _WIDTH>
float			core::TStringN<_WIDTH>::ToFloat		( void ) const
{
	float f;
	sscanf(_data, "%f", &f );
	return f;
}

template<int _WIDTH>
double			core::TStringN<_WIDTH>::ToDouble	( void ) const
{
	return atof( _data );
}

template<int _WIDTH>
bool			core::TStringN<_WIDTH>::ToBoolean	( void ) const
{
	this->hash();
	
	if( _data[0] == '0' ) {
		return false;
	}

	if( _hash == jotun::Hash("true")) {
		return true;
	}
	
	if( _hash == jotun::Hash("false")) {
		return false;
	}
	
	if( _hash == jotun::Hash("yes")) {
		return true;
	}
	
	if( _hash == jotun::Hash("no")) {
		return false;
	}
	
	if( _data[0] != '0' ) {
		return true;
	}
	
	return false;
}





