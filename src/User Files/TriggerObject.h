#ifndef _TRIGGEROBJECT
#define _TRIGGEROBJECT

#include "../Lediri Engine/Lediri.h"
#include "../Lediri Engine/Sprite.h"

class JumpTank;

class TriggerObject : public GameObject
{
public:
	virtual void Update();
	virtual void Draw();
	void Collision(JumpTank* go);

	TriggerObject() = default;
	TriggerObject(float posx, float posy, float posz, float scale);
	TriggerObject(const TriggerObject&) = delete;
	TriggerObject& operator=(const TriggerObject&) = delete;
	virtual ~TriggerObject();

	void CreateTrigger(float posx, float posy, float posz, float scale);
	virtual void CollisionEvent() = 0;
	//void SetPos(Vect p);

protected:
	GraphicsObject_WireframeConstantColor* pGObj_Trigger;

	static Vect DEFAULT_COLOR;

	Matrix world;
	Matrix scale;
	Vect pos;

	//sprite data
	Sprite* pTrigSprite = nullptr;
	bool spriteTriggered = false;
	float spriteTimer = 0.0f;
	float spriteTime = 5.0f;
	float spriteX;
	float spriteY;

};
#endif // !_TRIGGEROBJECT