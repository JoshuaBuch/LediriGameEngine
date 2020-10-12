#ifndef _JUMPTANKSTATE_NEUTRAL
#define _JUMPTANKSTATE_NEUTRAL

#include "JumpTankState.h"

class JumpTankState_Neutral : public JumpTankState
{
public:
	JumpTankState_Neutral() = default;
	JumpTankState_Neutral(const JumpTankState_Neutral&) = delete;
	JumpTankState_Neutral& operator=(const JumpTankState_Neutral&) = delete;
	virtual ~JumpTankState_Neutral() = default;

	const void Execute(JumpTank* e) const;

protected:


private:

};
#endif // !_JUMPTANKSTATE_NEUTRAL