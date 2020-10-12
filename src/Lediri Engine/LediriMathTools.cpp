#include "LediriMathTools.h"
#include "CollisionVolumeBSphere.h"
#include "CollisionVolumeAABB.h"
#include "CollisionVolumeOBB.h"
#include "CollisionObject.h"


bool LediriMathTools::Intersect(const CollisionVolumeBSphere& A, const CollisionVolumeBSphere& B)
{
	return (A.GetCenter() - B.GetCenter()).dot(A.GetCenter() - B.GetCenter()) < (A.GetRadius() + B.GetRadius()) * (A.GetRadius() + B.GetRadius());
}

bool LediriMathTools::Intersect(const CollisionVolumeBSphere& A, const CollisionVolumeAABB& B)
{
	Vect sphereCenter = A.GetCenter();
	Vect min = B.getMin();
	Vect max = B.getMax();
	Vect clampPoint;

	clampPoint.X() = ClampTest(min.X(), max.X(), sphereCenter.X());
	clampPoint.Y() = ClampTest(min.Y(), max.Y(), sphereCenter.Y());
	clampPoint.Z() = ClampTest(min.Z(), max.Z(), sphereCenter.Z());
	

	return PointInSphere(clampPoint, sphereCenter, A.GetRadius());
}

bool LediriMathTools::Intersect(const CollisionVolumeAABB & A, const CollisionVolumeBSphere & B)
{
	Vect sphereCenter = B.GetCenter();
	Vect min = A.getMin();
	Vect max = A.getMax();
	Vect clampPoint;

	clampPoint.X() = ClampTest(min.X(), max.X(), sphereCenter.X());
	clampPoint.Y() = ClampTest(min.Y(), max.Y(), sphereCenter.Y());
	clampPoint.Z() = ClampTest(min.Z(), max.Z(), sphereCenter.Z());

	return PointInSphere(clampPoint, sphereCenter, B.GetRadius());
}

//terrain AABB tests
bool LediriMathTools::Intersect(const CollisionVolumeBSphere& A, const Vect min, const Vect max)
{
	Vect sphereCenter = A.GetCenter();
	Vect clampPoint;

	clampPoint.X() = ClampTest(min.X(), max.X(), sphereCenter.X());
	clampPoint.Y() = ClampTest(min.Y(), max.Y(), sphereCenter.Y());
	clampPoint.Z() = ClampTest(min.Z(), max.Z(), sphereCenter.Z());

	return PointInSphere(clampPoint, sphereCenter, A.GetRadius());
}

bool LediriMathTools::Intersect(const CollisionVolumeOBB & A, const CollisionVolumeBSphere & B)
{
	Matrix OBBInverse = A.getWorldTransform().getInv();
	Vect sphereCenter = B.GetCenter();
	sphereCenter *= OBBInverse;

	Vect min = A.getMin();
	Vect max = A.getMax();
	Vect clampPoint;

	clampPoint.X() = ClampTest(min.X(), max.X(), sphereCenter.X());
	clampPoint.Y() = ClampTest(min.Y(), max.Y(), sphereCenter.Y());
	clampPoint.Z() = ClampTest(min.Z(), max.Z(), sphereCenter.Z());

	return PointInSphere(clampPoint, sphereCenter, B.GetRadius());
}

bool LediriMathTools::Intersect(const CollisionVolumeBSphere & A, const CollisionVolumeOBB & B)
{
	Matrix OBBInverse = B.getWorldTransform().getInv();
	Vect sphereCenter = A.GetCenter();
	sphereCenter *= OBBInverse;

	Vect min = B.getMin();
	Vect max = B.getMax();
	Vect clampPoint;

	clampPoint.X() = ClampTest(min.X(), max.X(), sphereCenter.X());
	clampPoint.Y() = ClampTest(min.Y(), max.Y(), sphereCenter.Y());
	clampPoint.Z() = ClampTest(min.Z(), max.Z(), sphereCenter.Z());

	return PointInSphere(sphereCenter, clampPoint, A.GetRadius());
}

bool LediriMathTools::Intersect(const CollisionVolumeOBB & A, const CollisionVolumeAABB & B)
{
	Matrix AWorld = A.getWorldTransform();
	Matrix BWorld = B.getWorldTransform();

	Vect vectList[15];
	vectList[0] = AWorld.get(ROW_0);
	vectList[1] = AWorld.get(ROW_1);
	vectList[2] = AWorld.get(ROW_2);
	vectList[3] = BWorld.get(ROW_0);
	vectList[4] = BWorld.get(ROW_1);
	vectList[5] = BWorld.get(ROW_2);

	int n = 5;
	for (int i = 0; i < 3; i++)
	{

		vectList[++n] = vectList[i].cross(vectList[3]);
		vectList[++n] = vectList[i].cross(vectList[4]);
		vectList[++n] = vectList[i].cross(vectList[5]);

	}

	Matrix AWInv = A.getWorldTransform().getInv();
	Matrix BWInv = B.getWorldTransform().getInv();

	Vect C1 = A.getCenter();
	Vect C2 = B.getCenter();

	Vect r1 = A.getHalfDiagonal();
	Vect r2 = B.getHalfDiagonal();

	for (int i = 0; i < 15; i++)
	{
		//Calculate Projection 1
		Vect vectInverse = vectList[i] * AWInv;
		float Proj1Max = (abs(vectInverse.X() * r1.X()) + abs(vectInverse.Y() * r1.Y()) + abs(vectInverse.Z() * r1.Z())) / vectList[i].mag();
		Proj1Max *= A.getScaleFactorSquared();

		//Calculate Projection 2
		vectInverse = vectList[i] * BWInv;
		float Proj2Max = (abs(vectInverse.X() * r2.X()) + abs(vectInverse.Y() * r2.Y()) + abs(vectInverse.Z() * r2.Z())) / vectList[i].mag();
		Proj2Max *= B.getScaleFactorSquared();

		//Calculate the projection of the distance between both centers
		float D = abs((C2 - C1).dot(vectList[i])) / vectList[i].mag();

		//Comparethe projected distance between the sum of the projected half diagonals
		if (D > Proj1Max + Proj2Max)
		{
			return false;
		}
	}

	return true;
}

bool LediriMathTools::Intersect(const CollisionVolumeOBB& A, const Vect min, const Vect max)
{
	Matrix AWorld = A.getWorldTransform();
	//Matrix BWorld = B.getWorldTransform();

	Vect halfDiagonal = ((max - min) * 0.5);
	Vect center = (min + halfDiagonal);

	float scaleSquared = 1.0f; // mat.get(ROW_0).magSqr();

	Matrix scale = Matrix(SCALE, max - min);
	Matrix translation = Matrix(TRANS, 0.5 * (min + max));

	Matrix BWorld = scale * translation;


	Vect vectList[15];
	vectList[0] = AWorld.get(ROW_0);
	vectList[1] = AWorld.get(ROW_1);
	vectList[2] = AWorld.get(ROW_2);
	vectList[3] = BWorld.get(ROW_0);
	vectList[4] = BWorld.get(ROW_1);
	vectList[5] = BWorld.get(ROW_2);

	int n = 5;
	for (int i = 0; i < 3; i++)
	{

		vectList[++n] = vectList[i].cross(vectList[3]);
		vectList[++n] = vectList[i].cross(vectList[4]);
		vectList[++n] = vectList[i].cross(vectList[5]);

	}

	Matrix AWInv = A.getWorldTransform().getInv();
	Matrix BWInv = BWInv.getInv();//B.getWorldTransform().getInv();

	Vect C1 = A.getCenter();
	Vect C2 = (min + halfDiagonal);//B.getCenter();

	Vect r1 = A.getHalfDiagonal();
	Vect r2 = ((max - min) * 0.5);//B.getHalfDiagonal();

	for (int i = 0; i < 15; i++)
	{
		//Calculate Projection 1
		Vect vectInverse = vectList[i] * AWInv;
		float Proj1Max = (abs(vectInverse.X() * r1.X()) + abs(vectInverse.Y() * r1.Y()) + abs(vectInverse.Z() * r1.Z())) / vectList[i].mag();
		Proj1Max *= A.getScaleFactorSquared();

		//Calculate Projection 2
		vectInverse = vectList[i] * BWInv;
		float Proj2Max = (abs(vectInverse.X() * r2.X()) + abs(vectInverse.Y() * r2.Y()) + abs(vectInverse.Z() * r2.Z())) / vectList[i].mag();
		Proj2Max *= scaleSquared;//B.getScaleFactorSquared();

		//Calculate the projection of the distance between both centers
		float D = abs((C2 - C1).dot(vectList[i])) / vectList[i].mag();

		//Comparethe projected distance between the sum of the projected half diagonals
		if (D > Proj1Max + Proj2Max)
		{
			return false;
		}
	}

	return true;
}

bool LediriMathTools::Intersect(const CollisionVolumeAABB & A, const CollisionVolumeOBB & B)
{
	Matrix AWorld = A.getWorldTransform();
	Matrix BWorld = B.getWorldTransform();

	Vect vectList[15];
	vectList[0] = AWorld.get(ROW_0);
	vectList[1] = AWorld.get(ROW_1);
	vectList[2] = AWorld.get(ROW_2);
	vectList[3] = BWorld.get(ROW_0);
	vectList[4] = BWorld.get(ROW_1);
	vectList[5] = BWorld.get(ROW_2);

	int n = 5;
	for (int i = 0; i < 3; i++)
	{

		vectList[++n] = vectList[i].cross(vectList[3]);
		vectList[n].W() = 0;
		vectList[++n] = vectList[i].cross(vectList[4]);
		vectList[n].W() = 0;
		vectList[++n] = vectList[i].cross(vectList[5]);
		vectList[n].W() = 0;

	}

	Matrix AWInv = A.getWorldTransform().getInv();
	Matrix BWInv = B.getWorldTransform().getInv();

	Vect C1 = A.getCenter();
	Vect C2 = B.getCenter();

	Vect r1 = A.getHalfDiagonal();
	Vect r2 = B.getHalfDiagonal();

	for (int i = 0; i < 15; i++)
	{
		//Calculate Projection 1
		Vect vectInverse = vectList[i] * AWInv;
		float Proj1Max = (abs(vectInverse.X() * r1.X()) + abs(vectInverse.Y() * r1.Y()) + abs(vectInverse.Z() * r1.Z())) / vectList[i].mag();
		Proj1Max *= A.getScaleFactorSquared();

		//Calculate Projection 2
		vectInverse = vectList[i] * BWInv;
		float Proj2Max = (abs(vectInverse.X() * r2.X()) + abs(vectInverse.Y() * r2.Y()) + abs(vectInverse.Z() * r2.Z())) / vectList[i].mag();
		Proj2Max *= B.getScaleFactorSquared();

		//Calculate the projection of the distance between both centers
		float D = abs((C2 - C1).dot(vectList[i])) / vectList[i].mag();

		//Compare the projected distance between the sum of the projected half diagonals
		if (D > Proj1Max + Proj2Max)
		{
			return false;
		}
	}

	return true;
}

bool LediriMathTools::Intersect(const CollisionVolumeOBB & A, const CollisionVolumeOBB & B)
{

	Matrix AWorld = A.getWorldTransform();
	Matrix BWorld = B.getWorldTransform();

	Vect vectList[15];
	vectList[0] = AWorld.get(ROW_0);
	vectList[1] = AWorld.get(ROW_1);
	vectList[2] = AWorld.get(ROW_2);
	vectList[3] = BWorld.get(ROW_0);
	vectList[4] = BWorld.get(ROW_1);
	vectList[5] = BWorld.get(ROW_2);
	
	int n = 5;
	for (int i = 0; i < 3; i++)
	{

		vectList[++n] = vectList[i].cross(vectList[3]);
		vectList[++n] = vectList[i].cross(vectList[4]);
		vectList[++n] = vectList[i].cross(vectList[5]);

	}

	Matrix AWInv = A.getWorldTransform().getInv();
	Matrix BWInv = B.getWorldTransform().getInv();

	Vect C1 = A.getCenter();
	Vect C2 = B.getCenter();

	Vect r1 = A.getHalfDiagonal();
	Vect r2 = B.getHalfDiagonal();

	for (int i = 0; i < 15; i++)
	{
		//Calculate Projection 1
		Vect vectInverse = vectList[i] * AWInv;
		float Proj1Max = (abs(vectInverse.X() * r1.X()) + abs(vectInverse.Y() * r1.Y()) + abs(vectInverse.Z() * r1.Z())) / vectList[i].mag();
		Proj1Max *= A.getScaleFactorSquared();

		//Calculate Projection 2
		vectInverse = vectList[i] * BWInv;
		float Proj2Max = (abs(vectInverse.X() * r2.X()) + abs(vectInverse.Y() * r2.Y()) + abs(vectInverse.Z() * r2.Z())) / vectList[i].mag();
		Proj2Max *= B.getScaleFactorSquared();

		//Calculate the projection of the distance between both centers
		float D = abs((C2 - C1).dot(vectList[i])) / vectList[i].mag();

		//Comparethe projected distance between the sum of the projected half diagonals
		if (D > Proj1Max + Proj2Max)
		{
			return false;
		}
	}
	
	return true;
}

float LediriMathTools::ClampTest(float a, float b, float c)
{
	if (c < a)
	{
		return a;
	}
	else if (c > b)
	{
		return b;
	}
	else
	{
		return c;
	}
}

bool LediriMathTools::PointInSphere(const Vect& c, const Vect& p, float r)
{
		return (c - p).dot(c - p) < r * r;

}

float LediriMathTools::ProjectionVectWOntoVectV(const Vect & W, const Vect & V)
{
	return (W.dot(V) / V.mag());
}



bool LediriMathTools::Intersect(const CollisionVolumeAABB & A, const CollisionVolumeAABB & B)
{
	Vect AMin = A.getMin();
	Vect AMax = A.getMax();
	Vect BMin = B.getMin();
	Vect BMax = B.getMax();
	
	if (AMax.X() < BMin.X())
	{
		return false;
	}
	if (BMax.X() < AMin.X())
	{
		return false;
	}
	if (AMax.Y() < BMin.Y())
	{
		return false;
	}
	if (BMax.Y() < AMin.Y())
	{
		return false;
	}

	if (AMax.Z() < BMin.Z())
	{
		return false;
	}
	if (BMax.Z() < AMin.Z())
	{
		return false;
	}
	return true;
}

bool LediriMathTools::Intersect(const CollisionVolumeAABB& A, const Vect min, const Vect max)
{
	Vect AMin = A.getMin();
	Vect AMax = A.getMax();
	Vect BMin = min;
	Vect BMax = max;

	if (AMax.X() < BMin.X())
	{
		return false;
	}
	if (BMax.X() < AMin.X())
	{
		return false;
	}

	if (AMax.Y() < BMin.Y())
	{
		return false;
	}
	if (BMax.Y() < AMin.Y())
	{
		return false;
	}

	if (AMax.Z() < BMin.Z())
	{
		return false;
	}
	if (BMax.Z() < AMin.Z())
	{
		return false;
	}
	return true;
}

bool LediriMathTools::Intersect(const CollisionObject* c1, const CollisionObject* c2)
{
	const CollisionVolume& v1 = c1->GetCollisionVolume();
	const CollisionVolume& v2 = c2->GetCollisionVolume();

	return v1.IntersectAccept(v2);
}

bool LediriMathTools::Intersect(const CollisionObject* c1, const Vect min, const Vect max)
{
	const CollisionVolume& v1 = c1->GetCollisionVolume();

	return v1.IntersectVisit(min, max);
}



//bool LediriMathTools::AxisOverlap(float a, float b)
//{
//	if (a < b)
//	{
//		return false;
//	}
//	return true;
//}