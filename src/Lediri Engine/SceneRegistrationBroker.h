#ifndef SCENEREGISTRATIONBROKER_H
#define SCENEREGISTRATIONBROKER_H

#include <list>

class CommandBase;

class SceneRegistrationBroker
{
public:
	SceneRegistrationBroker() = default;
	SceneRegistrationBroker(const SceneRegistrationBroker&) = delete;
	SceneRegistrationBroker& operator=(const SceneRegistrationBroker&) = delete;
	~SceneRegistrationBroker() {};

	void addCommand(CommandBase* cmd);
	void executeCommands(); //iterate through list and call each command's execute function.

private:
	using CommandList = std::list<CommandBase*>;

	CommandList CmdList;
	CommandList::iterator it;
	
};

#endif // !SCENEREGISTRATIONBROKER_H
