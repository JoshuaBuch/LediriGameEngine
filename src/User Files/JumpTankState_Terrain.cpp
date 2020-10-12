#include "JumpTankState_Terrain.h"
#include "JumpTank_FSM.h"

const JumpTankState_Terrain JumpTank_FSM::TerrainState;

const void JumpTankState_Terrain::Execute(JumpTank* e) const
{
	e->TerrainMove();
}