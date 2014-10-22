
#include <assert.h>

template<typename _Type>
SmrtPtr<_Type>::SmrtPtr		( void )
	: _ref( new Counted<_Type>() )
{
	// empty
}

template<typename _Type>
SmrtPtr<_Type>::SmrtPtr			( _Type* obj )
	: _ref( new Counted<_Type>(obj) )
{
	// empty
}

template<typename _Type>
SmrtPtr<_Type>::SmrtPtr			( const _Type*& obj )
	: _ref( new Counted<_Type>(obj) )
{
	// empty
}

template<typename _Type>
SmrtPtr<_Type>::SmrtPtr			( const SmrtPtr& ref )
	: _ref( ref._ref )
{
	_ref->AddRef();
}

template<typename _Type>
SmrtPtr<_Type>::~SmrtPtr		( void )
{
	_ref->DelRef();
}

template<typename _Type>
SmrtPtr<_Type>&	SmrtPtr<_Type>::operator=		( const SmrtPtr& ref )
{
	_ref->DelRef();
	_ref = ref._ref;
	_ref->AddRef();
	
	return *this;
}

template<typename _Type>
_Type*		SmrtPtr<_Type>::operator->		( void )
{
	assert( _ref->GetRef() != 0 );
	return _ref->GetRef();
}

template<typename _Type>
const _Type*		SmrtPtr<_Type>::operator->	( void ) const
{
	assert( _ref->GetRef() != 0 );
	return _ref->GetRef();
}

template<typename _Type>
_Type&		SmrtPtr<_Type>::operator*		( void )
{
	assert( _ref->GetRef() != 0 );
	return * ( _ref->GetRef() );
}

template<typename _Type>
_Type*		SmrtPtr<_Type>::ptr				( void )
{
	return _ref->GetRef();
}


template<typename _Type>
bool		SmrtPtr<_Type>::operator==		( const SmrtPtr& ref )
{
	return ( ref._ref == _ref );
}

template<typename _Type>
			SmrtPtr<_Type>::operator bool	( void ) const
{
	return ( _ref != 0 && _ref->Count() > 0 );
}
