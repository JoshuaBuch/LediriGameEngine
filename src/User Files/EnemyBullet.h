#ifndef EnemyBullet_H
#define EnemyBullet_H

#include "../Lediri Engine/GameObjectDependencies.h"
#include "Enemy.h"

class JumpTank;

class EnemyBullet : public Enemy
{
public:
	EnemyBullet();
	EnemyBullet(Vect pos, Vect dir, float s, int d);
	EnemyBullet(const EnemyBullet&) = delete;
	EnemyBullet& operator=(const EnemyBullet&) = delete;
	~EnemyBullet();

	void Update();
	void Draw();
	void Alarm0();
	void SceneExit();
	void SceneEntry();
	void Initialize(Vect pos, Vect dir, int d);

	void Collision(JumpTank* jt);



private:
	GraphicsObject_TextureFlat* pGObj_EBullet = nullptr;

	bool alarmRegistered = false;

	Vect direction;
};
#endif // !EnemyBullet_H