#ifndef VisualizerRenderCommand_H
#define VisualizerRenderCommand_H

#include "CommandBase.h"

#include "CollisionVolumeBSphere.h"

class VisualizerRenderCommand : public CommandBase, public Align16
{
public:
	VisualizerRenderCommand(const Matrix& mat, const Vect& col);
	VisualizerRenderCommand(const VisualizerRenderCommand&) = delete;
	VisualizerRenderCommand& operator=(const VisualizerRenderCommand&) = delete;
	~VisualizerRenderCommand(); //base class has to have virtual destructor

	void execute();
private:
	Matrix world;
	Vect color;
};
#endif // !VisualizerRenderCommand_H
