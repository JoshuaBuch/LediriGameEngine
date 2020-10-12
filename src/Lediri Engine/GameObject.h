#ifndef _GAMEOBJECT
#define _GAMEOBJECT
#include "UpdateObject.h"
#include "InputObject.h"
#include "DrawObject.h"
#include "AlarmObject.h"
#include "CollisionObject.h"
#include "PhysicsObject.h"

class GameObjectEntryCommand;
class GameObjectExitCommand;

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	GameObjects are a collection of commonly utilized functions. GameObjects are used to Draw(Render), Update, Read key press/release,
/// 			set alarms, and test collision. </summary>
///
/// <remarks>	Joshua, 3/1/2018. </remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

class GameObject : public DrawObject, public UpdateObject, public InputObject, public AlarmObject, public CollisionObject, public Align16
{
public:
	GameObject();
	virtual ~GameObject();
	void SubmitEntry();
	void SubmitExit();

private:

	friend class GameObjectEntryCommand;
	friend class GameObjectExitCommand;

	void ConnectToScene();
	void DisconnectFromScene();
	virtual void SceneEntry() {};
	virtual void SceneExit() {};

	GameObjectEntryCommand* pRegCmd;
	GameObjectExitCommand* pDeregCmd;
	RegistrationState curRegState;
};
#endif // !_GAMEOBJECT