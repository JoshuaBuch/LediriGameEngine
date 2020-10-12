#ifndef _UPDATEOBJECT
#define _UPDATEOBJECT

#include "RegistrationStateEnum.h"
#include "UpdateObjectManager.h"

class UpdateRegistrationCommand;
class UpdateDeregistrationCommand;

class UpdateObject
{
public:
	
	UpdateObject();
	virtual void Update() {};
	virtual ~UpdateObject();

	
protected: //only inhereted classes have access to protected
	void SubmitUpdateRegistration();
	void SubmitUpdateDeregistration();
	
private:

	friend class UpdateObjectAttorney;

	using StorageList = std::list<UpdateObject*>;
	using StorageListRef = StorageList::iterator;

	UpdateRegistrationCommand* pRegCmd;
	UpdateDeregistrationCommand* pDeregCmd;

	void SceneRegistration();
	void SceneDeregistration();
	void SetIteratorRef(StorageListRef ref);

	RegistrationState curRegState;
	UpdateObjectManager::StorageListRef pUODeleteRef;

};
#endif // !_UPDATEOBJECT
