#include "DrawDeregistrationCommand.h"
#include "DrawObject.h"
#include "DrawObjectAttorney.h"

DrawDeregistrationCommand::DrawDeregistrationCommand(DrawObject* drawObject)
{
	ptrDO = drawObject;
}

void DrawDeregistrationCommand::execute()
{
	DrawObjectAttorney::Registration::SceneDeregistration(ptrDO);
}

DrawDeregistrationCommand::~DrawDeregistrationCommand()
{
	//DebugMsg::out("\nDrawDeregistrationCommand being destroyed");
}
