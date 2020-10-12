#include "DrawObject.h"
#include "SceneManager.h"
#include "AzulCore.h"
#include "DrawRegistrationCommand.h"
#include "DrawDeregistrationCommand.h"

DrawObject::DrawObject()
{
	pRegCmd = new DrawRegistrationCommand(this);
	pDeregCmd = new DrawDeregistrationCommand(this);

	curRegState = RegistrationState::CURRENTLY_DEREGISTERED;
}

void DrawObject::SubmitDrawRegistration()
{
	assert(curRegState == RegistrationState::CURRENTLY_DEREGISTERED);

	//DebugMsg::out("\nSubmitting to draw registration");

	SceneManager::getCurScene()->SubmitCommand(pRegCmd);
	curRegState = RegistrationState::PENDING_REGISTRATION;
}

void DrawObject::SubmitDrawDeregistration()
{
	assert(curRegState == RegistrationState::CURRENTLY_REGISTERED);

	//DebugMsg::out("\nSubmitting to draw deregistration");

	SceneManager::getCurScene()->SubmitCommand(pDeregCmd);
	curRegState = RegistrationState::PENDING_DEREGISTRATION;
}

void DrawObject::SceneRegistration()
{
	assert(curRegState == RegistrationState::PENDING_REGISTRATION);
	SceneManager::getCurScene()->Register(this);
	curRegState = RegistrationState::CURRENTLY_REGISTERED;
}

void DrawObject::SceneDeregistration()
{
	assert(curRegState == RegistrationState::PENDING_DEREGISTRATION);
	SceneManager::getCurScene()->Deregister(this->pDODeleteRef);
	curRegState = RegistrationState::CURRENTLY_DEREGISTERED;
}

void DrawObject::SetIteratorRef(StorageListRef ref)
{
	this->pDODeleteRef = ref;
}

DrawObject::~DrawObject()
{
	//DebugMsg::out("\nDrawObject is being destroyed (objects command should be as well)");
	delete pRegCmd;
	delete pDeregCmd;
}