#pragma once

#include "core/HostAttribute.h"
#include "core/SmrtPtr.h"

namespace gui {

class Component;

class Widget
	: public THost< gui::Widget, gui::Component>
{
public:
				Widget				( void );
	virtual		~Widget				( void );
public:
	const char*	GetID				( void );
	bool		HasID				( const char* id );
	void		SetID				( const char* id );

public:
	void		On					( void );

public:
	template <class _Component, class ... _Args>
	bool		AddComponent		( _Args ... args  );
	template <class _Component>
	_Component*	Get					( void );

private:
	std::string _id;
};
typedef SmrtPtr<Widget>	HWidget;


} // namespace gui
