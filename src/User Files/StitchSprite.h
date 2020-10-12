#ifndef StitchSprite_H
#define StitchSprite_H

#include "../Lediri Engine/Sprite.h"

class Model;

class StitchSprite : public Sprite
{
public:
	StitchSprite();
	StitchSprite(const StitchSprite&) = delete;
	StitchSprite& operator=(const StitchSprite&) = delete;
	~StitchSprite() {};

	void Draw();
	void Update();

private:

	float angle = 0;
	float xt = 0;
	float yt = 0;
};
#endif // !StitchSprite_H
