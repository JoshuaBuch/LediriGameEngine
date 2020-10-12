#ifndef _LEDIRI
#define _LEDIRI

#include "AzulCore.h"
#include "ModelManager.h"
#include "TextureManager.h"
#include "ShaderManager.h"
#include "Camera Manager.h"
#include "ImageManager.h"
#include "TerrainObjectManager.h"
#include "SceneManager.h"
#include "GameObject.h"
#include "InputEventTypeEnum.h"	


using namespace std;

class Lediri : public Engine
{
public:

	// Methods Users need to overload
	static void pubInitialize(){ Instance().Initialize();};
	static void pubLoadContent() { Instance().LoadContent(); };
	static void pubUpdate() { Instance().Update(); };
	static void pubDraw() { Instance().Draw(); };
	static void pubUnLoadContent() { Instance().UnLoadContent(); };
	static float pubGetTimeInSeconds() { return Instance().GetTimeInSeconds(); };
	static void pubRun() { Instance().run(); };

	static void LoadResources() { Instance().privLoadResources(); };

	static void pubSetWindowName(const char* wn) { Instance().privSetWindowName(wn); };
	static void pubSetWidthHeight(int w, int h) { Instance().privSetWidthHeight(w, h); };
	static void pubSetClearColor(float r, float g, float b, float a) { Instance().privSetClearColor(r, g, b, a); };
	static int pubGetWidth() { return Instance().privGetWidth(); };
	static int pubGetHeight() { return Instance().privGetHeight(); };

	static void GameInitialize() { Instance().privGameInitialize(); };
	
	static void TerminateLediri() { Instance().privTerminateLediri(); };
	

private:	
	// legacy
	Lediri() {};
	Lediri(const Lediri&) = delete;
	Lediri& operator=(const Lediri&) = delete;
	~Lediri() {};
	//Lediri(const char* windowName, const int Width, const int Height);

	static Lediri* ptrInstance;

	static Lediri& Instance()
	{
		if (!ptrInstance)
		{
			ptrInstance = new Lediri();
		}
		return *ptrInstance;
	}


	virtual void Initialize() override;
	virtual void LoadContent() override;
	virtual void Update() override;
	virtual void Draw() override;
	virtual void UnLoadContent() override;

	void privLoadResources();
	void privSetWindowName(const char* wn);
	void privSetWidthHeight(int w, int h);
	void privSetClearColor(float r, float g, float b, float a);
	int privGetWidth();
	int privGetHeight();
	void privGameInitialize();

	void privTerminateLediri();
};


#endif // _LEDIRI