#include "LevelEnd_2.h"
#include "WinScene.h"

Vect LevelEnd_2::DEFAULT_COLOR = Color::Blue;

LevelEnd_2::LevelEnd_2(float posx, float posy, float posz, float scaleNum)
{
	pGObj_Trigger = new GraphicsObject_WireframeConstantColor(ModelManager::getModel("UnitBox"), ShaderManager::getShader("ShaderObject_constantColor"), DEFAULT_COLOR);

	world = Matrix(IDENTITY);
	Vect s;
	s.set(scaleNum, scaleNum, scaleNum);
	scale = Matrix(SCALE, s);

	//pos.set(2.57f, 0, 2.57f);
	pos.set(posx, posy, posz);
	world = scale * Matrix(TRANS, pos);

	pGObj_Trigger->SetWorld(world);


	DrawObject::SubmitDrawRegistration();
	SubmitUpdateRegistration();

	CollisionObject::SubmitCollisionRegistration<LevelEnd_2>(this);
	SetColliderModel(pGObj_Trigger->getModel(), COLLISION_VOLUME_TYPE::AABB);
	UpdateCollisionData(world);
}

void LevelEnd_2::Update()
{
	UpdateCollisionData(world);
	pGObj_Trigger->SetWorld(world);

}

void LevelEnd_2::Draw()
{
	pGObj_Trigger->Render(SceneManager::getCurScene()->GetCurCam());
}

void LevelEnd_2::Collision(JumpTank* jt)
{
	jt;
	SceneManager::SetNextScene(new WinScene());
}

LevelEnd_2::~LevelEnd_2()
{
	delete pGObj_Trigger;
}