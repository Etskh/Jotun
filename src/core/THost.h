#pragma once


#include <vector>

#include "SmrtPtr.h"



template < class _HostClass, class _AttributeClass>
class THost
{
	typedef SmrtPtr<_HostClass> H_HostClass;
	typedef SmrtPtr<_AttributeClass> H_AttributeClass;
public:
				THost				( void ){}
protected:
	template< class _Attribute>
	bool		AddAttribute		( void );
	template< class _Attribute, class ... _Args>
	bool		AddAttribute		( _Args ... args );
	template< class _Attribute>
	_Attribute*	GetAttribute		( void );

	unsigned int	GetAttributeCount( void ) const;


private:
	std::vector<H_AttributeClass>	_attributes;
};
