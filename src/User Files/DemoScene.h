#ifndef _DEMOSCENE
#define _DEMOSCENE

#include "../Lediri Engine/Lediri.h"
#include "../User Files/Plane.h"
#include "../User Files/Axis.h"
#include "../User Files/Frigate.h"
#include "Tank.h"
#include "../Lediri Engine/Scene.h"
#include "TesterObject.h"
#include "StitchSprite.h"
#include "EnemyTank.h"

class Plane;
class Axis;
class Frigate;
class Tank;
class Bullet;

class DemoScene : public Scene
{
public:



	DemoScene() = default;
	DemoScene(const DemoScene&) = delete;
	DemoScene& operator=(const DemoScene&) = delete;
	~DemoScene() {};
	
	void Initialize();
	void SceneEnd();

private:

	Plane* pPlaneGO;
	Axis* pAxisGO;
	Frigate* pFrigateGO;
	Tank* pTankGO;
	EnemyTank* pEnemyGO;
	StitchSprite* pStitchSprite;
	EnemySpawner* pESpawn;
	

};
#endif // !_DEMOSCENE
