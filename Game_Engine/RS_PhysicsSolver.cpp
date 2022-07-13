#include "RS_PhysicsSolver.h"
#include <map>

void RS_PhysicsSolver::CheckForCollisions(std::vector<RS_GameObject*> gameObjects)
{
	for (int i = 0; i < gameObjects.size(); i++) {
		if (gameObjects[i]->GetCollider().IsEnabled()) {
			for (int j = 0; j < gameObjects.size(); j++) {
				if (j == i) continue;

				RS_Collider* colA = &gameObjects[i]->GetCollider();
				SDL_Rect rectA = colA->GetCollisionBox();
				rectA.x += gameObjects[i]->GetTransform().position.x;
				rectA.y += gameObjects[i]->GetTransform().position.y;
				RS_Collider* colB = &gameObjects[j]->GetCollider();
				SDL_Rect rectB = colB->GetCollisionBox();
				rectB.x += gameObjects[j]->GetTransform().position.x;
				rectB.y += gameObjects[j]->GetTransform().position.y;

				if (SDL_HasIntersection(&rectA, &rectB)) {

					if (!colA->IsColliding()) { // Fire once
						// Dispatch on enter event
						colA->SetIsColliding(true);
					}
				}
				else {
					if (colA->IsColliding()) {
						colA->SetIsColliding(false);
					}
				}
			}
		}
	}
}
