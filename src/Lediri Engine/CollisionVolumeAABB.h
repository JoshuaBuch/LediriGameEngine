#ifndef CollisionVolumeAABB_H
#define CollisionVolumeAABB_H

#include "CollisionVolumeBoundingBoxBase.h"

class CollisionVolumeBSphere;
class CollisionVolumeOBB;
class Vect;

class CollisionVolumeAABB : public CollisionVolumeBoundingBoxBase
{
public:
	CollisionVolumeAABB();
	CollisionVolumeAABB(const CollisionVolumeAABB&) = default;
	CollisionVolumeAABB& operator=(const CollisionVolumeAABB&) = default;
	virtual ~CollisionVolumeAABB() { DebugMsg::out("CollisionVolumeAABB deleted"); }; //base class has to have virtual destructor

	void ComputeData(Model* mod, Matrix& mat);
	void ComputeData(const CollisionVolumeBSphere& bsphere);
	void SetMaxMin(const CollisionVolumeBSphere& bsphere);
	bool Intersect(const CollisionVolume& other);
	bool Intersect(const CollisionVolumeAABB& other);
	bool Intersect(const CollisionVolumeBSphere& other);
	bool Intersect(const CollisionVolumeOBB& other);
	bool IntersectAccept(const CollisionVolume& other) const override;
	bool IntersectVisit(const CollisionVolumeBSphere& other) const;
	bool IntersectVisit(const CollisionVolumeAABB& other) const;
	bool IntersectVisit(const CollisionVolumeOBB& other) const;

	void DebugView(const Vect& col) const;

	//terrain collision
	bool IntersectVisit(const Vect vMin, const Vect vMax) const override;
private:

	//float xMin, yMin, zMin;
	//float xMax, yMax, zMax;
	Vect curBSCenter;

};
#endif // !1
