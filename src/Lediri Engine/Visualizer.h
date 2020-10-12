#ifndef Visualizer_H
#define Visualizer_H

#include "AzulCore.h"
#include "Model.h"

class CollisionVolumeBSphere;
class CollisionVolumeAABB;
class CollisionVolumeOBB;
class CollisionObject;
class Vect;

class Visualizer : public Align16
{
public:
	static void ShowBSphere(const CollisionVolumeBSphere& S, const Vect& col = DEFAULT_COLOR)
	{
		Instance().privShowBSphere(S, col);
	};

	static void ShowAABB(const CollisionVolumeAABB& V, const Vect& col = DEFAULT_COLOR)
	{
		Instance().privShowAABB(V, col);
	}

	static void ShowAABB(const Vect& min, const Vect& max, const Vect& col = DEFAULT_COLOR)
	{
		Instance().privShowAABB(min, max, col);
	}

	static void ShowOBB(const CollisionVolumeOBB& V, const Vect& col = DEFAULT_COLOR)
	{
		Instance().privShowOBB(V, col);
	}

	static void ShowCollisionVolume(const CollisionObject* c, const Vect& col = DEFAULT_COLOR)
	{
		Instance().privShowCollisionVolume(c, col);
	};

	static void DrawLine(const Vect& start, const Vect& end, const Vect& col = DEFAULT_COLOR)
	{
		Instance().privDrawLine(start, end, col);
	}

	static void RenderBSphere(Matrix& S, const Vect& col) { Instance().privRenderBSphere(S, col); };
	static void RenderAABB(Matrix& S, const Vect& col) { Instance().privRenderAABB(S, col); };
	//static void RenderOBB(Matrix& S, const Vect& col) { Instance().privRenderOBB(S, col); };
	static void DeleteVisualizer() { Instance().privDeleteVisualizer(); };
private:

	Visualizer();
	Visualizer(const Visualizer&) = delete;
	Visualizer& operator=(const Visualizer&) = delete;
	~Visualizer();

	static Visualizer* ptrInstance;

	static Visualizer& Instance()
	{
		if (!ptrInstance)
		{
			ptrInstance = new Visualizer;
		}
		return *ptrInstance;
	}

	static Vect DEFAULT_COLOR;

	GraphicsObject_WireframeConstantColor* WFUnitSphere;
	GraphicsObject_WireframeConstantColor* WFUnitBox;

	void privShowBSphere(const CollisionVolumeBSphere& S, const Vect& col = DEFAULT_COLOR);
	void privShowAABB(const CollisionVolumeAABB& V, const Vect& col = DEFAULT_COLOR);	
	void privShowAABB(const Vect& min, const Vect& max, const Vect& col = DEFAULT_COLOR);
	void privShowOBB(const CollisionVolumeOBB& V, const Vect& col = DEFAULT_COLOR);
	void privShowCollisionVolume(const CollisionObject* c, const Vect& col = DEFAULT_COLOR);
	void privRenderBSphere(Matrix& S, const Vect& col);
	void privRenderAABB(Matrix& S, const Vect& col);
	//void privRenderOBB(Matrix& S, const Vect& col);
	void privDrawLine(const Vect& start, const Vect& end, const Vect& col = DEFAULT_COLOR);

	void privDeleteVisualizer();
};
#endif // !Visualizer_H
