#include "Cottage.h"
#include "../Lediri Engine/GameObjectDependencies.h"

Cottage::Cottage()
{
	Vect LightColor(1.50f, 1.50f, 1.50f, 1.0f);
	Vect LightPos(1.0f, 1.0f, 1.0f, 1.0f);
	pGObj_Cottage = new GraphicsObject_TextureLight(ModelManager::getModel("Cottage"), ShaderManager::getShader("ShaderObject_textureLight"), TextureManager::getTexture("CabinTex"), LightColor, LightPos);

	Matrix world;

	CotScale.set(SCALE, 1.0f, 1.0f, 1.0f);
	CotRot.set(IDENTITY);
	CotPos.set(0, 20, 0);
	world = CotScale * CotRot * Matrix(TRANS, CotPos);
	pGObj_Cottage->SetWorld(world);

	UpdateObject::SubmitUpdateRegistration();
	DrawObject::SubmitDrawRegistration();
	InputObject::SubmitInputRegistration(AZUL_KEY::KEY_F1, INPUT_EVENT_TYPE::KEY_PRESS);
	InputObject::SubmitInputRegistration(AZUL_KEY::KEY_F2, INPUT_EVENT_TYPE::KEY_PRESS);

	CollisionObject::SubmitCollisionRegistration<Cottage>(this);
	SetColliderModel(pGObj_Cottage->getModel(), COLLISION_VOLUME_TYPE::OBB);

}

void Cottage::Update()
{
	//if (Keyboard::GetKeyState(AZUL_KEY::KEY_W))
	//{
	//	CotPos += Vect(0, 0, 1) * CotRot * .8f;
	//	//vPosTurret += Vect(0, 0, 1) * mTankRot * TankTransSpeed;
	//}
	//else if (Keyboard::GetKeyState(AZUL_KEY::KEY_S))
	//{
	//	CotPos += Vect(0, 0, 1) * CotRot * -.8f;
	//	//vPosTurret += Vect(0, 0, 1) 
	//}

	//if (Keyboard::GetKeyState(AZUL_KEY::KEY_A))
	//{
	//	CotRot *= Matrix(ROT_Y, CotRotAng);
	//}
	//else if (Keyboard::GetKeyState(AZUL_KEY::KEY_D))
	//{
		//CotRot *= Matrix(ROT_Y, -CotRotAng);
	//}

	Matrix world = CotScale * CotRot * Matrix(TRANS, CotPos);

	pGObj_Cottage->SetWorld(world);

	this->UpdateCollisionData(world);
	SceneManager::getCurScene()->GetCurCam()->updateCamera();

}

void Cottage::Draw()
{
	pGObj_Cottage->Render(SceneManager::getCurScene()->GetCurCam());
}

void Cottage::KeyPressed(AZUL_KEY k)
{

	switch (k)
	{

	case AZUL_KEY::KEY_F1:
		SceneManager::getCurScene()->SetGodCam();
		break;
	case AZUL_KEY::KEY_F2:
		SceneManager::getCurScene()->UnsetGodCam();
		break;
	default:
		break;
	}

}

Cottage::~Cottage()
{
	delete pGObj_Cottage;
}