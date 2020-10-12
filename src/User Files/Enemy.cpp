#include "Enemy.h"
#include "GameManager.h"

Enemy::Enemy()
{
	//DebugMsg::out("\n*******EnemyBase CONSTRUCTOR called\n");
}

Enemy::~Enemy()
{
	//DebugMsg::out("\n*******EnemyBase destructor called\n");
}

bool Enemy::PlayerInRange(float range)
{
	Vect dist = GameManager::GetPlayerPos() - vPos;
	float mag = dist.mag();

	if (mag < range)
	{
		return true;
	}
	return false;
}

Vect Enemy::DirectionToPlayer()
{
	return (GameManager::GetPlayerPos() - vPos).norm();
}

void Enemy::LookAt(Vect position)
{
	Vect dir = position - vPos;
	//dir.Y() = vPos.Y();
	Vect newUp = dir.cross(mWorld.get(ROW_0));
	//might have to zero out y-component
	mRot.set(IDENTITY);
	mRot.set(ROT_ORIENT, dir, newUp);

	mWorld = mScale * mRot * Matrix(TRANS, vPos);

	//don't forget to set graphicobject and collision data to new world
}

void Enemy::LookAtHorizontal(Vect position)
{
	Vect dir = position - vPos;
	dir.Y() = vPos.Y(); //Locks the object on the vertical axis. Only changes horizontal direction
	mRot.set(IDENTITY);
	mRot.set(ROT_ORIENT, dir, Vect(0, 1.0f, 0));

	mWorld = mScale * mRot * Matrix(TRANS, vPos);

	//don't forget to set graphicobject and collision data to new world
}

void Enemy::SendDamage(int d)
{
	health -= d;
}

const int Enemy::GetCollisionDamage()
{
	return collisionDamage;
}


