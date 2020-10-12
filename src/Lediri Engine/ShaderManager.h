#ifndef _ShaderMANAGER
#define _ShaderMANAGER
#include "AzulCore.h"
#include <map>
#include <string>

using namespace std;

class ShaderManager
{
public:

	static void loadShader(std::string modstr, string modfile) { Instance().privLoadShader(modstr, modfile); };
	static ShaderObject* getShader(std::string modstr) { return Instance().privGetShader(modstr); };

private:

	friend class ShaderManagerAttorney;

	ShaderManager() = default;
	ShaderManager(const ShaderManager&) = delete;
	ShaderManager& operator=(const ShaderManager&) = delete;
	~ShaderManager() {};

	//elements
	std::map<std::string, ShaderObject*> ShaderMap;
	ShaderObject* pTemp = nullptr;
	map<string, ShaderObject*>::iterator it;


	static ShaderManager* ptrInstance;

	static ShaderManager& Instance()
	{
		if (!ptrInstance)
		{
			ptrInstance = new ShaderManager;
		}
		return *ptrInstance;
	}

	void privLoadShader(std::string, string);
	ShaderObject* privGetShader(std::string);

	//attorney methods for Lediri
	static void DeleteShaders() { Instance().privDeleteShaders(); };
	void privDeleteShaders();
	static void DeleteShaderManager() { Instance().privDeleteShaderManager(); };
	void privDeleteShaderManager();

};
#endif _ShaderManager
#pragma once
