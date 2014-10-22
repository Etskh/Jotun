#pragma once

#include <vector>
#include <string>

#include "core/SmrtPtr.h"
#include "core/HostAttribute.h"

namespace gui {

class Widget;


class Component
	: public TAttribute< gui::Widget, gui::Component>
{
public:
	Component(Widget* hostWidget) : TAttribute(hostWidget) {}
	virtual ~Component(){}

public:


private:
	std::vector<std::string>	_namedValues;

};
typedef SmrtPtr<Component> HComponent;
#define COMPONENT(type) public:	\
	static	const char*	GetName(void) { return #type ; } \
	const char*	GetType(void) { return type::GetName(); }


} // namespace gui

