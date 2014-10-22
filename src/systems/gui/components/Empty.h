#pragma once




#include "systems/gui/GUI.h"

namespace gui {

namespace component {

	class Empty
		: public Component
	{
		COMPONENT(Empty)
	public:
					Empty		(Widget* hostWidget) : Component(hostWidget) {}
		virtual		~Empty		(void){}
	};

} // namespace component

} // namespace gui

