#pragma once

#include <vector>
#include <SDL.h>
#include "RS_Time.h"
#include "RS_Input.h"
#include "RS_Vector2.h"
#include "RS_GameObject.h"
#include "RS_Player.h"
#include "ScreenText.h"
#include "RS_SoundManager.h"
#include "RS_TextureManager.h"
#include "RS_PhysicsSolver.h"

class RS_GameWorld: public RS_InputActionListener {
public:
	RS_GameWorld();
	~RS_GameWorld();

	void Start();
	virtual void Init() = 0;
	void Run();
	void Stop();
	virtual void Update();
	virtual void Input() = 0;
	void Render();

	bool GetIsRunning();
protected:
	RS_Time time;
	RS_PhysicsSolver solver;
	RS_Logger* log;
	RS_Input* input;
	RS_TextureManager* textureManager;
	RS_SoundManager* soundManager;

	std::vector<RS_GameObject*> gameObjects;
	std::vector<ScreenText*> textObjects;

	virtual void HandleEvent(ActionData data) override;
	virtual void HandleEvent(ActionData data, int id) override;
private:
	bool isRunning = false;

	const float DELTA_TIME = 1000.0f / 60.0f;
};