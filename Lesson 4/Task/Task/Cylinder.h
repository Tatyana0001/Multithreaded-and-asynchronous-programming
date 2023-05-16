#pragma once
#include "shape.h"

class Cylinder : public Shape {
public:
	Cylinder() = default;
	Cylinder(int _x1, int _y1, double R, double H);
	int x1 = 0, y1 = 0;
	double radius;
	double height;
	double square;
};