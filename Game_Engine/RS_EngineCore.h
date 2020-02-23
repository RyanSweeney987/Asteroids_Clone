#pragma once

#include "SDL.h"
#include "RS_Time.h"
#include "RS_GameWorld.h"

class RS_EngineCore {
public:
	RS_EngineCore();
	~RS_EngineCore();
	int start();
private:
	int run();
	int stop();
	RS_GameWorld mainWorld;
};