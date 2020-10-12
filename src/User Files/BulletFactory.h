#ifndef BulletFactory_H
#define BulletFactory_H

#include "../Lediri Engine/Lediri.h"
#include <list>

class Bullet;

class BulletFactory
{
public:

	static void CreateBullet(const Matrix& rot, const Vect& pos) { Instance().privCreateBullet(rot, pos); };
	static void RecycleBullet(Bullet* b) { Instance().privRecycleBullet(b); };
	static void UseBullet(Vect pos) { Instance().UseBullet(pos); };
	static void TerminateBulletFactory() { Instance().privTerminateBulletFactory(); };

private:

	BulletFactory() = default;
	BulletFactory(const BulletFactory&) = delete;
	BulletFactory& operator=(const BulletFactory&) = delete;
	~BulletFactory();

	static BulletFactory* ptrInstance;

	static BulletFactory& Instance()
	{
		if (!ptrInstance)
		{
			ptrInstance = new BulletFactory;
		}
		return *ptrInstance;
	}

	static std::list<Bullet*> ActiveBullets;
	static std::list<Bullet*> InactiveBullets;
	Bullet* btemp;

	void privCreateBullet(const Matrix& rot, const Vect& pos);
	void privRecycleBullet(Bullet* b);
	void privUseBullet(Vect pos);
	void privTerminateBulletFactory();
};

#endif // !BulletFactory_H
