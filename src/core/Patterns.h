#ifndef __INCLUDED_JOTUN_Patterns_h
#define __INCLUDED_JOTUN_Patterns_h

//
// SAFE_DELETE_x
//
#ifndef SAFE_DELETE
#	define SAFE_DELETE(x) if(x!=NULL){delete x; x=NULL;}
#endif // SAFE_DELETE
#ifndef SAFE_DELETE_ARRAY
#	define SAFE_DELETE_ARRAY(a) if(a!=NULL){delete[] a; a=NULL;}
#endif // SAFE_DELETE_ARRAY
#define SAFE_DELETE_STDVECTOR(v) for(size_t i=0; i<v.size(); i++) { if(v[i]!=NULL){delete v[i]; v[i]=NULL;} } v.clear()


//
// DISALLOW_COPY_AND_ASSIGN( IInterface )
//
#ifndef DISALLOW_COPY_AND_ASSIGN
#	define DISALLOW_COPY_AND_ASSIGN(cls) private: cls( const cls & ref ); cls & operator= ( const cls & ref );
#	define INTERFACE_CLASS(cls) DISALLOW_COPY_AND_ASSIGN(cls)
#endif // DISALLOW_COPY_AND_ASSIGN

//
// JOTUN_UNUSED_PARAMETER
//
#ifndef JOTUN_UNUSED_PARAMETER
#	define JOTUN_UNUSED_PARAMETER(x) x;
#endif // JOTUN_UNUSED_PARAMETER


//
// OUT
//
#ifndef OUT
#	define OUT
#endif // OUT


//
// A quick n' dirty hash function
//
namespace jotun {

//
// Our very own Hashifier! Hash all the things!
//
unsigned long Hash		(const char* str );

//
// For the asserts
//
const bool NOT_IMPLEMENTED	= false;
const bool BIG_PROBLEM		= false;


} // namespace jotun


//
// Short-name types
//
typedef unsigned int	uint;
typedef unsigned short	ushort;
typedef unsigned long ulong;
typedef unsigned char	uchar;
typedef unsigned char	ubyte;
typedef unsigned char	byte;









#endif // __INCLUDED_JOTUN_Patterns_h
