#ifndef CollisionObject_H
#define CollisionObject_H

#include "RegistrationStateEnum.h"
#include "AzulCore.h"
#include "CollisionObjectGroup.h"

#include "CollisionVolumeBSphere.h"
#include "CollisionRegistrationCommand.h"
#include "CollisionDeregistrationCommand.h"

#include "CollisionVolumeType.h"

class SceneRegistrationCommand;
class CollisionVolumeBSphere;

class CollisionObject
{
public:
	CollisionObject();
	CollisionObject(const CollisionObject&) = delete;
	CollisionObject& operator=(const CollisionObject&) = delete;
	virtual ~CollisionObject(); //base class has to have virtual destructor

	virtual void Collision(CollisionObject* c);
	//const CollisionVolumeBSphere& GetBSphere();
	const CollisionVolume& GetCollisionVolume() const;
	const CollisionVolumeBSphere& GetCollisionSphere() const;

protected:

	template <typename C>
	void SubmitCollisionRegistration(C* c)
	{
		//assert(this->curRegState == RegistrationState::CURRENTLY_DEREGISTERED);
		//DebugMsg::out("\nSubmitting to collision registration");
		pRegCmd = new CollisionRegistrationCommand<C>(c);
		SceneManager::getCurScene()->SubmitCommand(pRegCmd);
		curRegState = RegistrationState::CURRENTLY_REGISTERED;
	}

	template <typename C>
	void SubmitCollisionDeregistration(C* c)
	{
		//assert(this->curRegState == RegistrationState::CURRENTLY_REGISTERED);
		//DebugMsg::out("\nDeregistering from collision group");
		pDeregcmd = new CollisionDeregistrationCommand<C>(c);
		SceneManager::getCurScene()->SubmitCommand(pDeregcmd);
		curRegState = RegistrationState::CURRENTLY_DEREGISTERED;
	}

	void SetColliderModel(Model* mod, COLLISION_VOLUME_TYPE type);
	void UpdateCollisionData(Matrix& mat);


private:
	//CollisionVolumeBSphere BSphere;
	CollisionVolume* myVolume;
	CollisionVolumeBSphere* myBSphere = nullptr;
	Model* pColModel;

	RegistrationState curRegState = RegistrationState::CURRENTLY_DEREGISTERED;

	SceneRegistrationCommand* pRegCmd;
	SceneRegistrationCommand* pDeregcmd;

};

#endif // !CollisionObject_H
