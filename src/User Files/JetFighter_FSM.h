#ifndef _JETFIGHTER_FSM
#define _JETFIGHTER_FSM

#include "JetFighterState.h"

#include "JetFighterState_Patrol.h"
#include "JetFighterState_Chase.h"
#include "JetFighterState_Return.h"

class JetFighter_FSM
{
public:
	JetFighter_FSM() = default;
	JetFighter_FSM(const JetFighter_FSM&) = delete;
	JetFighter_FSM& operator=(const JetFighter_FSM&) = delete;
	~JetFighter_FSM() = default;

	static const JetFighterState_Patrol PatrolState;
	static const JetFighterState_Chase ChaseState;
	static const JetFighterState_Return ReturnState;

	//static void TerminateFSM();

private:

};
#endif // !_JETFIGHTER_FSM
