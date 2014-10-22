

template< class _HostClass, class _AttributeClass>
TAttribute<_HostClass,_AttributeClass>::TAttribute( _HostClass* host )
	: _host ( host )
{
	// empty
}

template < class _HostClass, class _AttributeClass >
_HostClass*	TAttribute<_HostClass,_AttributeClass>::GetHost	( void )
{
	return _host;
}

