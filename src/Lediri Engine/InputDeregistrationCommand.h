#ifndef InputDeregistrationCommand_H
#define InputDeregistrationCommand_H

#include "CommandBase.h"
#include "InputEventTypeEnum.h"

class InputObject;

class InputDeregistrationCommand : public CommandBase
{
public:
	InputDeregistrationCommand(InputObject* io);
	InputDeregistrationCommand(const InputDeregistrationCommand&) = delete;
	InputDeregistrationCommand& operator=(const InputDeregistrationCommand&) = delete;
	~InputDeregistrationCommand(); //base class has to have virtual destructor

	void execute();
	void KeyNInputTypeSet(AZUL_KEY k, INPUT_EVENT_TYPE iet);
private:

	InputObject * ptrIO;
	AZUL_KEY key;
	INPUT_EVENT_TYPE myIET;

};
#endif // !InputDeregistrationCommand_H