#ifndef _ENEMYTANKSTATE
#define _ENEMYTANKSTATE

#include "EnemyTank.h"

class EnemyTankState
{
public:
	EnemyTankState() = default;
	EnemyTankState(const EnemyTankState&) = delete;
	EnemyTankState& operator=(const EnemyTankState&) = delete;
	virtual ~EnemyTankState() = default;

	virtual const void Execute(EnemyTank * e) const = 0;

private:

};
#endif // !_ENEMYTANKSTATE
