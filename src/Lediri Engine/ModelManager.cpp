#include "ModelManager.h"
#include <iostream>

//Set ModelManager to null
ModelManager* ModelManager::ptrInstance = nullptr;

ModelManager::ModelManager()
{
	//These default models are part of azul so they should always be loaded into the model
	//manager when it is initialized.
	pTemp = new Model(Model::PreMadeModels::UnitSphere);
	ModelMap.insert(pair<string, Model*>("UnitSphere", pTemp));

	pTemp = new Model(Model::PreMadeModels::UnitBox_WF);
	ModelMap.insert(pair<string, Model*>("UnitBox", pTemp));

	pTemp = new Model(Model::PreMadeModels::UnitSquareXY);
	ModelMap.insert(pair<string, Model*>("UnitSquareXY", pTemp));
}

void ModelManager::privLoadModel(string modstr, string modfile)
{
	//it = ModelMap.find(modstr);
	//assert(it == ModelMap.end());
	modfile = "Models/" + modfile;
	pTemp = new Model(modfile.c_str());
	ModelMap.insert(pair<string, Model*>(modstr, pTemp));
	pTemp = nullptr;
}

Model* ModelManager::privGetModel(std::string modstr)
{
	pTemp = ModelMap[modstr];
	if (pTemp == nullptr)
	{
		OutputDebugString("\n\n\nModel manager could not locate model\n\n\n");
		//DebugMsg::out("Model manager failed to locate: s%. Does not exist");
	}
	assert(pTemp && "Failed to get model");
	return (pTemp);
}

void ModelManager::privDeleteModels()
{
	//delete the model, can't simply use clear method for map as that doesn't actually delete
	//the objects in the map.
	it = ModelMap.begin();
	while (it != ModelMap.end())
	{
		delete(it->second);
		it++;
	}
	ModelMap.clear();
}

void ModelManager::DeleteModels()
{
	Instance().privDeleteModels();
}

void ModelManager::privDeleteModelManager()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}