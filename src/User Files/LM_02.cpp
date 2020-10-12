#include "LM_02.h"
#include "GameManager.h"
#include "Ground.h"
#include "L2Trigger_01.h"
#include "DestroyerDroid.h"
#include "EnemyTank.h"
#include "JetFighter.h"
#include "L2Trigger_02.h"
#include "LevelEnd_2.h"

LM_02::LM_02()
{
	GameManager::RegisterLevelManager(this);

	pEnd = nullptr;	
	pTrigger = new L2Trigger_01(0, 0, 0, 50);

	//pTrig1 = new L1Trigger_01(0, -10, 0, 50);

	//spawn ground
	groundArray[0] = new Ground(0, -500, 0, 1000); //center
	groundArray[1] = new Ground(750, -100, 0, 200);  //left path up
	groundArray[2] = new Ground(1050, -20, 0, 200);
	groundArray[3] = new Ground(1350, 50, 0, 200);
	groundArray[4] = new Ground(1600, 100, 0, 200);
	groundArray[5] = new Ground(1850, 150, 0, 200);
	groundArray[6] = new Ground(2050, 150, 0, 200);
	groundArray[7] = new Ground(2050, 150, -200, 200);
	groundArray[8] = new Ground(2050, 150, -500, 200);
	groundArray[9] = new Ground(2050, 150, -800, 200);
	groundArray[10] = new Ground(2050, 50, -1100, 500); //upper generator
	groundArray[11] = new Ground(0, -100, -700, 200); //back path
	groundArray[12] = new Ground(0, -100, -1000, 200);
	groundArray[13] = new Ground(0, -100, -1300, 200);
	groundArray[14] = new Ground(0, -100, -1600, 200);
	groundArray[15] = new Ground(0, -100, -1900, 200);
	groundArray[16] = new Ground(0, -100, -2200, 200);
	groundArray[17] = new Ground(0, -250, -2600, 500);
	groundArray[18] = new Ground(-400, -100, -2600, 200); //back to right path
	groundArray[19] = new Ground(-700, -180, -2600, 200);
	groundArray[20] = new Ground(-1000, -260, -2600, 200);
	groundArray[21] = new Ground(-1300, -340, -2600, 200);
	groundArray[22] = new Ground(-1600, -420, -2400, 200);
	groundArray[23] = new Ground(-1800, -500, -2300, 200);
	groundArray[24] = new Ground(-700, -100, 0, 200); //right path
	groundArray[25] = new Ground(-900, -200, 0, 200);
	groundArray[26] = new Ground(-1100, -300, 0, 200);
	groundArray[27] = new Ground(-1300, -400, 0, 200);
	groundArray[28] = new Ground(-1550, -400, 0, 200);
	groundArray[29] = new Ground(-1800, -400, 0, 200);
	groundArray[30] = new Ground(-2200, -550, 0, 500); //right generator
	groundArray[31] = new Ground(-1800, -400, -300, 200);
	groundArray[32] = new Ground(-1800, -400, -600, 200);
	groundArray[33] = new Ground(-1800, -400, -900, 200);
	groundArray[34] = new Ground(-1800, -400, -1200, 200);
	groundArray[35] = new Ground(-1800, -400, -1500, 200);
	groundArray[36] = new Ground(-1800, -400, -1800, 200);
	groundArray[37] = new Ground(-1800, -400, -2100, 200);



	ddArray[0] = new DestroyerDroid(-2050, -280, 100, Speed::Slow);
	ddArray[1] = new DestroyerDroid(-2050, -280, -100, Speed::Slow);
	ddArray[2] = new DestroyerDroid(-2000, -280, 0, Speed::Slow);
	ddArray[3] = new DestroyerDroid(-1800, -180, -2100, Speed::Fast); //lonerDD


	jfArray[0] = new JetFighter(Vect(750, 50, 0));
	jfArray[1] = new JetFighter(Vect(1500, 250, 50));
	jfArray[2] = new JetFighter(Vect(2050, 400, -1300));
	jfArray[3] = new JetFighter(Vect(2150, 400, -1300));
	jfArray[4] = new JetFighter(Vect(0, 80, -1200)); //back path jf
	jfArray[5] = new JetFighter(Vect(50, 80, -1500));


	etArray[0] = new EnemyTank(Vect(2100, 250, -100));
	etArray[1] = new EnemyTank(Vect(0, 0, -2600));


	genArray[0] = new L2Trigger_02(2050, 350, -1300, 50);
	genArray[1] = new L2Trigger_02(0, 50, -2600, 50);
	genArray[2] = new L2Trigger_02(-2200, -250, 0, 50);

	//etArray[0] = new EnemyTank(Vect(400, -50, 0));
	//etArray[1] = new EnemyTank(Vect(-350, -50, 0));

	ddArray[4] = new DestroyerDroid(-80, 10, 1000, Speed::Fast); //end DD
	ddArray[5] = new DestroyerDroid(80, 10, 1250, Speed::Fast);
	ddArray[6] = new DestroyerDroid(-80, 10, 1500, Speed::Fast);
	ddArray[7] = new DestroyerDroid(80, 10, 1750, Speed::Fast);

	jfArray[6] = new JetFighter(Vect(-80, 150, 1200)); //end jf
	jfArray[7] = new JetFighter(Vect(120, 150, 1500));
	jfArray[8] = new JetFighter(Vect(-80, 150, 1750));

	//etArray[2] = new EnemyTank(Vect(100, 0, 1200));
	//etArray[3] = new EnemyTank(Vect(-50, 0, 1450));
	//etArray[4] = new EnemyTank(Vect(100, 0, 1850));

	groundArray[38] = new Ground(0, -250, 750, 500); //end path
	groundArray[39] = new Ground(0, -250, 1250, 500);
	groundArray[40] = new Ground(0, -250, 1750, 500);
	groundArray[41] = new Ground(0, -250, 2250, 500);
	groundArray[42] = new Ground(0, -500, 3000, 1000);

}


void LM_02::GeneratorDeath()
{
	gensKilled++;
	if (!pathUnlocked)
	{
		if (gensKilled >= maxGens)
		{




			pEnd = new LevelEnd_2(0, 50, 3000, 50); //create level end trigger
		}
	}

}


LM_02::~LM_02()
{

	delete pTrigger;
	if (pEnd != nullptr)
	{
		delete pEnd;
	}

	for (int i = 0; i < 3; i++)
	{
		delete genArray[i];
		genArray[i] = nullptr;
	}

	if (!pathUnlocked)
	{
		for (int i = 0; i < 43; i++) //one number higher than the array goes to
		{
			delete groundArray[i];
			groundArray[i] = nullptr;
		}

		for (int i = 0; i < 8; i++)
		{
			delete ddArray[i];
			ddArray[i] = nullptr;
		}

		for (int i = 0; i < 9; i++)
		{
			delete jfArray[i];
			jfArray[i] = nullptr;
		}

		for (int i = 0; i < 2; i++)
		{
			delete etArray[i];
			etArray[i] = nullptr;
		}
	}
	else
	{
		for (int i = 0; i < 43; i++) //one number higher than the array goes to
		{
			delete groundArray[i];
			groundArray[i] = nullptr;
		}

		for (int i = 0; i < 8; i++)
		{
			delete ddArray[i];
			ddArray[i] = nullptr;
		}

		for (int i = 0; i < 9; i++)
		{
			delete jfArray[i];
			jfArray[i] = nullptr;
		}

		for (int i = 0; i < 5; i++)
		{
			delete etArray[i];
			etArray[i] = nullptr;
		}
	}



}