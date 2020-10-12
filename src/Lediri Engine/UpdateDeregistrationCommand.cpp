#include "UpdateDeregistrationCommand.h"
#include "UpdateObject.h"
#include "UpdateObjectAttorney.h"

UpdateDeregistrationCommand::UpdateDeregistrationCommand(UpdateObject* updateObject)
{
	ptrUO = updateObject;
}

void UpdateDeregistrationCommand::execute()
{
	UpdateObjectAttorney::Registration::SceneDeregistration(ptrUO);
}

UpdateDeregistrationCommand::~UpdateDeregistrationCommand()
{
	//DebugMsg::out("\nUpdateDeregistrationCommand being deleted");
}
