#ifndef  _L2Trigger_02
#define _L2Trigger_02

#include "TriggerObject.h"
class JumpTank;
class Bullet;

class L2Trigger_02 : public TriggerObject
{
public:
	L2Trigger_02(float posx, float posy, float posz, float scaleNum);
	L2Trigger_02(const L2Trigger_02&) = delete;
	L2Trigger_02& operator=(const L2Trigger_02&) = delete;
	~L2Trigger_02();

	void Collision(JumpTank* jt);
	void Collision(Bullet* b);
	void CollisionEvent() override;

private:
	bool alive = true;
};
#endif // ! _L2Trigger_02