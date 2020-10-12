#ifndef UPDATEDEREGISTRATIONCOMMAND_H
#define UPDATEDEREGISTRATIONCOMMAND_H

#include "CommandBase.h"

class UpdateObject;


class UpdateDeregistrationCommand : public CommandBase
{
public:
	UpdateDeregistrationCommand(UpdateObject* updateObject);
	UpdateDeregistrationCommand(const UpdateDeregistrationCommand&) = delete;
	UpdateDeregistrationCommand& operator=(const UpdateDeregistrationCommand&) = delete;
	~UpdateDeregistrationCommand(); //base class has to have virtual destructor

	void execute();
private:

	UpdateObject * ptrUO;

};
#endif // !UPDATEDEREGISTRATIONCOMMAND_H
