#pragma once

struct RS_Vector2 {
public:
	RS_Vector2() : x(0), y(0) {}
	RS_Vector2(int x, int y) : x(x), y(y) {}
	RS_Vector2& operator+=(const RS_Vector2& arg);
	int x;
	int y;
};