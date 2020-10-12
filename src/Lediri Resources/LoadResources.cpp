#include "../Lediri Engine/Lediri.h"

#include "../User Files/DemoScene.h"
#include "../User Files//TestScene.h"
#include "../User Files/TerrainScene.h"
#include "../User Files/PhysicsDemoScene.h"
#include "../User Files/Level_1.h"
#include "../User Files/Level_2.h"
#include "../User Files/TitleScene.h"
#include "../User Files/WinScene.h"

void Lediri::privLoadResources()
{
	//Load Models
	ModelManager::loadModel("ModelAxis", "Axis.azul");
	ModelManager::loadModel("ModelPlane", "Plane.azul");
	ModelManager::loadModel("ModelSpaceFrigate", "space_frigate.azul");
	ModelManager::loadModel("Bullet", "sphere.azul");
	ModelManager::loadModel("TankBody", "t99body.azul");
	ModelManager::loadModel("TankTurret", "t99turret.azul");
	ModelManager::loadModel("Cottage", "Cottage.azul");
	ModelManager::loadModel("Spaceship", "Spaceship.azul");

	//load Textures
	TextureManager::loadTexture("SpaceFrigateTex", "space_frigate.tga");
	TextureManager::loadTexture("TextPlane", "grid.tga");
	TextureManager::loadTexture("BulletTex", "sphere.tga");
	TextureManager::loadTexture("StitchTex", "reticle.tga");
	TextureManager::loadTexture("TankBodyTex", "body.tga");
	TextureManager::loadTexture("TankTracksTex", "track.tga");
	TextureManager::loadTexture("GrassTex", "grass.tga");
	TextureManager::loadTexture("CabinTex", "Cabintexture.tga");
	TextureManager::loadTexture("HMTest16", "HMTest16.tga");
	TextureManager::loadTexture("h4x4", "h4x4.tga");
	TextureManager::loadTexture("BlueFloorTex", "BlueFloor.tga");
	TextureManager::loadTexture("JTBodyTex", "JumpTankBodyTexture.tga");
	TextureManager::loadTexture("JTHeadTex", "JumpTankHeadTexture.tga");
	TextureManager::loadTexture("dtest", "dtest.tga");
	TextureManager::loadTexture("plain4x4", "plain4x4.tga");
	TextureManager::loadTexture("EnemyBulletTex", "BulletTexture.tga");
	TextureManager::loadTexture("JTBulletTex", "JTBulletTexture.tga");
	TextureManager::loadTexture("JetTexture", "JetTexture.tga");

	//floor textures
	TextureManager::loadTexture("FloorTex2", "FloorTexture-02.tga");

	//sprite textures
	TextureManager::loadTexture("JumpTankTitleTex", "JumpTankTitle.tga");
	TextureManager::loadTexture("ArmorTex", "ArmorPipSprite.tga");
	TextureManager::loadTexture("L1ObjectiveTex", "JTL1Objective.tga");
	TextureManager::loadTexture("L2ObjectiveTex", "JTL2Objective.tga");
	TextureManager::loadTexture("JumpTankWinTex", "JumpTankWinScreen.tga");

	//load Images
	ImageManager::loadImage("TargetImage", "StitchTex");
	ImageManager::loadImage("TitleImage", "JumpTankTitleTex");
	ImageManager::loadImage("ArmorImage", "ArmorTex");
	ImageManager::loadImage("L1ObjectiveImage", "L1ObjectiveTex");
	ImageManager::loadImage("L2ObjectiveImage", "L2ObjectiveTex");
	ImageManager::loadImage("WinImage", "JumpTankWinTex");
	

	//load Shaders
	ShaderManager::loadShader("ShaderObject_texture", "textureFlatRender");
	ShaderManager::loadShader("ShaderObject_textureLight", "textureLightRender");
	ShaderManager::loadShader("ShaderObject_constantColor", "colorConstantRender");
	ShaderManager::loadShader("ShaderObject_colorNoTexture", "colorNoTextureRender");
	ShaderManager::loadShader("ShaderObject_varyColor", "colorVaryRender");
	ShaderManager::loadShader("SpriteRender", "spriteRender");
	ShaderManager::loadShader("SpriteLineRender", "spriteLineRender");

	//load Terrain
	//TerrainObjectManager::LoadTerrainObject("MainTerrain", "Textures/h4x4.tga", 30.0f, 20.0f, -4, "GrassTex", 1, 1);


	//SceneManager::SetNextScene(new TestScene());
	//SceneManager::SetNextScene(new DemoScene());

	//SceneManager::SetNextScene(new DemoScene());


	SceneManager::SetNextScene(new TitleScene());
	//SceneManager::SetNextScene(new Level_1());
	//SceneManager::SetNextScene(new Level_2());
	//SceneManager::SetNextScene(new WinScene());


	//SceneManager::SetNextScene(new TerrainScene()); //Use this to test terrain
}

void Lediri::privGameInitialize()
{
	Lediri::setWindowName("Lediri");
	Lediri::setWidthHeight(800, 600);
	Lediri::SetClearColor(0.1f, 0.4f, 0.8f, 1.0f);
}




