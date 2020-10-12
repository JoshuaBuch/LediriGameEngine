#include "L1Trigger_01.h"


L1Trigger_01::L1Trigger_01(float posx, float posy, float posz, float scaleNum)
{
	pTrigSprite = new Sprite(ImageManager::getImage("L1ObjectiveImage"));
	
	spriteX = ((float)Lediri::pubGetWidth() / 2);
	spriteY = ((float)Lediri::pubGetHeight() / 2);
	pTrigSprite->SetTrans(spriteX, spriteY);
	pTrigSprite->SetRotZ(0.0f);
	pTrigSprite->SetScale(5.0f, 5.0f, 5.0f);


	CreateTrigger(posx, posy, posz, scaleNum); //base class function to create object
}

void L1Trigger_01::Collision(JumpTank* jt)
{	
	jt;
}

void L1Trigger_01::CollisionEvent()
{
	DebugMsg::out("Colliding with tank\n");

	
}

L1Trigger_01::~L1Trigger_01()
{
	//base class should be deleting the graphics object
	delete pTrigSprite;
}