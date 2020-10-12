#ifndef _JETFIGHTERSTATE
#define _JETFIGHTERSTATE

//class JetFighter;
#include "JetFighter.h"
//#include "JetFighter_FSM.h"

class JetFighterState
{
public:
	JetFighterState() = default;
	JetFighterState(const JetFighterState&) = delete;
	JetFighterState& operator=(const JetFighterState&) = delete;
	virtual ~JetFighterState() = default;

	virtual const void Execute(JetFighter * e) const = 0;


protected:


private:

};
#endif // !_JETFIGHTERSTATE
