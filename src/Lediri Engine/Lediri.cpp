#include "Lediri.h"
#include "ModelManagerAttorney.h"
#include "ShaderManagerAttorney.h"
#include "TextureManagerAttorney.h"
#include "TimeManagerAttorney.h"
#include "ImageManagerAttorney.h"
#include "TerrainObjectManagerAttorney.h"

Lediri* Lediri::ptrInstance = nullptr;

//-----------------------------------------------------------------------------
// Lediri::Initialize()
//		Allows the engine to perform any initialization it needs to before 
//      starting to run.  This is where it can query for any required services 
//      and load any non-graphic related content. 
//-----------------------------------------------------------------------------
void Lediri::Initialize()
{
	Lediri::GameInitialize();
	//current clear point
}

//-----------------------------------------------------------------------------
// Lediri::LoadContent()
//		Allows you to load all content needed for your engine,
//	    such as objects, graphics, etc.
//-----------------------------------------------------------------------------
void Lediri::LoadContent()
{
	Lediri::LoadResources();
}

//-----------------------------------------------------------------------------
// Lediri::Update()
//      Called once per frame, update data, tranformations, etc
//      Use this function to control process order
//      Input, AI, Physics, Animation, and Graphics
//-----------------------------------------------------------------------------

void Lediri::Update()
{

	TimeManagerAttorney::ProcessTime(this->GetTimeInSeconds());
	SceneManager::Update();
}

//-----------------------------------------------------------------------------
// Lediri::Draw()
//		This function is called once per frame
//	    Use this for draw graphics to the screen.
//      Only do rendering here
//-----------------------------------------------------------------------------
void Lediri::Draw()
{
	SceneManager::Draw();
}



//-----------------------------------------------------------------------------
// Lediri::UnLoadContent()
//       unload content (resources loaded above)
//       unload all content that was loaded before the Engine Loop started
//-----------------------------------------------------------------------------
void Lediri::UnLoadContent()
{
	//general clean up.
	Visualizer::DeleteVisualizer();

	ModelManagerAttorney::DeleteModels();
	ModelManagerAttorney::DeleteModelManager();

	TextureManagerAttorney::DeleteTextures();
	TextureManagerAttorney::DeleteTextureManager();

	ImageManagerAttorney::DeleteImages();
	ImageManagerAttorney::DeleteImageManager();

	ShaderManagerAttorney::DeleteShaders();
	ShaderManagerAttorney::DeleteShaderManager();

	TerrainObjectManagerAttorney::DeleteTerrainObjects();
	TerrainObjectManagerAttorney::DeleteTerrainObjectManager();

	SceneManager::DeleteSceneManager();

	TimeManagerAttorney::DeleteTimeManager();

}

void Lediri::privSetWindowName(const char* wn)
{
	this->setWindowName(wn);
}

void Lediri::privSetWidthHeight(int w, int h)
{
	this->setWidthHeight(w, h);
}

void Lediri::privSetClearColor(float r, float g, float b, float a)
{
	this->SetClearColor(r, g, b, a);
}

int Lediri::privGetWidth()
{
	return this->getWidth();
}

int Lediri::privGetHeight()
{
	return this->getHeight();
}

void Lediri::privTerminateLediri()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}