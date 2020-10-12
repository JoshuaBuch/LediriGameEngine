#ifndef _GROUND
#define _GROUND

#include "../Lediri Engine/Lediri.h"

class JumpTank;

class Ground : public GameObject
{
public:
	void Update();
	void Input();
	void Draw();
	void Collision(JumpTank* go);

	Ground();
	Ground(float posx, float posy, float posz, float scaleNum);
	Ground(const Ground&) = delete;
	Ground& operator=(const Ground&) = delete;
	~Ground();

	void SetPos(Vect p);
	const float GetMaxHeight();
private:
	GraphicsObject_TextureFlat* pGObj_Ground;

	Matrix world;
	Matrix scale;
	Vect pos;

	float maxHeightPos;


};
#endif // !_GROUND