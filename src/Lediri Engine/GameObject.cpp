#include "GameObject.h"
#include "GameObjectEntryCommand.h"
#include "GameObjectExitCommand.h"
#include "SceneManager.h"

GameObject::GameObject()
{
	pRegCmd = new GameObjectEntryCommand(this);
	pDeregCmd = new GameObjectExitCommand(this);

	curRegState = RegistrationState::CURRENTLY_DEREGISTERED;
}

void GameObject::SubmitEntry()
{
	assert(curRegState == RegistrationState::CURRENTLY_DEREGISTERED);
	SceneManager::getCurScene()->SubmitCommand(pRegCmd);
	curRegState = RegistrationState::PENDING_REGISTRATION;

}

void GameObject::SubmitExit()
{
	assert(curRegState == RegistrationState::CURRENTLY_REGISTERED);
	SceneManager::getCurScene()->SubmitCommand(pDeregCmd);
	curRegState = RegistrationState::PENDING_DEREGISTRATION;
}

void GameObject::ConnectToScene()
{
	assert(curRegState == RegistrationState::PENDING_REGISTRATION);
	curRegState = RegistrationState::CURRENTLY_REGISTERED;
	this->SceneEntry();
}

void GameObject::DisconnectFromScene()
{
	assert(curRegState == RegistrationState::PENDING_DEREGISTRATION);
	curRegState = RegistrationState::CURRENTLY_DEREGISTERED;
	this->SceneExit();
}

GameObject::~GameObject()
{
	delete pRegCmd;
	delete pDeregCmd;

}