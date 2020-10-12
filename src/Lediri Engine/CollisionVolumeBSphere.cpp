#include "CollisionVolumeBSphere.h"
#include "Matrix.h"
#include "Model.h"
#include "LediriMathTools.h"
#include "Visualizer.h"

CollisionVolumeBSphere::CollisionVolumeBSphere()
{

}

void CollisionVolumeBSphere::ComputeData(Model* mod, Matrix& mat)
{
	center = mod->getCenter() * mat;
	tmpForward = Vect(0, 0, 1, 0) * mat;
	radius = mod->getRadius() * tmpForward.mag();
}

const Vect& CollisionVolumeBSphere::GetCenter() const
{
	return center;
}

float CollisionVolumeBSphere::GetRadius() const
{
	return radius;
}

void CollisionVolumeBSphere::DebugView(const Vect & col) const
{
	Visualizer::ShowBSphere(*this, col);
}

bool CollisionVolumeBSphere::Intersect(const CollisionVolume& other)
{
	other;
	return true;
}

bool CollisionVolumeBSphere::Intersect(const CollisionVolumeBSphere& other)
{
	other;
	return true;
}

bool CollisionVolumeBSphere::Intersect(const CollisionVolumeAABB & other)
{
	other;
	return false;
}

bool CollisionVolumeBSphere::Intersect(const CollisionVolumeOBB & other)
{
	other;
	return false;
}

bool CollisionVolumeBSphere::IntersectAccept(const CollisionVolume & other) const
{
	return other.IntersectVisit(*this);
}

bool CollisionVolumeBSphere::IntersectVisit(const CollisionVolumeBSphere & other) const
{
	return LediriMathTools::Intersect(*this, other);
}

bool CollisionVolumeBSphere::IntersectVisit(const CollisionVolumeAABB & other) const
{
	return LediriMathTools::Intersect(*this, other);
}

bool CollisionVolumeBSphere::IntersectVisit(const CollisionVolumeOBB & other) const
{
	return LediriMathTools::Intersect(*this, other);
}

bool CollisionVolumeBSphere::IntersectVisit(const Vect vMin, const Vect vMax) const
{
	return LediriMathTools::Intersect(*this, vMin, vMax);
}