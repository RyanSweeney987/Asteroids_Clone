#include "RS_Line.h"

RS_Line::RS_Line(RS_Point p1, RS_Point p2)
{
	points.push_back(p1);
	points.push_back(p2);
}

std::vector<RS_Point>& RS_Line::getPoints()
{
	return points;
}

void RS_Line::setLine(RS_Point p1, RS_Point p2)
{
	points[0] = p1;
	points[1] = p2;
}
