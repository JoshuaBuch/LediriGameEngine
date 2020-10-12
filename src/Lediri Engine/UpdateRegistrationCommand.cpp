#include "UpdateRegistrationCommand.h"
#include "UpdateObject.h"
#include "UpdateObjectAttorney.h"

UpdateRegistrationCommand::UpdateRegistrationCommand(UpdateObject* updateObject)
{
	ptrUO = updateObject;
}

void UpdateRegistrationCommand::execute()
{
	UpdateObjectAttorney::Registration::SceneRegistration(ptrUO);
}

UpdateRegistrationCommand::~UpdateRegistrationCommand()
{
	//DebugMsg::out("\nUpdateRegistrationCommand being deleted");
}