#ifndef _PHYSICSOBJECT
#define _PHYSICSOBJECT

#include "RegistrationStateEnum.h"
#include "AzulCore.h"

class GameObject;
class Vect;

class PhysicsObject : public Align16
{
public:
	PhysicsObject();
	virtual ~PhysicsObject();
	void ProcessActions();
	void AddMove(float m);
	Matrix& GetWorld();

protected: //only inhereted classes have access to protected
	void SubmitPhysicsRegistration(Matrix s, Matrix r, Matrix t);
	//void SubmitUpdateDeregistration();

private:
	void ProcessMoves();
	float moves = 0.0f;
	Vect position = Vect(0, 0, 0);
	Vect forward = Vect(0, 0, 1);
	Matrix* mWorld;
	Matrix mScale = Matrix(IDENTITY);
	Matrix mTrans = Matrix(IDENTITY);
	Matrix mRotation = Matrix(IDENTITY);


};
#endif // !_PHYSICSOBJECT
