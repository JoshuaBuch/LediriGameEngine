#ifndef _ENEMYTANKSTATE_ATTACK
#define _ENEMYTANKSTATE_ATTACK

#include "EnemyTankState.h"

class EnemyTankState_Attack : public EnemyTankState
{
public:
	EnemyTankState_Attack() = default;
	EnemyTankState_Attack(const EnemyTankState_Attack&) = default;
	EnemyTankState_Attack& operator=(const EnemyTankState_Attack&) = default;
	virtual ~EnemyTankState_Attack() = default;

	const void Execute(EnemyTank* e) const override;

private:

};
#endif // !_ENEMYTANKSTATE_ATTACK