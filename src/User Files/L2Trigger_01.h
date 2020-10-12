#ifndef  _L2TRIGGER_01
#define _L2TRIGGER_01

#include "TriggerObject.h"
class JumpTank;

class L2Trigger_01 : public TriggerObject
{
public:
	L2Trigger_01(float posx, float posy, float posz, float scaleNum);
	L2Trigger_01(const L2Trigger_01&) = delete;
	L2Trigger_01& operator=(const L2Trigger_01&) = delete;
	~L2Trigger_01();

	void Collision(JumpTank* jt);
	void CollisionEvent() override;

private:

};
#endif // ! _L2TRIGGER_01