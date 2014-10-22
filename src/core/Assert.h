#ifndef __INCLUDED_JOTUN_Assert_h
#define __INCLUDED_JOTUN_Assert_h

namespace core {

void Assert( bool val, const char* valStr, const char* file, unsigned int line, const char* callingFunc );

} // namespace core

#include "core/Compiler.h"

#ifdef JOTUN_DEBUG
#	define ASSERT(x) core::Assert( !(!(x)), #x, JOTUN_FILE, JOTUN_LINE, JOTUN_FUNC );
#else
#	define ASSERT(x)
#endif

#endif // __INCLUDED_JOTUN_Assert_h