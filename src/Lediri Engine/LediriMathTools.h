#ifndef LediriMathTools_H
#define LediriMathTools_H

#include "DebugOut.h"

class CollisionVolumeBSphere;
class CollisionVolumeAABB;
class CollisionVolumeOBB;
class CollisionObject;
class Vect;

class LediriMathTools
{
public:
	LediriMathTools() = default;
	LediriMathTools(const LediriMathTools&) = delete;
	LediriMathTools& operator=(const LediriMathTools&) = delete;
	~LediriMathTools() { DebugMsg::out("LediriMathTools deleted"); }; //base class has to have virtual destructor

	static bool Intersect(const CollisionObject* c1, const CollisionObject* c2);

	static bool Intersect(const CollisionVolumeBSphere& A, const CollisionVolumeBSphere& B);
	static bool Intersect(const CollisionVolumeBSphere& A, const CollisionVolumeAABB& B);
	static bool Intersect(const CollisionVolumeBSphere& A, const CollisionVolumeOBB& B);

	static bool Intersect(const CollisionVolumeAABB& A, const CollisionVolumeBSphere& B);
	static bool Intersect(const CollisionVolumeAABB& A, const CollisionVolumeAABB& B);
	static bool Intersect(const CollisionVolumeAABB& A, const CollisionVolumeOBB& B);
	
	static bool Intersect(const CollisionVolumeOBB& A, const CollisionVolumeBSphere& B);
	static bool Intersect(const CollisionVolumeOBB& A, const CollisionVolumeAABB& B);
	static bool Intersect(const CollisionVolumeOBB& A, const CollisionVolumeOBB& B);

	//Terrain collision test
	static bool Intersect(const CollisionVolumeBSphere& A, const Vect min, const Vect max);
	static bool Intersect(const CollisionVolumeOBB& A, const Vect min, const Vect max);
	static bool Intersect(const CollisionVolumeAABB& A, const Vect min, const Vect max);
	static bool Intersect(const CollisionObject* c1, const Vect min, const Vect max);

private:

	//static bool AxisOverlap(float a, float b);
	static float ClampTest(float a, float b, float c);
	static bool PointInSphere(const Vect& c, const Vect& p, float r);

	static float ProjectionVectWOntoVectV(const Vect& W, const Vect& V);
};

#endif // !LediriMathTools_H
