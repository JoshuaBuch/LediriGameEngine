#ifndef AlarmObjectAttorney_H
#define AlarmObjectAttorney_H

#include "AlarmObject.h"
#include "AlarmRegistrationCommand.h"
#include "AlarmDeregistrationCommand.h"

class AlarmObjectAttorney
{
public:
	using AlarmMap = std::multimap<float, AlarmObject*>;
	using StorageMapRef = AlarmMap::iterator;

	class GameLoop
	{
	private:

		friend class AlarmObjectManager;
		static void TriggerAlarm(AlarmObject* pAO, AlarmObjectManager::ALARM_ID id) { pAO->TriggerAlarm(id); };
		static void SetIteratorReference(AlarmObject* pAO, AlarmObjectManager::ALARM_ID id, AlarmObjectManager::StorageMapRef ref) { pAO->SetIteratorRef(ref, id); };

	};

	class Registration
	{
	private:
		friend class AlarmRegistrationCommand;
		friend class AlarmDeregistrationCommand;

		static void SceneRegistration(AlarmObject* pAO, float t, AlarmObjectManager::ALARM_ID id) { pAO->AlarmRegistration(t, id); };
		static void SceneDeregistration(AlarmObject* pAO, AlarmObjectManager::ALARM_ID id) { pAO->AlarmDeregistration(id); };

	};

private:


};
#endif // !AlarmObjectAttorney_H
