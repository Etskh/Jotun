#pragma once



#include <SDL2/SDL.h>


#include "core/SmrtPtr.h"


struct DeviceConstructor
{
	const char* title;
	unsigned int width;
	unsigned int height;

	DeviceConstructor ( void );
};



class Device
{
public:
					Device		( const DeviceConstructor& dconst );
	virtual		~Device	( void );

public:
	//void			OnRender	( Callback callback );


public:
	bool			Run			( void );



public:
	static void	MessageBoxError ( const char* title, const char* message );
	static void	Sleep	( float milliseconds );


private:

	SDL_Window*		_window;
	bool			_run;
};


typedef SmrtPtr<Device> HDevice;
