#include "EnemyTank.h"
#include "DebugOut.h"
#include "EnemySpawner.h"
#include "EnemyTank_FSM.h"
#include "EnemyTankState.h"
#include "../Lediri Engine/TimeManager.h"
#include "EnemyBullet.h"
#include "EnemyBulletFactory.h"
#include "JumpTank.h"

EnemyTank::EnemyTank()
{
	pGObj_EnemyTank = new GraphicsObject_TextureLight(ModelManager::getModel("TankBody"), ShaderManager::getShader("ShaderObject_textureLight"), TextureManager::getTexture("SpaceFrigateTex"), TextureManager::getTexture("SpaceFrigateTex"), TextureManager::getTexture("SpaceFrigateTex"), LightColor, LightPos);
	pGObj_EnemyTankTurret = new GraphicsObject_TextureLight(ModelManager::getModel("TankTurret"), ShaderManager::getShader("ShaderObject_textureLight"), TextureManager::getTexture("SpaceFrigateTex"), LightColor, LightPos);

	mScale.set(SCALE, .5f, .5f, .5f);
	mRot.set(IDENTITY);
	vPos.set(150, 0, 0);
	mWorld = mScale * mRot * Matrix(TRANS, vPos);
	mWorldTurret = mWorld;
	vPosTurret = mWorld.get(ROW_3);
	vPosTurret.set(vPosTurret.X(), vPosTurret.Y() + 6.0f, vPosTurret.Z());
	mWorldTurret.set(ROW_3, vPosTurret);
	pGObj_EnemyTank->SetWorld(mWorld);
	pGObj_EnemyTankTurret->SetWorld(mWorldTurret);

	
	SubmitDrawRegistration();
	SubmitUpdateRegistration();
	CollisionObject::SubmitCollisionRegistration<EnemyTank>(this);

	SetColliderModel(pGObj_EnemyTank->getModel(), COLLISION_VOLUME_TYPE::AABB);

	curState = &EnemyTank_FSM::PatrolState;

	health = 3;
	collisionDamage = 2;
}

EnemyTank::EnemyTank(Vect pos)
{
	pGObj_EnemyTank = new GraphicsObject_TextureLight(ModelManager::getModel("TankBody"), ShaderManager::getShader("ShaderObject_textureLight"), TextureManager::getTexture("SpaceFrigateTex"), TextureManager::getTexture("SpaceFrigateTex"), TextureManager::getTexture("SpaceFrigateTex"), LightColor, LightPos);
	pGObj_EnemyTankTurret = new GraphicsObject_TextureLight(ModelManager::getModel("TankTurret"), ShaderManager::getShader("ShaderObject_textureLight"), TextureManager::getTexture("SpaceFrigateTex"), LightColor, LightPos);

	//pos.set(0, 0, 0);
	mScale.set(SCALE, .5f, .5f, .5f);
	mRot.set(IDENTITY);
	vPos.set(pos.X(), pos.Y(), pos.Z());
	mWorld = mScale * mRot * Matrix(TRANS, vPos);
	mWorldTurret = mWorld;
	vPosTurret = mWorld.get(ROW_3);
	vPosTurret.set(vPosTurret.X(), vPosTurret.Y() + 6.0f, vPosTurret.Z());
	mWorldTurret.set(ROW_3, vPosTurret);
	pGObj_EnemyTank->SetWorld(mWorld);
	pGObj_EnemyTankTurret->SetWorld(mWorldTurret);


	SubmitDrawRegistration();
	SubmitUpdateRegistration();
	CollisionObject::SubmitCollisionRegistration<EnemyTank>(this);

	SetColliderModel(pGObj_EnemyTank->getModel(), COLLISION_VOLUME_TYPE::AABB);

	this->UpdateCollisionData(mWorld);

	curState = &EnemyTank_FSM::PatrolState;

	health = 3;
	collisionDamage = 2;
}

//EnemyTank::EnemyTank(Vect ranPos)
//{
//	pGObj_EnemyTank = new GraphicsObject_TextureLight(ModelManager::getModel("TankBody"), ShaderManager::getShader("ShaderObject_textureLight"), TextureManager::getTexture("SpaceFrigateTex"), TextureManager::getTexture("SpaceFrigateTex"), TextureManager::getTexture("SpaceFrigateTex"), LightColor, LightPos);
//	pGObj_EnemyTankTurret = new GraphicsObject_TextureLight(ModelManager::getModel("TankTurret"), ShaderManager::getShader("ShaderObject_textureLight"), TextureManager::getTexture("SpaceFrigateTex"), LightColor, LightPos);
//
//	mScale.set(SCALE, .5f, .5f, .5f);
//	mRot.set(IDENTITY);
//	vPos = ranPos;
//	mWorld = mScale * mRot * Matrix(TRANS, vPos);
//	mWorldTurret = mWorld;
//	vPosTurret = mWorld.get(ROW_3);
//	vPosTurret.set(vPosTurret.X(), vPosTurret.Y() + 6.0f, vPosTurret.Z());
//	mWorldTurret.set(ROW_3, vPosTurret);
//	pGObj_EnemyTank->SetWorld(mWorld);
//	pGObj_EnemyTankTurret->SetWorld(mWorldTurret);
//
//	SubmitDrawRegistration();
//	SubmitUpdateRegistration();
//	CollisionObject::SubmitCollisionRegistration<EnemyTank>(this);
//
//	SetColliderModel(pGObj_EnemyTank->getModel(), COLLISION_VOLUME_TYPE::OBB);
//
//	moveSpeed = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 4));
//	TankRotAng = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (0.4 - 0.2)));
//
//
//	//enemySpawner = ES;
//	this->UpdateCollisionData(mWorld);
//
//
//	curState = &EnemyTank_FSM::IdleState;
//}

void EnemyTank::Update()
{
	curState->Execute(this);
	//DebugMsg::out("%x, %x, %x", vPos.X(), vPos.Y(), vPos.Z());
	//vTankPos += Vect(0, 0, 1) * mTankRot * TankTransSpeed;
	//mTankRot *= Matrix(ROT_Y, -TankRotAng);

	//mWorld = mTankScale * mTankRot * Matrix(TRANS, vTankPos);
	mWorldTurret = mWorld;
	mWorldTurret = mScale * mRot * Matrix(TRANS, vPos + Vect(0, 6.0f, 0));

	pGObj_EnemyTankTurret->SetWorld(mWorldTurret);
	//pGObj_EnemyTank->SetWorld(mWorld);

	this->UpdateCollisionData(mWorld);
	//SceneManager::getCurScene()->GetCurCam()->updateCamera();


}

void EnemyTank::Patrol()
{
	moveSpeed = .20f;
	vPos += Vect(0, 0, 1) * mRot * moveSpeed;
	mRot *= Matrix(ROT_Y, -TankRotAng);

	mWorld = mScale * mRot * Matrix(TRANS, vPos);
	mWorldTurret = mWorld;
	mWorldTurret = mScale * mRot * Matrix(TRANS, vPos + Vect(0, 6.0f, 0));

	pGObj_EnemyTankTurret->SetWorld(mWorldTurret);
	pGObj_EnemyTank->SetWorld(mWorld);

	this->UpdateCollisionData(mWorld);
	SceneManager::getCurScene()->GetCurCam()->updateCamera();
}

void EnemyTank::Fire()
{
	//DebugMsg::out("Fire!");
	Vect p = vPos;
	p.Y() = p.Y() + 2.0f;
	Vect d = mWorld.get(ROW_2).norm();
	d.Y() = 0;
	//new EnemyBullet(p, d, bulletSize, bulletDamage);
	EnemyBulletFactory::CreateEnemyBullet(p, d, bulletDamage);
}

void EnemyTank::FollowPlayer()
{
	if (PlayerInRange(120.0f))
	{
		Vect dir = vPos - GameManager::GetPlayerPos();
		dir.Y() = 0;
		dir = dir.norm();
		vPos += dir * moveSpeed;
	}
	else if (!PlayerInRange(120.1f))
	{
		Vect dir = GameManager::GetPlayerPos() - vPos;
		dir.Y() = 0;
		dir = dir.norm();
		vPos += dir * moveSpeed;
	}
	if (fireTimer >= fireTime)
	{
		Fire();
		fireTimer = 0;
	}
	
	fireTimer += TimeManager::GetLastFrameTime();

	this->LookAtHorizontal(GameManager::GetPlayerPos());
	pGObj_EnemyTank->SetWorld(mWorld);
	this->UpdateCollisionData(mWorld);
}

void EnemyTank::ChangeState(const EnemyTankState* ptrState)
{
	curState = ptrState;
}

void EnemyTank::Draw()
{
	pGObj_EnemyTank->Render(SceneManager::getCurScene()->GetCurCam());
	pGObj_EnemyTankTurret->Render(SceneManager::getCurScene()->GetCurCam());
}

void EnemyTank::Collision(JumpTank* t)
{
	t;
	if (!dead)
	{
		dead = true;
		SubmitExit();
		t->SendPlayerDamage(collisionDamage);
	}

	//enemySpawner->killEnemy();
}

void EnemyTank::SubmitExit()
{
	GameManager::RegisterDeath();
	SubmitDrawDeregistration();
	SubmitUpdateDeregistration();
	CollisionObject::SubmitCollisionDeregistration<EnemyTank>(this);
}

void EnemyTank::Collision(Bullet* b)
{
	b;
	this->SendDamage(1);
	if (health < 1)
	{
		if (!dead)
		{
			dead = true;
			SubmitExit(); //set up what happens in SubmitExit()
		}
	}
	//SubmitExit();
	//enemySpawner->killEnemy();

}

EnemyTank::~EnemyTank()
{
	delete pGObj_EnemyTank;
	delete pGObj_EnemyTankTurret;
}