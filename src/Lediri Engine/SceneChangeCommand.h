#ifndef SceneChangeCommand_H
#define SceneChangeCommand_H

#include "SceneChangeCommandBase.h"

class Scene;

class SceneChangeCommand : public SceneChangeCommandBase
{
public:
	SceneChangeCommand();
	SceneChangeCommand(const SceneChangeCommand&) = delete;
	SceneChangeCommand& operator=(const SceneChangeCommand&) = delete;
	virtual ~SceneChangeCommand()
	{
		//DebugMsg::out("\nDeleting CommandBase object"); 
	}; //base class has to have virtual destructor

	void execute();

private:
	friend class SceneManager;

	Scene* ptrScene;

	void SetScene(Scene* s);
};
#endif // !SceneChangeCommand_H
