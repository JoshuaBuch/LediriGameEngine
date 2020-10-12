#include "KeyboardEventManager.h"
#include "SingleKeyEventManager.h"

void KeyboardEventManager::Register(InputObject * io, AZUL_KEY k, INPUT_EVENT_TYPE iet)
{
	//check to see if a single key manager exists for the key, if not make a new one and add it to map.
	this->it = this->mySKMap.find(k);
	if (it == mySKMap.end())
	{
		//DebugMsg::out("Creating list for new key and adding InputObject");
		it = this->mySKMap.insert(mySKMap.end(), std::pair<AZUL_KEY, SingleKeyEventManager*>(k, new SingleKeyEventManager(k)));
		this->it->second->Register(io, iet);
	}
	else
	{
		//DebugMsg::out("Adding InputObject to existing list.");
		this->it->second->Register(io, iet);
	}
}

void KeyboardEventManager::Deregister(InputObject* pIO, AZUL_KEY k, INPUT_EVENT_TYPE iet)
{
	//when deregistering, check if the SKEM is empty, if it is, add to an inactive list for optimization. Not needed now.
	this->it = this->mySKMap.find(k);
	if (it == mySKMap.end())
	{
		DebugMsg::out("Key being deregistered was never registered");
	}
	else
	{
		this->it->second->Deregister(pIO, iet);
	}
}

void KeyboardEventManager::ProcessKeyEvents()
{
	for (this->it = mySKMap.begin(); it != mySKMap.end(); it++)
	{
		this->it->second->ProcessKeyEvent();
	}
}

KeyboardEventManager::~KeyboardEventManager()
{
	for (this->it = mySKMap.begin(); it != mySKMap.end(); it++)
	{
		delete (this->it->second);
		this->it->second = nullptr;
	}
	mySKMap.clear();
}

