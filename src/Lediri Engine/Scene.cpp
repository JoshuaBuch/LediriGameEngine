#include "Scene.h"
#include "Lediri.h"

Scene::Scene()
{

}

void Scene::Initialize()
{
}

void Scene::SubmitCommand(CommandBase* cmd)
{
	sceneBroker.addCommand(cmd);
}

void Scene::SubmitVisualizerCommand(CommandBase* cmd)
{
	visualBroker.addCommand(cmd);
}

void Scene::Register(UpdateObject* up)
{
	UOMan.Register(up);
}

void Scene::Deregister(UpdateObjectManager::StorageListRef ref)
{
	UOMan.Deregister(ref);
}

void Scene::Register(DrawObject * dr)
{
	DOMan.Register(dr);
}

void Scene::Deregister(DrawObjectManager::StorageListRef ref)
{
	DOMan.Deregister(ref);
}

void Scene::Register(float t, AlarmObject* al, AlarmObjectManager::ALARM_ID id)
{
	AOMan.Register(t, al, id);
}

void Scene::Deregister(AlarmObjectManager::StorageMapRef& ref)
{
	AOMan.Deregister(ref);
}

void Scene::Register(InputObject* io, AZUL_KEY k, INPUT_EVENT_TYPE iet)
{
	k; //must be changed to use the Keyboardeventmanager
	KbEM.Register(io, k, iet);
}

void Scene::Deregister(InputObject* pIO, AZUL_KEY k, INPUT_EVENT_TYPE iet)
{
	k; //must be changed to use the Keyboardeventmanager
	KbEM.Deregister(pIO, k, iet);
}

void Scene::Update()
{
	sceneBroker.executeCommands();
	AOMan.ProcessAlarms();
	UOMan.ProcessElements();
	KbEM.ProcessKeyEvents();
	COMan.ProcessCollisions();
	CamMan.GodCameraUpdate();
}

void Scene::Draw()
{
	visualBroker.executeCommands();
	DOMan.ProcessElements();
}

Camera* Scene::GetCurCam()
{
	return (CamMan.GetCurCam());
}

Camera* Scene::GetSpriteCam()
{
	return (CamMan.GetSpriteCam());
}

void Scene::SetDefaultCamera()
{
	CamMan.SetDefaultCam();
}

void Scene::SetGodCam()
{
	CamMan.SetGodCamera();
}

void Scene::UnsetGodCam()
{
	CamMan.UnsetGodCamera();
}

Scene::~Scene()
{
	DebugMsg::out("\n\nDeleting scene object");
}