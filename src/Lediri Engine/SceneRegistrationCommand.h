#ifndef SceneRegistrationCommand_H
#define SceneRegistrationCommand_H

#include "CommandBase.h"

class SceneRegistrationCommand : public CommandBase
{
public:
	SceneRegistrationCommand() = default;
	SceneRegistrationCommand(const SceneRegistrationCommand&) = delete;
	SceneRegistrationCommand& operator=(const SceneRegistrationCommand&) = delete;
	virtual ~SceneRegistrationCommand()
	{
		//DebugMsg::out("\n\nDeleting SceneRegistrationCommand");
	};

	virtual void execute() = 0;

private:

};
#endif // !SceneRegistrationCommand_H
