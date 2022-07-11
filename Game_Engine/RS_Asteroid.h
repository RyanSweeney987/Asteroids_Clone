#pragma once

#include "RS_GameObject.h"

class RS_Asteroid : public RS_GameObject {
public:
	RS_Asteroid(int x, int y, int width, int height, RS_Sprite& sprite);
private:
	float rotation = rand() % 5;
	RS_Vector2f movement = RS_Vector2f(rand() % 4 + (-2), rand() % 4 + (-2));

	// Inherited via RS_GameObject
	virtual void Update() override;
	// Inherited via RS_GameObject
	virtual void HandleEvent(ActionData data) override;
	virtual void HandleEvent(ActionData data, int id) override;

	// Inherited via RS_GameObject
	virtual void OnCollisionEnter() override;
	virtual void OnCollisionExit() override;
};