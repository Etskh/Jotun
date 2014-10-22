#pragma once


#include <string>
#include <vector>
#include "System.h"


class Application
{
protected:
					Application	( const char* name );
public:
	virtual		~Application	( void );

public:
	template < class _System >
	void			Load			( SmrtPtr< _System > sys );
	void			Load			( HSystem sys );

public:
	virtual void	Run				( void );
	virtual void	Close			( void );

public:
	virtual void	OnUpdate		( float deltaTime ) = 0;

public:
	const char*	GetName		( void ) const;

private:
	std::string	_name;
	bool		_run;

	std::vector<HSystem>	_systems;
};

#include "Application.inl"
