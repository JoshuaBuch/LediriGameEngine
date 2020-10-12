#include "PhysicsObject.h"
#include "AzulCore.h"

PhysicsObject::PhysicsObject()
{
	
}

void PhysicsObject::SubmitPhysicsRegistration(Matrix s, Matrix r, Matrix t)
{
	mScale = s;
	mRotation = r;
	mTrans = t;
	mWorld = new Matrix();
	*mWorld	= mScale * mRotation * mTrans;

}

void PhysicsObject::ProcessActions()
{
	ProcessMoves();
}

void PhysicsObject::ProcessMoves()
{
	//requires handle to game objects
	//move game object by 1 unit
	if (moves > 0)
	{
		*mWorld = (*mWorld) * Matrix(TRANS, forward);
		moves--;
	}
}

void PhysicsObject::AddMove(float m)
{
	moves += m;
}

Matrix& PhysicsObject::GetWorld()
{
	return *mWorld;
}

PhysicsObject::~PhysicsObject()
{
	delete mWorld;
}