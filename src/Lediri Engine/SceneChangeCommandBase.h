#ifndef SceneChangeCommandBase_H
#define SceneChangeCommandBase_H

#include "CommandBase.h"

class SceneChangeCommandBase : public CommandBase
{
public:
	SceneChangeCommandBase() = default;
	SceneChangeCommandBase(const SceneChangeCommandBase&) = delete;
	SceneChangeCommandBase& operator=(const SceneChangeCommandBase&) = delete;
	virtual ~SceneChangeCommandBase()
	{
		//DebugMsg::out("\nDeleting CommandBase object"); 
	}; //base class has to have virtual destructor

	virtual void execute() = 0;
private:

};
#endif // !SceneChangeCommandBase_H
