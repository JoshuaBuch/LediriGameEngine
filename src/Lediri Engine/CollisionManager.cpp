#include "CollisionManager.h"

void CollisionManager::ProcessCollisions()
{
	for (CTCit = CTCmdCol.begin(); CTCit != CTCmdCol.end(); CTCit++)
	{
		(*CTCit)->execute();
	}
}

CollisionManager::~CollisionManager()
{
	for (CTCit = CTCmdCol.begin(); CTCit != CTCmdCol.end(); CTCit++)
	{
		delete (*CTCit);
	}

	for (CODeleteit = CODeleteCmdList.begin(); CODeleteit != CODeleteCmdList.end(); CODeleteit++)
	{
		(*CODeleteit)->execute();
		delete (*CODeleteit);
	}
}
