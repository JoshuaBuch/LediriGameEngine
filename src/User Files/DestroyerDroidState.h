#ifndef _DESTROYERDROIDSTATE
#define _DESTROYERDROIDSTATE

#include "DestroyerDroid.h"

class DestroyerDroidState
{
public:
	DestroyerDroidState() = default;
	DestroyerDroidState(const DestroyerDroidState&) = delete;
	DestroyerDroidState& operator=(const DestroyerDroidState&) = delete;
	virtual ~DestroyerDroidState() = default;

	virtual const void Execute(DestroyerDroid* e) const = 0;

protected:


private:

};
#endif // !_DESTROYERDROIDSTATE
