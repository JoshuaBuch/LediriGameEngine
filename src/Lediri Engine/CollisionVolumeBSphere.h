#ifndef CollisionVolumeBSphere_H
#define CollisionVolumeBSphere_H

#include "CollisionVolume.h"

class CollisionVolumeAABB;
class CollisionVolumeOBB;

class CollisionVolumeBSphere : public CollisionVolume
{
public:

	CollisionVolumeBSphere();
	CollisionVolumeBSphere(const CollisionVolumeBSphere&) = delete;
	CollisionVolumeBSphere& operator=(const CollisionVolumeBSphere&) = delete;
	virtual ~CollisionVolumeBSphere() { DebugMsg::out("CollisionVolumeBSphere deleted"); }; //base class has to have virtual destructor

	void ComputeData(Model* mod, Matrix& mat);
	bool Intersect(const CollisionVolume& other);
	bool Intersect(const CollisionVolumeBSphere& other);
	bool Intersect(const CollisionVolumeAABB& other);
	bool Intersect(const CollisionVolumeOBB& other);
	bool IntersectAccept(const CollisionVolume& other) const override;
	bool IntersectVisit(const CollisionVolumeBSphere& other) const;
	bool IntersectVisit(const CollisionVolumeAABB& other) const;
	bool IntersectVisit(const CollisionVolumeOBB& other) const;

	const Vect& GetCenter() const;
	float GetRadius() const;

	void DebugView(const Vect& col) const;

	//terrain
	bool IntersectVisit(const Vect vMin, const Vect vMax) const override;

private:
	Vect center;
	float radius;

	Vect tmpForward = Vect(0, 0, 1, 0);
};
#endif // !CollisionVolumeBSphere_H
