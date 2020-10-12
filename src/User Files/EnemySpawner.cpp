#include "EnemySpawner.h"
#include <stdlib.h>
#include "DemoScene.h"

EnemySpawner::EnemySpawner()
{
	
	//for (int i = 0; i < 6; i++)
	//{
	//	float r1 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 400));
	//	float r2 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 400));
	//	ranPos.set(r1, 0, r2);
	//	enemyArray[i] = new EnemyTank(ranPos, this);
	//}

	//for (int i = 0; i < 10; i++)
	//{
	//	float r1 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 1500));
	//	float r2 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (200) + 60));
	//	float r3 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 1500));
	//	ranPos.set(r1, r2, r3);
	//	frigateArray[i] = new Frigate(ranPos);
	//}
}

void EnemySpawner::killEnemy()
{
	enemyNum--;
	if (enemyNum <= 0)
	{
		SceneManager::SetNextScene(new DemoScene());
	}
}

EnemySpawner::~EnemySpawner()
{
	for (int i = 0; i < 6; i++)
	{
		if (enemyArray[i] != 0)
		{
			delete enemyArray[i];
		}
		
	}
	
	//for (int i = 0; i < 10; i++)
	//{
	//	delete frigateArray[i];
	//}
}