#include "DestroyerDroidState_Idle.h"
#include "DestroyerDroid_FSM.h"

const DestroyerDroidState_Idle DestroyerDroid_FSM::IdleState;

const void DestroyerDroidState_Idle::Execute(DestroyerDroid* e) const
{
	if (e->PlayerInRange(200))
	{
		e->ChangeState(&DestroyerDroid_FSM::ChaseState);
	}
	else
	{
		//DebugMsg::out("The droid is searching!\n\n");
	}
}
