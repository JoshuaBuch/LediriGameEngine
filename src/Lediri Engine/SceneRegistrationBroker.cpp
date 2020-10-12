#include "SceneRegistrationBroker.h"
#include "CommandBase.h"

void SceneRegistrationBroker::addCommand(CommandBase* cmd)
{
	CmdList.push_back(cmd);
}

void SceneRegistrationBroker::executeCommands()
{
	for (it = CmdList.begin(); it != CmdList.end(); it++)
	{
		(*it)->execute();
	}
	CmdList.clear();
}