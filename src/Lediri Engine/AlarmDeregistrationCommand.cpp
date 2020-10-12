#include "AlarmDeregistrationCommand.h"
#include "AlarmObject.h"
#include "AlarmObjectAttorney.h"

AlarmDeregistrationCommand::AlarmDeregistrationCommand(AlarmObject* alarmObject, AlarmObjectManager::ALARM_ID id)
{
	ptrAO = alarmObject;
	alarm_id = id;
}

void AlarmDeregistrationCommand::execute()
{
	AlarmObjectAttorney::Registration::SceneDeregistration(ptrAO, this->alarm_id);
}

AlarmDeregistrationCommand::~AlarmDeregistrationCommand()
{
	//DebugMsg::out("\nAlarmDeregistrationCommand being deleted");
}