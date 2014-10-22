
template<typename _Type>
Counted<_Type>::Counted		( void )
	: _ptr(0)
	, _count(0)
{
	// empty
}

template<typename _Type>
Counted<_Type>::Counted		( _Type* obj )
	: _ptr(obj)
	, _count(1)
{
	// empty
}

#include <cstdio>

template<typename _Type>
Counted<_Type>::~Counted	( void )
{
	DelRef();
	
	if(_count > 1) {
		puts("Memleak!\n");
	}
}


template<typename _Type>
uint		Counted<_Type>::AddRef	( void )
{
	_count ++;
	return _count;
}

template<typename _Type>
uint		Counted<_Type>::DelRef	( void )
{
	_count --;
	if(_count == 0) {
		if(_ptr != 0 ) {
			delete _ptr;
			_ptr = 0;
		}
	}
	return _count;
}

template<typename _Type>
uint		Counted<_Type>::Count	( void ) const
{
	return _count;
}


template<typename _Type>
_Type*	Counted<_Type>::GetRef		( void ) const
{
	return _ptr;
}

