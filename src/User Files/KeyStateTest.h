#ifndef KeyStateTest_H
#define KeyStateTest_H

#include "../Lediri Engine/Lediri.h"

enum class KeyState
{
	Up = 0,
	Down = 1
};

class KeyStateTest : public GameObject
{
public:
	KeyStateTest(AZUL_KEY k);
	KeyStateTest(const KeyStateTest&) = delete;
	KeyStateTest& operator=(const KeyStateTest&) = delete;
	~KeyStateTest() {};

	void TestKey();
private:


	AZUL_KEY Key;
	KeyState myState = KeyState::Up;

};
#endif // !1