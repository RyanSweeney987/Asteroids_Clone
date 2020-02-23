#include <SDL.h>
#include "RS_Rectangle.h"

RS_Rectangle::RS_Rectangle(RS_Vector2 pos, int size) : size(size)
{
	type = "rectangle";
	position = pos;

	pointsCount = 5;
	points = new RS_Vector2[pointsCount];

	points[0] = RS_Vector2(0, 0);
	points[1] = RS_Vector2(0, size);
	points[2] = RS_Vector2(size, size);
	points[3] = RS_Vector2(size, 0);
	points[4] = RS_Vector2(0, 0);

	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Square Constructed with Param(%p)", this);
}

RS_Rectangle::~RS_Rectangle()
{
	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Square Destructed with Param(%p)", this);
}
