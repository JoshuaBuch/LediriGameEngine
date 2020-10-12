#ifndef _PHYSICSDEMOSCENE
#define _PHYSICSDEMOSCENE

#include "../Lediri Engine/Lediri.h"
#include "../User Files/Plane.h"
#include "../User Files/Axis.h"

class Plane;
class Axis;
class Cube;

class PhysicsDemoScene : public Scene
{
public:

	PhysicsDemoScene() = default;
	PhysicsDemoScene(const PhysicsDemoScene&) = delete;
	PhysicsDemoScene& operator=(const PhysicsDemoScene&) = delete;
	~PhysicsDemoScene() {};

	void Initialize();
	void SceneEnd();

private:
	Plane* pPlaneGO;
	Axis* pAxisGO;
	Cube* pCubeGO;
};

#endif // ! _PHYSICSDEMOSCENE
