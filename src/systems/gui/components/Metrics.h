#pragma once




#include "systems/gui/GUI.h"

namespace gui {

namespace component {

	class Metrics
		: public Component
	{
		COMPONENT(Metrics)
	public:
					Metrics		(Widget* hostWidget) : Component(hostWidget) {}
		virtual		~Metrics	(void){}

	public:

	};

} // namespace component

} // namespace gui

