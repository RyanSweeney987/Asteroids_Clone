#include "RS_Vector2.h"

RS_Vector2& RS_Vector2::operator+=(const RS_Vector2& arg)
{
	this->x += arg.x;
	this->y += arg.y;
	return *this;
}
