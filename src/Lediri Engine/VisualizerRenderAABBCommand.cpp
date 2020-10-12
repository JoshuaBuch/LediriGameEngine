#include "VisualizerRenderAABBCommand.h"
#include "Visualizer.h"

VisualizerRenderAABBCommand::VisualizerRenderAABBCommand(const Matrix & mat, const Vect & col)
{
	world = mat;
	color = col;
}

void VisualizerRenderAABBCommand::execute()
{
	Visualizer::RenderAABB(world, color);
	delete this;
}

VisualizerRenderAABBCommand::~VisualizerRenderAABBCommand()
{
}


