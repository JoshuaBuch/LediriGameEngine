#include "Cube.h"

Cube::Cube()
{
	pGObj_Cube = new GraphicsObject_TextureLight(ModelManager::getModel("UnitBox"), ShaderManager::getShader("ShaderObject_textureLight"), TextureManager::getTexture("CabinTex"), TextureManager::getTexture("CabinTex"), TextureManager::getTexture("TankBodyTex"), LightColor, LightPos);


	DrawObject::SubmitDrawRegistration();
	SubmitUpdateRegistration();
	InputObject::SubmitInputRegistration(AZUL_KEY::KEY_W, INPUT_EVENT_TYPE::KEY_PRESS);


	//Movement wrapper code for physics object
	//pGObj_Cube->SetWorld(GetWorld());


}


void Cube::Update()
{
	//ProcessActions();
	if (Keyboard::GetKeyState(AZUL_KEY::KEY_W))
	{

		vCubePos += Vect(0, 0, 1) * mCubeRot * CubeTransSpeed;

		//acceleration test
		time += timeStep;
		zPos = timeStep * (velocity + timeStep * acceleration / 2.0f);
		velocity += timeStep * acceleration;
		vCubePos += Vect(0, 0, zPos) * mCubeRot;// *TankTransSpeed;

		//DebugMsg::out("Velocity: %f\n", velocity);
	}
	else
	{
		if (zPos > 0)
		{
			time += timeStep;
			zPos = timeStep * (velocity + timeStep * acceleration / 2.0f);
			velocity -= timeStep * acceleration;
			vCubePos += Vect(0, 0, zPos) * mCubeRot;// *TankTransSpeed;
			DebugMsg::out("Velocity: %f\n", velocity);
		}

	}


	//mWorld = mCubeScale * mCubeRot * Matrix(TRANS, vCubePos);
	//pGObj_Cube->SetWorld(this->GetWorld());

	mCubeRotPos = mCubeRot * Matrix(TRANS, vCubePos);
	vNewCamPos = vCamLookAt * mCubeRotPos;		// This moves the cam position relative to ship's position and rotation
	vNewLookAt = vCamCubeOffset * mCubeRotPos;   // This moves the look-at point relative to ship's position and rotation
	SceneManager::getCurScene()->GetCurCam()->setOrientAndPosition(Vect(0, 1, 0), vNewCamPos, vNewLookAt);
	SceneManager::getCurScene()->GetCurCam()->updateCamera();
}

void Cube::Draw()
{
	pGObj_Cube->Render(SceneManager::getCurScene()->GetCurCam());
}

void Cube::KeyPressed(AZUL_KEY k)
{
	switch (k)
	{
	case AZUL_KEY::KEY_W:
		DebugMsg::out("\nW was pressed by Cube");
		//AddMove(100.0f);
	default:
		break;
	}
}

Cube::~Cube()
{
	delete pGObj_Cube;
	pGObj_Cube = nullptr;
}