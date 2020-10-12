#ifndef _CAMERAMANAGER
#define _CAMERAMANAGER

#include "AzulCore.h"

class Camera;

class CameraManager : public Align16
{
public:

	CameraManager();
	CameraManager(const CameraManager&) = delete;
	CameraManager& operator=(const CameraManager&) = delete;
	~CameraManager();

	void SetDefaultCam();
	void SetCurCam(Camera* newCam);
	Camera* GetCurCam();
	Camera* GetSpriteCam();

	void SetGodCamera();
	void UnsetGodCamera();

private:

	friend class Scene;
	Camera* pDefaultCam;
	Camera* pCurCam = nullptr;
	Camera* pOrthographicCam;
	Camera* pGodCam;
	Camera* LastCam;

	friend class Lediri;

	void DeleteDefaultCamera(); //this is never called
	void InitializeGodCamera();
	void GodCameraUpdate();
	//void privUpdateCurCam();
	
	Vect CamOffset;
	Vect CamPos;
	Matrix CamRot;
	Vect CamUp;
	Vect CamDir;
	float camSpeed;
	float camRotation;


};

#endif _CAMERAMANAGER