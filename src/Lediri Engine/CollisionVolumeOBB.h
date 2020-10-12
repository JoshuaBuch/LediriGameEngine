#ifndef CollisionVolumeOBB_H
#define CollisionVolumeOBB_H

#include "CollisionVolumeBoundingBoxBase.h"

class CollisionVolumeBSphere;
class CollisionVolumeAABB;

class CollisionVolumeOBB : public CollisionVolumeBoundingBoxBase
{
public:
	CollisionVolumeOBB();
	CollisionVolumeOBB(const CollisionVolumeOBB&) = delete;
	CollisionVolumeOBB& operator=(const CollisionVolumeOBB&) = delete;
	virtual ~CollisionVolumeOBB() { DebugMsg::out("CollisionVolumeOBB deleted"); };

	void ComputeData(Model* mod, Matrix& mat);
	bool Intersect(const CollisionVolume& other);
	bool Intersect(const CollisionVolumeAABB& other);
	bool Intersect(const CollisionVolumeOBB& other);
	bool Intersect(const CollisionVolumeBSphere& other);
	bool IntersectAccept(const CollisionVolume& other) const override;
	bool IntersectVisit(const CollisionVolumeBSphere& other) const;
	bool IntersectVisit(const CollisionVolumeAABB& other) const;
	bool IntersectVisit(const CollisionVolumeOBB& other) const;

	void DebugView(const Vect& col) const;

	//terrain
	bool IntersectVisit(const Vect vMin, const Vect vMax) const override;

private:

};

#endif // !CollisionVolumeOBB_H
