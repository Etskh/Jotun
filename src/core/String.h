#ifndef __INCLUDED_JOTUN_String_h
#define __INCLUDED_JOTUN_String_h

#include <string>
#include "Patterns.h"
#include "List.h"

#include "TStringN.h"

namespace core {


class String
{
public:
					String			( void );
					String			( const String&	ref );
					String			( const char*	str );
					~String			( void );
	
public:
	String&			operator=		( const String& ref );
	String&			operator=		( const char*	str );
	
	String&			operator+=		( const String& ref );
	String&			operator+=		( const char* str );
	
	String			operator+		( const String& ref )	const;
	String			operator+		( const char* str )		const;
	
public:
	bool			operator==		( const String& ref )	const;
	bool			operator!=		( const String& ref )	const;
	bool			operator==		( const char* str )		const;
	bool			operator!=		( const char* str )		const;
	operator 		bool			( void )				const;
	
public:
	uint			size			( void ) const;
	const char*		c_str			( void ) const;
	const char*		c_str			( void );
	
public:
	uint			hash			( void ) const;	
	
public:
	uint			Split			( const char* delimiters, core::List<String>* strList );
	uint			CompareToEnum	( const char** enumStrs, uint enumCount );
	
public:
	bool			EndsWith		( const char* str ) const;
	bool			StartsWith		( const char* str ) const;
	
public:
	int				ToInteger		( void ) const;
	uint			ToUInteger		( void ) const;
	float			ToFloat			( void ) const;
	double			ToDouble		( void ) const;
	bool			ToBoolean		( void ) const;
	
private:
	std::string		_data;
	mutable uint	_hash;
	mutable bool	_changed;
};


} // namespace core


#endif // __INCLUDED_JOTUN_String_h