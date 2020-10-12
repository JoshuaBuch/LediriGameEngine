#ifndef CollisionRegistrationCommand_H
#define CollisionRegistrationCommand_H

#include "SceneRegistrationCommand.h"
#include "CollisionObjectGroup.h"

template <typename C>
class CollisionRegistrationCommand : public SceneRegistrationCommand
{
public:
	CollisionRegistrationCommand(C* c)
	{
		pCO = c;
	};
	CollisionRegistrationCommand(const CollisionRegistrationCommand&) = delete;
	CollisionRegistrationCommand& operator=(const CollisionRegistrationCommand) = delete;
	~CollisionRegistrationCommand()
	{

	}

	virtual void execute() override
	{
		CollisionObjectGroup<C>::Register(pCO);
		delete this;
	}

private:
	C* pCO;

};
#endif // !CollisionRegistrationCommand_H
