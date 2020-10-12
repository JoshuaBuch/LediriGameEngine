#include "Sprite.h"
#include "ModelManager.h"
#include "ShaderManager.h"
#include "Lediri.h"

Sprite::Sprite(Image * image, Matrix scale, Matrix rotZ, float transX, float transY)
{
	pModelDefault = ModelManager::getModel("UnitSquareXY");
	pDefaultSpriteShader = ShaderManager::getShader("SpriteRender");
	Scale = scale;
	RotZ = rotZ;
	Trans.set(TRANS, transX, transY, 0.0);
	World = Scale * RotZ * Trans;
	rect = new Rect(150.0f, 500.0f, 100.0f, 100.0f);
	pGraphicsObj_Sprite = new GraphicsObject_Sprite(pModelDefault, pDefaultSpriteShader, image, rect);
	pGraphicsObj_Sprite->SetWorld(World);
}

Sprite::Sprite(Image* image)
{

	pModelDefault = ModelManager::getModel("UnitSquareXY");
	pDefaultSpriteShader = ShaderManager::getShader("SpriteRender");
	rect = new Rect(150.0f, 500.0f, 100.0f, 100.0f);
	pGraphicsObj_Sprite = new GraphicsObject_Sprite(pModelDefault, pDefaultSpriteShader, image, rect);

	pGraphicsObj_Sprite->SetWorld(World);
}

Sprite::Sprite()
{
	//pModelDefault = ModelManager::getModel("UnitSquareXY");
	//pDefaultSpriteShader = ShaderManager::getShader("SpriteRender");
	//Scale = Matrix(SCALE, 1.0f, 1.0f, 1.0f);
	//RotZ = Matrix(ROT_Z, 0.0f);
	//Trans = Matrix(TRANS, 0.0f, 0.0f, 0.0f);
	//World = Scale * RotZ * Trans;
}

void Sprite::SetScale(float x, float y, float z)
{
	Scale.set(SCALE, x, y, z);
	World = Scale * RotZ * Trans;
}

//This is radians
void Sprite::SetRotZ(const float r)
{
	RotZ.set(ROT_Z, r);
	//World = Trans * RotZ * Scale;
	World = Scale * RotZ * Trans;
	pGraphicsObj_Sprite->SetWorld(this->GetWorld());
}

void Sprite::SetTrans(const float x, const float y)
{
	Trans.set(TRANS, x, y, 0.0);
	World = Scale * RotZ * Trans;
	pGraphicsObj_Sprite->SetWorld(this->GetWorld());
}

void Sprite::SetOrigin(float x, float y)
{
	//pGraphicsObj_Sprite->set(ROW_3, Vect(x, y, 0, 1));
	pGraphicsObj_Sprite->SetWorld(World);
	y;
	x;
}

void Sprite::Render(Camera* cam)
{
	pGraphicsObj_Sprite->Render(cam);
}

void Sprite::SetWorld(Matrix w)
{
	World = w;
	pGraphicsObj_Sprite->SetWorld(this->GetWorld());
}

Matrix& Sprite::GetWorld()
{
	return this->World;
}

void Sprite::SetScaleByPixel(float w, float h)
{
	width = w;
	height = h;
	//pGraphicsObj_Sprite->pMatrix_orig->set(ROW_0, Vect(width, 0, 0, 0));
	//pGraphicsObj_Sprite->pMatrix_orig->set(ROW_1, Vect(0, height, 0, 0));
}

Sprite::~Sprite()
{
	delete pGraphicsObj_Sprite;
	delete rect;
	DebugMsg::out("Sprite base class being deleted");
}