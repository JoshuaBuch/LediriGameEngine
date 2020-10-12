#include "TerrainObjectManager.h"
#include "TerrainObject.h"
#include <iostream>

TerrainObjectManager* TerrainObjectManager::ptrInstance = nullptr;

TerrainObjectManager::TerrainObjectManager()
{

}

void TerrainObjectManager::privLoadTerrainObject(std::string terrainName, char* terstr, float s, float maxheight, float baseHeight, char* textureName, int repeatu, int repeatv)
{
	std::string terString = terstr;
	pTemp = new TerrainObject(terstr, s, maxheight, baseHeight, textureName, repeatu, repeatv);
	TerrainObjectMap.insert(pair<string, TerrainObject*>(terrainName, pTemp));
	pTemp = nullptr;
}

TerrainObject* TerrainObjectManager::privGetTerrainObject(std::string terrainName)
{
	pTemp = TerrainObjectMap[terrainName];
	if (pTemp == nullptr)
	{
		OutputDebugString("\n\n\nTerrainObjectManager could not locate terrain object\n\n\n");
	}
	assert(pTemp && "Failed to get terrain object");
	return (pTemp);
}

void TerrainObjectManager::privDeleteTerrainObjects()
{
	it = TerrainObjectMap.begin();
	while (it != TerrainObjectMap.end())
	{
		delete(it->second);
		it++;
	}
	TerrainObjectMap.clear();
}

void TerrainObjectManager::DeleteTerrainObjects()
{
	Instance().privDeleteTerrainObjects();
}

void TerrainObjectManager::privDeleteTerrainObjectManager()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}