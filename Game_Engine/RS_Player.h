#pragma once

#include "RS_GameObject.h"

class RS_Player : public RS_GameObject {
public:
	RS_Player(int x, int y, int width, int height, RS_Sprite& sprite);
	~RS_Player();
private:
	unsigned int health = 1000;
	// Inherited via RS_GameObject
	virtual void Update() override;

	// Inherited via RS_GameObject
	virtual void HandleEvent(ActionData data) override;
	virtual void HandleEvent(ActionData data, int id) override;

	// Inherited via RS_GameObject
	virtual void OnCollisionEnter() override;
	virtual void OnCollisionExit() override;
};