#ifndef SceneChangeNullCommand_H
#define SceneChangeNullCommand_H

#include "SceneChangeCommandBase.h"

class SceneChangeNullCommand : public SceneChangeCommandBase
{
public:
	SceneChangeNullCommand() = default;
	SceneChangeNullCommand(const SceneChangeNullCommand&) = delete;
	SceneChangeNullCommand& operator=(const SceneChangeNullCommand&) = delete;
	~SceneChangeNullCommand()
	{
		//DebugMsg::out("\nDeleting CommandBase object"); 
	}; //base class has to have virtual destructor

	void execute() {};
private:

};
#endif // !SceneChangeNullCommand_H
