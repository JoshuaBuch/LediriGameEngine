#ifndef ShaderManagerAttorney_H
#define ShaderManagerAttorney_H

#include "ShaderManager.h"

class ShaderManagerAttorney
{
public:

private:
	friend class Lediri; //Lediri only needs access to the model Manager's delete function

	ShaderManagerAttorney();
	ShaderManagerAttorney(const ShaderManagerAttorney&) = delete;
	ShaderManagerAttorney& operator=(const ShaderManagerAttorney&) = delete;
	~ShaderManagerAttorney() {};

	static void DeleteShaders() { ShaderManager::DeleteShaders(); };
	static void DeleteShaderManager() { ShaderManager::DeleteShaderManager(); };
};
#endif // !ShaderManagerAttorney_H

