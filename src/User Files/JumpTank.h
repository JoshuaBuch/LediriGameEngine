#ifndef _JUMPTANK
#define _JUMPTANK

#include "../Lediri Engine/GameObjectDependencies.h"

class TerrainObject;
class Axis;
class JumpTankState;
class Ground;
class EnemyTank;
class EnemyBullet;
class Sprite;
class DestroyerDroid;
class JetFighter;
class L1Trigger_01;
class TriggerObject;
class LevelEnd_1;
class LevelEnd_2;

class JumpTank : public GameObject
{
public:
	JumpTank() = delete;
	JumpTank(int stateSet);
	JumpTank(const JumpTank&) = delete;
	JumpTank& operator=(const JumpTank&);
	~JumpTank();

	void Update();
	void Draw();
	void KeyPressed(AZUL_KEY k);
	
	void Collision(Ground* g);
	void Collision(EnemyTank* et);
	void Collision(EnemyBullet* eb);
	void Collision(DestroyerDroid* dd);
	void Collision(JetFighter* jf);
	//void Collision(L1Trigger_01* t) { t; };
	void Collision(TriggerObject* t) { t; };
	void Collision(LevelEnd_1* e) { e; };
	void Collision(LevelEnd_2* e) { e; };

	Vect GetPos();
	void MovePlayer();
	void TerrainMove();
	void SendPlayerDamage(int d);

private:

	void AlignToGround();
	void CheckAltitude();
	void CreateHUD();
	void UpdateHUD();
	void DrawHUD();
	//wireframe graphics
	//GraphicsObject_WireframeConstantColor* pGObj_Tank = nullptr;
	const JumpTankState* curState;
	static Vect DEFAULT_COLOR;

	GraphicsObject_TextureLight* pGObj_Tank = nullptr;
	GraphicsObject_TextureLight* pGObj_TankTurret = nullptr;
	Vect LightColor = Vect(1.50f, 1.50f, 1.50f, 1.0f);
	Vect LightPos = Vect(1.0f, 1.0f, 1.0f, 1.0f);

	//camera
	Vect vCamLookAt = Vect(0, 20, 90);
	Vect vCamTankOffset = Vect(0, 70, -250);
	Vect vNewCamPos;
	Vect vNewLookAt;
	float camOriginalZ = -250.0f;
	float currentZOffset = -250.0f;
	float camModifier = 15.0f;
	float camMinDist = 50.0f;
	float camMaxDist = 300.0f;
	Matrix camRot;

	Matrix mTankScale;
	Vect vTankPos;
	Matrix mTankRot;
	Matrix mTankRotPos;
	Matrix mWorld;
	Matrix mWorldTurret;
	Vect vPosTurret;

	const float TankTransSpeed = 4.5f;
	const float TankRotAng = .03f;
	

	float targetAngle = 0;

	bool canMove = true;

	//health
	int maxHealth = 10;
	int playerHealth = maxHealth;

	//jumping
	bool isJumping = false;
	bool canJump = true;

	//ground variables
	float tankVerticalSize = 0;
	bool onGround = false;
	float groundHeight;
	float deathHeight = -1000.0f;

	float force = 5.0f;
	float curForce = force;
	float gravity = -.1f;
	float velocityMax = -10.0f;

	float originalY;

	//Hud code
	Sprite* hpSprite[10];
	float spriteX = 30.0f;
	float spriteY;
	float spriteOffset = 30.0f;

	//junk test code
	Axis* point;
	TerrainObject* terrain;
	bool godMode;
};
#endif