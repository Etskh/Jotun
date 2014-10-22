#pragma once


#include "core/math/Vector.h"
#include "core/Colour.h"

////////////////////////////////////////////////////////////////////
//
// Parameter.h
//
class Parameter
{
public:
	//
	// Some fun values
	//
	enum Type {
		Float,
		Vector,
		Colour,
		Color=Colour,
		Matrix,
		Texture,
		Invalid
	};
	//
	// Quick-hand purposes
	// it helps us remove some boiler-plate
	//
	enum Purpose {
		None,
		WorldView,
		Projection,
		Position
	};
	
private:
	//
	// class Instance
	//
	class Instance
	{
	public:
		//
		// The handle to the Instance
		//
		typedef std::shared_ptr<Instance> Handle; // TODO - change this to: typedef SmrtPtr<Instance> Handle;
		
	public:
		//
		// Best friends!
		//
		friend class Parameter;
		
	public:
		//
		// Complicated things
		//
		const char*		 name				( void ) const;
		const Parameter* host				( void ) const;
		//
		// Rendering business
		//
		bool			MakeActive			( void );
		bool			SetValue			( float value );
		bool			SetValue			( core::Vector3& vector );
		bool			SetValue			( core::Colour& colour );
		bool			SetValue			( core::Matrix4& matrix );
		bool			SetValue			( Texture::Handle texture );
		
	public:
						~Instance			( void );		
	private:
						Instance			( const Parameter* host );
	private:
		const Parameter*	_host;
		void*				_data;
	};
	
public:
	//
	// And a little shorthand for everyone else
	//
	typedef Instance::Handle HInstance;
	
	
public:
	//
	// This is the useful bits
	//
						Parameter		( void );
						Parameter		( const char* name, Type type, Purpose purpose );
						~Parameter		( void );
	HInstance			CreateInstance	( void );
	
public:
	const char*			name			( void ) const;
	Type				type			( void ) const;
	uint				size			( void ) const;
	Purpose				purpose			( void ) const;
	
	
private:
	std::string				_name;
	Type					_type;
	uint					_size;
	Purpose					_purpose;
};


