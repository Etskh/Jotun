#include "Container.h"

#include "core/Assert.h"


using namespace gui;
using namespace component;




Container::Container		( Widget* hostWidget )
	: Component(hostWidget)
{
	// empty
}

Container::~Container		( void )
{
	// empty
}




bool			Container::Add				( HWidget widget )
{
	_children.push_back( widget );
	return true;
}

HWidget			Container::At				( unsigned int index )
{
	ASSERT( index < _children.size() );
	return _children[index];
}

unsigned int	Container::Count			( void ) const
{
	return _children.size();
}
