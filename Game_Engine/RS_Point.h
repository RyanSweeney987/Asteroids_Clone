#pragma once

class RS_Point {
public:
	RS_Point();
	RS_Point(int x, int y);
	int getX();
	int getY();
	void setPoint(int x, int y);
private:
	int x;
	int y;
};