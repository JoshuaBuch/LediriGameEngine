#ifndef _LM_01
#define _LM_01

#include "LevelManager.h"

class Ground;
class DestroyerDroid;
class EnemyTank;
class JetFighter;
class L1Trigger_01;
class LevelEnd_1;

class LM_01 : public LevelManager
{
public:
	LM_01();
	LM_01(const LM_01&) = delete;
	LM_01& operator=(const LM_01&) = delete;
	~LM_01();

	virtual void RegisterEnemyDeath() override;
	virtual void RegisterJetFighterDeath() override;

private:
	int pathUnlock = 5;
	bool pathUnlocked = false;
	//int jetFightUnlock = 15;
	//bool jetFightStarted = false;
	//ground data
	int groundAmount = 18;
	Ground* groundArray[18];

	L1Trigger_01* pTrig1;
	LevelEnd_1* pEnd;

	//enemy data
	DestroyerDroid* ddArray[11];
	EnemyTank* etArray[4];
	JetFighter* jfArray[3];


};
#endif // !_LM_01
