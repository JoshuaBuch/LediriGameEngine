#ifndef _MODELMANAGER
#define _MODELMANAGER
#include "AzulCore.h"
#include <map>
#include <string>


using namespace std;

class ModelManager
{
public:

	//users must access these methods when uploading assets and using them inside of game objects
	static void loadModel(std::string modstr, string modfile) { Instance().privLoadModel(modstr, modfile); };
	static Model* getModel(std::string modstr) { return Instance().privGetModel(modstr); };


private:

	friend class ModelManagerAttorney;

	ModelManager();
	ModelManager(const ModelManager&) = delete;
	ModelManager& operator=(const ModelManager&) = delete;
	~ModelManager() {};

	//elements
	std::map<std::string, Model*> ModelMap;
	Model* pTemp = nullptr;
	map<string, Model*>::iterator it;

	//instance
	static ModelManager* ptrInstance;

	static ModelManager& Instance()
	{
		if (!ptrInstance)
		{
			ptrInstance = new ModelManager;
		}
		return *ptrInstance;
	}


	//methods
	void privLoadModel(std::string, string);
	Model* privGetModel(std::string);

	//Attorney methods for Lediri
	static void DeleteModels(); //this function is to simply grab the INSTANCE of modelmanager
	void privDeleteModels();
	static void DeleteModelManager() { Instance().privDeleteModelManager(); };
	void privDeleteModelManager();

};
#endif _MODELMANAGER
