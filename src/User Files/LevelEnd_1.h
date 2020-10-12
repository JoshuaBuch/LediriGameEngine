#ifndef _LEVELEND_1
#define _LEVELEND_1

#include "../Lediri Engine/Lediri.h"

class JumpTank;

class LevelEnd_1 : public GameObject
{
public:
	virtual void Update();
	virtual void Draw();
	void Collision(JumpTank* jt);

	LevelEnd_1() = default;
	LevelEnd_1(float posx, float posy, float posz, float scale);
	LevelEnd_1(const LevelEnd_1&) = delete;
	LevelEnd_1& operator=(const LevelEnd_1&) = delete;
	~LevelEnd_1();

private:

	GraphicsObject_WireframeConstantColor* pGObj_Trigger;

	static Vect DEFAULT_COLOR;

	Matrix world;
	Matrix scale;
	Vect pos;
};
#endif