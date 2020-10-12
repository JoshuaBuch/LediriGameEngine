#ifndef CollisionDeregistrationCommand_H
#define CollisionDeregistrationCommand_H

#include "SceneRegistrationCommand.h"
#include "CollisionObjectGroup.h"

template <typename C>
class CollisionDeregistrationCommand : public SceneRegistrationCommand
{
public:
	CollisionDeregistrationCommand(C* c)
	{
		pCO = c;
	};
	CollisionDeregistrationCommand(const CollisionDeregistrationCommand&) = delete;
	CollisionDeregistrationCommand& operator=(const CollisionDeregistrationCommand) = delete;
	~CollisionDeregistrationCommand()
	{

	}

	virtual void execute() override
	{
		CollisionObjectGroup<C>::Deregister(pCO);
		delete this;
	}

private:
	C* pCO;

};
#endif // !CollisionDeregistrationCommand_H
