#ifndef COMMANDBASE_H
#define COMMANDBASE_H

#include "AzulCore.h"

class CommandBase
{
public:
	CommandBase() = default;
	CommandBase(const CommandBase&) = delete;
	CommandBase& operator=(const CommandBase&) = delete;
	virtual ~CommandBase() 
	{ 
		//DebugMsg::out("\nDeleting CommandBase object"); 
	}; //base class has to have virtual destructor

	virtual void execute() = 0;
private:



};
#endif // !COMMANDBASE_H
