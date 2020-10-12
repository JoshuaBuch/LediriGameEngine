#include "AlarmRegistrationCommand.h"
#include "AlarmObject.h"
#include "AlarmObjectAttorney.h"
AlarmRegistrationCommand::AlarmRegistrationCommand(AlarmObject* alarmObject, AlarmObjectManager::ALARM_ID id)
{
	ptrAO = alarmObject;
	alarm_id = id;
}

void AlarmRegistrationCommand::execute()
{
	AlarmObjectAttorney::Registration::SceneRegistration(ptrAO, this->alarmTimer, this->alarm_id);
}

void AlarmRegistrationCommand::setAlarmTimer(float t)
{
	this->alarmTimer = t;
}

AlarmRegistrationCommand::~AlarmRegistrationCommand()
{
	//DebugMsg::out("\nAlarmRegistrationCommand being deleted");
}