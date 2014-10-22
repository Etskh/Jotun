

#include "Application.h"

#include "platform/Device.h"


Application::Application ( const char* name )
	: _name( name )
	, _run ( true )
{
	// empty
}


Application::~Application ( void )
{
	// empty
}


void	Application::Run	( void )
{
	float delta = 0.016f;

	while ( _run ) {

		this->OnUpdate(delta);

		Device::Sleep( delta );
	}
}


void	Application::Close	( void )
{
	_run = false;
}


const char* Application::GetName ( void ) const
{
	return _name.c_str();
}





void		Application::Load		( HSystem sys )
{
	_systems.push_back( sys );
}



