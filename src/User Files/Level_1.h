#ifndef _LEVEL_1
#define _LEVEL_1

#include "../Lediri Engine/Lediri.h"
#include "Plane.h"

class JumpTank;
class LM_01;
class DestroyerDroid;
class EnemyTank;
class Ground;

class Level_1 : public Scene
{
public:
	Level_1() = default;
	Level_1(const Level_1&) = delete;
	Level_1& operator=(const Level_1&) = delete;
	~Level_1() {};

	void Initialize();
	void SceneEnd();

private:

	JumpTank* pPlayer;
	Plane* pPlaneGO;
	LM_01* pLM;
	DestroyerDroid* pDD;
	EnemyTank* pEnemyTank;

	
};
#endif 