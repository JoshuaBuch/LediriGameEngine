#include "Plane.h"

Plane::Plane()
{
	pGObj_Plane = new GraphicsObject_TextureFlat(ModelManager::getModel("ModelPlane"), ShaderManager::getShader("ShaderObject_texture"), TextureManager::getTexture("GrassTex"));


	Matrix world = Matrix(SCALE, 4000, 400, 4000);
	pGObj_Plane->SetWorld(world);

	//DebugMsg::out("\n\nPlane is trying to register to draw manager");
	DrawObject::SubmitDrawRegistration();
	//CollisionObject::SubmitCollisionRegistration<Plane>(this);

}

void Plane::Update()
{

}

void Plane::Draw()
{
	pGObj_Plane->Render(SceneManager::getCurScene()->GetCurCam());
}

Plane::~Plane()
{
	//DebugMsg::out("\n\nPlane is being deleted");
	delete pGObj_Plane;
}