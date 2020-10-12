#ifndef CollisionManager_H
#define CollisionManager_H

#include <list>
#include "AzulCore.h"
#include "CollisionTestPairCommand.h"
#include "CollisionTestSelfCommand.h"
#include "COGroupDeleteCommand.h"

#include "CollisionTestPairCommand_NoTier.h"

class CollisionObject;
class CollisionTestCommandBase;

class CollisionManager
{
public:

	CollisionManager() = default;
	CollisionManager(const CollisionManager&) = delete;
	CollisionManager& operator=(const CollisionManager&) = delete;
	~CollisionManager();

private:

	using CollisionTestCommandCollection = std::list<CollisionTestCommandBase*>;
	using CollisionTestIterator = CollisionTestCommandCollection::iterator;
	CollisionTestCommandCollection CTCmdCol;
	CollisionTestIterator CTCit;

	std::list<CommandBase*> CODeleteCmdList;
	std::list<CommandBase*>::iterator CODeleteit;

	friend class Scene;

	void ProcessCollisions();
	
	template <typename C1, typename C2>
	void SetCollisionPair()
	{
		DebugMsg::out("\nCreating new CollisionTestPairCommand");

		CTCmdCol.push_back(new CollisionTestPairCommand<C1, C2>());

		//CTCmdCol.push_back(new CollisionTestPairCommand_NoTier<C1, C2>());
	};

	template <typename C>
	void SetCollisionSelf()
	{
		DebugMsg::out("\nCreating new CollisionTestSelfCommand");

		CTCmdCol.push_back(new CollisionTestSelfCommand<C>());
	};

	template <typename C>
	void SaveCollisionDeleteCmd(C* c)
	{
		CODeleteCmdList.push_back(c);
	}
};
#endif // !CollisionManager_H
