#ifndef _CUBE
#define _CUBE

#include "../Lediri Engine/Lediri.h"

class Cube : public GameObject
{
public:

	Cube();
	Cube(const Cube&) = delete;
	Cube& operator=(const Cube&) = delete;
	~Cube();

	void Update();
	void Draw();
	void KeyPressed(AZUL_KEY k);

private:
	GraphicsObject_TextureLight * pGObj_Cube;

	//shader settings
	Vect LightColor = Vect(1.50f, 1.50f, 1.50f, 1.0f);
	Vect LightPos = Vect(1.0f, 1.0f, 1.0f, 1.0f);

	//Camera settings
	Vect vCamLookAt = Vect(0, 20, 90);
	Vect vCamCubeOffset = Vect(0, 70, -150);
	Vect vNewCamPos;
	Vect vNewLookAt;
	Matrix mCubeRotPos;

	//World Matrix settings
	Vect vCubePos;
	Matrix mCubeRot = Matrix(IDENTITY);
	Matrix mCubeScale = Matrix(SCALE, 30.0f, 30.0f, 30.0f);
	const float CubeTransSpeed = 1.0f;
	Matrix mWorld;


	//acceleration test
	float acceleration = 1;
	float time;
	float timeStep = 0.1f;
	float zPos = 1;
	float velocity = 0;
	float newAcceleration;
	const float force = 2;
};
#endif // !_CUBE
