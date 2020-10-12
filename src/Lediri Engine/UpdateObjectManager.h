#ifndef _UPDATEOBJECTMANAGER
#define _UPDATEOBJECTMANAGER
#include <list>
#include "AzulCore.h"


class UpdateObject;

class UpdateObjectManager
{
private: //private comes first because the using StorageList must proceed the using in public

	using StorageList = std::list<UpdateObject*>;

	friend class Scene;

	StorageList UOList;
	StorageList::iterator it;
	StorageList::iterator reference;

	void ProcessElements(); //iterates through the list and calls each object's update

	void Register(UpdateObject* up);
	void Deregister(StorageList::iterator ref);

public:
	using StorageListRef = StorageList::iterator;

	UpdateObjectManager() = default;
	UpdateObjectManager(const UpdateObjectManager&) = delete;
	UpdateObjectManager& operator=(const UpdateObjectManager&) = delete;
	~UpdateObjectManager() {};





};
#endif // !_UPDATEOBJECTMANAGER
