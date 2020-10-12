#include "AlarmObjectManager.h"
#include "GameObject.h"
#include "AlarmObject.h"
#include "TimeManager.h"
#include "AlarmObjectAttorney.h"

AlarmObjectManager::AlarmObjectManager()
{

}

void AlarmObjectManager::Register(float t, AlarmObject* ao, ALARM_ID id)
{
	//DebugMsg::out("\nadded to the alarm manager");
	reference = myMap.insert(std::pair<float, AlarmEvent>((TimeManager::GetGameTime() + t), AlarmEvent(ao, id))); //MUST add current time to the Alarm's time
	AlarmObjectAttorney::GameLoop::SetIteratorReference(ao, id, reference);
}

void AlarmObjectManager::Deregister(StorageMapRef& ref)
{
	//DebugMsg::out("\nAlarm has been removed from the alarm manager");
	myMap.erase(ref);
}

void AlarmObjectManager::ProcessAlarms()
{
	while ( myMap.begin() != myMap.end() && myMap.begin()->first <= TimeManager::GetGameTime())
	{
		//DebugMsg::out("Alarm time = %f", myMap.begin()->first);

		AlarmObjectAttorney::GameLoop::TriggerAlarm(myMap.begin()->second.first, myMap.begin()->second.second); //look at the second element's first element in map (AlarmObject pointer)
		myMap.erase(myMap.begin());
	}
}

AlarmObjectManager::~AlarmObjectManager()
{
	DebugMsg::out("\nAlarmObjectManager being destroyed");
	//should alarmobjectmanager be the one destroying the alarms?
	//while (myMap.begin() != myMap.end() && myMap.begin()->first <= TimeManager::GetGameTime())
	//{
	//	//DebugMsg::out("Alarm time = %f", myMap.begin()->first);

	////	AlarmObjectAttorney::GameLoop::TriggerAlarm(myMap.begin()->second.first, myMap.begin()->second.second); //look at the second element's first element in map (AlarmObject pointer)
	//	myMap.erase(myMap.begin());
	//}
}