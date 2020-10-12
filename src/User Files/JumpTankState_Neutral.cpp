#include "JumpTankState_Neutral.h"
#include "JumpTank_FSM.h"

const JumpTankState_Neutral JumpTank_FSM::NeutralState;

const void JumpTankState_Neutral::Execute(JumpTank* e) const
{
	e->MovePlayer();
}