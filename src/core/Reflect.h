#ifndef __INCLUDED_JOTUN_Reflect_h
#define __INCLUDED_JOTUN_Reflect_h




class Callback
{
public:

};



template <class _Host, class _Return, class ... _Args>
class GCallback
	: public Callback
{

};



class MCallback
	: public Callback
{

};



#endif // __INCLUDED_JOTUN_Reflect_h
