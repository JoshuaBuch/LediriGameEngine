#include "EnemyTankState_Attack.h"
#include "EnemyTank_FSM.h"

const EnemyTankState_Attack EnemyTank_FSM::AttackState;

const void EnemyTankState_Attack::Execute(EnemyTank* e) const
{
	e->FollowPlayer();
	//e->Fire();
}