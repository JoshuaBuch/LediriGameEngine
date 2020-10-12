#include "UpdateObjectManager.h"
#include "UpdateObjectAttorney.h"
#include "GameObject.h"

void UpdateObjectManager::Register(UpdateObject* up)
{
	//DebugMsg::out("\nadded to the update manager");
	reference = UOList.insert(UOList.end(), up);
	UpdateObjectAttorney::GameLoop::SetIteratorReference(up, reference);
}

void UpdateObjectManager::Deregister(StorageList::iterator ref)
{
	//DebugMsg::out("\nremoved from the update manager");
	UOList.erase(ref); 
}

void UpdateObjectManager::ProcessElements()
{
	for (it = UOList.begin(); it != UOList.end(); it++ )
	{
		(*it)->Update();
	}
}