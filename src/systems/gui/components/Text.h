#pragma once




#include "systems/gui/GUI.h"

namespace gui {

namespace component {

	class Text
			: public Component
		{
			COMPONENT(Text)
		public:
						Text	(Widget* hostWidget) : Component(hostWidget) {}
						Text	(Widget* hostWidget, const char* text) : Component(hostWidget), _text(text) {}
			virtual		~Text	(void){}

		public:
			void		SetText	( const char* text ) { _text = text; }
			const char*	GetText	( void ) { return _text.c_str(); }

		private:
			std::string	_text;
		};

} // namespace component

} // namespace gui

