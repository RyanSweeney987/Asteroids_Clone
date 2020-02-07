#pragma once

#include "SDL.h"

class RS_EngineCore {
public:
	RS_EngineCore();
	~RS_EngineCore();
	int start();
private:
	bool isRunning;
	SDL_Renderer* renderer;
	SDL_Window* window;
	SDL_Event* inputEvent;
	int run();
	int stop();
	void procInput();
	void update();
	void render();
};