#ifndef _AXIS
#define _AXIS

#include "../Lediri Engine/Lediri.h"

class Plane;

class Axis : public GameObject
{
public:
	void Update();
	void Input();
	void Draw();
	void Collision(Plane* p);

	Axis();
	Axis(const Axis&) = delete;
	Axis& operator=(const Axis&) = delete;
	~Axis();

	void SetPos(Vect p);
	void SetRot(Vect m);
private:
	GraphicsObject_ColorNoTexture * pGObj_Axis;

	Matrix world;
	Matrix scale;
	Vect pos;


};
#endif // !_AXIS