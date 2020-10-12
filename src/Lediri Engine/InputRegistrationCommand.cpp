#include "InputRegistrationCommand.h"
#include "InputObject.h"
#include "AzulCore.h"
#include "InputObjectAttorney.h"

InputRegistrationCommand::InputRegistrationCommand(InputObject* io)
{
	ptrIO = io;
}

void InputRegistrationCommand::execute()
{
	InputObjectAttorney::Registration::SceneRegistration(ptrIO, key, myIET);
	delete this;
}

void InputRegistrationCommand::KeyNInputTypeSet(AZUL_KEY k, INPUT_EVENT_TYPE iet)
{
	this->key = k;
	this->myIET = iet;
}

InputRegistrationCommand::~InputRegistrationCommand()
{
	//DebugMsg::out("\nInputRegistrationCommand being deleted");
}