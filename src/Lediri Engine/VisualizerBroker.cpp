#include "VisualizerBroker.h"
#include "CommandBase.h"

void VisualizerBroker::addCommand(CommandBase* cmd)
{
	CmdList.push_back(cmd);
}

void VisualizerBroker::executeCommands()
{
	for (it = CmdList.begin(); it != CmdList.end(); it++)
	{
		(*it)->execute();
	}
	CmdList.clear();
}