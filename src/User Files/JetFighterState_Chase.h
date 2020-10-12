#ifndef _JETFIGHTERSTATE_CHASE
#define _JETFIGHTERSTATE_CHASE

#include "JetFighterState.h"

class JetFighterState_Chase : public JetFighterState
{
public:
	JetFighterState_Chase() = default;
	JetFighterState_Chase(const JetFighterState_Chase&) = default;
	JetFighterState_Chase& operator=(const JetFighterState_Chase&) = default;
	virtual ~JetFighterState_Chase() = default;

	const void Execute(JetFighter* e) const override;
private:

};
#endif