#include "EnemyTankState_Idle.h"
#include "EnemyTank_FSM.h"

const EnemyTankState_Idle EnemyTank_FSM::IdleState;

const void EnemyTankState_Idle::Execute(EnemyTank* e) const
{
	if (e->PlayerInRange(50.0f))
	{
		//set state to attack
		e->ChangeState(&EnemyTank_FSM::AttackState);
	}
}