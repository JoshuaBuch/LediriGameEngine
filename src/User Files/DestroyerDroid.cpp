#include "DestroyerDroid.h"
#include "DestroyerDroid_FSM.h"
#include "JumpTank.h"

//#include "DestroyerDroidState.h"

DestroyerDroid::DestroyerDroid(float x = 0, float y = 0, float z = 0, Speed sp = Speed::Slow)
{
	pGObj_Temp = new GraphicsObject_TextureLight(ModelManager::getModel("UnitSphere"), ShaderManager::getShader("ShaderObject_textureLight"), TextureManager::getTexture("TankBodyTex"), TextureManager::getTexture("TankBodyTex"), TextureManager::getTexture("TankBodyTex"), LightColor, LightPos);

	mScale.set(SCALE, 10.0f, 10.0f, 10.0f);
	mRot.set(IDENTITY);
	vPos.set(x, y, z);
	mWorld = mScale * mRot * Matrix(TRANS, vPos);

	pGObj_Temp->SetWorld(mWorld);

	SubmitDrawRegistration();
	SubmitUpdateRegistration();
	CollisionObject::SubmitCollisionRegistration<DestroyerDroid>(this);

	SetColliderModel(pGObj_Temp->getModel(), COLLISION_VOLUME_TYPE::BSPHERE);
	UpdateCollisionData(mWorld);

	health = 1;
	moveSpeed = .3f;
	collisionDamage = 3;

	curState = &DestroyerDroid_FSM::IdleState;

	switch (sp)
	{
	case Speed::Slow:
		//set it to neutral state
		moveSpeed = .3f;
		break;
	case Speed::Fast:
		moveSpeed = 1.0f;
		break;
	default:
		moveSpeed = .3f;
		break;
	}
}

void DestroyerDroid::Update()
{

	//this->MoveTowardsPlayer();
	curState->Execute(this);
	pGObj_Temp->SetWorld(mWorld);
	UpdateCollisionData(mWorld);
}

void DestroyerDroid::Draw()
{
	pGObj_Temp->Render(SceneManager::getCurScene()->GetCurCam());
}

bool DestroyerDroid::isPlayerInRange()
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

void DestroyerDroid::MoveTowardsPlayer()
{
	Vect dist = GameManager::GetPlayerPos() - vPos;
	//float mag = dist.mag();

	vPos += dist.norm() * moveSpeed;
	mWorld = mScale * mRot * Matrix(TRANS, vPos);



}

void DestroyerDroid::Collision(JumpTank* jt)
{
	jt;
	//do an explosion and destroy the player.
	jt->SendPlayerDamage(collisionDamage);
	if (!dead)
	{
		dead = true;
		SubmitExit();
	}
	
}

void DestroyerDroid::Collision(Bullet* b)
{
	b;
	this->SendDamage(1);
	if (health < 1)
	{
		if (!dead)
		{
			dead = true;
			SubmitExit();
		}
		
	}
}

void DestroyerDroid::SubmitExit()
{
	GameManager::RegisterDeath();
	SubmitDrawDeregistration();
	SubmitUpdateDeregistration();
	CollisionObject::SubmitCollisionDeregistration<DestroyerDroid>(this);
}

void DestroyerDroid::ChangeState(const DestroyerDroidState* ptrState)
{
	curState = ptrState;
}

DestroyerDroid::~DestroyerDroid()
{
	delete pGObj_Temp;
	DebugMsg::out("DestroyerDroid being deleted");
}