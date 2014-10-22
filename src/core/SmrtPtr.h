#ifndef __INCLUDED_JOTUN_SmrtPtr_h
#define __INCLUDED_JOTUN_SmrtPtr_h

#include "Counted.h"



template< class _Type >
class SmrtPtr
{
public:
					SmrtPtr			( void );
					SmrtPtr			( _Type* obj );
					SmrtPtr			( const _Type*& obj );
					SmrtPtr			( const SmrtPtr& ref );
					~SmrtPtr		( void );
public:
	SmrtPtr&		operator=		( const SmrtPtr& ref );
	_Type*			operator->		( void );
	const _Type*	operator->		( void ) const;
	_Type&			operator*		( void );
	
	_Type*			ptr				( void );
	
public:
	bool			operator==		( const SmrtPtr& ref );
					operator bool	( void ) const;

private:
	Counted<_Type>*		_ref;
};

#include "SmrtPtr.inl"

#endif // __INCLUDED_JOTUN_SmrtPtr_h