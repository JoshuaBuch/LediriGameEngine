#include "InputDeregistrationCommand.h"
#include "InputObject.h"
#include "InputObjectAttorney.h"

InputDeregistrationCommand::InputDeregistrationCommand(InputObject* io)
{
	ptrIO = io;
}

void InputDeregistrationCommand::execute()
{
	InputObjectAttorney::Registration::SceneDeregistration(ptrIO, key, myIET);
	delete this;
}

void InputDeregistrationCommand::KeyNInputTypeSet(AZUL_KEY k, INPUT_EVENT_TYPE iet)
{
	key = k;
	myIET = iet;
}

InputDeregistrationCommand::~InputDeregistrationCommand()
{
	//DebugMsg::out("\nInputDeregistrationCommand being deleted");
}