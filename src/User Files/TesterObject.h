#ifndef TesterObject_H
#define TesterObject_H

#include "../Lediri Engine/Lediri.h"

class KeyStateTest;


class TesterObject : public GameObject
{
public:
	TesterObject();
	TesterObject(const TesterObject&) = delete;
	TesterObject& operator=(const TesterObject&) = delete;
	~TesterObject() {};

	void Update();
	void KeyPressed(AZUL_KEY k);
	void KeyReleased(AZUL_KEY k);
	void Alarm0();
	void Alarm1();
	void Alarm2();
	void Alarm3();
	void Alarm4();
private:

	bool alarm_three_off = false;
	//KeyStateTest* pMyKeyTest;
};
#endif // !1
