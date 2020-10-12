#ifndef DESTROYERDROID_FSM_
#define DESTROYERDROID_FSM_

#include "DestroyerDroidState.h"
#include "DestroyerDroidState_Idle.h"
#include "DestroyerDroidState_Chase.h"


class DestroyerDroid_FSM
{
public:
	DestroyerDroid_FSM() = default;
	DestroyerDroid_FSM(const DestroyerDroid_FSM&) = delete;
	DestroyerDroid_FSM& operator=(const DestroyerDroid_FSM&) = delete;
	~DestroyerDroid_FSM() = default;

	static const DestroyerDroidState_Idle IdleState;
	static const DestroyerDroidState_Chase ChaseState;

private:

};
#endif // !DESTROYERDROID_FSM_
