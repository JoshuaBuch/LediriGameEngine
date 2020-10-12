#ifndef DRAWOBJECTMANAGER_H
#define DRAWOBJECTMANAGER_H
#include <list>
#include "AzulCore.h"

class DrawObject;

class DrawObjectManager
{
private:

	using StorageList = std::list<DrawObject*>;

	friend class Scene;

	StorageList DOList;
	StorageList::iterator it;
	StorageList::iterator reference;

	void ProcessElements(); //iterates through the list and calls each object's update

	void Register(DrawObject* dr);
	void Deregister(StorageList::iterator ref);

public:
	using StorageListRef = StorageList::iterator;

	DrawObjectManager() = default;
	DrawObjectManager(const DrawObjectManager&) = delete;
	DrawObjectManager& operator=(const DrawObjectManager&) = delete;
	~DrawObjectManager() {};



};
#endif // !DRAWOBJECTMANAGER_H
