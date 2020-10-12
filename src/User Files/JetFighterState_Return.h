#ifndef _JETFIGHTERSTATE_RETURN
#define _JETFIGHTERSTATE_RETURN

#include "JetFighterState.h"

class JetFighterState_Return : public JetFighterState
{
public:
	JetFighterState_Return() = default;
	JetFighterState_Return(const JetFighterState_Return&) = default;
	JetFighterState_Return& operator=(const JetFighterState_Return&) = default;
	virtual ~JetFighterState_Return() = default;

	const void Execute(JetFighter* e) const override;
private:

};
#endif