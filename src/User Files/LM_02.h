#ifndef _LM_02
#define _LM_02

#include "LevelManager.h"

class Ground;
class DestroyerDroid;
class EnemyTank;
class JetFighter;
class L2Trigger_01;
class L2Trigger_02;
class LevelEnd_2;

class LM_02 : public LevelManager
{
public:
	LM_02();
	LM_02(const LM_02&) = delete;
	LM_02& operator=(const LM_02&) = delete;
	~LM_02();

	//virtual void RegisterEnemyDeath() override;
	//virtual void RegisterJetFighterDeath() override;
	virtual void GeneratorDeath() override;

private:
	int pathUnlock = 5;
	bool pathUnlocked = false;
	//int jetFightUnlock = 15;
	//bool jetFightStarted = false;
	int gensKilled = 0;
	int maxGens = 3;

	LevelEnd_2* pEnd; //switch level trigger

	//ground data
	int groundAmount = 18;
	Ground* groundArray[43];

	//L1Trigger_02* pTrig1;

	//enemy data
	DestroyerDroid* ddArray[8];
	EnemyTank* etArray[5];
	JetFighter* jfArray[9];
	L2Trigger_02* genArray[3];
	L2Trigger_01* pTrigger;

};
#endif // !_LM_02