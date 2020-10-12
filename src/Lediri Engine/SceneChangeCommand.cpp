#include "SceneChangeCommand.h"
#include "SceneManager.h"

SceneChangeCommand::SceneChangeCommand()
{
	//ptrScene = s;
}

void SceneChangeCommand::execute()
{
	SceneManager::SetScene(ptrScene);
}

void SceneChangeCommand::SetScene(Scene* s)
{
	ptrScene = s;
}