#ifndef ALARMOBJECTMANAGER_H
#define ALARMOBJECTMANAGER_H

#include <map>
#include <functional> //included for the use of std::greater

//#include "AlarmObject.h"
class AlarmObject;

class AlarmObjectManager
{
public:
	enum ALARM_ID
	{
		ALARM_0,
		ALARM_1,
		ALARM_2,
		ALARM_3,
		ALARM_4
	};
	static const int ALARM_NUMBER = 5;

private:
	using AlarmEvent = std::pair<AlarmObject*, ALARM_ID>;
	using AlarmMap = std::multimap<float, AlarmEvent>;

public:



	using StorageMapRef = AlarmMap::iterator;

	void Register(float t, AlarmObject* ao, ALARM_ID id);
	void Deregister(StorageMapRef& ref); //change to take a reference to an iterator

	AlarmObjectManager();
	AlarmObjectManager(const AlarmObjectManager&) = delete;
	AlarmObjectManager& operator=(const AlarmObjectManager&) = delete;
	~AlarmObjectManager();

private:

	friend class Scene;

	AlarmMap myMap;
	AlarmMap::iterator reference;

	void ProcessAlarms();

};
#endif // !ALARMOBJECTMANAGER_H
