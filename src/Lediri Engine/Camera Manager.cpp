#include "Camera Manager.h"
#include "Lediri.h"

CameraManager::CameraManager()
{
	pOrthographicCam = new Camera(Camera::Type::ORTHOGRAPHIC_2D);

	assert(pOrthographicCam);

	pOrthographicCam->setViewport(0, 0, Lediri::pubGetWidth(), Lediri::pubGetHeight());
	pOrthographicCam->setOrthographic(-0.5f*Lediri::pubGetWidth(), 0.5f*Lediri::pubGetWidth(), -0.5f*Lediri::pubGetHeight(), 0.5f*Lediri::pubGetHeight(), 1.0f, 1000.0f);
	
	Vect up2DCam(0.0f, 1.0f, 0.0f);
	Vect pos2DCam(0.0f, 0.0f, 0.0f);
	Vect lookAt2DCam(0.0f, 0.0f, -1.0f);
	pOrthographicCam->setOrientAndPosition(up2DCam, lookAt2DCam, pos2DCam);

	pOrthographicCam->updateCamera();  // Again, if we change anythign about the camera, we need to call update again

	this->SetDefaultCam();
	pGodCam = new Camera(Camera::Type::PERSPECTIVE_3D);
	this->InitializeGodCamera();
}

void CameraManager::SetDefaultCam()
{
	DebugMsg::out("\n\npDefaultCam Created");
	pDefaultCam = new Camera(Camera::Type::PERSPECTIVE_3D);
	pDefaultCam->setViewport(0, 0, Lediri::pubGetWidth(), Lediri::pubGetHeight());
	pDefaultCam->setPerspective(35.0f, float(Lediri::pubGetWidth()) / float(Lediri::pubGetHeight()), 1.0f, 5000.0f);


	// Orient Camera
	Vect up3DCam(0.0f, 1.0f, 0.0f);
	Vect pos3DCam(50.0f, 50.0f, 150.0f);
	Vect lookAt3DCam(0.0f, 0.0f, 0.0f);
	pDefaultCam->setOrientAndPosition(up3DCam, lookAt3DCam, pos3DCam);
	pDefaultCam->updateCamera();  // Note: if the camera moves/changes, we need to call update again
	
	pCurCam = pDefaultCam;

}

Camera* CameraManager::GetCurCam()
{
	return this->pCurCam;
}

Camera * CameraManager::GetSpriteCam()
{
	return pOrthographicCam;
}

void CameraManager::SetCurCam(Camera* newCam)
{
	this->pCurCam = newCam;
}

void CameraManager::InitializeGodCamera()
{

	pGodCam->setViewport(0, 0, Lediri::pubGetWidth(), Lediri::pubGetHeight());
	pGodCam->setPerspective(35.0f, float(Lediri::pubGetWidth()) / float(Lediri::pubGetHeight()), 1.0f, 5000.0f);

	// Orient Camera
	Vect up3DCam(0.0f, 1.0f, 0.0f);
	Vect pos3DCam(50.0f, 50.0f, 150.0f);
	Vect lookAt3DCam(0.0f, 0.0f, 0.0f);

	camSpeed = 2.0f;
	camRotation = 0.02f;

	CamOffset.set(10.0f, 00.0f, 0.0f);
	CamPos.set(0.0f, 70.0f, -120.0f);
	CamRot.set(IDENTITY);
	CamUp.set(0, 1, 0);
	CamDir.set(0, 0, 1);

	Vect Target(0, 0, 0);
	CamRot.set(ROT_ORIENT, Target - CamPos, CamUp);
	//CamRot *= Matrix(ROT_Y, 3.14159f);

	pGodCam->setOrientAndPosition(CamUp * CamRot, CamPos + CamDir * CamRot, CamPos);
	pGodCam->updateCamera();  // Note: if the camera moves/changes, we need to call update again

}

void CameraManager::GodCameraUpdate()
{
	// Camera translation movement (NOTE: This time, I'm NOT using time-based values for simplicity)
	if (Keyboard::GetKeyState(AZUL_KEY::KEY_I))
	{
		CamPos += Vect(0, 0, 1) * CamRot * camSpeed;
	}
	else if (Keyboard::GetKeyState(AZUL_KEY::KEY_K))
	{
		CamPos += Vect(0, 0, 1) * CamRot * -camSpeed;
	}

	if (Keyboard::GetKeyState(AZUL_KEY::KEY_J))
	{
		CamPos += Vect(1, 0, 0) * CamRot * camSpeed;
	}
	else if (Keyboard::GetKeyState(AZUL_KEY::KEY_L))
	{
		CamPos += Vect(1, 0, 0) * CamRot * -camSpeed;
	}

	// Camera Rotation movement (NOTE: This time, I'm NOT using time-based values for simplicity)
	if (Keyboard::GetKeyState(AZUL_KEY::KEY_ARROW_LEFT))
	{
		CamRot *= Matrix(ROT_Y, camRotation);
	}
	else if (Keyboard::GetKeyState(AZUL_KEY::KEY_ARROW_RIGHT))
	{
		CamRot *= Matrix(ROT_Y, -camRotation);
	}

	if (Keyboard::GetKeyState(AZUL_KEY::KEY_ARROW_UP))
	{
		CamRot *= Matrix(ROT_AXIS_ANGLE, Vect(1, 0, 0) * CamRot, -camRotation);
	}
	else if (Keyboard::GetKeyState(AZUL_KEY::KEY_ARROW_DOWN))
	{
		CamRot *= Matrix(ROT_AXIS_ANGLE, Vect(1, 0, 0) * CamRot, camRotation);
	}

	// Update the camera settings
	//pCurrentCamera->setOrientAndPosition(CamUp * CamRot, CamPos + CamDir * CamRot, CamPos);
	//DebugMsg::out("\nCamPos: %f, %f, %f", CamPos.X(), CamPos.Y(), CamPos.Z());
	pGodCam->setOrientAndPosition(CamUp * CamRot, CamPos + CamDir * CamRot, CamPos);
	pGodCam->updateCamera();
}

void CameraManager::SetGodCamera()
{
	LastCam = pCurCam;
	pCurCam = pGodCam;
}

void CameraManager::UnsetGodCamera()
{
	pCurCam = LastCam;
}


//this is never being called. Do I need this?
void CameraManager::DeleteDefaultCamera()
{
	delete pDefaultCam;
	pDefaultCam = nullptr;
	delete pGodCam;
	pGodCam = nullptr;
	delete pOrthographicCam;
	pOrthographicCam = nullptr;
}

CameraManager::~CameraManager()
{
	delete pDefaultCam;
	pDefaultCam = nullptr;
	pCurCam = nullptr;
	delete pGodCam;
	pGodCam = nullptr;
	delete pOrthographicCam;
	pOrthographicCam = nullptr;

}