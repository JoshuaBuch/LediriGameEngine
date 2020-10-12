#ifndef _DESTROYERDROIDSTATE_IDLE
#define _DESTROYERDROIDSTATE_IDLE

#include "DestroyerDroidState.h"

class DestroyerDroidState_Idle : public DestroyerDroidState
{
public:
	DestroyerDroidState_Idle() = default;
	DestroyerDroidState_Idle(const DestroyerDroidState_Idle&) = default;
	DestroyerDroidState_Idle& operator=(const DestroyerDroidState_Idle&) = default;
	virtual ~DestroyerDroidState_Idle() = default;

	const void Execute(DestroyerDroid* e) const override;
private:

};
#endif // !_DESTROYERDROIDSTATE_IDLE