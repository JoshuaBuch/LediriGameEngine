#include "ShaderManager.h"
#include <iostream>


//Set ModelManager to null
ShaderManager* ShaderManager::ptrInstance = nullptr;


void ShaderManager::privLoadShader(string modstr, string modfile)
{
	//it = ShaderMap.find(modstr);
	//assert(it == ShaderMap.end());
	modfile = "Shaders/" + modfile;
	pTemp = new ShaderObject(modfile.c_str());
	ShaderMap.insert(pair<string, ShaderObject*>(modstr, pTemp));
}

ShaderObject* ShaderManager::privGetShader(std::string modstr)
{
	pTemp = ShaderMap[modstr];
	if (pTemp == nullptr)
	{
		OutputDebugString("\n\n\nThis SHADER does not exist\n\n\n");
	}
	assert(pTemp);
	return (pTemp);
}

void ShaderManager::privDeleteShaders()
{
	//delete the Shader, can't simply use clear method for map as that doesn't actually delete
	//the objects in the map.
	it = ShaderMap.begin();
	while (it != ShaderMap.end())
	{
		delete(it->second);
		it++;
	}
	ShaderMap.clear();
}

void ShaderManager::privDeleteShaderManager()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}
