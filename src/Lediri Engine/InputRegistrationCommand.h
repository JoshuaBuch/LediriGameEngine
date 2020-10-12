#ifndef InputRegistrationCommand_H
#define InputRegistrationCommand_H

#include "CommandBase.h"
#include "InputEventTypeEnum.h"

class InputObject;

class InputRegistrationCommand : public CommandBase
{
public:
	InputRegistrationCommand(InputObject* io);
	InputRegistrationCommand(const InputRegistrationCommand&) = delete;
	InputRegistrationCommand& operator=(const InputRegistrationCommand&) = delete;
	~InputRegistrationCommand(); //base class has to have virtual destructor

	void execute();
	void KeyNInputTypeSet(AZUL_KEY k, INPUT_EVENT_TYPE iet);
private:

	InputObject* ptrIO;
	AZUL_KEY key;
	INPUT_EVENT_TYPE myIET;

};
#endif // !InputRegistrationCommand_H
