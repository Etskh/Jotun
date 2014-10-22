#pragma once


#include "SmrtPtr.h"



template < class _HostClass, class _AttributeClass >
class TAttribute
{
public:
	typedef SmrtPtr<_AttributeClass> H_AttributeClass;
public:
				TAttribute			( _HostClass* host );
	virtual		~TAttribute			( void ){}

public:
	virtual const char*	GetType		(void) = 0;

protected:
	_HostClass*	GetHost				( void );

private:
	_HostClass*	_host;

	friend class THost<_HostClass,_AttributeClass>;
};
