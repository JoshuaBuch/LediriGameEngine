#ifndef  _TERRAINOBJECTMANAGERATTORNEY_H
#define _TERRAINOBJECTMANAGERATTORNEY_H

#include "TerrainObjectManager.h"

class TerrainObjectManagerAttorney
{
public:

private:
	friend class Lediri; //Lediri only needs access to the terrainobject manager's delete function

	TerrainObjectManagerAttorney() = default;
	TerrainObjectManagerAttorney(const TerrainObjectManagerAttorney&) = delete;
	TerrainObjectManagerAttorney& operator=(const TerrainObjectManagerAttorney&) = delete;
	~TerrainObjectManagerAttorney() {};

	static void DeleteTerrainObjects() { TerrainObjectManager::DeleteTerrainObjects(); };
	static void DeleteTerrainObjectManager() { TerrainObjectManager::DeleteTerrainObjectManager(); };

};
#endif // ! _TERRAINOBJECTMANAGERATTORNEY_H
