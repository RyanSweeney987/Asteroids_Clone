#include "RS_Vector2.h"

RS_Vector2& RS_Vector2::operator+=(const RS_Vector2& arg)
{
	this->x += arg.x;
	this->y += arg.y;
	return *this;
}
<<<<<<< Updated upstream
=======

RS_Vector2f::RS_Vector2f(const RS_Vector2& arg) : x(arg.x), y(arg.y)
{
}

RS_Vector2f& RS_Vector2f::operator=(const RS_Vector2& arg)
{
	this->x += arg.x;
	this->y += arg.y;
	return *this;
}

RS_Vector2f& RS_Vector2f::operator+=(const RS_Vector2f& arg)
{
	this->x += arg.x;
	this->y += arg.y;
	return *this;
}
>>>>>>> Stashed changes
