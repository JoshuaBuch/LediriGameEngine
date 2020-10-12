#ifndef ModelManagerAttorney_H
#define ModelManagerAttorney_H

#include "ModelManager.h"

class ModelManagerAttorney
{
public:

private:
	friend class Lediri; //Lediri only needs access to the model Manager's delete function

	ModelManagerAttorney() = default;
	ModelManagerAttorney(const ModelManagerAttorney&) = delete;
	ModelManagerAttorney& operator=(const ModelManagerAttorney&) = delete;
	~ModelManagerAttorney() {};

	static void DeleteModels() { ModelManager::DeleteModels(); };
	static void DeleteModelManager() { ModelManager::DeleteModelManager(); };
};

#endif // !ModelManagerAttorney_H
