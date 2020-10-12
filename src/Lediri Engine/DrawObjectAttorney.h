#ifndef DrawObjectAttorney_H
#define DrawObjectAttorney_H

#include "DrawObject.h"
#include "DrawRegistrationCommand.h"
#include "DrawDeregistrationCommand.h"

class DrawObjectAttorney
{
public:
	using StorageList = std::list<DrawObject*>;
	using StorageListRef = StorageList::iterator;
	class GameLoop
	{
	private:

		friend class DrawObjectManager;
		static void Draw(DrawObject* pDO) { pDO->Draw(); };
		static void SetIteratorReference(DrawObject* pDO, StorageListRef ref) { pDO->SetIteratorRef(ref); };

	};

	class Registration
	{
	private:
		friend class DrawRegistrationCommand;
		friend class DrawDeregistrationCommand;

		static void SceneRegistration(DrawObject* pDO) { pDO->SceneRegistration(); };
		static void SceneDeregistration(DrawObject* pDO) { pDO->SceneDeregistration(); };

	};

private:


};
#endif // !DrawObjectAttorney_H

