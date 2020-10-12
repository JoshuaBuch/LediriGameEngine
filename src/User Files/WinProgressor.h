#ifndef _WINPROGRESSOR_H
#define _WINPROGRESSOR_H

#include "../Lediri Engine/GameObjectDependencies.h"

class Sprite;

class WinProgressor : public GameObject
{
public:
	WinProgressor();
	WinProgressor(const WinProgressor&) = delete;
	WinProgressor& operator=(const WinProgressor&) = delete;
	~WinProgressor();

	void Draw();
	void Update();

private:
	Sprite* titleSprite = nullptr;


};

#endif // !_WINPROGRESSOR_H