#include "GameObjectExitCommand.h"
#include "GameObject.h"

GameObjectExitCommand::GameObjectExitCommand(GameObject* go)
{
	ptrGO = go;
}

void GameObjectExitCommand::execute()
{
	ptrGO->DisconnectFromScene();
}