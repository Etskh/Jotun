

#include <string.h> // for memset

#include "Device.h"

#include "core/Colour.h"


bool CheckSDLError( bool bCondition, const char* szCondition, const char* errorMsg, const char* file, int line ) {
	if( bCondition ) {
		return true;
	}
	else {
		char buffer[1024];

		sprintf( buffer, "%s failed in %s at line %d\n%s SDL_Error:\n  %s\n", szCondition, file, line, errorMsg, SDL_GetError() );

		SDL_ShowSimpleMessageBox( SDL_MESSAGEBOX_ERROR, errorMsg, buffer, NULL );
	}
	return false;
}
#define CHECK_SDL( condition, errorMsg ) CheckSDLError(condition, #condition, errorMsg, __FILE__, __LINE__)





DeviceConstructor::DeviceConstructor ( void )
{
	memset( this, 0, sizeof(DeviceConstructor));
}



Device::Device ( const DeviceConstructor& dconst )
	: _window( NULL )
	, _run ( false )
{
	//Initialize SDL
	if( CHECK_SDL( (SDL_Init( SDL_INIT_VIDEO ) >= 0), "Couldn't initialize SDL") ) {

		//Create window
		_window = SDL_CreateWindow(
			dconst.title?dconst.title:"Device",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			dconst.width?dconst.width:640,
			dconst.height?dconst.height:480,
			SDL_WINDOW_SHOWN
			);

		if( CHECK_SDL( (_window != NULL), "Window could not be created!")  ) {
			_run = true;

			// Window is created
		}
	}
}


Device::~Device ( void )
{
	// Destroy the window if we have one
	if( _window ) {
		SDL_DestroyWindow( _window );
	}

	//Quit SDL subsystems
	SDL_Quit();
}



void	Device::MessageBoxError( const char* title, const char* message )
{
	SDL_ShowSimpleMessageBox( SDL_MESSAGEBOX_ERROR, title, message, NULL );
}



void	Device::Sleep	( float )
{
	/*SDL_semaphore semaphore;

	SDL_SemWaitTimeout( &semaphore, (uint)(seconds*1000.f) );
	*/
}



bool		Device::Run ( void )
{
	// The default colour
	const core::Colour background = core::Colour::SlateGrey;

	//The surface contained by the window
	SDL_Surface* screenSurface = NULL;
	SDL_Event event;

	// If we have a run and window
	//
	if( _window ) {
		//Get window surface
		screenSurface = SDL_GetWindowSurface( _window  );

		//Fill the surface white
		SDL_FillRect( screenSurface, NULL, SDL_MapRGB(
				screenSurface->format,
				background.red8(),
				background.green8(),
				background.blue8()
				));

		//Update the surface
		SDL_UpdateWindowSurface( _window );

		while(SDL_PollEvent(&event))
		{
			switch(event.type) {

			case SDL_QUIT:
				_run = false;
				break;
			}
		}
		return _run;
	}

	return false;
}



