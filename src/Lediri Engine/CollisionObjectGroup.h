#ifndef CollisionObjectGroup_H
#define CollisionObjectGroup_H

#include <list>
#include "COGroupDeleteCommand.h"
#include "CollisionVolumeAABB.h"
#include "Visualizer.h"
#include "Color.h"

class CollisionObject;
class CollisionVolumeAABB;

template <typename C>
class CollisionObjectGroup
{
public:
	
	using CollisionObjectCollection = std::list<C*>;

	static void Register(C* c) { Instance().privRegister(c); };
	static void Deregister(C* c) { Instance().privDeregister(c); };
	static const CollisionObjectCollection& GetCollisionObjectCollection() { return Instance().privGetCollisionObjectCollection(); };
	static const CollisionVolumeAABB& GetCollisionObjectGroupAABB() { return Instance().privGetCollisionObjectGroupAABB(); };
	static void UpdateCOGAABB() { Instance().privUpdateCOGAABB(); };
	static void Delete() { Instance().privDelete(); };
	static void GetInstance() { Instance().privGetInstance(); };

private:

	CollisionObjectGroup() 
	{
	};
	CollisionObjectGroup(const CollisionObjectGroup&) {};
	CollisionObjectGroup& operator=(const CollisionObjectGroup&) {};
	~CollisionObjectGroup() { DebugMsg::out("\nDeleting CollisionObjectGroup"); };

	CollisionObjectCollection COList;

	static CollisionObjectGroup<C>* ptrInstance;
	CollisionVolumeAABB* AABBGroup = nullptr;

	static CollisionObjectGroup& Instance()
	{
		if (!ptrInstance)
		{
			ptrInstance = new CollisionObjectGroup;
			ptrInstance->AABBGroup = new CollisionVolumeAABB();
			SceneManager::getCurScene()->SendCollisionDeleteCmd(new COGroupDeleteCommand<C>());
		}
		return *ptrInstance;
	}


	void privRegister(C* c)
	{
		COList.push_back(c);
		//AABBGroup->ComputeData(c->GetCollisionSphere());
		//DebugMsg::out("\nObject has been added to respective collision group");
	}

	void privDeregister(C* c)
	{
		COList.remove(c);
		//DebugMsg::out("\n\nObject has been removed from respective collision group");
	}

	const CollisionObjectCollection& privGetCollisionObjectCollection()
	{
		return COList;
	}

	const CollisionVolumeAABB& privGetCollisionObjectGroupAABB()
	{
		return *(this->AABBGroup);
	}

	void privUpdateCOGAABB()
	{
		auto it1 = COList.begin();
		if (COList.size() > 0)
		{
			AABBGroup->SetMaxMin((*it1)->GetCollisionSphere());
		}
		
		for (it1 = COList.begin(); it1 != COList.end(); it1++)
		{
			AABBGroup->ComputeData((*it1)->GetCollisionSphere());
		}

		return;
	}

	void privDelete()
	{
		COList.clear();
		delete AABBGroup;
		delete (ptrInstance);
		ptrInstance = nullptr;
	};

};


template <typename C>
CollisionObjectGroup<C>* CollisionObjectGroup<C>::ptrInstance = nullptr;
#endif // !CollisionObjectGroup_H

