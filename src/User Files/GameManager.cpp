#include "GameManager.h"
#include "LevelManager.h"

GameManager* GameManager::ptrInstance = nullptr;

void GameManager::privRegisterLevelManager(LevelManager* lm)
{
	curLM = lm;
}

void GameManager::privRegisterPlayer(JumpTank* p)
{
	if (curLM != nullptr)
	{
		curLM->RegisterPlayer(p);
	}

}

Vect GameManager::privGetPlayerPos()
{
	//return(curLM->GetPlayerPos());
	if (curLM != nullptr)
	{
		return (curLM->GetPlayerPos());
	}
	else
	{
		Vect v;
		v.set(0.0f, 0.0f, 0.0f);
		return v;
	}
}

void GameManager::privRegisterDeath()
{
	//tell the LM that an enemy has died
	if (curLM != nullptr)
	{
		curLM->RegisterEnemyDeath();
	}
}

void GameManager::privRegisterJetFighterDeath()
{
	if (curLM != nullptr)
	{
		curLM->RegisterJetFighterDeath();
	}
}

void GameManager::privRegisterGeneratorDeath()
{
	if (curLM != nullptr)
	{
		curLM->GeneratorDeath();
	}
}

void GameManager::privUpdateLevelDeathHeight(float ypos)
{
	if (deathHeight > ypos)
	{
		deathHeight = ypos;
	}
}

float GameManager::privGetLevelDeathHeight()
{
	return deathHeight;
}

void GameManager::privTerminateGameManager()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}




