#ifndef EnemySpawner_H
#define EnemySpawner_H

#include "../Lediri Engine/GameObjectDependencies.h"
#include "EnemyTank.h"
#include "Frigate.h"
#include <random>
#include "AzulCore.h"

class EnemySpawner : public GameObject
{
public:

	EnemySpawner();
	EnemySpawner(const EnemySpawner&) = delete;
	EnemySpawner& operator=(const EnemySpawner&) = delete;
	~EnemySpawner();

	void killEnemy();
	

private:
	
	Vect ranPos;
	EnemyTank* enemyArray[6] = { 0 };
	Frigate* frigateArray[10];
	int enemyNum = 6;

};

#endif // !EnemySpawner_H
