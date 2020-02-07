#include "RS_Point.h"

RS_Point::RS_Point() : x(0), y(0)
{
}

RS_Point::RS_Point(int x, int y) : x(x), y(y)
{
}

int RS_Point::getX()
{
	return x;
}

int RS_Point::getY()
{
	return y;
}

void RS_Point::setPoint(int x, int y)
{
	this->x = x;
	this->y = y;
}