#ifndef DRAWREGISTRATIONCOMMAND_H
#define DRAWREGISTRATIONCOMMAND_H

#include "CommandBase.h"

class DrawObject;


class DrawRegistrationCommand : public CommandBase
{
public:
	DrawRegistrationCommand(DrawObject* drawObject);
	DrawRegistrationCommand(const DrawRegistrationCommand&) = delete;
	DrawRegistrationCommand& operator=(const DrawRegistrationCommand&) = delete;
	~DrawRegistrationCommand(); //base class has to have virtual destructor

	void execute();
private:

	DrawObject * ptrDO;

};
#endif // !DRAWREGISTRATIONCOMMAND_H
