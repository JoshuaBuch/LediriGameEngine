#include "TerrainScene.h"
#include "../Lediri Engine/TerrainObject.h"
#include "JumpTank.h"
#include "GodCamObject.h"
#include "LevelManager.h"

#include "Axis.h"

void TerrainScene::Initialize()
{
	TerrainObjectManager::getTerrainObject("MainTerrain")->Initialize();

	//terrain->BuildTerrainTest();
	pLM = new LevelManager();
	pPlayer = new JumpTank(1);
	gc = new GodCamObject();
	gc;
	//terrain->SimpleTest();

	//JumpTank* jTank = new JumpTank();
	//jTank;
}

void TerrainScene::SceneEnd()
{
	//delete terrain;
	delete axis;
	delete pLM;
	delete pPlayer;
	delete gc;
}
