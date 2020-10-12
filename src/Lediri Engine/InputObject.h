#ifndef _InputOBJECT
#define _InputOBJECT

#include "RegistrationStateEnum.h"
#include "InputEventTypeEnum.h"
#include <map>
#include "AzulCore.h"

class InputRegistrationCommand;
class InputDeregistrationCommand;

class InputObject
{
public:

	InputObject();
	virtual ~InputObject();

	virtual void KeyPressed(AZUL_KEY k) { k; };
	virtual void KeyReleased(AZUL_KEY k) { k; };

protected:
	void SubmitInputRegistration(AZUL_KEY k, INPUT_EVENT_TYPE iet);
	void SubmitInputDeregistration(AZUL_KEY k, INPUT_EVENT_TYPE iet);

private:
	friend class InputObjectAttorney;

	using StorageMap = std::map<InputObject*, INPUT_EVENT_TYPE>;

	InputRegistrationCommand* pRegCmd;
	InputDeregistrationCommand* pDeregCmd;

	void SceneRegistration(AZUL_KEY k, INPUT_EVENT_TYPE iet);
	void SceneDeregistration(AZUL_KEY k, INPUT_EVENT_TYPE iet);

	RegistrationState curRegState;

};
#endif // !_InputOBJECT