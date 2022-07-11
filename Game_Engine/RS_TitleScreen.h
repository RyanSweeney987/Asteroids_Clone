#pragma once

#include "RS_GameWorld.h"

class RS_TitleScreen : public RS_GameWorld {
public:
	RS_TitleScreen();
	// Inherited via RS_GameWorld
	virtual void Init() override;
	virtual void Update() override;
	virtual void Input() override;

	// Inherited via RS_InputActionListener
	virtual void HandleEvent(ActionData data) override;
	virtual void HandleEvent(ActionData data, int id) override;
};