#ifndef Bullet_H
#define Bullet_H

#include "../Lediri Engine/GameObjectDependencies.h"

class SceneManager;
class Frigate;
class EnemyTank;
class JetFighter;
class DestroyerDroid;
class Enemy;
class L2Trigger_02;

class Bullet : public GameObject
{
public:

	void Update();
	void Draw();
	void Alarm0();

	void Initialize(const Matrix& rot, const Vect& pos);
	void SceneEntry();
	void SceneExit();

	void Collision(EnemyTank* et);
	void Collision(JetFighter* jf);
	void Collision(DestroyerDroid* dd);
	void Collision(L2Trigger_02* t);

	Bullet();
	Bullet(const Bullet&) = delete;
	Bullet& operator=(const Bullet&) = delete;
	~Bullet();

private:
	GraphicsObject_TextureFlat* pGObj_BulletLight = nullptr;

	Matrix BulletScale;
	Vect BulletPos;
	Matrix BulletRot;
	Matrix BulletRotPos;
	Vect vBulletForward;
	Matrix worldPos;
	const float BulletSpeed = 2.0f;
	
	bool alarmRegistered = false;
};
#endif // !Bullet_H
