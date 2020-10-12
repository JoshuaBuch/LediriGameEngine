#include "WinScene.h"
#include "WinProgressor.h"

void WinScene::Initialize()
{
	wp = new WinProgressor();
}

void WinScene::SceneEnd()
{
	delete wp;
}