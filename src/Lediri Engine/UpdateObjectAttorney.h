#ifndef UpdateObjectAttorney_H
#define UpdateObjectAttorney_H

#include "UpdateObject.h"
#include "UpdateRegistrationCommand.h"
#include "UpdateDeregistrationCommand.h"

class UpdateObjectAttorney
{
public:
	using StorageList = std::list<UpdateObject*>;
	using StorageListRef = StorageList::iterator;
	class GameLoop
	{
	private:

		friend class UpdateObjectManager;
		static void Update(UpdateObject* pUO) { pUO->Update(); };
		static void SetIteratorReference(UpdateObject* pUO, StorageListRef ref) { pUO->SetIteratorRef(ref); };
	
	};

	class Registration
	{
	private:
		friend class UpdateRegistrationCommand;
		friend class UpdateDeregistrationCommand;

		static void SceneRegistration(UpdateObject* pUO) { pUO->SceneRegistration(); };
		static void SceneDeregistration(UpdateObject* pUO) { pUO->SceneDeregistration(); };

	};

private:


};
#endif // !UpdateObjectAttorney_H
