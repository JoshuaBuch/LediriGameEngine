#include "Frigate.h"
#include "Bullet.h"
#include "BulletFactory.h"
#include "../Lediri Engine/CollisionObjectGroup.h"
#include "../Lediri Engine/Visualizer.h"
#include "TestScene.h"

Frigate::Frigate()
{
	Vect LightColor(1.50f, 1.50f, 1.50f, 1.0f);
	Vect LightPos(1.0f, 1.0f, 1.0f, 1.0f);
	pGObj_FT = new GraphicsObject_TextureLight(ModelManager::getModel("ModelSpaceFrigate"), ShaderManager::getShader("ShaderObject_textureLight"), TextureManager::getTexture("SpaceFrigateTex"), LightColor, LightPos);

	Matrix world;

	ShipScale.set(SCALE, 0.5f, 0.5f, 0.5f);
	ShipRot.set(IDENTITY);
	ShipPos.set(0, 20, 0);
	world = ShipScale * ShipRot * Matrix(TRANS, ShipPos);
	pGObj_FT->SetWorld(world);

	UpdateObject::SubmitUpdateRegistration();
	DrawObject::SubmitDrawRegistration();

	CollisionObject::SubmitCollisionRegistration<Frigate>(this);
	SetColliderModel(pGObj_FT->getModel(), COLLISION_VOLUME_TYPE::AABB );

}

Frigate::Frigate(Vect ranPos)
{
	Vect LightColor(1.50f, 1.50f, 1.50f, 1.0f);
	Vect LightPos(1.0f, 1.0f, 1.0f, 1.0f);
	pGObj_FT = new GraphicsObject_TextureLight(ModelManager::getModel("ModelSpaceFrigate"), ShaderManager::getShader("ShaderObject_textureLight"), TextureManager::getTexture("SpaceFrigateTex"), LightColor, LightPos);

	Matrix world;

	ShipScale.set(SCALE, 0.5f, 0.5f, 0.5f);
	ShipRot.set(IDENTITY);
	//ShipRot.set(ROT_Y, 3.14f * .25f);
	ShipPos = ranPos;
	world = ShipScale * ShipRot * Matrix(TRANS, ShipPos);
	pGObj_FT->SetWorld(world);

	UpdateObject::SubmitUpdateRegistration();
	DrawObject::SubmitDrawRegistration();

	ShipRotAng = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (.05 - .01) + 0.001));

	//AlarmObject::SubmitAlarmRegistration(2.0f, AlarmObjectManager::ALARM_0);
	//AlarmObject::SubmitAlarmRegistration(2.0f, AlarmObjectManager::ALARM_1);
	//AlarmObject::SubmitAlarmRegistration(2.0f, AlarmObjectManager::ALARM_2);
	//AlarmObject::SubmitAlarmRegistration(2.0f, AlarmObjectManager::ALARM_3);


	CollisionObject::SubmitCollisionRegistration<Frigate>(this);
	SetColliderModel(pGObj_FT->getModel(), COLLISION_VOLUME_TYPE::OBB);
}

void Frigate::Update()
{
	//Matrix world = ShipScale * ShipRot * Matrix(TRANS, ShipPos);
	//if (ShipRotAng == 0.0f)
	//{
	//	pGObj_FT->SetWorld(world);
	//	UpdateCollisionData(world);
	//}
	//
	//else
	//{
	//	ShipPos += Vect(0, 0, 1) * ShipRot * ShipTransSpeed;
	//	ShipRot *= Matrix(ROT_Y, -ShipRotAng);
	//	ShipRot *= Matrix(ROT_X, -ShipRotAng);

	//	world = ShipScale * ShipRot * Matrix(TRANS, ShipPos);
	//}

	//pGObj_FT->SetWorld(world);

	//if (Keyboard::GetKeyState(AZUL_KEY::KEY_W))
	//{
	//	ShipPos += Vect(0, 0, 1) * ShipRot * .8f;
	//	//vPosTurret += Vect(0, 0, 1) * mTankRot * TankTransSpeed;
	//}
	//else if (Keyboard::GetKeyState(AZUL_KEY::KEY_S))
	//{
	//	ShipPos += Vect(0, 0, 1) * ShipRot * -.8f;
	//	//vPosTurret += Vect(0, 0, 1) 
	//}

	//if (Keyboard::GetKeyState(AZUL_KEY::KEY_A))
	//{
	//	ShipRot *= Matrix(ROT_Y, ShipRotAng);
	//}
	//else if (Keyboard::GetKeyState(AZUL_KEY::KEY_D))
	//{
	//	ShipRot *= Matrix(ROT_Y, -ShipRotAng);
	//}

	//DebugMsg::out("\n\n%d", ShipRot.isRotation());
	//ShipRot *= Matrix(ROT_Y, 0.02f);
	Matrix world = ShipScale * ShipRot * Matrix(TRANS, ShipPos);
	

	pGObj_FT->SetWorld(world);

	this->UpdateCollisionData(world);
	SceneManager::getCurScene()->GetCurCam()->updateCamera();

}

void Frigate::Alarm0()
{
	DebugMsg::out("\n\nFRIGATE Alarm ZERO");
}

void Frigate::Alarm1()
{
	DebugMsg::out("\n\nFRIGATE Alarm ONE");
}

void Frigate::Alarm2()
{
	DebugMsg::out("\n\nFRIGATE Alarm TWO");
}

void Frigate::Alarm3()
{
	//DebugMsg::out("\n\nFRIGATE Alarm THREE");
}

void Frigate::Alarm4()
{
	//DebugMsg::out("\n\nFRIGATE Alarm FOUR");
}

void Frigate::Draw()
{
	pGObj_FT->Render(SceneManager::getCurScene()->GetCurCam());
}
	
void Frigate::Collision(Tank* f)
{
	f;
	DebugMsg::out("Frigate colliding with Tank\n");
}

Matrix Frigate::getFrigateWorld()
{
	return (ShipScale * ShipRot * Matrix(TRANS, ShipPos));
}

Frigate::~Frigate()
{
	//DebugMsg::out("\n\nFrigate %s is being deleted");
	delete pGObj_FT;
}