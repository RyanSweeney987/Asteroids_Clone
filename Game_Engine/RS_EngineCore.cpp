#include "RS_EngineCore.h"

#include <iostream>

RS_EngineCore::RS_EngineCore()
{
	// Load stuffs
}

RS_EngineCore::~RS_EngineCore()
{
	SDL_Quit();
}

int RS_EngineCore::start()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		return 1;
	}

	return run();
}

int RS_EngineCore::run()
{
	mainWorld.start();

	return stop();
}

int RS_EngineCore::stop()
{
	return 1;
}