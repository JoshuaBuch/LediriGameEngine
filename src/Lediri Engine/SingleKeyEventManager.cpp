#include "SingleKeyEventManager.h"
#include "InputObjectAttorney.h"

SingleKeyEventManager::SingleKeyEventManager(AZUL_KEY k)
{
	this->key = k;
	this->myPreviousKeyState = KEY_STATE::released;
}

void SingleKeyEventManager::Register(InputObject* pIO, INPUT_EVENT_TYPE iet)
{
	//DebugMsg::out("\nkey registered to SingleKeyEventManager");
	if (iet == INPUT_EVENT_TYPE::KEY_PRESS)
	{
		KeyPressMap.insert(std::pair<InputObject*, INPUT_EVENT_TYPE>(pIO, iet));
	}
	else if(iet == INPUT_EVENT_TYPE::KEY_RELEASE)
	{
		KeyReleaseMap.insert(std::pair<InputObject*, INPUT_EVENT_TYPE>(pIO, iet));
	}
}

void SingleKeyEventManager::Deregister(InputObject* pIO, INPUT_EVENT_TYPE iet)
{
	//DebugMsg::out("\nkey deregistered from the SingleKeyEventManager");
	if (iet == INPUT_EVENT_TYPE::KEY_PRESS)
	{
		KeyPressMap.erase(pIO);
	}

	else if(iet == INPUT_EVENT_TYPE::KEY_RELEASE)
	{
		KeyReleaseMap.erase(pIO);
	}
}

void SingleKeyEventManager::ProcessKeyEvent()
{
	if (Keyboard::GetKeyState(key) && myPreviousKeyState == KEY_STATE::released)
	{
		for (it = KeyPressMap.begin(); it != KeyPressMap.end(); it++)
		{
			InputObjectAttorney::GameLoop::KeyPressed(it->first, this->key);
		}
		myPreviousKeyState = KEY_STATE::pressed;
	}

	if(!(Keyboard::GetKeyState(key)) && myPreviousKeyState == KEY_STATE::pressed)
	{
		for (it = KeyReleaseMap.begin(); it != KeyReleaseMap.end(); it++)
		{
			InputObjectAttorney::GameLoop::KeyReleased(it->first, this->key);
		}
		myPreviousKeyState = KEY_STATE::released;
	}


}
