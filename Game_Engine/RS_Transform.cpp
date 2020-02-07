#include "RS_Transform.h"

RS_Transform::RS_Transform(RS_Vector2 position) : position(position)
{
}

void RS_Transform::setPosition(RS_Vector2 newPosition)
{
	position = newPosition;
}
