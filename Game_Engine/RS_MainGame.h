#pragma once

#include "RS_GameWorld.h"
#include "RS_Timer.h"

class CountDownTimer : public RS_TimerCallback {
public:
	int timerCount = 30;
	virtual void Run() override;
};

class RS_MainGame : public RS_GameWorld {
public:
	RS_MainGame();

	// Inherited via RS_GameWorld
	//virtual void Start() override;
	virtual void Init() override;
	virtual void Update() override;
	virtual void Input() override;
private:

	int score = 0;
	ScreenText* countDownText;
	ScreenText* scoreText;
	RS_Timer timer = RS_Timer(1000, true);
	SDL_Event* gameEvents;

	virtual void HandleEvent(ActionData data) override;
	virtual void HandleEvent(ActionData data, int id) override;

	void InitAsteroids();

	CountDownTimer countDown;
};