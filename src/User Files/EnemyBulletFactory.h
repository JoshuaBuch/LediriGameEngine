#ifndef EnemyBulletFactory_H
#define EnemyBulletFactory_H

#include "../Lediri Engine/Lediri.h"
#include <list>

class EnemyBullet;

class EnemyBulletFactory
{
public:

	static void CreateEnemyBullet(Vect pos, Vect dir, int d) { Instance().privCreateEnemyBullet(pos, dir, d); };
	static void RecycleEnemyBullet(EnemyBullet* b) { Instance().privRecycleEnemyBullet(b); };
	static void UseEnemyBullet(Vect pos) { Instance().UseEnemyBullet(pos); };
	static void TerminateEnemyBulletFactory() { Instance().privTerminateEnemyBulletFactory(); };

private:

	EnemyBulletFactory() = default;
	EnemyBulletFactory(const EnemyBulletFactory&) = delete;
	EnemyBulletFactory& operator=(const EnemyBulletFactory&) = delete;
	~EnemyBulletFactory();

	static EnemyBulletFactory* ptrInstance;

	static EnemyBulletFactory& Instance()
	{
		if (!ptrInstance)
		{
			ptrInstance = new EnemyBulletFactory;
		}
		return *ptrInstance;
	}

	static std::list<EnemyBullet*> ActiveEnemyBullets;
	static std::list<EnemyBullet*> InactiveEnemyBullets;
	EnemyBullet* btemp;

	void privCreateEnemyBullet(Vect pos, Vect dir, int d);
	void privRecycleEnemyBullet(EnemyBullet* b);
	//void privUseEnemyBullet(Vect pos);
	void privTerminateEnemyBulletFactory();

	float bulletScale = 1.5f;
};

#endif // !EnemyBulletFactory_H