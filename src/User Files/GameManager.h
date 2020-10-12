#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "DebugOut.h"
#include "../Lediri Engine/Lediri.h"

class LevelManager;
class JumpTank;

class GameManager
{
public:


	static void RegisterLevelManager(LevelManager* lm) { Instance().privRegisterLevelManager(lm); }
	static void RegisterPlayer(JumpTank* p) { Instance().privRegisterPlayer(p); }
	static Vect GetPlayerPos() { return Instance().privGetPlayerPos(); }
	static void UpdateLevelDeathHeight(float ypos) { Instance().privUpdateLevelDeathHeight(ypos); };
	static float GetLevelDeathHeight() { return Instance().privGetLevelDeathHeight(); };
	static void RegisterDeath() { Instance().privRegisterDeath(); };
	static void RegisterJetFighterDeath() { Instance().privRegisterJetFighterDeath(); };
	static void RegisterGeneratorDeath() { Instance().privRegisterGeneratorDeath(); };

	static void TerminateGameManager() { Instance().privTerminateGameManager(); }

private:
	GameManager() = default;
	GameManager(const GameManager&) = delete;
	GameManager& operator=(const GameManager&) = delete;
	~GameManager() { DebugMsg::out("GameManager deleted"); };

	static GameManager* ptrInstance;

	static GameManager& Instance()
	{
		if (!ptrInstance)
		{
			ptrInstance = new GameManager();
			ptrInstance->curLM = nullptr;
		}
		return *ptrInstance;
	}

	//member functions
	void privRegisterLevelManager(LevelManager* lm);
	void privRegisterPlayer(JumpTank* p);
	Vect privGetPlayerPos();
	void privUpdateLevelDeathHeight(float ypos);
	float privGetLevelDeathHeight();
	void privRegisterDeath();
	void privRegisterJetFighterDeath();
	void privRegisterGeneratorDeath();


	void privTerminateGameManager();

	//variables
	LevelManager* curLM;
	float deathHeight;

};
#endif