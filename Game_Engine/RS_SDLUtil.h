#pragma once
#include <vector>
#include <SDL.h>
#include "RS_Vector2.h"

class RS_SDLUtil {
public:
	static SDL_Point* vectorToSDLPoint(RS_Vector2* points, int count);
}