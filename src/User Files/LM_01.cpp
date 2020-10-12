#include "LM_01.h"
#include "GameManager.h"
#include "Ground.h"
#include "L1Trigger_01.h"
#include "DestroyerDroid.h"
#include "EnemyTank.h"
#include "JetFighter.h"
#include "LevelEnd_1.h"

LM_01::LM_01()
{
	pEnd = nullptr;
	GameManager::RegisterLevelManager(this);

	pTrig1 = new L1Trigger_01(0, -10, 0, 50);

	//spawn ground
	groundArray[0] = new Ground(0, -550, 0, 1000);

	groundArray[16] = new Ground(0, -550, 3200, 1000);


	ddArray[0] = new DestroyerDroid(250, -20, 250, Speed::Slow);
	ddArray[1] = new DestroyerDroid(-250, -20, -250, Speed::Slow);
	ddArray[2] = new DestroyerDroid(0, 0, 300, Speed::Fast);

	etArray[0] = new EnemyTank(Vect(400, -50, 0));
	etArray[1] = new EnemyTank(Vect(-350, -50, 0));

}

void LM_01::RegisterEnemyDeath()
{
	enemyKills++;
	if (pathUnlocked == false)
	{
		if (enemyKills >= pathUnlock)
		{
			pathUnlocked = true;
			//spawn the other grounds
			groundArray[1] = new Ground(0, -120, 650, 200);
			groundArray[2] = new Ground(0, -100, 880, 200);
			groundArray[3] = new Ground(-220, -100, 1150, 200);
			groundArray[4] = new Ground(-100, -150, 1450, 200);
			groundArray[5] = new Ground(-50, -180, 1700, 200);
			groundArray[6] = new Ground(-250, -150, 1950, 200);
			groundArray[7] = new Ground(150, -150, 1950, 200); //left side bridge start
			groundArray[8] = new Ground(150, -150, 2150, 200);
			groundArray[9] = new Ground(150, -150, 2350, 200);
			groundArray[10] = new Ground(150, -150, 2550, 200);
			groundArray[11] = new Ground(-250, -150, 2150, 200); //right side bridge start
			groundArray[12] = new Ground(-250, -150, 2350, 200);
			groundArray[13] = new Ground(-450, -150, 2350, 200);
			groundArray[14] = new Ground(-250, -150, 2550, 200);
			groundArray[15] = new Ground(-450, -150, 2550, 200);
			groundArray[17] = new Ground(-220, 0, 1300, 50); //small box

			//spawn more droids
			ddArray[3] = new DestroyerDroid(200, -30, 1950, Speed::Slow);
			ddArray[4] = new DestroyerDroid(150, -30, 1900, Speed::Slow);
			ddArray[5] = new DestroyerDroid(175, -30, 2050, Speed::Slow);
			ddArray[6] = new DestroyerDroid(180, -30, 2200, Speed::Fast);
			ddArray[7] = new DestroyerDroid(150, -30, 2400, Speed::Fast);
			ddArray[8] = new DestroyerDroid(140, -30, 2600, Speed::Slow);
			ddArray[9] = new DestroyerDroid(180, -30, 2600, Speed::Fast);
			ddArray[10] = new DestroyerDroid(-220, 20, 1150, Speed::Slow);

			//spawn enemy tanks
			etArray[2] = new EnemyTank(Vect(-200, -50, 2550));
			etArray[3] = new EnemyTank(Vect(-320, -50, 2350));

			jfArray[0] = new JetFighter(Vect(0, 50, 3200));
			jfArray[1] = new JetFighter(Vect(200, 50, 3200));
			jfArray[2] = new JetFighter(Vect(-200, 50, 3200));
		}
	}

	
}

void LM_01::RegisterJetFighterDeath()
{
	jetFighterKills++;

	if (jetFighterKills >= 3)
	{
		//create a trigger to unlock the next level;
		pEnd = new LevelEnd_1(0, 50, 3200, 50);
		DebugMsg::out("Go to next level");
	}
}

LM_01::~LM_01()
{

	delete pTrig1;
	if (pEnd != nullptr)
	{
		delete pEnd;
	}
	

	if (pathUnlocked)
	{
		for (int i = 0; i < groundAmount; i++)
		{

			delete groundArray[i]; //don't use brackets
			groundArray[i] = nullptr;

		}

		for (int i = 0; i < 11; i++)
		{
			delete ddArray[i];
			ddArray[i] = nullptr;
		}

		for (int i = 0; i < 4; i++)
		{
			delete etArray[i];
			etArray[i] = nullptr;
		}

		for (int i = 0; i < 3; i++)
		{
			delete jfArray[i];
			jfArray[i] = nullptr;
		}
	}
	else
	{
		delete groundArray[0];

		delete groundArray[16];

		for (int i = 0; i < 3; i++)
		{
			delete ddArray[i];
			ddArray[i] = nullptr;
		}


		for (int i = 0; i < 2; i++)
		{
			delete etArray[i];
			etArray[i] = nullptr;
		}
	}


}