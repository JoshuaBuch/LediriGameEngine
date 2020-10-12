#ifndef _SCENEMANAGER
#define _SCENEMANAGER

//#include "Lediri.h"
#include "Scene.h"

class Scene;
class SceneChangeCommandBase;
class SceneChangeNullCommand;
class SceneChangeCommand;

class SceneManager
{
public:
	static Scene* getCurScene() { return Instance().privGetCurScene(); };
	static void SetNextScene(Scene* s) { Instance().privSetNextScene(s); };
	static void Update() { Instance().privUpdate(); };
	static void Draw() { Instance().privDraw(); };
	static void Initialize() { Instance().privInitialize(); };
	static void DeleteScene() { Instance().privDeleteScene(); };

	static void DeleteSceneManager() { Instance().privDeleteSceneManager(); };

private:

	friend SceneChangeCommand;

	SceneManager();
	SceneManager(const SceneManager&) = delete;
	SceneManager& operator=(const SceneManager&) = delete;
	~SceneManager();

	

	static SceneManager* ptrInstance;

	static SceneManager& Instance()
	{
		if (!ptrInstance)
		{
			ptrInstance = new SceneManager();
		}
		return *ptrInstance;
	}

	SceneChangeNullCommand* pSceneNullCmd;
	SceneChangeCommand* pSceneChangeCmd;
	SceneChangeCommandBase* pCurSceneCmd;

	Scene* curScene = nullptr;
	Scene* privGetCurScene();

	void privSetNextScene(Scene* s);
	void privUpdate();
	void privDraw();
	void privInitialize();
	void privDeleteScene();

	void privDeleteSceneManager();
	
	static void SetScene(Scene* s);
};

#endif // !_SCENEMANAGER

