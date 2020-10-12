#ifndef _LEVELEND_2
#define _LEVELEND_2

#include "../Lediri Engine/Lediri.h"

class JumpTank;

class LevelEnd_2 : public GameObject
{
public:
	virtual void Update();
	virtual void Draw();
	void Collision(JumpTank* jt);

	LevelEnd_2() = default;
	LevelEnd_2(float posx, float posy, float posz, float scale);
	LevelEnd_2(const LevelEnd_2&) = delete;
	LevelEnd_2& operator=(const LevelEnd_2&) = delete;
	~LevelEnd_2();

private:

	GraphicsObject_WireframeConstantColor* pGObj_Trigger;

	static Vect DEFAULT_COLOR;

	Matrix world;
	Matrix scale;
	Vect pos;
};
#endif