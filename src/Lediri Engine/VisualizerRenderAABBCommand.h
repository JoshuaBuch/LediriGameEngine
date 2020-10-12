#ifndef VisualizerRenderAABBCommand_H
#define VisualizerRenderAABBCommand_H

#include "CommandBase.h"

#include "CollisionVolumeAABB.h"

class VisualizerRenderAABBCommand : public CommandBase, public Align16
{
public:
	VisualizerRenderAABBCommand(const Matrix& mat, const Vect& col);
	VisualizerRenderAABBCommand(const VisualizerRenderAABBCommand&) = delete;
	VisualizerRenderAABBCommand& operator=(const VisualizerRenderAABBCommand&) = delete;
	~VisualizerRenderAABBCommand(); //base class has to have virtual destructor

	void execute();
private:
	Matrix world;
	Vect color;
};

#endif // !VisualizerRenderAABBCommand_H
