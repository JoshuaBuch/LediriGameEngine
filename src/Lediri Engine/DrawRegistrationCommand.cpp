#include "DrawRegistrationCommand.h"
#include "DrawObject.h"
#include "DrawObjectAttorney.h"

DrawRegistrationCommand::DrawRegistrationCommand(DrawObject* drawObject)
{
	ptrDO = drawObject;
}

void DrawRegistrationCommand::execute()
{
	DrawObjectAttorney::Registration::SceneRegistration(ptrDO);
}

DrawRegistrationCommand::~DrawRegistrationCommand()
{
	//DebugMsg::out("\nDrawRegistrationCommand being deleted");
}