#ifndef JETFIGHTER_H
#define JETFIGHTER_H

#include "Enemy.h"

class JetFighterState;
class Bullet;
class JumpTank;

class JetFighter : public Enemy
{
public:

	JetFighter() = delete;
	JetFighter(Vect pos);
	JetFighter(const JetFighter&) = delete;
	JetFighter& operator=(const JetFighter&) = delete;
	virtual ~JetFighter();

	void Update() override;
	void Draw() override;
	void SubmitExit();
	void Collision(Bullet* b);
	void Collision(JumpTank* jt);

	void ChasePlayer();
	bool PlayerInSight();
	void Patrol();
	bool CanFire();
	void Fire();
	void CalculateReturnPosition();
	bool atOriginalAltitude();
	void Return();
	void ChangeState(const JetFighterState* ptrState);

private:
	const JetFighterState* curState;

	GraphicsObject_TextureFlat* pGObj_EnemyJet = nullptr;
	Vect LightColor = Vect(1.50f, 1.50f, 1.50f, 1.0f);
	Vect LightPos = Vect(1.0f, 1.0f, 1.0f, 1.0f);

	Matrix mJetScale;
	Vect vJetPos;
	Matrix mJetRot;
	Matrix mJetRotPos;
	Matrix mWorld;

	float FireTimer = 0.0f;
	float FireTime = 3.0f;
	float bulletSize = 3.5f;
	int bulletDamage = 2;
	float JetTransSpeed = 1.0f;
	float JetRotAng = .02f;
	float originalHeight = 4.0f;
	Vect returnPoint;
	float returnOffset = 10.0f;
	Vect returnDirection;
	bool dead = false;
};
#endif