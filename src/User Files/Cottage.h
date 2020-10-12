#ifndef _COTTAGE
#define _COTTAGE

#include "../Lediri Engine//GameObject.h"
#include "AzulCore.h"

class SceneManager;
class Frigate;

class Cottage : public GameObject
{
public:
	void Update();
	void Draw();
	void KeyPressed(AZUL_KEY k);
	void Collision(Frigate* f) { f;  };

	Cottage();
	Cottage(const Cottage&) = delete;
	Cottage& operator=(const Cottage&) = delete;
	~Cottage();
private:
	GraphicsObject_TextureLight * pGObj_Cottage = nullptr;

	Matrix CotScale;
	Vect CotPos;
	Matrix CotRot;

	const float CotRotAng = .05f;

	
};
#endif // !_COTTAGE
