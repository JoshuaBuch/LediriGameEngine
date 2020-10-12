#include "TextureManager.h"


//Set ModelManager to null
TextureManager* TextureManager::ptrInstance = nullptr;

void TextureManager::privLoadTexture(string modstr, string modfile)
{
	//it = TextureMap.find(modstr);
	//assert(it == TextureMap.end());
	modfile = "Textures/" + modfile;
	pTemp = new Texture(modfile.c_str());
	TextureMap.insert(pair<string, Texture*>(modstr, pTemp));
}

Texture* TextureManager::privGetTexture(std::string modstr)
{
	pTemp = TextureMap[modstr];
	if (pTemp == nullptr)
	{
		OutputDebugString("\n\n\nThis TEXTURE does not exist\n\n\n");
	}
	assert(pTemp);
	return (TextureMap[modstr]);
}

void TextureManager::privDeleteTextures()
{
	//delete the Texture, can't simply use clear method for map as that doesn't actually delete
	//the objects in the map.
	it = TextureMap.begin();
	while (it != TextureMap.end())
	{
		delete(it->second);
		it++;
	}
	TextureMap.clear();
}

void TextureManager::privDeleteTextureManager()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}
