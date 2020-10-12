#ifndef _ENEMYTANK_FSM
#define _ENEMYTANK_FSM

#include "EnemyTankState.h"
#include "EnemyTankState_Patrol.h"
#include "EnemyTankState_Idle.h"
#include "EnemyTankState_Attack.h"

class EnemyTank_FSM
{
public:

	EnemyTank_FSM() = default;
	EnemyTank_FSM(const EnemyTank_FSM&) = delete;
	EnemyTank_FSM& operator=(const EnemyTank_FSM&) = delete;
	~EnemyTank_FSM() = default;

	static const EnemyTankState_Patrol PatrolState;
	static const EnemyTankState_Idle IdleState;
	static const EnemyTankState_Attack AttackState;


private:

};
#endif // !_ENEMYTANK_FSM
