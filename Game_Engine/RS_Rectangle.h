#pragma once

#include "RS_Shape.h"

class RS_Rectangle : public RS_Shape {
public:
	RS_Rectangle(RS_Vector2 pos, int size);
	~RS_Rectangle();
private:
	int size;
};