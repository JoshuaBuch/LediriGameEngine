#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H

#include "../Lediri Engine/Lediri.h"
#include "JumpTank.h"

class JumpTank;

class LevelManager
{
public:

	LevelManager();
	LevelManager(const LevelManager&) = delete;
	LevelManager& operator=(const LevelManager&) = delete;
	virtual ~LevelManager();


	Vect GetPlayerPos();
	virtual void RegisterEnemyDeath();
	virtual void RegisterJetFighterDeath();
	virtual void GeneratorDeath() {};
	virtual void StartNextLevel() {};

	void RegisterPlayer(JumpTank* p);

	
protected:
	JumpTank* pPlayer;
	int enemyKills = 0;
	int jetFighterKills = 0;

private:


};

#endif