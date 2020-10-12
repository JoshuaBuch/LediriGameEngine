#ifndef GameObjectExitCommand_H
#define GameObjectExitCommand_H

#include "CommandBase.h"

class GameObject;

class GameObjectExitCommand : public CommandBase
{
public:
	GameObjectExitCommand(GameObject* go);
	GameObjectExitCommand(const GameObjectExitCommand&) = delete;
	GameObjectExitCommand& operator=(const GameObjectExitCommand&) = delete;
	~GameObjectExitCommand() {}; //base class has to have virtual destructor

	void execute();
private:

	GameObject * ptrGO;
};
#endif // !GameObjectExitCommand_H
