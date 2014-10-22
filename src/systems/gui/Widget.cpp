

#include "core/Assert.h"

#include "GUI.h"

using namespace gui;


Widget::Widget				( void )
{
	// empty
}

Widget::~Widget			( void )
{
	// empty
}



const char*	Widget::GetID		( void )
{
	return _id.c_str();
}
bool		Widget::HasID		( const char* id )
{
	return jotun::Hash( id ) == jotun::Hash( _id.c_str() );
}
void		Widget::SetID		( const char* id )
{
	ASSERT( id != NULL );
	_id = id;
}

