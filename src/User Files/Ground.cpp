#include "Ground.h"
#include "GameManager.h"
#include "../Lediri Engine/Visualizer.h"

Ground::Ground()
{
	pGObj_Ground = new GraphicsObject_TextureFlat(ModelManager::getModel("UnitBox"), ShaderManager::getShader("ShaderObject_texture"), TextureManager::getTexture("BlueFloorTex"), TextureManager::getTexture("BlueFloorTex"));

	world = Matrix(IDENTITY);
	Vect s;
	s.set(100.0f, 100.0f, 100.0f);
	scale = Matrix(SCALE, s);

	//pos.set(2.57f, 0, 2.57f);
	pos.set(0, -52, 0);
	world = scale * Matrix(TRANS, pos);

	pGObj_Ground->SetWorld(world);
	

	DrawObject::SubmitDrawRegistration();

	CollisionObject::SubmitCollisionRegistration<Ground>(this);
	SetColliderModel(pGObj_Ground->getModel(), COLLISION_VOLUME_TYPE::AABB);
	UpdateCollisionData(world);
}

Ground::Ground(float posx, float posy, float posz, float scaleNum)
{
	pGObj_Ground = new GraphicsObject_TextureFlat(ModelManager::getModel("UnitBox"), ShaderManager::getShader("ShaderObject_texture"), TextureManager::getTexture("FloorTex2"), TextureManager::getTexture("FloorTex2"), TextureManager::getTexture("FloorTex2"));

	world = Matrix(IDENTITY);
	Vect s;
	s.set(scaleNum, scaleNum, scaleNum);
	scale = Matrix(SCALE, s);

	//pos.set(2.57f, 0, 2.57f);
	pos.set(posx, posy, posz);
	world = scale * Matrix(TRANS, pos);

	pGObj_Ground->SetWorld(world);


	DrawObject::SubmitDrawRegistration();

	CollisionObject::SubmitCollisionRegistration<Ground>(this);
	SetColliderModel(pGObj_Ground->getModel(), COLLISION_VOLUME_TYPE::AABB);
	UpdateCollisionData(world);

	GameManager::UpdateLevelDeathHeight(posy); //jumptank needs to be last object created
}

void Ground::Update()
{
	//Visualizer::ShowCollisionVolume(this, Color::Green);
}

void Ground::Draw()
{
	pGObj_Ground->Render(SceneManager::getCurScene()->GetCurCam());
}

void Ground::SetPos(Vect p)
{
	world = Matrix(IDENTITY);
	world = scale * Matrix(TRANS, p);
	pGObj_Ground->SetWorld(world);
}

const float Ground::GetMaxHeight()
{
	maxHeightPos = scale.get(ROW_1).mag() * .5f;
	maxHeightPos += this->pos.Y();
	return maxHeightPos;
}

void Ground::Collision(JumpTank* go)
{
	go;
}

Ground::~Ground()
{
	delete pGObj_Ground;
}