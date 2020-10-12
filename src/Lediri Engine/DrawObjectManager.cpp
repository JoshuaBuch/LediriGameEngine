#include "DrawObjectManager.h"
#include "DrawObjectAttorney.h"
#include "GameObject.h"

void DrawObjectManager::Register(DrawObject* dr)
{
	//DebugMsg::out("\nadded to the draw manager");
	reference = DOList.insert(DOList.end(), dr);
	DrawObjectAttorney::GameLoop::SetIteratorReference(dr, reference);

	
}

void DrawObjectManager::Deregister(StorageList::iterator ref)
{
	//DebugMsg::out("\nremoved from the draw manager");
	DOList.erase(ref);
}

void DrawObjectManager::ProcessElements()
{
	for (it = DOList.begin(); it != DOList.end(); it++)
	{
		(*it)->Draw();

	}
}