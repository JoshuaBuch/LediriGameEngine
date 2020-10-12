#ifndef _DESTROYERDROIDSTATE_CHASE
#define _DESTROYERDROIDSTATE_CHASE

#include "DestroyerDroidState.h"

class DestroyerDroidState_Chase : public DestroyerDroidState
{
public:
	DestroyerDroidState_Chase() = default;
	DestroyerDroidState_Chase(const DestroyerDroidState_Chase&) = default;
	DestroyerDroidState_Chase& operator=(const DestroyerDroidState_Chase&) = default;
	virtual ~DestroyerDroidState_Chase() = default;

	const void Execute(DestroyerDroid * e) const override;

private:

};
#endif // !_DESTROYERDROIDSTATE_CHASE
