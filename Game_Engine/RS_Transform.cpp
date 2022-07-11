#include "RS_Transform.h"

RS_Transform::RS_Transform()
{
	position = RS_Vector2(0, 0);
}

RS_Transform::RS_Transform(RS_Vector2 position) : position(position)
{
}

void RS_Transform::move(RS_Vector2 offset)
{
	position += offset;
}

RS_Vector2& RS_Transform::getPosition()
{
	return position;
}

void RS_Transform::set(RS_Vector2 newPosition)
{
	position = newPosition;
}
