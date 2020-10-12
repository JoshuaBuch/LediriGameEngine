#include "Level_1.h"
#include "BulletFactory.h"
#include "EnemyBulletFactory.h"
#include "Bullet.h"
#include "JumpTank.h"

#include "EnemyTank.h"
#include "JetFighter.h"
#include "GodCamObject.h"
#include "Ground.h"
#include "EnemyBullet.h"
#include "DestroyerDroid.h"
#include "L1Trigger_01.h"
#include "LevelEnd_1.h"

#include "GameManager.h"
#include "LM_01.h"

#include "../Lediri Engine/TerrainObject.h"

void Level_1::Initialize()
{
	//pDD = new DestroyerDroid();
	//pEnemyTank = new EnemyTank();
	pLM = new LM_01();
	//pPlaneGO = new Plane();



	//TriggerObject* to = new TriggerObject(0, 0, 0, 50);
	//to;


	//JetFighter* pJF = new JetFighter();
	//pJF;
	////
	//EnemyTank* et = new EnemyTank(Vect(100, 0, 0));
	//et;

	//GodCamObject* gc = new GodCamObject();
	//gc;


	//TerrainModel* terrain = new TerrainModel();
	//terrain->BuildTerrain();

	pPlayer = new JumpTank(0);


	//JetFighter* pJet = new JetFighter();
	//pJet;


	SetCollisionPair<JumpTank, Ground>();
	SetCollisionPair<Bullet, EnemyTank>();
	SetCollisionPair<JumpTank, EnemyTank>();
	SetCollisionPair<EnemyBullet, JumpTank>();
	SetCollisionPair<DestroyerDroid, JumpTank>();
	SetCollisionPair<JetFighter, Bullet>();
	SetCollisionPair<JetFighter, JumpTank>();
	SetCollisionPair<DestroyerDroid, Bullet>();
	//SetCollisionPair<JumpTank, L1Trigger_01>();
	SetCollisionPair<JumpTank, TriggerObject>();
	SetCollisionPair<JumpTank, LevelEnd_1>();
}

void Level_1::SceneEnd()
{
	BulletFactory::TerminateBulletFactory();
	EnemyBulletFactory::TerminateEnemyBulletFactory();
	GameManager::TerminateGameManager();
	//delete pPlaneGO;
	delete pPlayer;
	delete pLM;

	//delete pDD;
}
