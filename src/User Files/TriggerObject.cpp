#include "TriggerObject.h"
#include "JumpTank.h"
#include "../Lediri Engine/TimeManager.h"

Vect TriggerObject::DEFAULT_COLOR = Color::Red;

TriggerObject::TriggerObject(float posx, float posy, float posz, float scaleNum)
{
	posx;
	posy;
	posz;
	scaleNum;

}

void TriggerObject::CreateTrigger(float posx, float posy, float posz, float scaleNum)
{
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

	CollisionObject::SubmitCollisionRegistration<TriggerObject>(this);
	SetColliderModel(pGObj_Trigger->getModel(), COLLISION_VOLUME_TYPE::AABB);
	UpdateCollisionData(world);

	spriteTriggered = true;
}

void TriggerObject::Update()
{
	UpdateCollisionData(world);
	pGObj_Trigger->SetWorld(world);

	if (pTrigSprite != nullptr)
	{
		pTrigSprite->SetTrans(spriteX, spriteY);

		if (spriteTriggered)
		{
			if (spriteTimer > spriteTime)
			{
				spriteTriggered = false;
				SubmitDrawDeregistration();
				//CollisionObject::SubmitCollisionDeregistration<TriggerObject>(this);
			}
			spriteTimer += TimeManager::GetLastFrameTime();
		}
	}

}

void TriggerObject::Draw()
{
	pGObj_Trigger->Render(SceneManager::getCurScene()->GetCurCam());

	if (pTrigSprite != nullptr)
	{
		if (spriteTriggered)
		{
			pTrigSprite->Render(SceneManager::getCurScene()->GetSpriteCam());
		}
	}

}

void TriggerObject::Collision(JumpTank* jt)
{
	jt;
	//show sprite
	//spriteTriggered = true;
	CollisionEvent();
}

TriggerObject::~TriggerObject()
{
	delete pGObj_Trigger;
	//delete sprite;
}