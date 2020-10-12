#ifndef _FRIGATE
#define _FRIGATE

//#include "../Lediri Engine/Lediri.h"
#include "../Lediri Engine/GameObject.h"
#include "AzulCore.h"

class BSphere;
class SceneManager;
class Tank;
class Bullet;
class Cottage;

class Frigate : public GameObject
{
public:
	void Update();
	void Draw();
	void Alarm0();
	void Alarm1();
	void Alarm2();
	void Alarm3();
	void Alarm4();
	Matrix getFrigateWorld();

	void Collision(Tank* f);
	void Collision(Cottage* c) { c; };
	Frigate();
	Frigate(Vect ranPos);
	Frigate(const Frigate&) = delete;
	Frigate& operator=(const Frigate&) = delete;
	~Frigate();

private:
	GraphicsObject_TextureLight* pGObj_FT = nullptr;
	
	Vect CamLookAt = Vect(0, 0, 0);
	Vect CamShipOffset = Vect(0, 70, -150);
	Vect vNewCamPos;
	Vect vNewLookAt;

	Matrix ShipScale;
	Vect ShipPos;
	Matrix ShipRot;
	Matrix ShipRotPos;
	float ShipTransSpeed = 1;
	float ShipRotAng = 0.05f;

	bool frigateDrawOn = true;
	bool BulletReady = true;

};
#endif // !_FRIGATE