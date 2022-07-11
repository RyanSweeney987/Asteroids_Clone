#include "RS_Shape.h"

RS_Shape::RS_Shape()
{
}

RS_Shape::~RS_Shape()
{
	delete[] points;
}

void RS_Shape::update()
{
}

std::string RS_Shape::getType()
{
	return type;
}

RS_Vector2* RS_Shape::getPoints()
{
	return points;
}

RS_Vector2& RS_Shape::getPosition()
{
	return position;
}

int RS_Shape::getPointsCount()
{
	return pointsCount;
}
