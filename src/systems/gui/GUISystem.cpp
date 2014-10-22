


#include "GUISystem.h"


#include "GUI.h"

#include "components/all.h"

using namespace gui;


GUISystem::GUISystem			( Application* app )
	: System ( app, "GUI System" )
{
	HWidget console;

	_root = new Widget();
	_root->AddComponent<component::Container>();
	_root->AddComponent<component::Metrics>();

	console = new Widget();

	console->SetID("console");

	console->AddComponent<component::Container>();
	console->AddComponent<component::Metrics>();

	console->AddComponent<component::Text>("This doesn't make sense");

	//console->On<action::Update>( console );

	//_root->Get<component::Container>()->Add(console);
}



GUISystem::~GUISystem		( void )
{
	// empty
}

HWidget		GUISystem::GetRootWidget		( void )
{
	return _root;
}


bool		GUISystem::ConsolePrint		( const char* )
{
	//console = _root->GetComponent<ContainerComponent>()->FindChild("console");

	//printf("Got the console's name: '%s'\n", console->GetName());

	return true;
}
