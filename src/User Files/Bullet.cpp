#include "Bullet.h"
#include "BulletFactory.h"
#include "Enemy.h"

Bullet::Bullet()
{
	Vect LightColor(1.50f, 1.50f, 1.50f, 1.0f);
	Vect LightPos(1.0f, 1.0f, 1.0f, 1.0f);
	pGObj_BulletLight = new GraphicsObject_TextureFlat(ModelManager::getModel("Bullet"), ShaderManager::getShader("ShaderObject_texture"), TextureManager::getTexture("JTBulletTex"));

	BulletScale.set(SCALE, 1.5f, 1.5f, 1.5f);

	//UpdateObject::SubmitUpdateRegistration();
	//DrawObject::SubmitDrawRegistration();

	SetColliderModel(pGObj_BulletLight->getModel(), COLLISION_VOLUME_TYPE::BSPHERE);


}

void Bullet::Initialize(const Matrix& rot, const Vect& pos)
{
	BulletRot = rot;
	BulletPos = pos;
	worldPos = BulletScale * BulletRot * Matrix(TRANS, BulletPos);
	vBulletForward = Vect(0, 0, 1, 0);



	pGObj_BulletLight->SetWorld(worldPos);
	UpdateCollisionData(worldPos);

	alarmRegistered = true;
	AlarmObject::SubmitAlarmRegistration(2.0f, AlarmObjectManager::ALARM_0);
}

void Bullet::SceneEntry()
{
	UpdateObject::SubmitUpdateRegistration();
	DrawObject::SubmitDrawRegistration();
	CollisionObject::SubmitCollisionRegistration<Bullet>(this);
}

void Bullet::SceneExit()
{
	if (alarmRegistered)
	{
		AlarmObject::SubmitAlarmDeregistration(AlarmObjectManager::ALARM_0);
	}
	UpdateObject::SubmitUpdateDeregistration();
	DrawObject::SubmitDrawDeregistration();
	CollisionObject::SubmitCollisionDeregistration<Bullet>(this);
	BulletFactory::RecycleBullet(this);
}

void Bullet::Alarm0()
{	
	alarmRegistered = false;
	SubmitExit();
}

void Bullet::Update()
{
	BulletPos += vBulletForward * BulletRot * BulletSpeed;
	worldPos = BulletScale * BulletRot * Matrix(TRANS, BulletPos);

	pGObj_BulletLight->SetWorld(worldPos);
	this->UpdateCollisionData(worldPos);

}

void Bullet::Draw()
{
	pGObj_BulletLight->Render(SceneManager::getCurScene()->GetCurCam());
}

void Bullet::Collision(EnemyTank* et)
{
	et;
	SubmitExit();
}

void Bullet::Collision(JetFighter* jf)
{
	jf;
	SubmitExit();
}

void Bullet::Collision(DestroyerDroid* dd)
{
	dd;
	SubmitExit();
}

void Bullet::Collision(L2Trigger_02* t)
{
	t;
	SubmitExit();
}

//void Bullet::Collision(Enemy* e)
//{
//	e;
//	DebugMsg::out("Bullet hit enemy");
//}


Bullet::~Bullet()
{
	delete pGObj_BulletLight;
}