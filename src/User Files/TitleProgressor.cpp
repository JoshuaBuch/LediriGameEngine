#include "TitleProgressor.h"
#include "../Lediri Engine/Sprite.h"
#include "../Lediri Engine/Lediri.h"
#include "Level_1.h"

TitleProgressor::TitleProgressor()
{
	titleSprite = new Sprite(ImageManager::getImage("TitleImage"));
	float transX = (float)Lediri::pubGetWidth() / 2.0f;
	float transY = ((float)Lediri::pubGetHeight() / 2.0f) + 60.0f;
	titleSprite->SetTrans(transX, transY);
	titleSprite->SetRotZ(0.0f);
	titleSprite->SetScale(8.0f, 8.0f, 8.0f);

	SubmitDrawRegistration();
	SubmitUpdateRegistration();

	SceneManager::getCurScene()->GetCurCam()->setOrientAndPosition(Vect(0, 1, 0), Vect(0, 0, 0), Vect(0, 0, 0));
	SceneManager::getCurScene()->GetCurCam()->updateCamera();
}

void TitleProgressor::Update()
{
	float transX = (float)Lediri::pubGetWidth() / 2.0f;
	float transY = ((float)Lediri::pubGetHeight() / 2.0f);// +60.0f;
	titleSprite->SetTrans(transX, transY);
	titleSprite->SetRotZ(3.14159f);

	if (Keyboard::GetKeyState(AZUL_KEY::KEY_ENTER))
	{
		SceneManager::SetNextScene(new Level_1());
	}
}

void TitleProgressor::Draw()
{
	titleSprite->Render(SceneManager::getCurScene()->GetSpriteCam());
}

TitleProgressor::~TitleProgressor()
{
	delete titleSprite;
	titleSprite = nullptr;
}