#include "InputObject.h"
#include "SceneManager.h"
#include "InputRegistrationCommand.h"
#include "InputDeregistrationCommand.h"

InputObject::InputObject()
{

	curRegState = RegistrationState::CURRENTLY_DEREGISTERED;
}

void InputObject::SubmitInputRegistration(AZUL_KEY k, INPUT_EVENT_TYPE iet)
{
	assert(curRegState == RegistrationState::PENDING_REGISTRATION || curRegState == RegistrationState::CURRENTLY_DEREGISTERED);
	//DebugMsg::out("\nSubmitting to input registration");
	pRegCmd = new InputRegistrationCommand(this); //we have to create a new Command because an InputObject can register many keys
	this->pRegCmd->KeyNInputTypeSet(k, iet);
	SceneManager::getCurScene()->SubmitCommand(pRegCmd);
	pRegCmd = nullptr;
	curRegState = RegistrationState::PENDING_REGISTRATION;
}

void InputObject::SubmitInputDeregistration(AZUL_KEY k, INPUT_EVENT_TYPE iet)
{
	assert(curRegState == RegistrationState::CURRENTLY_REGISTERED || curRegState == RegistrationState::PENDING_DEREGISTRATION);
	//DebugMsg::out("\nSubmitting to input deregistration");
	pDeregCmd = new InputDeregistrationCommand(this); //we have to create a new Command because an InputObject can Deregister many keys
	this->pDeregCmd->KeyNInputTypeSet(k, iet);
	SceneManager::getCurScene()->SubmitCommand(pDeregCmd);
	curRegState = RegistrationState::PENDING_DEREGISTRATION;

}
void InputObject::SceneRegistration(AZUL_KEY k, INPUT_EVENT_TYPE iet)
{
	assert(curRegState == RegistrationState::PENDING_REGISTRATION || curRegState == RegistrationState::CURRENTLY_REGISTERED);
	SceneManager::getCurScene()->Register(this, k, iet);
	curRegState = RegistrationState::CURRENTLY_REGISTERED;
}

void InputObject::SceneDeregistration(AZUL_KEY k, INPUT_EVENT_TYPE iet)
{
	assert(curRegState == RegistrationState::PENDING_DEREGISTRATION || curRegState == RegistrationState::CURRENTLY_DEREGISTERED);
	if (iet == INPUT_EVENT_TYPE::KEY_PRESS)
	{
		SceneManager::getCurScene()->Deregister(this, k, iet);
	}
	if (iet == INPUT_EVENT_TYPE::KEY_RELEASE)
	{
		SceneManager::getCurScene()->Deregister(this, k, iet);
	}
	curRegState = RegistrationState::CURRENTLY_DEREGISTERED;
}


InputObject::~InputObject()
{
	//DebugMsg::out("\nInputObject is being destroyed");
}