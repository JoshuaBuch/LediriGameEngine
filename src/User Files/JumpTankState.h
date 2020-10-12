#ifndef _JUMPTANKSTATE
#define _JUMPTANKSTATE

#include "JumpTank.h"

class JumpTankState
{
public:
	JumpTankState() = default;
	JumpTankState(const JumpTankState&) = delete;
	JumpTankState& operator=(const JumpTankState&) = delete;
	virtual ~JumpTankState() = default;

	virtual const void Execute(JumpTank* e) const = 0;

protected:


private:

};
#endif // !_JUMPTANKSTATE