#ifndef TextureManagerAttorney_H
#define TextureManagerAttorney_H

#include "TextureManager.h"

class TextureManagerAttorney
{
public:

private:
	friend class Lediri; //Lediri only needs access to the model Manager's delete function

	TextureManagerAttorney();
	TextureManagerAttorney(const TextureManagerAttorney&) = delete;
	TextureManagerAttorney& operator=(const TextureManagerAttorney&) = delete;
	~TextureManagerAttorney() {};

	static void DeleteTextures() { TextureManager::DeleteTextures(); };
	static void DeleteTextureManager() { TextureManager::DeleteTextureManager(); };
};
#endif // !TextureManagerAttorney_H
