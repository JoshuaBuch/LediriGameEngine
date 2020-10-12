#ifndef _JUMPTANKSTATE_TERRAIN
#define _JUMPTANKSTATE_TERRAIN

#include "JumpTankState.h"

class JumpTankState_Terrain : public JumpTankState
{
public:
	JumpTankState_Terrain() = default;
	JumpTankState_Terrain(const JumpTankState_Terrain&) = delete;
	JumpTankState_Terrain& operator=(const JumpTankState_Terrain&) = delete;
	virtual ~JumpTankState_Terrain() = default;

	const void Execute(JumpTank* e) const;

protected:


private:

};
#endif // !_JUMPTANKSTATE_TERRAIN