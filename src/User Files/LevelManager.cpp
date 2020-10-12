#include "LevelManager.h"
#include "JumpTank.h"
#include "GameManager.h"

LevelManager::LevelManager()
{
	//GameManager::RegisterLevelManager(this);
}

void LevelManager::RegisterPlayer(JumpTank* p)
{
	pPlayer = p;
}

void LevelManager::RegisterEnemyDeath()
{
	enemyKills;
}

void LevelManager::RegisterJetFighterDeath()
{
	
}

Vect LevelManager::GetPlayerPos()
{
	return pPlayer->GetPos();
}

LevelManager::~LevelManager()
{
	
}
