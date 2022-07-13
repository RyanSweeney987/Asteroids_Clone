#pragma once
#include <SDL.h>

enum class CollisionFilter {
	Default,
	Player,
	Enemy,
	Weapon
};

class RS_CollisionListener {
public:
	virtual void OnCollisionEnter() = 0;
	virtual void OnCollisionExit() = 0;
};

class RS_Collider {
public:
	RS_Collider(RS_CollisionListener* listener);

	bool IsEnabled();
	bool IsColliding();
	bool IsDebugRenderEnabled();
	SDL_Rect& GetCollisionBox();

	void SetIsEnabled(bool enabled);
	void SetDebugRenderEnabled(bool enabled);
	void SetIsColliding(bool isColliding);
private:
	bool enabled = true;
	bool isColliding = false;
	bool isDebugRenderEnabled;

	SDL_Rect collisionBox;
	RS_CollisionListener* listener;
};