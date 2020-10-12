#ifndef _DRAWOBJECT
#define _DRAWOBJECT

#include "RegistrationStateEnum.h"
#include "DrawObjectManager.h"

class DrawRegistrationCommand;
class DrawDeregistrationCommand;

class DrawObject
{
public:
	DrawObject();
	virtual void Draw() {};
	virtual ~DrawObject();


protected: //only inhereted classes have access to protected
	void SubmitDrawRegistration();
	void SubmitDrawDeregistration();
	//void SubmitDrawRegistration2D();
	//void SubmitDrawDeregistration2D();

private:

	friend class DrawObjectAttorney;

	using StorageList = std::list<DrawObject*>;
	using StorageListRef = StorageList::iterator;

	DrawRegistrationCommand * pRegCmd;
	DrawDeregistrationCommand* pDeregCmd;

	void SceneRegistration();
	void SceneDeregistration();
	void SetIteratorRef(StorageListRef ref);

	RegistrationState curRegState;
	DrawObjectManager::StorageListRef pDODeleteRef;
};
#endif // !_DRAWOBJECT
