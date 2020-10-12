#ifndef DESTROYERDROID_H
#define DESTROYERDROID_H

#include "Enemy.h"
class DestroyerDroidState;
class JumpTank;
class Bullet;

enum class Speed
{
	Slow = 0,
	Fast = 1
};

class DestroyerDroid : public Enemy
{
public:
	DestroyerDroid() = delete;
	DestroyerDroid(float x, float y, float z, Speed sp);
	DestroyerDroid(const DestroyerDroid&) = delete;
	DestroyerDroid& operator=(const DestroyerDroid&) = delete;
	virtual ~DestroyerDroid();

	void Update() override;
	void Draw() override;
	void Collision(JumpTank* jt);
	void Collision(Bullet* b);
	void SubmitExit();

	void MoveTowardsPlayer();
	bool isPlayerInRange();
	void ChangeState(const DestroyerDroidState* ptrState);
	
private:
	//graphic variables, temporary to enemy for testing
	GraphicsObject_TextureLight* pGObj_Temp = nullptr;
	Vect LightColor = Vect(1.50f, 1.50f, 1.50f, 1.0f);
	Vect LightPos = Vect(1.0f, 1.0f, 1.0f, 1.0f);

	const DestroyerDroidState* curState;
	bool dead = false;
};
#endif