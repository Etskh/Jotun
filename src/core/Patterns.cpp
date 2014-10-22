
#include "Patterns.h"


unsigned long jotun::Hash(const char* str )
{
    unsigned long hash = 0;
    int c = *str;

    while (c != 0) {
        hash = c + (hash << 6) + (hash << 16) - hash;
		c = *str++;
	}
	
    return hash;
}