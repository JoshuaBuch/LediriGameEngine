#include "BulletFactory.h"
#include "Bullet.h"

BulletFactory* BulletFactory::ptrInstance = nullptr;

std::list<Bullet*> BulletFactory::ActiveBullets;
std::list<Bullet*> BulletFactory::InactiveBullets;

void BulletFactory::privCreateBullet(const Matrix& rot, const Vect& pos)
{
   	if (InactiveBullets.empty())
	{
		//DebugMsg::out("\n\nCreating new bullet");
		btemp = new Bullet();
		btemp->Initialize(rot, pos);
		ActiveBullets.push_front(btemp);
		btemp->SubmitEntry();
	}
	else
	{
		//DebugMsg::out("\n\nUsing recycled bullet");
		btemp = InactiveBullets.front();
		InactiveBullets.pop_front();
		btemp->Initialize(rot, pos);
		ActiveBullets.push_front(btemp);
		btemp->SubmitEntry();
	}
}

void BulletFactory::privRecycleBullet(Bullet* b)
{
	//DebugMsg::out("\n\nRecycling bullet");

	ActiveBullets.remove(b);
	InactiveBullets.push_front(b);
}

void BulletFactory::privTerminateBulletFactory()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}

BulletFactory::~BulletFactory()
{
	while (!InactiveBullets.empty())
	{
		btemp = InactiveBullets.front();
		InactiveBullets.pop_front();
		delete btemp;
	}

	while (!ActiveBullets.empty())
	{
		btemp = ActiveBullets.front();
		ActiveBullets.pop_front();
		delete btemp;
	}
}

