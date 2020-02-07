#pragma once
#include "RS_Vector2.h"

class RS_Transform {
public:
	RS_Transform(RS_Vector2 position);
	void setPosition(RS_Vector2 newPosition);
private:
	RS_Vector2 position;
};