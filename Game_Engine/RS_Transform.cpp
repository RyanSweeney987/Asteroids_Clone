#include "RS_Transform.h"
#include "RS_Logger.h"

RS_Transform::RS_Transform() : RS_Transform(RS_Vector2f(0, 0), RS_Vector2f(1, 1), 0)
{
}

RS_Transform::RS_Transform(RS_Vector2f position) : RS_Transform(position, RS_Vector2f(1, 1), 0)
{
}

RS_Transform::RS_Transform(RS_Vector2f position, RS_Vector2f scale) : RS_Transform(position, scale, 0.0f)
{
}

RS_Transform::RS_Transform(RS_Vector2f position, RS_Vector2f scale, float angleRadians) : position(position), scale(scale), angleDeg(angleDeg)
{
}

float RS_Transform::GetAngleRadians()
{
	return (angleDeg - 90) * (float)M_PI / 180.0f;
}

void RS_Transform::MoveForward(float magnitude)
{
	position.x += magnitude * cosf(GetAngleRadians());
	position.y += magnitude * sinf(GetAngleRadians());
}

void RS_Transform::MoveTo(RS_Vector2f newPosition)
{
	position = newPosition;
}

void RS_Transform::Move(RS_Vector2f newPosition)
{
	position += newPosition;
}

void RS_Transform::Rotate(float angleDeg)
{
	this->angleDeg += angleDeg;
}

void RS_Transform::SetScale(RS_Vector2f newScale)
{
	scale = newScale;
}
