#pragma once
#define _USE_MATH_DEFINES

#include <math.h>
#include "RS_Vector2.h"

class RS_Transform {
public:
	RS_Transform();
	RS_Transform(RS_Vector2f position);
	RS_Transform(RS_Vector2f position, RS_Vector2f scale);
	RS_Transform(RS_Vector2f position, RS_Vector2f scale, float angleDeg);

	RS_Vector2f position;
	float angleDeg;
	RS_Vector2f scale;

	float GetAngleRadians();

	void MoveForward(float magnitude);
	void MoveTo(RS_Vector2f newPosition);
	void Move(RS_Vector2f newPosition);
	void RotateTo(float angleDeg);
	void Rotate(float angleDeg);
	void SetScale(RS_Vector2f newScale);
};