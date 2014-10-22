#ifndef __INCLUDED_JOTUN_Counted_h
#define __INCLUDED_JOTUN_Counted_h

#include "Patterns.h"


template< class _Type >
class Counted
{
public:
					Counted		( void );
					Counted		( _Type* obj );
					~Counted	( void );
public:
	inline uint		AddRef		( void );
	inline uint		DelRef		( void );
	inline uint		Count		( void ) const;
	
	inline _Type*	GetRef		( void ) const;

private:
	mutable _Type* 	_ptr;
	uint			_count;
};

#include "Counted.inl"

#endif // __INCLUDED_JOTUN_Counted_h