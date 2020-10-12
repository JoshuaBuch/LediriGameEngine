#include "PhysicsDemoScene.h"
#include "Cube.h"

void PhysicsDemoScene::Initialize()
{
	this->SetDefaultCamera();

	pPlaneGO = new Plane();
	pAxisGO = new Axis();
	pCubeGO = new Cube();
}

void PhysicsDemoScene::SceneEnd()
{
	delete pPlaneGO;
	delete pAxisGO;
	delete pCubeGO;
}