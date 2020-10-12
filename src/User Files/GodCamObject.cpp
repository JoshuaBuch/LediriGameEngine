#include "GodCamObject.h"

GodCamObject::GodCamObject()
{
	SubmitUpdateRegistration();
	InputObject::SubmitInputRegistration(AZUL_KEY::KEY_F1, INPUT_EVENT_TYPE::KEY_PRESS);
	InputObject::SubmitInputRegistration(AZUL_KEY::KEY_F2, INPUT_EVENT_TYPE::KEY_PRESS);
}

GodCamObject::~GodCamObject()
{

}

void GodCamObject::Update()
{

}


void GodCamObject::KeyPressed(AZUL_KEY k)
{
	switch (k)
	{
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

void GodCamObject::KeyReleased(AZUL_KEY k)
{
	k;
}