#pragma once
#include "RS_GameObject.h"

class RS_Background : public RS_GameObject {
public:
	RS_Background(RS_Sprite& background);
private:
	// Inherited via RS_GameObject
	virtual void Update() override;

	virtual void HandleEvent(ActionData data) override;

	virtual void HandleEvent(ActionData data, int id) override;

	virtual void OnCollisionEnter() override;

	virtual void OnCollisionExit() override;

};