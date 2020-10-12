#include "KeyStateTest.h"

KeyStateTest::KeyStateTest(AZUL_KEY k)
	: Key(k)
{

}

void KeyStateTest::TestKey()
{
	if (myState == KeyState::Up)
	{
		if (Keyboard::GetKeyState(Key))
		{
			DebugMsg::out("\nKey was pressed");
			myState = KeyState::Down;
		}
	}
	if (myState == KeyState::Down)
	{
		if (!(Keyboard::GetKeyState(Key)))
		{
			DebugMsg::out("\nKey was released");
			myState = KeyState::Up;
		}
	}


}