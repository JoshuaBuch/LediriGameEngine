#include "Visualizer.h"
#include "Color.h"
#include "SceneManager.h"
#include "CollisionVolumeBSphere.h"
#include "CollisionVolumeAABB.h"
#include "CollisionVolumeOBB.h"
#include "ModelManager.h"
#include "ShaderManager.h"
#include "VisualizerRenderCommand.h"
#include "VisualizerRenderAABBCommand.h"
#include "Scene.h"
#include "CollisionObject.h"

Visualizer* Visualizer::ptrInstance = nullptr;
Vect Visualizer::DEFAULT_COLOR = Color::Blue;

Visualizer::Visualizer()
{
	WFUnitSphere = new GraphicsObject_WireframeConstantColor(ModelManager::getModel("UnitSphere"), ShaderManager::getShader("ShaderObject_constantColor"), DEFAULT_COLOR);
	WFUnitBox = new GraphicsObject_WireframeConstantColor(ModelManager::getModel("UnitBox"), ShaderManager::getShader("ShaderObject_constantColor"), DEFAULT_COLOR);
}

void Visualizer::privShowBSphere(const CollisionVolumeBSphere& S, const Vect& col)
{
	Vect vBSSize = S.GetRadius() * Vect(1, 1, 1);
	Vect vBSPos = S.GetCenter();

	Matrix worldBS = Matrix(SCALE, vBSSize) * Matrix(TRANS, vBSPos);


	//Create command that will execute RenderXVolumeType
	SceneManager::getCurScene()->SubmitVisualizerCommand(new VisualizerRenderCommand(worldBS, col));
	
}

void Visualizer::privShowAABB(const CollisionVolumeAABB& V, const Vect& col)
{
	Matrix scale = V.getScale();
	//scale = scale * 3.0f;
	Matrix translation = V.getTranslation();

	Matrix worldBB = scale * translation;

	SceneManager::getCurScene()->SubmitVisualizerCommand(new VisualizerRenderAABBCommand(worldBB, col));
}

void Visualizer::privShowAABB(const Vect& min, const Vect& max, const Vect& col)
{
	//halfDiagonal = ((mod->getMaxAABB() - mod->getMinAABB()) * 0.5);
	//center = (min + halfDiagonal);

	//scaleSquared = mat.get(ROW_0).magSqr();

	Matrix scale = Matrix(SCALE, max - min);
	Matrix translation = Matrix(TRANS, 0.5 * (min + max));

	Matrix worldBB = scale * translation;

	SceneManager::getCurScene()->SubmitVisualizerCommand(new VisualizerRenderAABBCommand(worldBB, col));
}

void Visualizer::privShowOBB(const CollisionVolumeOBB & V, const Vect & col)
{
	Matrix scale = V.getScale();
	Matrix translation = V.getTranslation();
	Matrix worldBB = scale * translation;
	worldBB = worldBB * V.getWorldTransform();

	SceneManager::getCurScene()->SubmitVisualizerCommand(new VisualizerRenderAABBCommand(worldBB, col));
}

void Visualizer::privShowCollisionVolume(const CollisionObject* c, const Vect& col)
{
	c->GetCollisionVolume().DebugView(col);

	//c->GetCollisionSphere().DebugView(col);
}

//Called by the visualizer commands
void Visualizer::privRenderBSphere(Matrix& S, const Vect& col)
{
	WFUnitSphere->SetWorld(S);
	WFUnitSphere->SetColor(col);
	WFUnitSphere->Render(SceneManager::getCurScene()->GetCurCam());
}

void Visualizer::privRenderAABB(Matrix& S, const Vect& col)
{
	WFUnitBox->SetWorld(S);
	WFUnitBox->SetColor(col);
	WFUnitBox->Render(SceneManager::getCurScene()->GetCurCam());
}

/*
void Visualizer::privRenderLine(Matrix& S, const Vect& col)
{
	create a thin box and ROTATE the box in the direction of the end point
	need to work on how to rotate an object towards a desired point

	try getting the directional vector of end-start and set the forward vector of a rotational matrix to that direction
	then it should be world *= newRotationMatrix and the AABB's forward will be facing toward the end point.
}
*/

void Visualizer::privDrawLine(const Vect& start, const Vect& end, const Vect& col)
{
	Matrix scale = Matrix(SCALE, end - start);
	Matrix translation = Matrix(TRANS, 0.5 * (start + end));

	Matrix worldBB = scale * translation;
	
	SceneManager::getCurScene()->SubmitVisualizerCommand(new VisualizerRenderAABBCommand(worldBB, col));
}

//void Visualizer::privRenderOBB(Matrix & S, const Vect & col)
//{
//	WFUnitBox->SetWorld(S);
//	WFUnitBox->pWireColor->set(col);
//	WFUnitBox->Render(SceneManager::getCurScene()->GetCurCam());
//}

void Visualizer::privDeleteVisualizer()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}

Visualizer::~Visualizer()
{
	delete WFUnitSphere;
	delete WFUnitBox;
}
