#include "EnemyTankState_Patrol.h"
#include "EnemyTank_FSM.h"

const EnemyTankState_Patrol EnemyTank_FSM::PatrolState;

const void EnemyTankState_Patrol::Execute(EnemyTank* e) const
{
	if (e->PlayerInRange(200.0f))
	{
		e->ChangeState(&EnemyTank_FSM::AttackState);
	}
	else
	{
		e->Patrol();
	}
	
}