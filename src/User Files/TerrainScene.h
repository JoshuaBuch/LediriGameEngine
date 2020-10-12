#ifndef _TERRAINSCENE
#define _TERRAINSCENE

#include "../Lediri Engine/Lediri.h"

class TerrainObject;
class JumpTank;
class Axis;
class LevelManager;
class GodCamObject;

class TerrainScene : public Scene
{
public:
	TerrainScene() = default;
	TerrainScene(const TerrainScene&) = delete;
	TerrainScene& operator=(const TerrainScene&) = delete;
	~TerrainScene() {};

	void Initialize();
	void SceneEnd();

	TerrainObject* terrain;
private:
	Axis* axis;
	LevelManager* pLM;
	JumpTank* pPlayer;
	GodCamObject* gc;

};
#endif // !_TERRAINSCENE
