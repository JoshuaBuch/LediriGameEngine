#include "CollisionVolumeOBB.h"
#include "Matrix.h"
#include "Model.h"
#include "LediriMathTools.h"
#include "Visualizer.h"

CollisionVolumeOBB::CollisionVolumeOBB()
{

}

void CollisionVolumeOBB::ComputeData(Model * mod, Matrix & mat)
{
	worldTransform = mat;
	min = mod->getMinAABB();
	max = mod->getMaxAABB();

	halfDiagonal = (max - min) * 0.5f;
	center = (min + halfDiagonal) * worldTransform;

	scaleSquared = mat.get(ROW_0).magSqr();

	scale = Matrix(SCALE, max - min);

	translation = Matrix(TRANS, 0.5 * (min + max));
}

bool CollisionVolumeOBB::Intersect(const CollisionVolume & other)
{
	other;
	return false;
}

bool CollisionVolumeOBB::Intersect(const CollisionVolumeAABB & other)
{
	other;
	return false;
}

bool CollisionVolumeOBB::Intersect(const CollisionVolumeOBB & other)
{
	other;
	return false;
}

bool CollisionVolumeOBB::Intersect(const CollisionVolumeBSphere & other)
{
	other;
	return false;
}

bool CollisionVolumeOBB::IntersectAccept(const CollisionVolume & other) const
{
	return other.IntersectVisit(*this);
}

bool CollisionVolumeOBB::IntersectVisit(const CollisionVolumeBSphere & other) const
{
	return LediriMathTools::Intersect(*this, other);
}

bool CollisionVolumeOBB::IntersectVisit(const CollisionVolumeAABB & other) const
{
	return LediriMathTools::Intersect(*this, other);
}

bool CollisionVolumeOBB::IntersectVisit(const CollisionVolumeOBB & other) const
{
	return LediriMathTools::Intersect(*this, other);
}

bool CollisionVolumeOBB::IntersectVisit(const Vect vMin, const Vect vMax) const
{
	return LediriMathTools::Intersect(*this, vMin, vMax);
}

void CollisionVolumeOBB::DebugView(const Vect & col) const
{
	Visualizer::ShowOBB(*this, col);
}


