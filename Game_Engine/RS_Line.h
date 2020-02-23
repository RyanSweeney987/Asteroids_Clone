#pragma once
#include "RS_Vector2.h"
#include <vector>
#include <cstdarg>

class RS_Line {
public:
	RS_Line(RS_Vector2 p1, RS_Vector2 p2);
	void setLine(RS_Vector2 p1, RS_Vector2 p2);
	std::vector<RS_Vector2>& getPoints();
private:
	std::vector<RS_Vector2> points;
};