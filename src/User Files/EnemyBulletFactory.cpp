#include "EnemyBulletFactory.h"
#include "EnemyBullet.h"

EnemyBulletFactory* EnemyBulletFactory::ptrInstance = nullptr;

std::list<EnemyBullet*> EnemyBulletFactory::ActiveEnemyBullets;
std::list<EnemyBullet*> EnemyBulletFactory::InactiveEnemyBullets;

void EnemyBulletFactory::privCreateEnemyBullet(Vect pos, Vect dir, int d)
{
	if (InactiveEnemyBullets.empty())
	{
		//DebugMsg::out("\n\nCreating new EnemyBullet");
		btemp = new EnemyBullet(pos, dir, bulletScale, d);
		btemp->Initialize(pos, dir, d);
		ActiveEnemyBullets.push_front(btemp);
		btemp->SubmitEntry();
	}
	else
	{
		//DebugMsg::out("\n\nUsing recycled EnemyBullet");
		btemp = InactiveEnemyBullets.front();
		InactiveEnemyBullets.pop_front();
		btemp->Initialize(pos, dir, d);
		ActiveEnemyBullets.push_front(btemp);
		btemp->SubmitEntry();
	}
}

void EnemyBulletFactory::privRecycleEnemyBullet(EnemyBullet* b)
{
	//DebugMsg::out("\n\nRecycling EnemyBullet");

	ActiveEnemyBullets.remove(b);
	InactiveEnemyBullets.push_front(b);
}

void EnemyBulletFactory::privTerminateEnemyBulletFactory()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}

EnemyBulletFactory::~EnemyBulletFactory()
{
	while (!InactiveEnemyBullets.empty())
	{
		btemp = InactiveEnemyBullets.front();
		InactiveEnemyBullets.pop_front();
		delete btemp;
	}

	while (!ActiveEnemyBullets.empty())
	{
		btemp = ActiveEnemyBullets.front();
		ActiveEnemyBullets.pop_front();
		delete btemp;
	}
}

