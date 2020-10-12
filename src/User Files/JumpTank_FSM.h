#ifndef _JUMPTANK_FSM
#define _JUMPTANK_FSM

#include "JumpTankState.h"
#include "JumpTankState_Neutral.h"
#include "JumpTankState_Terrain.h"

class JumpTank_FSM
{
public:
	JumpTank_FSM() = default;
	JumpTank_FSM(const JumpTank_FSM&) = delete;
	JumpTank_FSM& operator=(const JumpTank_FSM&) = delete;
	~JumpTank_FSM() = default;

	static const JumpTankState_Neutral NeutralState;
	static const JumpTankState_Terrain TerrainState;
	//static const JumpTankState_Patrol PatrolState;
	//static const JumpTankState_Chase ChaseState;

	//static void TerminateFSM();

private:

};
#endif // !_JUMPTANK_FSM