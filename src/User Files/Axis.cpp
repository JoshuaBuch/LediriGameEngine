#include "Axis.h"
#include "../Lediri Engine/Visualizer.h"

//#include "../Lediri Engine/TerrainModel.h"

Axis::Axis()
{
	pGObj_Axis = new GraphicsObject_ColorNoTexture(ModelManager::getModel("ModelAxis"), ShaderManager::getShader("ShaderObject_colorNoTexture"));

	world = Matrix(IDENTITY);
	Vect s;
	s.set(11.2f, 11.2f, 11.2f);
	scale = Matrix(SCALE, s);

	//pos.set(2.57f, 0, 2.57f);
	pos.set(0, 0, 0);
	pos.set(2.5f, 0.0f, 7.0f);
	world = scale * Matrix(TRANS, pos);
	pGObj_Axis->SetWorld(world);

	//DebugMsg::out("\n\nAxis is trying to register to draw manager");
	DrawObject::SubmitDrawRegistration();

	CollisionObject::SubmitCollisionRegistration<Axis>(this);

	//TerrainModel* terrain = new TerrainModel();
	//terrain->BuildTerrain();
	//terrain->SendPosition(pos);
}

void Axis::Update()
{
	
}

void Axis::Draw()
{
	pGObj_Axis->Render(SceneManager::getCurScene()->GetCurCam());
}

void Axis::SetPos(Vect p)
{
	world = Matrix(IDENTITY);
	Vect s;
	s.set(11.2f, 11.2f, 11.2f);
	scale = Matrix(SCALE, s);

	pos.set(p.X(), p.Y(), p.Z());
	world = scale * Matrix(TRANS, pos);
	pGObj_Axis->SetWorld(world);
}

void Axis::SetRot(Vect v)
{
	//v = v * 11.2f;
	DebugMsg::out("\nNormal = %f, %f, %f", v.X(), v.Y(), v.Z());
	Matrix rot = Matrix(IDENTITY);
	Vect newForward = world.get(ROW_0).cross(v);
	rot.set(ROT_ORIENT, newForward, v);
	//rot = Matrix(Setrot)

	//rot.set(ROW_1, v);
	//world.set(ROW_1, v);
	world = scale * rot * Matrix(TRANS, pos);
	//world.set(ROW_1, (v * scale.get(ROW_0).magSqr()));
	pGObj_Axis->SetWorld(world);
}

void Axis::Collision(Plane* p)
{
	AZUL_UNUSED(p);
	DebugMsg::out("\nCollision Axis with Plane");
}

void Axis::Input()
{

}

Axis::~Axis()
{
	//DebugMsg::out("\n\nAxis is being deleted");
	delete pGObj_Axis;
}