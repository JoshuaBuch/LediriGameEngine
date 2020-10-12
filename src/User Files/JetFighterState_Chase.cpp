#include "JetFighterState_Chase.h"
#include "JetFighter_FSM.h"


const JetFighterState_Chase JetFighter_FSM::ChaseState;

const void JetFighterState_Chase::Execute(JetFighter* e) const
{
	e->ChasePlayer();

	if (e->CanFire())
	{
		e->Fire();
		e->CalculateReturnPosition();
		e->ChangeState(&JetFighter_FSM::ReturnState);
	}
}