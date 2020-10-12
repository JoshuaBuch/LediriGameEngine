#ifndef UPDATEREGISTRATIONCOMMAND_H
#define UPDATEREGISTRATIONCOMMAND_H

#include "CommandBase.h"

class UpdateObject;


class UpdateRegistrationCommand : public CommandBase
{
public:
	UpdateRegistrationCommand(UpdateObject* updateObject);
	UpdateRegistrationCommand(const UpdateRegistrationCommand&) = delete;
	UpdateRegistrationCommand& operator=(const UpdateRegistrationCommand&) = delete;
	~UpdateRegistrationCommand(); //base class has to have virtual destructor

	void execute();
private:

	UpdateObject * ptrUO;

};
#endif // !UPDATEREGISTRATIONCOMMAND_H