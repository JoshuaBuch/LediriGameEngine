#ifndef _TERRAINOBJECTMANAGER
#define _TERRAINOBJECTMANAGER
#include "AzulCore.h"
#include <map>
#include <string>
#include "TerrainObject.h"

using namespace std;

class TerrainObjectManager
{
public:
	//load the terrain, need to use all the user input values here. not just string and file like the other asset managers
	static void LoadTerrainObject(std::string terrainName, char* terstr, float s, float maxheight, float baseHeight, char* textureName, int repeatu, int repeatv)
	{
		Instance().privLoadTerrainObject(terrainName, terstr, s, maxheight, baseHeight, textureName, repeatu, repeatv);
	}
	static TerrainObject* getTerrainObject(std::string terrainName) { return Instance().privGetTerrainObject(terrainName); };

private:
	
	friend class TerrainObjectManagerAttorney;

	TerrainObjectManager();
	TerrainObjectManager(const TerrainObjectManager&) = delete;
	TerrainObjectManager& operator=(const TerrainObjectManager&) = delete;
	~TerrainObjectManager() {};

	//elements
	std::map<std::string, TerrainObject*> TerrainObjectMap;
	TerrainObject* pTemp = nullptr;
	map<string, TerrainObject*>::iterator it;

	static TerrainObjectManager* ptrInstance;

	static TerrainObjectManager& Instance()
	{
		if (!ptrInstance)
		{
			ptrInstance = new TerrainObjectManager();
		}
		return *ptrInstance;
	}

	//methods
	void privLoadTerrainObject(std::string terrainName, char* modstr, float s, float maxheight, float baseHeight, char* textureName, int repeatu, int repeatv); //this needs more values
	TerrainObject* privGetTerrainObject(std::string);

	static void DeleteTerrainObjects();
	void privDeleteTerrainObjects();
	static void DeleteTerrainObjectManager() { Instance().privDeleteTerrainObjectManager(); };
	void privDeleteTerrainObjectManager();

};

#endif