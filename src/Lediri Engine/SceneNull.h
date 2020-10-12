#ifndef SceneNull_H
#define SceneNull_H

#include "Scene.h"

class SceneNull : public Scene
{

public:

	SceneNull() = default;
	SceneNull(const SceneNull&) = delete;
	SceneNull& operator=(const SceneNull&) = delete;
	virtual ~SceneNull() {};

};
#endif // !SceneNull_H
