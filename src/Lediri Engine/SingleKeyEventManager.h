#ifndef SingleKeyEventManager_H
#define SingleKeyEventManager_H

#include "Keyboard.h"
#include "InputObject.h"
#include <map>

class SingleKeyEventManager
{
private:
	using StorageMap = std::map<InputObject*, INPUT_EVENT_TYPE>;
	using StorageMapIterator = StorageMap::iterator;

	//friend class Scene; //temporary, it will most likely be friended to the KbEM
	friend class KeyboardEventManager;

	AZUL_KEY key;
	KEY_STATE myPreviousKeyState;
	StorageMap KeyPressMap;
	StorageMap KeyReleaseMap;
	std::map<InputObject*, INPUT_EVENT_TYPE>::iterator it;


	void Register(InputObject* pIO, INPUT_EVENT_TYPE iet);
	void Deregister(InputObject* pIO, INPUT_EVENT_TYPE iet);

	void ProcessKeyEvent();


public:
	using StorageMapIterator = StorageMap::iterator;

	SingleKeyEventManager() {};
	SingleKeyEventManager(AZUL_KEY k);
	SingleKeyEventManager(const SingleKeyEventManager&) = delete;
	SingleKeyEventManager& operator=(const SingleKeyEventManager&) = delete;
	~SingleKeyEventManager() {};



};
#endif // !SingleKeyEventManager_H
