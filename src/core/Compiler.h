#ifndef __INCLUDED_JOTUN_Compiler_h
#define __INCLUDED_JOTUN_Compiler_h

#ifdef DEBUG
#	define JOTUN_DEBUG
#endif // DEBUG


#define JOTUN_FILE	__FILE__
#define JOTUN_LINE	__LINE__

#ifdef __GNUC__
#	define JOTUN_FUNC __PRETTY_FUNCTION__
#	define JOTUN_DEBUG_STOP	asm("int $3");
#else
#	ifdef _MSC_VER
#		define JOTUN_FUNC __FUNCSIG__
#		define JOTUN_DEBUG_STOP	__asm{ int 3 };
#		pragma warning(disable:4996) // stupid sprintf_s stuff
#		pragma warning(disable:4201) // nameless structs
#	else
		static_assert(false, "Unknown compiler!");
#	endif // _MSC_VER
#endif // __GNUC__





#endif // __INCLUDED_JOTUN_Compiler_h