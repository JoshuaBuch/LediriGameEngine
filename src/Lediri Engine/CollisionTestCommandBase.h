#ifndef CollisionTestCommandBase_H
#define CollisionTestCommandBase_H

#include "CommandBase.h"

class CollisionTestCommandBase : public CommandBase
{
public:
	CollisionTestCommandBase() = default;
	CollisionTestCommandBase(const CollisionTestCommandBase&) = delete;
	CollisionTestCommandBase& operator=(const CollisionTestCommandBase&) = delete;
	virtual ~CollisionTestCommandBase()
	{
		DebugMsg::out("\nDeleting CollisionTestCommandBase object"); 
	}; //base class has to have virtual destructor

	virtual void execute() = 0;
private:

};
#endif // !CollisionTestCommandBase_H
