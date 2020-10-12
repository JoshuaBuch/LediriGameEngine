#include "JumpTank.h"
#include "BulletFactory.h"
#include "GameManager.h"
#include "JumpTank_FSM.h"
#include "Ground.h"
#include "Level_1.h"
#include "Level_2.h"
#include "TitleScene.h"

#include "EnemyTank.h"
#include "DestroyerDroid.h"
#include "JetFighter.h"

#include "../Lediri Engine/Sprite.h"
#include "../Lediri Engine/Visualizer.h"


#include "Axis.h"

Vect JumpTank::DEFAULT_COLOR = Color::Blue;

JumpTank::JumpTank(int stateSet = 0)
{

	godMode = false;


	GameManager::RegisterPlayer(this);

	//wireframe graphics
	//pGObj_Tank = new GraphicsObject_WireframeConstantColor(ModelManager::getModel("TankBody"), ShaderManager::getShader("ShaderObject_constantColor"), DEFAULT_COLOR);
	pGObj_Tank = new GraphicsObject_TextureLight(ModelManager::getModel("TankBody"), ShaderManager::getShader("ShaderObject_textureLight"), TextureManager::getTexture("JTBodyTex"), TextureManager::getTexture("JTBodyTex"), TextureManager::getTexture("JTBodyTex"), LightColor, LightPos);
	pGObj_TankTurret = new GraphicsObject_TextureLight(ModelManager::getModel("TankTurret"), ShaderManager::getShader("ShaderObject_textureLight"), TextureManager::getTexture("JTHeadTex"), TextureManager::getTexture("JTHeadTex"), LightColor, LightPos);

	mTankScale.set(SCALE, .5f, .5f, .5f);
	mTankRot.set(IDENTITY);
	vTankPos.set(0, 0, 0);
	mWorld = mTankScale * mTankRot * Matrix(TRANS, vTankPos);
	mWorldTurret = mWorld;
	vPosTurret = mWorld.get(ROW_3);
	vPosTurret.set(vPosTurret.X(), vPosTurret.Y() + 6.0f, vPosTurret.Z());
	mWorldTurret.set(ROW_3, vPosTurret);
	pGObj_Tank->SetWorld(mWorld);
	pGObj_TankTurret->SetWorld(mWorldTurret);

	SubmitDrawRegistration();
	SubmitUpdateRegistration();

	CollisionObject::SubmitCollisionRegistration<JumpTank>(this);

	SetColliderModel(pGObj_Tank->getModel(), COLLISION_VOLUME_TYPE::AABB);
	tankVerticalSize = pGObj_Tank->getModel()->getMaxAABB().Y() - pGObj_Tank->getModel()->getMinAABB().Y();
	tankVerticalSize *= mTankScale.get(ROW_1).mag();

	InputObject::SubmitInputRegistration(AZUL_KEY::KEY_J, INPUT_EVENT_TYPE::KEY_PRESS);
	InputObject::SubmitInputRegistration(AZUL_KEY::KEY_SPACE, INPUT_EVENT_TYPE::KEY_PRESS);
	InputObject::SubmitInputRegistration(AZUL_KEY::KEY_I, INPUT_EVENT_TYPE::KEY_PRESS);
	InputObject::SubmitInputRegistration(AZUL_KEY::KEY_U, INPUT_EVENT_TYPE::KEY_PRESS);
	InputObject::SubmitInputRegistration(AZUL_KEY::KEY_K, INPUT_EVENT_TYPE::KEY_PRESS);
	InputObject::SubmitInputRegistration(AZUL_KEY::KEY_O, INPUT_EVENT_TYPE::KEY_PRESS);
	InputObject::SubmitInputRegistration(AZUL_KEY::KEY_F5, INPUT_EVENT_TYPE::KEY_PRESS);
	InputObject::SubmitInputRegistration(AZUL_KEY::KEY_F6, INPUT_EVENT_TYPE::KEY_PRESS);


	UpdateCollisionData(mWorld);
	//terrain = new TerrainObject("Textures/h4x4.tga", 20.0f, 20.0f, -4, "GrassTex", 1, 1);
	//terrain->SendPosition(vTankPos, this->GetCollisionSphere().GetRadius());

	switch (stateSet)
	{
	case 0:
		//set it to neutral state
		curState = &JumpTank_FSM::NeutralState;
		break;
	case 1:
		//set to test with terrain
		TerrainObjectManager::getTerrainObject("MainTerrain")->SendPosition(vTankPos, this->GetCollisionSphere().GetRadius());
		point = new Axis();
		curState = &JumpTank_FSM::TerrainState;
		break;
	default:
		stateSet = -2;
		assert(stateSet < 0);
	}

	CreateHUD();

	deathHeight = GameManager::GetLevelDeathHeight();
}

void JumpTank::CreateHUD()
{
	for (int i = 0; i < maxHealth; i++)
	{
		hpSprite[i] = new Sprite(ImageManager::getImage("ArmorImage"));
		spriteX;
		spriteY = ((float)Lediri::pubGetHeight() / 2 + 270);
		hpSprite[i]->SetTrans(spriteX, spriteY);
		hpSprite[i]->SetRotZ(0.0f);
		hpSprite[i]->SetScale(.25f, .25f, .25f);
	}

}

void JumpTank::UpdateHUD()
{
	//float transX = (float)Lediri::pubGetWidth();
	for (int i = 0; i < playerHealth; i++)
	{
		//UpdateHUD();
		hpSprite[i]->SetTrans(spriteX + (i * spriteOffset), spriteY);
		//hpSprite->SetRotZ(0);
	}
}

void JumpTank::Update()
{
	curState->Execute(this);
	if (!godMode)
	{
		onGround = false;
	}
	
	UpdateHUD();

}

void JumpTank::MovePlayer()
{

	Vect tempPos = GameManager::GetPlayerPos();

	if (canMove)
	{
		if (Keyboard::GetKeyState(AZUL_KEY::KEY_W))
		{
			//InputObject::SubmitInputDeregistration(AZUL_KEY::KEY_Y, INPUT_EVENT_TYPE::KEY_RELEASE);

			vTankPos += Vect(0, 0, 1) * mTankRot * TankTransSpeed;
			vPosTurret += Vect(0, 0, 1) * mTankRot * TankTransSpeed;
			//targetSprite->SetScale(2.0f, 2.0f, 1.0f);


			//acceleration test
			//time += timeStep;
			//zPos = timeStep * (velocity + timeStep * acceleration / 2.0f);
			//velocity += timeStep * acceleration;
			//vTankPos += Vect(0, 0, zPos) * mTankRot;// *TankTransSpeed;

			//DebugMsg::out("Position: %d\n", zPos);
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

		//if (Keyboard::GetKeyState(AZUL_KEY::KEY_R))
		//{
		//	vTankPos += Vect(0, 1, 0) * mTankRot * TankTransSpeed;
		//}
		//else if (Keyboard::GetKeyState(AZUL_KEY::KEY_F))
		//{
		//	vTankPos += Vect(0, 1, 0) * mTankRot * -TankTransSpeed;
		//}

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

	if (isJumping)
	{
		if (vTankPos.Y() > originalY)
		{
			vTankPos.set(vTankPos.X(), vTankPos.Y() + curForce, vTankPos.Z());
			if (curForce > velocityMax)
			{
				//DebugMsg::out("\ncurForce = %f", curForce);
				curForce += gravity;
			}
		}
		else
		{
			vTankPos.set(vTankPos.X(), originalY, vTankPos.Z());
			isJumping = false;
			curForce = force;
		}
		//add to the Y and apply gravity

	}

	if (!onGround)
	{
		if (isJumping)
		{
			//DebugMsg::out("\n%i", isJumping);
			vTankPos.Y() += -.5f;
			CheckAltitude();
			canJump = false;
		}
		else
		{
			vTankPos.Y() += -4.0f;
			CheckAltitude();
			canJump = false;
		}
	}
	else
	{
		AlignToGround();
	}

	mWorld = mTankScale * mTankRot * Matrix(TRANS, vTankPos);
	mWorldTurret = mWorld;
	//vPosTurret.set(vPosTurret.X(), vPosTurret.Y(), vPosTurret.Z());
	//mWorldTurret.set(ROW_3, vPosTurret);
	mWorldTurret = mTankScale * mTankRot * Matrix(TRANS, vTankPos + Vect(0, 6.0f, 0));
	pGObj_TankTurret->SetWorld(mWorldTurret);
	pGObj_Tank->SetWorld(mWorld);
	this->UpdateCollisionData(mWorld);
	//Matrix rr = Matrix(ROT_ORIENT, )


	mTankRotPos = mTankRot * Matrix(TRANS, vTankPos);  // This is the worldmat without scaling
	vNewCamPos = vCamLookAt * mTankRotPos;		// This moves the cam position relative to ship's position and rotation

	vNewLookAt = vCamTankOffset * mTankRotPos;   // This moves the look-at point relative to ship's position and rotation

	SceneManager::getCurScene()->GetCurCam()->setOrientAndPosition(Vect(0, 1, 0), vNewCamPos, vNewLookAt);
	SceneManager::getCurScene()->GetCurCam()->updateCamera();


	//sprite update
	targetAngle += 0.05f;
	//targetSprite->SetRotZ(targetAngle);


	//Vect zztop = terrain->GetTerrainPosNormal(vTankPos);
	//zztop;
	//terrain test
	//vTankPos = terrain->GetTerrainPosNormal(vTankPos);
	//mTankRot = Matrix(ROW_1, terrain->GetTerrainPosNormal(vTankPos));


	//mTankRot.set(ROW_3, terrain->GetTerrainPosNormal(vTankPos));
	//mWorld = mTankScale * mTankRot * Matrix(TRANS, vTankPos);
	//pGObj_Tank->SetWorld(mWorld);
	this->UpdateCollisionData(mWorld);
	//mWorld.set(ROW_1, Vect(terrain->GetTerrainPosNormal(vTankPos).X(), terrain->GetTerrainPosNormal(vTankPos).Y(), terrain->GetTerrainPosNormal(vTankPos).Z(), mWorld.get(ROW_1).W()));
	//Matrix rr = Matrix(ROT_ORIENT, mWorld.get(ROW_2), terrain->GetTerrainPosNormal(vTankPos));
	//mWorld *= rr;
	//mWorld.set(ROT_ORIENT, mWorld.get(ROW_2),terrain->GetTerrainPosNormal(vTankPos));
	pGObj_Tank->SetWorld(mWorld);
}

void JumpTank::AlignToGround()
{
	vTankPos.Y() = groundHeight - (tankVerticalSize * .2f);
}

void JumpTank::CheckAltitude()
{
	//DebugMsg::out("%f", vTankPos.Y());
	if (vTankPos.Y() < deathHeight)
	{
		SceneManager::SetNextScene(new TitleScene());
	}
}

void JumpTank::Collision(Ground* g)
{
	//only do this if i'm not jumping
	if (!isJumping)
	{
		groundHeight = g->GetMaxHeight();
		if ((vTankPos.Y() + tankVerticalSize) >= groundHeight)
		{
			onGround = true;
			canJump = true;
		}

		//DebugMsg::out("Colliding with ground");
	}
	else
	{
		if (curForce < 0)
		{
			groundHeight = g->GetMaxHeight();
			if ((vTankPos.Y() + tankVerticalSize) > groundHeight)
			{
				vTankPos.set(vTankPos.X(), originalY, vTankPos.Z());
				isJumping = false;
				onGround = true;
				canJump = true;
				curForce = force;
			}
		}

	}

}

void JumpTank::Collision(EnemyTank* et)
{
	et;
	SendPlayerDamage(et->GetCollisionDamage());
}

void JumpTank::Collision(EnemyBullet* eb)
{
	eb;
}

void JumpTank::Collision(DestroyerDroid* dd)
{
	dd;
}

void JumpTank::Collision(JetFighter* jf)
{
	jf;
}

void JumpTank::SendPlayerDamage(int d)
{
	if (!godMode)
	{
		playerHealth -= d;
	}
	
	DebugMsg::out("\nHP = %i", playerHealth);
	if (playerHealth < 1)
	{
		SceneManager::SetNextScene(new Level_1());
	}
}

void JumpTank::TerrainMove()
{

	Vect tempPos = GameManager::GetPlayerPos();

	if (canMove)
	{
		if (Keyboard::GetKeyState(AZUL_KEY::KEY_W))
		{
			//InputObject::SubmitInputDeregistration(AZUL_KEY::KEY_Y, INPUT_EVENT_TYPE::KEY_RELEASE);

			vTankPos += Vect(0, 0, 1) * mTankRot * TankTransSpeed;
			vPosTurret += Vect(0, 0, 1) * mTankRot * TankTransSpeed;
			//targetSprite->SetScale(2.0f, 2.0f, 1.0f);


			//acceleration test
			//time += timeStep;
			//zPos = timeStep * (velocity + timeStep * acceleration / 2.0f);
			//velocity += timeStep * acceleration;
			//vTankPos += Vect(0, 0, zPos) * mTankRot;// *TankTransSpeed;

			//DebugMsg::out("Position: %d\n", zPos);
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

		if (Keyboard::GetKeyState(AZUL_KEY::KEY_R))
		{
			vTankPos += Vect(0, 1, 0) * mTankRot * TankTransSpeed;
		}
		else if (Keyboard::GetKeyState(AZUL_KEY::KEY_F))
		{
			vTankPos += Vect(0, 1, 0) * mTankRot * -TankTransSpeed;
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

	if (isJumping)
	{
		if (vTankPos.Y() > originalY)
		{
			vTankPos.set(vTankPos.X(), vTankPos.Y() + curForce, vTankPos.Z());
			if (curForce > velocityMax)
			{
				DebugMsg::out("\ncurForce = %f", curForce);
				curForce += gravity;
			}
		}
		else
		{
			vTankPos.set(vTankPos.X(), originalY, vTankPos.Z());
			isJumping = false;
			curForce = force;
		}
		//add to the Y and apply gravity
	}

	//terrain->GetTerrainPosHeight(vTankPos);
	vTankPos.Y() = TerrainObjectManager::getTerrainObject("MainTerrain")->GetTerrainPosHeight(vTankPos);
	//DebugMsg::out("Y-Pos = %f", vTankPos.Y());
	mWorld = mTankScale * mTankRot * Matrix(TRANS, vTankPos);
	mWorldTurret = mWorld;
	//vPosTurret.set(vPosTurret.X(), vPosTurret.Y(), vPosTurret.Z());
	//mWorldTurret.set(ROW_3, vPosTurret);
	mWorldTurret = mTankScale * mTankRot * Matrix(TRANS, vTankPos + Vect(0, 6.0f, 0));
	pGObj_TankTurret->SetWorld(mWorldTurret);
	pGObj_Tank->SetWorld(mWorld);
	this->UpdateCollisionData(mWorld);
	//Matrix rr = Matrix(ROT_ORIENT, )


	mTankRotPos = mTankRot * Matrix(TRANS, vTankPos);  // This is the worldmat without scaling
	vNewCamPos = vCamLookAt * mTankRotPos;		// This moves the cam position relative to ship's position and rotation
	vNewLookAt = vCamTankOffset * mTankRotPos;   // This moves the look-at point relative to ship's position and rotation
	//SceneManager::getCurScene()->GetCurCam()->setOrientAndPosition(Vect(0, 1, 0), vNewCamPos, vNewLookAt);
	//SceneManager::getCurScene()->GetCurCam()->updateCamera();


	//sprite update
	targetAngle += 0.05f;
	//targetSprite->SetRotZ(targetAngle);


	//Vect zztop = terrain->GetTerrainPosNormal(vTankPos);
	//zztop;
	//terrain test
	//vTankPos = terrain->GetTerrainPosNormal(vTankPos);
	//mTankRot = Matrix(ROW_1, terrain->GetTerrainPosNormal(vTankPos));


	//mTankRot.set(ROW_3, terrain->GetTerrainPosNormal(vTankPos));
	//mWorld = mTankScale * mTankRot * Matrix(TRANS, vTankPos);
	//pGObj_Tank->SetWorld(mWorld);
	//this->UpdateCollisionData(mWorld);
	//mWorld.set(ROW_1, Vect(terrain->GetTerrainPosNormal(vTankPos).X(), terrain->GetTerrainPosNormal(vTankPos).Y(), terrain->GetTerrainPosNormal(vTankPos).Z(), mWorld.get(ROW_1).W()));
	//Matrix rr = Matrix(ROT_ORIENT, mWorld.get(ROW_2), terrain->GetTerrainPosNormal(vTankPos));
	//mWorld *= rr;
	//mWorld.set(ROT_ORIENT, mWorld.get(ROW_2),terrain->GetTerrainPosNormal(vTankPos));
	pGObj_Tank->SetWorld(mWorld);

	//Vect axisPos;
	//axisPos.set(vTankPos.X() - this->GetCollisionSphere().GetRadius(), 0.0f, vTankPos.Z() - this->GetCollisionSphere().GetRadius());
	//axisPos.set(vTankPos.X(), vTankPos.Y(), vTankPos.Z());
	//point->SetPos(axisPos);
	TerrainObjectManager::getTerrainObject("MainTerrain")->SendPosition(vTankPos, this->GetCollisionSphere().GetRadius());
	TerrainObjectManager::getTerrainObject("MainTerrain")->TestIntersection(*this);

	point->SetRot(TerrainObjectManager::getTerrainObject("MainTerrain")->GetTerrainPosNormal(vTankPos));

	//Visualizer::ShowBSphere(this->GetCollisionSphere(), Color::White);
	//Visualizer::ShowCollisionVolume(this, Color::White);
}

void JumpTank::Draw()
{
	pGObj_Tank->Render(SceneManager::getCurScene()->GetCurCam());
	pGObj_TankTurret->Render(SceneManager::getCurScene()->GetCurCam());
	DrawHUD();
	//hpSprite->Render(SceneManager::getCurScene()->GetSpriteCam());
	//targetSprite->Render(SceneManager::getCurScene()->GetSpriteCam());
}

void JumpTank::DrawHUD()
{
	for (int i = 0; i < playerHealth; i++)
	{
		hpSprite[i]->Render(SceneManager::getCurScene()->GetSpriteCam());
	}
}

void JumpTank::KeyPressed(AZUL_KEY k)
{
	switch (k)
	{
	case AZUL_KEY::KEY_SPACE:
		if (isJumping == false && canJump)
		{
			canJump = false;
			onGround = false;
			isJumping = true;
			originalY = vTankPos.Y();
			vTankPos.set(vTankPos.X(), vTankPos.Y() + curForce, vTankPos.Z());
		}
		break;
	case AZUL_KEY::KEY_J:
		BulletFactory::CreateBullet(this->mTankRot, this->vTankPos + Vect(0.0f, 8.0f, 0.0f));
		break;
	case AZUL_KEY::KEY_I:
		vCamTankOffset.Z() += camModifier;
		break;
	case AZUL_KEY::KEY_K:
		DebugMsg::out("\ndist = %f, max dist = %f", (vTankPos - vCamTankOffset).mag(), camMaxDist);
		if ((vCamTankOffset - vTankPos).mag() < camMaxDist)
		{
			vCamTankOffset.Z() -= camModifier;
		}
		else if ((vTankPos - vCamTankOffset).mag() > camMaxDist)
		{
			vCamTankOffset.Z() -= camModifier;
		}
		break;
	case AZUL_KEY::KEY_U:
		vCamTankOffset.Z() = camOriginalZ;
		vNewCamPos = vCamLookAt * mTankRotPos;		// This moves the cam position relative to ship's position and rotation
		vNewLookAt = vCamTankOffset * mTankRotPos;   // This moves the look-at point relative to ship's position and rotation
		break;
	case AZUL_KEY::KEY_F1:
		SceneManager::getCurScene()->SetGodCam();
		break;
	case AZUL_KEY::KEY_F2:
		SceneManager::getCurScene()->UnsetGodCam();
		break;
	case AZUL_KEY::KEY_F5:
		SceneManager::SetNextScene(new Level_1());
		break;
	case AZUL_KEY::KEY_F6:
		SceneManager::SetNextScene(new Level_2());
		break;
	default:
		break;
	}
}

//void JumpTank::KeyReleased(AZUL_KEY k)
//{
//	switch (k)
//	{
//	case AZUL_KEY::KEY_W:
//		time = 0;
//		break;
//	case AZUL_KEY::KEY_T:
//		SceneManager::SetNextScene(new TestScene());
//		break;
//	case AZUL_KEY::KEY_Y:
//		SceneManager::SetNextScene(new DemoScene());
//	default:
//		break;
//	}
//}

Vect JumpTank::GetPos()
{
	return this->vTankPos;
}

JumpTank& JumpTank::operator=(const JumpTank&)
{
	// TODO: insert return statement here
	return *this;
}

JumpTank::~JumpTank()
{
	delete pGObj_Tank;
	delete pGObj_TankTurret;
	for (int i = 0; i < maxHealth; i++)
	{
		delete hpSprite[i];
	}
}
