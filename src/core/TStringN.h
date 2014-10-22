#ifndef __INCLUDED_JOTUN_TStringN_h
#define __INCLUDED_JOTUN_TStringN_h


#include "Patterns.h"


namespace core {

template< int _WIDTH >
class TStringN
{
public:
					TStringN		( void );
					TStringN		( const TStringN& ref );
					TStringN		( const char* str );
					~TStringN		( void );
	
public:
	TStringN&		operator=		( const TStringN& ref );
	TStringN&		operator+=		( const TStringN& ref );
	TStringN&		operator=		( const char* str );
	TStringN&		operator+=		( const char* str );
	TStringN		operator+		( const TStringN& ref )	const;
	TStringN		operator+		( const char* str )		const;
	
public:
	bool			operator==		( const TStringN& ref )	const;
	bool			operator!=		( const TStringN& ref )	const;
	bool			operator==		( const char* str )		const;
	bool			operator!=		( const char* str )		const;
	operator 		bool			( void )				const;
	
public:
	uint			size			( void ) const;
	const char*		c_str			( void ) const;
	
public:
	uint			hash			( void ) const;	
	
public:
	uint			CompareToEnum	( const char** enumStrs, uint enumCount );
	TStringN&		RemoveAll		( const char* characters );
	
public:
	int				ToInteger		( void ) const;
	uint			ToUInteger		( void ) const;
	float			ToFloat			( void ) const;
	double			ToDouble		( void ) const;
	bool			ToBoolean		( void ) const;
	
private:
	mutable uint	_hash;
	bool			_changed;
	char			_data		[_WIDTH];
};

typedef TStringN<10> String16;
typedef TStringN<26> String32;
typedef TStringN<58> String64;

}

#include "TStringN.inl"


#endif // __INCLUDED_JOTUN_TStringN_h