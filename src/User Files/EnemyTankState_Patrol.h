#ifndef _ENEMYTANKSTATE_PATROL
#define _ENEMYTANKSTATE_PATROL

#include "EnemyTankState.h"

class EnemyTankState_Patrol : public EnemyTankState
{
public:
	EnemyTankState_Patrol() = default;
	EnemyTankState_Patrol(const EnemyTankState_Patrol&) = default;
	EnemyTankState_Patrol& operator=(const EnemyTankState_Patrol&) = default;
	virtual ~EnemyTankState_Patrol() = default;

	const void Execute(EnemyTank * e) const override;

private:

};
#endif // !_ENEMYTANKSTATE_PATROL
