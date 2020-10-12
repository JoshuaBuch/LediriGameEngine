#include "ImageManager.h"
#include "TextureManager.h"

ImageManager* ImageManager::ptrInstance = nullptr;

void ImageManager::privLoadImage(string imStr, string texName)
{
	pTemp = new Image(TextureManager::getTexture(texName), new Rect(0.0f, 0.0f, (float)TextureManager::getTexture(texName)->getWidth(), (float)TextureManager::getTexture(texName)->getHeight()));
	ImageMap.insert(pair<string, Image*>(imStr, pTemp));
}

Image* ImageManager::privGetImage(string imStr)
{
	pTemp = ImageMap[imStr];
	if (pTemp == nullptr)
	{
		OutputDebugString("\n\n\nThis TEXTURE does not exist\n\n\n");
	}
	assert(pTemp);
	return (ImageMap[imStr]);
}

void ImageManager::privDeleteImages()
{
	it = ImageMap.begin();
	while (it != ImageMap.end())
	{
		delete(it->second);
		it++;
	}
	ImageMap.clear();
}

void ImageManager::privDeleteImageManager()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}
