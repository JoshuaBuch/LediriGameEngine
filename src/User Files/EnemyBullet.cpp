#include "EnemyBullet.h"
#include "JumpTank.h"
#include "EnemyBulletFactory.h"

EnemyBullet::EnemyBullet()
{

	pGObj_EBullet = new GraphicsObject_TextureFlat(ModelManager::getModel("Bullet"), ShaderManager::getShader("ShaderObject_texture"), TextureManager::getTexture("EnemyBulletTex"));

	mScale.set(SCALE, 2.5f, 2.5f, 2.5f);
	mRot.set(IDENTITY);
	vPos.set(0,0,0);
	mWorld = mScale * mRot * Matrix(TRANS, vPos);


	alarmRegistered = true;
	pGObj_EBullet->SetWorld(mWorld);


	//alarmRegistered = true;
	AlarmObject::SubmitAlarmRegistration(2.0f, AlarmObjectManager::ALARM_0);

	SubmitUpdateRegistration();
	SubmitDrawRegistration();
	CollisionObject::SubmitCollisionRegistration<EnemyBullet>(this);

	SetColliderModel(pGObj_EBullet->getModel(), COLLISION_VOLUME_TYPE::BSPHERE);

	UpdateCollisionData(mWorld);

}


EnemyBullet::EnemyBullet(Vect pos, Vect dir, float s, int d)
{

	pGObj_EBullet = new GraphicsObject_TextureFlat(ModelManager::getModel("Bullet"), ShaderManager::getShader("ShaderObject_texture"), TextureManager::getTexture("EnemyBulletTex"));

	mScale.set(SCALE, s, s, s);
	mRot.set(IDENTITY);

	vPos = pos;
	mWorld = mScale * mRot * Matrix(TRANS, vPos);

	//UpdateObject::SubmitUpdateRegistration();
	//DrawObject::SubmitDrawRegistration();
	//CollisionObject::SubmitCollisionRegistration<EnemyBullet>(this);

	SetColliderModel(pGObj_EBullet->getModel(), COLLISION_VOLUME_TYPE::BSPHERE);

	pGObj_EBullet->SetWorld(mWorld);
	UpdateCollisionData(mWorld);

	//alarmRegistered = true;
	//AlarmObject::SubmitAlarmRegistration(2.0f, AlarmObjectManager::ALARM_0);

	//alarmRegistered = true;

	direction = dir;
	moveSpeed = 4.0f;
	collisionDamage = d;

	//this->SubmitEntry(); //make sure to do this if using alarms
}

void EnemyBullet::Initialize(Vect pos, Vect dir, int d)
{
	vPos = pos;
	direction = dir;
	collisionDamage = d;

	mWorld = mScale * mRot * Matrix(TRANS, vPos);
	pGObj_EBullet->SetWorld(mWorld);
	UpdateCollisionData(mWorld);

	alarmRegistered = true;
	AlarmObject::SubmitAlarmRegistration(2.0f, AlarmObjectManager::ALARM_0);
}

void EnemyBullet::SceneEntry()
{
	UpdateObject::SubmitUpdateRegistration();
	DrawObject::SubmitDrawRegistration();
	CollisionObject::SubmitCollisionRegistration<EnemyBullet>(this);
}

void EnemyBullet::SceneExit()
{
	if (alarmRegistered)
	{
		AlarmObject::SubmitAlarmDeregistration(AlarmObjectManager::ALARM_0);
	}
	SubmitDrawDeregistration();
	SubmitUpdateDeregistration();
	CollisionObject::SubmitCollisionDeregistration<EnemyBullet>(this);
	EnemyBulletFactory::RecycleEnemyBullet(this);
}

void EnemyBullet::Update()
{
	vPos += direction * moveSpeed;
	mWorld = mScale * mRot * Matrix(TRANS, vPos);

	pGObj_EBullet->SetWorld(mWorld);
	UpdateCollisionData(mWorld);
}

void EnemyBullet::Collision(JumpTank* jt)
{
	jt->SendPlayerDamage(collisionDamage);
	SubmitExit();
}

void EnemyBullet::Alarm0()
{
	alarmRegistered = false;
	SubmitExit();
}



void EnemyBullet::Draw()
{
	pGObj_EBullet->Render(SceneManager::getCurScene()->GetCurCam());
}

EnemyBullet::~EnemyBullet()
{
	delete pGObj_EBullet;
}