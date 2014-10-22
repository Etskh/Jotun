
#include "Assert.h"

#include "platform/Device.h"

#include <stdio.h>
#include <stdlib.h>


void core::Assert( bool val, const char* valStr, const char* file, unsigned int line, const char* callingFunc )
{
	if( !val ) {
		char buffer[256];
		sprintf(buffer,"An assertion was triggered!\n\'%s\' turned out was false in %s at line %u from %s.", valStr, file, line, callingFunc );

		Device::MessageBoxError("Assertion", buffer);

		fprintf( stderr, "%s", buffer );

		JOTUN_DEBUG_STOP
	}
}
