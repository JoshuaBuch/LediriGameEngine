#ifndef _TEXTUREMANAGER
#define _TEXTUREMANAGER
#include "AzulCore.h"
#include <map>
#include <string>

using namespace std;

class TextureManager
{
public:

	static void loadTexture(std::string modstr, string modfile) { Instance().privLoadTexture(modstr, modfile); };
	static Texture* getTexture(std::string modstr) { return Instance().privGetTexture(modstr); };

private:

	friend class TextureManagerAttorney;

	TextureManager() = default;
	TextureManager(const TextureManager&) = delete;
	TextureManager& operator=(const TextureManager&) = delete;
	~TextureManager() {};

	std::map<std::string, Texture*> TextureMap;
	Texture* pTemp = nullptr;
	map<string, Texture*>::iterator it;

	static TextureManager* ptrInstance;

	static TextureManager& Instance()
	{
		if (!ptrInstance)
		{
			ptrInstance = new TextureManager;
		}
		return *ptrInstance;
	}

	void privLoadTexture(std::string, string);
	Texture* privGetTexture(std::string);

	//attorney methods for Lediri
	static void DeleteTextures() { Instance().privDeleteTextures(); };
	void privDeleteTextures();
	static void DeleteTextureManager() { Instance().privDeleteTextureManager(); };
	void privDeleteTextureManager();
};
#endif _TextureManager
