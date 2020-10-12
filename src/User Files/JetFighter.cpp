#include "JetFighter.h"
#include "JetFighter_FSM.h"
#include "EnemyBullet.h"
#include "JumpTank.h"
#include "EnemyBulletFactory.h"
#include "../Lediri Engine/TimeManager.h"

JetFighter::JetFighter(Vect pos)
{
	pGObj_EnemyJet = new GraphicsObject_TextureFlat(ModelManager::getModel("Spaceship"), ShaderManager::getShader("ShaderObject_texture"), TextureManager::getTexture("JetTexture"));

	mScale.set(SCALE, 10.0f, 10.0f, 10.0f);
	mRot.set(IDENTITY);
	originalHeight = pos.Y();
	vPos.set(pos.X(), originalHeight, pos.Z());
	mWorld = mScale * mRot * Matrix(TRANS, vPos);
	pGObj_EnemyJet->SetWorld(mWorld);

	SubmitDrawRegistration();
	SubmitUpdateRegistration();
	CollisionObject::SubmitCollisionRegistration<JetFighter>(this);

	SetColliderModel(pGObj_EnemyJet->getModel(), COLLISION_VOLUME_TYPE::AABB);

	curState = &JetFighter_FSM::PatrolState;

	collisionDamage = 3;
	moveSpeed = .5f;
	health = 2;

}

void JetFighter::Update()
{
	curState->Execute(this);

	Matrix mOffset = Matrix(ROT_X, -1.57f);// *Matrix(ROT_Z, -0.79f)* Matrix(ROT_Y, -1.57f);

	mWorld = mOffset * mScale * mRot * Matrix(TRANS, vPos);

	pGObj_EnemyJet->SetWorld(mWorld);

	this->UpdateCollisionData(mWorld);
	SceneManager::getCurScene()->GetCurCam()->updateCamera();
}

void JetFighter::Draw()
{
	pGObj_EnemyJet->Render(SceneManager::getCurScene()->GetCurCam());
}

void JetFighter::Patrol()
{

	vPos += Vect(0, 0, 1) * mRot * JetTransSpeed;
	mRot *= Matrix(ROT_Y, -JetRotAng);


}

bool JetFighter::CanFire()
{
	if (FireTimer > FireTime)
	{
		return true;
	}
	else
	{
		FireTimer += TimeManager::GetLastFrameTime();
		return false;
	}

}

void JetFighter::CalculateReturnPosition()
{
	returnPoint = mWorld.get(ROW_3).norm();
	returnPoint.X() *= returnOffset;
	returnPoint.Z() *= returnOffset;
	returnPoint.Y() = originalHeight;

	returnDirection = (returnPoint + vPos).norm();
	returnDirection.Y() += 1.0f;
}

void JetFighter::Return()
{
	vPos += returnDirection * moveSpeed;

	mRot.set(ROT_ORIENT, returnDirection, mWorld.get(ROW_2).cross(mWorld.get(ROW_0)));
	mWorld = mScale * mRot * Matrix(TRANS, vPos);
	pGObj_EnemyJet->SetWorld(mWorld);

	this->UpdateCollisionData(mWorld);
}

bool JetFighter::atOriginalAltitude()
{
	if (vPos.Y() >= originalHeight)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void JetFighter::Fire()
{
	DebugMsg::out("Fire");
	FireTimer = 0;
	//new EnemyBullet(vPos, mWorld.get(ROW_2).norm(), bulletSize, bulletDamage);
	EnemyBulletFactory::CreateEnemyBullet(vPos, mWorld.get(ROW_2).norm(), bulletDamage);
}

void JetFighter::ChasePlayer()
{

	//DebugMsg::out("\nPos = %f, %f, %f", pos.X(), pos.Y(), pos.Z());
	//Vect dist = GameManager::GetPlayerPos() - vPos;
	//float mag = dist.mag();
	//rot = Matrix(ROT_XYZ)
	Vect dir = this->DirectionToPlayer();
	vPos += dir * moveSpeed;
	mRot.set(ROT_ORIENT, dir, mWorld.get(ROW_2).cross(mWorld.get(ROW_0)));
	mWorld = mScale * mRot * Matrix(TRANS, vPos);
	pGObj_EnemyJet->SetWorld(mWorld);

	this->UpdateCollisionData(mWorld);

}

void JetFighter::Collision(Bullet* b)
{
	b;
	this->SendDamage(1);
	if (health < 1)
	{
		if (!dead)
		{
			dead = true;
			GameManager::RegisterJetFighterDeath();
			GameManager::RegisterDeath();
			SubmitExit();
		}

	}
}

void JetFighter::Collision(JumpTank* jt)
{
	jt;
	if (!dead)
	{
		dead = true;
		GameManager::RegisterJetFighterDeath();
		GameManager::RegisterDeath();
		SubmitExit();
		jt->SendPlayerDamage(collisionDamage);
	}

}

void JetFighter::SubmitExit()
{

	GameManager::RegisterDeath();
	SubmitDrawDeregistration();
	SubmitUpdateDeregistration();
	CollisionObject::SubmitCollisionDeregistration<JetFighter>(this);
}

void JetFighter::ChangeState(const JetFighterState* ptrState)
{
	curState = ptrState;
}

bool JetFighter::PlayerInSight()
{
	Vect dist = GameManager::GetPlayerPos() - vPos;
	float mag = dist.mag();

	//DebugMsg::out("mag = %f\n", mag);

	if (mag < 100.0f)
	{
		return true;
	}
	return false;
}

JetFighter::~JetFighter()
{
	delete pGObj_EnemyJet;
}