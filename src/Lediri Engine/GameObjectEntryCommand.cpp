#include "GameObjectEntryCommand.h"
#include "GameObject.h"

GameObjectEntryCommand::GameObjectEntryCommand(GameObject* go)
{
	ptrGO = go;
}

void GameObjectEntryCommand::execute()
{
	ptrGO->ConnectToScene();
}