#pragma once
#include "RS_Point.h"
#include <vector>
#include <cstdarg>

class RS_Line {
public:
	RS_Line(RS_Point p1, RS_Point p2);
	void setLine(RS_Point p1, RS_Point p2);
	std::vector<RS_Point>& getPoints();
private:
	std::vector<RS_Point> points;
};