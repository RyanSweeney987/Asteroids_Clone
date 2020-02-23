#include "RS_Line.h"

RS_Line::RS_Line(RS_Vector2 p1, RS_Vector2 p2)
{
	points.push_back(p1);
	points.push_back(p2);
}

std::vector<RS_Vector2>& RS_Line::getPoints()
{
	return points;
}

void RS_Line::setLine(RS_Vector2 p1, RS_Vector2 p2)
{
	points[0] = p1;
	points[1] = p2;
}
