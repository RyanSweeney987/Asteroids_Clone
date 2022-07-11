#pragma once
#include <vector>
#include "RS_GameObject.h"

class RS_PhysicsSolver {
public:
	void CheckForCollisions(std::vector<RS_GameObject*> gameObjects);
private:
	std::vector<RS_GameObject*> colliding;
};