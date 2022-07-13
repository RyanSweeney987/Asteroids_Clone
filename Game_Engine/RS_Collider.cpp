#include "RS_Collider.h"

RS_Collider::RS_Collider(RS_CollisionListener* listener) : listener(listener)
{
}

bool RS_Collider::IsEnabled()
{
	return enabled;
}

bool RS_Collider::IsColliding()
{
	return isColliding;
}

bool RS_Collider::IsDebugRenderEnabled()
{
	return isDebugRenderEnabled;
}

SDL_Rect& RS_Collider::GetCollisionBox()
{
	return collisionBox;
}

void RS_Collider::SetIsEnabled(bool enabled)
{
	this->enabled = enabled;
}

void RS_Collider::SetDebugRenderEnabled(bool enabled)
{
	isDebugRenderEnabled = enabled;
}

void RS_Collider::SetIsColliding(bool isColliding)
{
	if (isColliding) {
		// Dispatch enter?
		listener->OnCollisionEnter();
	}
	else {
		// Dispatch exit?
		listener->OnCollisionExit();
	}

	this->isColliding = isColliding;
}