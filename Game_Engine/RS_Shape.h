#pragma once
#include <vector>
#include "RS_Line.h"
#include <string>
#include "RS_Transform.h"

class RS_Shape {
public:
	friend class RS_Triangle;
protected:
	RS_Transform transform;
	std::vector<RS_Line*> lines;
	std::string type;
};