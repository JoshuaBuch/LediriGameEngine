#include "DemoScene.h"
#include "Bullet.h"
#include "EnemySpawner.h"
#include "BulletFactory.h"

void DemoScene::Initialize()
{
	//this->SetDefaultCamera(); //this is not needed, cameraManager automatically set's the default cam

	pPlaneGO = new Plane();
	pAxisGO = new Axis();
	//pESpawn = new EnemySpawner();
	pFrigateGO = new Frigate(Vect(0, 5, 0));

	pTankGO = new Tank(Vect(0, 0, -43), true);

	Frigate* pFrigateGO2 = new Frigate(Vect(0.0f, 10.0f, 80.0f));
	Tank* pTankGO2 = new Tank(Vect(0, 0, 0), true);
	//Tank* pTankGO3 = new Tank(Vect(-150, 0, 0), true);

	pFrigateGO2;
	pTankGO2;
	//pTankGO3;

	//pStitchSprite = new StitchSprite();

	//SetCollisionSelf<EnemyTank>();
	//SetCollisionPair<EnemyTank, Tank>();
	//SetCollisionPair<Bullet, EnemyTank>();
	//SetCollisionSelf<Tank>();
	SetCollisionPair<Tank, Frigate>();
}


void DemoScene::SceneEnd()
{


	BulletFactory::TerminateBulletFactory();
	delete pPlaneGO;
	delete pAxisGO;
	delete pTankGO;
	//delete pESpawn;
	delete pFrigateGO;
	delete pStitchSprite;
}