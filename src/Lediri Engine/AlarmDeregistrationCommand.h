#ifndef ALARMDEREGISTRATIONCOMMAND_H
#define ALARMDEREGISTRATIONCOMMAND_H

#include "CommandBase.h"
#include "AlarmObjectManager.h"

class AlarmObject;

class AlarmDeregistrationCommand : public CommandBase
{
public:
	AlarmDeregistrationCommand(AlarmObject* alarmObject, AlarmObjectManager::ALARM_ID id);
	AlarmDeregistrationCommand(const AlarmDeregistrationCommand&) = delete;
	AlarmDeregistrationCommand& operator=(const AlarmDeregistrationCommand&) = delete;
	~AlarmDeregistrationCommand(); //base class has to have virtual destructor

	void execute();
private:

	AlarmObject * ptrAO;
	AlarmObjectManager::ALARM_ID alarm_id;
};
#endif // !ALARMDEREGISTRATIONCOMMAND_H



