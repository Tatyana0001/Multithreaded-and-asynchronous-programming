#pragma once
#include "shape.h"

class Circle : public Shape {
public:
	Circle() = default;
	Circle(int _x1, int _y1, double R);
	int x1 = 0, y1 = 0;
	double radius;
	double square;
};