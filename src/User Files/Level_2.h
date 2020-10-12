#ifndef _LEVEL_2
#define _LEVEL_2

#include "../Lediri Engine/Lediri.h"
#include "Plane.h"

class JumpTank;
class LM_02;
class DestroyerDroid;
class EnemyTank;
class Ground;

class Level_2 : public Scene
{
public:
	Level_2() = default;
	Level_2(const Level_2&) = delete;
	Level_2& operator=(const Level_2&) = delete;
	~Level_2() {};

	void Initialize();
	void SceneEnd();

private:

	JumpTank* pPlayer;
	Plane* pPlaneGO;
	LM_02* pLM;
	DestroyerDroid* pDD;
	EnemyTank* pEnemyTank;


};
#endif 