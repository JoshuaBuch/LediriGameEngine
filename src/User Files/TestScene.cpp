#include "TestScene.h"
#include "BulletFactory.h"

void TestScene::Initialize()
{
	
	
	Tank* pTankGO2 = new Tank(Vect(55, 15, -60, 0), true);
	pTankGO2;
	
	Tank* pTankGO3 = new Tank(Vect(-55, 15, -180, 0), true);
	pTankGO3;
	pTankGO = new Tank(Vect(0, 15, -40, 0), true);
	pFrigateGO = new Frigate(Vect(0, 20, 0));
	Frigate* pFrigateGO2 = new Frigate(Vect(50, 20, 0));
	pFrigateGO2;
	//pStitchSprite = new StitchSprite();

	//pCottage = new Cottage();
	//Cottage* two = new Cottage();

	//two;
	//SetCollisionPair<Frigate, Cottage>();
	SetCollisionPair<Tank, Frigate>();
	//SetCollisionSelf<Tank>();

}

void TestScene::SceneEnd()
{
	BulletFactory::TerminateBulletFactory();
	delete pFrigateGO;
	delete pCottage;
}