#include "SceneManager.h"
#include "SceneNull.h"
#include "SceneChangeNullCommand.h"
#include "SceneChangeCommandBase.h"
#include "SceneChangeCommand.h"

SceneManager* SceneManager::ptrInstance = nullptr;

SceneManager::SceneManager()
{
	curScene = new SceneNull();
	pSceneChangeCmd = new SceneChangeCommand();
	pSceneNullCmd = new SceneChangeNullCommand();
	pCurSceneCmd = pSceneNullCmd;
}

void SceneManager::privSetNextScene(Scene* s)
{
	pSceneChangeCmd->SetScene(s);
	pCurSceneCmd = pSceneChangeCmd;
}

void SceneManager::SetScene(Scene* s)
{
	DeleteScene();
	Instance().curScene = s;
	Instance().curScene->Initialize();
	Instance().pCurSceneCmd = Instance().pSceneNullCmd;
}

void SceneManager::privInitialize()
{
	curScene->Initialize();
}

void SceneManager::privUpdate()
{
	curScene->Update();
	pCurSceneCmd->execute();
}

void SceneManager::privDraw()
{
	curScene->Draw();
}

void SceneManager::privDeleteScene()
{
	curScene->SceneEnd();
	delete curScene;
	curScene = nullptr;
}

void SceneManager::privDeleteSceneManager()
{
	//Delete the scenemanager instance pointer
	delete ptrInstance;
	ptrInstance = nullptr;
}

Scene* SceneManager::privGetCurScene()
{
	return curScene;
}

SceneManager::~SceneManager()
{
	//Delete SceneChangeCommand
	delete pSceneChangeCmd;
	pSceneChangeCmd = nullptr;


	//Delete SceneChangeNullCommand
	delete pSceneNullCmd;
	pSceneNullCmd = nullptr;

	//Clean up and delete current scene on exit

	curScene->SceneEnd();
	delete curScene;
	curScene = nullptr;






}