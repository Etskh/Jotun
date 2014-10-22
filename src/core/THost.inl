

#include "core/Patterns.h"

#include <utility>


template< class _HostClass, class _AttributeClass>
template< class _Attribute>
bool		THost<_HostClass,_AttributeClass>::AddAttribute( void )
{
	// TODO: assert that _Attribute is a subclass or class of _AttributeClass
	H_AttributeClass hac (new _Attribute( static_cast<_HostClass*>( this ) ) );
	_attributes.push_back( hac );
	return true;
}

template< class _HostClass, class _AttributeClass>
template< class _Attribute, class ... _Args>
bool		THost<_HostClass,_AttributeClass>::AddAttribute( _Args ... args)
{
	// TODO: assert that _Attribute is a subclass or class of _AttributeClass
	H_AttributeClass hac (new _Attribute( static_cast<_HostClass*>(this), args... ) );
	_attributes.push_back( hac );
	return true;
}


template< class _HostClass, class _AttributeClass>
template< class _Attribute>
_Attribute*	THost<_HostClass,_AttributeClass>::GetAttribute( void )
{
	uint hash = jotun::Hash( _Attribute::GetName() );
	// TODO: assert that _Attribute is a subclass or class of _AttributeClass
	for( uint a=0; a< _attributes.size(); a++ ) {
		if( hash == jotun::Hash( _attributes[a]->GetType() ) ) {
			return static_cast<_Attribute*>(&(*(_attributes[a])));
		}
	}
	return NULL;
}

template< class _HostClass, class _AttributeClass>
unsigned int THost<_HostClass,_AttributeClass>::GetAttributeCount( void ) const
{
	return _attributes.size();
}

