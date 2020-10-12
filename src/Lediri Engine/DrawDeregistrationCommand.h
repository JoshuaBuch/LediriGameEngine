#ifndef DRAWDEREGISTRATIONCOMMAND_H
#define DRAWDEREGISTRATIONCOMMAND_H

#include "CommandBase.h"

class DrawObject;


class DrawDeregistrationCommand : public CommandBase
{
public:
	DrawDeregistrationCommand(DrawObject* drawObject);
	DrawDeregistrationCommand(const DrawDeregistrationCommand&) = delete;
	DrawDeregistrationCommand& operator=(const DrawDeregistrationCommand&) = delete;
	~DrawDeregistrationCommand(); //base class has to have virtual destructor

	void execute();
private:

	DrawObject* ptrDO;

};
#endif // !DRAWDEREGISTRATIONCOMMAND_H
