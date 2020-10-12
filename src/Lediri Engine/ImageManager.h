#ifndef ImageManager_H
#define ImageManager_H

#include "Image.h"
#include <string>
#include <map>

using namespace std;

class ImageManager
{
public:
	static void loadImage(string imString, string texName) { Instance().privLoadImage(imString, texName); };
	static Image* getImage(std::string imstring) { return Instance().privGetImage(imstring); };

private:

	friend class ImageManagerAttorney;

	ImageManager() = default;
	ImageManager(const ImageManager&) = delete;
	ImageManager& operator=(const ImageManager&) = delete;
	~ImageManager() {};

	std::map<std::string, Image*> ImageMap;
	Image* pTemp = nullptr;
	map<string, Image*>::iterator it;

	static ImageManager* ptrInstance;

	static ImageManager& Instance()
	{
		if (!ptrInstance)
		{
			ptrInstance = new ImageManager;
		}
		return *ptrInstance;
	}

	void privLoadImage(string, string);
	Image* privGetImage(string);

	//attorney method for Lediri
	static void DeleteImages() { Instance().privDeleteImages(); };
	void privDeleteImages();
	static void DeleteImageManager() { Instance().privDeleteImageManager(); };
	void privDeleteImageManager();
};
#endif // !ImageManager_H
