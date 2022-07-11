#pragma once
#include <vector>
#include <SDL.h>
#include "RS_Shape.h"
#include "RS_Time.h"

class RS_GameWorld {
public:
	RS_GameWorld();
	~RS_GameWorld();

	void start();
	void run();
	void stop();
	void update();
	void input();
	void draw();
	bool getIsRunning();
private:
	const float DELTA_TIME = 1000.0f / 60.0f;

	bool isRunning = false;
	bool keys[256];

	std::vector<RS_Shape*> shapes;
	RS_Time time;

	SDL_Renderer* renderer;
	SDL_Window* window;
	SDL_Event* inputEvent;
};