#ifndef KeyboardEventManager_H
#define KeyboardEventManager_H

#include "Keyboard.h"
#include "InputEventTypeEnum.h"
#include <map>

class InputObject;
class SingleKeyEventManager;

class KeyboardEventManager
{

private:

	friend class Scene;

	using StorageMap = std::map<AZUL_KEY, SingleKeyEventManager*>;
	using StorageMapIterator = StorageMap::iterator;

	StorageMap mySKMap;
	StorageMapIterator it;
public:

	KeyboardEventManager() = default;
	KeyboardEventManager(const KeyboardEventManager&) = delete;
	KeyboardEventManager& operator=(const KeyboardEventManager&) = delete;
	~KeyboardEventManager();

	void Register(InputObject* io, AZUL_KEY k, INPUT_EVENT_TYPE iet);
	void Deregister(InputObject* pIO, AZUL_KEY k, INPUT_EVENT_TYPE iet);
	void ProcessKeyEvents();


};
#endif // !KeyboardEventManager_H

