
#include "core/Assert.h"



template<typename _Type>
core::List<_Type>::List		( void )
{
	// empty
}

template<typename _Type>
core::List<_Type>::List			( const List& ref )
	: _data ( ref._data )
{
	//empty
}


template<typename _Type>
core::List<_Type>::List			( const _Type* array, uint count )
{
	for( int i=0; i < count; i++) {
		_data.push_back( array[i] );
	}
}


template<typename _Type>
core::List<_Type>::~List			( void )
{
	//empty
}


template<typename _Type>
core::List<_Type>&			core::List<_Type>::operator=		( const List& ref )
{
	_data = ref._data;
	
	return *this;
}

template<typename _Type>
core::List<_Type>&			core::List<_Type>::operator+=		( const List& ref )
{
	for(uint s=0; s< ref.size(); s++) {
		_data.push_back( ref[s] );
	}
	
	return *this;
}

template<typename _Type>
core::List<_Type>			core::List<_Type>::operator+		( const List& ref )
{
	List<_Type> newList(*this);
	
	newList += ref;
	
	return newList;
}



template<typename _Type>
uint			core::List<_Type>::size			( void ) const
{
	return _data.size();
}


template<typename _Type>
typename core::List<_Type>::iterator		core::List<_Type>::begin		( void )
{
	return _data.begin();
}

template<typename _Type>
typename core::List<_Type>::iterator		core::List<_Type>::end			( void )
{
	return _data.end();
}

template<typename _Type>
_Type&			core::List<_Type>::operator[]		( int index )
{
	ASSERT( index >= 0 );
	return _data[index];
}

template<typename _Type>
const _Type&	core::List<_Type>::operator[]		( int index ) const
{
	ASSERT( index >= 0 );
	return _data[index];
}


template<typename _Type>
core::List<_Type>&			core::List<_Type>::operator+=		( const _Type& ref )
{
	_data.push_back( ref );
	
	return *this;
}

/*template<typename _Type>
core::List<_Type>&			core::List<_Type>::operator+=		( _Type val )
{
	_data.push_back( val );
	
	return *this;
}*/

template<typename _Type>
void			core::List<_Type>::push_back		( const _Type& ref )
{
	_data.push_back( ref );
}

/*template<typename _Type>
void			core::List<_Type>::push_back		( _Type val )
{
	_data.push_back( val );
}*/

template<typename _Type>
void			core::List<_Type>::Add				( const _Type& ref )
{
	_data.push_back( ref );
}

/*template<typename _Type>
void			core::List<_Type>::Add				( _Type val )
{
	_data.push_back( val );
}*/



template<typename _Type>
_Type&			core::List<_Type>::back			( void )
{
	return _data.back();
}

