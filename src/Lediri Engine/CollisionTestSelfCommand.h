#ifndef CollisionTestSelfCommand_H
#define CollisionTestSelfCommand_H

#include "CollisionTestCommandBase.h"
#include "CollisionVolumeBSphere.h"
#include "LediriMathTools.h"


class CollisionVolumeAABB;

template <typename C>
class CollisionTestSelfCommand : public CollisionTestCommandBase
{
public:

	CollisionTestSelfCommand()
		: Collection(CollisionObjectGroup<C>::GetCollisionObjectCollection()),
		COGBox(CollisionObjectGroup<C>::GetCollisionObjectGroupAABB())
	{

	};

	CollisionTestSelfCommand(const CollisionTestSelfCommand&) = delete;
	CollisionTestSelfCommand& operator=(const CollisionTestSelfCommand&) = delete;

	~CollisionTestSelfCommand()
	{
		DebugMsg::out("\nDeleting CollisionTestSelfCommand object"); 
	}; //base class has to have virtual destructor

	virtual void execute()
	{
		CollisionObjectGroup<C>::UpdateCOGAABB();

		//DebugMsg::out("\nSelfCommand execute signing on");
		for (auto it1 = Collection.begin(); it1 != Collection.end(); it1++)
		{
			
			for (auto it2 = std::next(it1); it2 != Collection.end(); it2++)
			{

				bool test_result = LediriMathTools::Intersect((*it1)->GetCollisionSphere(), (*it2)->GetCollisionSphere());

				if (test_result)
				{
					test_result = LediriMathTools::Intersect(*it1, *it2);
					if (test_result)
					{
						Visualizer::ShowCollisionVolume(*it1, Color::Red);
						Visualizer::ShowCollisionVolume(*it2, Color::Red);
						(*it1)->Collision(*it2);
						(*it2)->Collision(*it1);

					}
					else
					{
						Visualizer::ShowCollisionVolume(*it1, Color::Maroon);
						Visualizer::ShowCollisionVolume(*it2, Color::Maroon);

					}
				}
				else
				{
					Visualizer::ShowAABB(COGBox, Color::White);
					Visualizer::ShowCollisionVolume(*it1, Color::Blue);
					Visualizer::ShowCollisionVolume(*it2, Color::Blue);
				}

			}

		}
	}

private:
	typename const CollisionObjectGroup<C>::CollisionObjectCollection& Collection;
	const CollisionVolumeAABB& COGBox;
};
#endif // !CollisionTestSelfCommand_H

