#include "L2Trigger_02.h"
#include "GameManager.h"

L2Trigger_02::L2Trigger_02(float posx, float posy, float posz, float scaleNum)
{
	pTrigSprite = nullptr;
	//CreateTrigger(posx, posy, posz, scaleNum); //base class function to create object

	pGObj_Trigger = new GraphicsObject_WireframeConstantColor(ModelManager::getModel("UnitBox"), ShaderManager::getShader("ShaderObject_constantColor"), DEFAULT_COLOR);

	world = Matrix(IDENTITY);
	Vect s;
	s.set(scaleNum, scaleNum, scaleNum);
	scale = Matrix(SCALE, s);

	//pos.set(2.57f, 0, 2.57f);
	pos.set(posx, posy, posz);
	world = scale * Matrix(TRANS, pos);

	pGObj_Trigger->SetWorld(world);


	DrawObject::SubmitDrawRegistration();
	SubmitUpdateRegistration();

	CollisionObject::SubmitCollisionRegistration<L2Trigger_02>(this);
	SetColliderModel(pGObj_Trigger->getModel(), COLLISION_VOLUME_TYPE::AABB);
	UpdateCollisionData(world);

	spriteTriggered = true;
}

void L2Trigger_02::Collision(Bullet* b)
{
	b;
	//destroy this thing
	if (alive)
	{
		GameManager::RegisterGeneratorDeath();
		SubmitDrawDeregistration();
		alive = false;
	}
	
}

void L2Trigger_02::Collision(JumpTank* jt)
{
	jt;
}

void L2Trigger_02::CollisionEvent()
{

}

L2Trigger_02::~L2Trigger_02()
{

}