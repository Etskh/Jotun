#pragma once

#include "core/SmrtPtr.h"

#include "jotun/System.h"

#include "platform/Device.h"

//#include "systems/gfx/GfxSystem.h"


#include "GUI.h"


namespace gui {

class GUISystem : public System
{
public:

				GUISystem			( Application* app);
	virtual		~GUISystem			( void );


public:
	HWidget		GetRootWidget		( void );


	bool		ConsolePrint		( const char* str );



private:
	//SmrtPtr<GfxSystem>	gfx;

	HWidget _root;
};


} // namespace gui

