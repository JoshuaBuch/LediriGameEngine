#ifndef ALARMREGISTRATIONCOMMAND_H
#define ALARMREGISTRATIONCOMMAND_H

#include "CommandBase.h"
#include "AlarmObjectManager.h"

class AlarmObject;

class AlarmRegistrationCommand : public CommandBase
{
public:
	AlarmRegistrationCommand(AlarmObject* alarmObject, AlarmObjectManager::ALARM_ID id);
	AlarmRegistrationCommand(const AlarmRegistrationCommand&) = delete;
	AlarmRegistrationCommand& operator=(const AlarmRegistrationCommand&) = delete;
	~AlarmRegistrationCommand(); //base class has to have virtual destructor

	void execute();
	void setAlarmTimer(float t);

private:
	float alarmTimer;
	AlarmObject* ptrAO;
	AlarmObjectManager::ALARM_ID alarm_id;
};
#endif // !ALARMREGISTRATIONCOMMAND_H
