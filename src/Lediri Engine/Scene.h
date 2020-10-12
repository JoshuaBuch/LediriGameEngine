#ifndef _SCENE
#define _SCENE

#include "SceneRegistrationBroker.h"
#include "VisualizerBroker.h"
#include "UpdateObjectManager.h"
#include "DrawObjectManager.h"
#include "AlarmObjectManager.h"
#include "KeyboardEventManager.h"
#include "CollisionManager.h"
#include "SingleKeyEventManager.h" //temporary
#include "Camera Manager.h"

class UpdateObject;
class UpdateObjectManager;
class DrawObject;
class DrawObjectManager;
class AlarmObject;
class AlarmObjectManager;
class InputObject;
class CommandBase;

class Scene : public Align16
{
public:

	Scene();
	Scene(const Scene&) = delete;
	Scene& operator=(const Scene&) = delete;
	virtual ~Scene();

	virtual void Initialize();

	//User functions
	Camera* GetCurCam();
	Camera* GetSpriteCam();
	void SetDefaultCamera();
	void SetGodCam();
	void UnsetGodCam();

	template <typename C1, typename C2>
	void SetCollisionPair()
	{
		this->COMan.SetCollisionPair<C1, C2>();
	};

	template <typename C>
	void SetCollisionSelf()
	{
		this->COMan.SetCollisionSelf<C>();
	};

	template <typename C>
	void SendCollisionDeleteCmd(C* c)
	{
		this->COMan.SaveCollisionDeleteCmd(c);
	}

private:

	friend class SceneManager;
	friend class DrawObject;
	friend class UpdateObject;
	friend class AlarmObject;
	friend class InputObject;
	friend class CollisionObject;
	friend class GameObject;
	friend class Visualizer;

	UpdateObjectManager UOMan;
	DrawObjectManager DOMan;
	AlarmObjectManager AOMan;
	KeyboardEventManager KbEM;
	CollisionManager COMan;
	SceneRegistrationBroker sceneBroker;
	VisualizerBroker visualBroker;
	CameraManager CamMan;

	virtual void Draw();
	virtual void Update();
	virtual void SceneEnd() {};

	void SubmitCommand(CommandBase* cmd);
	void SubmitVisualizerCommand(CommandBase* cmd);

	void Register(UpdateObject* up);
	void Deregister(UpdateObjectManager::StorageListRef ref);

	void Register(DrawObject* dr);
	void Deregister(DrawObjectManager::StorageListRef ref);

	void Register(float t, AlarmObject* al, AlarmObjectManager::ALARM_ID id);
	void Deregister(AlarmObjectManager::StorageMapRef& ref);

	void Register(InputObject* io, AZUL_KEY k, INPUT_EVENT_TYPE IET);
	void Deregister(InputObject* pIO, AZUL_KEY k, INPUT_EVENT_TYPE iet);

};
#endif // !_SCENE
