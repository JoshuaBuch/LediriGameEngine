#ifndef ENEMY_H
#define ENEMY_H

#include "../Lediri Engine/GameObjectDependencies.h"
#include "GameManager.h"

class Enemy : public GameObject
{
public:
	Enemy();
	Enemy(const Enemy&) = delete;
	Enemy& operator=(const Enemy&) = delete;
	virtual ~Enemy();

	virtual void Update() { DebugMsg::out("EnemyBase Update being called"); }
	virtual void Draw() { DebugMsg::out("EnemyBase DRAW being called"); }


	void SendDamage(int d);
	bool PlayerInRange(float range);
	Vect DirectionToPlayer();
	void LookAt(Vect position); //changes forward vector to the direction of the passed in position
	void LookAtHorizontal(Vect position); //only changes the horizontal axis to the direction of the passed in position
	const int GetCollisionDamage();

protected:

	int health;
	int collisionDamage;
	int damage;
	float moveSpeed = .2f;

	Vect vPos;
	Matrix mScale;
	Matrix mRot;
	Matrix mWorld;

private: 


};
#endif