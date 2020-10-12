#ifndef GameObjectEntryCommand_H
#define GameObjectEntryCommand_H

#include "CommandBase.h"

class GameObject;

class GameObjectEntryCommand : public CommandBase
{
public:
	GameObjectEntryCommand(GameObject* go);
	GameObjectEntryCommand(const GameObjectEntryCommand&) = delete;
	GameObjectEntryCommand& operator=(const GameObjectEntryCommand&) = delete;
	~GameObjectEntryCommand() {}; //base class has to have virtual destructor

	void execute();
private:

	GameObject * ptrGO;
};
#endif // !GameObjectEntryCommand_H

