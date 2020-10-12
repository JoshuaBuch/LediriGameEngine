#ifndef _JETFIGHTERSTATE_PATROL
#define _JETFIGHTERSTATE_PATROL

#include "JetFighterState.h"

class JetFighterState_Patrol : public JetFighterState
{
public:
	JetFighterState_Patrol() = default;
	JetFighterState_Patrol(const JetFighterState_Patrol&) = default;
	JetFighterState_Patrol& operator=(const JetFighterState_Patrol&) = default;
	virtual ~JetFighterState_Patrol() = default;

	const void Execute(JetFighter * e) const override;
private:

};
#endif