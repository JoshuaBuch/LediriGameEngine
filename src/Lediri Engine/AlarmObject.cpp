#include "AlarmObject.h"
#include "AzulCore.h"
#include "SceneManager.h"
#include "AlarmRegistrationCommand.h"
#include "AlarmDeregistrationCommand.h"

AlarmObject::AlarmObject()
{

	for (int i = 0; i < AlarmObjectManager::ALARM_NUMBER; i++)
	{
		this->RegData[i].pRegCmd = new AlarmRegistrationCommand(this, (AlarmObjectManager::ALARM_ID)i);
		this->RegData[i].pDeregCmd = new AlarmDeregistrationCommand(this, (AlarmObjectManager::ALARM_ID)i);
		this->RegData[i].curRegState = RegistrationState::CURRENTLY_DEREGISTERED;
	}

	
}

void AlarmObject::SubmitAlarmRegistration(float t, AlarmObjectManager::ALARM_ID id)
{
	assert(this->RegData[id].curRegState == RegistrationState::CURRENTLY_DEREGISTERED);
	//DebugMsg::out("\nSubmitting to alarm registration");
	this->RegData[id].pRegCmd->setAlarmTimer(t);
	SceneManager::getCurScene()->SubmitCommand(this->RegData[id].pRegCmd);
	this->RegData[id].curRegState = RegistrationState::PENDING_REGISTRATION;
}

void AlarmObject::SubmitAlarmDeregistration(AlarmObjectManager::ALARM_ID id)
{
	assert(this->RegData[id].curRegState == RegistrationState::CURRENTLY_REGISTERED);
	//DebugMsg::out("\nSubmitting to 
	// alarm deregistration");
	SceneManager::getCurScene()->SubmitCommand(this->RegData[id].pDeregCmd);
	this->RegData[id].curRegState = RegistrationState::PENDING_DEREGISTRATION;

}

void AlarmObject::AlarmRegistration(float t, AlarmObjectManager::ALARM_ID id)
{
	assert(this->RegData[id].curRegState == RegistrationState::PENDING_REGISTRATION);
	SceneManager::getCurScene()->Register(t, this, id);
	this->RegData[id].curRegState = RegistrationState::CURRENTLY_REGISTERED;
}

void AlarmObject::AlarmDeregistration(AlarmObjectManager::ALARM_ID id)
{
	assert(this->RegData[id].curRegState == RegistrationState::PENDING_DEREGISTRATION);
	SceneManager::getCurScene()->Deregister(this->RegData[id].pMyDeleteRef);
	this->RegData[id].curRegState = RegistrationState::CURRENTLY_DEREGISTERED;
}


void AlarmObject::SetIteratorRef(AlarmObjectManager::StorageMapRef ref, AlarmObjectManager::ALARM_ID id)
{
	this->RegData[id].pMyDeleteRef = ref;
}

void AlarmObject::TriggerAlarm(AlarmObjectManager::ALARM_ID id)
{

	this->RegData[id].curRegState = RegistrationState::CURRENTLY_DEREGISTERED;
	switch (id)
	{
	case AlarmObjectManager::ALARM_0:
		this->Alarm0();
		break;
	case AlarmObjectManager::ALARM_1:
		this->Alarm1();
		break;
	case AlarmObjectManager::ALARM_2:
		this->Alarm2();
		break;
	case AlarmObjectManager::ALARM_3:
		this->Alarm3();
		break;
	case AlarmObjectManager::ALARM_4:
		this->Alarm4();
		break;
	}
}
AlarmObject::~AlarmObject()
{
	//we do need to delete these alarms somewhere
	DebugMsg::out("\nAlarmObject being destroyed");
	for (int i = 0; i < AlarmObjectManager::ALARM_NUMBER; i++)
	{
		if (this->RegData[i].pRegCmd != nullptr)
		{
			delete this->RegData[i].pRegCmd;
			delete this->RegData[i].pDeregCmd;
		}

	}
}