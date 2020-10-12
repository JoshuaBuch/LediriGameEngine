#include "CollisionVolumeBoundingBoxBase.h"

Matrix CollisionVolumeBoundingBoxBase::getScale() const
{
	return scale;
}

float CollisionVolumeBoundingBoxBase::getScaleFactorSquared() const
{
	return scaleSquared;
}

Matrix CollisionVolumeBoundingBoxBase::getTranslation() const
{
	return translation;
}

Matrix CollisionVolumeBoundingBoxBase::getWorldTransform() const
{
	return worldTransform;
}

Vect CollisionVolumeBoundingBoxBase::getCenter() const
{
	return center;
}

Vect CollisionVolumeBoundingBoxBase::getHalfDiagonal() const
{
	return halfDiagonal;
}

Vect CollisionVolumeBoundingBoxBase::getMin() const
{
	return min;
}

Vect CollisionVolumeBoundingBoxBase::getMax() const
{
	return max;
}
