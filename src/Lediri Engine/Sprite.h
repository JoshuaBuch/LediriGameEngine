#ifndef Sprite_H
#define Sprite_H

#include "DrawObject.h"
#include "UpdateObject.h"

class Matrix;
class Image;

class Sprite : public Align16
{
public:
	Sprite(Image* image, Matrix scale, Matrix rotZ, float transX, float transY);
	Sprite(Image* image);
	Sprite();
	Sprite(const Sprite&) = delete;
	Sprite& operator=(const Sprite&) = delete;
	virtual ~Sprite();

	void Render(Camera* c);
	virtual void Update() {};
	void SetScale(float x, float y, float z);
	void SetScaleByPixel(float w, float h);
	void SetRotZ(const float r);
	void SetTrans(const float x, const float y);
	void SetOrigin(float x, float y);
	Matrix& GetWorld();
	void SetWorld(Matrix w);

protected:
	GraphicsObject_Sprite * pGraphicsObj_Sprite;
	Model* pModelDefault;
	ShaderObject* pDefaultSpriteShader;

private:

	Matrix Scale;
	Matrix RotZ;
	Matrix Trans;
	Matrix World = Matrix(IDENTITY);


	float width;
	float height;

	Rect* rect;
};
#endif //Sprite_H
