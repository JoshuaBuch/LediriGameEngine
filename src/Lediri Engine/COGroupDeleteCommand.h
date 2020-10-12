#ifndef COGroupDeleteCommand_H
#define COGroupDeleteCommand_H

#include "CommandBase.h"

#include "CollisionObjectGroup.h"

template <typename C>
class COGroupDeleteCommand : public CommandBase
{
public:
	
	COGroupDeleteCommand()
	{
		
	};
	COGroupDeleteCommand(const COGroupDeleteCommand&) = delete;
	COGroupDeleteCommand& operator=(const COGroupDeleteCommand&) = delete;
	virtual ~COGroupDeleteCommand()
	{
		DebugMsg::out("\nDeleting COGroupDeleteCommand object"); 
	}; //base class has to have virtual destructor

	virtual void execute()
	{
		CollisionObjectGroup<C>::Delete();
	};
private:

};
#endif // !COGroupDeleteCommand_H
