#ifndef ImageManagerAttorney_H
#define ImageManagerAttorney_H

#include "ImageManager.h"

class ImageManagerAttorney
{
public:

private:
	friend class Lediri;

	ImageManagerAttorney();
	ImageManagerAttorney(const ImageManagerAttorney&) = delete;
	ImageManagerAttorney& operator=(const ImageManagerAttorney&) = delete;
	~ImageManagerAttorney() {};

	static void DeleteImages() { ImageManager::DeleteImages(); };
	static void DeleteImageManager() { ImageManager::DeleteImageManager(); };
};
#endif // !