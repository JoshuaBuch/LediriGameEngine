#ifndef _TITLEPROGRESSOR_H
#define _TITLEPROGRESSOR_H

#include "../Lediri Engine/GameObjectDependencies.h"

class Sprite;

class TitleProgressor : public GameObject
{
public:
	TitleProgressor();
	TitleProgressor(const TitleProgressor&) = delete;
	TitleProgressor& operator=(const TitleProgressor&) = delete;
	~TitleProgressor();

	void Draw();
	void Update();

private:
	Sprite* titleSprite = nullptr;


};

#endif // !_TITLEPROGRESSOR_H
