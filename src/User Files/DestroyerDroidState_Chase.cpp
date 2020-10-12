#include "DestroyerDroidState_Chase.h"
#include "DestroyerDroid_FSM.h"

const DestroyerDroidState_Chase DestroyerDroid_FSM::ChaseState;

const void DestroyerDroidState_Chase::Execute(DestroyerDroid* e) const
{
	e->MoveTowardsPlayer();
	//DebugMsg::out("The droid is chasing!\n\n");
}
