#include "WinProgressor.h"
#include "../Lediri Engine/Sprite.h"
#include "../Lediri Engine/Lediri.h"
#include "Level_1.h"

WinProgressor::WinProgressor()
{
	titleSprite = new Sprite(ImageManager::getImage("WinImage"));
	float transX = (float)Lediri::pubGetWidth() / 2.0f;
	float transY = ((float)Lediri::pubGetHeight() / 2.0f) + -20.0f;
	titleSprite->SetTrans(transX, transY);
	titleSprite->SetRotZ(0.0f);
	titleSprite->SetScale(8.0f, 8.0f, 8.0f);

	SubmitDrawRegistration();
	SubmitUpdateRegistration();

	SceneManager::getCurScene()->GetCurCam()->setOrientAndPosition(Vect(0, 1, 0), Vect(0, 0, 0), Vect(0, 0, 0));
	SceneManager::getCurScene()->GetCurCam()->updateCamera();
}

void WinProgressor::Update()
{
	float transX = (float)Lediri::pubGetWidth() / 2.0f;
	float transY = ((float)Lediri::pubGetHeight() / 2.0f - 40.0f);// +60.0f;
	titleSprite->SetTrans(transX, transY);
	titleSprite->SetRotZ(3.14159f);

	if (Keyboard::GetKeyState(AZUL_KEY::KEY_ENTER))
	{
		SceneManager::SetNextScene(new Level_1());
	}
}

void WinProgressor::Draw()
{
	titleSprite->Render(SceneManager::getCurScene()->GetSpriteCam());
}

WinProgressor::~WinProgressor()
{
	delete titleSprite;
	titleSprite = nullptr;
}