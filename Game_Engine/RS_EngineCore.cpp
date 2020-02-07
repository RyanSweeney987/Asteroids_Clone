#include "RS_EngineCore.h"

#include <iostream>

RS_EngineCore::RS_EngineCore()
{
}

RS_EngineCore::~RS_EngineCore()
{
	// Cleanup and unloading
	delete inputEvent;

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Delay(4000);

	SDL_Quit();
}

int RS_EngineCore::start()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		return 1;
	}

	window = SDL_CreateWindow("Test Window", 250, 250, 800, 600, SDL_WINDOW_SHOWN);

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	inputEvent = new SDL_Event();

	isRunning = true;

	return run();
}

int RS_EngineCore::run()
{
	while (isRunning) {
		procInput();
		update();
		render();
	}

	return stop();
}

int RS_EngineCore::stop()
{
	isRunning = false;

	return 1;
}

void RS_EngineCore::procInput()
{
	if (SDL_PollEvent(inputEvent)) {
		if (inputEvent->type == SDL_KEYDOWN) {

			std::printf("Key pressed\r\n");
		}
		else if (inputEvent->type == SDL_QUIT) {
			stop();
		}
	}
}

void RS_EngineCore::update()
{

}

void RS_EngineCore::render()
{
	// Set background colour
	SDL_SetRenderDrawColor(renderer, 33, 33, 33, 255);
	// Clear window
	SDL_RenderClear(renderer);

	SDL_Rect r;
	r.x = 50;
	r.y = 50;
	r.w = 50;
	r.h = 50;
	// Set rect colour
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	// Draw rect
	SDL_RenderFillRect(renderer, &r);

	SDL_Point triangle[4] = {
		{ 200, 50 },
		{ 250, 50 },
		{ 225, 100 },
		{ 200, 50 }
	};
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

	SDL_RenderDrawLines(renderer, triangle, 4);

	// Render rect to screen
	SDL_RenderPresent(renderer);
}
