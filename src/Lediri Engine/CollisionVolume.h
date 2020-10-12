#ifndef CollisionVolume_H
#define CollisionVolume_H

#include "DebugOut.h"
#include "Align16.h"
#include "MathApp.h"

class Matrix;
class Model;
class CollisionVolumeBSphere;
class CollisionVolumeAABB;
class CollisionVolumeOBB;
class Vect;

class CollisionVolume : public Align16
{
public:

	CollisionVolume() = default;
	CollisionVolume(const CollisionVolume&) = delete;
	CollisionVolume& operator=(const CollisionVolume&) = delete;
	virtual ~CollisionVolume() { DebugMsg::out("CollisionVolume deleted"); }; //base class has to have virtual destructor

	virtual void DebugView(const Vect& col) const = 0;
	virtual void ComputeData(Model* mod, Matrix& mat) =0;
	virtual bool Intersect(const CollisionVolume& other) =0;
	virtual bool Intersect(const CollisionVolumeBSphere& other) =0;
	virtual bool Intersect(const CollisionVolumeAABB& other) = 0;
	virtual bool Intersect(const CollisionVolumeOBB& other) = 0;
	virtual bool IntersectAccept(const CollisionVolume& other) const = 0;
	virtual bool IntersectVisit(const CollisionVolumeBSphere& other) const =0;
	virtual bool IntersectVisit(const CollisionVolumeAABB& other) const = 0;
	virtual bool IntersectVisit(const CollisionVolumeOBB& other) const = 0;

	//terrain
	virtual bool IntersectVisit(const Vect min, const Vect max) const = 0;


private:

};

#endif