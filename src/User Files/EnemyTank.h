#ifndef EnemyTank_H
#define EnemyTank_H

#include "Enemy.h"

class JumpTank;
class Bullet;
class EnemySpawner;

class EnemyTankState;

class EnemyTank : public Enemy
{
public:
	EnemyTank();
	EnemyTank(Vect pos);
	EnemyTank(const EnemyTank&) = delete;
	EnemyTank& operator=(const EnemyTank&) = delete;
	~EnemyTank();

	void Update();
	void Draw();
	void Collision(JumpTank* t);
	void Collision(Bullet* b);
	void Collision(EnemyTank* et) { et; };

	void SubmitExit();

	//void Move();
	void Patrol();
	void Fire();
	void FollowPlayer();
	void ChangeState(const EnemyTankState* ptrState);

private:
	GraphicsObject_TextureLight* pGObj_EnemyTank = nullptr;
	GraphicsObject_TextureLight* pGObj_EnemyTankTurret = nullptr;

	Vect LightColor = Vect(1.50f, 1.50f, 1.50f, 1.0f);
	Vect LightPos = Vect(1.0f, 1.0f, 1.0f, 1.0f);

	Matrix mTankRotPos;
	Matrix mWorldTurret;
	Vect vPosTurret;

	
	float TankRotAng = .002f;
	float fireTime = 2.0f;
	float fireTimer = 0.0f;
	float bulletSize = 3.5f;
	int bulletDamage = 2;

	EnemySpawner* enemySpawner;
	bool dead = false;

	const EnemyTankState* curState;

};
#endif // !EnemyTank_H
