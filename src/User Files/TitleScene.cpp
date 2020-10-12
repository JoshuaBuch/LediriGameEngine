#include "TitleScene.h"
#include "TitleProgressor.h"

void TitleScene::Initialize()
{
	tp = new TitleProgressor();
}

void TitleScene::SceneEnd()
{
	delete tp;
}