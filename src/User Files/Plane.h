#ifndef _PLANE
#define _PLANE

#include "../Lediri Engine/Lediri.h"


class Plane : public GameObject
{
public:
	void Update();
	void Draw();


	Plane();
	Plane(const Plane&) = delete;
	Plane& operator=(const Plane&) = delete;
	~Plane() override;


private:
	GraphicsObject_TextureFlat * pGObj_Plane = nullptr;



};
#endif // !_PLANE
