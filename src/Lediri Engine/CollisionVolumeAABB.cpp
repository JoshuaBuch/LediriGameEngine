#include "CollisionVolumeAABB.h"
#include "Matrix.h"
#include "Model.h"
#include "LediriMathTools.h"
#include "Visualizer.h"
#include "CollisionVolumeBSphere.h"

CollisionVolumeAABB::CollisionVolumeAABB()
{

}

void CollisionVolumeAABB::ComputeData(Model* mod, Matrix& mat)
{
	worldTransform = mat;

	Vect* vectList = mod->getVectList();
	
	max = vectList[0] * mat;
	min = vectList[0] * mat;
	for (i = 0; i < mod->getVectNum(); i++)
	{
		Vect tmp = vectList[i] * mat;
		if (tmp.X() > max.X())
		{
			max.X() = tmp.X();
		}
		if (tmp.X() < min.X())
		{
			min.X() = tmp.X();
		}

		if (tmp.Y() > max.Y())
		{
			max.Y() = tmp.Y();
		}
		if (tmp.Y() < min.Y())
		{
			min.Y() = tmp.Y();
		}

		if (tmp.Z() > max.Z())
		{
			max.Z() = tmp.Z();
		}
		if (tmp.Z() < min.Z())
		{
			min.Z() = tmp.Z();
		}
	}


	center = (max + min) * .5f;
	halfDiagonal = max - center;

	//Visualizer::ShowAABB(min, max);

	scaleSquared = mat.get(ROW_0).magSqr();
	//Vect scaledMin = min * scaleSquared;
	//Vect scaledMax = max * scaleSquared;
	//Visualizer::ShowAABB(scaledMin, scaledMax);

	scale = Matrix(SCALE, max - min);

	translation = Matrix(TRANS, 0.5 * (min + max));

}

void CollisionVolumeAABB::ComputeData(const CollisionVolumeBSphere& bsphere)
{

	curBSCenter = bsphere.GetCenter();
	curBSCenter.W() = 0.0f;
	float radius = bsphere.GetRadius();
	radius;

	if (max.X() < curBSCenter.X() + radius)
	{
		max.X() = curBSCenter.X() + radius;
	}
	if (min.X() > curBSCenter.X() - radius)
	{
		min.X() = curBSCenter.X() - radius;
	}
	if (max.Y() < curBSCenter.Y() + radius)
	{
		max.Y() = curBSCenter.Y() + radius;
	}
	if (min.Y() > curBSCenter.Y() - radius)
	{
		min.Y() = curBSCenter.Y() - radius;
	}
	if (max.Z() < curBSCenter.Z() + radius)
	{
		max.Z() = curBSCenter.Z() + radius;
	}
	if (min.Z() > curBSCenter.Z() - radius)
	{
		min.Z() = curBSCenter.Z() - radius;
	}
	//max.X() = bsphere.GetCenter().X() + bsphere.GetRadius();
	//min.X() = bsphere.GetCenter().X() - bsphere.GetRadius();
	//max.Y() = bsphere.GetCenter().Y() + bsphere.GetRadius();
	//min.Y() = bsphere.GetCenter().Y() - bsphere.GetRadius();
	//max.Z() = bsphere.GetCenter().Z() + bsphere.GetRadius();
	//min.Z() = bsphere.GetCenter().Z() - bsphere.GetRadius();


	halfDiagonal = (max - min) * 0.5f;
	center = (min + halfDiagonal);
	
	scaleSquared = worldTransform.get(ROW_0).magSqr();

	scale = Matrix(SCALE, max - min);
	translation = Matrix(TRANS, 0.5f * (min + max));

}

void CollisionVolumeAABB::SetMaxMin(const CollisionVolumeBSphere& bsphere)
{
	max = bsphere.GetCenter();
	min = bsphere.GetCenter();
}

bool CollisionVolumeAABB::Intersect(const CollisionVolume & other)
{
	other;
	return true;
}

bool CollisionVolumeAABB::Intersect(const CollisionVolumeAABB & other)
{
	other;
	return true;
}

bool CollisionVolumeAABB::Intersect(const CollisionVolumeBSphere & other)
{
	other;
	return true;
}

bool CollisionVolumeAABB::Intersect(const CollisionVolumeOBB & other)
{
	other;
	return false;
}

bool CollisionVolumeAABB::IntersectAccept(const CollisionVolume & other) const
{
	return other.IntersectVisit(*this);
}

bool CollisionVolumeAABB::IntersectVisit(const CollisionVolumeBSphere & other) const
{
	return LediriMathTools::Intersect(*this, other);
}

bool CollisionVolumeAABB::IntersectVisit(const CollisionVolumeAABB & other) const
{
	return LediriMathTools::Intersect(*this, other);
}

bool CollisionVolumeAABB::IntersectVisit(const CollisionVolumeOBB & other) const
{
	return LediriMathTools::Intersect(*this, other);
}

bool CollisionVolumeAABB::IntersectVisit(const Vect vMin, const Vect vMax) const
{
	return LediriMathTools::Intersect(*this, vMin, vMax);
}

void CollisionVolumeAABB::DebugView(const Vect & col) const
{
	Visualizer::ShowAABB(*this, col);
}
