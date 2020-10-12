#ifndef Tank_H
#define Tank_H

#include "../Lediri Engine/GameObjectDependencies.h"

class Frigate;
class EnemyTank;
class Sprite;

class Tank : public GameObject
{
public:

	Tank();
	Tank(Vect pos, bool b);
	Tank(const Tank&) = delete;
	Tank& operator=(const Tank&) = delete;
	~Tank();


	void Update();
	void Draw();
	void Collision(EnemyTank* et);
	void Collision(Frigate* f);
	void Collision(Tank* t);
	void Alarm0();
	void Alarm1();
	void KeyPressed(AZUL_KEY k);
	void KeyReleased(AZUL_KEY k);



private:


	GraphicsObject_TextureLight* pGObj_Tank = nullptr;
	GraphicsObject_TextureLight* pGObj_TankTurret = nullptr;
	Sprite* targetSprite = nullptr; //sprite
	Vect LightColor = Vect(1.50f, 1.50f, 1.50f, 1.0f);
	Vect LightPos = Vect(1.0f, 1.0f, 1.0f, 1.0f);

	Vect vCamLookAt = Vect(0, 20, 90);
	Vect vCamTankOffset = Vect(0, 70, -150);
	Vect vNewCamPos;
	Vect vNewLookAt;

	Matrix mTankScale;
	Vect vTankPos;
	Matrix mTankRot;
	Matrix mTankRotPos;
	Matrix mWorld;
	Matrix mWorldTurret;
	Vect vPosTurret;

	const float TankTransSpeed = 1;
	const float TankRotAng = .05f;

	float targetAngle = 0;

	bool canMove = true;


	//acceleration test
	float acceleration = 1;
	float time;
	float timeStep = 0.1f;
	float zPos = 1;
	float velocity = 0;
	float newAcceleration;
	const float force = 2;



};
#endif // !Tank_H