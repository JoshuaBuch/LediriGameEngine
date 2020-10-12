#ifndef VisualizerBroker_H
#define VisualizerBroker_H

#include <list>

class CommandBase;

class VisualizerBroker
{
public:
	VisualizerBroker() = default;
	VisualizerBroker(const VisualizerBroker&) = delete;
	VisualizerBroker& operator=(const VisualizerBroker&) = delete;
	~VisualizerBroker() {};

	void addCommand(CommandBase* cmd);
	void executeCommands(); //iterate through list and call each command's execute function.

private:
	using CommandList = std::list<CommandBase*>;

	CommandList CmdList;
	CommandList::iterator it;
};
#endif // !VisualizerBroker_H
