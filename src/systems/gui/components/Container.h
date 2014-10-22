#pragma once




#include "systems/gui/GUI.h"

namespace gui {

namespace component {

	class Container
		: public Component
	{
		COMPONENT(Container)
	public:
						Container		( Widget* hostWidget );
		virtual			~Container		( void );

	public:
		bool			Add				( HWidget widget );
		HWidget			At				( unsigned int index );
		unsigned int	Count			( void ) const;

	private:
		std::vector<HWidget>	_children;
	};

} // namespace component

} // namespace gui
