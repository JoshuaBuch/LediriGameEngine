#ifndef ALARMOBJECT_H
#define ALARMOBJECT_H

#include "RegistrationStateEnum.h"
#include "AlarmObjectManager.h"

class AlarmRegistrationCommand;
class AlarmDeregistrationCommand;

class AlarmObject
{
public:
	AlarmObject();
	virtual ~AlarmObject();
	virtual void Alarm0() {};
	virtual void Alarm1() {};
	virtual void Alarm2() {};
	virtual void Alarm3() {};
	virtual void Alarm4() {};


protected:
	void SubmitAlarmRegistration(float t, AlarmObjectManager::ALARM_ID id);
	void SubmitAlarmDeregistration(AlarmObjectManager::ALARM_ID id);

private:

	struct RegistrationData
	{
		AlarmObjectManager::StorageMapRef pMyDeleteRef;
		RegistrationState curRegState;
		AlarmRegistrationCommand* pRegCmd;
		AlarmDeregistrationCommand* pDeregCmd;
	};
	friend class AlarmObjectAttorney;

	//using AlarmMap = std::multimap<float, AlarmObject*>;
	//using StorageMapRef = AlarmMap::iterator;

	RegistrationData RegData[AlarmObjectManager::ALARM_NUMBER];

	void AlarmRegistration(float t, AlarmObjectManager::ALARM_ID id);
	void AlarmDeregistration(AlarmObjectManager::ALARM_ID id);
	void SetIteratorRef(AlarmObjectManager::StorageMapRef ref, AlarmObjectManager::ALARM_ID id);

	void TriggerAlarm(AlarmObjectManager::ALARM_ID id);
};

#endif // !ALARMOBJECT_H
