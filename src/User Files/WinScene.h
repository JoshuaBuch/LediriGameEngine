#ifndef _WINSCENE_H
#define _WINSCENE_H

#include "../Lediri Engine/Scene.h"

class WinProgressor;

class WinScene : public Scene
{
public:
	WinScene() = default;
	WinScene(const WinScene&) = delete;
	WinScene& operator=(const WinScene&) = delete;
	~WinScene() {};

	void Initialize();
	void SceneEnd();

private:
	WinProgressor* wp = nullptr;

};
#endif
