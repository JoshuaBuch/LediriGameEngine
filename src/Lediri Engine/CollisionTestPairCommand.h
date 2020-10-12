#ifndef CollisionTestPairCommand_H
#define CollisionTestPairCommand_H

#include "CollisionTestCommandBase.h"
#include "CollisionObjectGroup.h"
#include "CollisionVolumeBSphere.h"
#include "LediriMathTools.h"
#include "Visualizer.h"
#include "Color.h"
#include "AzulHelper.h"

class CollisionVolumeAABB;

template <typename C1, typename C2>
class CollisionTestPairCommand : public CollisionTestCommandBase
{
public:
	CollisionTestPairCommand()
		: Collection1(CollisionObjectGroup<C1>::GetCollisionObjectCollection()),
		Collection2(CollisionObjectGroup<C2>::GetCollisionObjectCollection()),
		COGBox1(CollisionObjectGroup<C1>::GetCollisionObjectGroupAABB()),
		COGBox2(CollisionObjectGroup<C2>::GetCollisionObjectGroupAABB())
	{
	};

	CollisionTestPairCommand(const CollisionTestPairCommand&) = delete;
	CollisionTestPairCommand& operator=(const CollisionTestPairCommand&) = delete;

	~CollisionTestPairCommand()
	{
		DebugMsg::out("\nDeleting CollisionTestPairCommand object");
	}; //base class has to have virtual destructor

	virtual void execute()
	{
		CollisionObjectGroup<C1>::UpdateCOGAABB();
		CollisionObjectGroup<C2>::UpdateCOGAABB();

		//Visualizer::ShowAABB(COGBox1, Color::Green);
		//Visualizer::ShowAABB(COGBox2, Color::Green);

		//Check if the CollisionObjectGroup AABBs intersect
		bool test_result = LediriMathTools::Intersect(COGBox1, COGBox2);
		if (test_result)
		{
			//Yes the AABBs are intersecting
			//Visualizer::ShowAABB(COGBox1, Color::Green);
			//Visualizer::ShowAABB(COGBox2, Color::Green);
			
			//Begin checking if any of the GameObjects BSphere's intersect with the other group's AABB
			for (auto it1 = Collection1.begin(); it1 != Collection1.end(); it1++)
			{
				test_result = LediriMathTools::Intersect((*it1)->GetCollisionSphere(), COGBox2);

				if (test_result)
				{
					//Check if the GameObject's BSphere intersects with any of the other group's GameObject BSpheres
					for (auto it2 = Collection2.begin(); it2 != Collection2.end(); it2++)
					{
						test_result = LediriMathTools::Intersect((*it1)->GetCollisionSphere(), (*it2)->GetCollisionSphere());
						//Visualizer::ShowBSphere((*it1)->GetCollisionSphere(), Color::Red);
						//Visualizer::ShowBSphere((*it2)->GetCollisionSphere(), Color::Red);
						if (test_result)
						{
							//Visualizer::ShowCollisionVolume(*it1, Color::Maroon);

							test_result = LediriMathTools::Intersect(*it1, *it2);

							if (test_result)
							{
								//Visualizer::ShowCollisionVolume(*it1, Color::Red);
								//Visualizer::ShowCollisionVolume(*it2, Color::Red);
								(*it1)->Collision(*it2);
								(*it2)->Collision(*it1);
							
							}
							else
							{
								//Visualizer::ShowCollisionVolume(*it1, Color::Yellow);
								//Visualizer::ShowCollisionVolume(*it2, Color::Maroon);

							}
						}
						else
						{
							//Visualizer::ShowCollisionVolume(*it1, Color::Yellow);
							//Visualizer::ShowCollisionVolume(*it2, Color::Yellow); //switch to Yellow
						}
					}
				}
				else //if no Bspheres collide with a group's AABB
				{

					for (auto it2 = Collection2.begin(); it2 != Collection2.end(); it2++)
					{
						//Visualizer::ShowCollisionVolume(*it1, Color::Blue);
						//Visualizer::ShowCollisionVolume(*it2, Color::Blue);
					}

				}

			}
		}
		else
		{
			//Show the collision group boxes
			//Visualizer::ShowAABB(COGBox1, Color::Blue);
			//Visualizer::ShowAABB(COGBox2, Color::Blue);
			for (auto it1 = Collection1.begin(); it1 != Collection1.end(); it1++)
			{
				for (auto it2 = Collection2.begin(); it2 != Collection2.end(); it2++)
				{
					//Visualizer::ShowCollisionVolume(*it1, Color::Blue);
					//Visualizer::ShowCollisionVolume(*it2, Color::Blue);
				}
			}
		}

	}

private:
	typename const CollisionObjectGroup<C1>::CollisionObjectCollection& Collection1;
	typename const CollisionObjectGroup<C2>::CollisionObjectCollection& Collection2;
	const CollisionVolumeAABB& COGBox1;
	const CollisionVolumeAABB& COGBox2;
};
#endif // !CollisionTestPairCommand_H
