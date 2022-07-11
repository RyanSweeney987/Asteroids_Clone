#pragma once

struct RS_Vector2 {
public:
	RS_Vector2() : x(0), y(0) {}
	RS_Vector2(int x, int y) : x(x), y(y) {}
	RS_Vector2& operator+=(const RS_Vector2& arg);
	int x;
	int y;
<<<<<<< Updated upstream
=======
};

struct RS_Vector2f {
	RS_Vector2f() : x(0), y(0) {}
	RS_Vector2f(float x, float y) : x(x), y(y) {}
	RS_Vector2f(const RS_Vector2& arg);
	RS_Vector2f& operator=(const RS_Vector2& arg);
	RS_Vector2f& operator+=(const RS_Vector2f& arg);
	float x;
	float y;
>>>>>>> Stashed changes
};