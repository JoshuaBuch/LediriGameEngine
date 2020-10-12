#ifndef TestScene_H
#define TestScene_H

#include "../Lediri Engine/Scene.h"
#include "Frigate.h"
#include "Tank.h"
#include "StitchSprite.h"
#include "Cottage.h"

class TestScene : public Scene
{
public:

	TestScene() = default;
	TestScene(const TestScene&) = delete;
	TestScene& operator=(const TestScene&) = delete;
	~TestScene() {};

	void Initialize();
	void SceneEnd();

private:
	Frigate* pFrigateGO;
	Tank* pTankGO;
	StitchSprite* pStitchSprite;
	Cottage* pCottage;

};
#endif // !TestScene_H
