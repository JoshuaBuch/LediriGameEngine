#include "JetFighterState_Return.h"
#include "JetFighter_FSM.h"


const JetFighterState_Return JetFighter_FSM::ReturnState;

const void JetFighterState_Return::Execute(JetFighter* e) const
{
	if (e->atOriginalAltitude())
	{
		e->ChangeState(&JetFighter_FSM::ChaseState);
	}
	else
	{
		e->Return();
	}
}