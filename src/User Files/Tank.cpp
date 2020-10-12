#include "Tank.h"
#include "DebugOut.h"
#include "BulletFactory.h"
#include "TestScene.h"
#include "DemoScene.h"
#include "../Lediri Engine/Sprite.h"

Tank::Tank()
{
	pGObj_Tank = new GraphicsObject_TextureLight(ModelManager::getModel("TankBody"), ShaderManager::getShader("ShaderObject_textureLight"), TextureManager::getTexture("TankBodyTex"), TextureManager::getTexture("TankBodyTex"), TextureManager::getTexture("TankBodyTex"), LightColor, LightPos);
	pGObj_TankTurret = new GraphicsObject_TextureLight(ModelManager::getModel("TankTurret"), ShaderManager::getShader("ShaderObject_textureLight"), TextureManager::getTexture("SpaceFrigateTex"), LightColor, LightPos);

	//Create sprite
	//Matrix spriteScale = Matrix(SCALE, 1.0f, 1.0f, 1.0f);
	//Matrix spriteRotZ = Matrix(ROT_Z, 0.0f);
	//float transX = (float)Lediri::pubGetWidth() / 2.0f;
	//float transY = ((float)Lediri::pubGetHeight() / 2.0f) + 60.0f;
	//targetSprite = new Sprite(ImageManager::getImage("StitchImage"), spriteScale, spriteRotZ, transX, transY);

	targetSprite = new Sprite(ImageManager::getImage("StitchImage"));
	float transX = (float)Lediri::pubGetWidth() / 2.0f;
	float transY = ((float)Lediri::pubGetHeight() / 2.0f) + 60.0f;
	targetSprite->SetTrans(transX, transY);
	targetSprite->SetRotZ(0.0f);
	targetSprite->SetScale(1.0f, 1.0f, 1.0f);




	mTankScale.set(SCALE, .5f, .5f, .5f);
	mTankRot.set(IDENTITY);
	vTankPos.set(0, 15, 0);
	mWorld = mTankScale * mTankRot * Matrix(TRANS, vTankPos);
	mWorldTurret = mWorld;
	vPosTurret = mWorld.get(ROW_3);
	vPosTurret.set(vPosTurret.X(), vPosTurret.Y() + 6.0f, vPosTurret.Z());
	mWorldTurret.set(ROW_3, vPosTurret);
	pGObj_Tank->SetWorld(mWorld);
	pGObj_TankTurret->SetWorld(mWorldTurret);
	
	SubmitDrawRegistration();
	SubmitUpdateRegistration();
	CollisionObject::SubmitCollisionRegistration<Tank>(this);

	SetColliderModel(pGObj_Tank->getModel(), COLLISION_VOLUME_TYPE::AABB);

	

	InputObject::SubmitInputRegistration(AZUL_KEY::KEY_SPACE, INPUT_EVENT_TYPE::KEY_PRESS);
	InputObject::SubmitInputRegistration(AZUL_KEY::KEY_F1, INPUT_EVENT_TYPE::KEY_PRESS);
	InputObject::SubmitInputRegistration(AZUL_KEY::KEY_F2, INPUT_EVENT_TYPE::KEY_PRESS);
	InputObject::SubmitInputRegistration(AZUL_KEY::KEY_T, INPUT_EVENT_TYPE::KEY_RELEASE);
	InputObject::SubmitInputRegistration(AZUL_KEY::KEY_Y, INPUT_EVENT_TYPE::KEY_RELEASE);

	InputObject::SubmitInputRegistration(AZUL_KEY::KEY_W, INPUT_EVENT_TYPE::KEY_PRESS);
	InputObject::SubmitInputRegistration(AZUL_KEY::KEY_W, INPUT_EVENT_TYPE::KEY_RELEASE);

}

Tank::Tank(Vect pos, bool b)
{
	pGObj_Tank = new GraphicsObject_TextureLight(ModelManager::getModel("TankBody"), ShaderManager::getShader("ShaderObject_textureLight"), TextureManager::getTexture("TankBodyTex"), TextureManager::getTexture("TankBodyTex"), TextureManager::getTexture("TankBodyTex"), LightColor, LightPos);
	pGObj_TankTurret = new GraphicsObject_TextureLight(ModelManager::getModel("TankTurret"), ShaderManager::getShader("ShaderObject_textureLight"), TextureManager::getTexture("SpaceFrigateTex"), LightColor, LightPos);

	targetSprite = new Sprite(ImageManager::getImage("StitchImage"));
	float transX = (float)Lediri::pubGetWidth() / 2.0f;
	float transY = ((float)Lediri::pubGetHeight() / 2.0f) + 60.0f;
	targetSprite->SetTrans(transX, transY);
	targetSprite->SetRotZ(0.0f);
	targetSprite->SetScale(1.0f, 1.0f, 1.0f);

	mTankScale.set(SCALE, .5f, .5f, .5f);
	mTankRot.set(IDENTITY);
	vTankPos.set(pos);
	mWorld = mTankScale * mTankRot * Matrix(TRANS, pos);
	mWorldTurret = mWorld;
	vPosTurret = mWorld.get(ROW_3);
	vPosTurret.set(vPosTurret.X(), vPosTurret.Y() + 6.0f, vPosTurret.Z());
	mWorldTurret.set(ROW_3, vPosTurret);
	pGObj_Tank->SetWorld(mWorld);
	pGObj_TankTurret->SetWorld(mWorldTurret);

	SubmitDrawRegistration();
	SubmitUpdateRegistration();
	CollisionObject::SubmitCollisionRegistration<Tank>(this);

	SetColliderModel(pGObj_Tank->getModel(), COLLISION_VOLUME_TYPE::BSPHERE);



	InputObject::SubmitInputRegistration(AZUL_KEY::KEY_SPACE, INPUT_EVENT_TYPE::KEY_PRESS);
	InputObject::SubmitInputRegistration(AZUL_KEY::KEY_F1, INPUT_EVENT_TYPE::KEY_PRESS);
	InputObject::SubmitInputRegistration(AZUL_KEY::KEY_F2, INPUT_EVENT_TYPE::KEY_PRESS);
	InputObject::SubmitInputRegistration(AZUL_KEY::KEY_T, INPUT_EVENT_TYPE::KEY_RELEASE);
	InputObject::SubmitInputRegistration(AZUL_KEY::KEY_Y, INPUT_EVENT_TYPE::KEY_RELEASE);

	InputObject::SubmitInputRegistration(AZUL_KEY::KEY_W, INPUT_EVENT_TYPE::KEY_PRESS);
	InputObject::SubmitInputRegistration(AZUL_KEY::KEY_W, INPUT_EVENT_TYPE::KEY_RELEASE);

	canMove = b;

}

void Tank::Update()
{
	if (canMove)
	{
		if (Keyboard::GetKeyState(AZUL_KEY::KEY_W))
		{
			//InputObject::SubmitInputDeregistration(AZUL_KEY::KEY_Y, INPUT_EVENT_TYPE::KEY_RELEASE);

			vTankPos += Vect(0, 0, 1) * mTankRot * TankTransSpeed;
			vPosTurret += Vect(0, 0, 1) * mTankRot * TankTransSpeed;
			targetSprite->SetScale(2.0f, 2.0f, 1.0f);


			//acceleration test
			//time += timeStep;
			//zPos = timeStep * (velocity + timeStep * acceleration / 2.0f);
			//velocity += timeStep * acceleration;
			//vTankPos += Vect(0, 0, zPos) * mTankRot;// *TankTransSpeed;

			DebugMsg::out("Position: %d\n", zPos);
		}
		//else
		//{
		//	if (zPos > 0)
		//	{
		//		time += timeStep;
		//		zPos = timeStep * (velocity + timeStep * acceleration / 2.0f);
		//		velocity -= timeStep * acceleration;
		//		vTankPos += Vect(0, 0, zPos) * mTankRot;// *TankTransSpeed;
		//	}

		//}
		else if (Keyboard::GetKeyState(AZUL_KEY::KEY_S))
		{
			vTankPos += Vect(0, 0, 1) * mTankRot * -TankTransSpeed;
			//vPosTurret += Vect(0, 0, 1) 
			//targetSprite->SetTrans(50, 50);
		}

		// Ship Rotation movement (not using time-based values for simplicity)
		if (Keyboard::GetKeyState(AZUL_KEY::KEY_A))
		{
			mTankRot *= Matrix(ROT_Y, TankRotAng);
		}
		else if (Keyboard::GetKeyState(AZUL_KEY::KEY_D))
		{
			mTankRot *= Matrix(ROT_Y, -TankRotAng);
		}
	}


	mWorld = mTankScale * mTankRot * Matrix(TRANS, vTankPos);
	mWorldTurret = mWorld;
	//vPosTurret.set(vPosTurret.X(), vPosTurret.Y(), vPosTurret.Z());
	//mWorldTurret.set(ROW_3, vPosTurret);
	mWorldTurret = mTankScale * mTankRot * Matrix(TRANS, vTankPos + Vect(0, 6.0f, 0));
	pGObj_TankTurret->SetWorld(mWorldTurret);
	pGObj_Tank->SetWorld(mWorld);
	this->UpdateCollisionData(mWorld);

	mTankRotPos = mTankRot * Matrix(TRANS, vTankPos);  // This is the worldmat without scaling
	vNewCamPos = vCamLookAt * mTankRotPos;		// This moves the cam position relative to ship's position and rotation
	vNewLookAt = vCamTankOffset * mTankRotPos;   // This moves the look-at point relative to ship's position and rotation
	SceneManager::getCurScene()->GetCurCam()->setOrientAndPosition(Vect(0, 1, 0), vNewCamPos, vNewLookAt);
	SceneManager::getCurScene()->GetCurCam()->updateCamera();


	//sprite update
	targetAngle += 0.05f;
	//targetSprite->SetRotZ(targetAngle);
}

void Tank::Draw()
{
	pGObj_Tank->Render(SceneManager::getCurScene()->GetCurCam());
	pGObj_TankTurret->Render(SceneManager::getCurScene()->GetCurCam());
	targetSprite->Render(SceneManager::getCurScene()->GetSpriteCam());
	//targetSprite->Render(SceneManager::getCurScene()->GetCurCam());
}

void Tank::Collision(EnemyTank* et)
{
	et;
}

void Tank::Collision(Tank* t)
{
	t;
}

void Tank::Collision(Frigate* f)
{
	f;
	DebugMsg::out("Tank colliding with frigate\n");
}

void Tank::Alarm0()
{
}

void Tank::Alarm1()
{
}

void Tank::KeyPressed(AZUL_KEY k)
{
	switch (k)
	{
	case AZUL_KEY::KEY_W:
		break;
	case AZUL_KEY::KEY_SPACE:
		BulletFactory::CreateBullet(this->mTankRot, this->vTankPos + Vect(0.0f, 8.0f, 0.0f));
		break;
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

void Tank::KeyReleased(AZUL_KEY k)
{
	switch (k)
	{
	case AZUL_KEY::KEY_W:
		time = 0;
		break;
	case AZUL_KEY::KEY_T:
		SceneManager::SetNextScene(new TestScene());
		break;
	case AZUL_KEY::KEY_Y:
		SceneManager::SetNextScene(new DemoScene());
	default:
		break;
	}
}

Tank::~Tank()
{
	delete targetSprite;
	delete pGObj_Tank;
	delete pGObj_TankTurret;
}