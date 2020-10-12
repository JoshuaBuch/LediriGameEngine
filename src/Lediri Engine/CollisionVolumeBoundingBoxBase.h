#ifndef CollisionVolumeBoundingBoxBase_H
#define CollisionVolumeBoundingBoxBase_H

#include "CollisionVolume.h"

class CollisionVolumeBoundingBoxBase : public CollisionVolume
{
public:
	CollisionVolumeBoundingBoxBase() = default;
	CollisionVolumeBoundingBoxBase(const CollisionVolumeBoundingBoxBase&) = delete;
	CollisionVolumeBoundingBoxBase& operator=(const CollisionVolumeBoundingBoxBase&) = delete;
	virtual ~CollisionVolumeBoundingBoxBase() { DebugMsg::out("CollisionVolumeBoundingBoxBase deleted"); }; //base class has to have virtual destructor

	virtual Matrix getScale() const;
	virtual float getScaleFactorSquared() const;
	virtual Matrix getTranslation() const;
	virtual Matrix getWorldTransform() const;
	virtual Vect getCenter() const;
	virtual Vect getHalfDiagonal() const;
	virtual Vect getMin() const;
	virtual Vect getMax() const;

protected:

	Vect min;
	Vect max;
	Vect halfDiagonal;
	Vect center;
	float scaleSquared;

	int i;
	Matrix scale;
	Matrix translation;
	Matrix worldTransform;
private:


};
#endif // CollisionVolumeBoundingBoxBase_H
