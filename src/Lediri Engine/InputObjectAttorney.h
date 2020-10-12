#ifndef InputObjectAttorney_H
#define InputObjectAttorney_H

#include "InputObject.h"
#include "InputRegistrationCommand.h"
#include "InputDeregistrationCommand.h"

class InputObjectAttorney
{
public:
	using StorageMap = std::map<InputObject*, INPUT_EVENT_TYPE>;
	using StorageMapIterator = StorageMap::iterator;

	class GameLoop
	{
	private:

		friend class KeyboardEventManager;
		friend class SingleKeyEventManager;

		static void KeyPressed(InputObject* pIO, AZUL_KEY k) { pIO->KeyPressed(k); };
		static void KeyReleased(InputObject* pIO, AZUL_KEY k) { pIO->KeyReleased(k); };
	};

	class Registration
	{
	private:
		friend class InputRegistrationCommand;
		friend class InputDeregistrationCommand;

		static void SceneRegistration(InputObject* pIO, AZUL_KEY k, INPUT_EVENT_TYPE iet) { pIO->SceneRegistration(k, iet); };
		static void SceneDeregistration(InputObject* pIO, AZUL_KEY k, INPUT_EVENT_TYPE iet) { pIO->SceneDeregistration(k, iet); };
	};
private:

};

#endif // !InputObjectAttorney_H
