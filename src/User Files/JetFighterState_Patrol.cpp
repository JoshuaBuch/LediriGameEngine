#include "JetFighterState_Patrol.h"
#include "JetFighter_FSM.h"

const JetFighterState_Patrol JetFighter_FSM::PatrolState;

const void JetFighterState_Patrol::Execute(JetFighter* e) const
{
	if (e->PlayerInRange(200.0f))
	{
		//changestate
		e->ChangeState(&JetFighter_FSM::ChaseState);
	}
	else
	{
		e->Patrol();
	}
}
