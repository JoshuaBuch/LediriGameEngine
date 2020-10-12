#ifndef _ENEMYTANKSTATE_IDLE
#define _ENEMYTANKSTATE_IDLE

#include "EnemyTankState.h"

class EnemyTankState_Idle : public EnemyTankState
{
public:
	EnemyTankState_Idle() = default;
	EnemyTankState_Idle(const EnemyTankState_Idle&) = default;
	EnemyTankState_Idle& operator=(const EnemyTankState_Idle&) = default;
	virtual ~EnemyTankState_Idle() = default;

	const void Execute(EnemyTank* e) const override;

private:

};
#endif // !_ENEMYTANKSTATE_IDLE