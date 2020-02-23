#include "RS_Triangle.h"

RS_Triangle::RS_Triangle(RS_Vector2 pos, int width, int height)
{
	type = "triangle";
	position = pos;

	pointsCount = 4;
	points = new RS_Vector2[pointsCount];
	points[0] = RS_Vector2(0, 0);
	points[1] = RS_Vector2(0, width);
	points[2] = RS_Vector2(width, height);
	points[3] = RS_Vector2(0, 0);
}
