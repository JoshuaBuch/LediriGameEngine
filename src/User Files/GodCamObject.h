#ifndef _GODCAMOBJECT
#define _GODCAMOBJECT

#include "../Lediri Engine/GameObjectDependencies.h"

class GodCamObject : public GameObject
{
public:
	GodCamObject();
	GodCamObject(const GodCamObject&) = delete;
	GodCamObject& operator=(const GodCamObject&) = delete;
	~GodCamObject();
	

	void KeyPressed(AZUL_KEY k);
	void KeyReleased(AZUL_KEY k);

	void Update();

private:


};
#endif // !_GODCAMOBJECT
