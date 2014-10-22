#pragma once

#include <string>


class Application;

class System
{
public:
					System ( Application* owner, const char* sysName );
	virtual		~System ( void );

public:


private:
	//Application*	_owner;
	std::string		_name;
};


#include "core/SmrtPtr.h"

typedef SmrtPtr<System> HSystem;
