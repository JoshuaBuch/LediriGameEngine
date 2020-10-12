#ifndef  _L1TRIGGER_01
#define _L1TRIGGER_01

#include "TriggerObject.h"
class JumpTank;

class L1Trigger_01 : public TriggerObject
{
public:
	L1Trigger_01(float posx, float posy, float posz, float scaleNum);
	L1Trigger_01(const L1Trigger_01&) = delete;
	L1Trigger_01& operator=(const L1Trigger_01&) = delete;
	~L1Trigger_01();

	void Collision(JumpTank* jt);
	void CollisionEvent() override;

private:

};
#endif // ! _L1TRIGGER_01
