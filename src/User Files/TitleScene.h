#ifndef _TITLESCENE_H
#define _TITLESCENE_H

#include "../Lediri Engine/Scene.h"

class TitleProgressor;

class TitleScene : public Scene
{
public:
	TitleScene() = default;
	TitleScene(const TitleScene&) = delete;
	TitleScene& operator=(const TitleScene&) = delete;
	~TitleScene() {};

	void Initialize();
	void SceneEnd();

private:
	TitleProgressor* tp = nullptr;

};
#endif

