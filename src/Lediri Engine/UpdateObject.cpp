#include "UpdateObject.h"
#include "SceneManager.h"
#include "AzulCore.h"
#include "UpdateRegistrationCommand.h"
#include "UpdateDeregistrationCommand.h"

UpdateObject::UpdateObject()
{
	pRegCmd = new UpdateRegistrationCommand(this);
	pDeregCmd = new UpdateDeregistrationCommand(this);

	curRegState = RegistrationState::CURRENTLY_DEREGISTERED;
}

void UpdateObject::SubmitUpdateRegistration()
{
	assert(curRegState == RegistrationState::CURRENTLY_DEREGISTERED);
	//DebugMsg::out("\nSubmitting to update registration");

	SceneManager::getCurScene()->SubmitCommand(pRegCmd);
	curRegState = RegistrationState::PENDING_REGISTRATION;
}

void UpdateObject::SubmitUpdateDeregistration()
{
	assert(curRegState == RegistrationState::CURRENTLY_REGISTERED);

	//DebugMsg::out("\nSubmitting to update deregistration");

	SceneManager::getCurScene()->SubmitCommand(pDeregCmd);
	curRegState = RegistrationState::PENDING_DEREGISTRATION;
}

void UpdateObject::SceneRegistration()
{
	assert(curRegState == RegistrationState::PENDING_REGISTRATION);
	SceneManager::getCurScene()->Register(this);
	curRegState = RegistrationState::CURRENTLY_REGISTERED;
}

void UpdateObject::SceneDeregistration()
{
	assert(curRegState == RegistrationState::PENDING_DEREGISTRATION);
	SceneManager::getCurScene()->Deregister(this->pUODeleteRef);
	curRegState = RegistrationState::CURRENTLY_DEREGISTERED;
}

void UpdateObject::SetIteratorRef(StorageListRef ref)
{
	this->pUODeleteRef = ref;
}

UpdateObject::~UpdateObject()
{
	//DebugMsg::out("\nUpdateObject is being destroyed (objects command should be as well)");
	delete pRegCmd;
	delete pDeregCmd;
}