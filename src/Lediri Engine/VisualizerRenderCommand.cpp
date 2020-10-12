#include "VisualizerRenderCommand.h"
#include "Visualizer.h"

VisualizerRenderCommand::VisualizerRenderCommand(const Matrix& mat, const Vect& col)
{
	world = mat;
	color = col;
}



void VisualizerRenderCommand::execute()
{
	Visualizer::RenderBSphere(world, color);
	delete this;
}

VisualizerRenderCommand::~VisualizerRenderCommand()
{
	//DebugMsg::out("\nVisualizerRenderCommand deleted");
}