#pragma once
#include <vector>
#include "RS_Line.h"
#include <string>

class RS_Shape {
public:
	RS_Shape();
	~RS_Shape();
	void update();
	std::string getType();
	RS_Vector2* getPoints();
	RS_Vector2& getPosition();
	int getPointsCount();
	
	friend class RS_Triangle;
	friend class RS_Rectangle;
protected:
	RS_Vector2 position;
	RS_Vector2* points;
	int pointsCount;
	std::string type;
};