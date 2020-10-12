#include "CollisionObject.h"
#include "CollisionObjectGroup.h"
#include "CollisionVolumeBSphere.h"
#include "CollisionVolumeAABB.h"
#include "CollisionVolumeOBB.h"

CollisionObject::CollisionObject()
{
	//curRegState = RegistrationState::CURRENTLY_DEREGISTERED;
	myVolume = nullptr;
}

void CollisionObject::Collision(CollisionObject* c)
{
	AZUL_UNUSED(c);
	//DebugMsg::out("\n\nObject is missing a Collision function\n");
}

//const CollisionVolumeBSphere& CollisionObject::GetBSphere()
//{
//	return BSphere;
//}

const CollisionVolume& CollisionObject::GetCollisionVolume() const
{
	return *myVolume;
}

const CollisionVolumeBSphere& CollisionObject::GetCollisionSphere() const
{
	return *myBSphere;
}

void CollisionObject::SetColliderModel(Model * mod, COLLISION_VOLUME_TYPE type)
{
	//TODO: if we change collider model we need to check if a volume is already set and delete that model

	pColModel = mod;
	switch (type)
	{
	case(COLLISION_VOLUME_TYPE::BSPHERE):
		myVolume = new CollisionVolumeBSphere();
		myBSphere = new CollisionVolumeBSphere();
		break;
	case(COLLISION_VOLUME_TYPE::AABB):
		myVolume = new CollisionVolumeAABB();
		myBSphere = new CollisionVolumeBSphere();
		break;
	case(COLLISION_VOLUME_TYPE::OBB):
		myVolume = new CollisionVolumeOBB();
		myBSphere = new CollisionVolumeBSphere();
		break;
	}
}

void CollisionObject::UpdateCollisionData(Matrix & mat)
{
	myVolume->ComputeData(pColModel, mat);
	myBSphere->ComputeData(pColModel, mat);
}

CollisionObject::~CollisionObject()
{
	delete myVolume;
	delete myBSphere;
	//DebugMsg::out("CollisionObject deleted");
}